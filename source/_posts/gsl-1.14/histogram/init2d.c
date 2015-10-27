/* histogram/init2d.c
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
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_histogram2d.h>

gsl_histogram2d *
gsl_histogram2d_alloc (const size_t nx, const size_t ny)
{
  gsl_histogram2d *h;

  if (nx == 0)
    {
      GSL_ERROR_VAL ("histogram2d length nx must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EDOM, 0);
=======
			GSL_EDOM, 0);
>>>>>>> config
    }

  if (ny == 0)
    {
      GSL_ERROR_VAL ("histogram2d length ny must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EDOM, 0);
=======
			GSL_EDOM, 0);
>>>>>>> config
    }

  h = (gsl_histogram2d *) malloc (sizeof (gsl_histogram2d));

  if (h == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for histogram2d struct",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  h->xrange = (double *) malloc ((nx + 1) * sizeof (double));

  if (h->xrange == 0)
    {
      free (h);         /* exception in constructor, avoid memory leak */

      GSL_ERROR_VAL ("failed to allocate space for histogram2d x ranges",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  h->yrange = (double *) malloc ((ny + 1) * sizeof (double));

  if (h->yrange == 0)
    {
      free (h->xrange);
      free (h);         /* exception in constructor, avoid memory leak */

      GSL_ERROR_VAL ("failed to allocate space for histogram2d y ranges",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  h->bin = (double *) malloc (nx * ny * sizeof (double));

  if (h->bin == 0)
    {
      free (h->xrange);
      free (h->yrange);
      free (h);         /* exception in constructor, avoid memory leak */

      GSL_ERROR_VAL ("failed to allocate space for histogram bins",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  h->nx = nx;
  h->ny = ny;

  return h;
}

static void
make_uniform (double range[], size_t n, double xmin, double xmax)
{
  size_t i;

  for (i = 0; i <= n; i++)
    {
      double f1 = ((double) (n-i) / (double) n);
      double f2 = ((double) i / (double) n);
      range[i] = f1 * xmin +  f2 * xmax;
    }
}

gsl_histogram2d *
gsl_histogram2d_calloc_uniform (const size_t nx, const size_t ny,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                const double xmin, const double xmax,
                                const double ymin, const double ymax)
=======
				const double xmin, const double xmax,
				const double ymin, const double ymax)
>>>>>>> config
{
  gsl_histogram2d *h;

  if (xmin >= xmax)
    {
      GSL_ERROR_VAL ("xmin must be less than xmax", GSL_EINVAL, 0);
    }

  if (ymin >= ymax)
    {
      GSL_ERROR_VAL ("ymin must be less than ymax", GSL_EINVAL, 0);
    }

  h = gsl_histogram2d_calloc (nx, ny);

  if (h == 0)
    {
      return h;
    }

  make_uniform (h->xrange, nx, xmin, xmax);
  make_uniform (h->yrange, ny, ymin, ymax);

  return h;
}

gsl_histogram2d *
gsl_histogram2d_calloc (const size_t nx, const size_t ny)
{
  gsl_histogram2d *h;

  if (nx == 0)
    {
      GSL_ERROR_VAL ("histogram2d length nx must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EDOM, 0);
=======
			GSL_EDOM, 0);
>>>>>>> config
    }

  if (ny == 0)
    {
      GSL_ERROR_VAL ("histogram2d length ny must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EDOM, 0);
=======
			GSL_EDOM, 0);
>>>>>>> config
    }

  h = (gsl_histogram2d *) malloc (sizeof (gsl_histogram2d));

  if (h == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for histogram2d struct",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  h->xrange = (double *) malloc ((nx + 1) * sizeof (double));

  if (h->xrange == 0)
    {
      free (h);         /* exception in constructor, avoid memory leak */

      GSL_ERROR_VAL ("failed to allocate space for histogram2d x ranges",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  h->yrange = (double *) malloc ((ny + 1) * sizeof (double));

  if (h->yrange == 0)
    {
      free (h->xrange);
      free (h);         /* exception in constructor, avoid memory leak */

      GSL_ERROR_VAL ("failed to allocate space for histogram2d y ranges",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  h->bin = (double *) malloc (nx * ny * sizeof (double));

  if (h->bin == 0)
    {
      free (h->xrange);
      free (h->yrange);
      free (h);         /* exception in constructor, avoid memory leak */

      GSL_ERROR_VAL ("failed to allocate space for histogram bins",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  {
    size_t i;

    for (i = 0; i < nx + 1; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        h->xrange[i] = i;
=======
	h->xrange[i] = i;
>>>>>>> config
      }

    for (i = 0; i < ny + 1; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        h->yrange[i] = i;
=======
	h->yrange[i] = i;
>>>>>>> config
      }

    for (i = 0; i < nx * ny; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        h->bin[i] = 0;
=======
	h->bin[i] = 0;
>>>>>>> config
      }
  }

  h->nx = nx;
  h->ny = ny;

  return h;
}


void
gsl_histogram2d_free (gsl_histogram2d * h)
{
  RETURN_IF_NULL (h);
  free (h->xrange);
  free (h->yrange);
  free (h->bin);
  free (h);
}


<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
int 
gsl_histogram2d_set_ranges_uniform (gsl_histogram2d * h, 
                                    double xmin, double xmax,
                                    double ymin, double ymax)
=======
int
gsl_histogram2d_set_ranges_uniform (gsl_histogram2d * h,
				    double xmin, double xmax,
				    double ymin, double ymax)
>>>>>>> config
{
  size_t i;
  const size_t nx = h->nx, ny = h->ny;

  if (xmin >= xmax)
    {
      GSL_ERROR_VAL ("xmin must be less than xmax", GSL_EINVAL, 0);
    }

  if (ymin >= ymax)
    {
      GSL_ERROR_VAL ("ymin must be less than ymax", GSL_EINVAL, 0);
    }

  /* initialize ranges */

  make_uniform (h->xrange, nx, xmin, xmax);
  make_uniform (h->yrange, ny, ymin, ymax);

  /* clear contents */

  for (i = 0; i < nx * ny; i++)
    {
      h->bin[i] = 0;
    }

  return GSL_SUCCESS;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
int 
gsl_histogram2d_set_ranges (gsl_histogram2d * h, 
                            const double xrange[], size_t xsize,
                            const double yrange[], size_t ysize)
=======
int
gsl_histogram2d_set_ranges (gsl_histogram2d * h,
			    const double xrange[], size_t xsize,
			    const double yrange[], size_t ysize)
>>>>>>> config
{
  size_t i;
  const size_t nx = h->nx, ny = h->ny;

  if (xsize != (nx + 1))
    {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      GSL_ERROR_VAL ("size of xrange must match size of histogram", 
                     GSL_EINVAL, 0);
=======
      GSL_ERROR_VAL ("size of xrange must match size of histogram",
		     GSL_EINVAL, 0);
>>>>>>> config
    }

  if (ysize != (ny + 1))
    {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      GSL_ERROR_VAL ("size of yrange must match size of histogram", 
                     GSL_EINVAL, 0);
=======
      GSL_ERROR_VAL ("size of yrange must match size of histogram",
		     GSL_EINVAL, 0);
>>>>>>> config
    }

  /* initialize ranges */

  for (i = 0; i <= nx; i++)
    {
      h->xrange[i] = xrange[i];
    }

  for (i = 0; i <= ny; i++)
    {
      h->yrange[i] = yrange[i];
    }

  /* clear contents */

  for (i = 0; i < nx * ny; i++)
    {
      h->bin[i] = 0;
    }

  return GSL_SUCCESS;
}
