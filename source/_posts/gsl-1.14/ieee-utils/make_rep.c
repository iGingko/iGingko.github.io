/* ieee-utils/make_rep.c
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

#include <config.h>
#include <gsl/gsl_ieee_utils.h>

#include "endian.c"
#include "standardize.c"

static void sprint_nybble(int i, char *s) ;
static void sprint_byte(int i, char *s) ;
static int determine_ieee_type (int non_zero, int exponent, int max_exponent);


/* For the IEEE float format the bits are found from the following
   masks,
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
   
   sign      = 0x80000000  
   exponent  = 0x7f800000 
   mantisssa = 0x007fffff  

   For the IEEE double format the masks are,

   sign      = 0x8000000000000000  
   exponent  = 0x7ff0000000000000 
=======

   sign      = 0x80000000
   exponent  = 0x7f800000
   mantisssa = 0x007fffff

   For the IEEE double format the masks are,

   sign      = 0x8000000000000000
   exponent  = 0x7ff0000000000000
>>>>>>> config
   mantissa  = 0x000fffffffffffff

   */

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
void 
=======
void
>>>>>>> config
gsl_ieee_float_to_rep (const float * x, gsl_ieee_float_rep * r)
{
  int e, non_zero;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  union { 
    float f;
    struct  { 
      unsigned char byte[4] ;
    } ieee ;
  } u;
  
  u.f = *x ; 

  if (little_endian_p())
    make_float_bigendian(&(u.f)) ;
  
=======
  union {
    float f;
    struct  {
      unsigned char byte[4] ;
    } ieee ;
  } u;

  u.f = *x ;

  if (little_endian_p())
    make_float_bigendian(&(u.f)) ;

>>>>>>> config
  /* note that r->sign is signed, u.ieee.byte is unsigned */

  if (u.ieee.byte[3]>>7)
    {
      r->sign = 1 ;
    }
  else
    {
      r->sign = 0 ;
    }

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  e = (u.ieee.byte[3] & 0x7f) << 1 | (u.ieee.byte[2] & 0x80)>>7 ; 
  
=======
  e = (u.ieee.byte[3] & 0x7f) << 1 | (u.ieee.byte[2] & 0x80)>>7 ;

>>>>>>> config
  r->exponent = e - 127 ;

  sprint_byte((u.ieee.byte[2] & 0x7f) << 1,r->mantissa) ;
  sprint_byte(u.ieee.byte[1],r->mantissa + 7) ;
  sprint_byte(u.ieee.byte[0],r->mantissa + 15) ;

  r->mantissa[23] = '\0' ;

  non_zero = u.ieee.byte[0] || u.ieee.byte[1] || (u.ieee.byte[2] & 0x7f);

  r->type = determine_ieee_type (non_zero, e, 255) ;
}

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
void 
=======
void
>>>>>>> config
gsl_ieee_double_to_rep (const double * x, gsl_ieee_double_rep * r)
{

  int e, non_zero;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  union 
  { 
    double d;
    struct  { 
=======
  union
  {
    double d;
    struct  {
>>>>>>> config
      unsigned char byte[8];
    } ieee ;
  } u;

<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  u.d= *x ; 
  
  if (little_endian_p())
    make_double_bigendian(&(u.d)) ;
  
=======
  u.d= *x ;

  if (little_endian_p())
    make_double_bigendian(&(u.d)) ;

>>>>>>> config
  /* note that r->sign is signed, u.ieee.byte is unsigned */

  if (u.ieee.byte[7]>>7)
    {
      r->sign = 1 ;
    }
  else
    {
      r->sign = 0 ;
    }


  e =(u.ieee.byte[7] & 0x7f)<<4 ^ (u.ieee.byte[6] & 0xf0)>>4 ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  
=======

>>>>>>> config
  r->exponent = e - 1023 ;

  sprint_nybble(u.ieee.byte[6],r->mantissa) ;
  sprint_byte(u.ieee.byte[5],r->mantissa + 4) ;
  sprint_byte(u.ieee.byte[4],r->mantissa + 12) ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
  sprint_byte(u.ieee.byte[3],r->mantissa + 20) ; 
=======
  sprint_byte(u.ieee.byte[3],r->mantissa + 20) ;
>>>>>>> config
  sprint_byte(u.ieee.byte[2],r->mantissa + 28) ;
  sprint_byte(u.ieee.byte[1],r->mantissa + 36) ;
  sprint_byte(u.ieee.byte[0],r->mantissa + 44) ;

  r->mantissa[52] = '\0' ;

  non_zero = (u.ieee.byte[0] || u.ieee.byte[1] || u.ieee.byte[2]
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
              || u.ieee.byte[3] || u.ieee.byte[4] || u.ieee.byte[5] 
              || (u.ieee.byte[6] & 0x0f)) ;
=======
	      || u.ieee.byte[3] || u.ieee.byte[4] || u.ieee.byte[5]
	      || (u.ieee.byte[6] & 0x0f)) ;
>>>>>>> config

  r->type = determine_ieee_type (non_zero, e, 2047) ;
}

/* A table of character representations of nybbles */

static char nybble[16][5]={ /* include space for the \0 */
  "0000", "0001", "0010", "0011",
  "0100", "0101", "0110", "0111",
  "1000", "1001", "1010", "1011",
  "1100", "1101", "1110", "1111"
}  ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
          
=======

>>>>>>> config
static void
sprint_nybble(int i, char *s)
{
  char *c ;
  c=nybble[i & 0x0f ];
  *s=c[0] ;  *(s+1)=c[1] ;  *(s+2)=c[2] ;  *(s+3)=c[3] ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
} 
=======
}
>>>>>>> config

static void
sprint_byte(int i, char *s)
{
  char *c ;
  c=nybble[(i & 0xf0)>>4];
  *s=c[0] ;  *(s+1)=c[1] ;  *(s+2)=c[2] ;  *(s+3)=c[3] ;
  c=nybble[i & 0x0f];
  *(s+4)=c[0] ;  *(s+5)=c[1] ;  *(s+6)=c[2] ;  *(s+7)=c[3] ;
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
} 

static int 
=======
}

static int
>>>>>>> config
determine_ieee_type (int non_zero, int exponent, int max_exponent)
{
  if (exponent == max_exponent)
    {
      if (non_zero)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          return GSL_IEEE_TYPE_NAN ;
        }
      else
        {
          return GSL_IEEE_TYPE_INF ;
        }
=======
	{
	  return GSL_IEEE_TYPE_NAN ;
	}
      else
	{
	  return GSL_IEEE_TYPE_INF ;
	}
>>>>>>> config
    }
  else if (exponent == 0)
    {
      if (non_zero)
<<<<<<< 2157652494b7e03d4345b81d263b74e6846f75d8
        {
          return GSL_IEEE_TYPE_DENORMAL ;
        }
      else
        {
          return GSL_IEEE_TYPE_ZERO ;
        }
=======
	{
	  return GSL_IEEE_TYPE_DENORMAL ;
	}
      else
	{
	  return GSL_IEEE_TYPE_ZERO ;
	}
>>>>>>> config
    }
  else
    {
      return GSL_IEEE_TYPE_NORMAL ;
    }
}
