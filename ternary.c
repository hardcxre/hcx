#include "ternary.h"
#include "space.h"
#include "standard.h"
#include "trace.h"

struct hcx_ternary_t {
  hcx_space_t values;
};

hcx_value_t hcx_ternary_operate(hcx_ternary_t *ternary,
    hcx_value_t argument_1, hcx_value_t argument_2, hcx_value_t argument_3)
{
  return ternary->values[argument_1][argument_2][argument_3];
}

hcx_ternary_t *hcx_ternary_create()
{
  hcx_ternary_t *ternary;

  ternary = malloc(sizeof *ternary);
  if (ternary) {
    hcx_space_randomize(ternary->values);
  } else {
    hcx_trace("malloc");
  }

  return ternary;
}

void hcx_ternary_destroy(hcx_ternary_t *ternary)
{
  free(ternary);
}
