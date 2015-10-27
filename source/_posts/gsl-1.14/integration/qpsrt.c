/* integration/qpsrt.c
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

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
static inline void 
=======
static inline void
>>>>>>> config
qpsrt (gsl_integration_workspace * workspace);

static inline
void qpsrt (gsl_integration_workspace * workspace)
{
  const size_t last = workspace->size - 1;
  const size_t limit = workspace->limit;

  double * elist = workspace->elist;
  size_t * order = workspace->order;

  double errmax ;
  double errmin ;
  int i, k, top;

  size_t i_nrmax = workspace->nrmax;
  size_t i_maxerr = order[i_nrmax] ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  /* Check whether the list contains more than two error estimates */

  if (last < 2) 
=======

  /* Check whether the list contains more than two error estimates */

  if (last < 2)
>>>>>>> config
    {
      order[0] = 0 ;
      order[1] = 1 ;
      workspace->i = i_maxerr ;
      return ;
    }

  errmax = elist[i_maxerr] ;

  /* This part of the routine is only executed if, due to a difficult
     integrand, subdivision increased the error estimate. In the normal
     case the insert procedure should start after the nrmax-th largest
     error estimate. */

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  while (i_nrmax > 0 && errmax > elist[order[i_nrmax - 1]]) 
    {
      order[i_nrmax] = order[i_nrmax - 1] ;
      i_nrmax-- ;
    } 
=======
  while (i_nrmax > 0 && errmax > elist[order[i_nrmax - 1]])
    {
      order[i_nrmax] = order[i_nrmax - 1] ;
      i_nrmax-- ;
    }
>>>>>>> config

  /* Compute the number of elements in the list to be maintained in
     descending order. This number depends on the number of
     subdivisions still allowed. */
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  if(last < (limit/2 + 2)) 
=======

  if(last < (limit/2 + 2))
>>>>>>> config
    {
      top = last ;
    }
  else
    {
      top = limit - last + 1;
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  /* Insert errmax by traversing the list top-down, starting
     comparison from the element elist(order(i_nrmax+1)). */
  
  i = i_nrmax + 1 ;
  
=======

  /* Insert errmax by traversing the list top-down, starting
     comparison from the element elist(order(i_nrmax+1)). */

  i = i_nrmax + 1 ;

>>>>>>> config
  /* The order of the tests in the following line is important to
     prevent a segmentation fault */

  while (i < top && errmax < elist[order[i]])
    {
      order[i-1] = order[i] ;
      i++ ;
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  order[i-1] = i_maxerr ;
  
  /* Insert errmin by traversing the list bottom-up */
  
  errmin = elist[last] ;
  
  k = top - 1 ;
  
=======

  order[i-1] = i_maxerr ;

  /* Insert errmin by traversing the list bottom-up */

  errmin = elist[last] ;

  k = top - 1 ;

>>>>>>> config
  while (k > i - 2 && errmin >= elist[order[k]])
    {
      order[k+1] = order[k] ;
      k-- ;
    }
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  order[k+1] = last ;

  /* Set i_max and e_max */

  i_maxerr = order[i_nrmax] ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
  workspace->i = i_maxerr ;
  workspace->nrmax = i_nrmax ;
}


=======

  workspace->i = i_maxerr ;
  workspace->nrmax = i_nrmax ;
}
>>>>>>> config
