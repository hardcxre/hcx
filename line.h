#ifndef hcx_line_h
#define hcx_line_h

#include "value.h"

typedef hcx_value_t hcx_line_t[HCX_VALUE_COUNT];

void hcx_line_randomize(hcx_line_t *line);

/*
unsigned short i;
for (i = 0; i < HCX_VALUE_COUNT; i++) {
  *(unary->values + i) = rand() % HCX_VALUE_COUNT;
}
*/

void hcx_line_shuffle(hcx_line_t *line);

void hcx_line_swap_values(hcx_line_t *line, hcx_value_t position_1,
    hcx_value_t position_2);

void hcx_line_zero(hcx_line_t *line);

#endif
