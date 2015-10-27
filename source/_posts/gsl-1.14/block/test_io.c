/* block/test_io.c
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

void FUNCTION (test, text) (void);

void
FUNCTION (test, text) (void)
{
  size_t i;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  {
    TYPE (gsl_block) * v = FUNCTION (gsl_block, calloc) (N);

    FILE *f = fopen ("test.txt", "w");

    for (i = 0; i < N; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        v->data[i] = (ATOMIC) i;
=======
	v->data[i] = (ATOMIC) i;
>>>>>>> config
      };

    FUNCTION (gsl_block, fprintf) (f, v, OUT_FORMAT);

    fclose (f);

    FUNCTION (gsl_block, free) (v);
  }

  {
    TYPE (gsl_block) * w = FUNCTION (gsl_block, calloc) (N);

    FILE *f = fopen ("test.txt", "r");

    FUNCTION (gsl_block, fscanf) (f, w);

    status = 0;
    for (i = 0; i < N; i++)
      {
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        if (w->data[i] != (ATOMIC) i)
          status = 1;
=======
	if (w->data[i] != (ATOMIC) i)
	  status = 1;
>>>>>>> config
      };

    gsl_test (status, NAME (gsl_block) "_fprintf and fscanf");

    fclose (f);

    FUNCTION (gsl_block, free) (w);
  }
}
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8


=======
>>>>>>> config
