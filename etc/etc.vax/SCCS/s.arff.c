h35287
s 00007/00005/00931
d D 5.8 04/02/14 18:42:02 msokolov 29 28
c RT-11 V5.5 year extensions to 2099
c display dates in ISO 8601 format
e
s 00001/00001/00935
d D 5.7 04/02/14 17:56:15 msokolov 28 27
c c option directory initialization:	since Berkeley chose to allocate 4
c directory segments, only 480 blocks are available for data, not 486
e
s 00002/00000/00934
d D 5.6 87/12/26 12:20:53 bostic 27 25
c fix from John Gilmore for ANSI C
e
s 00016/00000/00934
d R 5.6 87/06/02 14:20:39 bostic 26 25
c arff is a vax specific program
e
s 00001/00001/00933
d D 5.5 87/05/01 08:17:10 bostic 25 24
c constant in conditional context; bug report 4.3BSD/etc/61
e
s 00006/00002/00928
d D 5.4 86/12/01 19:33:54 bostic 24 23
c recognize protected files; bug report 4.3BSD/etc/24
e
s 00014/00005/00916
d D 5.3 86/09/03 17:04:35 karels 23 22
c don't write empty directories back if initial read fails!
e
s 00118/00055/00803
d D 5.2 86/02/11 09:31:03 bloom 22 21
c new directory segments are now added, it lints, add defines for some
c structure references
e
s 00014/00002/00844
d D 5.1 85/06/06 10:58:49 dist 21 20
c Add copyright
e
s 00006/00003/00840
d D 4.17 83/11/18 10:47:47 ralph 20 19
c fixing extract command to work for multiple segments.
e
s 00019/00013/00824
d D 4.16 83/07/10 18:13:46 sam 19 18
c handle c flag sanely
e
s 00001/00001/00836
d D 4.15 83/07/02 00:18:01 sam 18 17
c include fixes
e
s 00001/00001/00836
d D 4.14 83/06/07 13:01:02 mckusick 17 16
c more intelligent error message per Bob Gray
e
s 00010/00008/00827
d D 4.13 83/04/22 17:15:55 helge 16 14
c now deletes files anywhere in the directory, and does not coredump
c if you try to access an uninitialized diskette
e
s 00011/00008/00827
d R 4.13 83/04/22 16:44:57 helge 15 14
c now deletes files anywhere in the directory, and does not coredump
c if you try to access an uninitialized diskette
e
s 00091/00084/00744
d D 4.12 82/12/23 11:42:21 sam 14 13
c a little more cleanup
e
s 00012/00003/00816
d D 4.11 82/06/27 16:20:22 wnj 13 12
c fix to x option per rich wales
e
s 00001/00001/00818
d D 4.10 82/06/27 15:50:32 wnj 12 11
c fix via cmu
e
s 00001/00001/00818
d D 4.9 82/06/27 15:42:24 wnj 11 10
c s/short/u_short/ in rt_len per ziebro.henr@parc-maxc
e
s 00429/00415/00390
d D 4.8 81/11/13 17:09:21 sam 10 9
c I had to read it, so I reformatted it.
e
s 00004/00005/00801
d D 4.7 81/07/08 15:07:02 root 9 8
c minor bug fixes
e
s 00014/00009/00792
d D 4.6 81/05/18 15:46:14 hickman 8 5
c Fix f and m options
e
s 00006/00004/00800
d R 4.7 81/05/18 15:38:40 hickman 7 6
c Really fixed the "f" option. Re added a removed read statement
e
s 00010/00007/00794
d R 4.6 81/05/12 16:46:14 hickman 6 5
c fixed "f" option so that it would create the target file if needed
e
s 00014/00010/00787
d D 4.5 81/04/08 18:18:40 root 5 4
c Fixed several bugs in multi-segment code:
c 1) initialized directory for ``c'' option wrong
c 2) didnt compute end of directory correctly when initing
c in general this program stands on its head to avoid letting
c the C compiler use types and the structure mechanism find things.
c the program is a big mess and needs to be cleaned up.
c i have little confidence in it in its present form /wnj
e
s 00036/00049/00761
d D 4.4 81/03/22 21:16:02 wnj 4 3
c multisegment dirs and cleanup
e
s 00097/00039/00713
d D 4.3 81/03/22 01:03:57 wnj 3 2
c first multi-segment version
e
s 00002/00002/00750
d D 4.2 80/11/03 15:29:30 bill 2 1
c read 128 bytes not 2
e
s 00752/00000/00000
d D 4.1 80/10/01 17:24:52 bill 1 0
c date and time created 80/10/01 17:24:52 by bill
e
u
U
t
T
I 21
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 21
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
D 14
static	char *sccsid = "%W% (Berkeley) %E%";
E 14
I 14
#ifndef lint
D 21
static	char sccsid[] = "%W% (Berkeley) %E%";
#endif
E 21
I 21
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 21
E 14
I 10

E 10
E 3
#include <sys/types.h>
#include <sys/stat.h>
D 18
#include <time.h>
E 18
I 18
#include <sys/time.h>
E 18
#include <signal.h>
#include <stdio.h>
I 19
#include <sys/file.h>
E 19
I 10

E 10
#define dbprintf printf
I 10

E 10
struct rt_dat {
D 4
unsigned short	int	rt_yr:5;	/*Year - 1972			*/
unsigned short	int	rt_dy:5;	/*day				*/
unsigned short	int	rt_mo:5;	/*month				*/
E 4
I 4
D 10
unsigned short	int	rt_yr:5;	/* Year - 1972			 */
unsigned short	int	rt_dy:5;	/* day				 */
unsigned short	int	rt_mo:5;	/* month				 */
E 10
I 10
	u_short	rt_yr:5;	/* year-1972 */
	u_short	rt_dy:5;	/* day */
D 29
	u_short	rt_mo:5;	/* month */
E 29
I 29
	u_short	rt_mo:4;	/* month */
	u_short	rt_yx:2;	/* year extension */
E 29
E 10
E 4
};
I 10

E 10
struct	rt_axent {
	char	rt_sent[14];
};

struct rt_ent {
D 4
	char  rt_pad;			/*unusued		     */
	char  rt_stat;			/*Type of entry, or end of seg*/
	unsigned short rt_name[3];	/*Name, 3 words in rad50 form */
	short rt_len;			/*Length of file	      */
	char  rt_chan;			/*Only used in temporary files*/
	char  rt_job;			/*Only used in temporary files*/
	struct rt_dat rt_date;		/*Creation Date			*/
E 4
I 4
D 10
	char  rt_pad;			/* unusued		     */
	char  rt_stat;			/* Type of entry, or end of seg */
	unsigned short rt_name[3];	/* Name, 3 words in rad50 form */
	short rt_len;			/* Length of file	      */
	char  rt_chan;			/* Only used in temporary files */
	char  rt_job;			/* Only used in temporary files */
	struct rt_dat rt_date;		/* Creation Date			 */
E 10
I 10
	char	rt_pad;		/* unusued */
D 24
	char	rt_stat;	/* type of entry, or end of seg */
E 24
I 24
	u_char	rt_stat;	/* type of entry, or end of seg */
E 24
	u_short	rt_name[3];	/* name, 3 words in rad50 form */
D 11
	short	rt_len;		/* length of file */
E 11
I 11
	u_short	rt_len;		/* length of file */
E 11
D 24
	char	rt_chan;	/* only used in temporary files */
E 24
I 24
	u_char	rt_chan;	/* only used in temporary files */
E 24
	char	rt_job;		/* only used in temporary files */
D 14
	struct rt_dat rt_date;	/* creation date */
E 14
I 14
	struct	rt_dat rt_date;	/* creation date */
E 14
E 10
E 4
};
D 10
#define RT_TEMP 1
#define RT_NULL 2
#define RT_FILE 4
#define RT_ESEG 8
#define RT_BLOCK 512
I 3
#define RT_DIRSIZE 31			/* max # of directory segments */
E 10
I 10

#define RT_TEMP		1
#define RT_NULL		2
#define RT_FILE		4
I 24
#define RT_PFILE	(0200|RT_FILE)	/* protected file */
E 24
#define RT_ESEG		8

#define RT_BLOCK	512	/* block size */
#define RT_DIRSIZE	31	/* max # of directory segments */

E 10
E 3
struct rt_head {
D 4
	short	rt_numseg;		/*number of segments available*/
	short	rt_nxtseg;		/*segment no of next log. seg */
	short	rt_lstseg;		/*highest seg currenltly open */
	unsigned short	rt_entpad;	/*extra words/dir. entry      */
	short	rt_stfile;		/*block no where files begin  */
E 4
I 4
D 10
	short	rt_numseg;		/* number of segments available */
	short	rt_nxtseg;		/* segment no of next log. seg */
	short	rt_lstseg;		/* highest seg currenltly open */
	unsigned short	rt_entpad;	/* extra words/dir. entry      */
	short	rt_stfile;		/* block no where files begin  */
E 10
I 10
	short	rt_numseg;	/* # of segments available */
	short	rt_nxtseg;	/* # of next logical segment */
	short	rt_lstseg;	/* highest seg currently open */
	u_short	rt_entpad;	/* extra words/directory entry */
	short	rt_stfile;	/* block # where files begin */
E 10
E 4
};
I 10

E 10
struct	rt_dir {
	struct rt_head	rt_axhead;
	struct rt_ent	rt_ents[72];
D 10
	char	_dirpad[6];
E 10
I 10
	char		_dirpad[6];
E 10
};
I 10

I 22
#define rd_numseg rt_axhead.rt_numseg
#define rd_nxtseg rt_axhead.rt_nxtseg
#define rd_lstseg rt_axhead.rt_lstseg
#define rd_entpad rt_axhead.rt_entpad
#define rd_stfile rt_axhead.rt_stfile

E 22
E 10
D 3
extern struct rt_dir	rt_dir;
E 3
I 3
D 14
extern struct rt_dir	rt_dir[RT_DIRSIZE];
E 3
extern int		rt_entsiz;
extern int		floppydes;
extern char		*rt_last;
I 10

E 14
E 10
typedef struct fldope {
	int	startad;
	int	count;
struct	rt_ent	*rtdope;
} FLDOPE;
I 10

E 10
FLDOPE *lookup();
I 10

E 10
D 14
#define rt(p) ((struct rt_ent *) p )
#define Ain1 03100
#define Ain2 050
D 10
#define flag(c) (flg[(c) - 'a'])
E 10
I 10
#define flag(c) (flg[('c') - 'a'])
E 14
I 14
#define	rt(p)	((struct rt_ent *) p )
#define	Ain1	03100
#define	Ain2	050
#define	flag(c)	(flg[('c') - 'a'])
E 14
E 10

D 10
char	*man	=	{ "rxtd" };

E 10
I 10
D 14
char *man = "rxtd";
E 10
char zeroes[512];
E 14
I 14
char	*man = "rxtd";
char	zeroes[512];
E 14
I 10

E 10
extern char *val;
extern char table[256];
D 3
struct rt_dir	rt_dir = {{4,0,1,0,14},{0,RT_NULL,{0,0,0},494,0}, {0,RT_ESEG}};
E 3
I 3
D 10
struct rt_dir	
D 5
   rt_dir[RT_DIRSIZE] = {{4,0,1,0,14},{0,RT_NULL,{0,0,0},494,0}, {0,RT_ESEG}};
E 5
I 5
   rt_dir[RT_DIRSIZE] = {{{4,0,1,0,14},{0,RT_NULL,{0,0,0},494,0}, {0,RT_ESEG}}};
E 5
E 3
int		rt_entsiz;
int		rt_nleft;
D 3
struct rt_ent	*rt_curend;
E 3
I 3
struct rt_ent	*rt_curend[RT_DIRSIZE];
E 3
int		floppydes;
int		dirdirty;
char		*rt_last;
char		*defdev = "/dev/floppy";
E 10
I 10
struct rt_dir rt_dir[RT_DIRSIZE] = {
I 27
	{
E 27
D 14
	{4, 0, 1, 0, 14},
	{ {0, RT_NULL, {0, 0, 0}, 494, 0}, {0, RT_ESEG} }
E 14
I 14
	{ 4, 0, 1, 0, 14 },
D 22
	{ { 0, RT_NULL, { 0, 0, 0 }, 494, 0 },
E 22
I 22
D 28
	{ { 0, RT_NULL, { 0, 0, 0 }, 486, 0 },
E 28
I 28
	{ { 0, RT_NULL, { 0, 0, 0 }, 480, 0 },
E 28
E 22
	  { 0, RT_ESEG } }
I 27
	}
E 27
E 14
};
E 10

I 22
struct rt_dir rt_nulldir = {
	{ 0, 0, 0, 0, 0 },
	{ { 0, RT_NULL, { 0, 0, 0 }, 0, 0 },
	  { 0, RT_ESEG } }
};

E 22
D 10
char	*opt	=	{ "vf" };
E 10
I 10
int	rt_entsiz;
int	rt_nleft;
struct rt_ent *rt_curend[RT_DIRSIZE];
int	floppydes;
int	dirdirty;
char	*rt_last;
char	*defdev = "/dev/floppy";
E 10

I 10
D 22
char *opt = "vf";
E 22
I 22
char *opt = "vfbcm";
E 22

E 10
D 22
int	signum[] = {SIGHUP, SIGINT, SIGQUIT, 0};
E 22
D 10
long	lseek();
int	rcmd();
int	dcmd();
int	xcmd();
int	tcmd();
E 10
I 10
extern long lseek();
int	rcmd(), dcmd(), xcmd(), tcmd();

E 10
int	(*comfun)();
char	flg[26];
char	**namv;
int	namc;
D 22
int	file;
E 22

D 10

E 10
main(argc, argv)
D 10
char *argv[];
E 10
I 10
	char *argv[];
E 10
{
	register char *cp;

D 4
	/*register i;
E 4
I 4
D 10
	/* register i;
E 4
	for(i=0; signum[i]; i++)
		if(signal(signum[i], SIG_IGN) != SIG_IGN)
D 4
			signal(signum[i], sigdone);*/
E 4
I 4
			signal(signum[i], sigdone); */
E 4
	if(argc < 2)
E 10
I 10
	if (argc < 2)
E 10
		usage();
D 16
	cp = argv[1];
E 16
D 10
	for(cp = argv[1]; *cp; cp++)
	switch(*cp) {
	case 'm':
	case 'v':
	case 'u':
	case 'w':
		flg[*cp - 'a']++;
		continue;
	case 'c':
		{
#define SURE	"Are you sure you want to clobber the floppy?\n"
			int tty;
D 2
			char response[2];
E 2
I 2
			char response[128];
E 2
			tty = open("/dev/tty",2);
			write(tty,SURE,sizeof(SURE));
D 2
			read(tty,response,2);
E 2
I 2
D 4
			read(tty,response,128);
E 4
I 4
			read(tty,response,sizeof(response));
E 4
E 2
			if(*response!='y')
				exit(50);
			flag('c')++;
			close(tty);
		}
		dirdirty++;
		continue;
E 10
I 10
	for (cp = argv[1]; *cp; cp++)
		switch (*cp) {
E 10

D 10
	case 'r':
		setcom(rcmd);
		flag('r')++;
		continue;
E 10
I 10
		case 'm':
		case 'v':
		case 'u':
		case 'w':
I 22
		case 'b':
E 22
			flg[*cp-'a']++;
			continue;
		case 'c':
D 19
			{
D 17
#define SURE	"Last chance before clobbering floppy?"
E 17
I 17
#define SURE	"Are you sure you want to clobber the floppy?"
E 17
				int tty;
				char response[128];
E 10

D 10
	case 'd':
		setcom(dcmd);
		flag('d')++;
		continue;
E 10
I 10
				tty = open("/dev/tty", 2);
				write(tty, SURE, sizeof(SURE));
				read(tty, response, sizeof(response));
				if (*response != 'y')
					exit(50);
				flag(c)++;
				close(tty);
			}
E 19
I 19
			flag(c)++;
E 19
			dirdirty++;
			continue;
E 10

D 10
	case 'x':
		setcom(xcmd);
		continue;
E 10
I 10
		case 'r':
			setcom(rcmd);
			flag(r)++;
			continue;
E 10

D 10
	case 't':
		setcom(tcmd);
		continue;
E 10
I 10
		case 'd':
			setcom(dcmd);
			flag(d)++;
			continue;
E 10

D 10
	case 'f':
		defdev = argv[2];
		argv++;
		argc--;
		continue;
E 10
I 10
		case 'x':
			setcom(xcmd);
			continue;
E 10

I 10
		case 't':
			setcom(tcmd);
			continue;
E 10

D 10
	default:
		fprintf(stderr, "arff: bad option `%c'\n", *cp);
		exit(1);
	}
E 10
I 10
		case 'f':
			defdev = argv[2];
			argv++;
			argc--;
			continue;

		default:
			fprintf(stderr, "arff: bad option `%c'\n", *cp);
			exit(1);
		}

E 10
	namv = argv+2;
	namc = argc-2;
D 10
	if(comfun == 0) {
		if(flg['u'-'a'] == 0) {
			fprintf(stderr, "arff: one of [%s] must be specified\n", man);
E 10
I 10
	if (comfun == 0) {
		if (flag(u) == 0) {
			fprintf(stderr, "arff: one of [%s] must be specified\n",
				man);
E 10
			exit(1);
		}
		setcom(rcmd);
	}
	(*comfun)();
	exit(notfound());
}

setcom(fun)
D 10
int (*fun)();
E 10
I 10
	int (*fun)();
E 10
{
D 10

	if(comfun != 0) {
E 10
I 10
	if (comfun != 0) {
E 10
		fprintf(stderr, "arff: only one of [%s] allowed\n", man);
		exit(1);
	}
	comfun = fun;
}

D 4







E 4
usage()
{
D 4
	printf("usage: ar [%s][%s] archive files ...\n", opt, man);
E 4
I 4
D 10

E 10
	fprintf(stderr, "usage: ar [%s][%s] archive files ...\n", opt, man);
E 4
	exit(1);
}

D 4


E 4
notfound()
{
D 10
	register i, n;
E 10
I 10
	register i, n = 0;
E 10

D 10
	n = 0;
	for(i=0; i<namc; i++)
		if(namv[i]) {
E 10
I 10
	for (i = 0; i < namc; i++)
		if (namv[i]) {
E 10
			fprintf(stderr, "arff: %s not found\n", namv[i]);
			n++;
		}
D 14
	return(n);
E 14
I 14
	return (n);
E 14
}

D 4


E 4
D 10
phserr()
{

	fprintf(stderr, "arff: phase error on %s\n", file);
}

E 10
D 22
mesg(c)
{
D 10

	if(flg['v'-'a'])
		if(c != 'c' || flg['v'-'a'] > 1)
E 10
I 10
	if (flag(v))
		if (c != 'c' || flag(v) > 1)
E 10
			printf("%c - %s\n", c, file);
}

E 22
tcmd()
{
D 10
	register char *de;
I 3
	int segnum;
	register char *last;
E 10
I 10
	register char *de, *last;
E 10
E 3
	FLDOPE *lookup(), *dope;
D 10
	int nleft; register i;
E 10
I 10
	int segnum, nleft;
	register i;
E 10
	register struct rt_ent *rde;

	rt_init();
D 10
	if(namc==0)
D 3
		for(de=((char *)&rt_dir)+10; de <= rt_last; de += rt_entsiz) {
E 3
I 3
	    for (segnum=0; segnum != -1;    /* for all dir. segments */
		 segnum = rt_dir[segnum].rt_axhead.rt_nxtseg - 1) {
		last = rt_last + segnum*2*RT_BLOCK;
		for(de=((char *)&rt_dir[segnum])+10; de <= last; 
		    de += rt_entsiz) {
E 3
			if(rtls(rt(de))) {
D 3
				nleft = (rt_last - de) / rt_entsiz;
				printf("\n\n%d entries remaining.\n",nleft);
E 3
I 3
				nleft = (last - de) / rt_entsiz;
				printf("\n%d entries remaining",nleft);
				printf(" in directory segment %d.\n",segnum+1);
E 3
				break;
			}
E 10
I 10
D 14
	if (namc == 0)
		for (segnum = 0; segnum != -1;
		     segnum = rt_dir[segnum].rt_axhead.rt_nxtseg - 1)
		{
			last = rt_last + segnum*2*RT_BLOCK;
			for (de = ((char *)&rt_dir[segnum])+10; de <= last; 
			    de += rt_entsiz)
				if (rtls(rt(de))) {
					nleft = (last-de)/rt_entsiz;
#define ENTRIES "\n%d entries remaining in directory segment %d.\n"
					printf(ENTRIES, nleft, segnum+1);
					break;
				}
E 10
		}
I 3
D 10
	    }
E 10
E 3
	else
E 14
I 14
	if (namc != 0) {
E 14
D 10
		for(i = 0; i < namc; i++) {
			if(dope = lookup(namv[i])) {
E 10
I 10
		for (i = 0; i < namc; i++)
			if (dope = lookup(namv[i])) {
E 10
				rde = dope->rtdope;
D 22
				rtls(rde);
E 22
I 22
				(void) rtls(rde);
E 22
				namv[i] = 0;
			}
I 14
		return;
	}
	for (segnum = 0; segnum != -1;
D 22
	  segnum = rt_dir[segnum].rt_axhead.rt_nxtseg - 1) {
E 22
I 22
	  segnum = rt_dir[segnum].rd_nxtseg - 1) {
E 22
		last = rt_last + segnum*2*RT_BLOCK;
		for (de = ((char *)&rt_dir[segnum])+10; de <= last; 
		    de += rt_entsiz)
			if (rtls(rt(de))) {
				nleft = (last-de)/rt_entsiz;
#define ENTRIES "\n%d entries remaining in directory segment %d.\n"
				printf(ENTRIES, nleft, segnum+1);
				break;
			}
	}
E 14
D 10
		}
E 10
}
I 10

E 10
rtls(de)
D 10
register struct rt_ent *de;
E 10
I 10
	register struct rt_ent *de;
E 10
{
D 10
	int month,day,year;
E 10
I 10
	int month, day, year;
E 10
	char name[12], ext[4];

D 10
	if(flg['v'-'a'])
		switch(de->rt_stat) {
		case RT_TEMP:
E 10
I 10
	switch (de->rt_stat) {

	case RT_TEMP:
		if (flag(v))
E 10
			printf("Tempfile:\n");
D 10
		case RT_FILE:
			unrad50(2,de->rt_name,name);
			unrad50(1,&(de->rt_name[2]),ext);
			day = de->rt_date.rt_dy;
			year = de->rt_date.rt_yr + 72;
			month = de->rt_date.rt_mo;
			printf("%6.6s  %3.3s	%02d/%02d/%02d	%d\n",name,
				ext,month,day,year,de->rt_len);
			break;
E 10
I 10
		/* fall thru...*/
E 10

D 10
		case RT_NULL:
			printf("%-25.9s	%d\n","<UNUSED>",de->rt_len);
E 10
I 10
	case RT_FILE:
I 24
	case RT_PFILE:
E 24
		if (!flag(v)) {
			sunrad50(name, de->rt_name);
			printf("%s\n", name);
E 10
			break;
D 10

		case RT_ESEG:
			return(1);
E 10
		}
D 10
	else {
		switch(de->rt_stat) {
		case RT_TEMP:
		case RT_FILE:
			sunrad50(name,de->rt_name);
			printf(name);putchar('\n');
			break;
E 10
I 10
		unrad50(2, de->rt_name, name);
		unrad50(1, &(de->rt_name[2]), ext);
		day = de->rt_date.rt_dy;
D 29
		year = de->rt_date.rt_yr+72;
E 29
I 29
		year = (de->rt_date.rt_yx<<5 | de->rt_date.rt_yr) + 1972;
E 29
		month = de->rt_date.rt_mo;
D 29
		printf("%6.6s  %3.3s	%02d/%02d/%02d	%d\n",name,
			ext, month, day, year, de->rt_len);
E 29
I 29
		printf("%6.6s  %3.3s	%04d-%02d-%02d	%d\n",name,
			ext, year, month, day, de->rt_len);
E 29
		break;
E 10

D 10
		case RT_ESEG:
			return(1);
E 10
I 10
	case RT_NULL:
		printf("%-25.9s	%d\n","<UNUSED>", de->rt_len);
		break;
E 10

D 10
		case RT_NULL:
			;
		}
E 10
I 10
	case RT_ESEG:
D 14
		return(1);
E 14
I 14
		return (1);
E 14
E 10
	}
D 14
	return(0);
E 14
I 14
	return (0);
E 14
}
I 10

E 10
xcmd()
{
D 10
	register char *de;
E 10
I 10
	register char *de, *last;
E 10
I 3
	int segnum;
D 10
	register char *last;
E 10
E 3
	char name[12];
	register int i;

	rt_init();
D 10
	if(namc==0)
D 3
		for(de=((char *)&rt_dir)+10; de <= rt_last; de += rt_entsiz) {
E 3
I 3
	    for (segnum=0; segnum != -1;    /* for all dir. segments */
		 segnum = rt_dir[segnum].rt_axhead.rt_nxtseg - 1) {
		last = rt_last + segnum*2*RT_BLOCK;
		for(de=((char *)&rt_dir[segnum])+10; de <= last; 
		    de += rt_entsiz) {
E 3
			sunrad50(name,rt(de)->rt_name);
			rtx(name);
		}
I 3
	    }
E 10
I 10
D 13
	if (namc == 0)
E 13
I 13
D 14
	if (namc == 0) {
E 13
		for (segnum = 0; segnum != -1;
		     segnum = rt_dir[segnum].rt_axhead.rt_nxtseg-1)
			for (last = rt_last+(segnum*2*RT_BLOCK),
			     de = ((char *)&rt_dir[segnum])+10; de <= last; 
			     de += rt_entsiz)
D 13
				sunrad50(name, rt(de)->rt_name), rtx(name);
E 10
E 3
D 4

E 4
	else
E 13
I 13
				switch (rt(de)->rt_stat) {
				case RT_ESEG:
					return;
				case RT_TEMP:
				case RT_FILE:
					sunrad50(name,rt(de)->rt_name);
					rtx(name);
				case RT_NULL:
				;
				}
	} else
E 14
I 14
	if (namc != 0) {
E 14
E 13
D 10
		for(i = 0; i < namc; i++)
		if(rtx(namv[i])==0) namv[i] = 0;
E 10
I 10
		for (i = 0; i < namc; i++)
			if (rtx(namv[i]) == 0)
				namv[i] = 0;
I 14
		return;
	}
	for (segnum = 0; segnum != -1;
D 22
	     segnum = rt_dir[segnum].rt_axhead.rt_nxtseg-1)
E 22
I 22
	     segnum = rt_dir[segnum].rd_nxtseg-1)
E 22
		for (last = rt_last+(segnum*2*RT_BLOCK),
		     de = ((char *)&rt_dir[segnum])+10; de <= last; 
D 20
		     de += rt_entsiz)
E 20
I 20
		     de += rt_entsiz) {
E 20
			switch (rt(de)->rt_stat) {

			case RT_ESEG:
D 20
				return;
E 20
I 20
				break;	/* exit loop and try next segment */
E 20

			case RT_TEMP:
			case RT_FILE:
I 24
			case RT_PFILE:
E 24
				sunrad50(name,rt(de)->rt_name);
D 22
				rtx(name);
E 22
I 22
				(void) rtx(name);
E 22

			case RT_NULL:
D 20
				break;
E 20
I 20
			default:
				continue;
E 20
			}
I 20
			break;
		}
E 20
E 14
E 10
}
I 10

E 10
rtx(name)
D 10
char *name;
E 10
I 10
	char *name;
E 10
{
	register FLDOPE *dope;
	FLDOPE *lookup();
	register startad, count;
D 10
	int file; char buff[512];
E 10
I 10
	int file;
	char buff[512];
E 10


D 10
	if(dope = lookup(name)) {
		if(flg['v' - 'a'])
E 10
I 10
	if (dope = lookup(name)) {
		if (flag(v))
E 10
D 22
			rtls(dope->rtdope);
E 22
I 22
			(void) rtls(dope->rtdope);
E 22
		else
			printf("x - %s\n",name);

D 10
		file = creat(name, 0666);
		if(file < 0) return(1);
E 10
I 10
		if ((file = creat(name, 0666)) < 0)
D 14
			return(1);
E 14
I 14
			return (1);
E 14
E 10
		count = dope->count;
		startad = dope->startad;
		for( ; count > 0 ; count -= 512) {
D 10
			lread(startad,512,buff);
			write(file,buff,512);
E 10
I 10
D 23
			lread(startad, 512, buff);
E 23
I 23
			(void) lread(startad, 512, buff);
E 23
D 22
			write(file, buff, 512);
E 22
I 22
			(void) write(file, buff, 512);
E 22
E 10
			startad += 512;
		}
D 22
		close(file);
E 22
I 22
		(void) close(file);
E 22
D 14
		return(0);
E 14
I 14
		return (0);
E 14
	}
D 14
	return(1);
E 14
I 14
	return (1);
E 14
}
I 10

E 10
rt_init()
{
	static initized = 0;
D 10
	register char *de;
E 10
I 10
	register char *de, *last;
E 10
D 3
	int mode;
E 3
I 3
	register i;
D 8
	int mode, dirnum;
E 8
I 8
	int dirnum;
	char *mode;
E 8
D 10
	register char *last;
E 10
I 8
	FILE *temp_floppydes;
E 8
E 3

D 10
	if(initized) return;
E 10
I 10
	if (initized)
		return;
E 10
	initized = 1;
I 19
	if (flag(c)) {
		struct stat sb;
		char response[128];
		int tty;

		if (stat(defdev, &sb) >= 0 && (sb.st_mode & S_IFMT) == S_IFREG)
			goto ignore;
		tty = open("/dev/tty", O_RDWR);
#define SURE	"Are you sure you want to clobber the floppy? "
D 22
		write(tty, SURE, sizeof (SURE));
		read(tty, response, sizeof (response));
E 22
I 22
		(void) write(tty, SURE, sizeof (SURE));
		(void) read(tty, response, sizeof (response));
E 22
		if (*response != 'y')
			exit(50);
D 22
		close(tty);
E 22
I 22
		(void) close(tty);
E 22
ignore:
		;
	}
E 19
D 10
	if(flag('c') || flag('d') || flag('r'))
E 10
I 10
	if (flag(c) || flag(d) || flag(r))
E 10
D 8
		mode = 2;
E 8
I 8
		mode = "r+";
E 8
	else
D 8
		mode = 0;
D 4
	if((floppydes = open(defdev,mode)) < 0)
E 4
I 4
	if((floppydes = open(defdev,mode)) < 0) {
E 4
		dbprintf("Floppy open failed\n");
E 8
I 8
		mode = "r";
D 10
	if((temp_floppydes = fopen(defdev, mode)) == NULL) {
E 10
I 10
	if ((temp_floppydes = fopen(defdev, mode)) == NULL) {
E 10
		perror(defdev);
E 8
I 4
		exit(1);
D 8
	}
E 8
I 8
	} else
		floppydes = fileno(temp_floppydes);
E 8
E 4
D 3
	if(flag('c')==0)
		lread(6*RT_BLOCK,2*RT_BLOCK,(char *)&rt_dir);
E 3
I 3
D 10
	if(flag('c')==0) {
		lread(6*RT_BLOCK,2*RT_BLOCK,(char *)&rt_dir[0]);
E 10
I 10
	if (!flag(c)) {
D 23
		lread(6*RT_BLOCK, 2*RT_BLOCK, (char *)&rt_dir[0]);
E 23
I 23
		if (lread(6*RT_BLOCK, 2*RT_BLOCK, (char *)&rt_dir[0]))
			exit(2);
E 23
E 10
D 22
		dirnum = rt_dir[0].rt_axhead.rt_numseg;
E 22
I 22
		dirnum = rt_dir[0].rd_numseg;
E 22
I 16
		/* check for blank/uninitialized diskette */
		if (dirnum <= 0) {
			fprintf(stderr,"arff: bad directory format\n");
			exit(1);
		}
E 16
		if (dirnum > RT_DIRSIZE) {
D 10
		   fprintf(stderr,"arff: too many directory segments\n");
		   exit(1);
E 10
I 10
			fprintf(stderr,"arff: too many directory segments\n");
			exit(1);
E 10
		}
D 10
		for (i=1; i<dirnum; i++)
		   lread((6+2*i)*RT_BLOCK,2*RT_BLOCK,(char *)&rt_dir[i]);
E 10
I 10
		for (i = 1; i < dirnum; i++)
D 23
			lread((6+2*i)*RT_BLOCK, 2*RT_BLOCK, (char *)&rt_dir[i]);
E 23
I 23
		    if (lread((6+2*i)*RT_BLOCK, 2*RT_BLOCK, (char *)&rt_dir[i]))
			exit(1);
E 23
E 10
D 5
	}
E 5
I 5
D 22
	} else
E 22
I 22
	} else {
E 22
		dirnum = 1;
I 22
		if (flag(b)) {
			rt_dir[0].rd_numseg = 31;
			rt_dir[0].rd_stfile = 68;
			rt_dir[0].rt_ents[0].rt_len = 20480 - 68;
		}
	}
E 22
E 5
E 3

D 3
	rt_entsiz = 2*rt_dir.rt_axhead.rt_entpad + 14;
	rt_entsiz = 14;
	rt_last = ((char *) &rt_dir) + 10 + 1014/rt_entsiz*rt_entsiz;
	for(de=((char *)&rt_dir)+10; de <= rt_last; de += rt_entsiz) {
E 3
I 3
D 22
	rt_entsiz = 2*rt_dir[0].rt_axhead.rt_entpad + 14;
	rt_entsiz = 14;			/* assume rt_entpad = 0 ??? */
E 22
I 22
	rt_entsiz = 2*rt_dir[0].rd_entpad + 14;
	/*
	 * We assume that the directory entries have no padding.  This
	 * may not be a valid assumption, but there are numerous point
	 * in the code where it assumes it is an rt_ent structure and
	 * not an rt_entsiz sized structure.
	 */
	rt_entsiz = 14;
E 22
	rt_last = ((char *) &rt_dir[0]) + 10 + 1014/rt_entsiz*rt_entsiz; 
	rt_nleft = 0;
	
D 10
	for (i=0; i<dirnum; i++) {
  	    last = rt_last + i*2*RT_BLOCK;
	    for(de=((char *)&rt_dir[i])+10; de <= last; de += rt_entsiz) {
E 3
		if(rt(de)->rt_stat==RT_ESEG) break;
I 3
	    }
	    rt_curend[i] = rt(de);
	    rt_nleft += (last - de) / rt_entsiz;
E 10
I 10
	for (i = 0; i < dirnum; i++) {
		last = rt_last + i*2*RT_BLOCK;
		for (de = ((char *)&rt_dir[i])+10; de <= last; de += rt_entsiz)
			if (rt(de)->rt_stat == RT_ESEG)
				break;
		rt_curend[i] = rt(de);
		rt_nleft += (last-de)/rt_entsiz;
E 10
E 3
	}
D 3
	rt_curend = rt(de);
	rt_nleft = (rt_last - de) / rt_entsiz;
E 3
}

static FLDOPE result;
I 10

E 10
FLDOPE *
lookup(name)
D 10
char * name;
E 10
I 10
	char *name;
E 10
{
	unsigned short rname[3];
D 10
	register char *de;
E 10
I 10
D 22
	register char *de, *last;
E 22
I 22
	register char *de;
E 22
E 10
I 3
	int segnum;
D 10
	register char *last;
E 10
E 3
	register index;

	srad50(name,rname);

D 4
	/*
E 4
I 4
	/* 
E 4
	 *  Search for name, accumulate blocks in index
	 */
	rt_init();
D 3
	index = 0;
	for(de = ((char *) &rt_dir) + 10; de <= rt_last; de += rt_entsiz) {
E 3
I 3
D 10
	for (segnum=0; segnum != -1;    /* for all dir. segments */
             segnum = rt_dir[segnum].rt_axhead.rt_nxtseg - 1) {
	    index = 0;
	    last = rt_last + segnum*2*RT_BLOCK;
	    for(de=((char *)&rt_dir[segnum])+10; 
		rt(de)->rt_stat != RT_ESEG; de += rt_entsiz) {
E 3
		switch(rt(de)->rt_stat) {
D 4
		case RT_ESEG:
D 3
			return((FLDOPE *) 0);
E 3
I 3
		        exit(1);
E 4
E 3
		case RT_FILE:
		case RT_TEMP:
		if(samename(rname,rt(de)->rt_name))
			goto found;
		case RT_NULL:
			index += rt(de)->rt_len;
		}
D 3
	}
E 3
I 3
	    }
E 10
I 10
	for (segnum = 0; segnum != -1;
D 22
	     segnum = rt_dir[segnum].rt_axhead.rt_nxtseg - 1)
E 22
I 22
	     segnum = rt_dir[segnum].rd_nxtseg - 1)
E 22
	{
		index = 0;
D 22
		last = rt_last + segnum*2*RT_BLOCK;
E 22
		for (de=((char *)&rt_dir[segnum])+10; 
		     rt(de)->rt_stat != RT_ESEG; de += rt_entsiz)
			switch(rt(de)->rt_stat) {

			case RT_FILE:
I 24
			case RT_PFILE:
E 24
			case RT_TEMP:
				if(samename(rname,rt(de)->rt_name)) {
					result.count = rt(de)->rt_len * 512;
					result.startad = 512*
D 22
						(rt_dir[segnum].rt_axhead.rt_stfile + index);
E 22
I 22
					    (rt_dir[segnum].rd_stfile + index);
E 22
					result.rtdope = (struct rt_ent *) de;
D 14
					return(&result);
E 14
I 14
					return (&result);
E 14
				}

			case RT_NULL:
				index += rt(de)->rt_len;
			}
E 10
        }
E 3
D 14
	return((FLDOPE *) 0);
E 14
I 14
	return ((FLDOPE *) 0);
E 14
D 10
found:	result.count = rt(de)->rt_len * 512;
D 3
	result.startad = 512 * (rt_dir.rt_axhead.rt_stfile + index);
E 3
I 3
	result.startad = 512 * (rt_dir[segnum].rt_axhead.rt_stfile + index);
E 3
	result.rtdope = (struct rt_ent *) de;
	return(&result);
E 10
I 10

E 10
}
I 10

E 10
static
D 10
samename(a,b)
unsigned short a[3],b[3];
E 10
I 10
samename(a, b)
	u_short a[], b[];
E 10
{
D 10
	return( a[0]==b[0] && a[1]==b[1] && a[2]==b[2] );
E 10
I 10
D 14
	return(*a == *b && a[1] == b[1] && a[2] == b[2] );
E 14
I 14
	return (*a == *b && a[1] == b[1] && a[2] == b[2] );
E 14
E 10
}

D 10

rad50(cp,out)
register unsigned char *cp;
unsigned short *out;
E 10
I 10
rad50(cp, out)
	register u_char *cp;
	u_short *out;
E 10
{
D 10
	register index;
	register temp;
E 10
I 10
	register index, temp;
E 10

D 10
	for(index = 0;*cp; index++) {

E 10
I 10
	for (index = 0; *cp; index++) {
E 10
		temp = Ain1 * table[*cp++];
D 10
		if(*cp!=0) {
E 10
I 10
		if (*cp!=0) {
E 10
			temp += Ain2 * table[*cp++];
D 10

E 10
			if(*cp!=0) 
				temp += table[*cp++];
		}
D 10

E 10
		out[index] = temp;
	}
}
D 10
#define reduce(x,p,q) \
	(x = v[p/q], p %= q);
E 10

D 10
unrad50(count,in,cp)
unsigned short *in;
register char *cp;
E 10
I 10
#define reduce(x, p, q) (x = v[p/q], p %= q);

unrad50(count, in, cp)
	u_short *in;
	register char *cp;
E 10
{
D 10
	register i, temp; register unsigned char *v = (unsigned char *) val;
E 10
I 10
	register i, temp;
	register u_char *v = (u_char *) val;
E 10
	
D 10
	for(i = 0; i < count; i++) {
E 10
I 10
	for (i = 0; i < count; i++) {
E 10
		temp = in[i];
D 10

		reduce (*cp++,temp,Ain1);
		reduce (*cp++,temp,Ain2);
		reduce (*cp++,temp,1);
E 10
I 10
		reduce(*cp++, temp, Ain1);
		reduce(*cp++, temp, Ain2);
		reduce(*cp++, temp, 1);
E 10
	}
	*cp=0;
}

D 10
srad50(name,rname)
register char * name;
register unsigned short *rname;
E 10
I 10
srad50(name, rname)
	register char *name;
	register u_short *rname;
E 10
{
D 10
	register index; register char *cp;
	char file[7],ext[4];
E 10
I 10
	register index;
	register char *cp;
	char file[7], ext[4];

E 10
D 4
	/*
E 4
I 4
	/* 
E 4
	 * Find end of pathname
	 */
D 10
	for(cp = name; *cp++; );
	while(cp >= name && *--cp != '/');
E 10
I 10
	for (cp = name; *cp++; )
		;
	while (cp >= name && *--cp != '/')
		;
E 10
	cp++;
D 4
	/*
E 4
I 4
	/* 
E 4
	 * Change to rad50
D 10
	 *
E 10
	 */
D 10
	for(index = 0; *cp; ){
E 10
I 10
	for (index = 0; *cp; ) {
E 10
		file[index++] = *cp++;
D 10
		if(*cp=='.') {
E 10
I 10
		if (*cp == '.') {
E 10
			cp++;
			break;
		}
D 10
		if(index>=6) {
E 10
I 10
		if (index >= 6) {
E 10
			break;
		}
	}
	file[index] = 0;
D 10
	for(index = 0; *cp; ){
E 10
I 10
	for (index = 0; *cp; ) {
E 10
		ext[index++] = *cp++;
D 10
		if(*cp=='.' || index>=3) {
E 10
I 10
		if (*cp == '.' || index >= 3)
E 10
			break;
D 10
		}
E 10
	}
	ext[index]=0;
D 10
	rname[0] = 0;
	rname[1] = 0;
	rname[2] = 0;
	rad50((unsigned char *)file,rname);
	rad50((unsigned char *)ext,rname+2);
E 10
I 10
	rname[0] = rname[1] = rname[2] = 0;
	rad50((u_char *)file, rname);
	rad50((u_char *)ext, rname+2);
E 10
}
D 10
sunrad50(name,rname)
unsigned short rname[3];
register char *name;
E 10
I 10

sunrad50(name, rname)
	u_short rname[];
	register char *name;
E 10
{
	register char *cp, *cp2;
	char ext[4];

D 10
	unrad50(2,rname,name);
	unrad50(1,rname + 2,ext);
	/* Jam name and extension together with a dot
	   deleting white space */
	for(cp = name; *cp++;);--cp;  while(*--cp==' ' && cp>=name);
	*++cp = '.';cp++;
	for(cp2=ext; *cp2!=' ' && cp2 < ext + 3;) {
E 10
I 10
	unrad50(2, rname, name);
	unrad50(1, rname + 2, ext);
	/*
	 * Jam name and extension together with a dot
	 * deleting white space
	 */
	for (cp = name; *cp++;)
		;
	--cp;
	while (*--cp == ' ' && cp >= name)
		;
	*++cp = '.';
	cp++;
	for (cp2 = ext; *cp2 != ' ' && cp2 < ext+3;)
E 10
		*cp++ = *cp2++;
D 10
	}
E 10
	*cp=0;
D 10
	if(cp[-1]=='.') cp[-1] = 0;
E 10
I 10
	if (cp[-1] == '.')
		cp[-1] = 0;
E 10
}

D 22
static char *oval = " ABCDEFGHIJKLMNOPQRSTUVWXYZ$.@0123456789";
E 22
static char *val = " abcdefghijklmnopqrstuvwxyz$.@0123456789";
I 10

E 10
static char table[256] = {
29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 
29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 
0, 29, 29, 29, 27, 29, 29, 29, 29, 29, 29, 29, 29, 29, 28, 29, 
30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 29, 29, 29, 29, 29, 29, 
29, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 29, 29, 29, 29, 29, 
29, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 29, 29, 29, 29, 29, 
29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 
29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 
0, 29, 29, 29, 27, 29, 29, 29, 29, 29, 29, 29, 29, 29, 28, 29, 
30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 29, 29, 29, 29, 29, 29, 
29, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 29, 29, 29, 29, 29, 
29, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 
16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 29, 29, 29, 29 };
		
D 10
long trans(logical)
register int logical;
E 10
I 10
/*
 * Logical to physical adress translation
 */
long
trans(logical)
	register int logical;
E 10
{
D 10
	/*  Logical to physical adress translation */
E 10
	register int sector, bytes, track;

D 10
	logical += 26 * 128;
	bytes = (logical & 127);
E 10
I 10
	logical += 26*128;
	bytes = (logical&127);
E 10
	logical >>= 7;
D 10
	sector = logical % 26;
E 10
I 10
	sector = logical%26;
E 10
	if(sector >= 13)
D 10
		sector = sector *2 +1;
E 10
I 10
		sector = sector*2+1;
E 10
	else
		sector *= 2;
D 10
	sector += 26 + ((track = (logical / 26)) - 1) * 6;
E 10
I 10
	sector += 26 + ((track = (logical/26))-1)*6;
E 10
	sector %= 26;
D 10
	return( (((track *26) + sector) << 7) + bytes);
E 10
I 10
D 14
	return((((track*26)+sector) << 7) + bytes);
E 14
I 14
	return ((((track*26)+sector) << 7) + bytes);
E 14
E 10
}
D 10
lread(startad,count,obuff)
register startad, count;
register char * obuff;
E 10
I 10

lread(startad, count, obuff)
	register startad, count;
	register char *obuff;
E 10
{
	long trans();
	extern floppydes;
I 10
	register int size = flag(m) ? 512 : 128;
I 23
	int error = 0;
	extern int errno;
E 23

E 10
I 8
D 9
	int temp;
E 9
E 8
	rt_init();
D 10
	if(flg['m'-'a']==0)
		while( (count -= 128) >= 0) {
			lseek(floppydes, trans(startad), 0);
D 4
			read(floppydes,obuff,128);
E 4
I 4
D 8
			 if (read(floppydes,obuff,128) != 128)
				fprintf(stderr, "arff: read error block %d\n",startad/128);
E 8
I 8
D 9
			 if ((temp = read(floppydes,obuff,128)) != 128)
				fprintf(stderr, "arff: read error block %d %d\n",startad/128, temp);
E 9
I 9
			 if (read(floppydes,obuff,128) != 128)
				fprintf(stderr, "arff: read error block %d\n",startad/128);
E 9
E 8
E 4
			obuff += 128;
			startad += 128;
		}
	else
		while( (count -= 512) >= 0) {
			lseek(floppydes,(long) (startad), 0);
D 4
			read(floppydes,obuff,512);
E 4
I 4
D 8
				fprintf(stderr, "arff: read error block %d\n",startad/512);
E 8
I 8
D 9
			if ((temp = read(floppydes, obuff, 512)) != 512)
				fprintf(stderr, "arff: read error block %d %d\n",startad/512, temp);
E 9
I 9
			if (read(floppydes, obuff, 512) != 512)
				fprintf(stderr, "arff: read error block %d\n",startad/512);
E 9
E 8
E 4
			obuff += 512;
			startad += 512;
		}
E 10
I 10
	while ((count -= size) >= 0) {
D 22
		lseek(floppydes, flag(m) ?
E 22
I 22
		(void) lseek(floppydes, flag(m) ?
E 22
			(long)startad : trans(startad), 0);
D 23
		if (read(floppydes, obuff, size) != size)
			fprintf(stderr, "arff: read error block %d\n",
E 23
I 23
		if (read(floppydes, obuff, size) != size) {
			error = errno;
			fprintf(stderr, "arff: read error block %d: ",
E 23
				startad/size);
I 23
			errno = error;
			perror("");
		}
E 23
		obuff += size;
		startad += size;
	}
I 23
	return (error);
E 23
E 10
}
D 10
lwrite(startad,count,obuff)
register startad, count;
register char * obuff;
E 10
I 10

lwrite(startad, count, obuff)
	register startad, count;
	register char *obuff;
E 10
{
	long trans();
	extern floppydes;
I 10
	register int size = flag(m) ? 512 : 128;

E 10
	rt_init();
D 10
	if(flg['m'-'a']==0)
		while( (count -= 128) >= 0) {
			lseek(floppydes, trans(startad), 0);
D 4
			write(floppydes,obuff,128);
E 4
I 4
			if ( write(floppydes,obuff,128) != 128)
				fprintf(stderr, "arff: write error block %d\n",startad/128);
E 4
			obuff += 128;
			startad += 128;
		}
	else
		while( (count -= 512) >= 0) {
			lseek(floppydes,(long) (startad), 0);
D 4
			write(floppydes,obuff,512);
E 4
I 4
			if ( write(floppydes,obuff,512) != 512)
				fprintf(stderr, "arff: write error block %d\n",startad/512);
E 4
			obuff += 512;
			startad += 512;
		}
E 10
I 10
	while ((count -= size) >= 0) {
D 22
		lseek(floppydes, flag(m) ?
E 22
I 22
		(void) lseek(floppydes, flag(m) ?
E 22
			(long)startad : trans(startad), 0);
		if (write(floppydes, obuff, size) != size)
			fprintf(stderr, "arff: write error block %d\n",
				startad/size);
		obuff += size;
		startad += size;
	}
E 10
}

rcmd()
{
	register int i;
I 3
D 4
	int debug;
E 4
E 3

	rt_init();
D 5
	if(namc>0)
E 5
I 5
D 10
	if (namc>0)
E 5
		for(i = 0; i < namc; i++)
D 3
			if(rtr(namv[i])==0) namv[i]=0;
E 3
I 3
D 4
			if((debug = rtr(namv[i]))==0) namv[i]=0;
			else printf("debug-rtr returns %d\n",debug);
E 4
I 4
			if(rtr(namv[i])==0) namv[i]=0;
E 10
I 10
	if (namc > 0)
		for (i = 0; i < namc; i++)
			if (rtr(namv[i]) == 0)
				namv[i] = 0;
E 10
E 4
E 3
D 5
	
	
E 5
}

rtr(name)
D 10
char *name;
E 10
I 10
	char *name;
E 10
{
D 10
	register FLDOPE *dope; register struct rt_ent *de;
	struct stat buf; register struct stat *bufp = &buf;
E 10
I 10
	register FLDOPE *dope;
	register struct rt_ent *de;
	struct stat buf;
	register struct stat *bufp = &buf;
E 10
I 3
	int segnum;
D 22
	register char *last;
E 22
I 22
	char type;
E 22
E 3

D 5
	if(stat(name,bufp)<0) return(1);
E 5
I 5
D 10
	if(stat(name,bufp)<0) {
E 10
I 10
	if (stat(name, bufp) < 0) {
E 10
		perror(name);
D 14
		return(-1);
E 14
I 14
		return (-1);
E 14
	}
I 22
	type = 'a';
E 22
E 5
D 10
	if(dope = lookup(name)) {
E 10
I 10
	if (dope = lookup(name)) {
E 10
		/* can replace, no problem */
		de = dope->rtdope;
D 10
		if(bufp->st_size <= (de->rt_len * 512))
E 10
I 10
D 22
		if (bufp->st_size <= (de->rt_len * 512))
E 10
			printf("r - %s\n",name),
E 22
I 22
		if (bufp->st_size <= (de->rt_len * 512)) {
			printf("r - %s\n",name);
E 22
D 10
			toflop(name,bufp->st_size,dope);
E 10
I 10
			toflop(name, bufp->st_size, dope);
E 10
D 22
		else {
D 4
			printf("%s will not fit in currently used file on floppy\n",name);
E 4
I 4
D 14
			fprintf(stderr, "%s will not fit in currently used file on floppy\n",name);
E 4
D 5
			return(1);
E 5
I 5
			return(-1);
E 14
I 14
			fprintf(stderr,
			  "%s will not fit in currently used file on floppy\n",
			  name);
			return (-1);
E 22
I 22
			goto found;
		} else {
			de = dope->rtdope;
			type = 'r';
			de->rt_stat = RT_NULL;
			de->rt_name[0] = 0;
			de->rt_name[1] = 0;
			de->rt_name[2] = 0;
			*((u_short *)&(de->rt_date)) = 0;
			scrunch();
E 22
E 14
E 5
		}
D 14
	} else {
D 3
		/* Search for vacant spot */
		for(de = rt_dir.rt_ents; (char *) de <= rt_last; de++) {
E 3
I 3
D 10
	    /* Search for vacant spot */
	    for (segnum=0; segnum != -1;    /* for all dir. segments */
		 segnum = rt_dir[segnum].rt_axhead.rt_nxtseg - 1) {
		last = rt_last + segnum*2*RT_BLOCK;
		for(de = rt_dir[segnum].rt_ents;
		    rt(de)->rt_stat != RT_ESEG; de++) {
E 3
			switch((de)->rt_stat) {
			case RT_NULL:
				if(bufp->st_size <= (de->rt_len * 512)) {
					printf("a - %s\n",name),
D 3
					mkent(de,bufp,name);
E 3
I 3
					mkent(de,segnum,bufp,name);
E 3
					goto found;
E 10
I 10
		/* Search for vacant spot */
		for (segnum = 0; segnum != -1;
		     segnum = rt_dir[segnum].rt_axhead.rt_nxtseg - 1)
		{
			last = rt_last + segnum*2*RT_BLOCK;
			for (de = rt_dir[segnum].rt_ents;
			    rt(de)->rt_stat != RT_ESEG; de++)
				if ((de)->rt_stat == RT_NULL) {
					if (bufp->st_size <= (de->rt_len*512)) {
						printf("a - %s\n",name),
						mkent(de, segnum, bufp,name);
						goto found;
					}
					continue;
E 14
I 14
D 22
		goto found;
E 22
	}
	/*
	 * Search for vacant spot
	 */
	for (segnum = 0; segnum != -1;
D 22
	     segnum = rt_dir[segnum].rt_axhead.rt_nxtseg - 1)
E 22
I 22
	     segnum = rt_dir[segnum].rd_nxtseg - 1)
E 22
	{
D 22
		last = rt_last + segnum*2*RT_BLOCK;
E 22
		for (de = rt_dir[segnum].rt_ents;
		    rt(de)->rt_stat != RT_ESEG; de++)
			if ((de)->rt_stat == RT_NULL) {
				if (bufp->st_size <= (de->rt_len*512)) {
D 22
					printf("a - %s\n",name),
E 22
I 22
					printf("%c - %s\n", type, name),
E 22
					mkent(de, segnum, bufp,name);
					goto found;
E 14
E 10
				}
D 10
				continue;
D 4
			case RT_ESEG:
D 3
				return(3);
E 3
I 3
				exit(1);  
E 4
E 3
			}
		}
E 10
D 3
		return(5);
E 3
I 3
D 14
	    }
D 5
	    return(3);
E 5
I 5
	    printf("%s: no slot for file\n", name);
	    return (-1);
E 14
I 14
				continue;
			}
E 14
E 5
E 3
	}
I 14
D 22
	printf("%s: no slot for file\n", name);
E 22
I 22
D 25
	if (type = 'r')
E 25
I 25
	if (type == 'r')
E 25
		printf("%s: no slot for file, file deleted\n",name);
	else
		printf("%s: no slot for file\n", name);
E 22
	return (-1);
E 14
D 10
found:	if(dope=lookup(name)) {
		toflop(name,bufp->st_size,dope);
E 10
I 10

found:
	if (dope = lookup(name)) {
		toflop(name, bufp->st_size, dope);
E 10
D 5
		return(0);
E 5
I 5
		return (0);
E 5
	}
D 5
	return(7);
E 5
I 5
	printf("%s: internal error, added then not found\n", name);
	return (-1);
E 5
D 10

E 10
}
D 3
mkent(de,bufp,name)
E 3
I 3
D 10
mkent(de,segnum,bufp,name)
E 3
register struct rt_ent *de;
I 3
int segnum;
E 3
register struct stat *bufp;
char *name;
E 10
I 10

mkent(de, segnum, bufp, name)
	register struct rt_ent *de;
	int segnum;
	register struct stat *bufp;
	char *name;
E 10
{
D 10
	struct tm *localtime(); register struct tm *timp;
	register struct rt_ent *workp; int count;
E 10
I 10
	struct tm *localtime();
	register struct tm *timp;
	register struct rt_ent *workp;
	int count;
E 10
	
	count = (((bufp->st_size -1) >>9) + 1);
D 10
						/* Make sure there is room */
	if(de->rt_len==count)
E 10
I 10
	/* make sure there is room */
	if (de->rt_len == count)
E 10
		goto overwrite;
D 3
	if(rt_nleft==0) {
E 3
I 3
D 10
	if(rt_curend[segnum] == (rt_last + (segnum*2*RT_BLOCK))) {
						/* no entries left on segment */
E 3
		if(flg['o'-'a'])
E 10
I 10
	if ((char *)rt_curend[segnum] == (rt_last + (segnum*2*RT_BLOCK))) {
D 22
		/* no entries left on segment */
		if (flag(o))
E 10
			goto overwrite;
D 3
		fprintf(stderr,"Directory full on  %s\n",defdev);
E 3
I 3
D 14
		fprintf(stderr,"Directory segment #%d full on  %s\n",segnum+1,
D 10
                    defdev);
E 10
I 10
			defdev);
E 14
I 14
		fprintf(stderr, "Directory segment #%d full on  %s\n",
			segnum+1, defdev);
E 14
E 10
E 3
		exit(1);
E 22
I 22
		/* no entries left on segment, trying adding new segment */
		if (rt_dir[0].rd_numseg > rt_dir[0].rd_lstseg) {
			short newseg;
			register int i;
			int maxseg;
			short size;

			newseg = rt_dir[0].rd_lstseg++;
			rt_dir[newseg] = rt_nulldir;
			rt_dir[newseg].rd_nxtseg = rt_dir[segnum].rd_nxtseg;
			rt_dir[segnum].rd_nxtseg = newseg + 1;
			rt_dir[newseg].rd_entpad = rt_dir[0].rd_entpad;
			rt_dir[newseg].rd_numseg = rt_dir[0].rd_numseg;
			size = 0;
			maxseg = 0;
			for(i = newseg - 1; i >= 0; i--) {
				workp = rt_curend[i] - 1;
				if (workp->rt_stat != RT_NULL)
					continue;
				if (workp->rt_len < size)
					continue;
				size = workp->rt_len;
				maxseg = i;
			}
			size = 0;
			for (workp = &rt_dir[maxseg].rt_ents[0]; 
			    workp->rt_stat != RT_ESEG; workp++) {
				size += workp->rt_len;
			}
			workp--;
			rt_dir[newseg].rt_ents[0].rt_len = workp->rt_len;
			rt_dir[newseg].rd_stfile = 
			    rt_dir[maxseg].rd_stfile + size - workp->rt_len;
			workp->rt_len = 0;
			rt_curend[newseg] = &rt_dir[newseg].rt_ents[1];
			lwrite(6*RT_BLOCK, 2*RT_BLOCK, (char *)&rt_dir[0]);
			if (segnum != 0)
				lwrite((6+segnum*2)*RT_BLOCK, 2*RT_BLOCK,
				    (char *)&rt_dir[segnum]);
			lwrite((6+newseg*2)*RT_BLOCK, 2*RT_BLOCK,
			    (char *)&rt_dir[newseg]);
			segnum = newseg;
			de = &rt_dir[newseg].rt_ents[0];
		} else {
			fprintf(stderr, "All directory segments full on  %s\n",
				defdev);
			exit(1);
		}
E 22
	}	
D 10
					/* copy directory entries up */
D 3
	for(workp = rt_curend+1; workp > de; workp--)
E 3
I 3
	for(workp = rt_curend[segnum]+1; workp > de; workp--)
E 10
I 10
	/* copy directory entries up */
	for (workp = rt_curend[segnum]+1; workp > de; workp--)
E 10
E 3
		*workp = workp[-1];
	de[1].rt_len -= count;
	de->rt_len = count;
D 3
	rt_curend++;
E 3
I 3
	rt_curend[segnum]++;
E 3
	rt_nleft--;
I 10

E 10
overwrite:
	srad50(name,de->rt_name);
	timp = localtime(&bufp->st_mtime);
D 12
	de->rt_date.rt_dy = timp->tm_mday + 1;
E 12
I 12
	de->rt_date.rt_dy = timp->tm_mday;
E 12
	de->rt_date.rt_mo = timp->tm_mon + 1;
D 29
	de->rt_date.rt_yr = timp->tm_year - 72;
E 29
I 29
	de->rt_date.rt_yr = (timp->tm_year - 72) & 0x1F;
	de->rt_date.rt_yx = (timp->tm_year - 72) >> 5;
E 29
	de->rt_stat = RT_FILE;
	de->rt_pad = 0;
	de->rt_chan = 0;
	de->rt_job = 0;
D 3
	lwrite(6*RT_BLOCK,2*RT_BLOCK,(char *)&rt_dir);
E 3
I 3
D 10
	lwrite((6+segnum*2)*RT_BLOCK,2*RT_BLOCK,(char *)&rt_dir[segnum]);
E 10
I 10
	lwrite((6+segnum*2)*RT_BLOCK, 2*RT_BLOCK, (char *)&rt_dir[segnum]);
E 10
E 3
D 4

E 4
}

D 10
toflop(name,ocount,dope)
char *name;
register FLDOPE *dope;
long ocount;
E 10
I 10
toflop(name, ocount, dope)
	char *name;
	register FLDOPE *dope;
	long ocount;
E 10
{
	register file, n, startad = dope->startad, count = ocount;
	char buff[512];
	
D 10
	file = open(name,0);
	if(file < 0) {
D 4
		printf("arff: couldn't open %s\n",name);exit(1);}
E 4
I 4
		fprintf(stderr, "arff: couldn't open %s\n",name);exit(1);}
E 10
I 10
	file = open(name, 0);
	if (file < 0) {
		fprintf(stderr, "arff: couldn't open %s\n",name);
		exit(1);
	}
E 10
E 4
	for( ; count >= 512; count -= 512) {
D 10
		read(file,buff,512);
		lwrite(startad,512,buff);
E 10
I 10
D 22
		read(file, buff, 512);
E 22
I 22
		(void) read(file, buff, 512);
E 22
		lwrite(startad, 512, buff);
E 10
		startad += 512;
	}
D 10
	read(file,buff,count);
E 10
I 10
D 22
	read(file, buff, count);
E 10
	close(file);
E 22
I 22
	(void) read(file, buff, count);
	(void) close(file);
E 22
D 10
	if(count <= 0) return;
	for(n = count; n < 512; n ++) buff[n] = 0;
	lwrite(startad,512,buff);
	count = (dope->rtdope->rt_len * 512 - ocount) / 512 ;
	if(count <= 0) return;
	for( ; count > 0 ; count--) {
E 10
I 10
	if (count <= 0)
		return;
	for (n = count; n < 512; n ++)
		buff[n] = 0;
	lwrite(startad, 512, buff);
	count = (dope->rtdope->rt_len*512-ocount)/512 ;
	if (count <= 0)
		return;
	for ( ; count > 0 ; count--) {
E 10
		startad += 512;
D 10
		lwrite(startad,512,zeroes);
E 10
I 10
		lwrite(startad, 512, zeroes);
E 10
	}
D 10

E 10
}
I 10

E 10
dcmd()
{
	register int i;

	rt_init();
D 10
	if(namc)
		for(i = 0; i < namc; i++)
			if(rtk(namv[i])==0) namv[i]=0;
	if(dirdirty)
E 10
I 10
	if (namc)
		for (i = 0; i < namc; i++)
			if (rtk(namv[i])==0)
				namv[i]=0;
	if (dirdirty)
E 10
		scrunch();
D 10
	
E 10
}
I 10

E 10
rtk(name)
D 10
char *name;
E 10
I 10
	char *name;
E 10
{
	register FLDOPE *dope;
	register struct rt_ent *de;
	FLDOPE *lookup();

D 10
	if(dope = lookup(name)) {
E 10
I 10
	if (dope = lookup(name)) {
E 10
		printf("d - %s\n",name);
		de = dope->rtdope;
		de->rt_stat = RT_NULL;
		de->rt_name[0] = 0;
		de->rt_name[1] = 0;
		de->rt_name[2] = 0;
D 10
		* ((unsigned short *) & (de->rt_date)) = 0;
E 10
I 10
D 14
		* ((u_short *)&(de->rt_date)) = 0;
E 14
I 14
		*((u_short *)&(de->rt_date)) = 0;
E 14
E 10
		dirdirty = 1;
D 14
		return(0);
E 14
I 14
		return (0);
E 14
	}
D 14
	return(1);
E 14
I 14
	return (1);
E 14
}
D 10
scrunch() {
E 10
I 10

scrunch()
{
E 10
D 3
	register struct rt_ent *de = rt_dir.rt_ents, *workp;
	for(de = rt_dir.rt_ents; de <= rt_curend; de++) {
E 3
I 3
	register struct rt_ent *de , *workp;
	register segnum;
D 10
	for (segnum=0; segnum != -1;    /* for all dir. segments */
E 10
I 10

	for (segnum = 0; segnum != -1;
E 10
D 22
	     segnum = rt_dir[segnum].rt_axhead.rt_nxtseg - 1) {
E 22
I 22
	     segnum = rt_dir[segnum].rd_nxtseg - 1) {
E 22
D 10
	    dirdirty = 0;
	    for(de = rt_dir[segnum].rt_ents; de <= rt_curend[segnum]; de++) {
E 3
		if(de->rt_stat==RT_NULL && de[1].rt_stat==RT_NULL) {
			(de+1)->rt_len += de->rt_len;
D 3
			for(workp = de; workp < rt_curend; workp++)
E 3
I 3
			for(workp = de; workp < rt_curend[segnum]; workp++)
E 3
				*workp = workp[1];
			de--;
D 3
			rt_curend--;
E 3
I 3
			rt_curend[segnum]--;
E 3
			rt_nleft++;
I 3
			dirdirty = 1;
E 3
		}
I 3
	    }
	    if (dirdirty)
	    lwrite((6+segnum*2)*RT_BLOCK,2*RT_BLOCK,(char *)&rt_dir[segnum]);
E 10
I 10
D 16
		dirdirty = 0;
E 16
		for (de = rt_dir[segnum].rt_ents; de <= rt_curend[segnum]; de++)
D 14
			if (de->rt_stat == RT_NULL && de[1].rt_stat == RT_NULL) {
E 14
I 14
			if (de->rt_stat == RT_NULL &&
D 16
			    de[1].rt_stat == RT_NULL) {
E 16
I 16
			    (de+1)->rt_stat == RT_NULL) {
E 16
E 14
				(de+1)->rt_len += de->rt_len;
D 16
				for (workp = de; workp < rt_curend[segnum]; workp++)
E 16
I 16
				for (workp=de; workp<rt_curend[segnum]; workp++)
E 16
					*workp = workp[1];
				de--;
				rt_curend[segnum]--;
				rt_nleft++;
D 16
				dirdirty = 1;
E 16
			}
D 16
		if (dirdirty)
			lwrite((6+segnum*2)*RT_BLOCK, 2*RT_BLOCK,
				(char *)&rt_dir[segnum]);
E 16
I 16
		lwrite((6+segnum*2)*RT_BLOCK, 2*RT_BLOCK,
			(char *)&rt_dir[segnum]);
E 16
E 10
E 3
	}
I 16
	dirdirty = 0;
E 16
D 3
	lwrite(6*RT_BLOCK,2*RT_BLOCK,(char *)&rt_dir);
E 3
}
E 1
