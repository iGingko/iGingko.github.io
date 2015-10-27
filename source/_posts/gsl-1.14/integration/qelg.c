/* integration/qelg.c
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

struct extrapolation_table
  {
    size_t n;
    double rlist2[52];
    size_t nres;
    double res3la[3];
  };

static void
  initialise_table (struct extrapolation_table *table);

static void
  append_table (struct extrapolation_table *table, double y);

static void
initialise_table (struct extrapolation_table *table)
{
  table->n = 0;
  table->nres = 0;
}
#ifdef JUNK
static void
initialise_table (struct extrapolation_table *table, double y)
{
  table->n = 0;
  table->rlist2[0] = y;
  table->nres = 0;
}
#endif
static void
append_table (struct extrapolation_table *table, double y)
{
  size_t n;
  n = table->n;
  table->rlist2[n] = y;
  table->n++;
}

/* static inline void
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
   qelg (size_t * n, double epstab[], 
   double * result, double * abserr, 
=======
   qelg (size_t * n, double epstab[],
   double * result, double * abserr,
>>>>>>> config
   double res3la[], size_t * nres); */

static inline void
  qelg (struct extrapolation_table *table, double *result, double *abserr);

static inline void
qelg (struct extrapolation_table *table, double *result, double *abserr)
{
  double *epstab = table->rlist2;
  double *res3la = table->res3la;
  const size_t n = table->n - 1;

  const double current = epstab[n];

  double absolute = GSL_DBL_MAX;
  double relative = 5 * GSL_DBL_EPSILON * fabs (current);

  const size_t newelm = n / 2;
  const size_t n_orig = n;
  size_t n_final = n;
  size_t i;

  const size_t nres_orig = table->nres;

  *result = current;
  *abserr = GSL_DBL_MAX;

  if (n < 2)
    {
      *result = current;
      *abserr = GSL_MAX_DBL (absolute, relative);
      return;
    }

  epstab[n + 2] = epstab[n];
  epstab[n] = GSL_DBL_MAX;

  for (i = 0; i < newelm; i++)
    {
      double res = epstab[n - 2 * i + 2];
      double e0 = epstab[n - 2 * i - 2];
      double e1 = epstab[n - 2 * i - 1];
      double e2 = res;

      double e1abs = fabs (e1);
      double delta2 = e2 - e1;
      double err2 = fabs (delta2);
      double tol2 = GSL_MAX_DBL (fabs (e2), e1abs) * GSL_DBL_EPSILON;
      double delta3 = e1 - e0;
      double err3 = fabs (delta3);
      double tol3 = GSL_MAX_DBL (e1abs, fabs (e0)) * GSL_DBL_EPSILON;

      double e3, delta1, err1, tol1, ss;

      if (err2 <= tol2 && err3 <= tol3)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          /* If e0, e1 and e2 are equal to within machine accuracy,
             convergence is assumed.  */

          *result = res;
          absolute = err2 + err3;
          relative = 5 * GSL_DBL_EPSILON * fabs (res);
          *abserr = GSL_MAX_DBL (absolute, relative);
          return;
        }
=======
	{
	  /* If e0, e1 and e2 are equal to within machine accuracy,
	     convergence is assumed.  */

	  *result = res;
	  absolute = err2 + err3;
	  relative = 5 * GSL_DBL_EPSILON * fabs (res);
	  *abserr = GSL_MAX_DBL (absolute, relative);
	  return;
	}
>>>>>>> config

      e3 = epstab[n - 2 * i];
      epstab[n - 2 * i] = e1;
      delta1 = e1 - e3;
      err1 = fabs (delta1);
      tol1 = GSL_MAX_DBL (e1abs, fabs (e3)) * GSL_DBL_EPSILON;

      /* If two elements are very close to each other, omit a part of
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
         the table by adjusting the value of n */

      if (err1 <= tol1 || err2 <= tol2 || err3 <= tol3)
        {
          n_final = 2 * i;
          break;
        }
=======
	 the table by adjusting the value of n */

      if (err1 <= tol1 || err2 <= tol2 || err3 <= tol3)
	{
	  n_final = 2 * i;
	  break;
	}
>>>>>>> config

      ss = (1 / delta1 + 1 / delta2) - 1 / delta3;

      /* Test to detect irregular behaviour in the table, and
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
         eventually omit a part of the table by adjusting the value of
         n. */

      if (fabs (ss * e1) <= 0.0001)
        {
          n_final = 2 * i;
          break;
        }

      /* Compute a new element and eventually adjust the value of
         result. */
=======
	 eventually omit a part of the table by adjusting the value of
	 n. */

      if (fabs (ss * e1) <= 0.0001)
	{
	  n_final = 2 * i;
	  break;
	}

      /* Compute a new element and eventually adjust the value of
	 result. */
>>>>>>> config

      res = e1 + 1 / ss;
      epstab[n - 2 * i] = res;

      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        const double error = err2 + fabs (res - e2) + err3;

        if (error <= *abserr)
          {
            *abserr = error;
            *result = res;
          }
=======
	const double error = err2 + fabs (res - e2) + err3;

	if (error <= *abserr)
	  {
	    *abserr = error;
	    *result = res;
	  }
>>>>>>> config
      }
    }

  /* Shift the table */

  {
    const size_t limexp = 50 - 1;

    if (n_final == limexp)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        n_final = 2 * (limexp / 2);
=======
	n_final = 2 * (limexp / 2);
>>>>>>> config
      }
  }

  if (n_orig % 2 == 1)
    {
      for (i = 0; i <= newelm; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          epstab[1 + i * 2] = epstab[i * 2 + 3];
        }
=======
	{
	  epstab[1 + i * 2] = epstab[i * 2 + 3];
	}
>>>>>>> config
    }
  else
    {
      for (i = 0; i <= newelm; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          epstab[i * 2] = epstab[i * 2 + 2];
        }
=======
	{
	  epstab[i * 2] = epstab[i * 2 + 2];
	}
>>>>>>> config
    }

  if (n_orig != n_final)
    {
      for (i = 0; i <= n_final; i++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          epstab[i] = epstab[n_orig - n_final + i];
        }
=======
	{
	  epstab[i] = epstab[n_orig - n_final + i];
	}
>>>>>>> config
    }

  table->n = n_final + 1;

  if (nres_orig < 3)
    {
      res3la[nres_orig] = *result;
      *abserr = GSL_DBL_MAX;
    }
  else
    {                           /* Compute error estimate */
      *abserr = (fabs (*result - res3la[2]) + fabs (*result - res3la[1])
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                 + fabs (*result - res3la[0]));
=======
		 + fabs (*result - res3la[0]));
>>>>>>> config

      res3la[0] = res3la[1];
      res3la[1] = res3la[2];
      res3la[2] = *result;
    }

  /* In QUADPACK the variable table->nres is incremented at the top of
     qelg, so it increases on every call. This leads to the array
     res3la being accessed when its elements are still undefined, so I
     have moved the update to this point so that its value more
     useful. */

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  table->nres = nres_orig + 1;  
=======
  table->nres = nres_orig + 1;
>>>>>>> config

  *abserr = GSL_MAX_DBL (*abserr, 5 * GSL_DBL_EPSILON * fabs (*result));

  return;
}
