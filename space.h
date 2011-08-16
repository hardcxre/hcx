#ifndef hcx_space_h
#define hcx_space_h

#include "value.h"

typedef hcx_value_t
hcx_space_t[HCX_VALUE_COUNT][HCX_VALUE_COUNT][HCX_VALUE_COUNT];

hcx_value_t hcx_space_pull(hcx_space_t space);
void hcx_space_push(hcx_space_t space, hcx_value_t value);
void hcx_space_randomize(hcx_space_t space);
void hcx_space_shuffle(hcx_space_t space);
void hcx_space_swap_values(hcx_space_t space, hcx_value_t position_a_x,
    hcx_value_t position_a_y, hcx_value_t position_a_z,
    hcx_value_t position_b_x, hcx_value_t position_b_y,
    hcx_value_t position_b_z);
void hcx_space_zero(hcx_space_t space);

#endif
