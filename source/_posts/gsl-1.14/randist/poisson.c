/* randist/poisson.c
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
#include <gsl/gsl_sf_gamma.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

/* The poisson distribution has the form

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
   p(n) = (mu^n / n!) exp(-mu) 
=======
   p(n) = (mu^n / n!) exp(-mu)
>>>>>>> config

   for n = 0, 1, 2, ... . The method used here is the one from Knuth. */

unsigned int
gsl_ran_poisson (const gsl_rng * r, double mu)
{
  double emu;
  double prod = 1.0;
  unsigned int k = 0;

  while (mu > 10)
    {
      unsigned int m = mu * (7.0 / 8.0);

      double X = gsl_ran_gamma_int (r, m);

      if (X >= mu)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          return k + gsl_ran_binomial (r, mu / X, m - 1);
        }
      else
        {
          k += m;
          mu -= X; 
        }
=======
	{
	  return k + gsl_ran_binomial (r, mu / X, m - 1);
	}
      else
	{
	  k += m;
	  mu -= X;
	}
>>>>>>> config
    }

  /* This following method works well when mu is small */

  emu = exp (-mu);

  do
    {
      prod *= gsl_rng_uniform (r);
      k++;
    }
  while (prod > emu);

  return k - 1;

}

void
gsl_ran_poisson_array (const gsl_rng * r, size_t n, unsigned int array[],
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                       double mu)
=======
		       double mu)
>>>>>>> config
{
  size_t i;

  for (i = 0; i < n; i++)
    {
      array[i] = gsl_ran_poisson (r, mu);
    }

  return;
}

double
gsl_ran_poisson_pdf (const unsigned int k, const double mu)
{
  double p;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  double lf = gsl_sf_lnfact (k); 
=======
  double lf = gsl_sf_lnfact (k);
>>>>>>> config

  p = exp (log (mu) * k - lf - mu);
  return p;
}
