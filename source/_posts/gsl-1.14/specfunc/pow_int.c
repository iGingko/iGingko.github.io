/* specfunc/pow_int.c
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

/* Author:  G. Jungman */

#include <config.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_sf_pow_int.h>


/*-*-*-*-*-*-*-*-*-*-*-* Functions w/ Error handling *-*-*-*-*-*-*-*-*-*-*-*/

int gsl_sf_pow_int_e(double x, int n, gsl_sf_result * result)
{
  double value = 1.0;
  int count = 0;

  /* CHECK_POINTER(result) */


  if(n < 0) {
    n = -n;

    if(x == 0.0) {
      double u = 1.0 / x;
      result->val = (n % 2) ? u : (u * u) ;  /* correct sign of infinity */
      result->err = GSL_POSINF;
      GSL_ERROR ("overflow", GSL_EOVRFLW);
    }

    x = 1.0/x;
  }

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  /* repeated squaring method 
=======
  /* repeated squaring method
>>>>>>> config
   * returns 0.0^0 = 1.0, so continuous in x
   */
  do {
     if(GSL_IS_ODD(n)) value *= x;
     n >>= 1;
     x *= x;
     ++count;
  } while (n);

  result->val = value;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  result->err = 2.0 * GSL_DBL_EPSILON * (count + 1.0) * fabs(value); 
=======
  result->err = 2.0 * GSL_DBL_EPSILON * (count + 1.0) * fabs(value);
>>>>>>> config

  return GSL_SUCCESS;
}

/*-*-*-*-*-*-*-*-*-* Functions w/ Natural Prototypes *-*-*-*-*-*-*-*-*-*-*/

#include "eval.h"

double gsl_sf_pow_int(const double x, const int n)
{
  EVAL_RESULT(gsl_sf_pow_int_e(x, n, &result));
}
