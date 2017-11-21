#include "matrix.h"
#include <assert.h>
#include "sphinxbase/prim_type.h"
#include "sphinxbase/ckd_alloc.h"

matrix_t *matrix_init(int32 nrow, int32 ncol)
{
    matrix_t *m= NULL;
    m->mat = ckd_calloc_2d(nrow, ncol, sizeof(float32));
    m->nrow = nrow;
    m->ncol = ncol;
    
    return m;
}

void matrix_display(matrix_t *m)
{
    int i,j;
    for (i= 0 ; i< m->nrow; i++){
        for (j= 0 ; j < m->ncol; j++){
            printf ("%f ", m->mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//range is the [0, range]
matrix_t *matrix_random_init(int32 nrow, int32 ncol, float32 range)
{
    matrix_t *m = NULL;
    m = matrix_init(nrow, ncol);

    int32 i,j;
    
    for (i= 0; i< m->nrow ; i++){

        for (j=0 ; j <m->ncol ; j++){
            float32 x=(float32)rand()/((float32)RAND_MAX/range);
            m->mat[i][j] = x ; 
        }
    }

}

void add_to_a(matrix_t *a, matrix_t *b)
{
    assert (a->ncol == b->ncol && a->nrow == b->nrow);
    int32 i, j;

    for (i=0; i<a->nrow;i++){
        for (j=0 ; j< a->ncol;j++){
            a->mat[i][j] += b->mat[i][j];
        }
    }
    
}

void scale_a(matrix_t *a, float scale)
{
    int32 i,j;
    for (i=0; i<a->nrow;i++){
        for (j=0 ; j< a->ncol;j++){
            a->mat[i][j] *= scale;
        }
    }
}

void add (matrix_t *out_c, matrix_t *a, matrix_t *b)
{
    assert (a->ncol == b->ncol && a->nrow == b->nrow);

    out_c->nrow = a->nrow;
    out_c->ncol = a->ncol;

    int32 i, j;
    for (i=0; i<out_c->nrow;i++){
        for (j=0 ; j< out_c->ncol;j++){
            out_c->mat[i][j] = a->mat[i][j] + b->mat[i][j];
        }
    }
}

void multiply (matrix_t *out_c, matrix_t *a, matrix_t *b)
{
    assert (a->ncol == b->nrow);
    int32 new_row = a->nrow;
    int32 new_col = b->ncol;
    int32 i=0,j=0,k=0;
    float32 val=0;

    out_c->nrow = new_row;
    out_c->ncol = new_col;

    for (i=0;i<new_row;i++){
        for (j=0;j<new_col; j++){
                
            val=0;
            for (k=0; k< a->ncol ; k++){
                val+= a->mat[i][k] * b->mat[k][j];
            }
            out_c->mat[i][j]=val;
        }
    }
        
}


void matrix_free(matrix_t *m)
{
    ckd_free_2d (m->mat);
    m->mat = NULL;
    ckd_free(m);
}
