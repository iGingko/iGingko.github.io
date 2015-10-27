/* permutation/permutation.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2001, 2002 Nicolas Darnis
 * 
=======
 *
 * Copyright (C) 2001, 2002 Nicolas Darnis
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

/* Modified for GSL by Brian Gough.
 * Use in-place algorithms, no need for workspace
 * Use conventions for canonical form given in Knuth (opposite of Sedgewick)
 */

#include <config.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_permutation.h>

int
gsl_permutation_linear_to_canonical (gsl_permutation * q,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                     const gsl_permutation * p)
=======
				     const gsl_permutation * p)
>>>>>>> config
{
  const size_t n = p->size;
  size_t i, k, s;
  size_t t = n;

  const size_t *const pp = p->data;
  size_t *const qq = q->data;

  if (q->size != p->size)
    {
      GSL_ERROR ("size of q does not match size of p", GSL_EINVAL);
    }

  for (i = 0; i < n; i++)
    {

      k = pp[i];
      s = 1;

      while (k > i)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          k = pp[k];
          s++;
        }

      if (k < i)
        continue;
=======
	{
	  k = pp[k];
	  s++;
	}

      if (k < i)
	continue;
>>>>>>> config

      /* Now have k == i, i.e the least in its cycle, and s == cycle length */

      t -= s;

      qq[t] = i;

      k = pp[i];
      s = 1;

      while (k > i)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          qq[t + s] = k;
          k = pp[k];
          s++;
        }

      if (t == 0)
        break;
=======
	{
	  qq[t + s] = k;
	  k = pp[k];
	  s++;
	}

      if (t == 0)
	break;
>>>>>>> config
    }

  return GSL_SUCCESS;
}

int
gsl_permutation_canonical_to_linear (gsl_permutation * p,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                     const gsl_permutation * q)
=======
				     const gsl_permutation * q)
>>>>>>> config
{
  size_t i, k, kk, first;
  const size_t n = p->size;

  size_t *const pp = p->data;
  const size_t *const qq = q->data;

  if (q->size != p->size)
    {
      GSL_ERROR ("size of q does not match size of p", GSL_EINVAL);
    }

  for (i = 0; i < n; i++)
    {
      pp[i] = i;
    }

  k = qq[0];
  first = pp[k];

  for (i = 1; i < n; i++)
    {
      kk = qq[i];

      if (kk > first)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          pp[k] = pp[kk];
          k = kk;
        }
      else
        {
          pp[k] = first;
          k = kk;
          first = pp[kk];
        }
=======
	{
	  pp[k] = pp[kk];
	  k = kk;
	}
      else
	{
	  pp[k] = first;
	  k = kk;
	  first = pp[kk];
	}
>>>>>>> config
    }

  pp[k] = first;

  return GSL_SUCCESS;
}


size_t
gsl_permutation_inversions (const gsl_permutation * p)
{
  size_t count = 0;
  size_t i, j;
  const size_t size = p->size;

  for (i = 0; i < size - 1; i++)
    {
      for (j = i + 1; j < size; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          if (p->data[i] > p->data[j])
            {
              count++;
            }
        }
=======
	{
	  if (p->data[i] > p->data[j])
	    {
	      count++;
	    }
	}
>>>>>>> config
    }

  return count;
}

size_t
gsl_permutation_linear_cycles (const gsl_permutation * p)
{
  size_t i, k;
  size_t count = 0;
  const size_t size = p->size;

  for (i = 0; i < size; i++)
    {

      k = p->data[i];

      while (k > i)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          k = p->data[k];
        }

      if (k < i)
        continue;
=======
	{
	  k = p->data[k];
	}

      if (k < i)
	continue;
>>>>>>> config

      count++;
    }

  return count;
}

size_t
gsl_permutation_canonical_cycles (const gsl_permutation * p)
{
  size_t i;
  size_t count = 1;
  size_t min = p->data[0];

  for (i = 0; i < p->size; i++)
    {
      if (p->data[i] < min)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          min = p->data[i];
          count++;
        }
=======
	{
	  min = p->data[i];
	  count++;
	}
>>>>>>> config
    }

  return count;
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
