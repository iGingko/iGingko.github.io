/* blas/source_ger.h
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

  if (order == CblasRowMajor) {
    INDEX ix = OFFSET(M, incX);
    for (i = 0; i < M; i++) {
      const BASE tmp = alpha * X[ix];
      INDEX jy = OFFSET(N, incY);
      for (j = 0; j < N; j++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        A[lda * i + j] += Y[jy] * tmp;
        jy += incY;
=======
	A[lda * i + j] += Y[jy] * tmp;
	jy += incY;
>>>>>>> config
      }
      ix += incX;
    }
  } else if (order == CblasColMajor) {
    INDEX jy = OFFSET(N, incY);
    for (j = 0; j < N; j++) {
      const BASE tmp = alpha * Y[jy];
      INDEX ix = OFFSET(M, incX);
      for (i = 0; i < M; i++) {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        A[i + lda * j] += X[ix] * tmp;
        ix += incX;
=======
	A[i + lda * j] += X[ix] * tmp;
	ix += incX;
>>>>>>> config
      }
      jy += incY;
    }
  } else {
    BLAS_ERROR("unrecognized operation");
  }
}
