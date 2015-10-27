/* linalg/ptlq.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Gerard Jungman, Brian Gough
 * Copyright (C) 2004 Joerg Wensch, modifications for LQ. 
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Gerard Jungman, Brian Gough
 * Copyright (C) 2004 Joerg Wensch, modifications for LQ.
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
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_permute_vector.h>
#include <gsl/gsl_linalg.h>

#include "givens.c"
#include "apply_givens.c"

/* The purpose of this package is to speed up QR-decomposition for
   large matrices.  Because QR-decomposition is column oriented, but
   GSL uses a row-oriented matrix format, there can considerable
   speedup obtained by computing the LQ-decomposition of the
   transposed matrix instead.  This package provides LQ-decomposition
   and related algorithms.  */

/* Factorise a general N x M matrix A into
 *
 *   P A = L Q
 *
 * where Q is orthogonal (M x M) and L is lower triangular (N x M).
 * When A is rank deficient, r = rank(A) < n, then the permutation is
 * used to ensure that the lower n - r columns of L are zero and the first
 * l rows of Q form an orthonormal basis for the rows of A.
 *
 * Q is stored as a packed set of Householder transformations in the
 * strict upper triangular part of the input matrix.
 *
 * L is stored in the diagonal and lower triangle of the input matrix.
 *
 * P: column j of P is column k of the identity matrix, where k =
 * permutation->data[j]
 *
 * The full matrix for Q can be obtained as the product
 *
 *       Q = Q_k .. Q_2 Q_1
 *
 * where k = MIN(M,N) and
 *
 *       Q_i = (I - tau_i * v_i * v_i')
 *
 * and where v_i is a Householder vector
 *
 *       v_i = [1, m(i,i+1), m(i,i+2), ... , m(i,M)]
 *
 * This storage scheme is the same as in LAPACK.  See LAPACK's
 * dgeqpf.f for details.
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
=======
 *
>>>>>>> config
 */

int
gsl_linalg_PTLQ_decomp (gsl_matrix * A, gsl_vector * tau, gsl_permutation * p, int *signum, gsl_vector * norm)
{
  const size_t N = A->size1;
  const size_t M = A->size2;

  if (tau->size != GSL_MIN (M, N))
    {
      GSL_ERROR ("size of tau must be MIN(M,N)", GSL_EBADLEN);
    }
  else if (p->size != N)
    {
      GSL_ERROR ("permutation size must be N", GSL_EBADLEN);
    }
  else if (norm->size != N)
    {
      GSL_ERROR ("norm size must be N", GSL_EBADLEN);
    }
  else
    {
      size_t i;

      *signum = 1;

      gsl_permutation_init (p); /* set to identity */

      /* Compute column norms and store in workspace */

      for (i = 0; i < N; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          gsl_vector_view c = gsl_matrix_row (A, i);
          double x = gsl_blas_dnrm2 (&c.vector);
          gsl_vector_set (norm, i, x);
        }

      for (i = 0; i < GSL_MIN (M, N); i++)
        {
          /* Bring the column of largest norm into the pivot position */

          double max_norm = gsl_vector_get(norm, i);
          size_t j, kmax = i;

          for (j = i + 1; j < N; j++)
            {
              double x = gsl_vector_get (norm, j);

              if (x > max_norm)
                {
                  max_norm = x;
                  kmax = j;
                }
            }

          if (kmax != i)
            {
              gsl_matrix_swap_rows (A, i, kmax);
              gsl_permutation_swap (p, i, kmax);
              gsl_vector_swap_elements(norm,i,kmax);

              (*signum) = -(*signum);
            }

          /* Compute the Householder transformation to reduce the j-th
             column of the matrix to a multiple of the j-th unit vector */

          {
            gsl_vector_view c_full = gsl_matrix_row (A, i);
            gsl_vector_view c = gsl_vector_subvector (&c_full.vector, 
                                                      i, M - i);
            double tau_i = gsl_linalg_householder_transform (&c.vector);

            gsl_vector_set (tau, i, tau_i);

            /* Apply the transformation to the remaining columns */

            if (i + 1 < N)
              {
                gsl_matrix_view m = gsl_matrix_submatrix (A, i +1, i, N - (i+1), M - i);

                gsl_linalg_householder_mh (tau_i, &c.vector, &m.matrix);
              }
          }

          /* Update the norms of the remaining columns too */

          if (i + 1 < M) 
            {
              for (j = i + 1; j < N; j++)
                {
                  double x = gsl_vector_get (norm, j);

                  if (x > 0.0)
                    {
                      double y = 0;
                      double temp= gsl_matrix_get (A, j, i) / x;
                  
                      if (fabs (temp) >= 1)
                        y = 0.0;
                      else
                        y = x * sqrt (1 - temp * temp);
                      
                      /* recompute norm to prevent loss of accuracy */

                      if (fabs (y / x) < sqrt (20.0) * GSL_SQRT_DBL_EPSILON)
                        {
                          gsl_vector_view c_full = gsl_matrix_row (A, j);
                          gsl_vector_view c = 
                            gsl_vector_subvector(&c_full.vector,
                                                 i+1, M - (i+1));
                          y = gsl_blas_dnrm2 (&c.vector);
                        }
                  
                      gsl_vector_set (norm, j, y);
                    }
                }
            }
        }
=======
	{
	  gsl_vector_view c = gsl_matrix_row (A, i);
	  double x = gsl_blas_dnrm2 (&c.vector);
	  gsl_vector_set (norm, i, x);
	}

      for (i = 0; i < GSL_MIN (M, N); i++)
	{
	  /* Bring the column of largest norm into the pivot position */

	  double max_norm = gsl_vector_get(norm, i);
	  size_t j, kmax = i;

	  for (j = i + 1; j < N; j++)
	    {
	      double x = gsl_vector_get (norm, j);

	      if (x > max_norm)
		{
		  max_norm = x;
		  kmax = j;
		}
	    }

	  if (kmax != i)
	    {
	      gsl_matrix_swap_rows (A, i, kmax);
	      gsl_permutation_swap (p, i, kmax);
	      gsl_vector_swap_elements(norm,i,kmax);

	      (*signum) = -(*signum);
	    }

	  /* Compute the Householder transformation to reduce the j-th
	     column of the matrix to a multiple of the j-th unit vector */

	  {
	    gsl_vector_view c_full = gsl_matrix_row (A, i);
	    gsl_vector_view c = gsl_vector_subvector (&c_full.vector,
						      i, M - i);
	    double tau_i = gsl_linalg_householder_transform (&c.vector);

	    gsl_vector_set (tau, i, tau_i);

	    /* Apply the transformation to the remaining columns */

	    if (i + 1 < N)
	      {
		gsl_matrix_view m = gsl_matrix_submatrix (A, i +1, i, N - (i+1), M - i);

		gsl_linalg_householder_mh (tau_i, &c.vector, &m.matrix);
	      }
	  }

	  /* Update the norms of the remaining columns too */

	  if (i + 1 < M)
	    {
	      for (j = i + 1; j < N; j++)
		{
		  double x = gsl_vector_get (norm, j);

		  if (x > 0.0)
		    {
		      double y = 0;
		      double temp= gsl_matrix_get (A, j, i) / x;

		      if (fabs (temp) >= 1)
			y = 0.0;
		      else
			y = x * sqrt (1 - temp * temp);

		      /* recompute norm to prevent loss of accuracy */

		      if (fabs (y / x) < sqrt (20.0) * GSL_SQRT_DBL_EPSILON)
			{
			  gsl_vector_view c_full = gsl_matrix_row (A, j);
			  gsl_vector_view c =
			    gsl_vector_subvector(&c_full.vector,
						 i+1, M - (i+1));
			  y = gsl_blas_dnrm2 (&c.vector);
			}

		      gsl_vector_set (norm, j, y);
		    }
		}
	    }
	}
>>>>>>> config

      return GSL_SUCCESS;
    }
}

int
gsl_linalg_PTLQ_decomp2 (const gsl_matrix * A, gsl_matrix * q, gsl_matrix * r, gsl_vector * tau, gsl_permutation * p, int *signum, gsl_vector * norm)
{
  const size_t N = A->size1;
  const size_t M = A->size2;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  if (q->size1 != M || q->size2 !=M) 
=======
  if (q->size1 != M || q->size2 !=M)
>>>>>>> config
    {
      GSL_ERROR ("q must be M x M", GSL_EBADLEN);
    }
  else if (r->size1 != N || r->size2 !=M)
    {
      GSL_ERROR ("r must be N x M", GSL_EBADLEN);
    }
  else if (tau->size != GSL_MIN (M, N))
    {
      GSL_ERROR ("size of tau must be MIN(M,N)", GSL_EBADLEN);
    }
  else if (p->size != N)
    {
      GSL_ERROR ("permutation size must be N", GSL_EBADLEN);
    }
  else if (norm->size != N)
    {
      GSL_ERROR ("norm size must be N", GSL_EBADLEN);
    }

  gsl_matrix_memcpy (r, A);

  gsl_linalg_PTLQ_decomp (r, tau, p, signum, norm);

  /* FIXME:  aliased arguments depends on behavior of unpack routine! */

  gsl_linalg_LQ_unpack (r, tau, q, r);

  return GSL_SUCCESS;
}


/* Solves the system x^T A = b^T using the P^T L Q  factorisation,

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
   z^T L = b^T Q^T 
=======
   z^T L = b^T Q^T
>>>>>>> config

   x = P z;

   to obtain x. Based on SLATEC code. */

int
gsl_linalg_PTLQ_solve_T (const gsl_matrix * QR,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                         const gsl_vector * tau,
                         const gsl_permutation * p,
                         const gsl_vector * b,
                         gsl_vector * x)
=======
			 const gsl_vector * tau,
			 const gsl_permutation * p,
			 const gsl_vector * b,
			 gsl_vector * x)
>>>>>>> config
{
  if (QR->size1 != QR->size2)
    {
      GSL_ERROR ("QR matrix must be square", GSL_ENOTSQR);
    }
  else if (QR->size2 != p->size)
    {
      GSL_ERROR ("matrix size must match permutation size", GSL_EBADLEN);
    }
  else if (QR->size2 != b->size)
    {
      GSL_ERROR ("matrix size must match b size", GSL_EBADLEN);
    }
  else if (QR->size1 != x->size)
    {
      GSL_ERROR ("matrix size must match solution size", GSL_EBADLEN);
    }
  else
    {
      gsl_vector_memcpy (x, b);

      gsl_linalg_PTLQ_svx_T (QR, tau, p, x);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
=======

>>>>>>> config
      return GSL_SUCCESS;
    }
}

int
gsl_linalg_PTLQ_svx_T (const gsl_matrix * LQ,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                       const gsl_vector * tau,
                       const gsl_permutation * p,
                       gsl_vector * x)
=======
		       const gsl_vector * tau,
		       const gsl_permutation * p,
		       gsl_vector * x)
>>>>>>> config
{
  if (LQ->size1 != LQ->size2)
    {
      GSL_ERROR ("LQ matrix must be square", GSL_ENOTSQR);
    }
  else if (LQ->size2 != p->size)
    {
      GSL_ERROR ("matrix size must match permutation size", GSL_EBADLEN);
    }
  else if (LQ->size1 != x->size)
    {
      GSL_ERROR ("matrix size must match solution size", GSL_EBADLEN);
    }
  else
    {
      /* compute sol = b^T Q^T */

      gsl_linalg_LQ_vecQT (LQ, tau, x);

      /* Solve  L^T x = sol, storing x inplace in sol */

      gsl_blas_dtrsv (CblasLower, CblasTrans, CblasNonUnit, LQ, x);

      gsl_permute_vector_inverse (p, x);

      return GSL_SUCCESS;
    }
}


int
gsl_linalg_PTLQ_LQsolve_T (const gsl_matrix * Q, const gsl_matrix * L,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                           const gsl_permutation * p,
                           const gsl_vector * b,
                           gsl_vector * x)
=======
			   const gsl_permutation * p,
			   const gsl_vector * b,
			   gsl_vector * x)
>>>>>>> config
{
  if (Q->size1 != Q->size2 || L->size1 != L->size2)
    {
      return GSL_ENOTSQR;
    }
  else if (Q->size1 != p->size || Q->size1 != L->size1
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
           || Q->size1 != b->size)
=======
	   || Q->size1 != b->size)
>>>>>>> config
    {
      return GSL_EBADLEN;
    }
  else
    {
      /* compute b' = Q b */

      gsl_blas_dgemv (CblasNoTrans, 1.0, Q, b, 0.0, x);

      /* Solve L^T x = b', storing x inplace */

      gsl_blas_dtrsv (CblasLower, CblasTrans, CblasNonUnit, L, x);

      /* Apply permutation to solution in place */

      gsl_permute_vector_inverse (p, x);

      return GSL_SUCCESS;
    }
}

int
gsl_linalg_PTLQ_Lsolve_T (const gsl_matrix * LQ,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        const gsl_permutation * p,
                        const gsl_vector * b,
                        gsl_vector * x)
=======
			const gsl_permutation * p,
			const gsl_vector * b,
			gsl_vector * x)
>>>>>>> config
{
  if (LQ->size1 != LQ->size2)
    {
      GSL_ERROR ("LQ matrix must be square", GSL_ENOTSQR);
    }
  else if (LQ->size1 != b->size)
    {
      GSL_ERROR ("matrix size must match b size", GSL_EBADLEN);
    }
  else if (LQ->size2 != x->size)
    {
      GSL_ERROR ("matrix size must match x size", GSL_EBADLEN);
    }
  else if (p->size != x->size)
    {
      GSL_ERROR ("permutation size must match x size", GSL_EBADLEN);
    }
  else
    {
      /* Copy x <- b */

      gsl_vector_memcpy (x, b);

      /* Solve L^T x = b, storing x inplace */

      gsl_blas_dtrsv (CblasLower, CblasTrans, CblasNonUnit, LQ, x);

      gsl_permute_vector_inverse (p, x);

      return GSL_SUCCESS;
    }
}


int
gsl_linalg_PTLQ_Lsvx_T (const gsl_matrix * LQ,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        const gsl_permutation * p,
                        gsl_vector * x)
=======
			const gsl_permutation * p,
			gsl_vector * x)
>>>>>>> config
{
  if (LQ->size1 != LQ->size2)
    {
      GSL_ERROR ("LQ matrix must be square", GSL_ENOTSQR);
    }
  else if (LQ->size2 != x->size)
    {
      GSL_ERROR ("matrix size must match x size", GSL_EBADLEN);
    }
  else if (p->size != x->size)
    {
      GSL_ERROR ("permutation size must match x size", GSL_EBADLEN);
    }
  else
    {
      /* Solve L^T x = b, storing x inplace */

      gsl_blas_dtrsv (CblasLower, CblasTrans, CblasNonUnit, LQ, x);

      gsl_permute_vector_inverse (p, x);

      return GSL_SUCCESS;
    }
}



/* Update a P^T L Q factorisation for P A= L Q ,  A' =  A +  v u^T,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                                 PA' = PA + Pv u^T
=======
						 PA' = PA + Pv u^T
>>>>>>> config

 * P^T L' Q' = P^T LQ + v u^T
 *       = P^T (L + (P v) u^T Q^T) Q
 *       = P^T (L + (P v) w^T) Q
 *
 * where w = Q^T u.
 *
 * Algorithm from Golub and Van Loan, "Matrix Computations", Section
 * 12.5 (Updating Matrix Factorizations, Rank-One Changes)
 */

int
gsl_linalg_PTLQ_update (gsl_matrix * Q, gsl_matrix * L,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                        const gsl_permutation * p,
                        const gsl_vector * v, gsl_vector * w)
=======
			const gsl_permutation * p,
			const gsl_vector * v, gsl_vector * w)
>>>>>>> config
{
  if (Q->size1 != Q->size2 || L->size1 != L->size2)
    {
      return GSL_ENOTSQR;
    }
  else if (L->size1 != Q->size2 || v->size != Q->size2 || w->size != Q->size2)
    {
      return GSL_EBADLEN;
    }
  else
    {
      size_t j, k;
      const size_t N = Q->size1;
      const size_t M = Q->size2;
      double w0;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      /* Apply Given's rotations to reduce w to (|w|, 0, 0, ... , 0) 

         J_1^T .... J_(n-1)^T w = +/- |w| e_1

         simultaneously applied to L,  H = J_1^T ... J^T_(n-1) L
         so that H is upper Hessenberg.  (12.5.2) */

      for (k = M - 1; k > 0; k--)
        {
          double c, s;
          double wk = gsl_vector_get (w, k);
          double wkm1 = gsl_vector_get (w, k - 1);

          create_givens (wkm1, wk, &c, &s);
          apply_givens_vec (w, k - 1, k, c, s);
          apply_givens_lq (M, N, Q, L, k - 1, k, c, s);
        }
=======
      /* Apply Given's rotations to reduce w to (|w|, 0, 0, ... , 0)

	 J_1^T .... J_(n-1)^T w = +/- |w| e_1

	 simultaneously applied to L,  H = J_1^T ... J^T_(n-1) L
	 so that H is upper Hessenberg.  (12.5.2) */

      for (k = M - 1; k > 0; k--)
	{
	  double c, s;
	  double wk = gsl_vector_get (w, k);
	  double wkm1 = gsl_vector_get (w, k - 1);

	  create_givens (wkm1, wk, &c, &s);
	  apply_givens_vec (w, k - 1, k, c, s);
	  apply_givens_lq (M, N, Q, L, k - 1, k, c, s);
	}
>>>>>>> config

      w0 = gsl_vector_get (w, 0);

      /* Add in v w^T  (Equation 12.5.3) */

      for (j = 0; j < N; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          double lj0 = gsl_matrix_get (L, j, 0);
          size_t p_j = gsl_permutation_get (p, j);
          double vj = gsl_vector_get (v, p_j);
          gsl_matrix_set (L, j, 0, lj0 + w0 * vj);
        }

      /* Apply Givens transformations L' = G_(n-1)^T ... G_1^T H  
         Equation 12.5.4 */

      for (k = 1; k < N; k++)
        {
          double c, s;
          double diag = gsl_matrix_get (L, k - 1, k - 1);
          double offdiag = gsl_matrix_get (L, k - 1, k );

          create_givens (diag, offdiag, &c, &s);
          apply_givens_lq (M, N, Q, L, k - 1, k, c, s);
        }
=======
	{
	  double lj0 = gsl_matrix_get (L, j, 0);
	  size_t p_j = gsl_permutation_get (p, j);
	  double vj = gsl_vector_get (v, p_j);
	  gsl_matrix_set (L, j, 0, lj0 + w0 * vj);
	}

      /* Apply Givens transformations L' = G_(n-1)^T ... G_1^T H
	 Equation 12.5.4 */

      for (k = 1; k < N; k++)
	{
	  double c, s;
	  double diag = gsl_matrix_get (L, k - 1, k - 1);
	  double offdiag = gsl_matrix_get (L, k - 1, k );

	  create_givens (diag, offdiag, &c, &s);
	  apply_givens_lq (M, N, Q, L, k - 1, k, c, s);
	}
>>>>>>> config

      return GSL_SUCCESS;
    }
}
