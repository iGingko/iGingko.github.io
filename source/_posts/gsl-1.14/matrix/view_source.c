/* matrix/view_source.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2007 Gerard Jungman, Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2007 Gerard Jungman, Brian Gough
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

QUALIFIED_VIEW (_gsl_matrix,view)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
FUNCTION (gsl_matrix, view_array) (QUALIFIER ATOMIC * array, 
                                   const size_t n1, const size_t n2)
=======
FUNCTION (gsl_matrix, view_array) (QUALIFIER ATOMIC * array,
				   const size_t n1, const size_t n2)
>>>>>>> config
{
  QUALIFIED_VIEW (_gsl_matrix,view) view = NULL_MATRIX_VIEW;

  if (n1 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n1 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_EINVAL, view);
=======
		     GSL_EINVAL, view);
>>>>>>> config
    }
  else if (n2 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n2 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_EINVAL, view);
=======
		     GSL_EINVAL, view);
>>>>>>> config
    }

  {
    TYPE(gsl_matrix) m = NULL_MATRIX;

    m.data = (ATOMIC *)array;
    m.size1 = n1;
    m.size2 = n2;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    m.tda = n2; 
    m.block = 0;
    m.owner = 0;

    view.matrix = m;    
=======
    m.tda = n2;
    m.block = 0;
    m.owner = 0;

    view.matrix = m;
>>>>>>> config
    return view;
  }
}

QUALIFIED_VIEW (_gsl_matrix,view)
FUNCTION(gsl_matrix, view_array_with_tda) (QUALIFIER ATOMIC * base,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                           const size_t n1, 
                                           const size_t n2,
                                           const size_t tda)
=======
					   const size_t n1,
					   const size_t n2,
					   const size_t tda)
>>>>>>> config
{
  QUALIFIED_VIEW (_gsl_matrix,view) view = NULL_MATRIX_VIEW;

  if (n1 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n1 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_EINVAL, view);
=======
		     GSL_EINVAL, view);
>>>>>>> config
    }
  else if (n2 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n2 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_EINVAL, view);
=======
		     GSL_EINVAL, view);
>>>>>>> config
    }
  else if (n2 > tda)
    {
      GSL_ERROR_VAL ("matrix dimension n2 must not exceed tda",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_EINVAL, view);
=======
		     GSL_EINVAL, view);
>>>>>>> config
    }


  {
    TYPE(gsl_matrix) m = NULL_MATRIX;

    m.data = (ATOMIC *)base;
    m.size1 = n1;
    m.size2 = n2;
    m.tda = tda;
    m.block = 0;
    m.owner = 0;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    view.matrix = m;    
=======
    view.matrix = m;
>>>>>>> config
    return view;
  }
}

QUALIFIED_VIEW (_gsl_matrix,view)
FUNCTION(gsl_matrix, view_vector) (QUALIFIED_TYPE(gsl_vector) * v,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                   const size_t n1, 
                                   const size_t n2)
=======
				   const size_t n1,
				   const size_t n2)
>>>>>>> config
{
  QUALIFIED_VIEW (_gsl_matrix,view) view = NULL_MATRIX_VIEW;

  if (n1 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n1 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_EINVAL, view);
=======
		     GSL_EINVAL, view);
>>>>>>> config
    }
  else if (n2 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n2 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_EINVAL, view);
    }
  else if (v->stride != 1) 
    {
      GSL_ERROR_VAL ("vector must have unit stride",
                     GSL_EINVAL, view);
    }
  else if (n1 * n2 > v->size)
    {
      GSL_ERROR_VAL ("matrix size exceeds size of original", 
                     GSL_EINVAL, view);
=======
		     GSL_EINVAL, view);
    }
  else if (v->stride != 1)
    {
      GSL_ERROR_VAL ("vector must have unit stride",
		     GSL_EINVAL, view);
    }
  else if (n1 * n2 > v->size)
    {
      GSL_ERROR_VAL ("matrix size exceeds size of original",
		     GSL_EINVAL, view);
>>>>>>> config
    }

  {
    TYPE(gsl_matrix) m = NULL_MATRIX;

    m.data = v->data;
    m.size1 = n1;
    m.size2 = n2;
    m.tda = n2;
    m.block = v->block;
    m.owner = 0;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    view.matrix = m;    
=======
    view.matrix = m;
>>>>>>> config
    return view;
  }
}


QUALIFIED_VIEW (_gsl_matrix,view)
FUNCTION(gsl_matrix, view_vector_with_tda) (QUALIFIED_TYPE(gsl_vector) * v,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                            const size_t n1, 
                                            const size_t n2,
                                            const size_t tda)
=======
					    const size_t n1,
					    const size_t n2,
					    const size_t tda)
>>>>>>> config
{
  QUALIFIED_VIEW (_gsl_matrix,view) view = NULL_MATRIX_VIEW;

  if (n1 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n1 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_EINVAL, view);
=======
		     GSL_EINVAL, view);
>>>>>>> config
    }
  else if (n2 == 0)
    {
      GSL_ERROR_VAL ("matrix dimension n2 must be positive integer",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_EINVAL, view);
    }
  else if (v->stride != 1) 
    {
      GSL_ERROR_VAL ("vector must have unit stride",
                     GSL_EINVAL, view);
=======
		     GSL_EINVAL, view);
    }
  else if (v->stride != 1)
    {
      GSL_ERROR_VAL ("vector must have unit stride",
		     GSL_EINVAL, view);
>>>>>>> config
    }
  else if (n2 > tda)
    {
      GSL_ERROR_VAL ("matrix dimension n2 must not exceed tda",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                     GSL_EINVAL, view);
    }
  else if (n1 * tda > v->size)
    {
      GSL_ERROR_VAL ("matrix size exceeds size of original", 
                     GSL_EINVAL, view);
=======
		     GSL_EINVAL, view);
    }
  else if (n1 * tda > v->size)
    {
      GSL_ERROR_VAL ("matrix size exceeds size of original",
		     GSL_EINVAL, view);
>>>>>>> config
    }

  {
    TYPE(gsl_matrix) m = NULL_MATRIX;

    m.data = v->data;
    m.size1 = n1;
    m.size2 = n2;
    m.tda = tda;
    m.block = v->block;
    m.owner = 0;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    view.matrix = m;    
=======
    view.matrix = m;
>>>>>>> config
    return view;
  }
}

#ifdef JUNK
int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
FUNCTION (gsl_matrix, view_from_matrix) (TYPE(gsl_matrix) * m, 
                                         TYPE(gsl_matrix) * mm, 
                                         const size_t k1,
                                         const size_t k2,
                                         const size_t n1, 
                                         const size_t n2)
=======
FUNCTION (gsl_matrix, view_from_matrix) (TYPE(gsl_matrix) * m,
					 TYPE(gsl_matrix) * mm,
					 const size_t k1,
					 const size_t k2,
					 const size_t n1,
					 const size_t n2)
>>>>>>> config
{
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

  m->data = mm->data + k1 * mm->tda + k2 ;
  m->size1 = n1;
  m->size2 = n2;
  m->tda = mm->tda;
  m->block = mm->block;
  m->owner = 0;

  return GSL_SUCCESS;
}

int
FUNCTION (gsl_vector, view_row_from_matrix) (TYPE(gsl_vector) * v,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                             TYPE(gsl_matrix) * m,
                                             const size_t i)
=======
					     TYPE(gsl_matrix) * m,
					     const size_t i)
>>>>>>> config
{
  const size_t column_length = m->size1;

  if (i >= column_length)
    {
      GSL_ERROR ("row index is out of range", GSL_EINVAL);
    }

  if (v->block != 0)
    {
      GSL_ERROR ("vector already has memory allocated to it", GSL_ENOMEM);
    }

  v->data = m->data + MULTIPLICITY * i * m->tda ;
  v->size = m->size2;
  v->stride = 1;

  return GSL_SUCCESS;
}

int
FUNCTION (gsl_vector, view_col_from_matrix) (TYPE(gsl_vector) * v,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                             TYPE(gsl_matrix) * m,
                                             const size_t j)
=======
					     TYPE(gsl_matrix) * m,
					     const size_t j)
>>>>>>> config
{
  const size_t row_length = m->size2;

  if (j >= row_length)
    {
      GSL_ERROR_VAL ("column index is out of range", GSL_EINVAL, 0);
    }

  if (v->block != 0)
    {
      GSL_ERROR ("vector already has memory allocated to it", GSL_ENOMEM);
    }

  v->data = m->data + MULTIPLICITY * j ;
  v->size = m->size1;
  v->stride = m->tda;

  return GSL_SUCCESS;
}
#endif /* JUNK */
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
