#include "ih/computer/system.h"
#include "ih/core/tools.h"
#include "ih/external/external.h"

/*
  static void and_logic(unsigned long input, ih_computer_output_t *output);
*/

static void or_logic(unsigned long input, ih_computer_output_t *output);

void and_logic(unsigned long input, ih_computer_output_t *output)
{
  assert(output);

  if (3 == input) {
    *(output->bits + 0) = 1;
  }
}

void or_logic(unsigned long input, ih_computer_output_t *output)
{
  assert(output);

  if (input != 0) {
    *(output->bits + 0) = 1;
  }
}

int main(int argc, char *argv[])
{
  ih_computer_system_t *ih_computer_system;
  ih_computer_output_t *ih_computer_output;
  unsigned short each_input;

  ih_computer_system = ih_computer_system_create(4, or_logic);
  if (!ih_computer_system) {
    ih_core_trace_exit("ih_computer_system_create");
  }

  ih_computer_system_print(ih_computer_system);

  for (each_input = 0; each_input < 4; each_input++) {
    ih_computer_output = ih_computer_system_compute(ih_computer_system, each_input);
    printf("%i -> %i\n", each_input, *(ih_computer_output->bits + 0));
  }

  ih_computer_system_destroy(ih_computer_system);

  return 0;
}
