#ifndef hcx_pile_h
#define hcx_pile_h

struct hcx_pile_t;
typedef struct hcx_pile_t hcx_pile_t;

/*
  TODO: add this to line, plane, and space?  use get/set for exact access and
  the methods below for fizzy access?
  rename find >> peek? browse? select? pull?
  rename add >> stash? push?
  push/pull is pretty good
*/

void hcx_pile_add(hcx_pile_t *pile, hcx_value_t value);
hcx_pile_t *hcx_pile_create();
void hcx_pile_destroy(hcx_pile_t *pile);
hcx_value_t hcx_pile_find(hcx_pile_t *pile);

#endif
