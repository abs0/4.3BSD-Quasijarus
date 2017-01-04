h48086
s 00000/00000/00008
d D 2.2 83/09/23 16:32:57 garrison 4 3
c Included changes from Arizona
e
s 00000/00000/00008
d D 2.1 83/06/22 14:24:56 garrison 3 2
c Make new release before sending it to Arizona for new changes.
e
s 00003/00002/00005
d D 1.2 83/06/14 16:47:47 rrh 2 1
c add sccs keywords per BSD conventions. Fix format strings so 
c pdp-11 style %D is now %ld, to not interact with sccs
e
s 00007/00000/00000
d D 1.1 83/06/06 11:47:27 garrison 1 0
c date and time created 83/06/06 11:47:27 by garrison
e
u
U
t
T
I 1
D 2
#

E 2
I 2
/*
 *	%W%	%G%
 */
E 2
long int nextrecord(), recsize(), nextline();

# define  maxstr            256
# define  pos(x)            fseek(stream,x,0)

E 1
