#include "matrix.h"
#include "sphinxbase/prim_type.h"
#include "sphinxbase/ckd_alloc.h"

matrix_t *matrix_init(int32 nrow, int32 ncol)
{
    matrix_t *m= NULL;
    m = ckd_calloc_2d(nrow, ncol, sizeof(float32));
    return m;

}

void multiply (matrix_t *out_c, matrix_t *a, matrix_t *b)
{
    if (a->ncol != b->nrow)
        out_c = NULL;
    else {
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
        
}


void matrix_free(matrix_t *m)
{
    ckd_free(m);
}
