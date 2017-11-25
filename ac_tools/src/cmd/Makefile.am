bin_PROGRAMS = simple_regression ac_linreg matrix_tester 

simple_regression_SOURCES = simple_regression.c
ac_linreg_SOURCES         = ac_linreg.c 
matrix_tester_SOURCES     = matrix_tester.c

#noinst_HEADERS = cmd_ln_defn.h sphinx_wave2feat.h

ac_linreg_LDADD = $(top_builddir)/src/lib/libacnnet.la -lsphinxbase -lsphinxad -lm

AM_CFLAGS =-I$(top_srcdir)/include \
	-I$(top_builddir)/include 

LDADD = -lsphinxbase -lsphinxad -lm

