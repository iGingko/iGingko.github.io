/* vector/copy_source.c
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
FUNCTION (gsl_vector, memcpy) (TYPE (gsl_vector) * dest,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                               const TYPE (gsl_vector) * src)
=======
			       const TYPE (gsl_vector) * src)
>>>>>>> config
{
  const size_t src_size = src->size;
  const size_t dest_size = dest->size;

  if (src_size != dest_size)
    {
      GSL_ERROR ("vector lengths are not equal", GSL_EBADLEN);
    }

  {
    const size_t src_stride = src->stride ;
    const size_t dest_stride = dest->stride ;
    size_t j;

    for (j = 0; j < src_size; j++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        size_t k;

        for (k = 0; k < MULTIPLICITY; k++) 
          {
            dest->data[MULTIPLICITY * dest_stride * j + k] 
              = src->data[MULTIPLICITY * src_stride * j + k];
          }
=======
	size_t k;

	for (k = 0; k < MULTIPLICITY; k++)
	  {
	    dest->data[MULTIPLICITY * dest_stride * j + k]
	      = src->data[MULTIPLICITY * src_stride * j + k];
	  }
>>>>>>> config
      }
  }

  return GSL_SUCCESS;
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
