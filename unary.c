#include "line.h"
#include "standard.h"
#include "trace.h"
#include "unary.h"

struct hcx_unary_t {
  hcx_line_t returns;
};

hcx_value_t hcx_unary_operate(hcx_unary_t *unary, hcx_value_t argument)
{
  return *(unary->returns + argument);
}

hcx_unary_t *hcx_unary_create()
{
  hcx_unary_t *unary;
  unsigned short i;

  unary = malloc(sizeof *unary);
  if (unary) {
    for (i = 0; i < HCX_VALUE_COUNT; i++) {
      *(unary->returns + i) = rand() % HCX_VALUE_COUNT;
    }
  } else {
    hcx_trace("malloc");
  }

  return unary;
}

void hcx_unary_destroy(hcx_unary_t *unary)
{
  free(unary);
}
