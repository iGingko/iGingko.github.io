/* ieee-utils/print.c
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
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_ieee_utils.h>

/* A table of sign characters, 0=positive, 1=negative. We print a space
   instead of a unary + sign for compatibility with bc */

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
static char signs[2]={' ','-'} ;  

void 
=======
static char signs[2]={' ','-'} ;

void
>>>>>>> config
gsl_ieee_fprintf_float (FILE * stream, const float * x) {
  gsl_ieee_float_rep r ;
  gsl_ieee_float_to_rep(x, &r) ;

  switch (r.type)
    {
    case GSL_IEEE_TYPE_NAN:
      fprintf(stream, "NaN") ;
      break ;
    case GSL_IEEE_TYPE_INF:
      fprintf(stream, "%cInf", signs[r.sign]) ;
      break ;
    case GSL_IEEE_TYPE_NORMAL:
      fprintf(stream, "%c1.%s*2^%d", signs[r.sign], r.mantissa, r.exponent) ;
      break ;
    case GSL_IEEE_TYPE_DENORMAL:
      fprintf(stream, "%c0.%s*2^%d", signs[r.sign], r.mantissa, r.exponent + 1) ;
      break ;
    case GSL_IEEE_TYPE_ZERO:
      fprintf(stream, "%c0", signs[r.sign]) ;
      break ;
    default:
      fprintf(stream, "[non-standard IEEE float]") ;
    }
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
void 
=======
void
>>>>>>> config
gsl_ieee_printf_float (const float * x)
{
  gsl_ieee_fprintf_float (stdout,x);
}

void
gsl_ieee_fprintf_double (FILE * stream, const double * x) {
  gsl_ieee_double_rep r ;
  gsl_ieee_double_to_rep (x, &r) ;

  switch (r.type)
    {
    case GSL_IEEE_TYPE_NAN:
      fprintf(stream, "NaN") ;
      break ;
    case GSL_IEEE_TYPE_INF:
      fprintf(stream, "%cInf", signs[r.sign]) ;
      break ;
    case GSL_IEEE_TYPE_NORMAL:
      fprintf(stream, "%c1.%s*2^%d", signs[r.sign], r.mantissa, r.exponent) ;
      break ;
    case GSL_IEEE_TYPE_DENORMAL:
      fprintf(stream, "%c0.%s*2^%d", signs[r.sign], r.mantissa, r.exponent + 1) ;
      break ;
    case GSL_IEEE_TYPE_ZERO:
      fprintf(stream, "%c0", signs[r.sign]) ;
      break ;
    default:
      fprintf(stream, "[non-standard IEEE double]") ;
    }
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
void 
=======
void
>>>>>>> config
gsl_ieee_printf_double (const double * x)
{
  gsl_ieee_fprintf_double (stdout,x);
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8





=======
>>>>>>> config
