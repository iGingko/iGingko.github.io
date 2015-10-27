/* statistics/wmean_source.c
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

double
FUNCTION (gsl_stats, wmean) (const BASE w[], const size_t wstride, const BASE data[], const size_t stride, const size_t size)
{
  /* Compute the weighted arithmetic mean M of a dataset using the
     recurrence relation

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
     M(n) = M(n-1) + (data[n] - M(n-1)) (w(n)/(W(n-1) + w(n))) 
=======
     M(n) = M(n-1) + (data[n] - M(n-1)) (w(n)/(W(n-1) + w(n)))
>>>>>>> config
     W(n) = W(n-1) + w(n)

   */

  long double wmean = 0;
  long double W = 0;

  size_t i;

  for (i = 0; i < size; i++)
    {
      BASE wi = w[i * wstride];

      if (wi > 0)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          W += wi;
          wmean += (data[i * stride] - wmean) * (wi / W);
        }
=======
	{
	  W += wi;
	  wmean += (data[i * stride] - wmean) * (wi / W);
	}
>>>>>>> config
    }

  return wmean;
}
