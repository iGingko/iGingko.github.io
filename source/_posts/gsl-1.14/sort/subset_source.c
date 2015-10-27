<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
/* sort/subset_source.c  
 * 
=======
/* sort/subset_source.c
 *
>>>>>>> config
 * Copyright (C) 1999,2000,2001  Thomas Walter, Brian Gough
 *
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3, or (at your option) any
 * later version.
 *
 * This source is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/* find the k-th smallest elements of the vector data, in ascending order */

int
FUNCTION (gsl_sort, smallest) (BASE * dest, const size_t k,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                               const BASE * src, const size_t stride,
                               const size_t n)
=======
			       const BASE * src, const size_t stride,
			       const size_t n)
>>>>>>> config
{
  size_t i, j;
  BASE xbound;

  if (k > n)
    {
      GSL_ERROR ("subset length k exceeds vector length n", GSL_EINVAL);
    }

  if (k == 0 || n == 0)
    {
      return GSL_SUCCESS;
    }

  /* take the first element */

  j = 1;
  xbound = src[0 * stride];
  dest[0] = xbound;

  /* examine the remaining elements */

  for (i = 1; i < n; i++)
    {
      size_t i1;

      BASE xi = src[i * stride];

      if (j < k)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          j++;
        }
      else if (xi >= xbound)
        {
          continue;
        }

      for (i1 = j - 1; i1 > 0 ; i1--)
        {
          if (xi > dest[i1 - 1])
            break;

          dest[i1] = dest[i1 - 1];
        }
=======
	{
	  j++;
	}
      else if (xi >= xbound)
	{
	  continue;
	}

      for (i1 = j - 1; i1 > 0 ; i1--)
	{
	  if (xi > dest[i1 - 1])
	    break;

	  dest[i1] = dest[i1 - 1];
	}
>>>>>>> config

      dest[i1] = xi;

      xbound = dest[j-1];
    }

  return GSL_SUCCESS;
}


int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
FUNCTION (gsl_sort_vector,smallest) (BASE * dest, const size_t k, 
                                     const TYPE (gsl_vector) * v)
=======
FUNCTION (gsl_sort_vector,smallest) (BASE * dest, const size_t k,
				     const TYPE (gsl_vector) * v)
>>>>>>> config
{
  return FUNCTION (gsl_sort, smallest) (dest, k, v->data, v->stride, v->size);
}

int
FUNCTION (gsl_sort, largest) (BASE * dest, const size_t k,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                              const BASE * src, const size_t stride,
                              const size_t n)
=======
			      const BASE * src, const size_t stride,
			      const size_t n)
>>>>>>> config
{
  size_t i, j;
  BASE xbound;

  if (k > n)
    {
      GSL_ERROR ("subset length k exceeds vector length n", GSL_EINVAL);
    }

  if (k == 0 || n == 0)
    {
      return GSL_SUCCESS;
    }

  /* take the first element */

  j = 1;
  xbound = src[0 * stride];
  dest[0] = xbound;

  /* examine the remaining elements */

  for (i = 1; i < n; i++)
    {
      size_t i1;

      BASE xi = src[i * stride];

      if (j < k)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          j++;
        }
      else if (xi <= xbound)
        {
          continue;
        }

      for (i1 = j - 1; i1 > 0 ; i1--)
        {
          if (xi < dest[i1 - 1])
            break;

          dest[i1] = dest[i1 - 1];
        }
=======
	{
	  j++;
	}
      else if (xi <= xbound)
	{
	  continue;
	}

      for (i1 = j - 1; i1 > 0 ; i1--)
	{
	  if (xi < dest[i1 - 1])
	    break;

	  dest[i1] = dest[i1 - 1];
	}
>>>>>>> config

      dest[i1] = xi;

      xbound = dest[j-1];
    }

  return GSL_SUCCESS;
}


int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
FUNCTION (gsl_sort_vector,largest) (BASE * dest, const size_t k, 
                                    const TYPE (gsl_vector) * v)
=======
FUNCTION (gsl_sort_vector,largest) (BASE * dest, const size_t k,
				    const TYPE (gsl_vector) * v)
>>>>>>> config
{
  return FUNCTION (gsl_sort, largest) (dest, k, v->data, v->stride, v->size);
}
