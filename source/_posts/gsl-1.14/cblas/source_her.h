/* blas/source_her.h
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Gerard Jungman
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000 Gerard Jungman
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
  const int conj = (order == CblasColMajor) ? -1 : 1;
  INDEX i, j;

  if (alpha == 0.0)
    return;

  if ((order == CblasRowMajor && Uplo == CblasUpper)
      || (order == CblasColMajor && Uplo == CblasLower)) {
    INDEX ix = OFFSET(N, incX);
    for (i = 0; i < N; i++) {
      const BASE tmp_real = alpha * CONST_REAL(X, ix);
      const BASE tmp_imag = alpha * conj * CONST_IMAG(X, ix);
      INDEX jx = ix;

      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        const BASE X_real = CONST_REAL(X, jx);
        const BASE X_imag = -conj * CONST_IMAG(X, jx);
        REAL(A, lda * i + i) += X_real * tmp_real - X_imag * tmp_imag;
        IMAG(A, lda * i + i) = 0;
        jx += incX;
      }

      for (j = i + 1; j < N; j++) {
        const BASE X_real = CONST_REAL(X, jx);
        const BASE X_imag = -conj * CONST_IMAG(X, jx);
        REAL(A, lda * i + j) += X_real * tmp_real - X_imag * tmp_imag;
        IMAG(A, lda * i + j) += X_imag * tmp_real + X_real * tmp_imag;
        jx += incX;
=======
	const BASE X_real = CONST_REAL(X, jx);
	const BASE X_imag = -conj * CONST_IMAG(X, jx);
	REAL(A, lda * i + i) += X_real * tmp_real - X_imag * tmp_imag;
	IMAG(A, lda * i + i) = 0;
	jx += incX;
      }

      for (j = i + 1; j < N; j++) {
	const BASE X_real = CONST_REAL(X, jx);
	const BASE X_imag = -conj * CONST_IMAG(X, jx);
	REAL(A, lda * i + j) += X_real * tmp_real - X_imag * tmp_imag;
	IMAG(A, lda * i + j) += X_imag * tmp_real + X_real * tmp_imag;
	jx += incX;
>>>>>>> config
      }
      ix += incX;
    }
  } else if ((order == CblasRowMajor && Uplo == CblasLower)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             || (order == CblasColMajor && Uplo == CblasUpper)) {
=======
	     || (order == CblasColMajor && Uplo == CblasUpper)) {
>>>>>>> config
    INDEX ix = OFFSET(N, incX);
    for (i = 0; i < N; i++) {
      const BASE tmp_real = alpha * CONST_REAL(X, ix);
      const BASE tmp_imag = alpha * conj * CONST_IMAG(X, ix);
      INDEX jx = OFFSET(N, incX);
      for (j = 0; j < i; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        const BASE X_real = CONST_REAL(X, jx);
        const BASE X_imag = -conj * CONST_IMAG(X, jx);
        REAL(A, lda * i + j) += X_real * tmp_real - X_imag * tmp_imag;
        IMAG(A, lda * i + j) += X_imag * tmp_real + X_real * tmp_imag;
        jx += incX;
      }

      {
        const BASE X_real = CONST_REAL(X, jx);
        const BASE X_imag = -conj * CONST_IMAG(X, jx);
        REAL(A, lda * i + i) += X_real * tmp_real - X_imag * tmp_imag;
        IMAG(A, lda * i + i) = 0;
        jx += incX;
=======
	const BASE X_real = CONST_REAL(X, jx);
	const BASE X_imag = -conj * CONST_IMAG(X, jx);
	REAL(A, lda * i + j) += X_real * tmp_real - X_imag * tmp_imag;
	IMAG(A, lda * i + j) += X_imag * tmp_real + X_real * tmp_imag;
	jx += incX;
      }

      {
	const BASE X_real = CONST_REAL(X, jx);
	const BASE X_imag = -conj * CONST_IMAG(X, jx);
	REAL(A, lda * i + i) += X_real * tmp_real - X_imag * tmp_imag;
	IMAG(A, lda * i + i) = 0;
	jx += incX;
>>>>>>> config
      }

      ix += incX;
    }
  } else {
    BLAS_ERROR("unrecognized operation");
  }
}
