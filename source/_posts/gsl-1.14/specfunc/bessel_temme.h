/* specfunc/bessel_temme.h
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

/* Author:  G. Jungman */

#ifndef BESSEL_TEMME_H_
#define BESSEL_TEMME_H_

#include <gsl/gsl_sf_result.h>


int
gsl_sf_bessel_Y_temme(const double nu, const double x,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                      gsl_sf_result * Y_nu,
                      gsl_sf_result * Y_nup1);

int
gsl_sf_bessel_K_scaled_temme(const double nu, const double x,
                             double * K_nu, double * K_nup1, double * Kp_nu);
=======
		      gsl_sf_result * Y_nu,
		      gsl_sf_result * Y_nup1);

int
gsl_sf_bessel_K_scaled_temme(const double nu, const double x,
			     double * K_nu, double * K_nup1, double * Kp_nu);
>>>>>>> config


#endif /* !BESSEL_TEMME_H_ */
