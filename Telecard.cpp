/*
 * Telecard Library
 *
 * www.github.com/hharte/TeleCard
 *
 * (c) 2022, Howard M. Harte
 *
 */

#include <stdint.h>
#include <Arduino.h>
#include <HardwareSerial.h>

#define CARD_SIZE  512  /* in bits */

#define MFG_MASK  (0x1F)

typedef union {
    uint8_t raw[64];
    struct {
      uint8_t issuer_area[8];
      uint8_t count[5];
    } field;
} tc_data_t;

/* function prototypes */
void tc_reset(void);
uint8_t tc_read(void);
void print_card_details(tc_data_t *tc, uint8_t len);
void dump_card_data(tc_data_t *tc, uint8_t len);
uint8_t count_bits(uint8_t value);
uint16_t counter_to_units(tc_data_t *tc);
uint32_t card_serial_num(tc_data_t *tc);
float card_value(uint16_t units, uint8_t cents_per_unit);
void card_data_to_c(tc_data_t *tc);


void print_card_details(tc_data_t *tc, uint8_t len) {
  char outstr[81];
  snprintf(outstr, sizeof(outstr), "\n\n   Manufacturer: 0x%02x\n", tc->raw[1] & MFG_MASK);
  Serial.print(outstr);

  snprintf(outstr, sizeof(outstr), "    Card length: %d bits\n", len * 8);
  Serial.print(outstr);

  snprintf(outstr, sizeof(outstr), "    Card number: 9%03u0%03u%03u%08lu\n",
    tc->raw[2], tc->raw[3], tc->raw[1],
    card_serial_num(tc));
  Serial.print(outstr);

  snprintf(outstr, sizeof(outstr), "       Checksum: 0x%02X\n", tc->raw[7]);
  Serial.print(outstr);

  uint16_t units = counter_to_units(tc);

  snprintf(outstr, sizeof(outstr), "Units remaining: %d\n", units);
  Serial.print(outstr);

  float value = card_value(units, 5);
  Serial.print("     Card value: $");
  Serial.println(value, 2);

}

void dump_card_data(tc_data_t *tc, uint8_t len) {
  char outstr[81];

  for (uint8_t i = 0; i < len; i++) {
    if (i % 8 == 0) {
      snprintf(outstr, sizeof(outstr), "\n%02X:", i);
      Serial.print(outstr);
    }
    snprintf(outstr, sizeof(outstr), " %02X", tc->raw[i]);
    Serial.print(outstr);
  }
}

/* Count number of bits set to 1. */
uint8_t count_bits(uint8_t value) {
  uint8_t bitcount = 0;
  while (value > 0) {
    if (value & 1) bitcount ++;
    value >>= 1;
  }
  return bitcount;
}

/* This style of counter seems specific to the US / Canada cards. */
/* Observed with US West, GTE, Bell cards. */
uint16_t counter_to_units(tc_data_t *tc) {
  uint16_t units = 0;

  units  =  count_bits(tc->field.count[4]);
  units += (count_bits(tc->field.count[3] & 0x0F) * 8);
  units += (count_bits(tc->field.count[2] & 0x0F) * 32);
  units += (count_bits(tc->field.count[1] & 0x0F) * 128);
  units += (count_bits(tc->field.count[0] & 0x0F) * 512);

  return units;
}

uint32_t card_serial_num(tc_data_t *tc) {
  uint32_t serialnum;

  serialnum  = ((uint32_t)tc->raw[4] << 16);
  serialnum |= ((uint32_t)tc->raw[5] << 8);
  serialnum |=  (uint32_t)tc->raw[6];

  return serialnum;
}

/* Return the card value */
float card_value(uint16_t units, uint8_t cents_per_unit) {
  float card_value;

  card_value = units * cents_per_unit / 100.0;

  return card_value;
}

void card_data_to_c(tc_data_t *tc) {
  char outstr[81];

  snprintf(outstr, sizeof(outstr), "\n{ /* Card number: 9%03u0%03u%03u%08lu, %d units */\n",
    tc->raw[2], tc->raw[3], tc->raw[1],
    card_serial_num(tc),
    counter_to_units(tc));
  Serial.print(outstr);
  snprintf(outstr, sizeof(outstr), "    0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,\n",
    tc->raw[0],
    tc->raw[1],
    tc->raw[2],
    tc->raw[3],
    tc->raw[4],
    tc->raw[5],
    tc->raw[6],
    tc->raw[7]);
  Serial.print(outstr);
  snprintf(outstr, sizeof(outstr), "    0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\n",
    tc->raw[8],
    tc->raw[9],
    tc->raw[10],
    tc->raw[11],
    tc->raw[12]);
  Serial.print(outstr);
  snprintf(outstr, sizeof(outstr), "    0x%02X, 0x%02X, 0x%02X\n};\n",
    tc->raw[13],
    tc->raw[14],
    tc->raw[15]);
  Serial.print(outstr);
}
