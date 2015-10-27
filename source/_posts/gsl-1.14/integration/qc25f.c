/* integration/qc25f.c
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

struct fn_fourier_params
{
  gsl_function *function;
  double omega;
};

static double fn_sin (double t, void *params);
static double fn_cos (double t, void *params);

static void
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
qc25f (gsl_function * f, double a, double b, 
=======
qc25f (gsl_function * f, double a, double b,
>>>>>>> config
       gsl_integration_qawo_table * wf, size_t level,
       double *result, double *abserr, double *resabs, double *resasc);

static void
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
qc25f (gsl_function * f, double a, double b, 
=======
qc25f (gsl_function * f, double a, double b,
>>>>>>> config
       gsl_integration_qawo_table * wf, size_t level,
       double *result, double *abserr, double *resabs, double *resasc)
{
  const double center = 0.5 * (a + b);
  const double half_length = 0.5 * (b - a);
  const double omega = wf->omega ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  const double par = omega * half_length;

  if (fabs (par) < 2)
    {
      gsl_function weighted_function;
      struct fn_fourier_params fn_params;

      fn_params.function = f;
      fn_params.omega = omega;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
      if (wf->sine == GSL_INTEG_SINE) 
        {
          weighted_function.function = &fn_sin;
        }
      else
        {
          weighted_function.function = &fn_cos;
        }
=======
      if (wf->sine == GSL_INTEG_SINE)
	{
	  weighted_function.function = &fn_sin;
	}
      else
	{
	  weighted_function.function = &fn_cos;
	}
>>>>>>> config

      weighted_function.params = &fn_params;

      gsl_integration_qk15 (&weighted_function, a, b, result, abserr,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                            resabs, resasc);
      
=======
			    resabs, resasc);

>>>>>>> config
      return;
    }
  else
    {
      double *moment;
      double cheb12[13], cheb24[25];
      double result_abs, res12_cos, res12_sin, res24_cos, res24_sin;
      double est_cos, est_sin;
      double c, s;
      size_t i;

      gsl_integration_qcheb (f, a, b, cheb12, cheb24);

      if (level >= wf->n)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          /* table overflow should not happen, check before calling */
          GSL_ERROR_VOID("table overflow in internal function", GSL_ESANITY);
        }
=======
	{
	  /* table overflow should not happen, check before calling */
	  GSL_ERROR_VOID("table overflow in internal function", GSL_ESANITY);
	}
>>>>>>> config

      /* obtain moments from the table */

      moment = wf->chebmo + 25 * level;

      res12_cos = cheb12[12] * moment[12];
      res12_sin = 0 ;

      for (i = 0; i < 6; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          size_t k = 10 - 2 * i;
          res12_cos += cheb12[k] * moment[k];
          res12_sin += cheb12[k + 1] * moment[k + 1];
        }
=======
	{
	  size_t k = 10 - 2 * i;
	  res12_cos += cheb12[k] * moment[k];
	  res12_sin += cheb12[k + 1] * moment[k + 1];
	}
>>>>>>> config

      res24_cos = cheb24[24] * moment[24];
      res24_sin = 0 ;

      result_abs = fabs(cheb24[24]) ;

      for (i = 0; i < 12; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          size_t k = 22 - 2 * i;
          res24_cos += cheb24[k] * moment[k];
          res24_sin += cheb24[k + 1] * moment[k + 1];
          result_abs += fabs(cheb24[k]) + fabs(cheb24[k+1]);
        }
=======
	{
	  size_t k = 22 - 2 * i;
	  res24_cos += cheb24[k] * moment[k];
	  res24_sin += cheb24[k + 1] * moment[k + 1];
	  result_abs += fabs(cheb24[k]) + fabs(cheb24[k+1]);
	}
>>>>>>> config

      est_cos = fabs(res24_cos - res12_cos);
      est_sin = fabs(res24_sin - res12_sin);

      c = half_length * cos(center * omega);
      s = half_length * sin(center * omega);

      if (wf->sine == GSL_INTEG_SINE)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          *result = c * res24_sin + s * res24_cos;
          *abserr = fabs(c * est_sin) + fabs(s * est_cos);
        }
      else
        {
          *result = c * res24_cos - s * res24_sin;
          *abserr = fabs(c * est_cos) + fabs(s * est_sin);
        }
      
=======
	{
	  *result = c * res24_sin + s * res24_cos;
	  *abserr = fabs(c * est_sin) + fabs(s * est_cos);
	}
      else
	{
	  *result = c * res24_cos - s * res24_sin;
	  *abserr = fabs(c * est_cos) + fabs(s * est_sin);
	}

>>>>>>> config
      *resabs = result_abs * half_length;
      *resasc = GSL_DBL_MAX;

      return;
    }
}

static double
fn_sin (double x, void *params)
{
  struct fn_fourier_params *p = (struct fn_fourier_params *) params;
  gsl_function *f = p->function;
  double w = p->omega;
  double wx = w * x;
  double sinwx = sin(wx) ;
  return GSL_FN_EVAL (f, x) * sinwx;
}

static double
fn_cos (double x, void *params)
{
  struct fn_fourier_params *p = (struct fn_fourier_params *) params;
  gsl_function *f = p->function;
  double w = p->omega;
  double wx = w * x;
  double coswx = cos(wx) ;
  return GSL_FN_EVAL (f, x) * coswx ;
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8

=======
>>>>>>> config
