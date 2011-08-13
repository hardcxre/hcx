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
  unsigned short i;
  unsigned short j;
  unsigned short k;

  ternary = malloc(sizeof *ternary);
  if (ternary) {
    for (i = 0; i < HCX_VALUE_COUNT; i++) {
      for (j = 0; j < HCX_VALUE_COUNT; j++) {
        for (k = 0; k < HCX_VALUE_COUNT; k++) {
          ternary->values[i][j][k] = rand() % HCX_VALUE_COUNT;
        }
      }
    }
  } else {
    hcx_trace("malloc");
  }

  return ternary;
}

void hcx_ternary_destroy(hcx_ternary_t *ternary)
{
  free(ternary);
}
