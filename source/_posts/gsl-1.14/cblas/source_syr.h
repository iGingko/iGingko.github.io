/* blas/source_syr.h
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

  if (N == 0)
    return;

  if (alpha == 0.0)
    return;

  if ((order == CblasRowMajor && Uplo == CblasUpper)
      || (order == CblasColMajor && Uplo == CblasLower)) {
    INDEX ix = OFFSET(N, incX);
    for (i = 0; i < N; i++) {
      const BASE tmp = alpha * X[ix];
      INDEX jx = ix;
      for (j = i; j < N; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        A[lda * i + j] += X[jx] * tmp;
        jx += incX;
=======
	A[lda * i + j] += X[jx] * tmp;
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
      const BASE tmp = alpha * X[ix];
      INDEX jx = OFFSET(N, incX);
      for (j = 0; j <= i; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        A[lda * i + j] += X[jx] * tmp;
        jx += incX;
=======
	A[lda * i + j] += X[jx] * tmp;
	jx += incX;
>>>>>>> config
      }
      ix += incX;
    }
  } else {
    BLAS_ERROR("unrecognized operation");
  }
}
