#include "binary.h"
#include "plane.h"
#include "standard.h"
#include "trace.h"

struct hcx_binary_t {
  hcx_plane_t returns;
};

hcx_value_t hcx_binary_operate(hcx_binary_t *binary, hcx_value_t argument_1,
    hcx_value_t argument_2)
{
  return binary->returns[argument_1][argument_2];
}

hcx_binary_t *hcx_binary_create()
{
  hcx_binary_t *binary;
  unsigned short i;
  unsigned short j;

  binary = malloc(sizeof *binary);
  if (binary) {
    for (i = 0; i < HCX_VALUE_COUNT; i++) {
      for (j = 0; j < HCX_VALUE_COUNT; j++) {
        binary->returns[i][j] = rand() % HCX_VALUE_COUNT;
      }
    }
  } else {
    hcx_trace("malloc");
  }

  return binary;
}

void hcx_binary_destroy(hcx_binary_t *binary)
{
  free(binary);
}
