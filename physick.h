#ifndef hcx_physick_h
#define hcx_physick_h

#include "physick.h"
#include "boole.h"
#include "declarations.h"
#include "sing.h"

typedef unsigned char hcx_physick_element_t;
#define hcx_physick_element_yes 1
#define hcx_physick_element_no 0
#define hcx_physick_element_is 2
#define hcx_physick_element_not 3

typedef unsigned short hcx_physick_atom_id_t;
#define HCX_PHYSICK_ATOM_COUNT (65536 - 1)

struct hcx_physick_atom_t {
  hcx_physick_element_t element;
  hcx_sing_scale_t scale;
  hcx_sing_geometry_id_t geometry_id;  /*  should this be in the sing node?  */
  hcx_dna_t dna;
};
typedef struct hcx_physick_atom_t hcx_physick_atom_t;

hcx_physick_element_t hcx_physick_fuse(hcx_physick_element_t function,
    hcx_physick_element_t argument);
void hcx_physick_spark(hcx_physick_atom_t *atom,
    hcx_physick_atom_t *neighbor_a, hcx_physick_atom_t *neighbor_b,
    hcx_physick_atom_t *neighbor_c);
hcx_boole_t hcx_physick_start();
void hcx_physick_stop();

#endif
