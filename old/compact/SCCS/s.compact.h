h54022
s 00005/00003/00064
d D 4.6 84/08/25 23:48:38 sam 6 5
c speed up balanced tree insertion
e
s 00034/00034/00033
d D 4.5 84/08/25 22:04:55 sam 5 4
c rewrite and speed up 
e
s 00003/00002/00064
d D 4.4 83/06/03 15:35:45 edward 4 3
c use MAXNAMLEN and MAXPATHLEN
e
s 00001/00001/00065
d D 4.3 83/05/04 16:39:23 sklower 3 2
c expand limits for 4.1c file system
e
s 00007/00005/00059
d D 4.2 83/02/23 22:50:05 shannon 2 1
c make mo re portable
e
s 00064/00000/00000
d D 4.1 83/02/11 14:58:38 shannon 1 0
c date and time created 83/02/11 14:58:38 by shannon
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

D 5
#define VAX 11/780


E 5
D 2
#ifdef VAX
E 2
I 2
#if defined(vax) || defined(sun)
E 2
typedef int longint;
#else
typedef long longint;
D 2
#include <retrofit.h>
E 2
#endif

D 4
#include <sys/types.h>
E 4
I 4
#include <sys/param.h>
E 4
#include <sys/stat.h>
I 4
#include <sys/dir.h>
E 4
#include <stdio.h>

D 3
#define LNAME 80
E 3
I 3
D 4
#define LNAME 1024
E 4
I 4
D 5
#define LNAME (MAXPATHLEN+1)
E 4
E 3
#define NEW flist; flist = flist -> next
#define LLEAF 010
#define RLEAF 04
#define SEEN 02
#define FBIT 01
E 5
#define COMPACTED 017777
D 5
#define PACKED 017437
#define EF 0400
#define NC 0401
E 5
I 5
#define PACKED	017437
E 5

struct charac {
D 2
	char lob;
	char hib;
E 2
I 2
#if defined(vax) || defined(pdp11)
D 5
	char lob, hib;
E 5
I 5
	char	lob, hib;
E 5
#else
D 5
	char hib, lob;
E 5
I 5
	char	hib, lob;
E 5
#endif
E 2
};

union cio {
D 5
	struct charac chars;
D 2
	int integ;
E 2
I 2
	short integ;
E 5
I 5
	struct	charac chars;
	short	integ;
E 5
E 2
};

I 5
#define LLEAF	010
#define RLEAF	04
#define SEEN	02
#define FBIT	01

#define EF	0400
#define NC	0401

#define	NF	(NC+1)

E 5
struct fpoint {
D 5
	struct node *fp;
	int flags;
} in [258];
E 5
I 5
	struct	node *fp;
	int	flags;
} in[NF];
E 5

struct index {
D 5
	struct node *pt;
	struct index *next;
} dir [514], *head, *flist, *dirp, *dirq;
E 5
I 5
	struct	node *pt;
	struct	index *next;
} dir[2*NF], *head, *flist, *dirp, *dirq;
E 5

I 5
#define	NEW	flist; flist = flist->next

E 5
union treep {
D 5
	struct node *p;
	int ch;
E 5
I 5
	struct	node *p;
	int	ch;
E 5
};

struct node {
D 5
	struct fpoint fath;
	union treep sp [2];
	struct index *top [2];
	longint count [2];
} dict [258], *bottom;
E 5
I 5
	struct	fpoint fath;
D 6
	union	treep sp[2];
	struct	index *top[2];
	longint	count[2];
E 6
I 6
	struct son {
		union	treep sp;
		struct	index *top;
		longint	count;
	} sons[2];
E 6
#define	LEFT	0
#define	RIGHT	1
} dict[NF], *bottom;
E 5

D 5
longint oc;

FILE *cfp, *uncfp;

struct stat status;
E 5
I 5
FILE	*cfp;
FILE	*uncfp;
E 5
E 1
