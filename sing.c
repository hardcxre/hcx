#include "physick.h"
#include "sing.h"
#include "standard.h"
#include "trace.h"

struct node_t {
  physick_atom_id_t container;
  physick_atom_id_t parts[SING_POINT_COUNT];
  physick_atom_t atom;

  /*
    ? is_initialized
  */

};
typedef struct node_t node_t;

struct sing_t {
  node_t *nodes;
  physick_atom_id_t cynosure;
};
typedef struct sing_t sing_t;

static sing_t sing;
static physick_atom_id_t focus_distance_to_node_id[PHYSICK_ATOM_COUNT];
static physick_atom_id_t node_id_to_focus_distance[PHYSICK_ATOM_COUNT];

static void focus(node_t *node);
static void init_focus_distances();
static void update_focus_distances(physick_atom_id_t node_id,
    physick_atom_id_t swap_focus_distance);

void focus(node_t *node)
{
  /*
  physick_spark(physick_atom_t *atom, physick_atom_t *neighbor_a,
      physick_atom_t *neighbor_b, physick_atom_t *neighbor_c);
  */

  /*
  void dna_evolve(physick_atom_t *child, physick_atom_t *parent_a,
      physick_atom_t *parent_b);
  */
}

void init_focus_distances()
{
  physick_atom_id_t node_id;

  for (node_id = 0; node_id < PHYSICK_ATOM_COUNT; node_id++) {
    *(focus_distance_to_node_id + node_id) = node_id;
    *(node_id_to_focus_distance + node_id) = node_id;
  }
}

boole_t sing_start()
{
  sing.cynosure = 0;
  init_focus_distances();

  sing.nodes = malloc(PHYSICK_ATOM_COUNT * sizeof(node_t));
  if (sing.nodes) {

  } else {
    hcx_trace("malloc");
  }

  return boole_false;
}

void sing_stop()
{
  free(sing.nodes);
}

void sing_tick()
{
  node_t *node;
  physick_atom_id_t node_id;
  physick_atom_id_t i;
  physick_atom_id_t part_node_id;
  physick_atom_id_t skip_node_id = 0;
  physick_atom_id_t focus_distance = 0;

  /*
    update this to do the n=N style simulate/sing::tick
  */
  node_id = sing.cynosure;
  while (boole_true) {
    node = sing.nodes + node_id;
    for (i = 0; i < SING_POINT_COUNT; i++) {
      part_node_id = *(node->parts + i);
      if (part_node_id && (part_node_id != skip_node_id)) {
        focus(node);
        update_focus_distances(node_id, focus_distance);
        focus_distance++;
      }
    }
    if (0 == node_id) {
      break;
    }
    skip_node_id = node_id;
    node_id = node->container;
  }
}

void update_focus_distances(physick_atom_id_t node_id,
    physick_atom_id_t swap_node_focus_distance)
{
  physick_atom_id_t swap_node_id;
  physick_atom_id_t node_focus_distance;

  swap_node_id = *(focus_distance_to_node_id + swap_node_focus_distance);
  node_focus_distance = *(node_id_to_focus_distance + node_id);

  *(focus_distance_to_node_id + swap_node_focus_distance) = node_id;
  *(focus_distance_to_node_id + node_focus_distance) = swap_node_id;

  *(node_id_to_focus_distance + node_id) = swap_node_focus_distance;
  *(node_id_to_focus_distance + swap_node_id) = node_focus_distance;
}
