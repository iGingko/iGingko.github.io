/* histogram/pdf.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007, 2009 Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007, 2009 Brian Gough
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
#include <gsl/gsl_errno.h>
#include <gsl/gsl_histogram.h>

#include "find.c"

double
gsl_histogram_pdf_sample (const gsl_histogram_pdf * p, double r)
{
  size_t i;
  int status;

/* Wrap the exclusive top of the bin down to the inclusive bottom of
   the bin. Since this is a single point it should not affect the
   distribution. */

  if (r == 1.0)
    {
      r = 0.0;
    }

  status = find (p->n, p->sum, r, &i);

  if (status)
    {
      GSL_ERROR_VAL ("cannot find r in cumulative pdf", GSL_EDOM, 0);
    }
  else
    {
      double delta = (r - p->sum[i]) / (p->sum[i + 1] - p->sum[i]);
      double x = p->range[i] + delta * (p->range[i + 1] - p->range[i]);
      return x;
    }
}

gsl_histogram_pdf *
gsl_histogram_pdf_alloc (const size_t n)
{
  gsl_histogram_pdf *p;

  if (n == 0)
    {
      GSL_ERROR_VAL ("histogram pdf length n must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EDOM, 0);
=======
			GSL_EDOM, 0);
>>>>>>> config
    }

  p = (gsl_histogram_pdf *) malloc (sizeof (gsl_histogram_pdf));

  if (p == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for histogram pdf struct",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  p->range = (double *) malloc ((n + 1) * sizeof (double));

  if (p->range == 0)
    {
      free (p);         /* exception in constructor, avoid memory leak */

      GSL_ERROR_VAL ("failed to allocate space for histogram pdf ranges",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  p->sum = (double *) malloc ((n + 1) * sizeof (double));

  if (p->sum == 0)
    {
      free (p->range);
      free (p);         /* exception in constructor, avoid memory leak */

      GSL_ERROR_VAL ("failed to allocate space for histogram pdf sums",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  p->n = n;

  return p;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
int 
=======
int
>>>>>>> config
gsl_histogram_pdf_init (gsl_histogram_pdf * p, const gsl_histogram * h)
{
  size_t i;
  size_t n = p->n;

  if (n != h->n)
    {
      GSL_ERROR ("histogram length must match pdf length", GSL_EINVAL);
    }

  for (i = 0; i < n; i++)
    {
      if (h->bin[i] < 0)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          GSL_ERROR ("histogram bins must be non-negative to compute"
                     "a probability distribution", GSL_EDOM);
        }
=======
	{
	  GSL_ERROR ("histogram bins must be non-negative to compute"
		     "a probability distribution", GSL_EDOM);
	}
>>>>>>> config
    }

  for (i = 0; i < n + 1; i++)
    {
      p->range[i] = h->range[i];
    }

  {
    double mean = 0, sum = 0;

    for (i = 0; i < n; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        mean += (h->bin[i] - mean) / ((double) (i + 1));
=======
	mean += (h->bin[i] - mean) / ((double) (i + 1));
>>>>>>> config
      }

    p->sum[0] = 0;

    for (i = 0; i < n; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        sum += (h->bin[i] / mean) / n;
        p->sum[i + 1] = sum;
=======
	sum += (h->bin[i] / mean) / n;
	p->sum[i + 1] = sum;
>>>>>>> config
      }
  }

  return GSL_SUCCESS;
}


void
gsl_histogram_pdf_free (gsl_histogram_pdf * p)
{
  RETURN_IF_NULL (p);
  free (p->range);
  free (p->sum);
  free (p);
}
