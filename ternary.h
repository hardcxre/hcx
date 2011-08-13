#ifndef hcx_ternary_h
#define hcx_ternary_h

#include "value.h"

struct hcx_ternary_t;
typedef struct hcx_ternary_t hcx_ternary_t;

hcx_value_t hcx_ternary_operate(hcx_ternary_t *ternary,
    hcx_value_t argument_1, hcx_value_t argument_2, hcx_value_t argument_3);

hcx_ternary_t *hcx_ternary_create();

void hcx_ternary_destroy(hcx_ternary_t *ternary);

#endif
