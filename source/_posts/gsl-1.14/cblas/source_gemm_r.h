/* blas/source_gemm_r.h
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

{
  INDEX i, j, k;
  INDEX n1, n2;
  INDEX ldf, ldg;
  int TransF, TransG;
  const BASE *F, *G;

  if (alpha == 0.0 && beta == 1.0)
    return;

  if (Order == CblasRowMajor) {
    n1 = M;
    n2 = N;
    F = A;
    ldf = lda;
    TransF = (TransA == CblasConjTrans) ? CblasTrans : TransA;
    G = B;
    ldg = ldb;
    TransG = (TransB == CblasConjTrans) ? CblasTrans : TransB;
  } else {
    n1 = N;
    n2 = M;
    F = B;
    ldf = ldb;
    TransF = (TransB == CblasConjTrans) ? CblasTrans : TransB;
    G = A;
    ldg = lda;
    TransG = (TransA == CblasConjTrans) ? CblasTrans : TransA;
  }

  /* form  y := beta*y */
  if (beta == 0.0) {
    for (i = 0; i < n1; i++) {
      for (j = 0; j < n2; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        C[ldc * i + j] = 0.0;
=======
	C[ldc * i + j] = 0.0;
>>>>>>> config
      }
    }
  } else if (beta != 1.0) {
    for (i = 0; i < n1; i++) {
      for (j = 0; j < n2; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        C[ldc * i + j] *= beta;
=======
	C[ldc * i + j] *= beta;
>>>>>>> config
      }
    }
  }

  if (alpha == 0.0)
    return;

  if (TransF == CblasNoTrans && TransG == CblasNoTrans) {

    /* form  C := alpha*A*B + C */

    for (k = 0; k < K; k++) {
      for (i = 0; i < n1; i++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        const BASE temp = alpha * F[ldf * i + k];
        if (temp != 0.0) {
          for (j = 0; j < n2; j++) {
            C[ldc * i + j] += temp * G[ldg * k + j];
          }
        }
=======
	const BASE temp = alpha * F[ldf * i + k];
	if (temp != 0.0) {
	  for (j = 0; j < n2; j++) {
	    C[ldc * i + j] += temp * G[ldg * k + j];
	  }
	}
>>>>>>> config
      }
    }

  } else if (TransF == CblasNoTrans && TransG == CblasTrans) {

    /* form  C := alpha*A*B' + C */

    for (i = 0; i < n1; i++) {
      for (j = 0; j < n2; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        BASE temp = 0.0;
        for (k = 0; k < K; k++) {
          temp += F[ldf * i + k] * G[ldg * j + k];
        }
        C[ldc * i + j] += alpha * temp;
=======
	BASE temp = 0.0;
	for (k = 0; k < K; k++) {
	  temp += F[ldf * i + k] * G[ldg * j + k];
	}
	C[ldc * i + j] += alpha * temp;
>>>>>>> config
      }
    }

  } else if (TransF == CblasTrans && TransG == CblasNoTrans) {

    for (k = 0; k < K; k++) {
      for (i = 0; i < n1; i++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        const BASE temp = alpha * F[ldf * k + i];
        if (temp != 0.0) {
          for (j = 0; j < n2; j++) {
            C[ldc * i + j] += temp * G[ldg * k + j];
          }
        }
=======
	const BASE temp = alpha * F[ldf * k + i];
	if (temp != 0.0) {
	  for (j = 0; j < n2; j++) {
	    C[ldc * i + j] += temp * G[ldg * k + j];
	  }
	}
>>>>>>> config
      }
    }

  } else if (TransF == CblasTrans && TransG == CblasTrans) {

    for (i = 0; i < n1; i++) {
      for (j = 0; j < n2; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        BASE temp = 0.0;
        for (k = 0; k < K; k++) {
          temp += F[ldf * k + i] * G[ldg * j + k];
        }
        C[ldc * i + j] += alpha * temp;
=======
	BASE temp = 0.0;
	for (k = 0; k < K; k++) {
	  temp += F[ldf * k + i] * G[ldg * j + k];
	}
	C[ldc * i + j] += alpha * temp;
>>>>>>> config
      }
    }

  } else {
    BLAS_ERROR("unrecognized operation");
  }
}
