/* fft/compare.h
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

int
FUNCTION(compare_complex,results) (const char *name_a, const BASE a[],
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                   const char *name_b, const BASE b[],
                                   size_t stride, size_t n, 
                                   const double allowed_ticks);

int
FUNCTION(compare_real,results) (const char *name_a, const BASE a[],
                                   const char *name_b, const BASE b[],
                                   size_t stride, size_t n, 
                                   const double allowed_ticks);
=======
				   const char *name_b, const BASE b[],
				   size_t stride, size_t n,
				   const double allowed_ticks);

int
FUNCTION(compare_real,results) (const char *name_a, const BASE a[],
				   const char *name_b, const BASE b[],
				   size_t stride, size_t n,
				   const double allowed_ticks);
>>>>>>> config
