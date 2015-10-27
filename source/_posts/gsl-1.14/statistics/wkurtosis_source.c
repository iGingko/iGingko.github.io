/* statistics/wkurtosis_source.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Jim Davies, Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Jim Davies, Brian Gough
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

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,wkurtosis) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n)
{
  const double wmean = FUNCTION(gsl_stats,wmean)(w, wstride, data, stride, n);
  const double wsd = FUNCTION(gsl_stats,wsd_m)(w, wstride, data, stride, n, wmean);
  return FUNCTION(gsl_stats,wkurtosis_m_sd)(w, wstride, data, stride, n, wmean, wsd);
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    
double 
FUNCTION(gsl_stats,wkurtosis_m_sd) (const BASE w[], const size_t wstride,
                                    const BASE data[], 
                                    const size_t stride,
                                    const size_t n,
                                    const double wmean, 
                                    const double wsd)
=======

double
FUNCTION(gsl_stats,wkurtosis_m_sd) (const BASE w[], const size_t wstride,
				    const BASE data[],
				    const size_t stride,
				    const size_t n,
				    const double wmean,
				    const double wsd)
>>>>>>> config
{
  /* takes a dataset and finds the kurtosis */

  long double wavg = 0, kurtosis;
  long double W = 0;
  size_t i;

  /* find the fourth moment the deviations, normalized by the sd */

  /* we use a recurrence relation to stably update a running value so
     there aren't any large sums that can overflow */

  for (i = 0; i < n; i++)
    {
      BASE wi = w[i * wstride];
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
      if (wi > 0) {
        const long double x = (data[i * stride] - wmean) / wsd;
        W += wi ;
        wavg += (x * x * x * x - wavg) * (wi / W);
=======

      if (wi > 0) {
	const long double x = (data[i * stride] - wmean) / wsd;
	W += wi ;
	wavg += (x * x * x * x - wavg) * (wi / W);
>>>>>>> config
      }
    }

  kurtosis = wavg - 3.0;  /* makes kurtosis zero for a Gaussian */

  return kurtosis;
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
