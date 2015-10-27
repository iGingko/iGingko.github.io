/* randist/binomial.c
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
#include <gsl/gsl_sys.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_sf_gamma.h>

/* The binomial distribution has the form,

   prob(k) =  n!/(k!(n-k)!) *  p^k (1-p)^(n-k) for k = 0, 1, ..., n

   This is the algorithm from Knuth */

/* Default binomial generator is now in binomial_tpe.c */

unsigned int
gsl_ran_binomial_knuth (const gsl_rng * r, double p, unsigned int n)
{
  unsigned int i, a, b, k = 0;

  while (n > 10)        /* This parameter is tunable */
    {
      double X;
      a = 1 + (n / 2);
      b = 1 + n - a;

      X = gsl_ran_beta (r, (double) a, (double) b);

      if (X >= p)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          n = a - 1;
          p /= X;
        }
      else
        {
          k += a;
          n = b - 1;
          p = (p - X) / (1 - X);
        }
=======
	{
	  n = a - 1;
	  p /= X;
	}
      else
	{
	  k += a;
	  n = b - 1;
	  p = (p - X) / (1 - X);
	}
>>>>>>> config
    }

  for (i = 0; i < n; i++)
    {
      double u = gsl_rng_uniform (r);
      if (u < p)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        k++;
=======
	k++;
>>>>>>> config
    }

  return k;
}

double
gsl_ran_binomial_pdf (const unsigned int k, const double p,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                      const unsigned int n)
=======
		      const unsigned int n)
>>>>>>> config
{
  if (k > n)
    {
      return 0;
    }
  else
    {
      double P;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      if (p == 0) 
        {
          P = (k == 0) ? 1 : 0;
        }
      else if (p == 1)
        {
          P = (k == n) ? 1 : 0;
        }
      else
        {
          double ln_Cnk = gsl_sf_lnchoose (n, k);
          P = ln_Cnk + k * log (p) + (n - k) * log1p (-p);
          P = exp (P);
        }
=======
      if (p == 0)
	{
	  P = (k == 0) ? 1 : 0;
	}
      else if (p == 1)
	{
	  P = (k == n) ? 1 : 0;
	}
      else
	{
	  double ln_Cnk = gsl_sf_lnchoose (n, k);
	  P = ln_Cnk + k * log (p) + (n - k) * log1p (-p);
	  P = exp (P);
	}
>>>>>>> config

      return P;
    }
}
