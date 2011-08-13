#ifndef hcx_ternary_h
#define hcx_ternary_h

#include "class.h"

struct hcx_ternary_t;
typedef struct hcx_ternary_t hcx_ternary_t;

hcx_class_t hcx_ternary_classify(hcx_ternary_t *ternary,
    hcx_class_t argument_1, hcx_class_t argument_2, hcx_class_t argument_3);

hcx_ternary_t *hcx_ternary_create();

void hcx_ternary_destroy(hcx_ternary_t *ternary);

#endif
