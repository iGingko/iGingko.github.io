/* multimin/fdfminimizer.c
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

#include <config.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_multimin.h>

gsl_multimin_fdfminimizer *
gsl_multimin_fdfminimizer_alloc (const gsl_multimin_fdfminimizer_type * T,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                 size_t n)
=======
				 size_t n)
>>>>>>> config
{
  int status;

  gsl_multimin_fdfminimizer *s =
    (gsl_multimin_fdfminimizer *) malloc (sizeof (gsl_multimin_fdfminimizer));

  if (s == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for minimizer struct",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_ENOMEM, 0);
=======
		     GSL_ENOMEM, 0);
>>>>>>> config
    }

  s->type = T;

  s->x = gsl_vector_calloc (n);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (s->x == 0) 
=======
  if (s->x == 0)
>>>>>>> config
    {
      free (s);
      GSL_ERROR_VAL ("failed to allocate space for x", GSL_ENOMEM, 0);
    }

  s->gradient = gsl_vector_calloc (n);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (s->gradient == 0) 
=======
  if (s->gradient == 0)
>>>>>>> config
    {
      gsl_vector_free (s->x);
      free (s);
      GSL_ERROR_VAL ("failed to allocate space for gradient", GSL_ENOMEM, 0);
    }

  s->dx = gsl_vector_calloc (n);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (s->dx == 0) 
=======
  if (s->dx == 0)
>>>>>>> config
    {
      gsl_vector_free (s->x);
      gsl_vector_free (s->gradient);
      free (s);
      GSL_ERROR_VAL ("failed to allocate space for dx", GSL_ENOMEM, 0);
    }

  s->state = malloc (T->size);

  if (s->state == 0)
    {
      gsl_vector_free (s->x);
      gsl_vector_free (s->gradient);
      gsl_vector_free (s->dx);
      free (s);
      GSL_ERROR_VAL ("failed to allocate space for minimizer state",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_ENOMEM, 0);
=======
		     GSL_ENOMEM, 0);
>>>>>>> config
    }

  status = (T->alloc) (s->state, n);

  if (status != GSL_SUCCESS)
    {
      free (s->state);
      gsl_vector_free (s->x);
      gsl_vector_free (s->gradient);
      gsl_vector_free (s->dx);
      free (s);

      GSL_ERROR_VAL ("failed to initialize minimizer state", GSL_ENOMEM, 0);
    }

  return s;
}

int
gsl_multimin_fdfminimizer_set (gsl_multimin_fdfminimizer * s,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                               gsl_multimin_function_fdf * fdf,
                               const gsl_vector * x,
                               double step_size, double tol)
=======
			       gsl_multimin_function_fdf * fdf,
			       const gsl_vector * x,
			       double step_size, double tol)
>>>>>>> config
{
  if (s->x->size != fdf->n)
    {
      GSL_ERROR ("function incompatible with solver size", GSL_EBADLEN);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  if (x->size != fdf->n) 
    {
      GSL_ERROR ("vector length not compatible with function", GSL_EBADLEN);
    }  
    
=======

  if (x->size != fdf->n)
    {
      GSL_ERROR ("vector length not compatible with function", GSL_EBADLEN);
    }

>>>>>>> config
  s->fdf = fdf;

  gsl_vector_memcpy (s->x,x);
  gsl_vector_set_zero (s->dx);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  return (s->type->set) (s->state, s->fdf, s->x, &(s->f), s->gradient, step_size, tol);
}

void
gsl_multimin_fdfminimizer_free (gsl_multimin_fdfminimizer * s)
{
  RETURN_IF_NULL (s);
  (s->type->free) (s->state);
  free (s->state);
  gsl_vector_free (s->dx);
  gsl_vector_free (s->gradient);
  gsl_vector_free (s->x);
  free (s);
}

int
gsl_multimin_fdfminimizer_iterate (gsl_multimin_fdfminimizer * s)
{
  return (s->type->iterate) (s->state, s->fdf, s->x, &(s->f), s->gradient, s->dx);
}

int
gsl_multimin_fdfminimizer_restart (gsl_multimin_fdfminimizer * s)
{
  return (s->type->restart) (s->state);
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
const char * 
=======
const char *
>>>>>>> config
gsl_multimin_fdfminimizer_name (const gsl_multimin_fdfminimizer * s)
{
  return s->type->name;
}


<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_vector * 
=======
gsl_vector *
>>>>>>> config
gsl_multimin_fdfminimizer_x (const gsl_multimin_fdfminimizer * s)
{
  return s->x;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_vector * 
=======
gsl_vector *
>>>>>>> config
gsl_multimin_fdfminimizer_dx (const gsl_multimin_fdfminimizer * s)
{
  return s->dx;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_vector * 
=======
gsl_vector *
>>>>>>> config
gsl_multimin_fdfminimizer_gradient (const gsl_multimin_fdfminimizer * s)
{
  return s->gradient;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
gsl_multimin_fdfminimizer_minimum (const gsl_multimin_fdfminimizer * s)
{
  return s->f;
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
