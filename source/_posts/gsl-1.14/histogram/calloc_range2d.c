/* gsl_histogram2d_calloc_range.c
 * Copyright (C) 2000  Simone Piccardi
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
/***************************************************************
 *
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * File gsl_histogram2d_calloc_range.c: 
 * Routine to create a variable binning 2D histogram providing 
 * the input range vectors. Need GSL library and header.
 * Do range check and allocate the histogram data. 
=======
 * File gsl_histogram2d_calloc_range.c:
 * Routine to create a variable binning 2D histogram providing
 * the input range vectors. Need GSL library and header.
 * Do range check and allocate the histogram data.
>>>>>>> config
 *
 * Author: S. Piccardi
 * Jan. 2000
 *
 ***************************************************************/
#include <config.h>
#include <stdlib.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_histogram2d.h>
/*
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * Routine that create a 2D histogram using the given 
=======
 * Routine that create a 2D histogram using the given
>>>>>>> config
 * values for X and Y ranges
 */
gsl_histogram2d *
gsl_histogram2d_calloc_range (size_t nx, size_t ny,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                              double *xrange,
                              double *yrange)
=======
			      double *xrange,
			      double *yrange)
>>>>>>> config
{
  size_t i, j;
  gsl_histogram2d *h;

  /* check arguments */

  if (nx == 0)
    {
      GSL_ERROR_VAL ("histogram length nx must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EDOM, 0);
=======
			GSL_EDOM, 0);
>>>>>>> config
    }

  if (ny == 0)
    {
      GSL_ERROR_VAL ("histogram length ny must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EDOM, 0);
=======
			GSL_EDOM, 0);
>>>>>>> config
    }

  /* init ranges */

  for (i = 0; i < nx; i++)
    {
      if (xrange[i] >= xrange[i + 1])
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          GSL_ERROR_VAL ("histogram xrange not in increasing order",
                            GSL_EDOM, 0);
        }
=======
	{
	  GSL_ERROR_VAL ("histogram xrange not in increasing order",
			    GSL_EDOM, 0);
	}
>>>>>>> config
    }

  for (j = 0; j < ny; j++)
    {
      if (yrange[j] >= yrange[j + 1])
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          GSL_ERROR_VAL ("histogram yrange not in increasing order"
                            ,GSL_EDOM, 0);
        }
=======
	{
	  GSL_ERROR_VAL ("histogram yrange not in increasing order"
			    ,GSL_EDOM, 0);
	}
>>>>>>> config
    }

  /* Allocate histogram  */

  h = (gsl_histogram2d *) malloc (sizeof (gsl_histogram2d));

  if (h == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for histogram struct",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  h->xrange = (double *) malloc ((nx + 1) * sizeof (double));

  if (h->xrange == 0)
    {
      /* exception in constructor, avoid memory leak */
      free (h);

      GSL_ERROR_VAL ("failed to allocate space for histogram xrange",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  h->yrange = (double *) malloc ((ny + 1) * sizeof (double));

  if (h->yrange == 0)
    {
      /* exception in constructor, avoid memory leak */
      free (h);

      GSL_ERROR_VAL ("failed to allocate space for histogram yrange",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  h->bin = (double *) malloc (nx * ny * sizeof (double));

  if (h->bin == 0)
    {
      /* exception in constructor, avoid memory leak */
      free (h->xrange);
      free (h->yrange);
      free (h);

      GSL_ERROR_VAL ("failed to allocate space for histogram bins",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  /* init histogram */

  /* init ranges */

  for (i = 0; i <= nx; i++)
    {
      h->xrange[i] = xrange[i];
    }

  for (j = 0; j <= ny; j++)
    {
      h->yrange[j] = yrange[j];
    }

  /* clear contents */

  for (i = 0; i < nx; i++)
    {
      for (j = 0; j < ny; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          h->bin[i * ny + j] = 0;
        }
=======
	{
	  h->bin[i * ny + j] = 0;
	}
>>>>>>> config
    }

  h->nx = nx;
  h->ny = ny;

  return h;
}
