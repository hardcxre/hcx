#ifndef hcx_unary_h
#define hcx_unary_h

#include "value.h"

struct hcx_unary_t;
typedef struct hcx_unary_t hcx_unary_t;

hcx_value_t hcx_unary_operate(hcx_unary_t *unary, hcx_value_t argument);
hcx_unary_t *hcx_unary_create();
void hcx_unary_destroy(hcx_unary_t *unary);

#endif
