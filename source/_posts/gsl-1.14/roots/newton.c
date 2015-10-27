/* roots/newton.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Reid Priedhorsky, Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Reid Priedhorsky, Brian Gough
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

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
/* newton.c -- newton root finding algorithm 
=======
/* newton.c -- newton root finding algorithm
>>>>>>> config

   This is the classical Newton-Raphson iteration.

   x[i+1] = x[i] - f(x[i])/f'(x[i])

*/

#include <config.h>

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_roots.h>

#include "roots.h"

typedef struct
  {
    double f, df;
  }
newton_state_t;

static int newton_init (void * vstate, gsl_function_fdf * fdf, double * root);
static int newton_iterate (void * vstate, gsl_function_fdf * fdf, double * root);

static int
newton_init (void * vstate, gsl_function_fdf * fdf, double * root)
{
  newton_state_t * state = (newton_state_t *) vstate;

  const double x = *root ;

  state->f = GSL_FN_FDF_EVAL_F (fdf, x);
  state->df = GSL_FN_FDF_EVAL_DF (fdf, x) ;

  return GSL_SUCCESS;

}

static int
newton_iterate (void * vstate, gsl_function_fdf * fdf, double * root)
{
  newton_state_t * state = (newton_state_t *) vstate;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  double root_new, f_new, df_new;

  if (state->df == 0.0)
    {
      GSL_ERROR("derivative is zero", GSL_EZERODIV);
    }

  root_new = *root - (state->f / state->df);

  *root = root_new ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  GSL_FN_FDF_EVAL_F_DF(fdf, root_new, &f_new, &df_new);

  state->f = f_new ;
  state->df = df_new ;

  if (!gsl_finite(f_new))
    {
      GSL_ERROR ("function value is not finite", GSL_EBADFUNC);
    }

  if (!gsl_finite (df_new))
    {
      GSL_ERROR ("derivative value is not finite", GSL_EBADFUNC);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
=======

>>>>>>> config
  return GSL_SUCCESS;
}


static const gsl_root_fdfsolver_type newton_type =
{"newton",                              /* name */
 sizeof (newton_state_t),
 &newton_init,
 &newton_iterate};

const gsl_root_fdfsolver_type  * gsl_root_fdfsolver_newton = &newton_type;
