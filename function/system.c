#include "ih/computer/system.h"
#include "ih/core/tools.h"
#include "ih/external/external.h"

struct ih_computer_system_t {
  unsigned long order;
  ih_computer_logic_f logic;
  ih_computer_output_t *computations;
};

static void compute_witih_logic(ih_computer_system_t *system);

static void free_computations(ih_computer_system_t *system);

static void init_computations(ih_computer_system_t *system);

void compute_witih_logic(ih_computer_system_t *system)
{
  assert(system);
  unsigned long each_computation;

  for (each_computation = 0; each_computation < system->order;
       each_computation++) {
    system->logic(each_computation, system->computations + each_computation);
  }
}

ih_computer_output_t *ih_computer_system_compute(ih_computer_system_t *system,
    unsigned long input)
{
  return system->computations + input;
}

ih_computer_system_t *ih_computer_system_create(unsigned long order,
    ih_computer_logic_f logic)
{
  ih_computer_system_t *system;

  system = malloc(sizeof *system);
  if (system) {
    system->order = order;
    system->logic = logic;
    system->computations = malloc(order * sizeof(ih_computer_output_t));
    if (system->computations) {
      init_computations(system);
      compute_witih_logic(system);
    } else {
      ih_core_trace("malloc");
      free(system);
      system = NULL;
    }
  } else {
    ih_core_trace("malloc");
  }

  return system;
}

ih_computer_system_t *ih_computer_system_create_from_file(char *filename)
{
  ih_core_trace_exit("TODO: implement");
  return NULL;
}

void ih_computer_system_destroy(void *system_object)
{
  assert(system_object);
  ih_computer_system_t *system;

  system = system_object;

  free_computations(system);
  free(system->computations);
  free(system);
}

char *ih_computer_system_get_as_string(void *system_object)
{
  assert(system_object);
  ih_computer_system_t *system;
  unsigned long string_size;
  char *string;
  unsigned long each_computation;
  unsigned long each_bit;
  unsigned long string_position;
  ih_computer_output_t *output;
  ih_core_bit_t bit;

  system = system_object;

  string_size = (IH_COMPUTER_OUTPUT_BITS + 1) * system->order;
  string = malloc(string_size + 1);
  if (string) {
    string_position = 0;
    for (each_computation = 0; each_computation < system->order;
         each_computation++) {
      for (each_bit = 0; each_bit < IH_COMPUTER_OUTPUT_BITS; each_bit++) {
        output = system->computations + each_computation;
        bit = *(output->bits + each_bit);
        if (bit) {
          *(string + string_position) = '1';
        } else {
          *(string + string_position) = '0';
        }
        string_position++;
      }
      *(string + string_position) = '\n';
      string_position++;
    }
    *(string + string_position) = '\0';
  } else {
    ih_core_trace("malloc");
  }

  return string;
}

void ih_computer_system_print(ih_computer_system_t *system)
{
  assert(system);
  char *string;

  string = ih_computer_system_get_as_string(system);
  if (string) {
    printf("%s", string);
    free(string);
  } else {
    ih_core_trace("ih_computer_system_get_as_string");
  }
}

ih_core_bool_t ih_computer_system_save_as_file(ih_computer_system_t *system,
    char *filename)
{
  ih_core_trace_exit("TODO: implement");
  return ih_core_bool_false;
}

void free_computations(ih_computer_system_t *system)
{
  unsigned long each_computation;

  for (each_computation = 0; each_computation < system->order;
       each_computation++) {
    ih_computer_output_free(system->computations + each_computation);
  }
}

void init_computations(ih_computer_system_t *system)
{
  unsigned long each_computation;

  for (each_computation = 0; each_computation < system->order;
       each_computation++) {
    ih_computer_output_init(system->computations + each_computation);
  }
}
