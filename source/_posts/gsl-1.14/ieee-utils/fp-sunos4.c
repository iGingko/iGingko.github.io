/* ieee-utils/fp-sunos4.c
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

#include <sys/ieeefp.h>
#include <floatingpoint.h>
#include <signal.h>
#include <gsl/gsl_ieee_utils.h>
#include <gsl/gsl_errno.h>

int
gsl_ieee_set_mode (int precision, int rounding, int exception_mask)
{
  char * out ;

  switch (precision)
    {
    case GSL_IEEE_SINGLE_PRECISION:
      ieee_flags ("set", "precision", "single", out) ;
      break ;
    case GSL_IEEE_DOUBLE_PRECISION:
      ieee_flags ("set", "precision", "double", out) ;
      break ;
    case GSL_IEEE_EXTENDED_PRECISION:
      ieee_flags ("set", "precision", "extended", out) ;
      break ;
    default:
      ieee_flags ("set", "precision", "extended", out) ;
    }

  switch (rounding)
    {
    case GSL_IEEE_ROUND_TO_NEAREST:
      ieee_flags ("set", "direction", "nearest", out) ;
      break ;
    case GSL_IEEE_ROUND_DOWN:
      ieee_flags ("set", "direction", "negative", out) ;
      break ;
    case GSL_IEEE_ROUND_UP:
      ieee_flags ("set", "direction", "positive", out) ;
      break ;
    case GSL_IEEE_ROUND_TO_ZERO:
      ieee_flags ("set", "direction", "tozero", out) ;
      break ;
    default:
      ieee_flags ("set", "direction", "nearest", out) ;
    }

  if (exception_mask & GSL_IEEE_MASK_INVALID)
    {
      ieee_handler ("set", "invalid", SIGFPE_IGNORE) ;
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  else 
=======
  else
>>>>>>> config
    {
      ieee_handler ("set", "invalid", SIGFPE_ABORT) ;
    }

  if (exception_mask & GSL_IEEE_MASK_DENORMALIZED)
    {
      ieee_handler ("set", "denormalized", SIGFPE_IGNORE) ;
    }
  else
    {
      GSL_ERROR ("sunos4 does not support the denormalized operand exception. "
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 "Use 'mask-denormalized' to work around this.",
                 GSL_EUNSUP) ;
=======
		 "Use 'mask-denormalized' to work around this.",
		 GSL_EUNSUP) ;
>>>>>>> config
    }


  if (exception_mask & GSL_IEEE_MASK_DIVISION_BY_ZERO)
    {
      ieee_handler ("set", "division", SIGFPE_IGNORE) ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
    } 
=======
    }
>>>>>>> config
  else
    {
      ieee_handler ("set", "division", SIGFPE_ABORT) ;
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (exception_mask & GSL_IEEE_MASK_OVERFLOW)
    {
      ieee_handler ("set", "overflow", SIGFPE_IGNORE) ;
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  else 
=======
  else
>>>>>>> config
    {
      ieee_handler ("set", "overflow", SIGFPE_ABORT) ;
    }

  if (exception_mask & GSL_IEEE_MASK_UNDERFLOW)
    {
      ieee_handler ("set", "underflow", SIGFPE_IGNORE) ;
    }
  else
    {
      ieee_handler ("set", "underflow", SIGFPE_ABORT) ;
    }

  if (exception_mask & GSL_IEEE_TRAP_INEXACT)
    {
      ieee_handler ("set", "inexact", SIGFPE_ABORT) ;
    }
  else
    {
      ieee_handler ("set", "inexact", SIGFPE_IGNORE) ;
    }

  return GSL_SUCCESS ;
}
