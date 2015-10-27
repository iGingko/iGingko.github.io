/* blas/source_syrk_r.h
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
  int uplo, trans;

  if (alpha == 0.0 && beta == 1.0)
    return;

  if (Order == CblasRowMajor) {
    uplo = Uplo;
    trans = (Trans == CblasConjTrans) ? CblasTrans : Trans;
  } else {
    uplo = (Uplo == CblasUpper) ? CblasLower : CblasUpper;

    if (Trans == CblasTrans || Trans == CblasConjTrans) {
      trans = CblasNoTrans;
    } else {
      trans = CblasTrans;
    }
  }

  /* form  y := beta*y */
  if (beta == 0.0) {
    if (uplo == CblasUpper) {
      for (i = 0; i < N; i++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        for (j = i; j < N; j++) {
          C[ldc * i + j] = 0.0;
        }
      }
    } else {
      for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
          C[ldc * i + j] = 0.0;
        }
=======
	for (j = i; j < N; j++) {
	  C[ldc * i + j] = 0.0;
	}
      }
    } else {
      for (i = 0; i < N; i++) {
	for (j = 0; j <= i; j++) {
	  C[ldc * i + j] = 0.0;
	}
>>>>>>> config
      }
    }
  } else if (beta != 1.0) {
    if (uplo == CblasUpper) {
      for (i = 0; i < N; i++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        for (j = i; j < N; j++) {
          C[ldc * i + j] *= beta;
        }
      }
    } else {
      for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
          C[ldc * i + j] *= beta;
        }
=======
	for (j = i; j < N; j++) {
	  C[ldc * i + j] *= beta;
	}
      }
    } else {
      for (i = 0; i < N; i++) {
	for (j = 0; j <= i; j++) {
	  C[ldc * i + j] *= beta;
	}
>>>>>>> config
      }
    }
  }

  if (alpha == 0.0)
    return;

  if (uplo == CblasUpper && trans == CblasNoTrans) {

    for (i = 0; i < N; i++) {
      for (j = i; j < N; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        BASE temp = 0.0;
        for (k = 0; k < K; k++) {
          temp += A[i * lda + k] * A[j * lda + k];
        }
        C[i * ldc + j] += alpha * temp;
=======
	BASE temp = 0.0;
	for (k = 0; k < K; k++) {
	  temp += A[i * lda + k] * A[j * lda + k];
	}
	C[i * ldc + j] += alpha * temp;
>>>>>>> config
      }
    }

  } else if (uplo == CblasUpper && trans == CblasTrans) {

    for (i = 0; i < N; i++) {
      for (j = i; j < N; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        BASE temp = 0.0;
        for (k = 0; k < K; k++) {
          temp += A[k * lda + i] * A[k * lda + j];
        }
        C[i * ldc + j] += alpha * temp;
=======
	BASE temp = 0.0;
	for (k = 0; k < K; k++) {
	  temp += A[k * lda + i] * A[k * lda + j];
	}
	C[i * ldc + j] += alpha * temp;
>>>>>>> config
      }
    }

  } else if (uplo == CblasLower && trans == CblasNoTrans) {

    for (i = 0; i < N; i++) {
      for (j = 0; j <= i; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        BASE temp = 0.0;
        for (k = 0; k < K; k++) {
          temp += A[i * lda + k] * A[j * lda + k];
        }
        C[i * ldc + j] += alpha * temp;
=======
	BASE temp = 0.0;
	for (k = 0; k < K; k++) {
	  temp += A[i * lda + k] * A[j * lda + k];
	}
	C[i * ldc + j] += alpha * temp;
>>>>>>> config
      }
    }

  } else if (uplo == CblasLower && trans == CblasTrans) {

    for (i = 0; i < N; i++) {
      for (j = 0; j <= i; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        BASE temp = 0.0;
        for (k = 0; k < K; k++) {
          temp += A[k * lda + i] * A[k * lda + j];
        }
        C[i * ldc + j] += alpha * temp;
=======
	BASE temp = 0.0;
	for (k = 0; k < K; k++) {
	  temp += A[k * lda + i] * A[k * lda + j];
	}
	C[i * ldc + j] += alpha * temp;
>>>>>>> config
      }
    }

  } else {
    BLAS_ERROR("unrecognized operation");
  }
}
