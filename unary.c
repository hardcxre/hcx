#include "standard.h"
#include "trace.h"
#include "unary.h"

void hcx_unary_generate(hcx_unary_t *destination, hcx_unary_t *source_1,
    hcx_unary_t *source_2)
{
  unsigned short i;
  unsigned short cut_point = hcx_value_rand();

  for (i = 0; i < cut_point; i++) {
    (*destination)[i] = (*source_1)[i];
  }
  for (i = cut_point; i < HCX_VALUE_MAX; i++) {
    (*destination)[i] = (*source_2)[i];
  }

  (*destination)[hcx_value_rand()] = hcx_value_rand();
}

hcx_value_t hcx_unary_pull(hcx_unary_t unary)
{
  hcx_value_t other_position = hcx_value_rand();
  hcx_value_t value = unary[0];

  unary[0] = unary[other_position];

  return value;
}

void hcx_unary_push(hcx_unary_t unary, hcx_value_t value)
{
  hcx_value_t other_position = hcx_value_rand();
  unary[other_position] = unary[0];
  unary[0] = value;
}

void hcx_unary_randomize(hcx_unary_t unary)
{
  unsigned short x;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    unary[x] = hcx_value_rand();
  }
}

void hcx_unary_shuffle(hcx_unary_t unary)
{
  unsigned short x;
  hcx_value_t other_position;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    other_position = hcx_value_rand();
    hcx_unary_swap_values(unary, x, other_position);
  }
}

void hcx_unary_swap_values(hcx_unary_t unary, hcx_value_t position_a,
    hcx_value_t position_b)
{
  hcx_value_t value = unary[position_a];
  unary[position_a] = unary[position_b];
  unary[position_b] = value;
}

void hcx_unary_zero(hcx_unary_t unary)
{
  unsigned short x;

  for (x = 0; x < HCX_VALUE_COUNT; x++) {
    unary[x] = 0;
  }
}
