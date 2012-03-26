#include "standard.h"
#include "ternary.h"
#include "trace.h"

hcx_value_t hcx_ternary_pull(hcx_ternary_t ternary)
{
  hcx_value_t other_position_x = hcx_value_rand();
  hcx_value_t other_position_y = hcx_value_rand();
  hcx_value_t other_position_z = hcx_value_rand();
  hcx_value_t value = ternary[0][0][0];

  ternary[0][0][0]
    = ternary[other_position_x][other_position_y][other_position_z];

  return value;
}

void hcx_ternary_push(hcx_ternary_t ternary, hcx_value_t value)
{
  hcx_value_t other_position_x = hcx_value_rand();
  hcx_value_t other_position_y = hcx_value_rand();
  hcx_value_t other_position_z = hcx_value_rand();

  ternary[other_position_x][other_position_y][other_position_z]
    = ternary[0][0][0];
  ternary[0][0][0] = value;
}

void hcx_ternary_randomize(hcx_ternary_t ternary)
{
  unsigned short x;
  unsigned short y;
  unsigned short z;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      for (z = 0; z < HCX_VALUE_COUNT; z++) {
        ternary[x][y][z] = hcx_value_rand();
      }
    }
  }
}

void hcx_ternary_shuffle(hcx_ternary_t ternary)
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
        hcx_ternary_swap_values(ternary, x, y, z,
            other_position_x, other_position_y, other_position_z);
      }
    }
  }
}

void hcx_ternary_swap_values(hcx_ternary_t ternary, hcx_value_t position_a_x,
    hcx_value_t position_a_y, hcx_value_t position_a_z,
    hcx_value_t position_b_x, hcx_value_t position_b_y,
    hcx_value_t position_b_z)
{
  hcx_value_t value = ternary[position_a_x][position_a_y][position_a_z];
  ternary[position_a_x][position_a_y][position_a_z]
    = ternary[position_b_x][position_b_y][position_b_z];
  ternary[position_b_x][position_b_y][position_b_z] = value;
}

void hcx_ternary_zero(hcx_ternary_t ternary)
{
  unsigned short x;
  unsigned short y;
  unsigned short z;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      for (z = 0; z < HCX_VALUE_COUNT; z++) {
        ternary[x][y][z] = 0;
      }
    }
  }
}
