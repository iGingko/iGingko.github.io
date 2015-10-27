/* integration/qags.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Brian Gough
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

#include <config.h>
#include <stdlib.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_integration.h>

#include "initialise.c"
#include "set_initial.c"
#include "qpsrt.c"
#include "util.c"
#include "reset.c"
#include "qpsrt2.c"
#include "qelg.c"
#include "positivity.c"

static int qags (const gsl_function * f, const double a, const double
  b, const double epsabs, const double epsrel, const size_t limit,
  gsl_integration_workspace * workspace, double *result, double *abserr,
  gsl_integration_rule * q);

int
gsl_integration_qags (const gsl_function *f,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                      double a, double b,
                      double epsabs, double epsrel, size_t limit,
                      gsl_integration_workspace * workspace,
                      double * result, double * abserr)
{
  int status = qags (f, a, b, epsabs, epsrel, limit,
                     workspace, 
                     result, abserr, 
                     &gsl_integration_qk21) ;
=======
		      double a, double b,
		      double epsabs, double epsrel, size_t limit,
		      gsl_integration_workspace * workspace,
		      double * result, double * abserr)
{
  int status = qags (f, a, b, epsabs, epsrel, limit,
		     workspace,
		     result, abserr,
		     &gsl_integration_qk21) ;
>>>>>>> config
  return status ;
}

/* QAGI: evaluate an integral over an infinite range using the
   transformation

   integrate(f(x),-Inf,Inf) = integrate((f((1-t)/t) + f(-(1-t)/t))/t^2,0,1)

   */

static double i_transform (double t, void *params);

int
gsl_integration_qagi (gsl_function * f,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                      double epsabs, double epsrel, size_t limit,
                      gsl_integration_workspace * workspace,
                      double *result, double *abserr)
=======
		      double epsabs, double epsrel, size_t limit,
		      gsl_integration_workspace * workspace,
		      double *result, double *abserr)
>>>>>>> config
{
  int status;

  gsl_function f_transform;

  f_transform.function = &i_transform;
  f_transform.params = f;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  status = qags (&f_transform, 0.0, 1.0, 
                 epsabs, epsrel, limit,
                 workspace,
                 result, abserr,
                 &gsl_integration_qk15);
=======
  status = qags (&f_transform, 0.0, 1.0,
		 epsabs, epsrel, limit,
		 workspace,
		 result, abserr,
		 &gsl_integration_qk15);
>>>>>>> config

  return status;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
static double 
=======
static double
>>>>>>> config
i_transform (double t, void *params)
{
  gsl_function *f = (gsl_function *) params;
  double x = (1 - t) / t;
  double y = GSL_FN_EVAL (f, x) + GSL_FN_EVAL (f, -x);
  return (y / t) / t;
}


/* QAGIL: Evaluate an integral over an infinite range using the
   transformation,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
   
=======

>>>>>>> config
   integrate(f(x),-Inf,b) = integrate(f(b-(1-t)/t)/t^2,0,1)

   */

struct il_params { double b ; gsl_function * f ; } ;

static double il_transform (double t, void *params);

int
gsl_integration_qagil (gsl_function * f,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                       double b,
                       double epsabs, double epsrel, size_t limit,
                       gsl_integration_workspace * workspace,
                       double *result, double *abserr)
=======
		       double b,
		       double epsabs, double epsrel, size_t limit,
		       gsl_integration_workspace * workspace,
		       double *result, double *abserr)
>>>>>>> config
{
  int status;

  gsl_function f_transform;
  struct il_params transform_params  ;

  transform_params.b = b ;
  transform_params.f = f ;

  f_transform.function = &il_transform;
  f_transform.params = &transform_params;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  status = qags (&f_transform, 0.0, 1.0, 
                 epsabs, epsrel, limit,
                 workspace,
                 result, abserr,
                 &gsl_integration_qk15);
=======
  status = qags (&f_transform, 0.0, 1.0,
		 epsabs, epsrel, limit,
		 workspace,
		 result, abserr,
		 &gsl_integration_qk15);
>>>>>>> config

  return status;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
static double 
=======
static double
>>>>>>> config
il_transform (double t, void *params)
{
  struct il_params *p = (struct il_params *) params;
  double b = p->b;
  gsl_function * f = p->f;
  double x = b - (1 - t) / t;
  double y = GSL_FN_EVAL (f, x);
  return (y / t) / t;
}

/* QAGIU: Evaluate an integral over an infinite range using the
   transformation

   integrate(f(x),a,Inf) = integrate(f(a+(1-t)/t)/t^2,0,1)

   */

struct iu_params { double a ; gsl_function * f ; } ;

static double iu_transform (double t, void *params);

int
gsl_integration_qagiu (gsl_function * f,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                       double a,
                       double epsabs, double epsrel, size_t limit,
                       gsl_integration_workspace * workspace,
                       double *result, double *abserr)
=======
		       double a,
		       double epsabs, double epsrel, size_t limit,
		       gsl_integration_workspace * workspace,
		       double *result, double *abserr)
>>>>>>> config
{
  int status;

  gsl_function f_transform;
  struct iu_params transform_params  ;

  transform_params.a = a ;
  transform_params.f = f ;

  f_transform.function = &iu_transform;
  f_transform.params = &transform_params;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  status = qags (&f_transform, 0.0, 1.0, 
                 epsabs, epsrel, limit,
                 workspace,
                 result, abserr,
                 &gsl_integration_qk15);
=======
  status = qags (&f_transform, 0.0, 1.0,
		 epsabs, epsrel, limit,
		 workspace,
		 result, abserr,
		 &gsl_integration_qk15);
>>>>>>> config

  return status;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
static double 
=======
static double
>>>>>>> config
iu_transform (double t, void *params)
{
  struct iu_params *p = (struct iu_params *) params;
  double a = p->a;
  gsl_function * f = p->f;
  double x = a + (1 - t) / t;
  double y = GSL_FN_EVAL (f, x);
  return (y / t) / t;
}

/* Main integration function */

static int
qags (const gsl_function * f,
      const double a, const double b,
      const double epsabs, const double epsrel,
      const size_t limit,
      gsl_integration_workspace * workspace,
      double *result, double *abserr,
      gsl_integration_rule * q)
{
  double area, errsum;
  double res_ext, err_ext;
  double result0, abserr0, resabs0, resasc0;
  double tolerance;

  double ertest = 0;
  double error_over_large_intervals = 0;
  double reseps = 0, abseps = 0, correc = 0;
  size_t ktmin = 0;
  int roundoff_type1 = 0, roundoff_type2 = 0, roundoff_type3 = 0;
  int error_type = 0, error_type2 = 0;

  size_t iteration = 0;

  int positive_integrand = 0;
  int extrapolate = 0;
  int disallow_extrapolation = 0;

  struct extrapolation_table table;

  /* Initialize results */

  initialise (workspace, a, b);

  *result = 0;
  *abserr = 0;

  if (limit > workspace->limit)
    {
      GSL_ERROR ("iteration limit exceeds available workspace", GSL_EINVAL) ;
    }

  /* Test on accuracy */

  if (epsabs <= 0 && (epsrel < 50 * GSL_DBL_EPSILON || epsrel < 0.5e-28))
    {
      GSL_ERROR ("tolerance cannot be acheived with given epsabs and epsrel",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 GSL_EBADTOL);
=======
		 GSL_EBADTOL);
>>>>>>> config
    }

  /* Perform the first integration */

  q (f, a, b, &result0, &abserr0, &resabs0, &resasc0);

  set_initial_result (workspace, result0, abserr0);

  tolerance = GSL_MAX_DBL (epsabs, epsrel * fabs (result0));

  if (abserr0 <= 100 * GSL_DBL_EPSILON * resabs0 && abserr0 > tolerance)
    {
      *result = result0;
      *abserr = abserr0;

      GSL_ERROR ("cannot reach tolerance because of roundoff error"
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 "on first attempt", GSL_EROUND);
=======
		 "on first attempt", GSL_EROUND);
>>>>>>> config
    }
  else if ((abserr0 <= tolerance && abserr0 != resasc0) || abserr0 == 0.0)
    {
      *result = result0;
      *abserr = abserr0;

      return GSL_SUCCESS;
    }
  else if (limit == 1)
    {
      *result = result0;
      *abserr = abserr0;

      GSL_ERROR ("a maximum of one iteration was insufficient", GSL_EMAXITER);
    }

  /* Initialization */

  initialise_table (&table);
  append_table (&table, result0);

  area = result0;
  errsum = abserr0;

  res_ext = result0;
  err_ext = GSL_DBL_MAX;

  positive_integrand = test_positivity (result0, resabs0);

  iteration = 1;

  do
    {
      size_t current_level;
      double a1, b1, a2, b2;
      double a_i, b_i, r_i, e_i;
      double area1 = 0, area2 = 0, area12 = 0;
      double error1 = 0, error2 = 0, error12 = 0;
      double resasc1, resasc2;
      double resabs1, resabs2;
      double last_e_i;

      /* Bisect the subinterval with the largest error estimate */

      retrieve (workspace, &a_i, &b_i, &r_i, &e_i);

      current_level = workspace->level[workspace->i] + 1;

      a1 = a_i;
      b1 = 0.5 * (a_i + b_i);
      a2 = b1;
      b2 = b_i;

      iteration++;

      q (f, a1, b1, &area1, &error1, &resabs1, &resasc1);
      q (f, a2, b2, &area2, &error2, &resabs2, &resasc2);

      area12 = area1 + area2;
      error12 = error1 + error2;
      last_e_i = e_i;

      /* Improve previous approximations to the integral and test for
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
         accuracy.

         We write these expressions in the same way as the original
         QUADPACK code so that the rounding errors are the same, which
         makes testing easier. */
=======
	 accuracy.

	 We write these expressions in the same way as the original
	 QUADPACK code so that the rounding errors are the same, which
	 makes testing easier. */
>>>>>>> config

      errsum = errsum + error12 - e_i;
      area = area + area12 - r_i;

      tolerance = GSL_MAX_DBL (epsabs, epsrel * fabs (area));

      if (resasc1 != error1 && resasc2 != error2)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          double delta = r_i - area12;

          if (fabs (delta) <= 1.0e-5 * fabs (area12) && error12 >= 0.99 * e_i)
            {
              if (!extrapolate)
                {
                  roundoff_type1++;
                }
              else
                {
                  roundoff_type2++;
                }
            }
          if (iteration > 10 && error12 > e_i)
            {
              roundoff_type3++;
            }
        }
=======
	{
	  double delta = r_i - area12;

	  if (fabs (delta) <= 1.0e-5 * fabs (area12) && error12 >= 0.99 * e_i)
	    {
	      if (!extrapolate)
		{
		  roundoff_type1++;
		}
	      else
		{
		  roundoff_type2++;
		}
	    }
	  if (iteration > 10 && error12 > e_i)
	    {
	      roundoff_type3++;
	    }
	}
>>>>>>> config

      /* Test for roundoff and eventually set error flag */

      if (roundoff_type1 + roundoff_type2 >= 10 || roundoff_type3 >= 20)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          error_type = 2;       /* round off error */
        }

      if (roundoff_type2 >= 5)
        {
          error_type2 = 1;
        }

      /* set error flag in the case of bad integrand behaviour at
         a point of the integration range */

      if (subinterval_too_small (a1, a2, b2))
        {
          error_type = 4;
        }
=======
	{
	  error_type = 2;       /* round off error */
	}

      if (roundoff_type2 >= 5)
	{
	  error_type2 = 1;
	}

      /* set error flag in the case of bad integrand behaviour at
	 a point of the integration range */

      if (subinterval_too_small (a1, a2, b2))
	{
	  error_type = 4;
	}
>>>>>>> config

      /* append the newly-created intervals to the list */

      update (workspace, a1, b1, area1, error1, a2, b2, area2, error2);

      if (errsum <= tolerance)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          goto compute_result;
        }

      if (error_type)
        {
          break;
        }

      if (iteration >= limit - 1)
        {
          error_type = 1;
          break;
        }

      if (iteration == 2)       /* set up variables on first iteration */
        {
          error_over_large_intervals = errsum;
          ertest = tolerance;
          append_table (&table, area);
          continue;
        }

      if (disallow_extrapolation)
        {
          continue;
        }
=======
	{
	  goto compute_result;
	}

      if (error_type)
	{
	  break;
	}

      if (iteration >= limit - 1)
	{
	  error_type = 1;
	  break;
	}

      if (iteration == 2)       /* set up variables on first iteration */
	{
	  error_over_large_intervals = errsum;
	  ertest = tolerance;
	  append_table (&table, area);
	  continue;
	}

      if (disallow_extrapolation)
	{
	  continue;
	}
>>>>>>> config

      error_over_large_intervals += -last_e_i;

      if (current_level < workspace->maximum_level)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          error_over_large_intervals += error12;
        }

      if (!extrapolate)
        {
          /* test whether the interval to be bisected next is the
             smallest interval. */

          if (large_interval (workspace))
            continue;

          extrapolate = 1;
          workspace->nrmax = 1;
        }

      if (!error_type2 && error_over_large_intervals > ertest)
        {
          if (increase_nrmax (workspace))
            continue;
        }
=======
	{
	  error_over_large_intervals += error12;
	}

      if (!extrapolate)
	{
	  /* test whether the interval to be bisected next is the
	     smallest interval. */

	  if (large_interval (workspace))
	    continue;

	  extrapolate = 1;
	  workspace->nrmax = 1;
	}

      if (!error_type2 && error_over_large_intervals > ertest)
	{
	  if (increase_nrmax (workspace))
	    continue;
	}
>>>>>>> config

      /* Perform extrapolation */

      append_table (&table, area);

      qelg (&table, &reseps, &abseps);

      ktmin++;

      if (ktmin > 5 && err_ext < 0.001 * errsum)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          error_type = 5;
        }

      if (abseps < err_ext)
        {
          ktmin = 0;
          err_ext = abseps;
          res_ext = reseps;
          correc = error_over_large_intervals;
          ertest = GSL_MAX_DBL (epsabs, epsrel * fabs (reseps));
          if (err_ext <= ertest)
            break;
        }
=======
	{
	  error_type = 5;
	}

      if (abseps < err_ext)
	{
	  ktmin = 0;
	  err_ext = abseps;
	  res_ext = reseps;
	  correc = error_over_large_intervals;
	  ertest = GSL_MAX_DBL (epsabs, epsrel * fabs (reseps));
	  if (err_ext <= ertest)
	    break;
	}
>>>>>>> config

      /* Prepare bisection of the smallest interval. */

      if (table.n == 1)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          disallow_extrapolation = 1;
        }

      if (error_type == 5)
        {
          break;
        }
=======
	{
	  disallow_extrapolation = 1;
	}

      if (error_type == 5)
	{
	  break;
	}
>>>>>>> config

      /* work on interval with largest error */

      reset_nrmax (workspace);
      extrapolate = 0;
      error_over_large_intervals = errsum;

    }
  while (iteration < limit);

  *result = res_ext;
  *abserr = err_ext;

  if (err_ext == GSL_DBL_MAX)
    goto compute_result;

  if (error_type || error_type2)
    {
      if (error_type2)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          err_ext += correc;
        }

      if (error_type == 0)
        error_type = 3;

      if (res_ext != 0.0 && area != 0.0)
        {
          if (err_ext / fabs (res_ext) > errsum / fabs (area))
            goto compute_result;
        }
      else if (err_ext > errsum)
        {
          goto compute_result;
        }
      else if (area == 0.0)
        {
          goto return_error;
        }
=======
	{
	  err_ext += correc;
	}

      if (error_type == 0)
	error_type = 3;

      if (res_ext != 0.0 && area != 0.0)
	{
	  if (err_ext / fabs (res_ext) > errsum / fabs (area))
	    goto compute_result;
	}
      else if (err_ext > errsum)
	{
	  goto compute_result;
	}
      else if (area == 0.0)
	{
	  goto return_error;
	}
>>>>>>> config
    }

  /*  Test on divergence. */

  {
    double max_area = GSL_MAX_DBL (fabs (res_ext), fabs (area));

    if (!positive_integrand && max_area < 0.01 * resabs0)
      goto return_error;
  }

  {
    double ratio = res_ext / area;

    if (ratio < 0.01 || ratio > 100.0 || errsum > fabs (area))
      error_type = 6;
  }

  goto return_error;

compute_result:

  *result = sum_results (workspace);
  *abserr = errsum;

return_error:

  if (error_type > 2)
    error_type--;



<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (error_type == 0) 
=======
  if (error_type == 0)
>>>>>>> config
    {
      return GSL_SUCCESS;
    }
  else if (error_type == 1)
    {
      GSL_ERROR ("number of iterations was insufficient", GSL_EMAXITER);
    }
  else if (error_type == 2)
    {
      GSL_ERROR ("cannot reach tolerance because of roundoff error",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 GSL_EROUND);
=======
		 GSL_EROUND);
>>>>>>> config
    }
  else if (error_type == 3)
    {
      GSL_ERROR ("bad integrand behavior found in the integration interval",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 GSL_ESING);
=======
		 GSL_ESING);
>>>>>>> config
    }
  else if (error_type == 4)
    {
      GSL_ERROR ("roundoff error detected in the extrapolation table",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 GSL_EROUND);
=======
		 GSL_EROUND);
>>>>>>> config
    }
  else if (error_type == 5)
    {
      GSL_ERROR ("integral is divergent, or slowly convergent",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 GSL_EDIVERGE);
=======
		 GSL_EDIVERGE);
>>>>>>> config
    }
  else
    {
      GSL_ERROR ("could not integrate function", GSL_EFAILED);
    }

}
