<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
noinst_LTLIBRARIES = libgslbspline.la 
=======
noinst_LTLIBRARIES = libgslbspline.la
>>>>>>> config

pkginclude_HEADERS = gsl_bspline.h

INCLUDES = -I$(top_srcdir)

libgslbspline_la_SOURCES = bspline.c

noinst_HEADERS =  bspline.h

check_PROGRAMS = test

TESTS = $(check_PROGRAMS)

test_LDADD = libgslbspline.la ../linalg/libgsllinalg.la ../permutation/libgslpermutation.la ../blas/libgslblas.la ../matrix/libgslmatrix.la ../vector/libgslvector.la ../block/libgslblock.la ../complex/libgslcomplex.la ../cblas/libgslcblas.la ../ieee-utils/libgslieeeutils.la  ../err/libgslerr.la ../test/libgsltest.la ../sys/libgslsys.la ../utils/libutils.la ../statistics/libgslstatistics.la

test_SOURCES = test.c
