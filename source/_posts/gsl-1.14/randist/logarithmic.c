/* randist/logarithmic.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 James Theiler, Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 James Theiler, Brian Gough
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
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
/* Logarithmic distribution 
=======
/* Logarithmic distribution
>>>>>>> config

   prob(n) =   p^n / (n log(1/(1-p)) for n = 1, 2, 3, ...

   We use Kemp's second accelerated generator, from Luc Devroye's book
   on "Non-Uniform Random Variate Generation", Springer */

unsigned int
gsl_ran_logarithmic (const gsl_rng * r, const double p)
{
  double c = log (1-p) ;

  double v = gsl_rng_uniform_pos (r);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (v >= p)
    {
      return 1 ;
    }
  else
    {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      double u = gsl_rng_uniform_pos (r);      
      double q = 1 - exp (c * u);

      if (v <= q*q)
        {
          double x = 1 + log(v)/log(q) ;
          return x ;
        }
      else if (v <= q)
        {
          return 2;
        }
      else
        {
          return 1 ;
        }
=======
      double u = gsl_rng_uniform_pos (r);
      double q = 1 - exp (c * u);

      if (v <= q*q)
	{
	  double x = 1 + log(v)/log(q) ;
	  return x ;
	}
      else if (v <= q)
	{
	  return 2;
	}
      else
	{
	  return 1 ;
	}
>>>>>>> config
    }
}

double
gsl_ran_logarithmic_pdf (const unsigned int k, const double p)
{
  if (k == 0)
    {
      return 0 ;
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  else 
=======
  else
>>>>>>> config
    {
      double P = pow(p, (double)k) / (double) k / log(1/(1-p)) ;
      return P;
    }
}
