#include "line.h"
#include "standard.h"
#include "trace.h"
#include "unary.h"

struct hcx_unary_t {
  hcx_line_t values;
};

hcx_value_t hcx_unary_operate(hcx_unary_t *unary, hcx_value_t argument)
{
  return unary->values[argument];
}

hcx_unary_t *hcx_unary_create()
{
  hcx_unary_t *unary;

  unary = malloc(sizeof *unary);
  if (unary) {
    hcx_line_shuffle(&unary->values);
  } else {
    hcx_trace("malloc");
  }

  return unary;
}

void hcx_unary_destroy(hcx_unary_t *unary)
{
  free(unary);
}
