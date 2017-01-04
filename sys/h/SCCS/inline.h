h26047
s 00001/00001/00051
d D 4.5 82/06/08 22:03:32 wnj 11 10
c irele -> iunlock
e
s 00003/00002/00049
d D 4.4 81/11/08 16:43:39 wnj 10 9
c plock/prele -> ilock/irele
e
s 00003/00003/00048
d D 4.3 81/02/26 04:30:01 wnj 9 8
c cosmetics
e
s 00001/00001/00050
d D 4.2 81/02/19 21:40:42 wnj 8 7
c %G%->%E%
e
s 00000/00000/00051
d D 4.1 80/11/09 17:01:02 bill 7 6
c stamp for 4bsd
e
s 00003/00003/00048
d D 3.6 80/10/03 10:50:32 bill 6 5
c iupdat extra arg
e
s 00001/00001/00050
d D 3.5 80/06/07 02:57:47 bill 5 4
c %H%->%G%
e
s 00001/00001/00050
d D 3.4 80/06/04 13:43:27 bill 4 3
c reformat
e
s 00004/00000/00047
d D 3.3 80/05/18 11:32:54 bill 3 2
c ISSIG()
e
s 00006/00000/00041
d D 3.2 80/04/13 12:18:08 bill 2 1
c added IUPDAT
e
s 00041/00000/00000
d D 3.1 80/04/09 16:23:56 bill 1 0
c date and time created 80/04/09 16:23:56 by bill
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%H%	*/
E 5
I 5
D 8
/*	%M%	%I%	%G%	*/
E 8
I 8
/*	%M%	%I%	%E%	*/
I 10

E 10
E 8
E 5
/*
D 9
 * Definitions of inlines for FASTVAX, and macro replacements
 * for them if not FASTVAX (latter only scantily tested).
E 9
I 9
 * Definitions of inlines, and macro replacements
 * for them if UNFAST (latter only scantily tested).
E 9
 */

D 9
#ifdef FASTVAX
E 9
I 9
#ifndef UNFAST
E 9

D 10
#define	plock(ip) \
E 10
I 10
#define	ilock(ip) \
E 10
{ \
	while ((ip)->i_flag & ILOCK) { \
		(ip)->i_flag |= IWANT; \
		sleep((caddr_t)(ip), PINOD); \
	} \
	(ip)->i_flag |= ILOCK; \
}

D 10
#define	prele(ip) \
E 10
I 10
D 11
#define	irele(ip) \
E 11
I 11
#define	iunlock(ip) \
E 11
E 10
{ \
	(ip)->i_flag &= ~ILOCK; \
	if ((ip)->i_flag&IWANT) { \
		(ip)->i_flag &= ~IWANT; \
		wakeup((caddr_t)(ip)); \
	} \
}

#define	GETF(fp, fd) { \
	if ((unsigned)(fd) >= NOFILE || ((fp) = u.u_ofile[fd]) == NULL) { \
		u.u_error = EBADF; \
		return; \
	} \
}

I 2
D 6
#define	IUPDAT(ip, t1, t2) { \
E 6
I 6
#define	IUPDAT(ip, t1, t2, waitfor) { \
E 6
	if (ip->i_flag&(IUPD|IACC|ICHG)) \
D 6
		iupdat(ip, t1, t2); \
E 6
I 6
		iupdat(ip, t1, t2, waitfor); \
E 6
}
I 3
#define	ISSIG(p)	((p)->p_sig && \
	((p)->p_flag&STRC || ((p)->p_sig &~ (p)->p_ignsig)) && issig())
E 3
E 2
#else

#define	GETF(fp, fd) { \
	(fp) = getf(fd); \
	if ((fp) == NULL) \
		return; \
}
I 2

D 6
#define	IUPDAT(ip, t1, t2)	iupdat(ip, t1, t2)
E 6
I 6
#define	IUPDAT(ip, t1, t2, waitfor)	iupdat(ip, t1, t2, waitfor)
E 6
I 3

D 4
#define ISSIG(p)	issig(p)
E 4
I 4
#define	ISSIG(p)	issig(p)
E 4
E 3
E 2
#endif
E 1
