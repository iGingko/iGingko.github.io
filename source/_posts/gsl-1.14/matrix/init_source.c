/* matrix/init_source.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007, 2009 Gerard Jungman, Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007, 2009 Gerard Jungman, Brian Gough
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

TYPE (gsl_matrix) *
FUNCTION (gsl_matrix, alloc) (const size_t n1, const size_t n2)
{
  TYPE (gsl_block) * block;
  TYPE (gsl_matrix) * m;

  if (n1 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n1 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EINVAL, 0);
=======
			GSL_EINVAL, 0);
>>>>>>> config
    }
  else if (n2 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n2 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EINVAL, 0);
=======
			GSL_EINVAL, 0);
>>>>>>> config
    }

  m = (TYPE (gsl_matrix) *) malloc (sizeof (TYPE (gsl_matrix)));

  if (m == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for matrix struct",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  /* FIXME: n1*n2 could overflow for large dimensions */

  block = FUNCTION(gsl_block, alloc) (n1 * n2) ;

  if (block == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for block",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  m->data = block->data;
  m->size1 = n1;
  m->size2 = n2;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  m->tda = n2; 
=======
  m->tda = n2;
>>>>>>> config
  m->block = block;
  m->owner = 1;

  return m;
}

TYPE (gsl_matrix) *
FUNCTION (gsl_matrix, calloc) (const size_t n1, const size_t n2)
{
  size_t i;

  TYPE (gsl_matrix) * m = FUNCTION (gsl_matrix, alloc) (n1, n2);

  if (m == 0)
    return 0;

  /* initialize matrix to zero */

  for (i = 0; i < MULTIPLICITY * n1 * n2; i++)
    {
      m->data[i] = 0;
    }

  return m;
}

TYPE (gsl_matrix) *
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
FUNCTION (gsl_matrix, alloc_from_block) (TYPE(gsl_block) * block, 
                                         const size_t offset,
                                         const size_t n1, 
                                         const size_t n2,
                                         const size_t d2)
=======
FUNCTION (gsl_matrix, alloc_from_block) (TYPE(gsl_block) * block,
					 const size_t offset,
					 const size_t n1,
					 const size_t n2,
					 const size_t d2)
>>>>>>> config
{
  TYPE (gsl_matrix) * m;

  if (n1 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n1 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EINVAL, 0);
=======
			GSL_EINVAL, 0);
>>>>>>> config
    }
  else if (n2 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n2 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EINVAL, 0);
=======
			GSL_EINVAL, 0);
>>>>>>> config
    }
  else if (d2 < n2)
    {
      GSL_ERROR_VAL ("matrix dimension d2 must be greater than n2",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EINVAL, 0);
=======
			GSL_EINVAL, 0);
>>>>>>> config
    }
  else if (block->size < offset + n1 * d2)
    {
      GSL_ERROR_VAL ("matrix size exceeds available block size",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EINVAL, 0);
=======
			GSL_EINVAL, 0);
>>>>>>> config
    }

  m = (TYPE (gsl_matrix) *) malloc (sizeof (TYPE (gsl_matrix)));

  if (m == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for matrix struct",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  m->data = block->data + MULTIPLICITY * offset;
  m->size1 = n1;
  m->size2 = n2;
  m->tda = d2;
  m->block = block;
  m->owner = 0;

  return m;
}


TYPE (gsl_matrix) *
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
FUNCTION (gsl_matrix, alloc_from_matrix) (TYPE(gsl_matrix) * mm, 
                                          const size_t k1,
                                          const size_t k2,
                                          const size_t n1, 
                                          const size_t n2)
=======
FUNCTION (gsl_matrix, alloc_from_matrix) (TYPE(gsl_matrix) * mm,
					  const size_t k1,
					  const size_t k2,
					  const size_t n1,
					  const size_t n2)
>>>>>>> config
{
  TYPE (gsl_matrix) * m;

  if (n1 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n1 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EINVAL, 0);
=======
			GSL_EINVAL, 0);
>>>>>>> config
    }
  else if (n2 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n2 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EINVAL, 0);
=======
			GSL_EINVAL, 0);
>>>>>>> config
    }
  else if (k1 + n1 > mm->size1)
    {
      GSL_ERROR_VAL ("submatrix dimension 1 exceeds size of original",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EINVAL, 0);
=======
			GSL_EINVAL, 0);
>>>>>>> config
    }
  else if (k2 + n2 > mm->size2)
    {
      GSL_ERROR_VAL ("submatrix dimension 2 exceeds size of original",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_EINVAL, 0);
=======
			GSL_EINVAL, 0);
>>>>>>> config
    }

  m = (TYPE (gsl_matrix) *) malloc (sizeof (TYPE (gsl_matrix)));

  if (m == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for matrix struct",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        GSL_ENOMEM, 0);
=======
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  m->data = mm->data + k1 * mm->tda + k2 ;
  m->size1 = n1;
  m->size2 = n2;
  m->tda = mm->tda;
  m->block = mm->block;
  m->owner = 0;

  return m;
}

void
FUNCTION (gsl_matrix, free) (TYPE (gsl_matrix) * m)
{
  RETURN_IF_NULL (m);

  if (m->owner)
    {
      FUNCTION(gsl_block, free) (m->block);
    }

  free (m);
}
void
FUNCTION (gsl_matrix, set_identity) (TYPE (gsl_matrix) * m)
{
  size_t i, j;
  ATOMIC * const data = m->data;
  const size_t p = m->size1 ;
  const size_t q = m->size2 ;
  const size_t tda = m->tda ;

  const BASE zero = ZERO;
  const BASE one = ONE;

  for (i = 0; i < p; i++)
    {
      for (j = 0; j < q; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          *(BASE *) (data + MULTIPLICITY * (i * tda + j)) = ((i == j) ? one : zero);
        }
=======
	{
	  *(BASE *) (data + MULTIPLICITY * (i * tda + j)) = ((i == j) ? one : zero);
	}
>>>>>>> config
    }
}

void
FUNCTION (gsl_matrix, set_zero) (TYPE (gsl_matrix) * m)
{
  size_t i, j;
  ATOMIC * const data = m->data;
  const size_t p = m->size1 ;
  const size_t q = m->size2 ;
  const size_t tda = m->tda ;

  const BASE zero = ZERO;

  for (i = 0; i < p; i++)
    {
      for (j = 0; j < q; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          *(BASE *) (data + MULTIPLICITY * (i * tda + j)) = zero;
        }
=======
	{
	  *(BASE *) (data + MULTIPLICITY * (i * tda + j)) = zero;
	}
>>>>>>> config
    }
}

void
FUNCTION (gsl_matrix, set_all) (TYPE (gsl_matrix) * m, BASE x)
{
  size_t i, j;
  ATOMIC * const data = m->data;
  const size_t p = m->size1 ;
  const size_t q = m->size2 ;
  const size_t tda = m->tda ;

  for (i = 0; i < p; i++)
    {
      for (j = 0; j < q; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          *(BASE *) (data + MULTIPLICITY * (i * tda + j)) = x;
        }
    }
}

=======
	{
	  *(BASE *) (data + MULTIPLICITY * (i * tda + j)) = x;
	}
    }
}
>>>>>>> config
