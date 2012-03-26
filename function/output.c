#include "ih/computer/output.h"
#include "ih/external/external.h"

void ih_computer_output_free(ih_computer_output_t *output) {}

void ih_computer_output_init(ih_computer_output_t *output)
{
  memset(output->bits, 0, IH_COMPUTER_OUTPUT_BITS);
}
