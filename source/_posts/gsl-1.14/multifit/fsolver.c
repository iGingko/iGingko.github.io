/* multifit/fsolver.c
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
#include <gsl/gsl_multifit_nlin.h>

gsl_multifit_fsolver *
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_multifit_fsolver_alloc (const gsl_multifit_fsolver_type * T, 
                            size_t n, size_t p) 
=======
gsl_multifit_fsolver_alloc (const gsl_multifit_fsolver_type * T,
			    size_t n, size_t p)
>>>>>>> config
{
  int status;

  gsl_multifit_fsolver * s;

  if (n < p)
    {
      GSL_ERROR_VAL ("insufficient data points, n < p", GSL_EINVAL, 0);
    }

  s = (gsl_multifit_fsolver *) malloc (sizeof (gsl_multifit_fsolver));

  if (s == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for multifit solver struct",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  s->x = gsl_vector_calloc (p);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (s->x == 0) 
=======
  if (s->x == 0)
>>>>>>> config
    {
      free (s);
      GSL_ERROR_VAL ("failed to allocate space for x", GSL_ENOMEM, 0);
    }

  s->f = gsl_vector_calloc (n);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (s->f == 0) 
=======
  if (s->f == 0)
>>>>>>> config
    {
      gsl_vector_free (s->x);
      free (s);
      GSL_ERROR_VAL ("failed to allocate space for f", GSL_ENOMEM, 0);
    }

  s->dx = gsl_vector_calloc (p);

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (s->dx == 0) 
=======
  if (s->dx == 0)
>>>>>>> config
    {
      gsl_vector_free (s->x);
      gsl_vector_free (s->f);
      free (s);
      GSL_ERROR_VAL ("failed to allocate space for dx", GSL_ENOMEM, 0);
    }

  s->state = malloc (T->size);

  if (s->state == 0)
    {
      gsl_vector_free (s->dx);
      gsl_vector_free (s->x);
      gsl_vector_free (s->f);
      free (s);         /* exception in constructor, avoid memory leak */
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
      GSL_ERROR_VAL ("failed to allocate space for multifit solver state",
                        GSL_ENOMEM, 0);
=======

      GSL_ERROR_VAL ("failed to allocate space for multifit solver state",
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  s->type = T ;

  status = (s->type->alloc)(s->state, n, p);

  if (status != GSL_SUCCESS)
    {
      (s->type->free)(s->state);
      free (s->state);
      gsl_vector_free (s->dx);
      gsl_vector_free (s->x);
      gsl_vector_free (s->f);
      free (s);         /* exception in constructor, avoid memory leak */
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
      GSL_ERROR_VAL ("failed to set solver", status, 0);
    }
  
=======

      GSL_ERROR_VAL ("failed to set solver", status, 0);
    }

>>>>>>> config
  s->function = NULL;

  return s;
}

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_multifit_fsolver_set (gsl_multifit_fsolver * s, 
                          gsl_multifit_function * f, 
                          const gsl_vector * x)
=======
gsl_multifit_fsolver_set (gsl_multifit_fsolver * s,
			  gsl_multifit_function * f,
			  const gsl_vector * x)
>>>>>>> config
{
  if (s->f->size != f->n)
    {
      GSL_ERROR ("function size does not match solver", GSL_EBADLEN);
    }

  if (s->x->size != x->size)
    {
      GSL_ERROR ("vector length does not match solver", GSL_EBADLEN);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    }  
  
  s->function = f;
  gsl_vector_memcpy(s->x,x);
  
=======
    }

  s->function = f;
  gsl_vector_memcpy(s->x,x);

>>>>>>> config
  return (s->type->set) (s->state, s->function, s->x, s->f, s->dx);
}

int
gsl_multifit_fsolver_iterate (gsl_multifit_fsolver * s)
{
  return (s->type->iterate) (s->state, s->function, s->x, s->f, s->dx);
}

void
gsl_multifit_fsolver_free (gsl_multifit_fsolver * s)
{
  RETURN_IF_NULL (s);
  (s->type->free) (s->state);
  free (s->state);
  gsl_vector_free (s->dx);
  gsl_vector_free (s->x);
  gsl_vector_free (s->f);
  free (s);
}

const char *
gsl_multifit_fsolver_name (const gsl_multifit_fsolver * s)
{
  return s->type->name;
}

gsl_vector *
gsl_multifit_fsolver_position (const gsl_multifit_fsolver * s)
{
  return s->x;
}
