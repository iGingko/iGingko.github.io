/* randist/hyperg.c
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
#include <gsl/gsl_sf_gamma.h>

/* The hypergeometric distribution has the form,

   prob(k) =  choose(n1,t) choose(n2, t-k) / choose(n1+n2,t)

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
   where choose(a,b) = a!/(b!(a-b)!) 
=======
   where choose(a,b) = a!/(b!(a-b)!)
>>>>>>> config

   n1 + n2 is the total population (tagged plus untagged)
   n1 is the tagged population
   t is the number of samples taken (without replacement)
   k is the number of tagged samples found

*/

unsigned int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_ran_hypergeometric (const gsl_rng * r, unsigned int n1, unsigned int n2, 
                        unsigned int t)
=======
gsl_ran_hypergeometric (const gsl_rng * r, unsigned int n1, unsigned int n2,
			unsigned int t)
>>>>>>> config
{
  const unsigned int n = n1 + n2;

  unsigned int i = 0;
  unsigned int a = n1;
  unsigned int b = n1 + n2;
  unsigned int k = 0;

  if (t > n)
    {
      t = n ;
    }

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (t < n / 2) 
    {
      for (i = 0 ; i < t ; i++)
        {
          double u = gsl_rng_uniform(r) ;
          
          if (b * u < a)
            {
              k++ ;
              if (k == n1)
                return k ;
              a-- ;
            }
          b-- ;
        }
=======
  if (t < n / 2)
    {
      for (i = 0 ; i < t ; i++)
	{
	  double u = gsl_rng_uniform(r) ;

	  if (b * u < a)
	    {
	      k++ ;
	      if (k == n1)
		return k ;
	      a-- ;
	    }
	  b-- ;
	}
>>>>>>> config
      return k;
    }
  else
    {
      for (i = 0 ; i < n - t ; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          double u = gsl_rng_uniform(r) ;
          
          if (b * u < a)
            {
              k++ ;
              if (k == n1)
                return n1 - k ;
              a-- ;
            }
          b-- ;
        }
=======
	{
	  double u = gsl_rng_uniform(r) ;

	  if (b * u < a)
	    {
	      k++ ;
	      if (k == n1)
		return n1 - k ;
	      a-- ;
	    }
	  b-- ;
	}
>>>>>>> config
      return n1 - k;
    }


}

double
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_ran_hypergeometric_pdf (const unsigned int k, 
                            const unsigned int n1, 
                            const unsigned int n2, 
                            unsigned int t)
=======
gsl_ran_hypergeometric_pdf (const unsigned int k,
			    const unsigned int n1,
			    const unsigned int n2,
			    unsigned int t)
>>>>>>> config
{
  if (t > n1 + n2)
    {
      t = n1 + n2 ;
    }

  if (k > n1 || k > t)
    {
      return 0 ;
    }
  else if (t > n2 && k + n2 < t )
    {
      return 0 ;
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  else 
    {
      double p;
      
=======
  else
    {
      double p;

>>>>>>> config
      double c1 = gsl_sf_lnchoose(n1,k);
      double c2 = gsl_sf_lnchoose(n2,t-k);
      double c3 = gsl_sf_lnchoose(n1+n2,t);

      p = exp(c1 + c2 - c3) ;

      return p;
    }
}
