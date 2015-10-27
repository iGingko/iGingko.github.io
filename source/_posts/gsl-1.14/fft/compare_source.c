/* fft/compare_source.c
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

#include "compare.h"

int
FUNCTION(compare_complex,results) (const char *name_a, const BASE a[],
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                   const char *name_b, const BASE b[],
                                   size_t stride, size_t n,
                                   const double allowed_ticks)
=======
				   const char *name_b, const BASE b[],
				   size_t stride, size_t n,
				   const double allowed_ticks)
>>>>>>> config
{
  size_t i;
  double ticks, max_ticks = 0;
  double dr, di;
  const char *flag;

  for (i = 0; i < n; i++)
    {
      dr = b[2*stride*i] - a[2*stride*i];
      di = b[2*stride*i+1] - a[2*stride*i+1];
      ticks = (fabs (dr) + fabs (di)) / BASE_EPSILON;
      if (ticks > max_ticks)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          max_ticks = ticks;
        }
=======
	{
	  max_ticks = ticks;
	}
>>>>>>> config
    }

  if (max_ticks < allowed_ticks)
    {
      return 0;
    }

  printf ("\n%s vs %s : max_ticks = %f\n", name_a, name_b, max_ticks);

  for (i = 0; i < n; i++)
    {
      dr = b[2*stride*i] - a[2*stride*i];
      di = b[2*stride*i+1] - a[2*stride*i+1];
      ticks = (fabs (dr) + fabs (di)) / BASE_EPSILON;

      if (ticks > 1000)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          flag = "***";
        }
      else
        {
          flag = "";
        }

      printf ("%15s: %d  %.16f %.16f %s\n", name_a, (int)i,
              a[2*stride*i], a[2*stride*i+1], flag);
      printf ("%15s: %d  %.16f %.16f %e %s\n", name_b, (int)i,
              b[2*stride*i], b[2*stride*i+1], ticks, flag);
=======
	{
	  flag = "***";
	}
      else
	{
	  flag = "";
	}

      printf ("%15s: %d  %.16f %.16f %s\n", name_a, (int)i,
	      a[2*stride*i], a[2*stride*i+1], flag);
      printf ("%15s: %d  %.16f %.16f %e %s\n", name_b, (int)i,
	      b[2*stride*i], b[2*stride*i+1], ticks, flag);
>>>>>>> config
    }

  return -1;
}


int
FUNCTION(compare_real,results) (const char *name_a, const BASE a[],
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                const char *name_b, const BASE b[],
                                size_t stride, size_t n,
                                const double allowed_ticks)
=======
				const char *name_b, const BASE b[],
				size_t stride, size_t n,
				const double allowed_ticks)
>>>>>>> config
{
  size_t i;
  double ticks, max_ticks = 0;
  double dr;
  const char *flag;

  for (i = 0; i < n; i++)
    {
      dr = b[stride*i] - a[stride*i];
      ticks = fabs (dr) / BASE_EPSILON;
      if (ticks > max_ticks)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          max_ticks = ticks;
        }
=======
	{
	  max_ticks = ticks;
	}
>>>>>>> config
    }

  if (max_ticks < allowed_ticks)
    {
      return 0;
    }

  printf ("\n%s vs %s : max_ticks = %f\n", name_a, name_b, max_ticks);

  for (i = 0; i < n; i++)
    {
      dr = b[stride*i] - a[stride*i];
      ticks = fabs (dr) / BASE_EPSILON;

      if (ticks > 1000)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          flag = "***";
        }
      else
        {
          flag = "";
        }

      printf ("%15s: %d  %.16f %s\n", name_a, (int)i, 
              a[stride*i], flag);
      printf ("%15s: %d  %.16f %e %s\n", name_b, (int)i, 
              b[stride*i], ticks, flag);
=======
	{
	  flag = "***";
	}
      else
	{
	  flag = "";
	}

      printf ("%15s: %d  %.16f %s\n", name_a, (int)i,
	      a[stride*i], flag);
      printf ("%15s: %d  %.16f %e %s\n", name_b, (int)i,
	      b[stride*i], ticks, flag);
>>>>>>> config
    }

  return -1;
}
