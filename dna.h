#ifndef dna_h
#define dna_h

#include "boole.h"
#include "physick.h"

void dna_evolve(physick_atom_t *child, physick_atom_t *parent_a,
    physick_atom_t *parent_b);
boole_t dna_start();
void dna_stop();

#endif
