#ifndef hcx_binary_h
#define hcx_binary_h

#include "class.h"

struct hcx_binary_t;
typedef struct hcx_binary_t hcx_binary_t;

hcx_class_t hcx_binary_classify(hcx_binary_t *binary, hcx_class_t argument_1,
    hcx_class_t argument_2);

hcx_binary_t *hcx_binary_create();

void hcx_binary_destroy(hcx_binary_t *binary);

#endif
