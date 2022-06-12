/*
 * Telecard - Read Telecards with the Arduino ATmega32u4
 *
 * www.github.com/hharte/TeleCard
 *
 * (c) 2022, Howard M. Harte
 *
 * Reference: http://laurent.deschamps.free.fr/telecarte/phonecar.htm
 *
 * Hardware used: SparkFun Qwiic Pro Micro - USB-C (ATmega32U4) Board
 * https://www.amazon.com/SparkFun-Qwiic-Pro-Micro-microcontroller/dp/B084KPT7MH
 *
 */

#include "Telecard.h"

#define BAUD_RATE 115200
#define C_OUTPUT      /* Define to output data as a C data structure */

/*
          ISO 7816-2
  -------------+-------------
 |   1         |         5   |        Pinout:
 |             |             |        -------
 +-------\     |     /-------+
 |   2    +----+    +    6   |          1 : Vcc = 5V    5 : Gnd
 |        |         |        |          2 : R           6 : n.c.
 +--------|         |--------+          3 : Clock       7 : I/O
 |   3    |         |    7   |          4 : n.c.        8 : n.c.
 |        +----+----+        |
 +-------/     |     \-------+      n.c. : not connected
 |   4         |         8   |
 |             |             |
  -------------+-------------

The reader assembly used is Nortel part number NPS50883-01L5 from a
Nortel Millennium payphone.  It has a 2x7 0.1" female IDC ribbon cable.
Pin numbering on the 2x7 header is with reference to the arrow on the
IDC connector housing, not the red stripe on the ribbon cable.  Some
card reader assemblies have the red stripe on the wrong side.

Timing is set to reflect what was observed on a Nortel Millennium
Payphone.

*/

/* Telecard Interface:
 *      ATmega 32u4      ISO-7816 Pin    2x7 Header Pin          */   
#define CLK       7   /* Pin 3: Clock     1                      */
#define R         4   /* Pin 2: R         7                      */
#define I_O       9   /* Pin 7: I/O(OD)  14 Open Drain           */
                      /* Pin 5:          13 GND                  */
                      /* Pin 1:          10 VCC (5V)             */

/* The following are specific to the Nortel Multicard reader. */
#define CD_DET    8   /* Card Detect     12 1=Card present.      */
                      /* Card Detect Com  2 Tie to GND           */
#define PULLUP    2   /* Card Detect P/U 11 Pull-up              */

/* These are not used by the software */
#define MAG_DET   3   /* Mag Card Switch  9 Magnetic Card Switch */
#define RESET     5   /* Pin 5            5 Not used             */
#define FUSE_I    6   /* Pin 6            3 Not used             */

/* function prototypes */
void tc_reset(void);
uint8_t tc_read(void);

/* global variables */
char outstr[81];

void setup() {
  /* Initialize serial port */
  Serial.begin(BAUD_RATE);

  /* Configure Address and chip enables. */
  pinMode (CLK,     OUTPUT);
  pinMode (R,       OUTPUT);
  pinMode (I_O,     INPUT_PULLUP);
  pinMode (CD_DET,  INPUT_PULLUP);
  pinMode (MAG_DET, INPUT_PULLUP);
  pinMode (CD_DET,  INPUT_PULLUP);
  pinMode (RESET,   INPUT_PULLUP);
  pinMode (FUSE_I,  INPUT_PULLUP);
  pinMode (PULLUP,  INPUT_PULLUP);

  while (!Serial) {
    /* wait for USB serial port to connect */
  }

  Serial.print("\nTelecard Reader (c) 2022 - Howard M. Harte\n");
  Serial.print("https://github.com/hharte/TeleCard\n\n");
}

void loop() {
  uint8_t databyte;
  uint8_t bytecnt;
  tc_data_t tc_data = { 0 };

  if (digitalRead(CD_DET) == 0) {
    Serial.print("Insert Telecard.\n");
    while(digitalRead(CD_DET) == 0) {
      /* Wait for card to be inserted... */
    }
  }

  memset(&tc_data, 0, sizeof(tc_data));
  tc_reset();
  
  for (bytecnt = 0; bytecnt < (CARD_SIZE / 8); bytecnt++) {
    databyte = tc_read();

    tc_data.raw[bytecnt] = databyte;

    if ((bytecnt == 0) && (tc_data.raw[0] == 0xFF)) {
      Serial.print("\nInvalid read, please try again.\n");
      break;
    }

    if ((bytecnt == 0x10) && (tc_data.raw[0x10] == tc_data.raw[0])) {
      break;
    }
  }

  digitalWrite(R, 0);

  if (tc_data.raw[0] != 0xFF) {
    dump_card_data(&tc_data, bytecnt);
    print_card_details(&tc_data, bytecnt);
#ifdef C_OUTPUT
    card_data_to_c(&tc_data);
#endif /* C_OUTPUT */
  }

  Serial.print("\nDone reading Telecard.  Remove and re-insert to read another.\n\n");

  while(digitalRead(CD_DET) == 1) {
    /* Wait for card to be removed... */
  }

  delay(250); /* Debounce before reading the next card. */
}

/* Solaic Telecards - Reset */
void tc_reset(void) {
    digitalWrite(CLK, 0);
    digitalWrite(R, 0);
    delayMicroseconds(1000);
    digitalWrite(R, 1);
    delayMicroseconds(200);
    digitalWrite(CLK, 1);
    delayMicroseconds(770);
    digitalWrite(CLK, 0);
    delayMicroseconds(200);
    digitalWrite(R, 0);
    delayMicroseconds(250);
}

/* Read Byte from Telecard */
uint8_t tc_read(void) {
    uint8_t databyte = 0;

    for (uint8_t i = 0; i < 8; i++) {
      databyte <<= 1;
      databyte |= (digitalRead(I_O) & 1);
      digitalWrite(CLK, 1);   /* Advance address counter */
      delayMicroseconds(16);
      digitalWrite(CLK, 0);
      delayMicroseconds(30);
    }

    return databyte;
}
