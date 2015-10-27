/* matrix/prop_source.c
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

int
FUNCTION (gsl_matrix, isnull) (const TYPE (gsl_matrix) * m)
{
  const size_t size1 = m->size1;
  const size_t size2 = m->size2;
  const size_t tda = m->tda ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  size_t i, j, k;

  for (i = 0; i < size1 ; i++)
    {
      for (j = 0; j < size2; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          for (k = 0; k < MULTIPLICITY; k++) 
            {
              if (m->data[(i * tda + j) * MULTIPLICITY + k] != 0.0)
                {
                  return 0;
                }
            }
        }
    }
      
=======
	{
	  for (k = 0; k < MULTIPLICITY; k++)
	    {
	      if (m->data[(i * tda + j) * MULTIPLICITY + k] != 0.0)
		{
		  return 0;
		}
	    }
	}
    }

>>>>>>> config
  return 1;
}


int
FUNCTION (gsl_matrix, ispos) (const TYPE (gsl_matrix) * m)
{
  const size_t size1 = m->size1;
  const size_t size2 = m->size2;
  const size_t tda = m->tda ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  size_t i, j, k;

  for (i = 0; i < size1 ; i++)
    {
      for (j = 0; j < size2; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          for (k = 0; k < MULTIPLICITY; k++) 
            {
              if (m->data[(i * tda + j) * MULTIPLICITY + k] <= 0.0)
                {
                  return 0;
                }
            }
        }
    }
      
=======
	{
	  for (k = 0; k < MULTIPLICITY; k++)
	    {
	      if (m->data[(i * tda + j) * MULTIPLICITY + k] <= 0.0)
		{
		  return 0;
		}
	    }
	}
    }

>>>>>>> config
  return 1;
}


int
FUNCTION (gsl_matrix, isneg) (const TYPE (gsl_matrix) * m)
{
  const size_t size1 = m->size1;
  const size_t size2 = m->size2;
  const size_t tda = m->tda ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  size_t i, j, k;

  for (i = 0; i < size1 ; i++)
    {
      for (j = 0; j < size2; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          for (k = 0; k < MULTIPLICITY; k++) 
            {
              if (m->data[(i * tda + j) * MULTIPLICITY + k] >= 0.0)
                {
                  return 0;
                }
            }
        }
    }
      
=======
	{
	  for (k = 0; k < MULTIPLICITY; k++)
	    {
	      if (m->data[(i * tda + j) * MULTIPLICITY + k] >= 0.0)
		{
		  return 0;
		}
	    }
	}
    }

>>>>>>> config
  return 1;
}


int
FUNCTION (gsl_matrix, isnonneg) (const TYPE (gsl_matrix) * m)
{
  const size_t size1 = m->size1;
  const size_t size2 = m->size2;
  const size_t tda = m->tda ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  size_t i, j, k;

  for (i = 0; i < size1 ; i++)
    {
      for (j = 0; j < size2; j++)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          for (k = 0; k < MULTIPLICITY; k++) 
            {
              if (m->data[(i * tda + j) * MULTIPLICITY + k] < 0.0)
                {
                  return 0;
                }
            }
        }
    }
      
=======
	{
	  for (k = 0; k < MULTIPLICITY; k++)
	    {
	      if (m->data[(i * tda + j) * MULTIPLICITY + k] < 0.0)
		{
		  return 0;
		}
	    }
	}
    }

>>>>>>> config
  return 1;
}
