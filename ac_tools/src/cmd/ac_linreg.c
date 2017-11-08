/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include <sphinxbase/cmd_ln.h>

static arg_t defn[] = {
  { "-M",
    ARG_STRING,
    NULL,
    "model file in libsvm format" },

  { NULL, 0, NULL, NULL }
};


int main(int argc, char *argv[])
{
    cmd_ln_t *config;
    config = cmd_ln_parse_r(NULL, defn, argc, argv, TRUE);
}
