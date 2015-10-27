<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
noinst_LTLIBRARIES = libgslmonte.la 
=======
noinst_LTLIBRARIES = libgslmonte.la
>>>>>>> config

libgslmonte_la_SOURCES =  miser.c plain.c gsl_monte_vegas.h gsl_monte_miser.h gsl_monte_plain.h gsl_monte.h vegas.c

pkginclude_HEADERS = gsl_monte.h gsl_monte_vegas.h gsl_monte_miser.h gsl_monte_plain.h

INCLUDES = -I$(top_srcdir)

TESTS = $(check_PROGRAMS)

check_PROGRAMS = test #demo

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
test_SOURCES = test.c 
=======
test_SOURCES = test.c
>>>>>>> config
test_LDADD = libgslmonte.la ../rng/libgslrng.la  ../ieee-utils/libgslieeeutils.la ../err/libgslerr.la ../test/libgsltest.la ../sys/libgslsys.la ../utils/libutils.la

noinst_HEADERS = test_main.c

#demo_SOURCES= demo.c
#demo_LDADD = libgslmonte.la ../rng/libgslrng.la ../ieee-utils/libgslieeeutils.la ../err/libgslerr.la ../test/libgsltest.la ../utils/libutils.la
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8


=======
>>>>>>> config
