#ifndef hcx_unary_h
#define hcx_unary_h

#include "class.h"

struct hcx_unary_t;
typedef struct hcx_unary_t hcx_unary_t;

hcx_class_t hcx_unary_classify(hcx_unary_t *unary, hcx_class_t argument);

hcx_unary_t *hcx_unary_create();

void hcx_unary_destroy(hcx_unary_t *unary);

#endif
