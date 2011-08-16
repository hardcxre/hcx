#ifndef hcx_selector_h
#define hcx_selector_h

#include "boole.h"
#include "value.h"

struct hcx_selector_t;
typedef struct hcx_selector_t hcx_selector_t;

hcx_selector_t *hcx_selector_create();
void hcx_selector_destroy(hcx_selector_t *selector);
hcx_value_t hcx_selector_select(hcx_selector_t *selector);
void hcx_selector_suggest(hcx_selector_t *selector, hcx_value_t value);

#endif
