#ifndef hcx_binary_h
#define hcx_binary_h

#include "value.h"

typedef hcx_value_t hcx_binary_t[HCX_VALUE_COUNT][HCX_VALUE_COUNT];

void hcx_binary_generate(hcx_binary_t *destination, hcx_binary_t *source_1,
    hcx_binary_t *source_2);
hcx_value_t hcx_binary_pull(hcx_binary_t binary);
void hcx_binary_push(hcx_binary_t binary, hcx_value_t value);
void hcx_binary_randomize(hcx_binary_t binary);
void hcx_binary_shuffle(hcx_binary_t binary);
void hcx_binary_swap_values(hcx_binary_t binary, hcx_value_t position_a_x,
    hcx_value_t position_a_y, hcx_value_t position_b_x,
    hcx_value_t position_b_y);
void hcx_binary_zero(hcx_binary_t binary);

#endif
