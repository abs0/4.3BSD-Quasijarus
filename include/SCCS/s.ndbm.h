h54714
s 00007/00001/00055
d D 5.1 85/05/30 09:37:51 dist 6 5
c Add copyright
e
s 00004/00000/00052
d D 4.5 85/01/09 12:09:50 serge 5 4
c added dbm_dirfno() and dbm_pagfno() macros for flock(2) and fstat(2)
e
s 00024/00022/00028
d D 4.4 84/09/05 14:48:40 ralph 4 3
c added dbm_blkptr, dbm_keyptr fields for dbm_nextkey() changes.
e
s 00033/00026/00017
d D 4.3 84/08/28 14:11:44 ralph 3 2
c unify subroutine names, added error macros.
e
s 00004/00000/00039
d D 4.2 83/12/20 11:02:26 ralph 2 1
c added #defines for options to dbmstore().
e
s 00039/00000/00000
d D 4.1 83/12/02 17:05:58 ralph 1 0
c date and time created 83/12/02 17:05:58 by ralph
e
u
U
t
T
I 1
D 4
/*      %M%     %I%     %E%     */
E 4
I 4
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6
E 4

/*
D 3
 * (New) Hashed key data base library (-lndbm).
E 3
I 3
 * Hashed key data base library.
E 3
 */
#define PBLKSIZ 1024
#define DBLKSIZ 4096

typedef struct {
D 3
	int     db_dirf;                /* open directory file */
	int     db_pagf;                /* open page file */
	int     db_flags;
#define _DB_RDONLY      0x1     /* data base open read-only */
	long    db_maxbno;              /* last ``block'' in page file */
	long    db_bitno;
	long    db_hmask;
	long    db_blkno;               /* current page to read/write */
	long    db_pagbno;              /* current page in pagbuf */
	char    db_pagbuf[PBLKSIZ];     /* page file block buffer */
	long    db_dirbno;              /* current block in dirbuf */
	char    db_dirbuf[DBLKSIZ];     /* directory file block buffer */
E 3
I 3
D 4
	int     dbm_dirf;                /* open directory file */
	int     dbm_pagf;                /* open page file */
	int     dbm_flags;		/* flags, see below */
	long    dbm_maxbno;              /* last ``block'' in page file */
	long    dbm_bitno;
	long    dbm_hmask;
	long    dbm_blkno;               /* current page to read/write */
	long    dbm_pagbno;              /* current page in pagbuf */
	char    dbm_pagbuf[PBLKSIZ];     /* page file block buffer */
	long    dbm_dirbno;              /* current block in dirbuf */
	char    dbm_dirbuf[DBLKSIZ];     /* directory file block buffer */
E 4
I 4
	int	dbm_dirf;		/* open directory file */
	int	dbm_pagf;		/* open page file */
	int	dbm_flags;		/* flags, see below */
	long	dbm_maxbno;		/* last ``bit'' in dir file */
	long	dbm_bitno;		/* current bit number */
	long	dbm_hmask;		/* hash mask */
	long	dbm_blkptr;		/* current block for dbm_nextkey */
	int	dbm_keyptr;		/* current key for dbm_nextkey */
	long	dbm_blkno;		/* current page to read/write */
	long	dbm_pagbno;		/* current page in pagbuf */
	char	dbm_pagbuf[PBLKSIZ];	/* page file block buffer */
	long	dbm_dirbno;		/* current block in dirbuf */
	char	dbm_dirbuf[DBLKSIZ];	/* directory file block buffer */
E 4
E 3
} DBM;

D 3
#define dbrdonly(db)    ((db)->db_flags&_DB_RDONLY) != 0
E 3
I 3
#define _DBM_RDONLY	0x1	/* data base open read-only */
#define _DBM_IOERR	0x2	/* data base I/O error */
E 3

I 3
#define dbm_rdonly(db)	((db)->dbm_flags & _DBM_RDONLY)

#define dbm_error(db)	((db)->dbm_flags & _DBM_IOERR)
	/* use this one at your own risk! */
#define dbm_clearerr(db)	((db)->dbm_flags &= ~_DBM_IOERR)

I 5
/* for flock(2) and fstat(2) */
#define dbm_dirfno(db)	((db)->dbm_dirf)
#define dbm_pagfno(db)	((db)->dbm_pagf)

E 5
E 3
typedef struct {
D 4
	char    *dptr;
	int     dsize;
E 4
I 4
	char	*dptr;
	int	dsize;
E 4
} datum;

I 2
D 3
	/* flags to dbmstore() */
#define DB_INSERT	0
#define DB_REPLACE	1
E 3
I 3
/*
 * flags to dbm_store()
 */
#define DBM_INSERT	0
#define DBM_REPLACE	1
E 3

E 2
D 3
datum   dbmfetch();
datum   dbmfirstkey();
datum   dbmnextkey();
long    dbmforder();
int     dbmdelete();
int     dbmstore();

DBM     *ndbmopen();
void    ndbmclose();
E 3
I 3
D 4
DBM     *dbm_open();
void    dbm_close();
datum   dbm_fetch();
datum   dbm_firstkey();
datum   dbm_nextkey();
long    dbm_forder();
int     dbm_delete();
int     dbm_store();
E 4
I 4
DBM	*dbm_open();
void	dbm_close();
datum	dbm_fetch();
datum	dbm_firstkey();
datum	dbm_nextkey();
long	dbm_forder();
int	dbm_delete();
int	dbm_store();
E 4
E 3
E 1
