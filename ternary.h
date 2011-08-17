#ifndef hcx_ternary_h
#define hcx_ternary_h

#include "value.h"

typedef hcx_value_t
hcx_ternary_t[HCX_VALUE_COUNT][HCX_VALUE_COUNT][HCX_VALUE_COUNT];

void hcx_ternary_generate(hcx_ternary_t *destination, hcx_ternary_t *source_1,
    hcx_ternary_t *source_2);
hcx_value_t hcx_ternary_pull(hcx_ternary_t ternary);
void hcx_ternary_push(hcx_ternary_t ternary, hcx_value_t value);
void hcx_ternary_randomize(hcx_ternary_t ternary);
void hcx_ternary_shuffle(hcx_ternary_t ternary);
void hcx_ternary_swap_values(hcx_ternary_t ternary, hcx_value_t position_a_x,
    hcx_value_t position_a_y, hcx_value_t position_a_z,
    hcx_value_t position_b_x, hcx_value_t position_b_y,
    hcx_value_t position_b_z);
void hcx_ternary_zero(hcx_ternary_t ternary);

#endif
