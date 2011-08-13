#include "binary.h"
#include "plane.h"
#include "standard.h"
#include "trace.h"

struct hcx_binary_t {
  hcx_plane_t returns;
};

hcx_class_t hcx_binary_classify(hcx_binary_t *binary, hcx_class_t argument_1,
    hcx_class_t argument_2)
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
    for (i = 0; i < HCX_CLASS_COUNT; i++) {
      for (j = 0; j < HCX_CLASS_COUNT; j++) {
        binary->returns[i][j] = rand() % HCX_CLASS_COUNT;
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
