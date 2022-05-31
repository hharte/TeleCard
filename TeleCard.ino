/*
 * TeleCard - Read TeleCards with the Arduino ATmega2560
 *
 * www.github.com/hharte/TeleCard
 *
 * (c) 2022, Howard M. Harte
 *
 * Reference: http://laurent.deschamps.free.fr/telecarte/phonecar.htm
 *
 */

#define BAUD_RATE 115200

#define CARD_SIZE  128  /* in bits, 16 bytes of data on the TeleCard */

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

The reader assembly used is part nymber Nortel NPS50883-01L5 from a
Nortel Millennium payphone.  It has a 2x7 0.1" female IDC ribbon cable.
Pin numbering on the 2x7 header is with reference to the arrow on the
IDC connector housing, not the red stripe on the ribbon cable.  Some
card reader assemblies have the red stripe on the wrong side.

Timing is set to reflect what was observed on a Nortel Millennium
Payphone.

*/

/* Telecard Interface    ISO-7816 Pin    2x7 Header Pin              */   
#define CLK       2   /* Pin 3: Clock     1                          */
#define R         3   /* Pin 2: R         7                          */
#define I_O       4   /* Pin 7: I/O(OD)  14 Open Drain               */
#define CD_DET    5   /* Card Detect     12 1=Card present.          */
                      /* Pin 5:          13 GND                      */
                      /* Pin 1:          10 VCC (5V)                 */
                      /* Card Detect Com  2 Tie to GND               */

/* Solaic TeleCards - Reset */
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

void setup() {
  /* Initialize serial port */
  Serial.begin(BAUD_RATE);

  /* Configure Address and chip enables. */
  pinMode (CLK,   OUTPUT);
  pinMode (R,     OUTPUT);
  pinMode (I_O,   INPUT_PULLUP);
  pinMode (CD_DET,INPUT_PULLUP);

  while (!Serial) {
    /* wait for USB serial port to connect */
  }

  Serial.print("\nTeleCard Reader (c) 2022 - Howard M. Harte\n");
  Serial.print("https://github.com/hharte/TeleCard\n\n");
}

char outstr[81];

void loop() {
  uint8_t databyte;

  if (digitalRead(CD_DET) == 0) {
    Serial.print("Insert TeleCard.\n");
    while(digitalRead(CD_DET) == 0) {
      /* Wait for card to be inserted... */
    }
  }

  tc_reset();
  
  for (uint8_t bytecnt = 0; bytecnt < (CARD_SIZE / 8); bytecnt++) {
    databyte = tc_read();
    if (bytecnt % 8 == 0) {
      snprintf(outstr, sizeof(outstr), "\n%02X:", bytecnt);
      Serial.print(outstr);      
    }
    snprintf(outstr, sizeof(outstr), " %02X", databyte);
    Serial.print(outstr);
  }

  digitalWrite(R, 0);
  Serial.print("\nDone reading TeleCard.  Remove and re-insert to read another.\n\n");
  while(digitalRead(CD_DET) == 1) {
    /* Wait for card to be removed... */
  }

  delay(500); /* Debounce before reading the next card. */
}
