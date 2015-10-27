<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
noinst_LTLIBRARIES = libgslsum.la 
=======
noinst_LTLIBRARIES = libgslsum.la
>>>>>>> config

pkginclude_HEADERS = gsl_sum.h

INCLUDES = -I$(top_srcdir)

libgslsum_la_SOURCES = levin_u.c levin_utrunc.c work_u.c work_utrunc.c

TESTS = $(check_PROGRAMS)

check_PROGRAMS = test

test_LDADD = libgslsum.la ../ieee-utils/libgslieeeutils.la  ../err/libgslerr.la ../test/libgsltest.la ../sys/libgslsys.la ../utils/libutils.la

test_SOURCES = test.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8


=======
>>>>>>> config
