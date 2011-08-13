#include "ternary.h"
#include "space.h"
#include "standard.h"
#include "trace.h"

struct hcx_ternary_t {
  hcx_space_t returns;
};

hcx_class_t hcx_ternary_classify(hcx_ternary_t *ternary,
    hcx_class_t argument_1, hcx_class_t argument_2, hcx_class_t argument_3)
{
  return ternary->returns[argument_1][argument_2][argument_3];
}

hcx_ternary_t *hcx_ternary_create()
{
  hcx_ternary_t *ternary;
  unsigned short i;
  unsigned short j;
  unsigned short k;

  ternary = malloc(sizeof *ternary);
  if (ternary) {
    for (i = 0; i < HCX_CLASS_COUNT; i++) {
      for (j = 0; j < HCX_CLASS_COUNT; j++) {
        for (k = 0; k < HCX_CLASS_COUNT; k++) {
          ternary->returns[i][j][k] = rand() % HCX_CLASS_COUNT;
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
