/* interpolation/linear.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Gerard Jungman
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Gerard Jungman
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

/* Author:  G. Jungman
 */
#include <config.h>
#include <stdlib.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_interp.h>

static int
linear_init (void * vstate,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const double x_array[],
             const double y_array[],
             size_t size)
=======
	     const double x_array[],
	     const double y_array[],
	     size_t size)
>>>>>>> config
{
  return GSL_SUCCESS;
}

static
int
linear_eval (const void * vstate,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             const double x_array[], const double y_array[], size_t size,
             double x,
             gsl_interp_accel * a,
             double *y)
=======
	     const double x_array[], const double y_array[], size_t size,
	     double x,
	     gsl_interp_accel * a,
	     double *y)
>>>>>>> config
{
  double x_lo, x_hi;
  double y_lo, y_hi;
  double dx;
  size_t index;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (a != 0)
    {
      index = gsl_interp_accel_find (a, x_array, size, x);
    }
  else
    {
      index = gsl_interp_bsearch (x_array, x, 0, size - 1);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  /* evaluate */
  x_lo = x_array[index];
  x_hi = x_array[index + 1];
  y_lo = y_array[index];
  y_hi = y_array[index + 1];
  dx = x_hi - x_lo;
  if (dx > 0.0)
    {
      *y = y_lo + (x - x_lo) / dx * (y_hi - y_lo);
      return GSL_SUCCESS;
    }
  else
    {
      *y = 0.0;
      return GSL_EINVAL;
    }
}


static
int
linear_eval_deriv (const void * vstate,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                   const double x_array[], const double y_array[], size_t size,
                   double x,
                   gsl_interp_accel * a,
                   double *dydx)
=======
		   const double x_array[], const double y_array[], size_t size,
		   double x,
		   gsl_interp_accel * a,
		   double *dydx)
>>>>>>> config
{
  double x_lo, x_hi;
  double y_lo, y_hi;
  double dx;
  double dy;
  size_t index;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (a != 0)
    {
      index = gsl_interp_accel_find (a, x_array, size, x);
    }
  else
    {
      index = gsl_interp_bsearch (x_array, x, 0, size - 1);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  /* evaluate */
  x_lo = x_array[index];
  x_hi = x_array[index + 1];
  y_lo = y_array[index];
  y_hi = y_array[index + 1];
  dx = x_hi - x_lo;
  dy = y_hi - y_lo;
  if (dx > 0.0)
    {
      *dydx = dy / dx;;
      return GSL_SUCCESS;
    }
  else
    {
      *dydx = 0.0;
      return GSL_EINVAL;
    }
}


static
int
linear_eval_deriv2 (const void * vstate,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                    const double x_array[], const double y_array[], size_t size,
                    double x,
                    gsl_interp_accel * a,
                    double *y_pp)
=======
		    const double x_array[], const double y_array[], size_t size,
		    double x,
		    gsl_interp_accel * a,
		    double *y_pp)
>>>>>>> config
{
  *y_pp = 0.0;

  return GSL_SUCCESS;
}


static
int
linear_eval_integ (const void * vstate,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                   const double x_array[], const double y_array[], size_t size,
                   gsl_interp_accel * acc,
                   double a, double b,
                   double * result)
{
  size_t i, index_a, index_b;
  
=======
		   const double x_array[], const double y_array[], size_t size,
		   gsl_interp_accel * acc,
		   double a, double b,
		   double * result)
{
  size_t i, index_a, index_b;

>>>>>>> config
  if (acc != 0)
    {
      index_a = gsl_interp_accel_find (acc, x_array, size, a);
      index_b = gsl_interp_accel_find (acc, x_array, size, b);
    }
  else
    {
      index_a = gsl_interp_bsearch (x_array, a, 0, size - 1);
      index_b = gsl_interp_bsearch (x_array, b, 0, size - 1);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
    /* endpoints span more than one interval */

  *result = 0.0;
  
=======

    /* endpoints span more than one interval */

  *result = 0.0;

>>>>>>> config
  /* interior intervals */
  for(i=index_a; i<=index_b; i++) {
    const double x_hi = x_array[i + 1];
    const double x_lo = x_array[i];
    const double y_lo = y_array[i];
    const double y_hi = y_array[i + 1];
    const double dx = x_hi - x_lo;

    if(dx != 0.0) {
      if (i == index_a || i == index_b)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          double x1 = (i == index_a) ? a : x_lo;
          double x2 = (i == index_b) ? b : x_hi;
          const double D = (y_hi-y_lo)/dx;
          *result += (x2-x1) * (y_lo + 0.5*D*((x2-x_lo)+(x1-x_lo)));
        }
      else
        {
          *result += 0.5 * dx * (y_lo + y_hi);
        }
    }
  }
    
  return GSL_SUCCESS;
}

static const gsl_interp_type linear_type = 
{
  "linear", 
=======
	{
	  double x1 = (i == index_a) ? a : x_lo;
	  double x2 = (i == index_b) ? b : x_hi;
	  const double D = (y_hi-y_lo)/dx;
	  *result += (x2-x1) * (y_lo + 0.5*D*((x2-x_lo)+(x1-x_lo)));
	}
      else
	{
	  *result += 0.5 * dx * (y_lo + y_hi);
	}
    }
  }

  return GSL_SUCCESS;
}

static const gsl_interp_type linear_type =
{
  "linear",
>>>>>>> config
  2,
  NULL, /* alloc, not applicable */
  &linear_init,
  &linear_eval,
  &linear_eval_deriv,
  &linear_eval_deriv2,
  &linear_eval_integ,
  NULL, /* free, not applicable */
};

const gsl_interp_type * gsl_interp_linear = &linear_type;
