h13457
s 00010/00000/00000
d D 5.1 86/11/03 20:00:09 mckusick 1 0
c from CCI
e
u
U
t
T
I 1
/*
 *	%W% (Berkeley) %G%
 */

long int  mclock_()
  {
  int  buf[6];
  times(buf);
  return(buf[0]+buf[2]+buf[3]);
  }
E 1
