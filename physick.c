#include "physick.h"

static physick_element_t inherence[4][4] = {
  {
    physick_element_yes,
    physick_element_yes,
    physick_element_yes,
    physick_element_yes
  },
  {
    physick_element_no,
    physick_element_no,
    physick_element_no,
    physick_element_no
  },
  {
    physick_element_yes,
    physick_element_no,
    physick_element_is,
    physick_element_not
  },
  {
    physick_element_no,
    physick_element_yes,
    physick_element_not,
    physick_element_is
  }
};

physick_element_t physick_fuse(physick_element_t function,
    physick_element_t argument)
{
  return inherence[function][argument];
}

void physick_spark(physick_atom_t *atom, physick_atom_t *neighbor_a,
    physick_atom_t *neighbor_b, physick_atom_t *neighbor_c)
{
}

boole_t physick_start()
{
  return boole_true;
}

void physick_stop()
{
}
