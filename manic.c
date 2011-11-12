/*
  manic (a simple program that dreams)
  :: created in 2011 by zha (clownfysh@panix.com)
  :: from notes made in tyler two (http://clownfysh.com/manic)
  :: gcc -O3 -o manic manic.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define NODE_COUNT 70

#define EYES_OPEN_THRESHHOLD_START_NODE 172  /*  <= NODE_COUNT - 8  */
#define STAGNANCY_THRESHHOLD_START_NODE 217  /*  <= NODE_COUNT - 8  */

#define get_bit(value, bit_index) ((value >> bit_index) & 1)

#define trace(message, ...) fprintf(stderr, message "() in %s:%d\n",  \
      ##__VA_ARGS__, __FILE__, __LINE__)

#define trace_exit(message, ...) fprintf(stderr, message"() in %s:%d\n", \
      ##__VA_ARGS__, __FILE__, __LINE__); exit(22);

typedef unsigned char node_id_t;
typedef unsigned char node_value_t;

enum bool_t {
  bool_false,
  bool_true
};
typedef enum bool_t bool_t;

enum state_t {
  state_manic,
  state_sleep,
  state_awake,
  state_dprss
};
typedef enum state_t state_t;

struct node_t {
  unsigned char operator;
  node_id_t input_node_0;
  node_id_t input_node_1;
  node_id_t input_node_2;
  node_value_t value;
  unsigned char stagnancy;
};
typedef struct node_t node_t;

struct manic_t {
  node_t nodes[NODE_COUNT];
  unsigned char input_count;
  unsigned char output_count;
  unsigned char input_nodes[32];
  unsigned char output_nodes[32];
  node_id_t current_node;
  state_t state;
  float training_correlation;
  unsigned char eyes_open_threshhold;
  bool_t eyes_open_threshhold_valid;
  unsigned char stagnancy_threshhold;
  bool_t stagnancy_threshhold_valid;
};
typedef struct manic_t manic_t;

/*
unsigned char eca[256][2][2][2] = {
  {},
};
*/

manic_t *create(unsigned char input_count, unsigned char output_count);
manic_t *create_import(char *encoded_manic, unsigned char input_count,
    unsigned char output_count);
manic_t *copy(manic_t *manic);
void copy_in(manic_t *manic, ...);
void copy_out(manic_t *manic, ...);
void destroy(manic_t *manic);
char *export(manic_t *manic);
char *export_c(manic_t *manic);
float get_training_correlation(manic_t *manic);
/*  uuid_t get_uuid(manic_t *manic);  */
void import(manic_t *manic, char *encoded_manic);
/*  void set_uuid(manic_t *manic, uuid_t uuid);  */
void tick(manic_t *manic, ...);
void tick_multiple(manic_t *manic, unsigned short tick_count, ...);
void train(manic_t *manic, ...);

static void calculate_node_value(manic_t *manic, unsigned short node_index);
static void dream(manic_t *manic, unsigned short node_index);
static bool_t eye_is_open(manic_t *manic);
static unsigned char get_eyes_open_threshhold(manic_t *manic);
static unsigned char get_stagnancy_threshhold(manic_t *manic);
static void increment_stagnancy_and_possibly_dream(manic_t *manic,
    unsigned short node_index);
static void input_node_value(manic_t *manic, unsigned short node_index);
static void init_nodes(manic_t *manic);
static bool_t node_is_stagnant(manic_t *manic, unsigned short node_index);
static void set_node_value(manic_t *manic, unsigned short node_index,
    node_value_t value);
static bool_t within_range(unsigned short value, unsigned short lower_bound,
    unsigned short upper_bound);
unsigned long wrap_index(long virtual_index, unsigned long range);

void calculate_node_value(manic_t *manic, unsigned short node_index)
{
  node_t *node = manic->nodes + node_index;
  node_value_t old_value;
  node_value_t new_value;
  node_value_t input_value_0;
  node_value_t input_value_1;
  node_value_t input_value_2;
  unsigned char neighborhood;

  old_value = node->value;

  input_value_0 = (*(manic->nodes + node->input_node_0)).value;
  input_value_1 = (*(manic->nodes + node->input_node_1)).value;
  input_value_2 = (*(manic->nodes + node->input_node_2)).value;
  /*  TODO: make this a lookup table  */
  neighborhood = (input_value_0 * 4) + (input_value_1 * 2) + input_value_2;
  new_value = get_bit(node->operator, neighborhood);

  set_node_value(manic, node_index, new_value);
  if (old_value == new_value) {
    increment_stagnancy_and_possibly_dream(manic, node_index);
  }
}

manic_t *create(unsigned char input_count, unsigned char output_count)
{
  manic_t *manic;

  manic = malloc(sizeof *manic);
  if (manic) {
    init_nodes(manic);
    manic->input_count = input_count;
    manic->output_count = output_count;
    manic->eyes_open_threshhold_valid = bool_false;
    manic->stagnancy_threshhold_valid = bool_false;
  } else {
    trace("malloc");
  }

  return manic;
}

manic_t *create_import(char *encoded_manic, unsigned char input_count,
    unsigned char output_count)
{
  return NULL;
}

manic_t *copy(manic_t *manic)
{
  return NULL;
}

void copy_in(manic_t *manic, ...)
{
}

void copy_out(manic_t *manic, ...)
{
}

void destroy(manic_t *manic)
{
  free(manic);
}

void dream(manic_t *manic, unsigned short node_index)
{
  node_t *node = manic->nodes + node_index;

  node->operator = random() % 256;
  node->input_node_0 = random() % NODE_COUNT;
  node->input_node_1 = random() % NODE_COUNT;
  node->input_node_2 = random() % NODE_COUNT;
  set_node_value(manic, node_index, random() % 2);
  node->stagnancy = 0;
}

char *export(manic_t *manic)
{
  return NULL;
}

char *export_c(manic_t *manic)
{
  return NULL;
}

bool_t eye_is_open(manic_t *manic)
{
  return (random() % 256) >= get_eyes_open_threshhold(manic);
}

float get_training_correlation(manic_t *manic)
{
  return manic->training_correlation;
}

unsigned char get_eyes_open_threshhold(manic_t *manic)
{
  if (!manic->eyes_open_threshhold_valid) {
    manic->eyes_open_threshhold
      = (128 * (manic->nodes + (EYES_OPEN_THRESHHOLD_START_NODE + 0))->value)
      + (64 * (manic->nodes + (EYES_OPEN_THRESHHOLD_START_NODE + 1))->value)
      + (32 * (manic->nodes + (EYES_OPEN_THRESHHOLD_START_NODE + 2))->value)
      + (16 * (manic->nodes + (EYES_OPEN_THRESHHOLD_START_NODE + 3))->value)
      + (8 * (manic->nodes + (EYES_OPEN_THRESHHOLD_START_NODE + 4))->value)
      + (4 * (manic->nodes + (EYES_OPEN_THRESHHOLD_START_NODE + 5))->value)
      + (2 * (manic->nodes + (EYES_OPEN_THRESHHOLD_START_NODE + 6))->value)
      + (1 * (manic->nodes + (EYES_OPEN_THRESHHOLD_START_NODE + 7))->value);
    manic->eyes_open_threshhold_valid = bool_true;
  }

  return manic->eyes_open_threshhold;
}

unsigned char get_stagnancy_threshhold(manic_t *manic)
{
  if (!manic->stagnancy_threshhold_valid) {
    manic->stagnancy_threshhold
      = (128 * (manic->nodes + (STAGNANCY_THRESHHOLD_START_NODE + 0))->value)
      + (64 * (manic->nodes + (STAGNANCY_THRESHHOLD_START_NODE + 1))->value)
      + (32 * (manic->nodes + (STAGNANCY_THRESHHOLD_START_NODE + 2))->value)
      + (16 * (manic->nodes + (STAGNANCY_THRESHHOLD_START_NODE + 3))->value)
      + (8 * (manic->nodes + (STAGNANCY_THRESHHOLD_START_NODE + 4))->value)
      + (4 * (manic->nodes + (STAGNANCY_THRESHHOLD_START_NODE + 5))->value)
      + (2 * (manic->nodes + (STAGNANCY_THRESHHOLD_START_NODE + 6))->value)
      + (1 * (manic->nodes + (STAGNANCY_THRESHHOLD_START_NODE + 7))->value);
    manic->eyes_open_threshhold_valid = bool_true;
  }

  return manic->stagnancy_threshhold;
}

/*
uuid_t get_uuid(manic_t *manic)
{
  return manic->uuid;
}
*/

void import(manic_t *manic, char *encoded_manic)
{
}

void increment_stagnancy_and_possibly_dream(manic_t *manic,
    unsigned short node_index)
{
  node_t *node = manic->nodes + node_index;

  node->stagnancy++;
  if (node_is_stagnant(manic, node_index)) {
    dream(manic, node_index);
  }
}

void init_nodes(manic_t *manic)
{
  unsigned short node_index;
  node_t *node;

  for (node_index = 0; node_index < NODE_COUNT; node_index++) {
    node = manic->nodes + node_index;
    dream(manic, node_index);
  }
}

void input_node_value(manic_t *manic, unsigned short node_index)
{
  node_t *node = manic->nodes + node_index;
  node_value_t old_value;
  node_value_t new_value;
  unsigned short input_node_index;

  old_value = node->value;
  input_node_index = *(manic->input_nodes + node_index);
  new_value = (manic->nodes + input_node_index)->value;

  set_node_value(manic, node_index, new_value);
  if (old_value == new_value) {
    increment_stagnancy_and_possibly_dream(manic, node_index);
  }
}

bool_t node_is_stagnant(manic_t *manic, unsigned short node_index)
{
  return node_index >= get_stagnancy_threshhold(manic);
}

void set_node_value(manic_t *manic, unsigned short node_index,
    node_value_t value)
{
  if (within_range(node_index, EYES_OPEN_THRESHHOLD_START_NODE,
          EYES_OPEN_THRESHHOLD_START_NODE + 8)) {
    manic->eyes_open_threshhold_valid = bool_false;
  }
  if (within_range(node_index, STAGNANCY_THRESHHOLD_START_NODE,
          STAGNANCY_THRESHHOLD_START_NODE + 8)) {
    manic->stagnancy_threshhold_valid = bool_false;
  }
  (manic->nodes + node_index)->value = value;
}

/*
void set_uuid(manic_t *manic, uuid_t uuid)
{
}
*/

void tick(manic_t *manic, ...)
{
  unsigned short node_index = random() % NODE_COUNT;

  if ((node_index < manic->input_count) && eye_is_open(manic)) {
    input_node_value(manic, node_index);
  } else {
    calculate_node_value(manic, node_index);
  }

}

void tick_multiple(manic_t *manic, unsigned short tick_count, ...)
{
  unsigned short i;

  for (i = 0; i < tick_count; i++) {
    tick(manic);
  }
}

void train(manic_t *manic, ...)
{
}

bool_t within_range(unsigned short value, unsigned short lower_bound,
    unsigned short upper_bound)
{
  bool_t within;

  if ((value >= lower_bound) && (value <= upper_bound)) {
    within = bool_true;
  } else {
    within = bool_false;
  }

  return within;
}

unsigned long wrap_index(long virtual_index, unsigned long range)
{
  unsigned long wrapped_index;

  if (virtual_index >= (long) range) {
    wrapped_index = virtual_index % range;
  } else if (virtual_index < 0) {
    if (1 == range) {
      wrapped_index = 0;
    } else {
      wrapped_index = range - ((-1 * virtual_index) % range);
    }
  } else {
    wrapped_index = virtual_index;
  }

  return wrapped_index;
}

int main(int argc, char* argv[])
{
  manic_t *manic;
  unsigned char input_count = 0;
  unsigned char output_count = 0;
  unsigned short node_index;
  unsigned short x;
  unsigned short y;
  char c;

  manic = create(input_count, output_count);

  while (1) {
    tick(manic);

    for (node_index = 0; node_index < NODE_COUNT; node_index++) {
      if ((manic->nodes + node_index)->value) {
        c = '+';
      } else {
        c = ' ';
      }
      printf("%c", c);
    }
    printf("\n");

    /*  usleep(1024);  */
  }

  manic_destroy(manic);

  return 0;
}
