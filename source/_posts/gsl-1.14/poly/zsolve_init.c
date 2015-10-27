/* poly/zsolve_init.c
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

#include <config.h>
#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_poly.h>
#include <gsl/gsl_errno.h>

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
gsl_poly_complex_workspace * 
=======
gsl_poly_complex_workspace *
>>>>>>> config
gsl_poly_complex_workspace_alloc (size_t n)
{
  size_t nc ;

  gsl_poly_complex_workspace * w ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (n == 0)
    {
      GSL_ERROR_VAL ("matrix size n must be positive integer", GSL_EDOM, 0);
    }

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  w = (gsl_poly_complex_workspace *) 
=======
  w = (gsl_poly_complex_workspace *)
>>>>>>> config
    malloc (sizeof(gsl_poly_complex_workspace));

  if (w == 0)
    {
      GSL_ERROR_VAL ("failed to allocate space for struct", GSL_ENOMEM, 0);
    }

  nc = n - 1;

  w->nc = nc;

  w->matrix = (double *) malloc (nc * nc * sizeof(double));

  if (w->matrix == 0)
    {
      free (w) ;       /* error in constructor, avoid memory leak */
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
      GSL_ERROR_VAL ("failed to allocate space for workspace matrix", 
                        GSL_ENOMEM, 0);
=======

      GSL_ERROR_VAL ("failed to allocate space for workspace matrix",
			GSL_ENOMEM, 0);
>>>>>>> config
    }

  return w ;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
void 
=======
void
>>>>>>> config
gsl_poly_complex_workspace_free (gsl_poly_complex_workspace * w)
{
  RETURN_IF_NULL (w);
  free(w->matrix) ;
  free(w);
}
