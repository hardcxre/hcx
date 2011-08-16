#include "selector.h"
#include "line.h"
#include "max.h"
#include "standard.h"
#include "trace.h"

struct hcx_selector_t {
  hcx_line_t values;
};

hcx_selector_t *hcx_selector_create()
{
  hcx_selector_t *selector;

  selector = malloc(sizeof *selector);
  if (selector) {
    hcx_line_randomize(selector->values);
  } else {
    hcx_trace("malloc");
  }

  return selector;
}

void hcx_selector_destroy(hcx_selector_t *selector)
{
  free(selector);
}

hcx_value_t hcx_selector_select(hcx_selector_t *selector)
{
  hcx_value_t value_a_index = rand() % HCX_VALUE_COUNT;
  hcx_value_t value_b_index = rand() % HCX_VALUE_COUNT;
  hcx_value_t selected_index;

  hcx_value_t value_a = selector->values[value_a_index];
  hcx_value_t value_b = selector->values[value_b_index];

  if (value_a > value_b) {
    selected_index = value_a_index;
  } else {
    selected_index = value_b_index;
  }

  return selected_index;
}

void hcx_selector_suggest(hcx_selector_t *selector, hcx_value_t value)
{
  unsigned short new_value = selector->values[value];
  hcx_value_t competing_value_index;

  new_value *= 2;
  if (new_value > HCX_VALUE_MAX) {
    new_value = HCX_VALUE_MAX;
  }
  selector->values[value] = new_value;

  do {
    competing_value_index = hcx_value_rand();
  } while (competing_value_index == value);
  selector->values[competing_value_index] /= 2;
}
