#include "selector.h"
#include "line.h"
#include "standard.h"

struct hcx_selector_t {
  hcx_line_t excitements;
  hcx_selector_grow_mode_t grow_mode;
  hcx_selector_stay_mode_t stay_mode;
  hcx_boole_t competitive;
  hcx_value_t threshold;
  hcx_boole_t negative;
};

hcx_selector_t *hcx_selector_create(hcx_selector_grow_mode_t grow_mode,
    hcx_selector_stay_mode_t stay_mode, hcx_boole_t competitive,
    hcx_value_t threshold, hcx_boole_t negative)
{
  return NULL;
}

void hcx_selector_destroy(hcx_selector_t *selector)
{
}

hcx_value_t hcx_selector_get_excitement(hcx_selector_t *selector,
    hcx_value_t channel)
{
  return selector->excitements[channel];
}

void hcx_selector_tickle(hcx_selector_t *selector, hcx_value_t channel)
{
}
