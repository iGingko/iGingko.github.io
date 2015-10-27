/* multiroots/newton.c
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

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_linalg.h>

typedef struct
  {
    gsl_matrix * lu;
    gsl_permutation * permutation;
  }
newton_state_t;

static int newton_alloc (void * vstate, size_t n);
static int newton_set (void * vstate, gsl_multiroot_function_fdf * fdf, gsl_vector * x, gsl_vector * f, gsl_matrix * J, gsl_vector * dx);
static int newton_iterate (void * vstate, gsl_multiroot_function_fdf * fdf, gsl_vector * x, gsl_vector * f, gsl_matrix * J, gsl_vector * dx);
static void newton_free (void * vstate);

static int
newton_alloc (void * vstate, size_t n)
{
  newton_state_t * state = (newton_state_t *) vstate;
  gsl_permutation * p;
  gsl_matrix * m;

  m = gsl_matrix_calloc (n,n);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  if (m == 0) 
=======

  if (m == 0)
>>>>>>> config
    {
      GSL_ERROR ("failed to allocate space for lu", GSL_ENOMEM);
    }

  state->lu = m ;

  p = gsl_permutation_calloc (n);

  if (p == 0)
    {
      gsl_matrix_free(m);

      GSL_ERROR ("failed to allocate space for permutation", GSL_ENOMEM);
    }

  state->permutation = p ;

  return GSL_SUCCESS;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
static int 
=======
static int
>>>>>>> config
newton_set (void * vstate, gsl_multiroot_function_fdf * FDF, gsl_vector * x, gsl_vector * f, gsl_matrix * J, gsl_vector * dx)
{
  newton_state_t * state = (newton_state_t *) vstate;

  size_t i, n = FDF->n ;

  state = 0 ; /* avoid warnings about unused parameters */

  GSL_MULTIROOT_FN_EVAL_F_DF (FDF, x, f, J);

  for (i = 0; i < n; i++)
    {
      gsl_vector_set (dx, i, 0.0);
    }

  return GSL_SUCCESS;
}

static int
newton_iterate (void * vstate, gsl_multiroot_function_fdf * fdf, gsl_vector * x, gsl_vector * f, gsl_matrix * J, gsl_vector * dx)
{
  newton_state_t * state = (newton_state_t *) vstate;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  int signum;

  size_t i;

  size_t n = fdf->n ;

  gsl_matrix_memcpy (state->lu, J);

  gsl_linalg_LU_decomp (state->lu, state->permutation, &signum);

  gsl_linalg_LU_solve (state->lu, state->permutation, f, dx);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
=======

>>>>>>> config
  for (i = 0; i < n; i++)
    {
      double e = gsl_vector_get (dx, i);
      double y = gsl_vector_get (x, i);
      gsl_vector_set (dx, i, -e);
      gsl_vector_set (x, i, y - e);
    }

  {
    int status = GSL_MULTIROOT_FN_EVAL_F_DF (fdf, x, f, J);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    
    if (status != GSL_SUCCESS) 
      {
        return GSL_EBADFUNC;
=======

    if (status != GSL_SUCCESS)
      {
	return GSL_EBADFUNC;
>>>>>>> config
      }
  }

  return GSL_SUCCESS;
}


static void
newton_free (void * vstate)
{
  newton_state_t * state = (newton_state_t *) vstate;

  gsl_matrix_free(state->lu);

  gsl_permutation_free(state->permutation);
}


static const gsl_multiroot_fdfsolver_type newton_type =
{"newton",                              /* name */
 sizeof (newton_state_t),
 &newton_alloc,
 &newton_set,
 &newton_iterate,
 &newton_free};

const gsl_multiroot_fdfsolver_type  * gsl_multiroot_fdfsolver_newton = &newton_type;
