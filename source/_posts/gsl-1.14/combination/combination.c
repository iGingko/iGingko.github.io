/* combination/combination.c
 * based on permutation/permutation.c by Brian Gough
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2001 Szymon Jaroszewicz
 * 
=======
 *
 * Copyright (C) 2001 Szymon Jaroszewicz
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
#include <gsl/gsl_combination.h>

size_t
gsl_combination_n (const gsl_combination * c)
{
  return c->n ;
}

size_t
gsl_combination_k (const gsl_combination * c)
{
  return c->k ;
}

size_t *
gsl_combination_data (const gsl_combination * c)
{
  return c->data ;
}

int
gsl_combination_valid (gsl_combination * c)
{
  const size_t n = c->n ;
  const size_t k = c->k ;

  size_t i, j ;

  if( k > n )
    {
      GSL_ERROR("combination has k greater than n", GSL_FAILURE) ;
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  for (i = 0; i < k; i++) 
=======
  for (i = 0; i < k; i++)
>>>>>>> config
    {
      const size_t ci = c->data[i];

      if (ci >= n)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          GSL_ERROR("combination index outside range", GSL_FAILURE) ;
        }

      for (j = 0; j < i; j++)
        {
          if (c->data[j] == ci)
            {
              GSL_ERROR("duplicate combination index", GSL_FAILURE) ;
            }
          if (c->data[j] > ci)
            {
              GSL_ERROR("combination indices not in increasing order",
                        GSL_FAILURE) ;
            }
        }
    }
  
=======
	{
	  GSL_ERROR("combination index outside range", GSL_FAILURE) ;
	}

      for (j = 0; j < i; j++)
	{
	  if (c->data[j] == ci)
	    {
	      GSL_ERROR("duplicate combination index", GSL_FAILURE) ;
	    }
	  if (c->data[j] > ci)
	    {
	      GSL_ERROR("combination indices not in increasing order",
			GSL_FAILURE) ;
	    }
	}
    }

>>>>>>> config
  return GSL_SUCCESS;
}


int
gsl_combination_next (gsl_combination * c)
{
  /* Replaces c with the next combination (in the standard lexicographical
   * ordering).  Returns GSL_FAILURE if there is no next combination.
   */
  const size_t n = c->n;
  const size_t k = c->k;
  size_t *data = c->data;
  size_t i;

  if(k == 0)
    {
      return GSL_FAILURE;
    }
  i = k - 1;

  while(i > 0 && data[i] == n - k + i)
    {
      i--;
    }
  if(i == 0 && data[i] == n - k)
    {
      return GSL_FAILURE;
    }
  data[i]++;
  for(; i < k - 1; i++)
    {
      data[i + 1] = data[i] + 1;
    }
  return GSL_SUCCESS;
}

int
gsl_combination_prev (gsl_combination * c)
{
  /* Replaces c with the previous combination (in the standard
   * lexicographical ordering).  Returns GSL_FAILURE if there is no
   * previous combination.
   */
  const size_t n = c->n;
  const size_t k = c->k;
  size_t *data = c->data;
  size_t i;

  if(k == 0)
    {
      return GSL_FAILURE;
    }
  i = k - 1;

  while(i > 0 && data[i] == data[i-1] + 1)
    {
      i--;
    }
  if(i == 0 && data[i] == 0)
    {
      return GSL_FAILURE;
    }
  data[i++]--;
  for(; i < k; i++)
    {
      data[i] = n - k + i;
    }
  return GSL_SUCCESS;
}

int
gsl_combination_memcpy (gsl_combination * dest, const gsl_combination * src)
{
   const size_t src_n = src->n;
   const size_t src_k = src->k;
   const size_t dest_n = dest->n;
   const size_t dest_k = dest->k;

   if (src_n != dest_n || src_k != dest_k)
     {
       GSL_ERROR ("combination lengths are not equal", GSL_EBADLEN);
     }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
   
   {
     size_t j;
     
     for (j = 0; j < src_k; j++)
       {
         dest->data[j] = src->data[j];
       }
   }
   
=======

   {
     size_t j;

     for (j = 0; j < src_k; j++)
       {
	 dest->data[j] = src->data[j];
       }
   }

>>>>>>> config
   return GSL_SUCCESS;
}
