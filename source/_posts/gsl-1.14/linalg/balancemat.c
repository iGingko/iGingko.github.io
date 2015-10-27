/* linalg/balance.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2006 Patrick Alken
 * 
=======
 *
 * Copyright (C) 2006 Patrick Alken
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

/* Balance a general matrix by scaling the rows and columns, so the
 * new row and column norms are the same order of magnitude.
 *
 * B =  D^-1 A D
 *
 * where D is a diagonal matrix
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * This is necessary for the unsymmetric eigenvalue problem since the
 * calculation can become numerically unstable for unbalanced
 * matrices.  
=======
 *
 * This is necessary for the unsymmetric eigenvalue problem since the
 * calculation can become numerically unstable for unbalanced
 * matrices.
>>>>>>> config
 *
 * See Golub & Van Loan, "Matrix Computations" (3rd ed), Section 7.5.7
 * and Wilkinson & Reinsch, "Handbook for Automatic Computation", II/11 p320.
 */

#include <config.h>
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

#include <gsl/gsl_linalg.h>

#define FLOAT_RADIX       2.0
#define FLOAT_RADIX_SQ    (FLOAT_RADIX * FLOAT_RADIX)

int
gsl_linalg_balance_matrix(gsl_matrix * A, gsl_vector * D)
{
  const size_t N = A->size1;

  if (N != D->size)
    {
      GSL_ERROR ("vector must match matrix size", GSL_EBADLEN);
    }
  else
    {
      double row_norm,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             col_norm;
=======
	     col_norm;
>>>>>>> config
      int not_converged;
      gsl_vector_view v;

      /* initialize D to the identity matrix */
      gsl_vector_set_all(D, 1.0);

      not_converged = 1;

      while (not_converged)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          size_t i, j;
          double g, f, s;

          not_converged = 0;

          for (i = 0; i < N; ++i)
            {
              row_norm = 0.0;
              col_norm = 0.0;

              for (j = 0; j < N; ++j)
                {
                  if (j != i)
                    {
                      col_norm += fabs(gsl_matrix_get(A, j, i));
                      row_norm += fabs(gsl_matrix_get(A, i, j));
                    }
                }

              if ((col_norm == 0.0) || (row_norm == 0.0))
                {
                  continue;
                }

              g = row_norm / FLOAT_RADIX;
              f = 1.0;
              s = col_norm + row_norm;

              /*
               * find the integer power of the machine radix which
               * comes closest to balancing the matrix
               */
              while (col_norm < g)
                {
                  f *= FLOAT_RADIX;
                  col_norm *= FLOAT_RADIX_SQ;
                }

              g = row_norm * FLOAT_RADIX;

              while (col_norm > g)
                {
                  f /= FLOAT_RADIX;
                  col_norm /= FLOAT_RADIX_SQ;
                }

              if ((row_norm + col_norm) < 0.95 * s * f)
                {
                  not_converged = 1;

                  g = 1.0 / f;

                  /*
                   * apply similarity transformation D, where
                   * D_{ij} = f_i * delta_{ij}
                   */

                  /* multiply by D^{-1} on the left */
                  v = gsl_matrix_row(A, i);
                  gsl_blas_dscal(g, &v.vector);

                  /* multiply by D on the right */
                  v = gsl_matrix_column(A, i);
                  gsl_blas_dscal(f, &v.vector);

                  /* keep track of transformation */
                  gsl_vector_set(D, i, gsl_vector_get(D, i) * f);
                }
            }
        }
=======
	{
	  size_t i, j;
	  double g, f, s;

	  not_converged = 0;

	  for (i = 0; i < N; ++i)
	    {
	      row_norm = 0.0;
	      col_norm = 0.0;

	      for (j = 0; j < N; ++j)
		{
		  if (j != i)
		    {
		      col_norm += fabs(gsl_matrix_get(A, j, i));
		      row_norm += fabs(gsl_matrix_get(A, i, j));
		    }
		}

	      if ((col_norm == 0.0) || (row_norm == 0.0))
		{
		  continue;
		}

	      g = row_norm / FLOAT_RADIX;
	      f = 1.0;
	      s = col_norm + row_norm;

	      /*
	       * find the integer power of the machine radix which
	       * comes closest to balancing the matrix
	       */
	      while (col_norm < g)
		{
		  f *= FLOAT_RADIX;
		  col_norm *= FLOAT_RADIX_SQ;
		}

	      g = row_norm * FLOAT_RADIX;

	      while (col_norm > g)
		{
		  f /= FLOAT_RADIX;
		  col_norm /= FLOAT_RADIX_SQ;
		}

	      if ((row_norm + col_norm) < 0.95 * s * f)
		{
		  not_converged = 1;

		  g = 1.0 / f;

		  /*
		   * apply similarity transformation D, where
		   * D_{ij} = f_i * delta_{ij}
		   */

		  /* multiply by D^{-1} on the left */
		  v = gsl_matrix_row(A, i);
		  gsl_blas_dscal(g, &v.vector);

		  /* multiply by D on the right */
		  v = gsl_matrix_column(A, i);
		  gsl_blas_dscal(f, &v.vector);

		  /* keep track of transformation */
		  gsl_vector_set(D, i, gsl_vector_get(D, i) * f);
		}
	    }
	}
>>>>>>> config

      return GSL_SUCCESS;
    }
} /* gsl_linalg_balance_matrix() */

/*
gsl_linalg_balance_accum()
  Accumulate a balancing transformation into a matrix.
This is used during the computation of Schur vectors since the
Schur vectors computed are the vectors for the balanced matrix.
We must at some point accumulate the balancing transformation into
the Schur vector matrix to get the vectors for the original matrix.

A -> D A

where D is the diagonal matrix

Inputs: A - matrix to transform
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        D - vector containing diagonal elements of D
=======
	D - vector containing diagonal elements of D
>>>>>>> config
*/

int
gsl_linalg_balance_accum(gsl_matrix *A, gsl_vector *D)
{
  const size_t N = A->size1;

  if (N != D->size)
    {
      GSL_ERROR ("vector must match matrix size", GSL_EBADLEN);
    }
  else
    {
      size_t i;
      double s;
      gsl_vector_view r;

      for (i = 0; i < N; ++i)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          s = gsl_vector_get(D, i);
          r = gsl_matrix_row(A, i);

          gsl_blas_dscal(s, &r.vector);
        }
=======
	{
	  s = gsl_vector_get(D, i);
	  r = gsl_matrix_row(A, i);

	  gsl_blas_dscal(s, &r.vector);
	}
>>>>>>> config

      return GSL_SUCCESS;
    }
} /* gsl_linalg_balance_accum() */
