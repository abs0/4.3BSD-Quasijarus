h32735
s 00000/00000/00033
d D 4.2 82/08/17 13:26:23 rrh 2 1
c Changed the data types for the sdb class characters to be unsigned
c characters; this fixed a bug that prevented the arguments to a function
c from being printed symbolically.  The fix was done globally; it is not
c known if the "fix" fixed other bugs
e
s 00033/00000/00000
d D 4.1 80/10/09 23:57:08 bill 1 0
c date and time created 80/10/09 23:57:08 by bill
e
u
U
t
T
I 1
/* "%Z%%M% %I% %G%" */
/* type modifiers */

# define PTR  020
# define FTN  040
# define ARY  060

/* type packing constants */

# define TMASK 060
# define TMASK1 0300
# define TMASK2  0360
# define BTMASK 017
# define BTSHIFT 4
# define TSHIFT 2

/*	macros	*/

# define BTYPE(x)  (x&BTMASK)   /* basic type of x */
# define ISUNSIGNED(x) ((x)<=ULONG&&(x)>=UCHAR)
# define UNSIGNABLE(x) ((x)<=LONG&&(x)>=CHAR)
# define ENUNSIGN(x) ((x)+(UNSIGNED-INT))
# define DEUNSIGN(x) ((x)+(INT-UNSIGNED))
# define ISPTR(x) ((x&TMASK)==PTR)
# define ISFTN(x)  ((x&TMASK)==FTN)  /* is x a function type */
# define ISARY(x)   ((x&TMASK)==ARY)   /* is x an array type */
# define INCREF(x) (((x&~BTMASK)<<TSHIFT)|PTR|(x&BTMASK))
# define DECREF(x) (((x>>TSHIFT)&~BTMASK&0x3fff)|(x&BTMASK))
	/* pack and unpack field descriptors (size and offset) */
# define PKFIELD(s,o) ((o<<6)|s)
# define UPKFSZ(v)  (v&077)
# define UPKFOFF(v) (v>>6)

E 1
