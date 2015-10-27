/* linalg/sytd.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2001, 2007 Brian Gough
 * 
=======
 *
 * Copyright (C) 2001, 2007 Brian Gough
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

/* Factorise a symmetric matrix A into
 *
 * A = Q T Q'
 *
 * where Q is orthogonal and T is symmetric tridiagonal.  Only the
 * diagonal and lower triangular part of A is referenced and modified.
 *
 * On exit, T is stored in the diagonal and first subdiagonal of
 * A. Since T is symmetric the upper diagonal is not stored.
 *
 * Q is stored as a packed set of Householder transformations in the
 * lower triangular part of the input matrix below the first subdiagonal.
 *
 * The full matrix for Q can be obtained as the product
 *
 *       Q = Q_1 Q_2 ... Q_(N-2)
 *
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * where 
=======
 * where
>>>>>>> config
 *
 *       Q_i = (I - tau_i * v_i * v_i')
 *
 * and where v_i is a Householder vector
 *
 *       v_i = [0, ... , 0, 1, A(i+1,i), A(i+2,i), ... , A(N,i)]
 *
 * This storage scheme is the same as in LAPACK.  See LAPACK's
 * ssytd2.f for details.
 *
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * See Golub & Van Loan, "Matrix Computations" (3rd ed), Section 8.3 
 *
 * Note: this description uses 1-based indices. The code below uses
 * 0-based indices 
=======
 * See Golub & Van Loan, "Matrix Computations" (3rd ed), Section 8.3
 *
 * Note: this description uses 1-based indices. The code below uses
 * 0-based indices
>>>>>>> config
 */

#include <config.h>
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

#include <gsl/gsl_linalg.h>

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
int 
gsl_linalg_symmtd_decomp (gsl_matrix * A, gsl_vector * tau)  
=======
int
gsl_linalg_symmtd_decomp (gsl_matrix * A, gsl_vector * tau)
>>>>>>> config
{
  if (A->size1 != A->size2)
    {
      GSL_ERROR ("symmetric tridiagonal decomposition requires square matrix",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 GSL_ENOTSQR);
=======
		 GSL_ENOTSQR);
>>>>>>> config
    }
  else if (tau->size + 1 != A->size1)
    {
      GSL_ERROR ("size of tau must be (matrix size - 1)", GSL_EBADLEN);
    }
  else
    {
      const size_t N = A->size1;
      size_t i;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
      for (i = 0 ; i < N - 2; i++)
        {
          gsl_vector_view c = gsl_matrix_column (A, i);
          gsl_vector_view v = gsl_vector_subvector (&c.vector, i + 1, N - (i + 1));
          double tau_i = gsl_linalg_householder_transform (&v.vector);
          
          /* Apply the transformation H^T A H to the remaining columns */

          if (tau_i != 0.0) 
            {
              gsl_matrix_view m = gsl_matrix_submatrix (A, i + 1, i + 1, 
                                                        N - (i+1), N - (i+1));
              double ei = gsl_vector_get(&v.vector, 0);
              gsl_vector_view x = gsl_vector_subvector (tau, i, N-(i+1));
              gsl_vector_set (&v.vector, 0, 1.0);
              
              /* x = tau * A * v */
              gsl_blas_dsymv (CblasLower, tau_i, &m.matrix, &v.vector, 0.0, &x.vector);

              /* w = x - (1/2) tau * (x' * v) * v  */
              {
                double xv, alpha;
                gsl_blas_ddot(&x.vector, &v.vector, &xv);
                alpha = - (tau_i / 2.0) * xv;
                gsl_blas_daxpy(alpha, &v.vector, &x.vector);
              }
              
              /* apply the transformation A = A - v w' - w v' */
              gsl_blas_dsyr2(CblasLower, -1.0, &v.vector, &x.vector, &m.matrix);

              gsl_vector_set (&v.vector, 0, ei);
            }
          
          gsl_vector_set (tau, i, tau_i);
        }
      
      return GSL_SUCCESS;
    }
}  
=======

      for (i = 0 ; i < N - 2; i++)
	{
	  gsl_vector_view c = gsl_matrix_column (A, i);
	  gsl_vector_view v = gsl_vector_subvector (&c.vector, i + 1, N - (i + 1));
	  double tau_i = gsl_linalg_householder_transform (&v.vector);

	  /* Apply the transformation H^T A H to the remaining columns */

	  if (tau_i != 0.0)
	    {
	      gsl_matrix_view m = gsl_matrix_submatrix (A, i + 1, i + 1,
							N - (i+1), N - (i+1));
	      double ei = gsl_vector_get(&v.vector, 0);
	      gsl_vector_view x = gsl_vector_subvector (tau, i, N-(i+1));
	      gsl_vector_set (&v.vector, 0, 1.0);

	      /* x = tau * A * v */
	      gsl_blas_dsymv (CblasLower, tau_i, &m.matrix, &v.vector, 0.0, &x.vector);

	      /* w = x - (1/2) tau * (x' * v) * v  */
	      {
		double xv, alpha;
		gsl_blas_ddot(&x.vector, &v.vector, &xv);
		alpha = - (tau_i / 2.0) * xv;
		gsl_blas_daxpy(alpha, &v.vector, &x.vector);
	      }

	      /* apply the transformation A = A - v w' - w v' */
	      gsl_blas_dsyr2(CblasLower, -1.0, &v.vector, &x.vector, &m.matrix);

	      gsl_vector_set (&v.vector, 0, ei);
	    }

	  gsl_vector_set (tau, i, tau_i);
	}

      return GSL_SUCCESS;
    }
}
>>>>>>> config


/*  Form the orthogonal matrix Q from the packed QR matrix */

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_linalg_symmtd_unpack (const gsl_matrix * A, 
                          const gsl_vector * tau,
                          gsl_matrix * Q, 
                          gsl_vector * diag, 
                          gsl_vector * sdiag)
=======
gsl_linalg_symmtd_unpack (const gsl_matrix * A,
			  const gsl_vector * tau,
			  gsl_matrix * Q,
			  gsl_vector * diag,
			  gsl_vector * sdiag)
>>>>>>> config
{
  if (A->size1 !=  A->size2)
    {
      GSL_ERROR ("matrix A must be square", GSL_ENOTSQR);
    }
  else if (tau->size + 1 != A->size1)
    {
      GSL_ERROR ("size of tau must be (matrix size - 1)", GSL_EBADLEN);
    }
  else if (Q->size1 != A->size1 || Q->size2 != A->size1)
    {
      GSL_ERROR ("size of Q must match size of A", GSL_EBADLEN);
    }
  else if (diag->size != A->size1)
    {
      GSL_ERROR ("size of diagonal must match size of A", GSL_EBADLEN);
    }
  else if (sdiag->size + 1 != A->size1)
    {
      GSL_ERROR ("size of subdiagonal must be (matrix size - 1)", GSL_EBADLEN);
    }
  else
    {
      const size_t N = A->size1;

      size_t i;

      /* Initialize Q to the identity */

      gsl_matrix_set_identity (Q);

      for (i = N - 2; i-- > 0;)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          gsl_vector_const_view c = gsl_matrix_const_column (A, i);
          gsl_vector_const_view h = gsl_vector_const_subvector (&c.vector, i + 1, N - (i+1));
          double ti = gsl_vector_get (tau, i);

          gsl_matrix_view m = gsl_matrix_submatrix (Q, i + 1, i + 1, N-(i+1), N-(i+1));

          gsl_linalg_householder_hm (ti, &h.vector, &m.matrix);
        }
=======
	{
	  gsl_vector_const_view c = gsl_matrix_const_column (A, i);
	  gsl_vector_const_view h = gsl_vector_const_subvector (&c.vector, i + 1, N - (i+1));
	  double ti = gsl_vector_get (tau, i);

	  gsl_matrix_view m = gsl_matrix_submatrix (Q, i + 1, i + 1, N-(i+1), N-(i+1));

	  gsl_linalg_householder_hm (ti, &h.vector, &m.matrix);
	}
>>>>>>> config

      /* Copy diagonal into diag */

      for (i = 0; i < N; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          double Aii = gsl_matrix_get (A, i, i);
          gsl_vector_set (diag, i, Aii);
        }
=======
	{
	  double Aii = gsl_matrix_get (A, i, i);
	  gsl_vector_set (diag, i, Aii);
	}
>>>>>>> config

      /* Copy subdiagonal into sd */

      for (i = 0; i < N - 1; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          double Aji = gsl_matrix_get (A, i+1, i);
          gsl_vector_set (sdiag, i, Aji);
        }
=======
	{
	  double Aji = gsl_matrix_get (A, i+1, i);
	  gsl_vector_set (sdiag, i, Aji);
	}
>>>>>>> config

      return GSL_SUCCESS;
    }
}

int
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_linalg_symmtd_unpack_T (const gsl_matrix * A, 
                            gsl_vector * diag, 
                            gsl_vector * sdiag)
=======
gsl_linalg_symmtd_unpack_T (const gsl_matrix * A,
			    gsl_vector * diag,
			    gsl_vector * sdiag)
>>>>>>> config
{
  if (A->size1 !=  A->size2)
    {
      GSL_ERROR ("matrix A must be square", GSL_ENOTSQR);
    }
  else if (diag->size != A->size1)
    {
      GSL_ERROR ("size of diagonal must match size of A", GSL_EBADLEN);
    }
  else if (sdiag->size + 1 != A->size1)
    {
      GSL_ERROR ("size of subdiagonal must be (matrix size - 1)", GSL_EBADLEN);
    }
  else
    {
      const size_t N = A->size1;

      size_t i;

      /* Copy diagonal into diag */

      for (i = 0; i < N; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          double Aii = gsl_matrix_get (A, i, i);
          gsl_vector_set (diag, i, Aii);
        }
=======
	{
	  double Aii = gsl_matrix_get (A, i, i);
	  gsl_vector_set (diag, i, Aii);
	}
>>>>>>> config

      /* Copy subdiagonal into sdiag */

      for (i = 0; i < N - 1; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          double Aij = gsl_matrix_get (A, i+1, i);
          gsl_vector_set (sdiag, i, Aij);
        }
=======
	{
	  double Aij = gsl_matrix_get (A, i+1, i);
	  gsl_vector_set (sdiag, i, Aij);
	}
>>>>>>> config

      return GSL_SUCCESS;
    }
}
