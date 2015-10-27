/* sys/expm1.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Gerard Jungman, Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Gerard Jungman, Brian Gough
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
#include <math.h>
#include <gsl/gsl_math.h>

double gsl_expm1 (const double x)
{
  /* FIXME: this should be improved */

  if (fabs(x) < M_LN2)
    {
      /* Compute the taylor series S = x + (1/2!) x^2 + (1/3!) x^3 + ... */

      double i = 1.0;
      double sum = x;
      double term = x / 1.0;

      do
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          i++ ;
          term *= x/i;
          sum += term;
        }
      while (fabs(term) > fabs(sum) * GSL_DBL_EPSILON) ;
      
=======
	{
	  i++ ;
	  term *= x/i;
	  sum += term;
	}
      while (fabs(term) > fabs(sum) * GSL_DBL_EPSILON) ;

>>>>>>> config
      return sum ;
    }
  else
    {
      return exp(x) - 1;
    }
}
