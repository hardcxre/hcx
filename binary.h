#ifndef hcx_binary_h
#define hcx_binary_h

#include "value.h"

struct hcx_binary_t;
typedef struct hcx_binary_t hcx_binary_t;

hcx_value_t hcx_binary_operate(hcx_binary_t *binary, hcx_value_t argument_1,
    hcx_value_t argument_2);
hcx_binary_t *hcx_binary_create();
void hcx_binary_destroy(hcx_binary_t *binary);

#endif
