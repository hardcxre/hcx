#ifndef mosaic_h
#define mosaic_h

#include "sing.h"

#define MOSAIC_PIECE_COUNT SING_POINT_COUNT

struct mosaic_piece_t;
typedef struct mosaic_piece_t mosaic_piece_t;

struct mosaic_piece_t {
  sing_geometry_t *geometry;
  mosaic_piece_t *arrangement[SING_POINT_COUNT];
};

struct mosaic_t {
  mosaic_piece_t pieces[MOSAIC_PIECE_COUNT];
};
typedef struct mosaic_t mosaic_t;

#endif
