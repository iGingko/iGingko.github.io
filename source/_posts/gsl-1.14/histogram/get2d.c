/* histogram/get2d.c
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
#include <gsl/gsl_errno.h>
#include <gsl/gsl_histogram2d.h>

#include "find.c"

double
gsl_histogram2d_get (const gsl_histogram2d * h, const size_t i, const size_t j)
{
  const size_t nx = h->nx;
  const size_t ny = h->ny;

  if (i >= nx)
    {
      GSL_ERROR_VAL ("index i lies outside valid range of 0 .. nx - 1",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EDOM, 0);
=======
			GSL_EDOM, 0);
>>>>>>> config
    }

  if (j >= ny)
    {
      GSL_ERROR_VAL ("index j lies outside valid range of 0 .. ny - 1",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EDOM, 0);
=======
			GSL_EDOM, 0);
>>>>>>> config
    }

  return h->bin[i * ny + j];
}

int
gsl_histogram2d_get_xrange (const gsl_histogram2d * h, const size_t i,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                            double *xlower, double *xupper)
=======
			    double *xlower, double *xupper)
>>>>>>> config
{
  const size_t nx = h->nx;

  if (i >= nx)
    {
      GSL_ERROR ("index i lies outside valid range of 0 .. nx - 1", GSL_EDOM);
    }

  *xlower = h->xrange[i];
  *xupper = h->xrange[i + 1];

  return GSL_SUCCESS;
}

int
gsl_histogram2d_get_yrange (const gsl_histogram2d * h, const size_t j,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                            double *ylower, double *yupper)
=======
			    double *ylower, double *yupper)
>>>>>>> config
{
  const size_t ny = h->ny;

  if (j >= ny)
    {
      GSL_ERROR ("index j lies outside valid range of 0 .. ny - 1", GSL_EDOM);
    }

  *ylower = h->yrange[j];
  *yupper = h->yrange[j + 1];

  return GSL_SUCCESS;
}

int
gsl_histogram2d_find (const gsl_histogram2d * h,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                      const double x, const double y,
                      size_t * i, size_t * j)
=======
		      const double x, const double y,
		      size_t * i, size_t * j)
>>>>>>> config
{
  int status = find (h->nx, h->xrange, x, i);

  if (status)
    {
      GSL_ERROR ("x not found in range of h", GSL_EDOM);
    }

  status = find (h->ny, h->yrange, y, j);

  if (status)
    {
      GSL_ERROR ("y not found in range of h", GSL_EDOM);
    }

  return GSL_SUCCESS;
}
