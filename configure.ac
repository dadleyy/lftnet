AC_INIT([lftnet], 0.0.1)
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_COPYRIGHT([
])

AC_PROG_CXX
AC_PROG_LIBTOOL
AC_LANG([C++])

AC_MSG_CHECKING([if able to compile lambda expressions with c++ 11])
CPPFLAGS="$CPPFLAGS -std=c++14"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
  auto a = [] () { };
]])], [AC_MSG_RESULT([yes])], [AC_MSG_ERROR([could not use c++ 11])])

AC_CHECK_LIB([ssl], [SSL_library_init], [
  HAVE_SSL=1
  LIBS="-lssl $LIBS"
  AC_DEFINE([HAVE_SSL], [1], [ssl comment])], [
  AC_DEFINE([HAVE_SSL], [0], [ssl comment])])

AC_CHECK_LIB([mpg123], [mpg123_init], [
  HAVE_MPG123=1
  LIBS="-lmpg123 $LIBS"
  AC_DEFINE([HAVE_MPG123], [1], [mpg123])], [
  HAVE_MPG123=0
  AC_DEFINE([HAVE_MPG123], [0], [mpg123])])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
