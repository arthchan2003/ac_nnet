#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include "sphinxbase/cmd_ln.h"
#include "matrix.h"

static arg_t defn[] = {
  { NULL, 0, NULL, NULL }
};

int main(int argc, char *argv[])
{
//    cmd_ln_t * config;
//    config = cmd_ln_parse_r(NULL, defn, argc, argv, TRUE);

    //Zero initialization
    matrix_t* zero2, *zero5;
    zero2 = matrix_init(2,2);    
    matrix_display(zero2);
    matrix_free(zero2); zero2= NULL;

    zero5 = matrix_init(5,5);
    matrix_display(zero5);
    matrix_free(zero5); zero5= NULL;

    //Random initialization
    matrix_t* randmat;
    randmat = matrix_random_init(5,4, 1.0);
    printf ("Random Matrix 1");
    matrix_display(randmat);
    matrix_free(randmat); randmat= NULL;

    randmat = matrix_random_init(5,4, 10.0);
    matrix_display(randmat);
    matrix_free(randmat); randmat= NULL;

    //scaling
    matrix_t *mat1, *mat2;
    mat1 = matrix_random_init(5,4, 1.0);
    mat2 = matrix_random_init(5,4, 1.0);

    printf ("Matrix 1\n");
    matrix_display(mat1);

    printf ("Matrix 1 x 2\n");
    matrix_scale_a(mat1, 2.0);
    matrix_display(mat1);

    printf ("Matrix 1 x 2 x 0.5\n");
    matrix_scale_a(mat1, 0.5);
    matrix_display(mat1);

    printf ("Matrix 2\n");
    matrix_display(mat2);

    printf ("Matrix 1 + Matrix 2\n");;
    matrix_add_to_a(mat1, mat2);
    matrix_display(mat1);

    
    matrix_free(mat1); mat1 = NULL;
    matrix_free(mat2); mat2 = NULL;
    
//    cmd_ln_free_r(config); config= NULL;
    
    float32 vals_a[4] = {1,2,3,4};
    float32 vals_b[4] = {1,0,0,1};
    float32 vals_d[4] = {1,1,1,1};
    float32 vals_e[4] = {1,2,3,4};

    //Simple multiplications. 
    matrix_t *a, *b, *c, *d, *e;
    a = matrix_init_with_array(2,2,vals_a);
    b = matrix_init_with_array(2,2,vals_b);
    c = matrix_init(2,2);
    d = matrix_init_with_array(2,2,vals_d);
    e = matrix_init_with_array(2,2,vals_e);


    matrix_display(a);
    matrix_display(b);
    matrix_display(c);
    matrix_display(d);
    matrix_display(e);

    matrix_multiply (c, a, b);
    matrix_display(c);

    assert (matrix_verify(c,e));

    matrix_multiply (c, a, d);
    matrix_display(c);

    matrix_multiply (c, d, a);
    matrix_display(c);


    matrix_square_transpose(a);
    matrix_display(a);

    matrix_free(a) ; a = NULL;
    matrix_free(b) ; b = NULL;
    matrix_free(c) ; c = NULL;
    matrix_free(d) ; d = NULL;
    

    float32 vals_f[9] = {1,2,3,4,5,6,7,8,9};    
    matrix_t *f;

    f = matrix_init_with_array(3,3,vals_f);
    matrix_display(f);

    matrix_square_transpose(f);
    matrix_display(f);

    matrix_square_transpose(f);
    matrix_display(f);

    matrix_permute_rows(f, 0, 1);
    matrix_display(f);

    matrix_permute_rows(f, 0, 1);
    matrix_display(f);

    matrix_free(f) ; f = NULL;

    float32 vals_g[9] = {1,2,3,4,5,6,7,8,18};    
    matrix_t *g;

    g = matrix_init_with_array(3,3,vals_g);
    matrix_eliminate(g,0,1);
    matrix_display(g);
    matrix_eliminate(g,0,2);
    matrix_display(g);
    matrix_eliminate(g,1,2);
    matrix_display(g);

    matrix_free(g) ; g = NULL;
    return 0;
}
