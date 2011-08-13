#ifndef hcx_filter_h
#define hcx_filter_h

#include "boole.h"
#include "value.h"

#define HCX_FILTER_COMPETITIVE hcx_boole_true
#define HCX_FILTER_NONCOMPETITIVE hcx_boole_false

#define HCX_FILTER_NO_THRESHOLD 0

#define HCX_FILTER_POSITIVE hcx_boole_false
#define HCX_FILTER_NEGATIVE hcx_boole_true

enum hcx_filter_grow_mode_t {
  HCX_FILTER_GROW_MODE_INCREMENTAL,
  HCX_FILTER_GROW_MODE_EXPONENTIAL
};
typedef enum hcx_filter_grow_mode_t hcx_filter_grow_mode_t;

enum hcx_filter_stay_mode_t {
  HCX_FILTER_STAY_MODE_PERSIST,
  HCX_FILTER_STAY_MODE_DECAY
};
typedef enum hcx_filter_stay_mode_t hcx_filter_stay_mode_t;

struct hcx_filter_t;
typedef struct hcx_filter_t hcx_filter_t;

hcx_filter_t *hcx_filter_create(hcx_filter_grow_mode_t grow_mode,
    hcx_filter_stay_mode_t stay_mode, hcx_boole_t competitive,
    hcx_value_t threshold, hcx_boole_t negative);

void hcx_filter_destroy(hcx_filter_t *filter);

hcx_value_t hcx_filter_get_excitement(hcx_filter_t *filter,
    hcx_value_t channel);

void hcx_filter_tickle(hcx_filter_t *filter, hcx_value_t channel);

#endif
