/* statistics/variance_source.c
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
static double 
FUNCTION(compute,variance) (const BASE data[], const size_t stride, const size_t n, const double mean);

static double 
=======
static double
FUNCTION(compute,variance) (const BASE data[], const size_t stride, const size_t n, const double mean);

static double
>>>>>>> config
FUNCTION(compute,tss) (const BASE data[], const size_t stride, const size_t n, const double mean);

static double
FUNCTION(compute,variance) (const BASE data[], const size_t stride, const size_t n, const double mean)
{
  /* takes a dataset and finds the variance */

  long double variance = 0 ;

  size_t i;

  /* find the sum of the squares */
  for (i = 0; i < n; i++)
    {
      const long double delta = (data[i * stride] - mean);
      variance += (delta * delta - variance) / (i + 1);
    }

  return variance ;
}

static double
FUNCTION(compute,tss) (const BASE data[], const size_t stride, const size_t n, const double mean)
{
  /* takes a dataset and finds the sum of squares about the mean */

  long double tss = 0 ;

  size_t i;

  /* find the sum of the squares */
  for (i = 0; i < n; i++)
    {
      const long double delta = (data[i * stride] - mean);
      tss += delta * delta;
    }

  return tss ;
}


<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,variance_with_fixed_mean) (const BASE data[], const size_t stride, const size_t n, const double mean)
{
  const double variance = FUNCTION(compute,variance) (data, stride, n, mean);
  return variance;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,sd_with_fixed_mean) (const BASE data[], const size_t stride, const size_t n, const double mean)
{
  const double variance = FUNCTION(compute,variance) (data, stride, n, mean);
  const double sd = sqrt (variance);

  return sd;
}



<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
FUNCTION(gsl_stats,variance_m) (const BASE data[], const size_t stride, const size_t n, const double mean)
{
  const double variance = FUNCTION(compute,variance) (data, stride, n, mean);
  
  return variance * ((double)n / (double)(n - 1));
}

double 
=======
double
FUNCTION(gsl_stats,variance_m) (const BASE data[], const size_t stride, const size_t n, const double mean)
{
  const double variance = FUNCTION(compute,variance) (data, stride, n, mean);

  return variance * ((double)n / (double)(n - 1));
}

double
>>>>>>> config
FUNCTION(gsl_stats,sd_m) (const BASE data[], const size_t stride, const size_t n, const double mean)
{
  const double variance = FUNCTION(compute,variance) (data, stride, n, mean);
  const double sd = sqrt (variance * ((double)n / (double)(n - 1)));

  return sd;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,variance) (const BASE data[], const size_t stride, const size_t n)
{
  const double mean = FUNCTION(gsl_stats,mean) (data, stride, n);
  return FUNCTION(gsl_stats,variance_m)(data, stride, n, mean);
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
=======
double
>>>>>>> config
FUNCTION(gsl_stats,sd) (const BASE data[], const size_t stride, const size_t n)
{
  const double mean = FUNCTION(gsl_stats,mean) (data, stride, n);
  return FUNCTION(gsl_stats,sd_m) (data, stride, n, mean);
}


<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
double 
FUNCTION(gsl_stats,tss_m) (const BASE data[], const size_t stride, const size_t n, const double mean)
{
  const double tss = FUNCTION(compute,tss) (data, stride, n, mean);
  
  return tss;
}

double 
=======
double
FUNCTION(gsl_stats,tss_m) (const BASE data[], const size_t stride, const size_t n, const double mean)
{
  const double tss = FUNCTION(compute,tss) (data, stride, n, mean);

  return tss;
}

double
>>>>>>> config
FUNCTION(gsl_stats,tss) (const BASE data[], const size_t stride, const size_t n)
{
  const double mean = FUNCTION(gsl_stats,mean) (data, stride, n);
  return FUNCTION(gsl_stats,tss_m)(data, stride, n, mean);
}
