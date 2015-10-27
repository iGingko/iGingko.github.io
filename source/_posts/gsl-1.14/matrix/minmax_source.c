/* matrix/minmax_source.c
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
 * 
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Gerard Jungman, Brian Gough
 * 
=======
 *
 * Copyright (C) 1996, 1997, 1998, 1999, 2000, 2007 Gerard Jungman, Brian Gough
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

BASE
FUNCTION (gsl_matrix, max) (const TYPE (gsl_matrix) * m)
{
  /* finds the largest element of a matrix */

  const size_t M = m->size1;
  const size_t N = m->size2;
  const size_t tda = m->tda;

  BASE max = m->data[0 * tda + 0];
  size_t i, j;

  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          BASE x = m->data[i * tda + j];
          if (x > max)
            max = x;
#ifdef FP
          if (isnan (x))
            return x;
#endif
        }
=======
	{
	  BASE x = m->data[i * tda + j];
	  if (x > max)
	    max = x;
#ifdef FP
	  if (isnan (x))
	    return x;
#endif
	}
>>>>>>> config
    }

  return max;
}

BASE
FUNCTION (gsl_matrix, min) (const TYPE (gsl_matrix) * m)
{
  /* finds the smallest element of a matrix */

  const size_t M = m->size1;
  const size_t N = m->size2;
  const size_t tda = m->tda;

  BASE min = m->data[0 * tda + 0];
  size_t i, j;

  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          BASE x = m->data[i * tda + j];
          if (x < min)
            min = x;
#ifdef FP
          if (isnan (x))
            return x;
#endif
        }
=======
	{
	  BASE x = m->data[i * tda + j];
	  if (x < min)
	    min = x;
#ifdef FP
	  if (isnan (x))
	    return x;
#endif
	}
>>>>>>> config
    }

  return min;
}


void
FUNCTION (gsl_matrix, minmax) (const TYPE (gsl_matrix) * m,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                               BASE * min_out,
                               BASE * max_out)
=======
			       BASE * min_out,
			       BASE * max_out)
>>>>>>> config
{
  /* finds the smallest and largest elements of a matrix */

  const size_t M = m->size1;
  const size_t N = m->size2;
  const size_t tda = m->tda;

  BASE max = m->data[0 * tda + 0];
  BASE min = m->data[0 * tda + 0];

  size_t i, j;

  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          BASE x = m->data[i * tda + j];
          if (x < min)
            {
              min = x;
            }
          if (x > max)
            {
              max = x;
            }
#ifdef FP
          if (isnan (x))
            {
              *min_out = x;
              *max_out = x;
              return;
            }
#endif
        }
=======
	{
	  BASE x = m->data[i * tda + j];
	  if (x < min)
	    {
	      min = x;
	    }
	  if (x > max)
	    {
	      max = x;
	    }
#ifdef FP
	  if (isnan (x))
	    {
	      *min_out = x;
	      *max_out = x;
	      return;
	    }
#endif
	}
>>>>>>> config
    }

  *min_out = min;
  *max_out = max;
}

void
FUNCTION (gsl_matrix, max_index) (const TYPE (gsl_matrix) * m, size_t * imax_out, size_t *jmax_out)
{
  /* finds the largest element of a matrix */

  const size_t M = m->size1;
  const size_t N = m->size2;
  const size_t tda = m->tda;

  BASE max = m->data[0 * tda + 0];
  size_t imax = 0, jmax = 0;
  size_t i, j;

  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          BASE x = m->data[i * tda + j];
          if (x > max)
            {
              max = x;
              imax = i;
              jmax = j;
            }
#ifdef FP
          if (isnan (x))
            {
              *imax_out = i;
              *jmax_out = j;
              return;
            }
#endif
        }
=======
	{
	  BASE x = m->data[i * tda + j];
	  if (x > max)
	    {
	      max = x;
	      imax = i;
	      jmax = j;
	    }
#ifdef FP
	  if (isnan (x))
	    {
	      *imax_out = i;
	      *jmax_out = j;
	      return;
	    }
#endif
	}
>>>>>>> config
    }

  *imax_out = imax;
  *jmax_out = jmax;
}

void
FUNCTION (gsl_matrix, min_index) (const TYPE (gsl_matrix) * m, size_t * imin_out, size_t *jmin_out)
{
  /* finds the largest element of a matrix */

  const size_t M = m->size1;
  const size_t N = m->size2;
  const size_t tda = m->tda;

  BASE min = m->data[0 * tda + 0];
  size_t imin = 0, jmin = 0;
  size_t i, j;

  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          BASE x = m->data[i * tda + j];
          if (x < min)
            {
              min = x;
              imin = i;
              jmin = j;
            }
#ifdef FP
          if (isnan (x))
            {
              *imin_out = i;
              *jmin_out = j;
              return;
            }
#endif
        }
=======
	{
	  BASE x = m->data[i * tda + j];
	  if (x < min)
	    {
	      min = x;
	      imin = i;
	      jmin = j;
	    }
#ifdef FP
	  if (isnan (x))
	    {
	      *imin_out = i;
	      *jmin_out = j;
	      return;
	    }
#endif
	}
>>>>>>> config
    }

  *imin_out = imin;
  *jmin_out = jmin;
}

void
FUNCTION (gsl_matrix, minmax_index) (const TYPE (gsl_matrix) * m,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
                                     size_t * imin_out,
                                     size_t * jmin_out,
                                     size_t * imax_out,
                                     size_t * jmax_out)
=======
				     size_t * imin_out,
				     size_t * jmin_out,
				     size_t * imax_out,
				     size_t * jmax_out)
>>>>>>> config
{
  /* finds the smallest and largest elements of a matrix */

  const size_t M = m->size1;
  const size_t N = m->size2;
  const size_t tda = m->tda;

  size_t imin = 0, jmin = 0, imax = 0, jmax = 0;
  BASE max = m->data[0 * tda + 0];
  BASE min = m->data[0 * tda + 0];

  size_t i, j;

  for (i = 0; i < M; i++)
    {
      for (j = 0; j < N; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          BASE x = m->data[i * tda + j];
          if (x < min)
            {
              min = x;
              imin = i;
              jmin = j;
            }
          if (x > max)
            {
              max = x;
              imax = i;
              jmax = j;
            }
#ifdef FP
          if (isnan (x))
            {
              *imin_out = i;
              *jmin_out = j;
              *imax_out = i;
              *jmax_out = j;
              return;
            }
#endif
        }
=======
	{
	  BASE x = m->data[i * tda + j];
	  if (x < min)
	    {
	      min = x;
	      imin = i;
	      jmin = j;
	    }
	  if (x > max)
	    {
	      max = x;
	      imax = i;
	      jmax = j;
	    }
#ifdef FP
	  if (isnan (x))
	    {
	      *imin_out = i;
	      *jmin_out = j;
	      *imax_out = i;
	      *jmax_out = j;
	      return;
	    }
#endif
	}
>>>>>>> config
    }

  *imin_out = imin;
  *jmin_out = jmin;
  *imax_out = imax;
  *jmax_out = jmax;
}
