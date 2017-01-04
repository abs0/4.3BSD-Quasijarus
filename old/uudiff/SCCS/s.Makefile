h40430
s 00022/00000/00000
d D 4.1 83/01/01 19:02:26 sam 1 0
c date and time created 83/01/01 19:02:26 by sam
e
u
U
t
T
I 1
#	%W%	(Berkeley)	%G%
#
CFLAGS=-O

uudiff: lenrem locpart printable run1 trim

lenrem: lenrem.c
	cc $(CFLAGS) lenrem.c -o lenrem
locpart: locpart.c
	cc $(CFLAGS) locpart.c -o locpart
printable: printable.c
	cc $(CFLAGS) printable.c -o printable
run1: run1.c
	cc $(CFLAGS) run1.c -o run1
trim: trim.c
	cc $(CFLAGS) trim.c -o trim

install:
	: stuff lives here!

clean:
	rm -f *.o lenrem locpart printable run1 trim
E 1
