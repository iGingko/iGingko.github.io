/* fp-netbsd.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2001 Jason Beegan
 * 
=======
 *
 * Copyright (C) 2001 Jason Beegan
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

#include <ieeefp.h>
#include <gsl/gsl_ieee_utils.h>
#include <gsl/gsl_errno.h>

int
gsl_ieee_set_mode (int precision, int rounding, int exception_mask)
{
  fp_except mode = 0;
  fp_rnd    rnd  = 0;

  switch (precision)
    {
    case GSL_IEEE_SINGLE_PRECISION:
      GSL_ERROR ("NetBSD only supports default precision rounding",
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 GSL_EUNSUP);
      break;
    case GSL_IEEE_DOUBLE_PRECISION:
      GSL_ERROR ("NetBSD only supports default precision rounding",
                 GSL_EUNSUP);
      break;
    case GSL_IEEE_EXTENDED_PRECISION:
      GSL_ERROR ("NetBSD only supports default precision rounding",
                 GSL_EUNSUP);
=======
		 GSL_EUNSUP);
      break;
    case GSL_IEEE_DOUBLE_PRECISION:
      GSL_ERROR ("NetBSD only supports default precision rounding",
		 GSL_EUNSUP);
      break;
    case GSL_IEEE_EXTENDED_PRECISION:
      GSL_ERROR ("NetBSD only supports default precision rounding",
		 GSL_EUNSUP);
>>>>>>> config
      break;
    }

  switch (rounding)
    {
    case GSL_IEEE_ROUND_TO_NEAREST:
      rnd = FP_RN;
      fpsetround (rnd);
      break;
    case GSL_IEEE_ROUND_DOWN:
      rnd = FP_RM;
      fpsetround (rnd);
      break;
    case GSL_IEEE_ROUND_UP:
      rnd = FP_RP;
      fpsetround (rnd);
      break;
    case GSL_IEEE_ROUND_TO_ZERO:
      rnd = FP_RZ;
      fpsetround (rnd);
      break;
    default:
      rnd = FP_RN;
      fpsetround (rnd);
    }

/* Turn on all available exceptions apart from 'inexact'.
   Denormalized operand exception not available on all platforms. */

  mode = FP_X_INV | FP_X_DZ | FP_X_OFL | FP_X_UFL;
#ifdef FP_X_DNML
  mode = mode | FP_X_DNML;
#endif

  if (exception_mask & GSL_IEEE_MASK_INVALID)
    mode &= ~ FP_X_INV;

  if (exception_mask & GSL_IEEE_MASK_DENORMALIZED)
    {
#ifdef FP_X_DNML
      mode &= ~ FP_X_DNML;
#endif
    }
  else
    {
#ifndef FP_X_DNML
      GSL_ERROR ("NetBSD does not support the denormalized operand exception on this platform. "
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 "Use 'mask-denormalized' to work around this.",
                 GSL_EUNSUP);
=======
		 "Use 'mask-denormalized' to work around this.",
		 GSL_EUNSUP);
>>>>>>> config
#endif
    }

  if (exception_mask & GSL_IEEE_MASK_DIVISION_BY_ZERO)
    mode &= ~ FP_X_DZ;

  if (exception_mask & GSL_IEEE_MASK_OVERFLOW)
    mode &= ~ FP_X_OFL;

  if (exception_mask & GSL_IEEE_MASK_UNDERFLOW)
    mode &=  ~ FP_X_UFL;

  if (exception_mask & GSL_IEEE_TRAP_INEXACT)
    {
      mode |= FP_X_IMP;
    }
  else
    {
      mode &= ~ FP_X_IMP;
    }

  fpsetmask (mode);

  return GSL_SUCCESS;

}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
