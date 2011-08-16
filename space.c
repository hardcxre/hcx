#include "space.h"

hcx_value_t hcx_space_pull(hcx_space_t space)
{
  hcx_value_t other_position_x = hcx_value_rand();
  hcx_value_t other_position_y = hcx_value_rand();
  hcx_value_t other_position_z = hcx_value_rand();
  hcx_value_t value = space[0][0][0];

  space[0][0][0] = space[other_position_x][other_position_y][other_position_z];

  return value;
}

void hcx_space_push(hcx_space_t space, hcx_value_t value)
{
  hcx_value_t other_position_x = hcx_value_rand();
  hcx_value_t other_position_y = hcx_value_rand();
  hcx_value_t other_position_z = hcx_value_rand();

  space[other_position_x][other_position_y][other_position_z] = space[0][0][0];
  space[0][0][0] = value;
}

void hcx_space_randomize(hcx_space_t space)
{
  unsigned short x;
  unsigned short y;
  unsigned short z;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      for (z = 0; z < HCX_VALUE_COUNT; z++) {
        space[x][y][z] = hcx_value_rand();
      }
    }
  }
}

void hcx_space_shuffle(hcx_space_t space)
{
  unsigned short x;
  unsigned short y;
  unsigned short z;
  hcx_value_t other_position_x;
  hcx_value_t other_position_y;
  hcx_value_t other_position_z;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      for (z = 0; z < HCX_VALUE_COUNT; z++) {
        other_position_x = hcx_value_rand();
        other_position_y = hcx_value_rand();
        other_position_z = hcx_value_rand();
        hcx_space_swap_values(space, x, y, z,
            other_position_x, other_position_y, other_position_z);
      }
    }
  }
}

void hcx_space_swap_values(hcx_space_t space, hcx_value_t position_a_x,
    hcx_value_t position_a_y, hcx_value_t position_a_z,
    hcx_value_t position_b_x, hcx_value_t position_b_y,
    hcx_value_t position_b_z)
{
  hcx_value_t value = space[position_a_x][position_a_y][position_a_z];
  space[position_a_x][position_a_y][position_a_z]
    = space[position_b_x][position_b_y][position_b_z];
  space[position_b_x][position_b_y][position_b_z] = value;
}

void hcx_space_zero(hcx_space_t space)
{
  unsigned short x;
  unsigned short y;
  unsigned short z;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      for (z = 0; z < HCX_VALUE_COUNT; z++) {
        space[x][y][z] = 0;
      }
    }
  }
}
