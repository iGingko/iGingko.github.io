/* vector/swap_source.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Gerard Jungman, Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Gerard Jungman, Brian Gough
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

int
FUNCTION (gsl_vector, swap) (TYPE (gsl_vector) * v, TYPE (gsl_vector) * w)
{
  ATOMIC * d1 = v->data ;
  ATOMIC * d2 = w->data ;
  const size_t size = v->size ;
  const size_t s1 = MULTIPLICITY * v->stride ;
  const size_t s2 = MULTIPLICITY * w->stride ;
  size_t i, k ;

  if (v->size != w->size)
    {
      GSL_ERROR("vector lengths must be equal", GSL_EINVAL);
    }

  for (i = 0; i < size; i++)
    {
      for (k = 0; k < MULTIPLICITY; k++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          ATOMIC tmp = d1[i*s1 + k];
          d1[i*s1+k] = d2[i*s2 + k];
          d2[i*s2+k] = tmp;
        }
    }
  
=======
	{
	  ATOMIC tmp = d1[i*s1 + k];
	  d1[i*s1+k] = d2[i*s2 + k];
	  d2[i*s2+k] = tmp;
	}
    }

>>>>>>> config
  return GSL_SUCCESS;
}

int
FUNCTION (gsl_vector, swap_elements) (TYPE (gsl_vector) * v, const size_t i, const size_t j)
{
  ATOMIC * data = v->data ;
  const size_t size = v->size ;
  const size_t stride = v->stride ;

  if (i >= size)
    {
      GSL_ERROR("first index is out of range", GSL_EINVAL);
    }

  if (j >= size)
    {
      GSL_ERROR("second index is out of range", GSL_EINVAL);
    }

  if (i != j)
    {
      const size_t s = MULTIPLICITY * stride ;
      size_t k ;

      for (k = 0; k < MULTIPLICITY; k++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          ATOMIC tmp = data[j*s + k];
          data[j*s+k] = data[i*s + k];
          data[i*s+k] = tmp;
        }
    }
  
=======
	{
	  ATOMIC tmp = data[j*s + k];
	  data[j*s+k] = data[i*s + k];
	  data[i*s+k] = tmp;
	}
    }

>>>>>>> config
  return GSL_SUCCESS;
}

int
FUNCTION (gsl_vector, reverse) (TYPE (gsl_vector) * v)
{
  ATOMIC * data = v->data ;
  const size_t size = v->size ;
  const size_t stride = v->stride ;

  const size_t s = MULTIPLICITY * stride ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  size_t i ;

  for (i = 0 ; i < (size / 2) ; i++)
    {
      size_t j = size - i - 1 ;
      size_t k;

      for (k = 0; k < MULTIPLICITY; k++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          ATOMIC tmp = data[j*s + k];
          data[j*s+k] = data[i*s + k];
          data[i*s+k] = tmp;
        }
    }
  
  return GSL_SUCCESS;
}

=======
	{
	  ATOMIC tmp = data[j*s + k];
	  data[j*s+k] = data[i*s + k];
	  data[i*s+k] = tmp;
	}
    }

  return GSL_SUCCESS;
}
>>>>>>> config
