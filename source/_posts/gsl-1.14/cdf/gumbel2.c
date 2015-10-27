/* cdf/gumbel2.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2003, 2007 Brian Gough
 * 
=======
 *
 * Copyright (C) 2003, 2007 Brian Gough
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
#include <gsl/gsl_cdf.h>

double
gsl_cdf_gumbel2_P (const double x, const double a, const double b)
{
  double P;

  if (x == 0)
    {
      P = 0;
    }
  else
    {
      double u = pow (x, a);
      P = exp (-b / u);
    }

  return P;
}

double
gsl_cdf_gumbel2_Q (const double x, const double a, const double b)
{
  double Q;

  if (x == 0)
    {
      Q = 1;
    }
  else
    {
      double u = pow (x, a);
      Q = -expm1 (-b / u);
    }

  return Q;
}
