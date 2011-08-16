#include "plane.h"

hcx_value_t hcx_plane_pull(hcx_plane_t plane)
{
  hcx_value_t other_position_x = hcx_value_rand();
  hcx_value_t other_position_y = hcx_value_rand();
  hcx_value_t value = plane[0][0];

  plane[0][0] = plane[other_position_x][other_position_y];

  return value;
}

void hcx_plane_push(hcx_plane_t plane, hcx_value_t value)
{
  hcx_value_t other_position_x = hcx_value_rand();
  hcx_value_t other_position_y = hcx_value_rand();

  plane[other_position_x][other_position_y] = plane[0][0];
  plane[0][0] = value;
}

void hcx_plane_randomize(hcx_plane_t plane)
{
  unsigned short x;
  unsigned short y;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      plane[x][y] = hcx_value_rand();
    }
  }
}

void hcx_plane_shuffle(hcx_plane_t plane)
{
  unsigned short x;
  unsigned short y;
  hcx_value_t other_position_x;
  hcx_value_t other_position_y;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      other_position_x = hcx_value_rand();
      other_position_y = hcx_value_rand();
      hcx_plane_swap_values(plane, x, y, other_position_x, other_position_y);
    }
  }
}

void hcx_plane_swap_values(hcx_plane_t plane, hcx_value_t position_a_x,
    hcx_value_t position_a_y, hcx_value_t position_b_x,
    hcx_value_t position_b_y)
{
  hcx_value_t value = plane[position_a_x][position_a_y];
  plane[position_a_x][position_a_y] = plane[position_b_x][position_b_y];
  plane[position_b_x][position_b_y] = value;
}

void hcx_plane_zero(hcx_plane_t plane)
{
  unsigned short x;
  unsigned short y;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      plane[x][y] = 0;
    }
  }
}
