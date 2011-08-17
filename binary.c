#include "binary.h"
#include "standard.h"
#include "trace.h"

hcx_value_t hcx_binary_pull(hcx_binary_t binary)
{
  hcx_value_t other_position_x = hcx_value_rand();
  hcx_value_t other_position_y = hcx_value_rand();
  hcx_value_t value = binary[0][0];

  binary[0][0] = binary[other_position_x][other_position_y];

  return value;
}

void hcx_binary_push(hcx_binary_t binary, hcx_value_t value)
{
  hcx_value_t other_position_x = hcx_value_rand();
  hcx_value_t other_position_y = hcx_value_rand();

  binary[other_position_x][other_position_y] = binary[0][0];
  binary[0][0] = value;
}

void hcx_binary_randomize(hcx_binary_t binary)
{
  unsigned short x;
  unsigned short y;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      binary[x][y] = hcx_value_rand();
    }
  }
}

void hcx_binary_shuffle(hcx_binary_t binary)
{
  unsigned short x;
  unsigned short y;
  hcx_value_t other_position_x;
  hcx_value_t other_position_y;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      other_position_x = hcx_value_rand();
      other_position_y = hcx_value_rand();
      hcx_binary_swap_values(binary, x, y, other_position_x, other_position_y);
    }
  }
}

void hcx_binary_swap_values(hcx_binary_t binary, hcx_value_t position_a_x,
    hcx_value_t position_a_y, hcx_value_t position_b_x,
    hcx_value_t position_b_y)
{
  hcx_value_t value = binary[position_a_x][position_a_y];
  binary[position_a_x][position_a_y] = binary[position_b_x][position_b_y];
  binary[position_b_x][position_b_y] = value;
}

void hcx_binary_zero(hcx_binary_t binary)
{
  unsigned short x;
  unsigned short y;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    for (y = 0; y < HCX_VALUE_COUNT; y++) {
      binary[x][y] = 0;
    }
  }
}
