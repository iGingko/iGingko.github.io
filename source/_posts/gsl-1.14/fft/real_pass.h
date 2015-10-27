/* fft/real_pass.h
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Brian Gough
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

static void FUNCTION(fft_real,pass_2) (const BASE in[],
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                       const size_t istride,
                                       BASE out[],
                                       const size_t ostride,
                                       const size_t product,
                                       const size_t n,
                                       const TYPE(gsl_complex) twiddle[]);

static void FUNCTION(fft_real,pass_3) (const BASE in[], 
                                       const size_t istride,
                                       BASE out[],
                                       const size_t ostride,
                                       const size_t product,
                                       const size_t n,
                                       const TYPE(gsl_complex) twiddle1[],
                                       const TYPE(gsl_complex) twiddle2[]);

static void FUNCTION(fft_real,pass_4) (const BASE in[],
                                       const size_t istride,
                                       BASE out[],
                                       const size_t ostride,
                                       const size_t product,
                                       const size_t n,
                                       const TYPE(gsl_complex) twiddle1[],
                                       const TYPE(gsl_complex) twiddle2[],
                                       const TYPE(gsl_complex) twiddle3[]);

static void FUNCTION(fft_real,pass_5) (const BASE in[],
                                       const size_t istride,
                                       BASE out[],
                                       const size_t ostride,
                                       const size_t product,
                                       const size_t n,
                                       const TYPE(gsl_complex) twiddle1[],
                                       const TYPE(gsl_complex) twiddle2[],
                                       const TYPE(gsl_complex) twiddle3[],
                                       const TYPE(gsl_complex) twiddle4[]);

static void FUNCTION(fft_real,pass_n) (const BASE in[], 
                                       const size_t istride,
                                       BASE out[],
                                       const size_t ostride,
                                       const size_t factor,
                                       const size_t product,
                                       const size_t n,
                                       const TYPE(gsl_complex) twiddle[]);
=======
				       const size_t istride,
				       BASE out[],
				       const size_t ostride,
				       const size_t product,
				       const size_t n,
				       const TYPE(gsl_complex) twiddle[]);

static void FUNCTION(fft_real,pass_3) (const BASE in[],
				       const size_t istride,
				       BASE out[],
				       const size_t ostride,
				       const size_t product,
				       const size_t n,
				       const TYPE(gsl_complex) twiddle1[],
				       const TYPE(gsl_complex) twiddle2[]);

static void FUNCTION(fft_real,pass_4) (const BASE in[],
				       const size_t istride,
				       BASE out[],
				       const size_t ostride,
				       const size_t product,
				       const size_t n,
				       const TYPE(gsl_complex) twiddle1[],
				       const TYPE(gsl_complex) twiddle2[],
				       const TYPE(gsl_complex) twiddle3[]);

static void FUNCTION(fft_real,pass_5) (const BASE in[],
				       const size_t istride,
				       BASE out[],
				       const size_t ostride,
				       const size_t product,
				       const size_t n,
				       const TYPE(gsl_complex) twiddle1[],
				       const TYPE(gsl_complex) twiddle2[],
				       const TYPE(gsl_complex) twiddle3[],
				       const TYPE(gsl_complex) twiddle4[]);

static void FUNCTION(fft_real,pass_n) (const BASE in[],
				       const size_t istride,
				       BASE out[],
				       const size_t ostride,
				       const size_t factor,
				       const size_t product,
				       const size_t n,
				       const TYPE(gsl_complex) twiddle[]);
>>>>>>> config
