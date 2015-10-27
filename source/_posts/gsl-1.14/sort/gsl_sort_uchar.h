/* sort/gsl_sort_uchar.h
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Thomas Walter, Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Thomas Walter, Brian Gough
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

#ifndef __GSL_SORT_UCHAR_H__
#define __GSL_SORT_UCHAR_H__

#include <stdlib.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_permutation.h>

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

void gsl_sort_uchar (unsigned char * data, const size_t stride, const size_t n);
void gsl_sort_uchar_index (size_t * p, const unsigned char * data, const size_t stride, const size_t n);

int gsl_sort_uchar_smallest (unsigned char * dest, const size_t k, const unsigned char * src, const size_t stride, const size_t n);
int gsl_sort_uchar_smallest_index (size_t * p, const size_t k, const unsigned char * src, const size_t stride, const size_t n);

int gsl_sort_uchar_largest (unsigned char * dest, const size_t k, const unsigned char * src, const size_t stride, const size_t n);
int gsl_sort_uchar_largest_index (size_t * p, const size_t k, const unsigned char * src, const size_t stride, const size_t n);

__END_DECLS

#endif /* __GSL_SORT_UCHAR_H__ */
