/* deriv/gsl_deriv.h
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2000 David Morrison
 * 
=======
 *
 * Copyright (C) 2000 David Morrison
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

#ifndef __GSL_DERIV_H__
#define __GSL_DERIV_H__
#include <gsl/gsl_math.h>

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

int gsl_deriv_central (const gsl_function *f,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                       double x, double h,
                       double *result, double *abserr);

int gsl_deriv_backward (const gsl_function *f,
                        double x, double h,
                        double *result, double *abserr);

int gsl_deriv_forward (const gsl_function *f,
                       double x, double h,
                       double *result, double *abserr);
=======
		       double x, double h,
		       double *result, double *abserr);

int gsl_deriv_backward (const gsl_function *f,
			double x, double h,
			double *result, double *abserr);

int gsl_deriv_forward (const gsl_function *f,
		       double x, double h,
		       double *result, double *abserr);
>>>>>>> config

__END_DECLS

#endif /* __GSL_DERIV_H__ */
