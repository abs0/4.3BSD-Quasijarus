h39420
s 00002/00002/00503
d D 7.7 88/06/05 15:39:39 karels 30 29
c another gratuitous change gone awry
e
s 00014/00008/00491
d D 7.6 88/05/25 09:11:45 karels 29 28
c clean up after bostic (remove gratuitous reformatting)
e
s 00017/00023/00482
d D 7.5 88/05/22 14:05:14 bostic 28 27
c shell scripts can't be setuid
e
s 00003/00003/00502
d D 7.4 87/04/02 15:49:01 karels 27 25
c working with pack labels
e
s 00030/00003/00502
d D 7.3.1.1 87/04/02 15:40:58 karels 26 25
c add ifdefs for dev_bsize (almost working)
e
s 00004/00005/00501
d D 7.3 87/03/03 22:25:43 bostic 25 24
c changed SHSIZE to MAXINTERP
e
s 00018/00005/00488
d D 7.2 86/11/03 11:59:36 karels 24 23
c merge in tahoe support
e
s 00001/00001/00492
d D 7.1 86/06/05 00:02:21 mckusick 23 22
c 4.3BSD release version
e
s 00011/00008/00482
d D 6.17 86/02/23 23:08:40 karels 22 21
c lint
e
s 00001/00001/00489
d D 6.16 86/02/19 17:52:25 karels 21 20
c lint
e
s 00001/00001/00489
d D 6.15 85/11/26 12:37:15 karels 20 19
c now can use XTRC again instead of IXMOD
e
s 00001/00001/00489
d D 6.14 85/08/12 15:20:56 bloom 19 18
c arglist or envlist containing -1 caused panic
e
s 00007/00001/00483
d D 6.13 85/06/08 14:35:38 mckusick 18 17
c Add copyright
e
s 00060/00065/00424
d D 6.12 85/05/27 19:57:26 karels 17 16
c change argv[0] for executable scripts to be name of interpretter;
c reorder file closes on exec (avoid wedging when a.out is open and CLEX);
c split setregs to exec and machine-dependent part;
c implement high-water mark on file descriptors in use
e
s 00006/00002/00483
d D 6.11 85/05/27 16:23:13 mckusick 16 15
c must be careful to check bss and data sizes separately to avoid
c problems if their sum overflows
e
s 00002/00002/00483
d D 6.10 85/03/12 18:12:58 mckusick 15 14
c make swkill messages more informative
e
s 00007/00000/00478
d D 6.9 85/03/12 14:59:40 mckusick 14 13
c reset signal stack on exec()
e
s 00004/00000/00474
d D 6.8 84/11/20 11:23:55 karels 13 12
c (ugly) changes to avoid executing/writing traced text segments
c (need regions done right!)
e
s 00016/00016/00458
d D 6.7 84/08/29 20:19:16 bloom 12 11
c Change to includes.  no more ../h
e
s 00012/00006/00462
d D 6.6 84/07/29 18:37:57 sam 11 10
c complete revised argument processing -- use copyoutstr to move 
c arguments from swap space to user space
e
s 00054/00040/00414
d D 6.5 84/07/23 16:39:36 sam 10 9
c use copyinstr and copystr (add copyoutstr later)
e
s 00038/00029/00416
d D 6.4 84/07/21 17:24:16 sam 9 8
c remove a.out header from u. area
e
s 00023/00020/00422
d D 6.3 84/07/08 16:18:36 mckusick 8 7
c rework `namei' interface to eliminate global variables
e
s 00001/00000/00441
d D 6.2 83/08/23 11:44:45 karels 7 6
c turn off profiling at exec
e
s 00000/00000/00441
d D 6.1 83/07/29 06:32:51 sam 6 5
c 4.2 distribution
e
s 00004/00017/00437
d D 4.5 83/07/01 02:18:18 sam 5 4
c purge #if sun's
e
s 00001/00001/00453
d D 4.4 83/06/14 01:37:02 sam 4 3
c revamp locking to be done at the file table level
e
s 00015/00013/00439
d D 4.3 83/06/12 12:47:36 sam 3 2
c mask remains so we can safely reset signals held across exec
e
s 00007/00024/00445
d D 4.2 83/06/02 15:56:40 sam 2 1
c new signals
e
s 00469/00000/00000
d D 4.1 83/05/27 14:02:42 sam 1 0
c date and time created 83/05/27 14:02:42 by sam
e
u
U
f b 
t
T
I 1
D 18
/*	%M%	%I%	%E%	*/
E 18
I 18
/*
D 23
 * Copyright (c) 1982 Regents of the University of California.
E 23
I 23
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 23
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 18

#include "../machine/reg.h"
#include "../machine/pte.h"
#include "../machine/psl.h"
I 24
#include "../machine/mtpr.h"
E 24

D 12
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/map.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/kernel.h"
#include "../h/proc.h"
#include "../h/buf.h"
#include "../h/inode.h"
#include "../h/seg.h"
#include "../h/vm.h"
#include "../h/text.h"
#include "../h/file.h"
#include "../h/uio.h"
D 8
#include "../h/nami.h"
E 8
#include "../h/acct.h"
I 9
#include "../h/exec.h"
E 12
I 12
#include "param.h"
#include "systm.h"
#include "map.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
#include "proc.h"
#include "buf.h"
#include "inode.h"
#include "seg.h"
#include "vm.h"
#include "text.h"
#include "file.h"
#include "uio.h"
#include "acct.h"
#include "exec.h"
E 12
E 9

I 5
D 24
#ifdef vax
#include "../vax/mtpr.h"
#endif

E 24
E 5
/*
 * exec system call, with and without environments.
 */
struct execa {
	char	*fname;
	char	**argp;
	char	**envp;
};

execv()
{
	((struct execa *)u.u_ap)->envp = NULL;
	execve();
}

execve()
{
	register nc;
	register char *cp;
	register struct buf *bp;
	register struct execa *uap;
D 10
	int na, ne, ucp, ap, c;
E 10
I 10
D 22
	int na, ne, ucp, ap, len, cc;
E 22
I 22
	int na, ne, ucp, ap, cc;
	unsigned len;
E 22
E 10
	int indir, uid, gid;
	char *sharg;
	struct inode *ip;
	swblk_t bno;
	char cfname[MAXCOMLEN + 1];
I 9
D 25
#define	SHSIZE	32
E 9
	char cfarg[SHSIZE];
E 25
I 25
	char cfarg[MAXINTERP];
E 25
I 9
	union {
D 25
		char	ex_shell[SHSIZE];	/* #! and name of interpreter */
E 25
I 25
		char	ex_shell[MAXINTERP];	/* #! and interpreter name */
E 25
		struct	exec ex_exec;
	} exdata;
E 9
I 8
	register struct nameidata *ndp = &u.u_nd;
E 8
D 10
	int resid;
E 10
I 10
	int resid, error;
I 26
#ifdef SECSIZE
	extern long argdbsize;			/* XXX */
#endif SECSIZE
E 26
E 10

D 8
	if ((ip = namei(uchar, LOOKUP, 1)) == NULL)
E 8
I 8
	ndp->ni_nameiop = LOOKUP | FOLLOW;
	ndp->ni_segflg = UIO_USERSPACE;
	ndp->ni_dirp = ((struct execa *)u.u_ap)->fname;
	if ((ip = namei(ndp)) == NULL)
E 8
		return;
	bno = 0;
	bp = 0;
	indir = 0;
	uid = u.u_uid;
	gid = u.u_gid;
	if (ip->i_mode & ISUID)
		uid = ip->i_uid;
	if (ip->i_mode & ISGID)
		gid = ip->i_gid;

  again:
	if (access(ip, IEXEC))
		goto bad;
	if ((u.u_procp->p_flag&STRC) && access(ip, IREAD))
		goto bad;
	if ((ip->i_mode & IFMT) != IFREG ||
	   (ip->i_mode & (IEXEC|(IEXEC>>3)|(IEXEC>>6))) == 0) {
		u.u_error = EACCES;
		goto bad;
	}

	/*
D 10
	 * Read in first few bytes of file for segment sizes, ux_mag:
E 10
I 10
	 * Read in first few bytes of file for segment sizes, magic number:
E 10
	 *	407 = plain executable
	 *	410 = RO text
	 *	413 = demand paged RO text
	 * Also an ASCII line beginning with #! is
	 * the file name of a ``shell'' and arguments may be prepended
	 * to the argument list if given here.
	 *
	 * SHELL NAMES ARE LIMITED IN LENGTH.
	 *
	 * ONLY ONE ARGUMENT MAY BE PASSED TO THE SHELL FROM
	 * THE ASCII LINE.
	 */
D 9
	u.u_exdata.ux_shell[0] = 0;	/* for zero length files */
	u.u_error = rdwri(UIO_READ, ip, (caddr_t)&u.u_exdata, sizeof (u.u_exdata),
	    0, 1, &resid);
E 9
I 9
	exdata.ex_shell[0] = '\0';	/* for zero length files */
D 10
	u.u_error = rdwri(UIO_READ, ip, (caddr_t)&exdata,
	   sizeof (struct exec), 0, 1, &resid);
E 10
I 10
	u.u_error = rdwri(UIO_READ, ip, (caddr_t)&exdata, sizeof (exdata),
D 22
	    0, 1, &resid);
E 22
I 22
	    (off_t)0, 1, &resid);
E 22
E 10
E 9
	if (u.u_error)
		goto bad;
D 8
	u.u_count = resid;
E 8
#ifndef lint
D 8
	if (u.u_count > sizeof(u.u_exdata) - sizeof(u.u_exdata.Ux_A) &&
E 8
I 8
D 9
	if (resid > sizeof(u.u_exdata) - sizeof(u.u_exdata.Ux_A) &&
E 8
	    u.u_exdata.ux_shell[0] != '#') {
E 9
I 9
D 10
	if (resid > sizeof (struct exec) - sizeof (exdata.ex_exec.a_magic) &&
E 10
I 10
D 17
	if (resid > sizeof (exdata) - sizeof (exdata.ex_exec.a_magic) &&
E 17
I 17
	if (resid > sizeof(exdata) - sizeof(exdata.ex_exec) &&
E 17
E 10
	    exdata.ex_shell[0] != '#') {
E 9
		u.u_error = ENOEXEC;
		goto bad;
	}
#endif
D 9
	switch (u.u_exdata.ux_mag) {
E 9
I 9
D 21
	switch (exdata.ex_exec.a_magic) {
E 21
I 21
	switch ((int)exdata.ex_exec.a_magic) {
E 21
E 9

	case 0407:
D 9
		u.u_exdata.ux_dsize += u.u_exdata.ux_tsize;
		u.u_exdata.ux_tsize = 0;
E 9
I 9
		exdata.ex_exec.a_data += exdata.ex_exec.a_text;
		exdata.ex_exec.a_text = 0;
E 9
		break;

	case 0413:
	case 0410:
D 9
		if (u.u_exdata.ux_tsize == 0) {
E 9
I 9
		if (exdata.ex_exec.a_text == 0) {
E 9
			u.u_error = ENOEXEC;
			goto bad;
		}
		break;

	default:
D 9
		if (u.u_exdata.ux_shell[0] != '#' ||
		    u.u_exdata.ux_shell[1] != '!' ||
E 9
I 9
D 28
		if (exdata.ex_shell[0] != '#' ||
		    exdata.ex_shell[1] != '!' ||
E 9
		    indir) {
E 28
I 28
D 29
		if (exdata.ex_shell[0] != '#' || exdata.ex_shell[1] != '!' ||
		    indir++) {
E 29
I 29
		if (exdata.ex_shell[0] != '#' ||
		    exdata.ex_shell[1] != '!' ||
		    indir) {
E 29
E 28
			u.u_error = ENOEXEC;
			goto bad;
		}
D 9
		cp = &u.u_exdata.ux_shell[2];		/* skip "#!" */
		while (cp < &u.u_exdata.ux_shell[SHSIZE]) {
E 9
I 9
D 28
		cp = &exdata.ex_shell[2];		/* skip "#!" */
D 25
		while (cp < &exdata.ex_shell[SHSIZE]) {
E 25
I 25
		while (cp < &exdata.ex_shell[MAXINTERP]) {
E 25
E 9
			if (*cp == '\t')
				*cp = ' ';
			else if (*cp == '\n') {
E 28
I 28
		for (cp = &exdata.ex_shell[2];; ++cp) {
D 29
			if (cp == &exdata.ex_shell[MAXINTERP]) {
E 29
I 29
			if (cp >= &exdata.ex_shell[MAXINTERP]) {
E 29
				u.u_error = ENOEXEC;
				goto bad;
			}
			if (*cp == '\n') {
E 28
				*cp = '\0';
				break;
			}
D 28
			cp++;
E 28
I 28
			if (*cp == '\t')
				*cp = ' ';
E 28
		}
D 28
		if (*cp != '\0') {
			u.u_error = ENOEXEC;
			goto bad;
		}
D 9
		cp = &u.u_exdata.ux_shell[2];
E 9
I 9
		cp = &exdata.ex_shell[2];
E 9
		while (*cp == ' ')
			cp++;
E 28
I 28
D 29
		for (cp = &exdata.ex_shell[2]; *cp == ' '; ++cp);
E 29
I 29
		cp = &exdata.ex_shell[2];
		while (*cp == ' ')
			cp++;
E 29
E 28
D 8
		u.u_dirp = cp;
E 8
I 8
		ndp->ni_dirp = cp;
E 8
D 28
		while (*cp && *cp != ' ')
			cp++;
D 17
		sharg = NULL;
E 17
I 17
		cfarg[0] = '\0';
E 28
I 28
D 29
		for (; *cp && *cp != ' '; ++cp);
E 29
I 29
		while (*cp && *cp != ' ')
			cp++;
I 30
		cfarg[0] = '\0';
E 30
E 29
E 28
E 17
		if (*cp) {
D 28
			*cp++ = '\0';
			while (*cp == ' ')
				cp++;
E 28
I 28
D 29
			for (*cp++ = '\0'; *cp == ' '; ++cp);
E 29
I 29
			*cp++ = '\0';
			while (*cp == ' ')
				cp++;
E 29
E 28
D 17
			if (*cp) {
E 17
I 17
			if (*cp)
E 17
D 25
				bcopy((caddr_t)cp, (caddr_t)cfarg, SHSIZE);
E 25
I 25
				bcopy((caddr_t)cp, (caddr_t)cfarg, MAXINTERP);
E 25
D 17
				sharg = cfarg;
			}
E 17
D 29
		}
D 8
		if (u.u_dent.d_namlen > MAXCOMLEN)
			u.u_dent.d_namlen = MAXCOMLEN;
		bcopy((caddr_t)u.u_dent.d_name, (caddr_t)cfname,
		    (unsigned)(u.u_dent.d_namlen + 1));
E 8
I 8
D 17
		if (ndp->ni_dent.d_namlen > MAXCOMLEN)
			ndp->ni_dent.d_namlen = MAXCOMLEN;
		bcopy((caddr_t)ndp->ni_dent.d_name, (caddr_t)cfname,
		    (unsigned)(ndp->ni_dent.d_namlen + 1));
E 8
D 10
		cfname[MAXCOMLEN] = 0;
E 10
I 10
		cfname[MAXCOMLEN] = '\0';
E 17
E 10
D 28
		indir = 1;
E 28
I 28
		else
E 29
I 29
D 30
		} else
E 29
			cfarg[0] = '\0';
E 30
I 30
		}
E 30
I 29
		indir = 1;
E 29
E 28
		iput(ip);
D 8
		ip = namei(schar, LOOKUP, 1);
E 8
I 8
		ndp->ni_nameiop = LOOKUP | FOLLOW;
		ndp->ni_segflg = UIO_SYSSPACE;
		ip = namei(ndp);
E 8
		if (ip == NULL)
			return;
I 17
		bcopy((caddr_t)ndp->ni_dent.d_name, (caddr_t)cfname,
		    MAXCOMLEN);
		cfname[MAXCOMLEN] = '\0';
I 28
		uid = u.u_uid;		/* shell scripts can't be setuid */
		gid = u.u_gid;
E 28
E 17
		goto again;
	}

	/*
	 * Collect arguments on "file" in swap space.
	 */
	na = 0;
	ne = 0;
	nc = 0;
I 10
	cc = 0;
E 10
	uap = (struct execa *)u.u_ap;
I 26
#ifdef SECSIZE
	bno = rmalloc(argmap, (clrnd((int)btoc(NCARGS))) * CLBYTES / argdbsize);
#else SECSIZE
E 26
D 9
	if ((bno = rmalloc(argmap, (long)ctod(clrnd((int)btoc(NCARGS))))) == 0) {
E 9
I 9
	bno = rmalloc(argmap, (long)ctod(clrnd((int)btoc(NCARGS))));
I 26
#endif SECSIZE
E 26
	if (bno == 0) {
E 9
D 15
		swkill(u.u_procp, "exece");
E 15
I 15
		swkill(u.u_procp, "exec: no swap space");
E 15
		goto bad;
	}
	if (bno % CLSIZE)
		panic("execa rmalloc");
I 10
	/*
	 * Copy arguments into file in argdev area.
	 */
E 10
	if (uap->argp) for (;;) {
		ap = NULL;
D 17
		if (indir && (na == 1 || na == 2 && sharg))
E 17
I 17
		sharg = NULL;
		if (indir && na == 0) {
			sharg = cfname;
			ap = (int)sharg;
			uap->argp++;		/* ignore argv[0] */
		} else if (indir && (na == 1 && cfarg[0])) {
			sharg = cfarg;
			ap = (int)sharg;
		} else if (indir && (na == 1 || na == 2 && cfarg[0]))
E 17
			ap = (int)uap->fname;
		else if (uap->argp) {
			ap = fuword((caddr_t)uap->argp);
			uap->argp++;
		}
D 10
		if (ap==NULL && uap->envp) {
E 10
I 10
		if (ap == NULL && uap->envp) {
E 10
			uap->argp = NULL;
D 10
			if ((ap = fuword((caddr_t)uap->envp)) == NULL)
				break;
			uap->envp++;
			ne++;
E 10
I 10
			if ((ap = fuword((caddr_t)uap->envp)) != NULL)
				uap->envp++, ne++;
E 10
		}
		if (ap == NULL)
			break;
		na++;
D 10
		if (ap == -1)
			u.u_error = EFAULT;
E 10
I 10
		if (ap == -1) {
D 19
			error = EFAULT;
E 19
I 19
			u.u_error = EFAULT;
E 19
			break;
		}
E 10
		do {
D 10
			if (nc >= NCARGS-1)
				u.u_error = E2BIG;
			if (indir && na == 2 && sharg != NULL)
				c = *sharg++ & 0377;
			else if ((c = fubyte((caddr_t)ap++)) < 0)
				u.u_error = EFAULT;
			if (u.u_error) {
E 10
I 10
			if (cc <= 0) {
				/*
				 * We depend on NCARGS being a multiple of
D 26
D 27
				 * CLSIZE*NBPG.  This way we need only check
E 27
I 27
				 * CLBYTES.  This way we need only check
E 27
E 26
I 26
				 * CLBYTES.  This way we need only check
E 26
				 * overflow before each buffer allocation.
				 */
				if (nc >= NCARGS-1) {
					error = E2BIG;
					break;
				}
E 10
				if (bp)
D 10
					brelse(bp);
				bp = 0;
				goto badarg;
			}
			if (nc % (CLSIZE*NBPG) == 0) {
				if (bp)
E 10
					bdwrite(bp);
D 10
				bp = getblk(argdev, bno + ctod(nc / NBPG),
				    CLSIZE*NBPG);
E 10
I 10
D 26
D 27
				cc = CLSIZE*NBPG;
E 27
I 27
				cc = CLBYTES;
E 27
E 26
I 26
				cc = CLBYTES;
#ifdef SECSIZE
				bp = getblk(argdev, bno + nc / argdbsize, cc,
				    argdbsize);
#else SECSIZE
E 26
				bp = getblk(argdev, bno + ctod(nc/NBPG), cc);
I 26
#endif SECSIZE
E 26
E 10
				cp = bp->b_un.b_addr;
			}
D 10
			nc++;
			*cp++ = c;
		} while (c > 0);
E 10
I 10
D 17
			if (indir && na == 2 && sharg != NULL)
E 17
I 17
			if (sharg) {
E 17
D 22
				error = copystr(sharg, cp, cc, &len);
E 22
I 22
				error = copystr(sharg, cp, (unsigned)cc, &len);
E 22
D 17
			else
E 17
I 17
				sharg += len;
			} else {
E 17
D 22
				error = copyinstr((caddr_t)ap, cp, cc, &len);
E 22
I 22
				error = copyinstr((caddr_t)ap, cp, (unsigned)cc,
				    &len);
E 22
D 17
			ap += len;
E 17
I 17
				ap += len;
			}
E 17
			cp += len;
			nc += len;
			cc -= len;
		} while (error == ENOENT);
		if (error) {
			u.u_error = error;
			if (bp)
				brelse(bp);
			bp = 0;
			goto badarg;
		}
E 10
	}
	if (bp)
		bdwrite(bp);
	bp = 0;
	nc = (nc + NBPW-1) & ~(NBPW-1);
D 17
	if (indir) {
D 8
		u.u_dent.d_namlen = strlen(cfname);
		bcopy((caddr_t)cfname, (caddr_t)u.u_dent.d_name,
		    (unsigned)(u.u_dent.d_namlen + 1));
E 8
I 8
		ndp->ni_dent.d_namlen = strlen(cfname);
		bcopy((caddr_t)cfname, (caddr_t)ndp->ni_dent.d_name,
		    (unsigned)(ndp->ni_dent.d_namlen + 1));
E 8
	}
E 17
D 9
	getxfile(ip, nc + (na+4)*NBPW, uid, gid);
E 9
I 9
	getxfile(ip, &exdata.ex_exec, nc + (na+4)*NBPW, uid, gid);
E 9
	if (u.u_error) {
badarg:
D 10
		for (c = 0; c < nc; c += CLSIZE*NBPG) {
			bp = baddr(argdev, bno + ctod(c / NBPG), CLSIZE*NBPG);
E 10
I 10
		for (cc = 0; cc < nc; cc += CLSIZE*NBPG) {
I 26
#ifdef SECSIZE
			bp = baddr(argdev, bno + cc / argdbsize, CLSIZE*NBPG,
			    argdbsize);
#else SECSIZE
E 26
			bp = baddr(argdev, bno + ctod(cc/NBPG), CLSIZE*NBPG);
I 26
#endif SECSIZE
E 26
E 10
			if (bp) {
				bp->b_flags |= B_AGE;		/* throw away */
				bp->b_flags &= ~B_DELWRI;	/* cancel io */
				brelse(bp);
				bp = 0;
			}
		}
		goto bad;
	}
I 17
	iput(ip);
	ip = NULL;
E 17

	/*
D 10
	 * copy back arglist
E 10
I 10
	 * Copy back arglist.
E 10
	 */
	ucp = USRSTACK - nc - NBPW;
	ap = ucp - na*NBPW - 3*NBPW;
	u.u_ar0[SP] = ap;
	(void) suword((caddr_t)ap, na-ne);
	nc = 0;
I 11
	cc = 0;
E 11
	for (;;) {
		ap += NBPW;
D 10
		if (na==ne) {
E 10
I 10
		if (na == ne) {
E 10
			(void) suword((caddr_t)ap, 0);
			ap += NBPW;
		}
		if (--na < 0)
			break;
		(void) suword((caddr_t)ap, ucp);
		do {
D 11
			if (nc % (CLSIZE*NBPG) == 0) {
E 11
I 11
			if (cc <= 0) {
E 11
				if (bp)
					brelse(bp);
D 11
				bp = bread(argdev, bno + ctod(nc / NBPG),
				    CLSIZE*NBPG);
E 11
I 11
D 26
D 27
				cc = CLSIZE*NBPG;
E 27
I 27
				cc = CLBYTES;
E 27
E 26
I 26
				cc = CLBYTES;
#ifdef SECSIZE
				bp = bread(argdev, bno + nc / argdbsize, cc,
				    argdbsize);
#else SECSIZE
E 26
				bp = bread(argdev, bno + ctod(nc / NBPG), cc);
I 26
#endif SECSIZE
E 26
E 11
				bp->b_flags |= B_AGE;		/* throw away */
				bp->b_flags &= ~B_DELWRI;	/* cancel io */
				cp = bp->b_un.b_addr;
			}
D 10
			(void) subyte((caddr_t)ucp++, (c = *cp++));
E 10
I 10
D 11
			(void) subyte((caddr_t)ucp++, (cc = *cp++));
E 10
			nc++;
D 10
		} while(c&0377);
E 10
I 10
		} while(cc&0377);
E 11
I 11
D 22
			error = copyoutstr(cp, (caddr_t)ucp, cc, &len);
E 22
I 22
			error = copyoutstr(cp, (caddr_t)ucp, (unsigned)cc,
			    &len);
E 22
			ucp += len;
			cp += len;
			nc += len;
			cc -= len;
		} while (error == ENOENT);
		if (error == EFAULT)
			panic("exec: EFAULT");
E 11
E 10
	}
	(void) suword((caddr_t)ap, 0);
I 17

	/*
	 * Reset caught signals.  Held signals
	 * remain held through p_sigmask.
	 */
	while (u.u_procp->p_sigcatch) {
D 22
		nc = ffs(u.u_procp->p_sigcatch);
E 22
I 22
		nc = ffs((long)u.u_procp->p_sigcatch);
E 22
		u.u_procp->p_sigcatch &= ~sigmask(nc);
		u.u_signal[nc] = SIG_DFL;
	}
	/*
	 * Reset stack state to the user stack.
	 * Clear set of signals caught on the signal stack.
	 */
	u.u_onstack = 0;
	u.u_sigsp = 0;
	u.u_sigonstack = 0;

	for (nc = u.u_lastfile; nc >= 0; --nc) {
		if (u.u_pofile[nc] & UF_EXCLOSE) {
			closef(u.u_ofile[nc]);
			u.u_ofile[nc] = NULL;
			u.u_pofile[nc] = 0;
		}
		u.u_pofile[nc] &= ~UF_MAPPED;
	}
	while (u.u_lastfile >= 0 && u.u_ofile[u.u_lastfile] == NULL)
		u.u_lastfile--;
E 17
D 9
	setregs();
E 9
I 9
	setregs(exdata.ex_exec.a_entry);
E 9
I 8
	/*
	 * Remember file name for accounting.
	 */
	u.u_acflag &= ~AFORK;
D 17
	bcopy((caddr_t)ndp->ni_dent.d_name, (caddr_t)u.u_comm,
	    (unsigned)(ndp->ni_dent.d_namlen + 1));
E 17
I 17
	if (indir)
		bcopy((caddr_t)cfname, (caddr_t)u.u_comm, MAXCOMLEN);
	else {
		if (ndp->ni_dent.d_namlen > MAXCOMLEN)
			ndp->ni_dent.d_namlen = MAXCOMLEN;
		bcopy((caddr_t)ndp->ni_dent.d_name, (caddr_t)u.u_comm,
		    (unsigned)(ndp->ni_dent.d_namlen + 1));
	}
E 17
E 8
bad:
	if (bp)
		brelse(bp);
	if (bno)
I 26
#ifdef SECSIZE
		rmfree(argmap, (clrnd((int)btoc(NCARGS))) * CLBYTES / argdbsize,
		    bno);
#else SECSIZE
E 26
		rmfree(argmap, (long)ctod(clrnd((int) btoc(NCARGS))), bno);
I 26
#endif SECSIZE
E 26
D 17
	iput(ip);
E 17
I 17
	if (ip)
		iput(ip);
E 17
}

/*
 * Read in and set up memory for executed file.
 */
D 9
getxfile(ip, nargc, uid, gid)
E 9
I 9
getxfile(ip, ep, nargc, uid, gid)
E 9
	register struct inode *ip;
I 9
	register struct exec *ep;
E 9
	int nargc, uid, gid;
{
D 16
	register size_t ts, ds, ss;
E 16
I 16
	size_t ts, ds, ids, uds, ss;
E 16
	int pagi;

D 9
	if (u.u_exdata.ux_mag == 0413)
E 9
I 9
	if (ep->a_magic == 0413)
E 9
		pagi = SPAGI;
	else
		pagi = 0;
I 13
D 20
	if (ip->i_flag & IXMOD) {			/* XXX */
E 20
I 20
	if (ip->i_text && (ip->i_text->x_flag & XTRC)) {
E 20
		u.u_error = ETXTBSY;
		goto bad;
	}
E 13
D 9
	if (u.u_exdata.ux_tsize!=0 && (ip->i_flag&ITEXT)==0 &&
	    ip->i_count!=1) {
E 9
I 9
	if (ep->a_text != 0 && (ip->i_flag&ITEXT) == 0 &&
	    ip->i_count != 1) {
E 9
		register struct file *fp;

		for (fp = file; fp < fileNFILE; fp++) {
			if (fp->f_type == DTYPE_INODE &&
			    fp->f_count > 0 &&
			    (struct inode *)fp->f_data == ip &&
			    (fp->f_flag&FWRITE)) {
				u.u_error = ETXTBSY;
				goto bad;
			}
		}
	}

	/*
	 * Compute text and data sizes and make sure not too large.
I 16
	 * NB - Check data and bss separately as they may overflow 
	 * when summed together.
E 16
	 */
D 9
	ts = clrnd(btoc(u.u_exdata.ux_tsize));
	ds = clrnd(btoc((u.u_exdata.ux_dsize+u.u_exdata.ux_bsize)));
E 9
I 9
	ts = clrnd(btoc(ep->a_text));
I 16
	ids = clrnd(btoc(ep->a_data));
	uds = clrnd(btoc(ep->a_bss));
E 16
D 10
	ds = clrnd(btoc((ep->a_data + ep->a_bss)));
E 10
I 10
	ds = clrnd(btoc(ep->a_data + ep->a_bss));
E 10
E 9
	ss = clrnd(SSIZE + btoc(nargc));
D 16
	if (chksize((unsigned)ts, (unsigned)ds, (unsigned)ss))
E 16
I 16
	if (chksize((unsigned)ts, (unsigned)ids, (unsigned)uds, (unsigned)ss))
E 16
		goto bad;

	/*
	 * Make sure enough space to start process.
	 */
	u.u_cdmap = zdmap;
	u.u_csmap = zdmap;
	if (swpexpand(ds, ss, &u.u_cdmap, &u.u_csmap) == NULL)
		goto bad;

	/*
	 * At this point, committed to the new image!
	 * Release virtual memory resources of old process, and
	 * initialize the virtual memory of the new process.
	 * If we resulted from vfork(), instead wakeup our
	 * parent who will set SVFDONE when he has taken back
	 * our resources.
	 */
	if ((u.u_procp->p_flag & SVFORK) == 0)
		vrelvm();
	else {
		u.u_procp->p_flag &= ~SVFORK;
		u.u_procp->p_flag |= SKEEP;
		wakeup((caddr_t)u.u_procp);
		while ((u.u_procp->p_flag & SVFDONE) == 0)
			sleep((caddr_t)u.u_procp, PZERO - 1);
		u.u_procp->p_flag &= ~(SVFDONE|SKEEP);
	}
D 2
	u.u_procp->p_flag &= ~(SPAGI|SSEQL|SUANOM|SNUSIG);
E 2
I 2
	u.u_procp->p_flag &= ~(SPAGI|SSEQL|SUANOM|SOUSIG);
E 2
	u.u_procp->p_flag |= pagi;
	u.u_dmap = u.u_cdmap;
	u.u_smap = u.u_csmap;
	vgetvm(ts, ds, ss);

	if (pagi == 0)
		u.u_error =
		    rdwri(UIO_READ, ip,
			(char *)ctob(dptov(u.u_procp, 0)),
D 9
			(int)u.u_exdata.ux_dsize,
			(int)(sizeof(u.u_exdata)+u.u_exdata.ux_tsize),
E 9
I 9
			(int)ep->a_data,
D 22
			(int)(sizeof (struct exec) + ep->a_text),
E 22
I 22
			(off_t)(sizeof (struct exec) + ep->a_text),
E 22
E 9
			0, (int *)0);
D 9
	xalloc(ip, pagi);
E 9
I 9
	xalloc(ip, ep, pagi);
I 24
#if defined(tahoe)
	/*
	 * Define new keys.
	 */
	if (u.u_procp->p_textp == 0) {	/* use existing code key if shared */
		ckeyrelease(u.u_procp->p_ckey);
		u.u_procp->p_ckey = getcodekey();
	}
	mtpr(CCK, u.u_procp->p_ckey);
	dkeyrelease(u.u_procp->p_dkey);
	u.u_procp->p_dkey = getdatakey();
	mtpr(DCK, u.u_procp->p_dkey);
#endif
E 24
E 9
	if (pagi && u.u_procp->p_textp)
		vinifod((struct fpte *)dptopte(u.u_procp, 0),
		    PG_FTEXT, u.u_procp->p_textp->x_iptr,
D 9
		    (long)(1 + ts/CLSIZE), (int)btoc(u.u_exdata.ux_dsize));
E 9
I 9
D 22
		    (long)(1 + ts/CLSIZE), (int)btoc(ep->a_data));
E 22
I 22
		    (long)(1 + ts/CLSIZE), (size_t)btoc(ep->a_data));
E 22
E 9

D 24
#ifdef vax
E 24
I 24
#if defined(vax) || defined(tahoe)
E 24
	/* THIS SHOULD BE DONE AT A LOWER LEVEL, IF AT ALL */
D 5
#include "../vax/mtpr.h"		/* XXX */
E 5
	mtpr(TBIA, 0);
#endif

	if (u.u_error)
D 15
		swkill(u.u_procp, "i/o error mapping pages");
E 15
I 15
		swkill(u.u_procp, "exec: I/O error mapping pages");
E 15
	/*
	 * set SUID/SGID protections, if no tracing
	 */
	if ((u.u_procp->p_flag&STRC)==0) {
		u.u_uid = uid;
		u.u_procp->p_uid = uid;
		u.u_gid = gid;
	} else
		psignal(u.u_procp, SIGTRAP);
	u.u_tsize = ts;
	u.u_dsize = ds;
	u.u_ssize = ss;
I 7
	u.u_prof.pr_scale = 0;
I 24
#if defined(tahoe)
	u.u_pcb.pcb_savacc.faddr = (float *)NULL;
#endif
E 24
E 7
bad:
	return;
D 17
}

/*
 * Clear registers on exec
 */
D 9
setregs()
E 9
I 9
setregs(entry)
D 10
	int entry;
E 10
I 10
	u_long entry;
E 10
E 9
{
D 3
	register int (**rp)();
	register int i, sigmask;
E 3
I 3
	register int i;
E 3
I 2
	register struct proc *p = u.u_procp;
E 2

D 2
	for (rp = &u.u_signal[1], sigmask = 1; rp < &u.u_signal[NSIG];
	    sigmask <<= 1, rp++) {
		switch (*rp) {

		case SIG_IGN:
		case SIG_DFL:
		case SIG_HOLD:
			continue;

		default:
			/*
			 * Normal or deferring catch; revert to default.
			 */
E 2
I 2
D 3
	rp = &u.u_signal[1];
	for (sigmask = 1; rp < &u.u_signal[NSIG]; sigmask <<= 1, rp++)
		/* disallow masked signals to carry over? */
		if (p->p_sigcatch & sigmask && (p->p_sigmask & sigmask) == 0) {
E 2
			(void) spl6();
I 2
			p->p_sigcatch &= ~sigmask;
E 2
			*rp = SIG_DFL;
D 2
			if ((int)*rp & 1)
				u.u_procp->p_siga0 |= sigmask;
			else
				u.u_procp->p_siga0 &= ~sigmask;
			if ((int)*rp & 2)
				u.u_procp->p_siga1 |= sigmask;
			else
				u.u_procp->p_siga1 &= ~sigmask;
E 2
			(void) spl0();
D 2
			continue;
E 2
		}
E 3
I 3
	/*
	 * Reset caught signals.  Held signals
	 * remain held through p_sigmask.
	 */
	while (p->p_sigcatch) {
		(void) spl6();
		i = ffs(p->p_sigcatch);
		p->p_sigcatch &= ~(1 << (i - 1));
		u.u_signal[i] = SIG_DFL;
		(void) spl0();
	}
I 14
	/*
	 * Reset stack state to the user stack.
	 * Clear set of signals caught on the signal stack.
	 */
	u.u_onstack = 0;
	u.u_sigsp = 0;
	u.u_sigonstack = 0;
E 14
E 3
D 2
	}
E 2
D 5
#ifdef vax
E 5
D 3
/*
E 3
I 3
#ifdef notdef
	/* should pass args to init on the stack */
E 3
	for (rp = &u.u_ar0[0]; rp < &u.u_ar0[16];)
		*rp++ = 0;
D 3
*/
E 3
I 3
#endif
E 3
D 9
	u.u_ar0[PC] = u.u_exdata.ux_entloc+2;
E 9
I 9
	u.u_ar0[PC] = entry + 2;
E 9
D 5
#endif
#ifdef sun
	{ register struct regs *r = (struct regs *)u.u_ar0;
	  for (i = 0; i < 8; i++) {
		r->r_dreg[i] = 0;
		if (&r->r_areg[i] != &r->r_sp)
			r->r_areg[i] = 0;
	  }
	  r->r_sr = PSL_USERSET;
	  r->r_pc = u.u_exdata.ux_entloc;
	}
#endif
E 5
	for (i=0; i<NOFILE; i++) {
		if (u.u_pofile[i]&UF_EXCLOSE) {
D 4
			closef(u.u_ofile[i], u.u_pofile[i]);
E 4
I 4
			closef(u.u_ofile[i]);
E 4
			u.u_ofile[i] = NULL;
			u.u_pofile[i] = 0;
		}
		u.u_pofile[i] &= ~UF_MAPPED;
	}
E 17
D 8

	/*
	 * Remember file name for accounting.
	 */
	u.u_acflag &= ~AFORK;
	bcopy((caddr_t)u.u_dent.d_name, (caddr_t)u.u_comm,
	    (unsigned)(u.u_dent.d_namlen + 1));
E 8
D 5
#ifdef sun
	u.u_eosys = REALLYRETURN;
#endif
E 5
}
E 1
