#include "physick.h"

static hcx_physick_element_t inherence[4][4] = {
  {
    hcx_physick_element_yes,
    hcx_physick_element_yes,
    hcx_physick_element_yes,
    hcx_physick_element_yes
  },
  {
    hcx_physick_element_no,
    hcx_physick_element_no,
    hcx_physick_element_no,
    hcx_physick_element_no
  },
  {
    hcx_physick_element_yes,
    hcx_physick_element_no,
    hcx_physick_element_is,
    hcx_physick_element_not
  },
  {
    hcx_physick_element_no,
    hcx_physick_element_yes,
    hcx_physick_element_not,
    hcx_physick_element_is
  }
};

hcx_physick_element_t hcx_physick_fuse(hcx_physick_element_t function,
    hcx_physick_element_t argument)
{
  return inherence[function][argument];
}

void hcx_physick_spark(hcx_physick_atom_t *atom,
    hcx_physick_atom_t *neighbor_a, hcx_physick_atom_t *neighbor_b,
    hcx_physick_atom_t *neighbor_c)
{
}

hcx_boole_t hcx_physick_start()
{
  return hcx_boole_true;
}

void hcx_physick_stop()
{
}
