/* statistics/wvariance_source.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007, 2010 Jim Davies, Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007, 2010 Jim Davies, Brian Gough
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
static double 
FUNCTION(compute,wvariance) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n, const double wmean);

static double 
=======
static double
FUNCTION(compute,wvariance) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n, const double wmean);

static double
>>>>>>> config
FUNCTION(compute,wtss) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n, const double wmean);


static double
FUNCTION(compute,factor) (const BASE w[], const size_t wstride, const size_t n);

static double
FUNCTION(compute,wvariance) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n, const double wmean)
{
  /* takes a dataset and finds the weighted variance */

  long double wvariance = 0 ;
  long double W = 0;

  size_t i;

  /* find the sum of the squares */
  for (i = 0; i < n; i++)
    {
      BASE wi = w[i * wstride];

      if (wi > 0) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        const long double delta = (data[i * stride] - wmean);
        W += wi ;
        wvariance += (delta * delta - wvariance) * (wi / W);
=======
	const long double delta = (data[i * stride] - wmean);
	W += wi ;
	wvariance += (delta * delta - wvariance) * (wi / W);
>>>>>>> config
      }
    }

  return wvariance ;
}

static double
FUNCTION(compute,wtss) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n, const double wmean)
{
  /* takes a dataset and finds the weighted sum of squares about wmean*/

  long double wtss = 0 ;
  size_t i;

  /* find the sum of the squares */
  for (i = 0; i < n; i++)
    {
      BASE wi = w[i * wstride];

      if (wi > 0) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        const long double delta = (data[i * stride] - wmean);
        wtss += wi * delta * delta;
=======
	const long double delta = (data[i * stride] - wmean);
	wtss += wi * delta * delta;
>>>>>>> config
      }
    }

  return wtss ;
}


static double
FUNCTION(compute,factor) (const BASE w[], const size_t wstride, const size_t n)
{
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  /* Find the factor ``N/(N-1)'' which multiplies the raw std dev 
=======
  /* Find the factor ``N/(N-1)'' which multiplies the raw std dev
>>>>>>> config
     see the file doc/statnotes.tex for the derivation */

  long double a = 0 ;
  long double b = 0;
  long double factor;

  size_t i;

  /* find the sum of the squares */
  for (i = 0; i < n; i++)
    {
      BASE wi = w[i * wstride];

      if (wi > 0)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          a += wi ;
          b += wi * wi ;
        }
=======
	{
	  a += wi ;
	  b += wi * wi ;
	}
>>>>>>> config
    }

  factor = (a*a) / ((a*a) - b);

  return factor ;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,wvariance_with_fixed_mean) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n, const double wmean)
{
  const double wvariance = FUNCTION(compute,wvariance) (w, wstride, data, stride, n, wmean);
  return wvariance;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,wsd_with_fixed_mean) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n, const double wmean)
{
  const double wvariance = FUNCTION(compute,wvariance) (w, wstride, data, stride, n, wmean);
  const double wsd = sqrt (wvariance);

  return wsd;
}


<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,wvariance_m) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n, const double wmean)
{
  const double variance = FUNCTION(compute,wvariance) (w, wstride, data, stride, n, wmean);
  const double scale = FUNCTION(compute,factor)(w, wstride, n);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  return scale * variance;
}

double 
=======

  return scale * variance;
}

double
>>>>>>> config
FUNCTION(gsl_stats,wsd_m) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n, const double wmean)
{
  const double variance = FUNCTION(compute,wvariance) (w, wstride, data, stride, n, wmean);
  const double scale = FUNCTION(compute,factor)(w, wstride, n);
  const double wsd = sqrt(scale * variance) ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  return wsd;
}

double 
=======

  return wsd;
}

double
>>>>>>> config
FUNCTION(gsl_stats,wsd) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n)
{
  const double wmean = FUNCTION(gsl_stats,wmean) (w, wstride, data, stride, n);
  return FUNCTION(gsl_stats,wsd_m) (w, wstride, data, stride, n, wmean) ;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,wvariance) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n)
{
  const double wmean = FUNCTION(gsl_stats,wmean) (w, wstride, data, stride, n);
  return FUNCTION(gsl_stats,wvariance_m)(w, wstride, data, stride, n, wmean);
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,wtss_m) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n, const double wmean)
{
  const double wtss = FUNCTION(compute,wtss) (w, wstride, data, stride, n, wmean);
  return wtss;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,wtss) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t n)
{
  const double wmean = FUNCTION(gsl_stats,wmean) (w, wstride, data, stride, n);
  return FUNCTION(gsl_stats,wtss_m)(w, wstride, data, stride, n, wmean);
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8


=======
>>>>>>> config
