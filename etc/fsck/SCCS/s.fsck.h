h36887
s 00025/00021/00161
d D 5.7 88/05/07 01:04:10 mckusick 13 12
c expand from three static buffer to a dynamic buffer pool;
c initial sizing of the buffer pool is 128K (For 8K fs == 16 buffers)
e
s 00001/00000/00181
d D 5.6 88/05/01 23:36:54 mckusick 12 11
c add -c flag (convert dynamic cylinder group format back to static format)
e
s 00001/00000/00180
d D 5.5 87/04/07 19:49:18 karels 11 10
c fix alternate superblock location again; don't offer to rewrite
c standard superblock if we haven't found a good one yet; standardize units
c for -b (sectors! as before); kernel may change fs_dbsize
e
s 00001/00000/00179
d D 5.4 87/03/11 20:06:24 karels 10 9
c use physical sector size for partial buffer reads;
c -n implies "yes" answer for "CONTINUE?"
e
s 00001/00000/00178
d D 5.3 87/02/18 18:14:41 mckusick 9 8
c intuit the appropriate DEV_BSIZE from fsbtodb macro
e
s 00001/00000/00177
d D 5.2 87/01/07 19:26:41 mckusick 8 7
c be more persistent in trying to read directories; 
c add FOUND return status for routines called from dirscan
e
s 00007/00001/00170
d D 5.1 85/06/05 08:59:36 dist 7 6
c Add copyright
e
s 00027/00004/00144
d D 3.6 85/06/02 16:46:58 mckusick 6 5
c dynamically allocate zero link count table
e
s 00009/00005/00139
d D 3.5 85/05/31 20:08:12 mckusick 5 4
c dynamically allocate the duplicate block table
e
s 00001/00000/00143
d D 3.4 85/05/31 00:19:24 mckusick 4 3
c check for improper directory offsets; recover gracefully from read errors
e
s 00006/00024/00137
d D 3.3 85/02/08 19:15:03 mckusick 3 2
c merge passes 5 and 6 into a single pass
e
s 00017/00016/00144
d D 3.2 85/02/07 17:51:32 mckusick 2 1
c code reorganization and cleanup
e
s 00160/00000/00000
d D 3.1 84/03/31 21:03:41 mckusick 1 0
c date and time created 84/03/31 21:03:41 by mckusick
e
u
U
t
T
I 1
D 7
/* %W% (Berkeley) %G% */
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7

D 3
/* RECONSTRUCT ONLY BAD CG IN PASS 6 */

E 3
D 13
#define	MAXDUP		10	/* limit on dup blks (per inode) */
#define	MAXBAD		10	/* limit on bad blks (per inode) */
E 13
I 13
#define	MAXDUP		10	 /* limit on dup blks (per inode) */
#define	MAXBAD		10	 /* limit on bad blks (per inode) */
#define MAXBUFSPACE	128*1024 /* maximum space to allocate to buffers */
E 13
D 5
#define	DUPTBLSIZE	100	/* num of dup blocks to remember */
E 5
D 6
#define	MAXLNCNT	500	/* num zero link cnts to remember */
E 6

typedef	int	(*SIG_TYP)();

#ifndef BUFSIZ
#define BUFSIZ 1024
#endif

D 2
#define	MAXNINDIR	(MAXBSIZE / sizeof (daddr_t))
#define	MAXINOPB	(MAXBSIZE / sizeof (struct dinode))
#define	SPERB		(MAXBSIZE / sizeof(short))

E 2
D 3
#define	USTATE	0		/* inode not allocated */
#define	FSTATE	01		/* inode is file */
#define	DSTATE	02		/* inode is directory */
#define	CLEAR	03		/* inode is to be cleared */
E 3
I 3
#define	USTATE	01		/* inode not allocated */
#define	FSTATE	02		/* inode is file */
#define	DSTATE	03		/* inode is directory */
#define	DFOUND	04		/* directory found during descent */
#define	DCLEAR	05		/* directory is to be cleared */
#define	FCLEAR	06		/* file is to be cleared */
E 3

typedef struct dinode	DINODE;
typedef struct direct	DIRECT;

D 2
#define	ALLOC	((dp->di_mode & IFMT) != 0)
#define	DIRCT	((dp->di_mode & IFMT) == IFDIR)
#define	SPECIAL	((dp->di_mode & IFMT) == IFBLK || (dp->di_mode & IFMT) == IFCHR)
E 2
I 2
#define	ALLOC(dip)	(((dip)->di_mode & IFMT) != 0)
#define	DIRCT(dip)	(((dip)->di_mode & IFMT) == IFDIR)
#define	SPECIAL(dip) \
	(((dip)->di_mode & IFMT) == IFBLK || ((dip)->di_mode & IFMT) == IFCHR)
E 2

I 2
D 13
#define	MAXNINDIR	(MAXBSIZE / sizeof (daddr_t))
#define	MAXINOPB	(MAXBSIZE / sizeof (struct dinode))
#define	SPERB		(MAXBSIZE / sizeof(short))

E 13
I 13
/*
 * buffer cache structure.
 */
E 13
E 2
struct bufarea {
D 13
	struct bufarea	*b_next;		/* must be first */
E 13
I 13
	struct bufarea	*b_next;		/* free list queue */
	struct bufarea	*b_prev;		/* free list queue */
E 13
	daddr_t	b_bno;
	int	b_size;
I 4
	int	b_errs;
I 13
	int	b_flags;
E 13
E 4
	union {
D 13
		char	b_buf[MAXBSIZE];	/* buffer space */
		short	b_lnks[SPERB];		/* link counts */
		daddr_t	b_indir[MAXNINDIR];	/* indirect block */
		struct	fs b_fs;		/* super block */
		struct	cg b_cg;		/* cylinder group */
		struct dinode b_dinode[MAXINOPB]; /* inode block */
E 13
I 13
		char	*b_buf;			/* buffer space */
		daddr_t	*b_indir;		/* indirect block */
		struct	fs *b_fs;		/* super block */
		struct	cg *b_cg;		/* cylinder group */
		struct dinode *b_dinode;	/* inode block */
E 13
	} b_un;
	char	b_dirty;
};

I 13
#define	B_INUSE 1
E 13
typedef struct bufarea BUFAREA;

D 13
BUFAREA	inoblk;			/* inode blocks */
BUFAREA	fileblk;		/* other blks in filesys */
E 13
I 13
#define	MINBUFS		5	/* minimum number of buffers required */
BUFAREA	bufhead;		/* head of list of other blks in filesys */
E 13
BUFAREA	sblk;			/* file system superblock */
BUFAREA	cgblk;			/* cylinder group blocks */
I 13
BUFAREA	*getdatablk();
E 13

D 13
#define	initbarea(x)	(x)->b_dirty = 0;(x)->b_bno = (daddr_t)-1
E 13
#define	dirty(x)	(x)->b_dirty = 1
D 13
#define	inodirty()	inoblk.b_dirty = 1
E 13
I 13
#define	initbarea(x) \
	(x)->b_dirty = 0; \
	(x)->b_bno = (daddr_t)-1; \
	(x)->b_flags = 0;

E 13
#define	sbdirty()	sblk.b_dirty = 1
#define	cgdirty()	cgblk.b_dirty = 1
D 13

#define	dirblk		fileblk.b_un
#define	sblock		sblk.b_un.b_fs
#define	cgrp		cgblk.b_un.b_cg
E 13
I 13
#define	sblock		(*sblk.b_un.b_fs)
#define	cgrp		(*cgblk.b_un.b_cg)
E 13

struct filecntl {
	int	rfdes;
	int	wfdes;
	int	mod;
} dfile;			/* file descriptors for filesys */

I 2
enum fixstate {DONTKNOW, NOFIX, FIX};

E 2
struct inodesc {
D 2
	char id_type;		/* type of descriptor, DATA or ADDR */
E 2
I 2
	enum fixstate id_fix;	/* policy on fixing errors */
E 2
	int (*id_func)();	/* function to be applied to blocks of inode */
	ino_t id_number;	/* inode number described */
	ino_t id_parent;	/* for DATA nodes, their parent */
	daddr_t id_blkno;	/* current block number being examined */
	int id_numfrags;	/* number of frags contained in block */
	long id_filesize;	/* for DATA nodes, the size of the directory */
	int id_loc;		/* for DATA nodes, current location in dir */
	int id_entryno;		/* for DATA nodes, current entry number */
D 2
	DIRECT *id_dirp;	/* for data nodes, ptr to current entry */
	enum {DONTKNOW, NOFIX, FIX} id_fix; /* policy on fixing errors */
E 2
I 2
	DIRECT *id_dirp;	/* for DATA nodes, ptr to current entry */
	char *id_name;		/* for DATA nodes, name to find or enter */
	char id_type;		/* type of descriptor, DATA or ADDR */
E 2
};
/* file types */
#define	DATA	1
#define	ADDR	2

D 5

daddr_t	duplist[DUPTBLSIZE];	/* dup block table */
daddr_t	*enddup;		/* next entry in dup table */
daddr_t	*muldup;		/* multiple dups part of table */
E 5
I 5
/*
D 6
 * Linked list of duplicate blocks
E 6
I 6
 * Linked list of duplicate blocks.
 * 
 * The list is composed of two parts. The first part of the
 * list (from duplist through the node pointed to by muldup)
 * contains a single copy of each duplicate block that has been 
 * found. The second part of the list (from muldup to the end)
 * contains duplicate blocks that have been found more than once.
 * To check if a block has been found as a duplicate it is only
 * necessary to search from duplist through muldup. To find the 
 * total number of times that a block has been found as a duplicate
 * the entire list must be searched for occurences of the block
 * in question. The following diagram shows a sample list where
 * w (found twice), x (found once), y (found three times), and z
 * (found once) are duplicate block numbers:
 *
 *    w -> y -> x -> z -> y -> w -> y
 *    ^		     ^
 *    |		     |
 * duplist	  muldup
E 6
 */
struct dups {
	struct dups *next;
	daddr_t dup;
};
struct dups *duplist;		/* head of dup list */
struct dups *muldup;		/* end of unique duplicate dup block numbers */
E 5

D 6
ino_t	badlncnt[MAXLNCNT];	/* table of inos with zero link cnts */
ino_t	*badlnp;		/* next entry in table */
E 6
I 6
/*
 * Linked list of inodes with zero link counts.
 */
struct zlncnt {
	struct zlncnt *next;
	ino_t zlncnt;
};
struct zlncnt *zlnhead;		/* head of zero link count list */
E 6

char	rawflg;
char	*devname;
I 9
long	dev_bsize;		/* computed value of DEV_BSIZE */
I 10
long	secsize;		/* actual disk sector size */
E 10
E 9
char	nflag;			/* assume a no response */
char	yflag;			/* assume a yes response */
int	bflag;			/* location of alternate super block */
int	debug;			/* output debugging info */
I 12
int	cvtflag;		/* convert to old file system format */
E 12
char	preen;			/* just fix normal inconsistencies */
D 2
char	rplyflag;		/* any questions asked? */
E 2
char	hotroot;		/* checking root device */
I 11
char	havesb;			/* superblock has been read */
E 11
D 3
char	fixcg;			/* corrupted free list bit maps */
E 3

char	*blockmap;		/* ptr to primary blk allocation map */
D 3
char	*freemap;		/* ptr to secondary blk allocation map */
E 3
char	*statemap;		/* ptr to inode state table */
short	*lncntp;		/* ptr to link count table */

D 2
char	*srchname;		/* name being searched for in dir */
E 2
char	pathname[BUFSIZ];	/* current pathname */
char	*pathp;			/* pointer to pathname position */
char	*endpathname;

D 2
char	*lfname;

E 2
I 2
daddr_t	fmax;			/* number of blocks in the volume */
E 2
ino_t	imax;			/* number of inodes */
ino_t	lastino;		/* hiwater mark of inodes */
D 2
ino_t	lfdir;			/* lost & found directory */
E 2
I 2
ino_t	lfdir;			/* lost & found directory inode number */
char	*lfname;		/* lost & found directory name */
E 2

off_t	maxblk;			/* largest logical blk in file */
off_t	bmapsz;			/* num chars in blockmap */

D 3
daddr_t	n_ffree;		/* number of small free blocks */
daddr_t	n_bfree;		/* number of large free blocks */
E 3
daddr_t	n_blks;			/* number of blocks used */
daddr_t	n_files;		/* number of files seen */
D 3
daddr_t	n_index;
daddr_t	n_bad;
E 3
D 2
daddr_t	fmax;			/* number of blocks in the volume */
E 2

D 3
daddr_t	badblk;
daddr_t	dupblk;

int	inosumbad;
int	offsumbad;
int	frsumbad;
int	sbsumbad;

E 3
#define	zapino(x)	(*(x) = zino)
struct	dinode zino;

#define	setbmap(x)	setbit(blockmap, x)
#define	getbmap(x)	isset(blockmap, x)
#define	clrbmap(x)	clrbit(blockmap, x)
D 3

#define	setfmap(x)	setbit(freemap, x)
#define	getfmap(x)	isset(freemap, x)
#define	clrfmap(x)	clrbit(freemap, x)
E 3

I 8
#define	FOUND	020
E 8
#define	ALTERED	010
#define	KEEPON	04
#define	SKIP	02
#define	STOP	01

time_t	time();
DINODE	*ginode();
BUFAREA	*getblk();
int	findino();
E 1
