#ifndef sing_h
#define sing_h

#include "boole.h"

typedef unsigned char sing_scale_t;
#define SING_SCALE_COUNT (256 - 1)

typedef char sing_dimension_t;

typedef unsigned char sing_point_id_t;
#define SING_POINT_COUNT (256 - 1)

struct sing_point_t {
  sing_dimension_t x;
  sing_dimension_t y;
  sing_dimension_t z;
};
typedef struct sing_point_t sing_point_t;

typedef unsigned char sing_geometry_id_t;
#define SING_GEOMETRY_COUNT (256 - 1)

struct sing_geometry_t {
  sing_point_t points[SING_POINT_COUNT];
};
typedef struct sing_geometry_t sing_geometry_t;

boole_t sing_start();
void sing_stop();
void sing_tick();

#endif
