#ifndef hcx_sing_h
#define hcx_sing_h

#include "boole.h"

typedef unsigned char hcx_sing_scale_t;
#define HCX_SING_SCALE_COUNT (256 - 1)

typedef char hcx_sing_dimension_t;

typedef unsigned char hcx_sing_point_id_t;
#define HCX_SING_POINT_COUNT (256 - 1)

struct hcx_sing_point_t {
  hcx_sing_dimension_t x;
  hcx_sing_dimension_t y;
  hcx_sing_dimension_t z;
};
typedef struct hcx_sing_point_t hcx_sing_point_t;

typedef unsigned char hcx_sing_geometry_id_t;
#define HCX_SING_GEOMETRY_COUNT (256 - 1)

struct hcx_sing_geometry_t {
  hcx_sing_point_t points[HCX_SING_POINT_COUNT];
};
typedef struct hcx_sing_geometry_t hcx_sing_geometry_t;

hcx_boole_t hcx_sing_start();
void hcx_sing_stop();
void hcx_sing_tick();

#endif
