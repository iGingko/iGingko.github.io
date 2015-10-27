/* blas/source_trmv_r.h
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
  INDEX i, j;
  const int nonunit = (Diag == CblasNonUnit);
  const int Trans = (TransA != CblasConjTrans) ? TransA : CblasTrans;

  if ((order == CblasRowMajor && Trans == CblasNoTrans && Uplo == CblasUpper)
      || (order == CblasColMajor && Trans == CblasTrans && Uplo == CblasLower)) {
    /* form  x := A*x */

    INDEX ix = OFFSET(N, incX);
    for (i = 0; i < N; i++) {
      BASE temp = 0.0;
      const INDEX j_min = i + 1;
      const INDEX j_max = N;
      INDEX jx = OFFSET(N, incX) + j_min * incX;
      for (j = j_min; j < j_max; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        temp += X[jx] * A[lda * i + j];
        jx += incX;
      }
      if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + i];
      } else {
        X[ix] += temp;
=======
	temp += X[jx] * A[lda * i + j];
	jx += incX;
      }
      if (nonunit) {
	X[ix] = temp + X[ix] * A[lda * i + i];
      } else {
	X[ix] += temp;
>>>>>>> config
      }
      ix += incX;
    }
  } else if ((order == CblasRowMajor && Trans == CblasNoTrans && Uplo == CblasLower)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             || (order == CblasColMajor && Trans == CblasTrans && Uplo == CblasUpper)) {
=======
	     || (order == CblasColMajor && Trans == CblasTrans && Uplo == CblasUpper)) {
>>>>>>> config
    INDEX ix = OFFSET(N, incX) + (N - 1) * incX;
    for (i = N; i > 0 && i--;) {
      BASE temp = 0.0;
      const INDEX j_min = 0;
      const INDEX j_max = i;
      INDEX jx = OFFSET(N, incX) + j_min * incX;
      for (j = j_min; j < j_max; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        temp += X[jx] * A[lda * i + j];
        jx += incX;
      }
      if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + i];
      } else {
        X[ix] += temp;
=======
	temp += X[jx] * A[lda * i + j];
	jx += incX;
      }
      if (nonunit) {
	X[ix] = temp + X[ix] * A[lda * i + i];
      } else {
	X[ix] += temp;
>>>>>>> config
      }
      ix -= incX;
    }
  } else if ((order == CblasRowMajor && Trans == CblasTrans && Uplo == CblasUpper)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             || (order == CblasColMajor && Trans == CblasNoTrans && Uplo == CblasLower)) {
=======
	     || (order == CblasColMajor && Trans == CblasNoTrans && Uplo == CblasLower)) {
>>>>>>> config
    /* form  x := A'*x */
    INDEX ix = OFFSET(N, incX) + (N - 1) * incX;
    for (i = N; i > 0 && i--;) {
      BASE temp = 0.0;
      const INDEX j_min = 0;
      const INDEX j_max = i;
      INDEX jx = OFFSET(N, incX) + j_min * incX;
      for (j = j_min; j < j_max; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        temp += X[jx] * A[lda * j + i];
        jx += incX;
      }
      if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + i];
      } else {
        X[ix] += temp;
=======
	temp += X[jx] * A[lda * j + i];
	jx += incX;
      }
      if (nonunit) {
	X[ix] = temp + X[ix] * A[lda * i + i];
      } else {
	X[ix] += temp;
>>>>>>> config
      }
      ix -= incX;
    }
  } else if ((order == CblasRowMajor && Trans == CblasTrans && Uplo == CblasLower)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
             || (order == CblasColMajor && Trans == CblasNoTrans && Uplo == CblasUpper)) {
=======
	     || (order == CblasColMajor && Trans == CblasNoTrans && Uplo == CblasUpper)) {
>>>>>>> config
    INDEX ix = OFFSET(N, incX);
    for (i = 0; i < N; i++) {
      BASE temp = 0.0;
      const INDEX j_min = i + 1;
      const INDEX j_max = N;
      INDEX jx = OFFSET(N, incX) + (i + 1) * incX;
      for (j = j_min; j < j_max; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        temp += X[jx] * A[lda * j + i];
        jx += incX;
      }
      if (nonunit) {
        X[ix] = temp + X[ix] * A[lda * i + i];
      } else {
        X[ix] += temp;
=======
	temp += X[jx] * A[lda * j + i];
	jx += incX;
      }
      if (nonunit) {
	X[ix] = temp + X[ix] * A[lda * i + i];
      } else {
	X[ix] += temp;
>>>>>>> config
      }
      ix += incX;
    }
  } else {
    BLAS_ERROR("unrecognized operation");
  }
}
