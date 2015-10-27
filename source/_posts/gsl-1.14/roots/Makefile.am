# -*-makefile-*-

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
noinst_LTLIBRARIES = libgslroots.la 
=======
noinst_LTLIBRARIES = libgslroots.la
>>>>>>> config

pkginclude_HEADERS = gsl_roots.h

noinst_HEADERS = roots.h

INCLUDES = -I$(top_srcdir)

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
libgslroots_la_SOURCES = bisection.c brent.c falsepos.c	newton.c  secant.c steffenson.c	convergence.c fsolver.c fdfsolver.c 
=======
libgslroots_la_SOURCES = bisection.c brent.c falsepos.c	newton.c  secant.c steffenson.c	convergence.c fsolver.c fdfsolver.c
>>>>>>> config

check_PROGRAMS = test

TESTS = $(check_PROGRAMS)

test_SOURCES = test.c test_funcs.c test.h
test_LDADD = libgslroots.la ../ieee-utils/libgslieeeutils.la  ../err/libgslerr.la ../test/libgsltest.la ../sys/libgslsys.la ../utils/libutils.la
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
