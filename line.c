#include "line.h"

hcx_value_t hcx_line_pull(hcx_line_t line)
{
  hcx_value_t other_position = hcx_value_rand();
  hcx_value_t value = line[0];

  line[0] = line[other_position];

  return value;
}

void hcx_line_push(hcx_line_t line, hcx_value_t value)
{
  hcx_value_t other_position = hcx_value_rand();
  line[other_position] = line[0];
  line[0] = value;
}

void hcx_line_randomize(hcx_line_t line)
{
  unsigned short i;

  for (i = 0; i < HCX_VALUE_COUNT; i++) {
    line[i] = hcx_value_rand();
  }
}

void hcx_line_shuffle(hcx_line_t line)
{
  unsigned short i;
  hcx_value_t other_position;

  for (i = 0; i < HCX_VALUE_COUNT; i++) {
    other_position = hcx_value_rand();
    hcx_line_swap_values(line, i, other_position);
  }
}

void hcx_line_swap_values(hcx_line_t line, hcx_value_t position_a,
    hcx_value_t position_b)
{
  hcx_value_t value = line[position_a];
  line[position_a] = line[position_b];
  line[position_b] = value;
}

void hcx_line_zero(hcx_line_t line)
{
  unsigned short i;

  for (i = 0; i < HCX_VALUE_COUNT; i++) {
    line[i] = 0;
  }
}
