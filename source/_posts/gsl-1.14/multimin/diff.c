/* multimin/diff.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2000 David Morrison
 * 
=======
 *
 * Copyright (C) 2000 David Morrison
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
#include <gsl/gsl_multimin.h>

int
gsl_multimin_diff (const gsl_multimin_function * f,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                   const gsl_vector * x, gsl_vector * g)
=======
		   const gsl_vector * x, gsl_vector * g)
>>>>>>> config
{
  size_t i, n = f->n;

  double h = GSL_SQRT_DBL_EPSILON;


  gsl_vector * x1 = gsl_vector_alloc (n);  /* FIXME: pass as argument */

  gsl_vector_memcpy (x1, x);

  for (i = 0; i < n; i++)
    {
      double fl, fh;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
      double xi = gsl_vector_get (x, i);
      double dx = fabs(xi) * h;

      if (dx == 0.0) dx = h;

      gsl_vector_set (x1, i, xi + dx);
      fh = GSL_MULTIMIN_FN_EVAL(f, x1);

      gsl_vector_set (x1, i, xi - dx);
      fl = GSL_MULTIMIN_FN_EVAL(f, x1);

      gsl_vector_set (x1, i, xi);
      gsl_vector_set (g, i, (fh - fl) / (2.0 * dx));
    }

  gsl_vector_free (x1);

  return GSL_SUCCESS;
}
