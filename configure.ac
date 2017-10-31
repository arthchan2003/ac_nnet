dnl Welcome to the Sphinx automated build system.
dnl try not to hurt yourself ;)

AC_INIT([ac_nnet], alpha)
AC_CONFIG_HEADERS([include/config.h ])
AM_INIT_AUTOMAKE([no-define foreign])
AC_CONFIG_MACRO_DIR([m4])

CFLAGS=${CFLAGS:--g -O2 -Wall}

AC_CANONICAL_HOST
AC_ISC_POSIX
AC_PROG_CC
AC_PROG_CC_STDC

LT_INIT


AC_CONFIG_FILES([
Makefile
src/Makefile
src/lib/Makefile
])
AC_OUTPUT
