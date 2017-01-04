h65214
s 00002/00000/00017
d D 4.2 87/04/06 19:08:03 bostic 2 1
c added RANLIBMAG
e
s 00017/00000/00000
d D 4.1 83/05/03 13:48:12 sam 1 0
c date and time created 83/05/03 13:48:12 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

I 2
#define	RANLIBMAG	"__.SYMDEF"

E 2
/*
 * Structure of the __.SYMDEF table of contents for an archive.
 * __.SYMDEF begins with a word giving the number of ranlib structures
 * which immediately follow, and then continues with a string
 * table consisting of a word giving the number of bytes of strings
 * which follow and then the strings themselves.
 * The ran_strx fields index the string table whose first byte is numbered 0.
 */
struct	ranlib {
	union {
		off_t	ran_strx;	/* string table index of */
		char	*ran_name;	/* symbol defined by */
	} ran_un;
	off_t	ran_off;		/* library member at this offset */
};
E 1
