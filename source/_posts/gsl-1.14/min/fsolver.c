/* min/fsolver.c
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
#include <string.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_min.h>

#include "min.h"

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
static int 
compute_f_values (gsl_function * f, double x_minimum, double * f_minimum,
                  double x_lower, double * f_lower, 
                  double x_upper, double * f_upper);


static int 
compute_f_values (gsl_function * f, double x_minimum, double * f_minimum,
                  double x_lower, double * f_lower,
                  double x_upper, double * f_upper)
=======
static int
compute_f_values (gsl_function * f, double x_minimum, double * f_minimum,
		  double x_lower, double * f_lower,
		  double x_upper, double * f_upper);


static int
compute_f_values (gsl_function * f, double x_minimum, double * f_minimum,
		  double x_lower, double * f_lower,
		  double x_upper, double * f_upper)
>>>>>>> config
{
  SAFE_FUNC_CALL(f, x_lower, f_lower);
  SAFE_FUNC_CALL(f, x_upper, f_upper);
  SAFE_FUNC_CALL(f, x_minimum, f_minimum);

  return GSL_SUCCESS;
}

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_min_fminimizer_set (gsl_min_fminimizer * s, 
                        gsl_function * f, 
                        double x_minimum, double x_lower, double x_upper)
=======
gsl_min_fminimizer_set (gsl_min_fminimizer * s,
			gsl_function * f,
			double x_minimum, double x_lower, double x_upper)
>>>>>>> config
{
  int status ;

  double f_minimum, f_lower, f_upper;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  status = compute_f_values (f, x_minimum, &f_minimum, 
                             x_lower, &f_lower,  
                             x_upper, &f_upper);
=======
  status = compute_f_values (f, x_minimum, &f_minimum,
			     x_lower, &f_lower,
			     x_upper, &f_upper);
>>>>>>> config

  if (status != GSL_SUCCESS)
    {
      return status ;
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  status = gsl_min_fminimizer_set_with_values (s, f, x_minimum, f_minimum, 
                                               x_lower, f_lower,
                                               x_upper, f_upper);
=======

  status = gsl_min_fminimizer_set_with_values (s, f, x_minimum, f_minimum,
					       x_lower, f_lower,
					       x_upper, f_upper);
>>>>>>> config
  return status;
}

gsl_min_fminimizer *
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_min_fminimizer_alloc (const gsl_min_fminimizer_type * T) 
{
  gsl_min_fminimizer * s = 
=======
gsl_min_fminimizer_alloc (const gsl_min_fminimizer_type * T)
{
  gsl_min_fminimizer * s =
>>>>>>> config
    (gsl_min_fminimizer *) malloc (sizeof (gsl_min_fminimizer));

  if (s == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for minimizer struct",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    };

  s->state = malloc (T->size);

  if (s->state == 0)
    {
      free (s);         /* exception in constructor, avoid memory leak */

      GSL_ERROR_VAL ("failed to allocate space for minimizer state",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    };

  s->type = T ;
  s->function = NULL;

  return s;
}

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_min_fminimizer_set_with_values (gsl_min_fminimizer * s, gsl_function * f, 
                                    double x_minimum, double f_minimum, 
                                    double x_lower, double f_lower,
                                    double x_upper, double f_upper)
=======
gsl_min_fminimizer_set_with_values (gsl_min_fminimizer * s, gsl_function * f,
				    double x_minimum, double f_minimum,
				    double x_lower, double f_lower,
				    double x_upper, double f_upper)
>>>>>>> config
{
  s->function = f;
  s->x_minimum = x_minimum;
  s->x_lower = x_lower;
  s->x_upper = x_upper;

  if (x_lower > x_upper)
    {
      GSL_ERROR ("invalid interval (lower > upper)", GSL_EINVAL);
    }

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (x_minimum >= x_upper || x_minimum <= x_lower) 
    {
      GSL_ERROR ("x_minimum must lie inside interval (lower < x < upper)",
                 GSL_EINVAL);
=======
  if (x_minimum >= x_upper || x_minimum <= x_lower)
    {
      GSL_ERROR ("x_minimum must lie inside interval (lower < x < upper)",
		 GSL_EINVAL);
>>>>>>> config
    }

  s->f_lower = f_lower;
  s->f_upper = f_upper;
  s->f_minimum = f_minimum;

  if (f_minimum >= f_lower || f_minimum >= f_upper)
    {
      GSL_ERROR ("endpoints do not enclose a minimum", GSL_EINVAL);
    }

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  return (s->type->set) (s->state, s->function, 
                         x_minimum, f_minimum, 
                         x_lower, f_lower,
                         x_upper, f_upper);
=======
  return (s->type->set) (s->state, s->function,
			 x_minimum, f_minimum,
			 x_lower, f_lower,
			 x_upper, f_upper);
>>>>>>> config
}


int
gsl_min_fminimizer_iterate (gsl_min_fminimizer * s)
{
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  return (s->type->iterate) (s->state, s->function, 
                             &(s->x_minimum), &(s->f_minimum),
                             &(s->x_lower), &(s->f_lower), 
                             &(s->x_upper), &(s->f_upper));
=======
  return (s->type->iterate) (s->state, s->function,
			     &(s->x_minimum), &(s->f_minimum),
			     &(s->x_lower), &(s->f_lower),
			     &(s->x_upper), &(s->f_upper));
>>>>>>> config
}

void
gsl_min_fminimizer_free (gsl_min_fminimizer * s)
{
  RETURN_IF_NULL (s);
  free (s->state);
  free (s);
}

const char *
gsl_min_fminimizer_name (const gsl_min_fminimizer * s)
{
  return s->type->name;
}

/* Deprecated, use x_minimum instead */
double
gsl_min_fminimizer_minimum (const gsl_min_fminimizer * s)
{
  return s->x_minimum;
}

double
gsl_min_fminimizer_x_minimum (const gsl_min_fminimizer * s)
{
  return s->x_minimum;
}

double
gsl_min_fminimizer_x_lower (const gsl_min_fminimizer * s)
{
  return s->x_lower;
}

double
gsl_min_fminimizer_x_upper (const gsl_min_fminimizer * s)
{
  return s->x_upper;
}

double
gsl_min_fminimizer_f_minimum (const gsl_min_fminimizer * s)
{
  return s->f_minimum;
}

double
gsl_min_fminimizer_f_lower (const gsl_min_fminimizer * s)
{
  return s->f_lower;
}

double
gsl_min_fminimizer_f_upper (const gsl_min_fminimizer * s)
{
  return s->f_upper;
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
