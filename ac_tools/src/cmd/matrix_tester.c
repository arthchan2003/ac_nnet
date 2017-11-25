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

    matrix_t* zero2, *zero5;
    zero2 = matrix_init(2,2);    
    matrix_display(zero2);
    matrix_free(zero2); zero2= NULL;

    zero5 = matrix_init(5,5);
    matrix_display(zero5);
    matrix_free(zero5); zero5= NULL;

    matrix_t* randmat;
    randmat = matrix_random_init(5,4, 1.0);
    matrix_display(randmat);
    matrix_free(randmat); randmat= NULL;

    randmat = matrix_random_init(5,4, 10.0);
    matrix_display(randmat);
    matrix_free(randmat); randmat= NULL;
    
//    cmd_ln_free_r(config); config= NULL;
}
