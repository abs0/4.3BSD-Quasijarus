h42544
s 00000/00000/00010
d D 4.2 82/08/17 13:26:40 rrh 2 1
c Changed the data types for the sdb class characters to be unsigned
c characters; this fixed a bug that prevented the arguments to a function
c from being printed symbolically.  The fix was done globally; it is not
c known if the "fix" fixed other bugs
e
s 00010/00000/00000
d D 4.1 80/10/09 23:57:47 bill 1 0
c date and time created 80/10/09 23:57:47 by bill
e
u
U
t
T
I 1
/* "%Z%%M% %I% %G%" */
#ifndef VMUNIX
struct brbuf {
	int	nl, nr;
	char	*next;
	char	b[1024];
	int	fd;
};
long lseek();
#endif
E 1
