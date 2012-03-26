#ifndef ih_computer_output_h
#define ih_computer_output_h

#include "ih/core/bit.h"

#define IH_COMPUTER_OUTPUT_BITS 32

struct ih_computer_output_t {
  ih_core_bit_t bits[IH_COMPUTER_OUTPUT_BITS];
};
typedef struct ih_computer_output_t ih_computer_output_t;

void ih_computer_output_free(ih_computer_output_t *output);

void ih_computer_output_init(ih_computer_output_t *output);

#endif
