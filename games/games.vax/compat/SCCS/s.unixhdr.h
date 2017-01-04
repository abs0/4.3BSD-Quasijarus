h37779
s 00000/00000/00017
d D 4.1 82/05/12 11:14:24 rrh 2 1
c sync to release 4.1
e
s 00017/00000/00000
d D 1.1 82/05/12 11:03:39 rrh 1 0
c date and time created 82/05/12 11:03:39 by rrh
e
u
U
t
T
I 1
/*
 * 	%M%	%I%	%E%
 */
#define	MAGIC1	0407
#define	MAGIC2	0410
#define	MAGIC3	0411
#define	MAGIC4	0405
struct {
	unsigned short magic;
	unsigned short textsize;
	unsigned short datasize;
	unsigned short bsssize;
	unsigned short symsize;
	unsigned short entry;
	unsigned short dummy;
	unsigned short relflag;
} header;
E 1
