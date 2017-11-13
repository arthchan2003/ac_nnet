#include "sphinxbase/prim_type.h"


#ifndef AC_MATRIX_H
#define AC_MATRIX_H

typedef struct matrix_s {
    float32 **mat;
    int32 nrow;
    int32 ncol;
} matrix_t; 

matrix_t *matrix_init(int32 nrow, int32 ncol);

void multiply (matrix_t *out_c, matrix_t *a, matrix_t *b);

void matrix_free(matrix_t *m);

#endif /* AC_MATRIX_H */ 
