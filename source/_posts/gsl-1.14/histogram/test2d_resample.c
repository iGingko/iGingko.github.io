/* histogram/test2d_resample.c
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
#include <gsl/gsl_histogram2d.h>
#include <gsl/gsl_test.h>
#include <gsl/gsl_ieee_utils.h>

#include "urand.c"

void
test2d_resample (void)
{
  size_t i, j;
  int status = 0;
  double total = 0;
  size_t N = 200000;

  gsl_histogram2d *h;

  gsl_ieee_env_setup ();

  h = gsl_histogram2d_calloc_uniform (10, 10, 0.0, 1.0, 0.0, 1.0);

  for (i = 0; i < 10; i++)
    {
      for (j = 0; j < 10; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          double w = 10.0 * i + j;
          total += w;
          gsl_histogram2d_accumulate (h, 0.1 * i, 0.1 * i, w);
        }
=======
	{
	  double w = 10.0 * i + j;
	  total += w;
	  gsl_histogram2d_accumulate (h, 0.1 * i, 0.1 * i, w);
	}
>>>>>>> config
    }

  {
    gsl_histogram2d_pdf *p = gsl_histogram2d_pdf_alloc (10,10);

    gsl_histogram2d *hh = gsl_histogram2d_calloc_uniform (20, 20,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                                          0.0, 1.0,
                                                          0.0, 1.0);
=======
							  0.0, 1.0,
							  0.0, 1.0);
>>>>>>> config

    gsl_histogram2d_pdf_init (p, h);

    for (i = 0; i < N; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        double u = urand();
        double v = urand();
        double x, y;
        status = gsl_histogram2d_pdf_sample (p, u, v, &x, &y);
        status = gsl_histogram2d_increment (hh, x, y);
=======
	double u = urand();
	double v = urand();
	double x, y;
	status = gsl_histogram2d_pdf_sample (p, u, v, &x, &y);
	status = gsl_histogram2d_increment (hh, x, y);
>>>>>>> config
      }

    status = 0;
    for (i = 0; i < 20; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        for (j = 0; j < 20; j++)
          {
            double z = 4 * total * gsl_histogram2d_get (hh, i, j) / (double) N;
            size_t k1, k2;
            double ya;
            double x, xmax, y, ymax;

            gsl_histogram2d_get_xrange (hh, i, &x, &xmax);
            gsl_histogram2d_get_yrange (hh, j, &y, &ymax);

            gsl_histogram2d_find (h, x, y, &k1, &k2);
            ya = gsl_histogram2d_get (h, k1, k2);

            if (ya == 0)
              {
                if (z != 0)
                  {
                    status = 1;
                    printf ("(%d,%d): %g vs %g\n", (int)i, (int)j, z, ya);
                  }
              }
            else
              {
                double err = 1 / sqrt (gsl_histogram2d_get (hh, i, j));
                double sigma = fabs ((z - ya) / (ya * err));
                if (sigma > 3)
                  {
                    status = 1;
                    printf ("%g vs %g err=%g sigma=%g\n", z, ya, err, sigma);
                  }
              }
          }
=======
	for (j = 0; j < 20; j++)
	  {
	    double z = 4 * total * gsl_histogram2d_get (hh, i, j) / (double) N;
	    size_t k1, k2;
	    double ya;
	    double x, xmax, y, ymax;

	    gsl_histogram2d_get_xrange (hh, i, &x, &xmax);
	    gsl_histogram2d_get_yrange (hh, j, &y, &ymax);

	    gsl_histogram2d_find (h, x, y, &k1, &k2);
	    ya = gsl_histogram2d_get (h, k1, k2);

	    if (ya == 0)
	      {
		if (z != 0)
		  {
		    status = 1;
		    printf ("(%d,%d): %g vs %g\n", (int)i, (int)j, z, ya);
		  }
	      }
	    else
	      {
		double err = 1 / sqrt (gsl_histogram2d_get (hh, i, j));
		double sigma = fabs ((z - ya) / (ya * err));
		if (sigma > 3)
		  {
		    status = 1;
		    printf ("%g vs %g err=%g sigma=%g\n", z, ya, err, sigma);
		  }
	      }
	  }
>>>>>>> config
      }

    gsl_histogram2d_pdf_free (p) ;
    gsl_histogram2d_free (hh) ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    
=======

>>>>>>> config
    gsl_test (status, "gsl_histogram2d_pdf_sample within statistical errors");
  }

  gsl_histogram2d_free (h) ;
}
