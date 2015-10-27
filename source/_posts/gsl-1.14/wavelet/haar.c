/* wavelet/haar.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2004 Ivo Alxneit
 * 
=======
 *
 * Copyright (C) 2004 Ivo Alxneit
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
#include <gsl/gsl_errno.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_wavelet.h>

static const double ch_2[2] = { M_SQRT1_2, M_SQRT1_2 };
static const double cg_2[2] = { M_SQRT1_2, -(M_SQRT1_2) };

static int
haar_init (const double **h1, const double **g1, const double **h2,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
           const double **g2, size_t * nc, size_t * offset,
           const size_t member)
=======
	   const double **g2, size_t * nc, size_t * offset,
	   const size_t member)
>>>>>>> config
{
  if (member != 2)
    {
      return GSL_FAILURE;
    }

  *h1 = ch_2;
  *g1 = cg_2;
  *h2 = ch_2;
  *g2 = cg_2;

  *nc = 2;
  *offset = 0;

  return GSL_SUCCESS;
}

static int
haar_centered_init (const double **h1, const double **g1, const double **h2,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                    const double **g2, size_t * nc, size_t * offset,
                    const size_t member)
=======
		    const double **g2, size_t * nc, size_t * offset,
		    const size_t member)
>>>>>>> config
{
  if (member != 2)
    {
      return GSL_FAILURE;
    }

  *h1 = ch_2;
  *g1 = cg_2;
  *h2 = ch_2;
  *g2 = cg_2;

  *nc = 2;
  *offset = 1;

  return GSL_SUCCESS;
}

static const gsl_wavelet_type haar_type = {
  "haar",
  &haar_init
};

static const gsl_wavelet_type haar_centered_type = {
  "haar-centered",
  &haar_centered_init
};

const gsl_wavelet_type *gsl_wavelet_haar = &haar_type;
const gsl_wavelet_type *gsl_wavelet_haar_centered = &haar_centered_type;
