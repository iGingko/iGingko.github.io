/* specfunc/mathieu_angfunc.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 2002 Lowell Johnson
 * 
=======
 *
 * Copyright (C) 2002 Lowell Johnson
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
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* Author:  L. Johnson */

#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf_mathieu.h>


int gsl_sf_mathieu_ce(int order, double qq, double zz, gsl_sf_result *result)
{
  int even_odd, ii, status;
  double coeff[GSL_SF_MATHIEU_COEFF], norm, fn, factor;
  gsl_sf_result aa;


  norm = 0.0;
  even_odd = 0;
  if (order % 2 != 0)
      even_odd = 1;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  /* Handle the trivial case where q = 0. */
  if (qq == 0.0)
  {
      norm = 1.0;
      if (order == 0)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          norm = sqrt(2.0);

      fn = cos(order*zz)/norm;
      
=======
	  norm = sqrt(2.0);

      fn = cos(order*zz)/norm;

>>>>>>> config
      result->val = fn;
      result->err = 2.0*GSL_DBL_EPSILON;
      factor = fabs(fn);
      if (factor > 1.0)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          result->err *= factor;
      
      return GSL_SUCCESS;
  }
  
=======
	  result->err *= factor;

      return GSL_SUCCESS;
  }

>>>>>>> config
  /* Use symmetry characteristics of the functions to handle cases with
     negative order. */
  if (order < 0)
      order *= -1;

  /* Compute the characteristic value. */
  status = gsl_sf_mathieu_a(order, qq, &aa);
  if (status != GSL_SUCCESS)
  {
      return status;
  }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  /* Compute the series coefficients. */
  status = gsl_sf_mathieu_a_coeff(order, qq, aa.val, coeff);
  if (status != GSL_SUCCESS)
  {
      return status;
  }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (even_odd == 0)
  {
      fn = 0.0;
      norm = coeff[0]*coeff[0];
      for (ii=0; ii<GSL_SF_MATHIEU_COEFF; ii++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          fn += coeff[ii]*cos(2.0*ii*zz);
          norm += coeff[ii]*coeff[ii];
=======
	  fn += coeff[ii]*cos(2.0*ii*zz);
	  norm += coeff[ii]*coeff[ii];
>>>>>>> config
      }
  }
  else
  {
      fn = 0.0;
      for (ii=0; ii<GSL_SF_MATHIEU_COEFF; ii++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          fn += coeff[ii]*cos((2.0*ii + 1.0)*zz);
          norm += coeff[ii]*coeff[ii];
      }
  }
  
=======
	  fn += coeff[ii]*cos((2.0*ii + 1.0)*zz);
	  norm += coeff[ii]*coeff[ii];
      }
  }

>>>>>>> config
  norm = sqrt(norm);
  fn /= norm;

  result->val = fn;
  result->err = 2.0*GSL_DBL_EPSILON;
  factor = fabs(fn);
  if (factor > 1.0)
      result->err *= factor;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  return GSL_SUCCESS;
}


int gsl_sf_mathieu_se(int order, double qq, double zz, gsl_sf_result *result)
{
  int even_odd, ii, status;
  double coeff[GSL_SF_MATHIEU_COEFF], norm, fn, factor;
  gsl_sf_result aa;


  norm = 0.0;
  even_odd = 0;
  if (order % 2 != 0)
      even_odd = 1;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  /* Handle the trivial cases where order = 0 and/or q = 0. */
  if (order == 0)
  {
      result->val = 0.0;
      result->err = 0.0;
      return GSL_SUCCESS;
  }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (qq == 0.0)
  {
      norm = 1.0;
      fn = sin(order*zz);
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      
=======

>>>>>>> config
      result->val = fn;
      result->err = 2.0*GSL_DBL_EPSILON;
      factor = fabs(fn);
      if (factor > 1.0)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          result->err *= factor;
      
      return GSL_SUCCESS;
  }
  
=======
	  result->err *= factor;

      return GSL_SUCCESS;
  }

>>>>>>> config
  /* Use symmetry characteristics of the functions to handle cases with
     negative order. */
  if (order < 0)
      order *= -1;

  /* Compute the characteristic value. */
  status = gsl_sf_mathieu_b(order, qq, &aa);
  if (status != GSL_SUCCESS)
  {
      return status;
  }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  /* Compute the series coefficients. */
  status = gsl_sf_mathieu_b_coeff(order, qq, aa.val, coeff);
  if (status != GSL_SUCCESS)
  {
      return status;
  }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (even_odd == 0)
  {
      fn = 0.0;
      for (ii=0; ii<GSL_SF_MATHIEU_COEFF; ii++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          norm += coeff[ii]*coeff[ii];
          fn += coeff[ii]*sin(2.0*(ii + 1)*zz);
=======
	  norm += coeff[ii]*coeff[ii];
	  fn += coeff[ii]*sin(2.0*(ii + 1)*zz);
>>>>>>> config
      }
  }
  else
  {
      fn = 0.0;
      for (ii=0; ii<GSL_SF_MATHIEU_COEFF; ii++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          norm += coeff[ii]*coeff[ii];
          fn += coeff[ii]*sin((2.0*ii + 1)*zz);
=======
	  norm += coeff[ii]*coeff[ii];
	  fn += coeff[ii]*sin((2.0*ii + 1)*zz);
>>>>>>> config
      }
  }
  norm = sqrt(norm);
  fn /= norm;

  result->val = fn;
  result->err = 2.0*GSL_DBL_EPSILON;
  factor = fabs(fn);
  if (factor > 1.0)
      result->err *= factor;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  return GSL_SUCCESS;
}


int gsl_sf_mathieu_ce_array(int nmin, int nmax, double qq, double zz,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                            gsl_sf_mathieu_workspace *work,
                            double result_array[])
{
  int even_odd, order, ii, jj, status;
  double coeff[GSL_SF_MATHIEU_COEFF], *aa = work->aa, norm;
  
=======
			    gsl_sf_mathieu_workspace *work,
			    double result_array[])
{
  int even_odd, order, ii, jj, status;
  double coeff[GSL_SF_MATHIEU_COEFF], *aa = work->aa, norm;

>>>>>>> config

  /* Initialize the result array to zeroes. */
  for (ii=0; ii<nmax-nmin+1; ii++)
      result_array[ii] = 0.0;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  /* Ensure that the workspace is large enough to accomodate. */
  if (work->size < (unsigned int)nmax)
  {
      GSL_ERROR("Work space not large enough", GSL_EINVAL);
  }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (nmin < 0 || nmax < nmin)
  {
      GSL_ERROR("domain error", GSL_EDOM);
  }

  /* Compute all of the eigenvalues up to nmax. */
  gsl_sf_mathieu_a_array(0, nmax, qq, work, aa);

  for (ii=0, order=nmin; order<=nmax; ii++, order++)
  {
      norm = 0.0;
      even_odd = 0;
      if (order % 2 != 0)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          even_odd = 1;
  
      /* Handle the trivial case where q = 0. */
      if (qq == 0.0)
      {
          norm = 1.0;
          if (order == 0)
              norm = sqrt(2.0);

          result_array[ii] = cos(order*zz)/norm;

          continue;
      }
  
      /* Compute the series coefficients. */
      status = gsl_sf_mathieu_a_coeff(order, qq, aa[order], coeff);
      if (status != GSL_SUCCESS)
          return status;
  
      if (even_odd == 0)
      {
          norm = coeff[0]*coeff[0];
          for (jj=0; jj<GSL_SF_MATHIEU_COEFF; jj++)
          {
              result_array[ii] += coeff[jj]*cos(2.0*jj*zz);
              norm += coeff[jj]*coeff[jj];
          }
      }
      else
      {
          for (jj=0; jj<GSL_SF_MATHIEU_COEFF; jj++)
          {
              result_array[ii] += coeff[jj]*cos((2.0*jj + 1.0)*zz);
              norm += coeff[jj]*coeff[jj];
          }
      }
  
=======
	  even_odd = 1;

      /* Handle the trivial case where q = 0. */
      if (qq == 0.0)
      {
	  norm = 1.0;
	  if (order == 0)
	      norm = sqrt(2.0);

	  result_array[ii] = cos(order*zz)/norm;

	  continue;
      }

      /* Compute the series coefficients. */
      status = gsl_sf_mathieu_a_coeff(order, qq, aa[order], coeff);
      if (status != GSL_SUCCESS)
	  return status;

      if (even_odd == 0)
      {
	  norm = coeff[0]*coeff[0];
	  for (jj=0; jj<GSL_SF_MATHIEU_COEFF; jj++)
	  {
	      result_array[ii] += coeff[jj]*cos(2.0*jj*zz);
	      norm += coeff[jj]*coeff[jj];
	  }
      }
      else
      {
	  for (jj=0; jj<GSL_SF_MATHIEU_COEFF; jj++)
	  {
	      result_array[ii] += coeff[jj]*cos((2.0*jj + 1.0)*zz);
	      norm += coeff[jj]*coeff[jj];
	  }
      }

>>>>>>> config
      norm = sqrt(norm);
      result_array[ii] /= norm;
  }

  return GSL_SUCCESS;
}


int gsl_sf_mathieu_se_array(int nmin, int nmax, double qq, double zz,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                            gsl_sf_mathieu_workspace *work,
                            double result_array[])
{
  int even_odd, order, ii, jj, status;
  double coeff[GSL_SF_MATHIEU_COEFF], *bb = work->bb, norm;
  
=======
			    gsl_sf_mathieu_workspace *work,
			    double result_array[])
{
  int even_odd, order, ii, jj, status;
  double coeff[GSL_SF_MATHIEU_COEFF], *bb = work->bb, norm;

>>>>>>> config

  /* Initialize the result array to zeroes. */
  for (ii=0; ii<nmax-nmin+1; ii++)
      result_array[ii] = 0.0;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  /* Ensure that the workspace is large enough to accomodate. */
  if (work->size < (unsigned int)nmax)
  {
      GSL_ERROR("Work space not large enough", GSL_EINVAL);
  }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  if (nmin < 0 || nmax < nmin)
  {
      GSL_ERROR("domain error", GSL_EDOM);
  }

  /* Compute all of the eigenvalues up to nmax. */
  gsl_sf_mathieu_b_array(0, nmax, qq, work, bb);

  for (ii=0, order=nmin; order<=nmax; ii++, order++)
  {
      norm = 0.0;
      even_odd = 0;
      if (order % 2 != 0)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          even_odd = 1;
  
      /* Handle the trivial case where q = 0. */
      if (qq == 0.0)
      {
          norm = 1.0;
          result_array[ii] = sin(order*zz);

          continue;
      }
  
=======
	  even_odd = 1;

      /* Handle the trivial case where q = 0. */
      if (qq == 0.0)
      {
	  norm = 1.0;
	  result_array[ii] = sin(order*zz);

	  continue;
      }

>>>>>>> config
      /* Compute the series coefficients. */
      status = gsl_sf_mathieu_b_coeff(order, qq, bb[order], coeff);
      if (status != GSL_SUCCESS)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          return status;
      }
  
      if (even_odd == 0)
      {
          for (jj=0; jj<GSL_SF_MATHIEU_COEFF; jj++)
          {
              result_array[ii] += coeff[jj]*sin(2.0*(jj + 1)*zz);
              norm += coeff[jj]*coeff[jj];
          }
      }
      else
      {
          for (jj=0; jj<GSL_SF_MATHIEU_COEFF; jj++)
          {
              result_array[ii] += coeff[jj]*sin((2.0*jj + 1.0)*zz);
              norm += coeff[jj]*coeff[jj];
          }
      }
  
=======
	  return status;
      }

      if (even_odd == 0)
      {
	  for (jj=0; jj<GSL_SF_MATHIEU_COEFF; jj++)
	  {
	      result_array[ii] += coeff[jj]*sin(2.0*(jj + 1)*zz);
	      norm += coeff[jj]*coeff[jj];
	  }
      }
      else
      {
	  for (jj=0; jj<GSL_SF_MATHIEU_COEFF; jj++)
	  {
	      result_array[ii] += coeff[jj]*sin((2.0*jj + 1.0)*zz);
	      norm += coeff[jj]*coeff[jj];
	  }
      }

>>>>>>> config
      norm = sqrt(norm);
      result_array[ii] /= norm;
  }

  return GSL_SUCCESS;
}
