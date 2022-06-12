/*
 * Telecard Library
 *
 * www.github.com/hharte/TeleCard
 *
 * (c) 2022, Howard M. Harte
 *
 */

#define CARD_SIZE  512  /* in bits */
//#define C_OUTPUT      /* Define to output data as a C data structure */

#define MFG_MASK  (0x1F)

typedef union {
    uint8_t raw[64];
    struct {
      uint8_t issuer_area[8];
      uint8_t count[5];
    } field;
} tc_data_t;

/* function prototypes */
void print_card_details(tc_data_t *tc, uint8_t len);
void dump_card_data(tc_data_t *tc, uint8_t len);
uint8_t count_bits(uint8_t value);
uint16_t counter_to_units(tc_data_t *tc);
uint32_t card_serial_num(tc_data_t *tc);
float card_value(uint16_t units, uint8_t cents_per_unit);
void card_data_to_c(tc_data_t *tc);
