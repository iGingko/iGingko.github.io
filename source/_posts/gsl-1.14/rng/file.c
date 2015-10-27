/* rng/file.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2003 Olaf Lenz
 * 
=======
 *
 * Copyright (C) 2003 Olaf Lenz
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
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_rng.h>

int
gsl_rng_fread (FILE * stream, gsl_rng * r)
{
  size_t n = r->type->size ;

  char * state = (char *)r->state;

  size_t items = fread (state, 1, n, stream);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (items != n)
    {
      GSL_ERROR ("fread failed", GSL_EFAILED);
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
=======

>>>>>>> config
  return GSL_SUCCESS;
}

int
gsl_rng_fwrite (FILE * stream, const gsl_rng * r)
{
  size_t n = r->type->size ;

  char * state = (char *)r->state;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  size_t items = fwrite (state, 1, n, stream);
  
=======

  size_t items = fwrite (state, 1, n, stream);

>>>>>>> config
  if (items != n)
    {
      GSL_ERROR ("fwrite failed", GSL_EFAILED);
    }

  return GSL_SUCCESS;
}
