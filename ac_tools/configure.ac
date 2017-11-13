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


dnl
dnl Get SphinxBase source from command line if given
dnl
AC_ARG_WITH(sphinxbase,
	AS_HELP_STRING([--with-sphinxbase=DIRECTORY],
			[look for SphinxBase source files in DIRECTORY]),
			sphinxbase=$withval)

dnl
dnl Get SphinxBase build directory from command line if given
dnl
AC_ARG_WITH(sphinxbase-build,
	AS_HELP_STRING([--with-sphinxbase-build=DIRECTORY],
			[look for SphinxBase object files in DIRECTORY]),
	sphinxbasebuild=$withval)


dnl
dnl Check for installed SphinxBase
dnl FIXME: How do we find the installed headers robustly?
dnl
AC_CHECK_HEADER(sphinxbase/sphinx_config.h,
CPPFLAGS="-I/usr/include/sphinxbase -I/usr/local/include/sphinxbase",[
if test x$sphinxbase = x; then
   # Look for sphinxbase in the parent directory
   for sb in ../sphinxbase*; do
       AC_MSG_CHECKING([for sphinxbase in $sb])
       if test -f "$sb/include/prim_type.h"; then
          sphinxbase="`pwd`/$sb"
	  AC_MSG_RESULT(yes)
       else
	  AC_MSG_RESULT(no)
       fi
   done
fi
])


dnl
dnl Now verify SphinxBase if defined
dnl Sadly, this doesn't work when cross-compiling (for some dumb reason...)
dnl

dnl 
dnl When only --with-sphinxbase
dnl derive both CPPFLAGS and LDFLAGS
dnl 
: ${sphinxbasebuild=$sphinxbase}
if test x$sphinxbase != x && test x$cross_compiling = xyes; then
   CPPFLAGS="-I$sphinxbase/include -I$sphinxbase/include/sphinxbase/ $CPPFLAGS"
   LDFLAGS="$LDFLAGS -L$sphinxbasebuild/src/libsphinxfe -L$sphinxbasebuild/src/libsphinxad \
		     -L$sphinxbasebuild/src/libsphinxbase"
fi
if test x$sphinxbase != x && test x$cross_compiling != xyes; then
   AC_CHECK_FILE($sphinxbase/include/sphinxbase/prim_type.h,CPPFLAGS="-I$sphinxbase/include -I$sphinxbase/include/sphinxbase/ $CPPFLAGS",
   AC_ERROR(
[SphinxBase headers not found in $sphinxbase.  Please use the
--with-sphinxbase option to `configure' to specify the location of
SphinxBase.  Run $0 --help for more information.]))
fi

dnl 
dnl With --with-sphinxbase-build as well
dnl override LDFLAGS with libraries from --with-sphinxbase-build
dnl Logic if the library exists in the subdirectory level, 
dnl          i.e. they exist at the sphinxbase source true, use them first. 
dnl       else if the library exists in one single directory
dnl          i.e. they are probably installed, use them 
dnl       else I am not robust enough and can only yell.
dnl

if test x$sphinxbasebuild != x && test x$cross_compiling != xyes; then
   at_multi_dir="n"
   at_single_dir="n"

   AC_CHECK_FILES($sphinxbasebuild/src/libsphinxbase/libsphinxbase.la,
[at_multi_dir="y"
 echo "Using $sphinxbasebuild/src/libsphinxbase/libsphinxbase.la"
# CPPFLAGS="-I$sphinxbasebuild/include $CPPFLAGS"
 LDFLAGS="$LDFLAGS -L$sphinxbasebuild/src/libsphinxfe -L$sphinxbasebuild/src/libsphinxad \
-L$sphinxbasebuild/src/libsphinxbase"],
   [])

  if test x$at_multi_dir = xn; then
   AC_CHECK_FILES($sphinxbasebuild/lib/libsphinxbase.la,
[at_single_dir="y"
 echo "Using $sphinxbasebuild/lib/libsphinxbase.la"
# CPPFLAGS="-I$sphinxbasebuild/include $CPPFLAGS"
 LDFLAGS="$LDFLAGS -L$sphinxbasebuild/lib/"],
[])
  fi

   echo "Using libraries from multi directories? $at_multi_dir"
   echo "Using libraries from a single directory? $at_single_dir"
   
   if test x$at_multi_dir = xn && test x$at_single_dir = xn; then
      AC_ERROR([SphinxBase libraries were not found in $sphinxbasebuild/src/libsphinxbase/libsphinxbase.la or $sphinxbasebuild/lib/libsphinxbase.la
      Use the --with-sphinxbase-build option to `configure' to specify 
      the build directory for SphinxBase.  Run $0 --help for more information.])   
   fi
fi



dnl
dnl Check for installed SphinxBase
dnl FIXME: How do we find the installed headers robustly?
dnl
AC_CHECK_HEADER(sphinxbase/sphinx_config.h,
CPPFLAGS="-I/usr/include/sphinxbase -I/usr/local/include/sphinxbase",[
if test x$sphinxbase = x; then
p   # Look for sphinxbase in the parent directory
   for sb in ../sphinxbase*; do
       AC_MSG_CHECKING([for sphinxbase in $sb])
       if test -f "$sb/include/sphinxbase/prim_type.h"; then
          sphinxbase="`pwd`/$sb"
            AC_MSG_RESULT(yes)
       else
         AC_MSG_RESULT(no)
       fi
   done
fi
])





AC_SUBST(sphinxbase)

AC_CONFIG_FILES([
Makefile
src/Makefile
src/lib/Makefile
src/cmd/Makefile
])
AC_OUTPUT
