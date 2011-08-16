#ifndef hcx_plane_h
#define hcx_plane_h

#include "value.h"

typedef hcx_value_t hcx_plane_t[HCX_VALUE_COUNT][HCX_VALUE_COUNT];

hcx_value_t hcx_plane_pull(hcx_plane_t plane);
void hcx_plane_push(hcx_plane_t plane, hcx_value_t value);
void hcx_plane_randomize(hcx_plane_t plane);
void hcx_plane_shuffle(hcx_plane_t plane);
void hcx_plane_swap_values(hcx_plane_t plane, hcx_value_t position_a_x,
    hcx_value_t position_a_y, hcx_value_t position_b_x,
    hcx_value_t position_b_y);
void hcx_plane_zero(hcx_plane_t plane);

#endif
