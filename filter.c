#include "filter.h"
#include "line.h"
#include "standard.h"

struct hcx_filter_t {
  hcx_line_t excitements;
  hcx_filter_grow_mode_t grow_mode;
  hcx_filter_stay_mode_t stay_mode;
  hcx_boole_t competitive;
  hcx_value_t threshold;
  hcx_boole_t negative;
};

hcx_filter_t *hcx_filter_create(hcx_filter_grow_mode_t grow_mode,
    hcx_filter_stay_mode_t stay_mode, hcx_boole_t competitive,
    hcx_value_t threshold, hcx_boole_t negative)
{
  return NULL;
}

void hcx_filter_destroy(hcx_filter_t *filter)
{
}

hcx_value_t hcx_filter_get_excitement(hcx_filter_t *filter,
    hcx_value_t channel)
{
  return filter->excitements[channel];
}

void hcx_filter_tickle(hcx_filter_t *filter, hcx_value_t channel)
{
}
