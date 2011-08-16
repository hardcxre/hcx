#include "binary.h"
#include "plane.h"
#include "standard.h"
#include "trace.h"

struct hcx_binary_t {
  hcx_plane_t values;
};

hcx_value_t hcx_binary_operate(hcx_binary_t *binary, hcx_value_t argument_1,
    hcx_value_t argument_2)
{
  return binary->values[argument_1][argument_2];
}

hcx_binary_t *hcx_binary_create()
{
  hcx_binary_t *binary;

  binary = malloc(sizeof *binary);
  if (binary) {
    hcx_plane_randomize(binary->values);
  } else {
    hcx_trace("malloc");
  }

  return binary;
}

void hcx_binary_destroy(hcx_binary_t *binary)
{
  free(binary);
}
