/* randist/multinomial.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2002 Gavin E. Crooks <gec@compbio.berkeley.edu>
 * 
=======
 *
 * Copyright (C) 2002 Gavin E. Crooks <gec@compbio.berkeley.edu>
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
#include <gsl/gsl_sf_gamma.h>

/* The multinomial distribution has the form

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                      N!           n_1  n_2      n_K
   prob(n_1, n_2, ... n_K) = -------------------- p_1  p_2  ... p_K
                             (n_1! n_2! ... n_K!) 

   where n_1, n_2, ... n_K are nonnegative integers, sum_{k=1,K} n_k = N,
   and p = (p_1, p_2, ..., p_K) is a probability distribution. 
=======
				      N!           n_1  n_2      n_K
   prob(n_1, n_2, ... n_K) = -------------------- p_1  p_2  ... p_K
			     (n_1! n_2! ... n_K!)

   where n_1, n_2, ... n_K are nonnegative integers, sum_{k=1,K} n_k = N,
   and p = (p_1, p_2, ..., p_K) is a probability distribution.
>>>>>>> config

   Random variates are generated using the conditional binomial method.
   This scales well with N and does not require a setup step.

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
   Ref: 
=======
   Ref:
>>>>>>> config
   C.S. David, The computer generation of multinomial random variates,
   Comp. Stat. Data Anal. 16 (1993) 205-217
*/

void
gsl_ran_multinomial (const gsl_rng * r, const size_t K,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     const unsigned int N, const double p[], unsigned int n[])
=======
		     const unsigned int N, const double p[], unsigned int n[])
>>>>>>> config
{
  size_t k;
  double norm = 0.0;
  double sum_p = 0.0;

  unsigned int sum_n = 0;

  /* p[k] may contain non-negative weights that do not sum to 1.0.
   * Even a probability distribution will not exactly sum to 1.0
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
   * due to rounding errors. 
=======
   * due to rounding errors.
>>>>>>> config
   */

  for (k = 0; k < K; k++)
    {
      norm += p[k];
    }

  for (k = 0; k < K; k++)
    {
      if (p[k] > 0.0)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          n[k] = gsl_ran_binomial (r, p[k] / (norm - sum_p), N - sum_n);
        }
      else
        {
          n[k] = 0;
        }
=======
	{
	  n[k] = gsl_ran_binomial (r, p[k] / (norm - sum_p), N - sum_n);
	}
      else
	{
	  n[k] = 0;
	}
>>>>>>> config

      sum_p += p[k];
      sum_n += n[k];
    }

}


double
gsl_ran_multinomial_pdf (const size_t K,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                         const double p[], const unsigned int n[])
=======
			 const double p[], const unsigned int n[])
>>>>>>> config
{
  return exp (gsl_ran_multinomial_lnpdf (K, p, n));
}


double
gsl_ran_multinomial_lnpdf (const size_t K,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                           const double p[], const unsigned int n[])
=======
			   const double p[], const unsigned int n[])
>>>>>>> config
{
  size_t k;
  unsigned int N = 0;
  double log_pdf = 0.0;
  double norm = 0.0;

  for (k = 0; k < K; k++)
    {
      N += n[k];
    }

  for (k = 0; k < K; k++)
    {
      norm += p[k];
    }

  log_pdf = gsl_sf_lnfact (N);

  for (k = 0; k < K; k++)
    {
      /* Handle case where n[k]==0 and p[k]==0 */

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      if (n[k] > 0) 
        {
          log_pdf += log (p[k] / norm) * n[k] - gsl_sf_lnfact (n[k]);
        }
=======
      if (n[k] > 0)
	{
	  log_pdf += log (p[k] / norm) * n[k] - gsl_sf_lnfact (n[k]);
	}
>>>>>>> config
    }

  return log_pdf;
}
