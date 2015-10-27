/* interpolation/akima.c
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
#include <math.h>
#include <gsl/gsl_errno.h>
#include "integ_eval.h"
#include <gsl/gsl_interp.h>

typedef struct
{
  double * b;
  double * c;
  double * d;
  double * _m;
} akima_state_t;


/* common creation */
static void *
akima_alloc (size_t size)
{
  akima_state_t *state = (akima_state_t *) malloc (sizeof (akima_state_t));
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (state == NULL)
    {
      GSL_ERROR_NULL("failed to allocate space for state", GSL_ENOMEM);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  state->b = (double *) malloc (size * sizeof (double));
  
=======

  state->b = (double *) malloc (size * sizeof (double));

>>>>>>> config
  if (state->b == NULL)
    {
      free (state);
      GSL_ERROR_NULL("failed to allocate space for b", GSL_ENOMEM);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  state->c = (double *) malloc (size * sizeof (double));
  
=======

  state->c = (double *) malloc (size * sizeof (double));

>>>>>>> config
  if (state->c == NULL)
    {
      free (state->b);
      free (state);
      GSL_ERROR_NULL("failed to allocate space for c", GSL_ENOMEM);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  state->d = (double *) malloc (size * sizeof (double));
  
=======

  state->d = (double *) malloc (size * sizeof (double));

>>>>>>> config
  if (state->d == NULL)
    {
      free (state->c);
      free (state->b);
      free (state);
      GSL_ERROR_NULL("failed to allocate space for d", GSL_ENOMEM);
    }

  state->_m = (double *) malloc ((size + 4) * sizeof (double));

  if (state->_m == NULL)
    {
      free (state->d);
      free (state->c);
      free (state->b);
      free (state);
      GSL_ERROR_NULL("failed to allocate space for _m", GSL_ENOMEM);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  return state;
}


/* common calculation */
static void
akima_calc (const double x_array[], double b[],  double c[],  double d[], size_t size, double m[])
{
  size_t i;

  for (i = 0; i < (size - 1); i++)
    {
      const double NE = fabs (m[i + 1] - m[i]) + fabs (m[i - 1] - m[i - 2]);
      if (NE == 0.0)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          b[i] = m[i];
          c[i] = 0.0;
          d[i] = 0.0;
        }
      else
        {
          const double h_i = x_array[i + 1] - x_array[i];
          const double NE_next = fabs (m[i + 2] - m[i + 1]) + fabs (m[i] - m[i - 1]);
          const double alpha_i = fabs (m[i - 1] - m[i - 2]) / NE;
          double alpha_ip1;
          double tL_ip1;
          if (NE_next == 0.0)
            {
              tL_ip1 = m[i];
            }
          else
            {
              alpha_ip1 = fabs (m[i] - m[i - 1]) / NE_next;
              tL_ip1 = (1.0 - alpha_ip1) * m[i] + alpha_ip1 * m[i + 1];
            }
          b[i] = (1.0 - alpha_i) * m[i - 1] + alpha_i * m[i];
          c[i] = (3.0 * m[i] - 2.0 * b[i] - tL_ip1) / h_i;
          d[i] = (b[i] + tL_ip1 - 2.0 * m[i]) / (h_i * h_i);
        }
=======
	{
	  b[i] = m[i];
	  c[i] = 0.0;
	  d[i] = 0.0;
	}
      else
	{
	  const double h_i = x_array[i + 1] - x_array[i];
	  const double NE_next = fabs (m[i + 2] - m[i + 1]) + fabs (m[i] - m[i - 1]);
	  const double alpha_i = fabs (m[i - 1] - m[i - 2]) / NE;
	  double alpha_ip1;
	  double tL_ip1;
	  if (NE_next == 0.0)
	    {
	      tL_ip1 = m[i];
	    }
	  else
	    {
	      alpha_ip1 = fabs (m[i] - m[i - 1]) / NE_next;
	      tL_ip1 = (1.0 - alpha_ip1) * m[i] + alpha_ip1 * m[i + 1];
	    }
	  b[i] = (1.0 - alpha_i) * m[i - 1] + alpha_i * m[i];
	  c[i] = (3.0 * m[i] - 2.0 * b[i] - tL_ip1) / h_i;
	  d[i] = (b[i] + tL_ip1 - 2.0 * m[i]) / (h_i * h_i);
	}
>>>>>>> config
    }
}


static int
akima_init (void * vstate, const double x_array[], const double y_array[],
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
            size_t size)
=======
	    size_t size)
>>>>>>> config
{
  akima_state_t *state = (akima_state_t *) vstate;

  double * m = state->_m + 2; /* offset so we can address the -1,-2
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                 components */
=======
				 components */
>>>>>>> config

  size_t i;
  for (i = 0; i <= size - 2; i++)
    {
      m[i] = (y_array[i + 1] - y_array[i]) / (x_array[i + 1] - x_array[i]);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  /* non-periodic boundary conditions */
  m[-2] = 3.0 * m[0] - 2.0 * m[1];
  m[-1] = 2.0 * m[0] - m[1];
  m[size - 1] = 2.0 * m[size - 2] - m[size - 3];
  m[size] = 3.0 * m[size - 2] - 2.0 * m[size - 3];
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  akima_calc (x_array, state->b, state->c, state->d, size, m);
  
=======

  akima_calc (x_array, state->b, state->c, state->d, size, m);

>>>>>>> config
  return GSL_SUCCESS;
}


static int
akima_init_periodic (void * vstate,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     const double x_array[],
                     const double y_array[],
                     size_t size)
{
  akima_state_t *state = (akima_state_t *) vstate;
  
  double * m = state->_m + 2; /* offset so we can address the -1,-2
                                 components */
=======
		     const double x_array[],
		     const double y_array[],
		     size_t size)
{
  akima_state_t *state = (akima_state_t *) vstate;

  double * m = state->_m + 2; /* offset so we can address the -1,-2
				 components */
>>>>>>> config

  size_t i;
  for (i = 0; i <= size - 2; i++)
    {
      m[i] = (y_array[i + 1] - y_array[i]) / (x_array[i + 1] - x_array[i]);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  /* periodic boundary conditions */
  m[-2] = m[size - 1 - 2];
  m[-1] = m[size - 1 - 1];
  m[size - 1] = m[0];
  m[size] = m[1];
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  akima_calc (x_array, state->b, state->c, state->d, size, m);

  return GSL_SUCCESS;
}

static void
akima_free (void * vstate)
{
  akima_state_t *state = (akima_state_t *) vstate;

  free (state->b);
  free (state->c);
  free (state->d);
  free (state->_m);
  free (state);
}


static
int
akima_eval (const void * vstate,
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
  const akima_state_t *state = (const akima_state_t *) vstate;

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
  {
    const double x_lo = x_array[index];
    const double delx = x - x_lo;
    const double b = state->b[index];
    const double c = state->c[index];
    const double d = state->d[index];
    *y = y_array[index] + delx * (b + delx * (c + d * delx));
    return GSL_SUCCESS;
  }
}


static int
akima_eval_deriv (const void * vstate,
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
  const akima_state_t *state = (const akima_state_t *) vstate;

  size_t index;

  DISCARD_POINTER(y_array); /* prevent warning about unused parameter */
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
  {
    double x_lo = x_array[index];
    double delx = x - x_lo;
    double b = state->b[index];
    double c = state->c[index];
    double d = state->d[index];
    *dydx = b + delx * (2.0 * c + 3.0 * d * delx);
    return GSL_SUCCESS;
  }
}


static
int
akima_eval_deriv2 (const void * vstate,
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
  const akima_state_t *state = (const akima_state_t *) vstate;

  size_t index;

  DISCARD_POINTER(y_array); /* prevent warning about unused parameter */

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
  {
    const double x_lo = x_array[index];
    const double delx = x - x_lo;
    const double c = state->c[index];
    const double d = state->d[index];
    *y_pp = 2.0 * c + 6.0 * d * delx;
    return GSL_SUCCESS;
  }
}


static
int
akima_eval_integ (const void * vstate,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                  const double x_array[], const double y_array[], size_t size,
                  gsl_interp_accel * acc,
                  double a, double b,
                  double * result)
=======
		  const double x_array[], const double y_array[], size_t size,
		  gsl_interp_accel * acc,
		  double a, double b,
		  double * result)
>>>>>>> config
{
  const akima_state_t *state = (const akima_state_t *) vstate;

  size_t i, index_a, index_b;

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
  
  *result = 0.0;

  /* interior intervals */
  
=======

  *result = 0.0;

  /* interior intervals */

>>>>>>> config
  for(i=index_a; i<=index_b; i++) {
    const double x_hi = x_array[i + 1];
    const double x_lo = x_array[i];
    const double y_lo = y_array[i];
    const double dx = x_hi - x_lo;
    if(dx != 0.0) {

      if (i == index_a || i == index_b)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          double x1 = (i == index_a) ? a : x_lo;
          double x2 = (i == index_b) ? b : x_hi;
          *result += integ_eval (y_lo, state->b[i], state->c[i], state->d[i],
                                 x_lo, x1, x2);
        }
      else
        {
          *result += dx * (y_lo 
                           + dx*(0.5*state->b[i] 
                                 + dx*(state->c[i]/3.0 
                                       + 0.25*state->d[i]*dx)));
        }
=======
	{
	  double x1 = (i == index_a) ? a : x_lo;
	  double x2 = (i == index_b) ? b : x_hi;
	  *result += integ_eval (y_lo, state->b[i], state->c[i], state->d[i],
				 x_lo, x1, x2);
	}
      else
	{
	  *result += dx * (y_lo
			   + dx*(0.5*state->b[i]
				 + dx*(state->c[i]/3.0
				       + 0.25*state->d[i]*dx)));
	}
>>>>>>> config
    }
    else {
      *result = 0.0;
      return GSL_FAILURE;
    }
  }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  return GSL_SUCCESS;
}


<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
static const gsl_interp_type akima_type = 
{
  "akima", 
=======
static const gsl_interp_type akima_type =
{
  "akima",
>>>>>>> config
  5,
  &akima_alloc,
  &akima_init,
  &akima_eval,
  &akima_eval_deriv,
  &akima_eval_deriv2,
  &akima_eval_integ,
  &akima_free
};

const gsl_interp_type * gsl_interp_akima = &akima_type;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
static const gsl_interp_type akima_periodic_type = 
{
  "akima-periodic", 
=======
static const gsl_interp_type akima_periodic_type =
{
  "akima-periodic",
>>>>>>> config
  5,
  &akima_alloc,
  &akima_init_periodic,
  &akima_eval,
  &akima_eval_deriv,
  &akima_eval_deriv2,
  &akima_eval_integ,
  &akima_free
};

const gsl_interp_type * gsl_interp_akima_periodic = &akima_periodic_type;
