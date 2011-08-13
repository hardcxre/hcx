#ifndef hcx_mosaic_h
#define hcx_mosaic_h

#include "sing.h"

#define HCX_MOSAIC_PIECE_COUNT HCX_SING_POINT_COUNT

struct hcx_mosaic_piece_t;
typedef struct hcx_mosaic_piece_t hcx_mosaic_piece_t;

struct hcx_mosaic_piece_t {
  hcx_sing_geometry_t *geometry;
  hcx_mosaic_piece_t *arrangement[HCX_SING_POINT_COUNT];
};

struct hcx_mosaic_t {
  hcx_mosaic_piece_t pieces[HCX_MOSAIC_PIECE_COUNT];
};
typedef struct hcx_mosaic_t hcx_mosaic_t;

#endif
