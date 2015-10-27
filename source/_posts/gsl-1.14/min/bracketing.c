/* min/bracketing.c
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

/* bracketing.c -- find an initial bracketing interval for a function to minimize */

#include <config.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_min.h>
#include <gsl/gsl_machine.h>

#include "min.h"

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
int 
gsl_min_find_bracket(gsl_function *f,double *x_minimum,double * f_minimum,
                     double * x_lower, double * f_lower, 
                     double * x_upper, double * f_upper,
                     size_t eval_max)
=======
int
gsl_min_find_bracket(gsl_function *f,double *x_minimum,double * f_minimum,
		     double * x_lower, double * f_lower,
		     double * x_upper, double * f_upper,
		     size_t eval_max)
>>>>>>> config
{
  /* The three following variables must be declared volatile to avoid storage
     in extended precision registers available on some architecture. The code
     relies on the ability to compare double values. As the values will be
     store in regular memory, the extended precision will then be lost and
     values that are different in extended precision might have equal
     representation in double precision. This behavior might break the
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
     algorithm. 
=======
     algorithm.
>>>>>>> config
   */
  volatile double f_left = *f_lower;
  volatile double f_right = *f_upper;
  volatile double f_center;
  double x_left = *x_lower;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  double x_right= *x_upper; 
  double x_center;
  const double golden = 0.3819660;      /* golden = (3 - sqrt(5))/2 */
  size_t nb_eval = 0;
  
  
  if (f_right >= f_left) 
=======
  double x_right= *x_upper;
  double x_center;
  const double golden = 0.3819660;      /* golden = (3 - sqrt(5))/2 */
  size_t nb_eval = 0;


  if (f_right >= f_left)
>>>>>>> config
    {
      x_center = (x_right - x_left) * golden + x_left;
      nb_eval++;
      SAFE_FUNC_CALL (f, x_center, &f_center);
    }
  else
    {
      x_center = x_right ;
      f_center = f_right ;
      x_right = (x_center - x_left) / golden + x_left;
      nb_eval++;
      SAFE_FUNC_CALL (f, x_right, &f_right);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  do
    {
      if (f_center < f_left )
        {
          if (f_center < f_right)
            {
              *x_lower = x_left;
              *x_upper = x_right;
              *x_minimum = x_center;
              *f_lower = f_left;
              *f_upper = f_right;
              *f_minimum = f_center;
/*            gsl_ieee_printf_double (&f_left);
              printf(" ");
              gsl_ieee_printf_double (&f_center);
              printf("\n");*/
              return GSL_SUCCESS;
            }
          else if (f_center > f_right)
            {
              x_left = x_center;
              f_left = f_center;
              x_center = x_right;
              f_center = f_right;
              x_right = (x_center - x_left) / golden + x_left;
              nb_eval++;
              SAFE_FUNC_CALL (f, x_right, &f_right);
            }
          else /* f_center == f_right */
            {
              x_right = x_center;
              f_right = f_center;
              x_center = (x_right - x_left) * golden + x_left;
              nb_eval++;
              SAFE_FUNC_CALL (f, x_center, &f_center);
            }
        }
      else /* f_center >= f_left */
        {
          x_right = x_center;
          f_right = f_center;
          x_center = (x_right - x_left) * golden + x_left;
          nb_eval++;
          SAFE_FUNC_CALL (f, x_center, &f_center);
        }
    }
  while (nb_eval < eval_max 
         && (x_right - x_left) > GSL_SQRT_DBL_EPSILON * ( (x_right + x_left) * 0.5 ) + GSL_SQRT_DBL_EPSILON);
=======

  do
    {
      if (f_center < f_left )
	{
	  if (f_center < f_right)
	    {
	      *x_lower = x_left;
	      *x_upper = x_right;
	      *x_minimum = x_center;
	      *f_lower = f_left;
	      *f_upper = f_right;
	      *f_minimum = f_center;
/*            gsl_ieee_printf_double (&f_left);
	      printf(" ");
	      gsl_ieee_printf_double (&f_center);
	      printf("\n");*/
	      return GSL_SUCCESS;
	    }
	  else if (f_center > f_right)
	    {
	      x_left = x_center;
	      f_left = f_center;
	      x_center = x_right;
	      f_center = f_right;
	      x_right = (x_center - x_left) / golden + x_left;
	      nb_eval++;
	      SAFE_FUNC_CALL (f, x_right, &f_right);
	    }
	  else /* f_center == f_right */
	    {
	      x_right = x_center;
	      f_right = f_center;
	      x_center = (x_right - x_left) * golden + x_left;
	      nb_eval++;
	      SAFE_FUNC_CALL (f, x_center, &f_center);
	    }
	}
      else /* f_center >= f_left */
	{
	  x_right = x_center;
	  f_right = f_center;
	  x_center = (x_right - x_left) * golden + x_left;
	  nb_eval++;
	  SAFE_FUNC_CALL (f, x_center, &f_center);
	}
    }
  while (nb_eval < eval_max
	 && (x_right - x_left) > GSL_SQRT_DBL_EPSILON * ( (x_right + x_left) * 0.5 ) + GSL_SQRT_DBL_EPSILON);
>>>>>>> config
  *x_lower = x_left;
  *x_upper = x_right;
  *x_minimum = x_center;
  *f_lower = f_left;
  *f_upper = f_right;
  *f_minimum = f_center;
  return GSL_FAILURE;
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
