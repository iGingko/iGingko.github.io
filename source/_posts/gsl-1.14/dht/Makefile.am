<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
noinst_LTLIBRARIES = libgsldht.la 
=======
noinst_LTLIBRARIES = libgsldht.la
>>>>>>> config

pkginclude_HEADERS = gsl_dht.h

INCLUDES = -I$(top_srcdir)

TESTS = $(check_PROGRAMS)

check_PROGRAMS = test

test_LDADD = libgsldht.la ../specfunc/libgslspecfunc.la ../complex/libgslcomplex.la ../ieee-utils/libgslieeeutils.la ../err/libgslerr.la ../test/libgsltest.la ../sys/libgslsys.la ../utils/libutils.la

test_SOURCES = test.c

libgsldht_la_SOURCES = dht.c
