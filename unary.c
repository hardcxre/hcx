#include "standard.h"
#include "tools.h"
#include "unary.h"

struct hcx_unary_t {
  hcx_class_t returns[HCX_CLASS_COUNT];
};

hcx_class_t hcx_unary_classify(hcx_unary_t *unary, hcx_class_t argument)
{
  return *(unary->returns + argument);
}

hcx_unary_t *hcx_unary_create()
{
  hcx_unary_t *unary;
  unsigned short i;

  unary = malloc(sizeof *unary);
  if (unary) {
    for (i = 0; i < HCX_CLASS_COUNT; i++) {
      *(unary->returns + i) = rand() % HCX_CLASS_COUNT;
    }
  } else {
    hcx_tools_trace("malloc");
  }

  return unary;
}

void hcx_unary_destroy(hcx_unary_t *unary)
{
  free(unary);
}
