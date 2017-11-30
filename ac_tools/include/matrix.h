#include "sphinxbase/prim_type.h"


#ifndef AC_MATRIX_H
#define AC_MATRIX_H

typedef struct matrix_s {
    float32 **mat;
    int32 nrow;
    int32 ncol;
} matrix_t; 

matrix_t *matrix_init(int32 nrow, int32 ncol);

matrix_t *matrix_init_with_array (int32 nrow, int32 ncol, float32 array[]);

//range is the [0, range]
matrix_t *matrix_random_init(int32 nrow, int32 ncol, float32 range);

void matrix_display(matrix_t *m);

void matrix_add_to_a(matrix_t *a, matrix_t *b);

void matrix_scale_a(matrix_t *a, float scale);

void matrix_copy_to_a_from_b (matrix_t *a, matrix_t *b);

void matrix_multiply (matrix_t *out_c, matrix_t *a, matrix_t *b);

int32 matrix_equal(matrix_t *a, matrix_t *b);

void maatrix_add (matrix_t *out_c, matrix_t *a, matrix_t *b);

void matrix_free(matrix_t *m);

int32 matrix_equal(matrix_t *a, matrix_t *b);


//matrix_t *matrix_random_init(int32 nrow, int32 ncol, float32 range);


#endif /* AC_MATRIX_H */ 
