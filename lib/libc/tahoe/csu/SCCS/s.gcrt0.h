h37470
s 00024/00000/00000
d D 1.1 86/08/01 08:56:09 sam 1 0
c date and time created 86/08/01 08:56:09 by sam
e
u
U
t
T
I 1
    /*	@(#)gcrt0.h	1.1 (Tahoe) 3/21/85	*/

struct phdr {
    char	*lpc;
    char	*hpc;
    int		ncnt;
};

struct tostruct {
    char		*selfpc;
    long		count;
    unsigned short	link;
};

    /*
     *	a raw arc,
     *	    with pointers to the calling site and the called site
     *	    and a count.
     */
struct rawarc {
    unsigned long	raw_frompc;
    unsigned long	raw_selfpc;
    long		raw_count;
};
E 1
