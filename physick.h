#ifndef physick_h
#define physick_h

#include "physick.h"
#include "boole.h"
#include "declarations.h"
#include "sing.h"

typedef unsigned char physick_element_t;
#define physick_element_yes 1
#define physick_element_no 0
#define physick_element_is 2
#define physick_element_not 3

typedef unsigned short physick_atom_id_t;
#define PHYSICK_ATOM_COUNT (65536 - 1)

struct physick_atom_t {
  physick_element_t element;
  sing_scale_t scale;
  sing_geometry_id_t geometry_id;  /*  should this be in the sing node?  */
  dna_t dna;
};
typedef struct physick_atom_t physick_atom_t;

physick_element_t physick_fuse(physick_element_t function,
    physick_element_t argument);
void physick_spark(physick_atom_t *atom, physick_atom_t *neighbor_a,
    physick_atom_t *neighbor_b, physick_atom_t *neighbor_c);
boole_t physick_start();
void physick_stop();

#endif
