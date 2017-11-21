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
    cmd_ln_t * config;
    config = cmd_ln_parse_r(NULL, defn, argc, argv, TRUE);

    matrix_t* zero;
//    zero = matrix_init(2,2);
    
    
    cmd_ln_free_r(config); config= NULL;
}
