/* blas/test.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2001, 2007 Brian Gough
 * 
=======
 *
 * Copyright (C) 2001, 2007 Brian Gough
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
#include <stdlib.h>
#include <gsl/gsl_test.h>
#include <gsl/gsl_ieee_utils.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_cblas.h>

#include "tests.h"

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
int 
=======
int
>>>>>>> config
main (void)
{
  gsl_ieee_env_setup ();

#include "tests.c"

  exit (gsl_test_summary());
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
