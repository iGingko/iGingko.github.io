/* matrix/submatrix_source.c
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

QUALIFIED_VIEW(_gsl_matrix,view)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
FUNCTION (gsl_matrix, submatrix) (QUALIFIED_TYPE(gsl_matrix) * m, 
                                  const size_t i, const size_t j,
                                  const size_t n1, const size_t n2)
{
  QUALIFIED_VIEW(_gsl_matrix,view) view = NULL_MATRIX_VIEW; 
=======
FUNCTION (gsl_matrix, submatrix) (QUALIFIED_TYPE(gsl_matrix) * m,
				  const size_t i, const size_t j,
				  const size_t n1, const size_t n2)
{
  QUALIFIED_VIEW(_gsl_matrix,view) view = NULL_MATRIX_VIEW;
>>>>>>> config

  if (i >= m->size1)
    {
      GSL_ERROR_VAL ("row index is out of range", GSL_EINVAL, view);
    }
  else if (j >= m->size2)
    {
      GSL_ERROR_VAL ("column index is out of range", GSL_EINVAL, view);
    }
  else if (n1 == 0)
    {
      GSL_ERROR_VAL ("first dimension must be non-zero", GSL_EINVAL, view);
    }
  else if (n2 == 0)
    {
      GSL_ERROR_VAL ("second dimension must be non-zero", GSL_EINVAL, view);
    }
  else if (i + n1 > m->size1)
    {
      GSL_ERROR_VAL ("first dimension overflows matrix", GSL_EINVAL, view);
    }
  else if (j + n2 > m->size2)
    {
      GSL_ERROR_VAL ("second dimension overflows matrix", GSL_EINVAL, view);
    }

  {
     TYPE(gsl_matrix) s = NULL_MATRIX;

     s.data = m->data + MULTIPLICITY * (i * m->tda + j);
     s.size1 = n1;
     s.size2 = n2;
     s.tda = m->tda;
     s.block = m->block;
     s.owner = 0;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
     
     view.matrix = s;     
     return view;
  }
}

=======

     view.matrix = s;
     return view;
  }
}
>>>>>>> config
