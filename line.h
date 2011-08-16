#ifndef hcx_line_h
#define hcx_line_h

#include "value.h"

typedef hcx_value_t hcx_line_t[HCX_VALUE_COUNT];

hcx_value_t hcx_line_pull(hcx_line_t line);
void hcx_line_push(hcx_line_t line, hcx_value_t value);
void hcx_line_randomize(hcx_line_t line);
void hcx_line_shuffle(hcx_line_t line);
void hcx_line_swap_values(hcx_line_t line, hcx_value_t position_a,
    hcx_value_t position_b);
void hcx_line_zero(hcx_line_t line);

#endif
