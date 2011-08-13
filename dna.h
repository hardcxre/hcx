#ifndef hcx_dna_h
#define hcx_dna_h

#include "boole.h"
#include "physick.h"

void hcx_dna_evolve(hcx_physick_atom_t *child, hcx_physick_atom_t *parent_a,
    hcx_physick_atom_t *parent_b);

hcx_boole_t hcx_dna_start();

void hcx_dna_stop();

#endif
