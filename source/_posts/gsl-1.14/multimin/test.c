/* multimin/test.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Fabrice Rossi
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Fabrice Rossi
 *
>>>>>>> config
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
=======
 *
>>>>>>> config
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
=======
 *
>>>>>>> config
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/* Modified by Tuomo Keskitalo to add Nelder Mead Simplex test suite */

#include <config.h>
#include <stdlib.h>
#include <gsl/gsl_test.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_multimin.h>
#include <gsl/gsl_ieee_utils.h>

#include "test_funcs.h"

unsigned int fcount, gcount;

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
test_fdf(const char * desc, gsl_multimin_function_fdf *f, 
         initpt_function initpt, const gsl_multimin_fdfminimizer_type *T);
=======
test_fdf(const char * desc, gsl_multimin_function_fdf *f,
	 initpt_function initpt, const gsl_multimin_fdfminimizer_type *T);
>>>>>>> config

int
test_f(const char * desc, gsl_multimin_function *f, initpt_function initpt,
       const gsl_multimin_fminimizer_type *T);

int
main (void)
{
  gsl_ieee_env_setup ();

  {
    const gsl_multimin_fdfminimizer_type *fdfminimizers[6];
    const gsl_multimin_fdfminimizer_type ** T;

    fdfminimizers[0] = gsl_multimin_fdfminimizer_steepest_descent;
    fdfminimizers[1] = gsl_multimin_fdfminimizer_conjugate_pr;
    fdfminimizers[2] = gsl_multimin_fdfminimizer_conjugate_fr;
    fdfminimizers[3] = gsl_multimin_fdfminimizer_vector_bfgs;
    fdfminimizers[4] = gsl_multimin_fdfminimizer_vector_bfgs2;
    fdfminimizers[5] = 0;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    
    T = fdfminimizers;
    
    while (*T != 0) 
      {
        test_fdf("Roth", &roth, roth_initpt,*T);
        test_fdf("Wood", &wood, wood_initpt,*T);
        test_fdf("Rosenbrock", &rosenbrock, rosenbrock_initpt,*T);
        T++;
      }
    
    T = fdfminimizers;
    
    while (*T != 0) 
      {
        test_fdf("NRoth", &Nroth, roth_initpt,*T);
        test_fdf("NWood", &Nwood, wood_initpt,*T);
        test_fdf("NRosenbrock", &Nrosenbrock, rosenbrock_initpt,*T);
        T++;
=======

    T = fdfminimizers;

    while (*T != 0)
      {
	test_fdf("Roth", &roth, roth_initpt,*T);
	test_fdf("Wood", &wood, wood_initpt,*T);
	test_fdf("Rosenbrock", &rosenbrock, rosenbrock_initpt,*T);
	T++;
      }

    T = fdfminimizers;

    while (*T != 0)
      {
	test_fdf("NRoth", &Nroth, roth_initpt,*T);
	test_fdf("NWood", &Nwood, wood_initpt,*T);
	test_fdf("NRosenbrock", &Nrosenbrock, rosenbrock_initpt,*T);
	T++;
>>>>>>> config
      }
  }


  {
    const gsl_multimin_fminimizer_type *fminimizers[4];
    const gsl_multimin_fminimizer_type ** T;

    fminimizers[0] = gsl_multimin_fminimizer_nmsimplex;
    fminimizers[1] = gsl_multimin_fminimizer_nmsimplex2;
    fminimizers[2] = gsl_multimin_fminimizer_nmsimplex2rand;
    fminimizers[3] = 0;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    
    T = fminimizers;
    
    while (*T != 0) 
      {
        test_f("Roth", &roth_fmin, roth_initpt,*T);
        test_f("Wood", &wood_fmin, wood_initpt,*T);
        test_f("Rosenbrock", &rosenbrock_fmin, rosenbrock_initpt,*T);
        test_f("Spring", &spring_fmin, spring_initpt,*T);
        T++;
=======

    T = fminimizers;

    while (*T != 0)
      {
	test_f("Roth", &roth_fmin, roth_initpt,*T);
	test_f("Wood", &wood_fmin, wood_initpt,*T);
	test_f("Rosenbrock", &rosenbrock_fmin, rosenbrock_initpt,*T);
	test_f("Spring", &spring_fmin, spring_initpt,*T);
	T++;
>>>>>>> config
      }
  }


  exit (gsl_test_summary());
}

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
test_fdf(const char * desc, 
         gsl_multimin_function_fdf *f,
         initpt_function initpt,
         const gsl_multimin_fdfminimizer_type *T)
=======
test_fdf(const char * desc,
	 gsl_multimin_function_fdf *f,
	 initpt_function initpt,
	 const gsl_multimin_fdfminimizer_type *T)
>>>>>>> config
{
  int status;
  size_t iter = 0;
  double step_size;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  gsl_vector *x = gsl_vector_alloc (f->n);

  gsl_multimin_fdfminimizer *s;
  fcount = 0; gcount = 0;

  (*initpt) (x);

  step_size = 0.1 * gsl_blas_dnrm2 (x);

  s = gsl_multimin_fdfminimizer_alloc(T, f->n);

  gsl_multimin_fdfminimizer_set (s, f, x, step_size, 0.1);

#ifdef DEBUG
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  printf("x "); gsl_vector_fprintf (stdout, s->x, "%g"); 
  printf("g "); gsl_vector_fprintf (stdout, s->gradient, "%g"); 
#endif

  do 
=======
  printf("x "); gsl_vector_fprintf (stdout, s->x, "%g");
  printf("g "); gsl_vector_fprintf (stdout, s->gradient, "%g");
#endif

  do
>>>>>>> config
    {
      iter++;
      status = gsl_multimin_fdfminimizer_iterate(s);

#ifdef DEBUG
      printf("%i: \n",iter);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      printf("x "); gsl_vector_fprintf (stdout, s->x, "%g"); 
      printf("g "); gsl_vector_fprintf (stdout, s->gradient, "%g"); 
=======
      printf("x "); gsl_vector_fprintf (stdout, s->x, "%g");
      printf("g "); gsl_vector_fprintf (stdout, s->gradient, "%g");
>>>>>>> config
      printf("f(x) %g\n",s->f);
      printf("dx %g\n",gsl_blas_dnrm2(s->dx));
      printf("\n");
#endif

      status = gsl_multimin_test_gradient(s->gradient,1e-3);
    }
  while (iter < 5000 && status == GSL_CONTINUE);

  status |= (fabs(s->f) > 1e-5);

  gsl_test(status, "%s, on %s: %i iters (fn+g=%d+%d), f(x)=%g",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
           gsl_multimin_fdfminimizer_name(s),desc, iter, fcount, gcount, s->f);
=======
	   gsl_multimin_fdfminimizer_name(s),desc, iter, fcount, gcount, s->f);
>>>>>>> config

  gsl_multimin_fdfminimizer_free(s);
  gsl_vector_free(x);

  return status;
}

int
test_f(const char * desc, gsl_multimin_function *f, initpt_function initpt,
       const gsl_multimin_fminimizer_type *T)
{
  int status;
  size_t i, iter = 0;

  gsl_vector *x = gsl_vector_alloc (f->n);

  gsl_vector *step_size = gsl_vector_alloc (f->n);

  gsl_multimin_fminimizer *s;

  fcount = 0; gcount = 0;
  (*initpt) (x);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  for (i = 0; i < f->n; i++) 
=======
  for (i = 0; i < f->n; i++)
>>>>>>> config
    gsl_vector_set (step_size, i, 1);

  s = gsl_multimin_fminimizer_alloc(T, f->n);

  gsl_multimin_fminimizer_set (s, f, x, step_size);

#ifdef DEBUG
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  printf("x "); gsl_vector_fprintf (stdout, s->x, "%g"); 
#endif

  do 
=======
  printf("x "); gsl_vector_fprintf (stdout, s->x, "%g");
#endif

  do
>>>>>>> config
    {
      iter++;
      status = gsl_multimin_fminimizer_iterate(s);

#ifdef DEBUG
      printf("%i: \n",iter);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      printf("x "); gsl_vector_fprintf (stdout, s->x, "%g"); 
=======
      printf("x "); gsl_vector_fprintf (stdout, s->x, "%g");
>>>>>>> config
      printf("f(x) %g\n", gsl_multimin_fminimizer_minimum (s));
      printf("size: %g\n", gsl_multimin_fminimizer_size (s));
      printf("\n");
#endif

      status = gsl_multimin_test_size (gsl_multimin_fminimizer_size (s),
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                       1e-3);
=======
				       1e-3);
>>>>>>> config
    }
  while (iter < 5000 && status == GSL_CONTINUE);

  status |= (fabs(s->fval) > 1e-5);

  gsl_test(status, "%s, on %s: %d iter (fn=%d), f(x)=%g",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
           gsl_multimin_fminimizer_name(s),desc, iter, fcount, s->fval);
=======
	   gsl_multimin_fminimizer_name(s),desc, iter, fcount, s->fval);
>>>>>>> config

  gsl_multimin_fminimizer_free(s);
  gsl_vector_free(x);
  gsl_vector_free(step_size);

  return status;
}
