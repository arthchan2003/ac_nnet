#include "matrix.h"
#include <stdio.h>
#include <assert.h>
#include "sphinxbase/prim_type.h"
#include "sphinxbase/ckd_alloc.h"

matrix_t *matrix_init(int32 nrow, int32 ncol)
{
    matrix_t *m= NULL;
    m=ckd_calloc(1, sizeof(matrix_t));
    m->mat = ckd_calloc_2d(nrow, ncol, sizeof(float32));
    m->nrow = nrow;
    m->ncol = ncol;
    
    return m;
}

matrix_t *matrix_init_with_array (int32 nrow, int32 ncol, float32 array[])
{
    matrix_t *m = matrix_init(nrow, ncol);

    int32 l=0;
    int i,j;
    for (i=0 ; i< m->nrow ; i++){
        for (j=0 ; j < m->ncol ;j++){
            m->mat[i][j] = array[l];
            l++;
        }
    }
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

void matrix_permute_rows (matrix_t *m, int row1, int row2)
{
    float tmp;
    assert (row1 >=0 && row1 < m->nrow);
    assert (row2 >=0 && row2 < m->nrow);
    int j;

    for (j=0 ; j < m->ncol ;  j++){
        
        tmp = m->mat[row1][j]; 
        m->mat[row1][j] = m->mat[row2][j];
        m->mat[row2][j] = tmp;

    }
    
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

    return m;
}

void matrix_add_to_a(matrix_t *a, matrix_t *b)
{
    assert (a->ncol == b->ncol && a->nrow == b->nrow);
    int32 i, j;

    for (i=0; i<a->nrow;i++){
        for (j=0 ; j< a->ncol;j++){
            a->mat[i][j] += b->mat[i][j];
        }
    }
    
}


void matrix_scale_a(matrix_t *a, float scale)
{
    int32 i,j;
    for (i=0; i<a->nrow;i++){
        for (j=0 ; j< a->ncol;j++){
            a->mat[i][j] *= scale;
        }
    }
}

void matrix_copy_to_a_from_b (matrix_t *a, matrix_t *b)
{
    assert (a->ncol == b->ncol && a->nrow == b->nrow);
    int32 i,j;
    for (i=0; i<a->nrow;i++){
        for (j=0 ; j< a->ncol;j++){
            a->mat[i][j] = b->mat[i][j];
        }
    }
}

int32 matrix_equal(matrix_t *a, matrix_t *b)
{
    if (a->ncol != b->ncol || a->nrow != b->nrow)
        return 0;

    int32 i,j;
    for (i=0; i<a->nrow;i++){
        for (j=0 ; j< a->ncol;j++){
            if (a->mat[i][j] != b->mat[i][j])
                return 0;
        }
    }
    return 1;
}

int32 matrix_verify(matrix_t *a, matrix_t *b){
    return matrix_equal(a,b);
}

void matrix_add (matrix_t *out_c, matrix_t *a, matrix_t *b)
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

void matrix_square_transpose(matrix_t *a)
{
    assert (a->nrow == a->ncol);

    int32 i,j;
    float32 tmp;
    for (i=0; i< a->nrow ; i++){
        for (j=i+1; j < a->ncol ; j++){
            tmp =  a->mat[j][i];
            a->mat[j][i] = a->mat[i][j];
            a->mat[i][j] = tmp;
        }
    }
}


void matrix_multiply (matrix_t *out_c, matrix_t *a, matrix_t *b)
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
