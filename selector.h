#ifndef hcx_selector_h
#define hcx_selector_h

#include "boole.h"
#include "value.h"

/*
  TODO: simplify: make it always competitive, remove threshold, make it always
  positive, always exponential, and always decay

  use as filter
  use as priority
*/

#define HCX_SELECTOR_COMPETITIVE hcx_boole_true
#define HCX_SELECTOR_NONCOMPETITIVE hcx_boole_false

#define HCX_SELECTOR_NO_THRESHOLD 0

#define HCX_SELECTOR_POSITIVE hcx_boole_false
#define HCX_SELECTOR_NEGATIVE hcx_boole_true

enum hcx_selector_grow_mode_t {
  HCX_SELECTOR_GROW_MODE_INCREMENTAL,
  HCX_SELECTOR_GROW_MODE_EXPONENTIAL
};
typedef enum hcx_selector_grow_mode_t hcx_selector_grow_mode_t;

enum hcx_selector_stay_mode_t {
  HCX_SELECTOR_STAY_MODE_PERSIST,
  HCX_SELECTOR_STAY_MODE_DECAY
};
typedef enum hcx_selector_stay_mode_t hcx_selector_stay_mode_t;

struct hcx_selector_t;
typedef struct hcx_selector_t hcx_selector_t;

hcx_selector_t *hcx_selector_create(hcx_selector_grow_mode_t grow_mode,
    hcx_selector_stay_mode_t stay_mode, hcx_boole_t competitive,
    hcx_value_t threshold, hcx_boole_t negative);

void hcx_selector_destroy(hcx_selector_t *selector);

hcx_value_t hcx_selector_select(hcx_selector_t *selector);

void hcx_selector_suggest(hcx_selector_t *selector, hcx_value_t value);

#endif
