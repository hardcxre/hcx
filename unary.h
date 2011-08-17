#ifndef hcx_unary_h
#define hcx_unary_h

#include "value.h"

typedef hcx_value_t hcx_unary_t[HCX_VALUE_COUNT];

void hcx_unary_generate(hcx_unary_t *destination, hcx_unary_t *source_1,
    hcx_unary_t *source_2);
hcx_value_t hcx_unary_pull(hcx_unary_t unary);
void hcx_unary_push(hcx_unary_t unary, hcx_value_t value);
void hcx_unary_randomize(hcx_unary_t unary);
void hcx_unary_shuffle(hcx_unary_t unary);
void hcx_unary_swap_values(hcx_unary_t unary, hcx_value_t position_a,
    hcx_value_t position_b);
void hcx_unary_zero(hcx_unary_t unary);

#endif
