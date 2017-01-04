h33459
s 00056/00000/00000
d D 5.1 85/06/07 21:25:47 mckusick 1 0
c 4.3BSD beta release version
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

#if (HERE != VAX || TARGET != VAX)
	}}}}}	WRONG MACHINE!!!	}}}}}
#endif

/*  The code for converting the types of constants is not  */
/*  portable.  The problems involved in dealing with       */
/*  features such as reserved operands and byte orderings  */
/*  have proven very difficult to deal with in a portable  */
/*  manner.  Because of impending deadlines, I have put    */
/*  off trying to achieve portability.                     */
/*                                                         */
/*                             -Robert Paul Corbett        */
/*                              1983 May 1                 */


#define	BLANK	' '

#define MAXWORD  32767
#define MINWORD -32768

typedef
  struct Dreal
    {
      unsigned fract1: 7;
      unsigned exp: 8;
      unsigned sign: 1;
      unsigned fract2: 16;
      unsigned fract3: 16;
      unsigned fract4: 16;
    }
  dreal;

typedef
  struct Quad
    {
      long word1;
      long word2;
    }
  quad;

typedef
  union RealValue
    {
      double d;
      quad   q;
      dreal  f;
    }
  realvalue;
E 1
