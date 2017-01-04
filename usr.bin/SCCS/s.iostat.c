h26981
s 00001/00001/00359
d D 4.15 87/01/12 15:32:36 mckusick 15 14
c wrong subscript (from srk@sun.com (Steve Kleiman))
e
s 00039/00003/00321
d D 4.14 86/10/19 23:07:49 sam 14 13
c add tahoe support
e
s 00150/00080/00174
d D 4.13 85/04/25 21:27:13 sam 13 12
c handle lotsa drives as done for vmstat; also print header after continue
e
s 00000/00034/00254
d D 4.12 84/11/26 10:54:55 ralph 12 11
c take out sun code
e
s 00002/00001/00286
d D 4.11 84/11/24 01:01:51 lepreau 11 10
c fix negative times due to overflow; add fflush so works over net
e
s 00010/00004/00277
d D 4.10 83/10/19 20:16:37 sam 10 9
c disk stats are collected off alternate clock, if it exists
e
s 00010/00007/00271
d D 4.9 83/09/25 12:49:39 sam 9 8
c 60 no, hz yes
e
s 00004/00004/00274
d D 4.8 83/05/30 21:14:35 mckusick 8 7
c list "bps" (Kbytes per second) instead of "sps" (seeks per second)
e
s 00047/00011/00231
d D 4.7 83/02/23 19:28:21 shannon 7 6
c fixes for sun
e
s 00002/00001/00240
d D 4.6 81/04/21 01:49:39 root 6 5
c allow for no mba's
e
s 00001/00001/00240
d D 4.5 81/04/01 12:52:28 wnj 5 4
c restore sccsline
e
s 00001/00001/00240
d D 4.4 81/04/01 12:31:49 root 4 3
c aaa
e
s 00065/00003/00176
d D 4.3 81/03/09 20:22:32 toy 3 2
c Made it look up disk device names
e
s 00014/00011/00165
d D 4.2 80/10/19 13:38:33 bill 2 1
c reprint headers
e
s 00176/00000/00000
d D 4.1 80/10/19 13:32:17 bill 1 0
c date and time created 80/10/19 13:32:17 by bill
e
u
U
t
T
I 13
#ifndef lint
E 13
I 1
D 4
static	char *sccsid = "%W% (Berkeley) %G%";
E 4
I 4
D 5
static	char *sccsid = "@(#)iostat.c	4.3 (Berkeley) 3/9/81";
E 5
I 5
static	char *sccsid = "%W% (Berkeley) %E%";
I 13
#endif

E 13
E 5
E 4
/*
 * iostat
 */
I 3
#include <stdio.h>
I 13
#include <ctype.h>
E 13
E 3
#include <nlist.h>
I 13
#include <signal.h>

E 13
I 3
#include <sys/types.h>
I 13
#include <sys/file.h>
E 13
#include <sys/buf.h>
I 7
D 14
#include <sys/dk.h>
E 14
I 14
#include <sys/dkstat.h>
E 14
D 13
#ifdef vax
E 7
D 8
#include <sys/ubavar.h>
#include <sys/mbavar.h>
E 8
I 8
#include <vaxuba/ubavar.h>
#include <vaxmba/mbavar.h>
E 8
E 3
D 7
#include <sys/dk.h>
E 7
I 7
#endif
E 13
D 12
#ifdef sun
#include <sundev/mbvar.h>
#endif
E 12
E 7

struct nlist nl[] = {
	{ "_dk_busy" },
#define	X_DK_BUSY	0
	{ "_dk_time" },
#define	X_DK_TIME	1
	{ "_dk_xfer" },
#define	X_DK_XFER	2
	{ "_dk_wds" },
#define	X_DK_WDS	3
	{ "_tk_nin" },
#define	X_TK_NIN	4
	{ "_tk_nout" },
#define	X_TK_NOUT	5
	{ "_dk_seek" },
#define	X_DK_SEEK	6
	{ "_cp_time" },
#define	X_CP_TIME	7
	{ "_dk_mspw" },
#define	X_DK_MSPW	8
I 9
	{ "_hz" },
#define	X_HZ		9
E 9
I 7
D 10

E 10
I 10
	{ "_phz" },
#define	X_PHZ		10
I 13
	{ "_dk_ndrive" },
#define	X_DK_NDRIVE	11
E 13
E 10
#ifdef vax
E 7
I 3
	{ "_mbdinit" },
D 9
#define X_MBDINIT	9
E 9
I 9
D 10
#define X_MBDINIT	10
E 10
I 10
D 13
#define X_MBDINIT	11
E 13
I 13
D 14
#define X_MBDINIT	12
E 14
I 14
#define X_MBDINIT	(X_DK_NDRIVE+1)
E 14
E 13
E 10
E 9
	{ "_ubdinit" },
D 9
#define X_UBDINIT	10
E 9
I 9
D 10
#define X_UBDINIT	11
E 10
I 10
D 13
#define X_UBDINIT	12
E 13
I 13
D 14
#define X_UBDINIT	13
E 14
I 14
#define X_UBDINIT	(X_DK_NDRIVE+2)
E 14
E 13
E 10
E 9
I 7
#endif
I 14
#ifdef tahoe
#define	X_VBDINIT	(X_DK_NDRIVE+1)
	{ "_vbdinit" },
#endif
E 14
D 9

E 9
D 12
#ifdef sun
	{ "_mbdinit" },
D 9
#define X_MBDINIT	9
E 9
I 9
D 10
#define X_MBDINIT	10
E 10
I 10
#define X_MBDINIT	11
E 10
E 9
#endif
E 12
D 9

E 9
E 7
E 3
	{ 0 },
};
I 3

D 13
char dr_name[DK_NDRIVE][10];
E 13
I 13
char	**dr_name;
int	*dr_select;
float	*dk_mspw;
int	dk_ndrive;
int	ndrives = 0;
#ifdef vax
char	*defdrives[] = { "hp0", "hp1", "hp2",  0 };
#else
char	*defdrives[] = { 0 };
#endif
E 13

E 3
D 13
struct
{
E 13
I 13
struct {
E 13
	int	dk_busy;
	long	cp_time[CPUSTATES];
D 13
	long	dk_time[DK_NDRIVE];
	long	dk_wds[DK_NDRIVE];
	long	dk_seek[DK_NDRIVE];
	long	dk_xfer[DK_NDRIVE];
	float	dk_mspw[DK_NDRIVE];
E 13
I 13
	long	*dk_time;
	long	*dk_wds;
	long	*dk_seek;
	long	*dk_xfer;
E 13
	long	tk_nin;
	long	tk_nout;
} s, s1;

int	mf;
I 9
int	hz;
I 10
int	phz;
E 10
E 9
double	etime;
I 13
int	tohdr = 1;
int	printhdr();
E 13

main(argc, argv)
D 13
char *argv[];
E 13
I 13
	char *argv[];
E 13
{
	extern char *ctime();
	register  i;
D 13
	int iter;
E 13
I 13
	int iter, ndrives;
E 13
	double f1, f2;
	long t;
I 2
D 13
	int tohdr = 1;
E 13
I 13
	char *arg, **cp, name[6], buf[BUFSIZ];
E 13
E 2

	nlist("/vmunix", nl);
	if(nl[X_DK_BUSY].n_type == 0) {
		printf("dk_busy not found in /vmunix namelist\n");
		exit(1);
	}
	mf = open("/dev/kmem", 0);
	if(mf < 0) {
		printf("cannot open /dev/kmem\n");
		exit(1);
	}
	iter = 0;
D 13
	while (argc>1&&argv[1][0]=='-') {
		argc--;
		argv++;
E 13
I 13
	for (argc--, argv++; argc > 0 && argv[0][0] == '-'; argc--, argv++)
		;
D 15
	if (nl[DK_NDRIVE].n_value == 0) {
E 15
I 15
	if (nl[X_DK_NDRIVE].n_value == 0) {
E 15
		printf("dk_ndrive undefined in system\n");
		exit(1);
E 13
	}
D 13
	lseek(mf, (long)nl[X_DK_MSPW].n_value, 0);
	read(mf, s.dk_mspw, sizeof s.dk_mspw);
I 3
	for (i = 0; i < DK_NDRIVE; i++)
E 13
I 13
	lseek(mf, nl[X_DK_NDRIVE].n_value, L_SET);
	read(mf, &dk_ndrive, sizeof (dk_ndrive));
	if (dk_ndrive <= 0) {
		printf("dk_ndrive %d\n", dk_ndrive);
		exit(1);
	}
	dr_select = (int *)calloc(dk_ndrive, sizeof (int));
	dr_name = (char **)calloc(dk_ndrive, sizeof (char *));
	dk_mspw = (float *)calloc(dk_ndrive, sizeof (float));
#define	allocate(e, t) \
    s./**/e = (t *)calloc(dk_ndrive, sizeof (t)); \
    s1./**/e = (t *)calloc(dk_ndrive, sizeof (t));
	allocate(dk_time, long);
	allocate(dk_wds, long);
	allocate(dk_seek, long);
	allocate(dk_xfer, long);
	for (arg = buf, i = 0; i < dk_ndrive; i++) {
		dr_name[i] = arg;
E 13
		sprintf(dr_name[i], "dk%d", i);
I 13
		arg += strlen(dr_name[i]) + 1;
	}
E 13
	read_names();
E 3
D 13
	if(argc > 2)
		iter = atoi(argv[2]);
D 2
	printf("      TTY");
	for (i = 0; i < DK_NDRIVE; i++)
		if (s.dk_mspw[i] != 0.0)
			printf("           D%d ", i);
	printf("         CPU\n");
	printf(" tin tout");
	for (i = 0; i < DK_NDRIVE; i++)
		if (s.dk_mspw[i] != 0.0)
			printf(" sps tps msps ");
	printf(" us ni sy id\n");

E 2
loop:
I 2
	if (--tohdr == 0) {
D 3
		printf("      TTY");
E 3
I 3
		printf("      tty");
E 3
		for (i = 0; i < DK_NDRIVE; i++)
			if (s.dk_mspw[i] != 0.0)
D 3
				printf("           D%d ", i);
		printf("         CPU\n");
E 3
I 3
				printf("          %3.3s ", dr_name[i]);
		printf("         cpu\n");
E 3
		printf(" tin tout");
		for (i = 0; i < DK_NDRIVE; i++)
			if (s.dk_mspw[i] != 0.0)
D 8
				printf(" sps tps msps ");
E 8
I 8
				printf(" bps tps msps ");
E 8
		printf(" us ni sy id\n");
		tohdr = 19;
E 13
I 13
	lseek(mf, (long)nl[X_HZ].n_value, L_SET);
	read(mf, &hz, sizeof hz);
	lseek(mf, (long)nl[X_PHZ].n_value, L_SET);
	read(mf, &phz, sizeof phz);
	if (phz)
		hz = phz;
	lseek(mf, (long)nl[X_DK_MSPW].n_value, L_SET);
	read(mf, dk_mspw, dk_ndrive*sizeof (dk_mspw));
	/*
	 * Choose drives to be displayed.  Priority
	 * goes to (in order) drives supplied as arguments,
	 * default drives.  If everything isn't filled
	 * in and there are drives not taken care of,
	 * display the first few that fit.
	 */
	ndrives = 0;
	while (argc > 0 && !isdigit(argv[0][0])) {
		for (i = 0; i < dk_ndrive; i++) {
			if (strcmp(dr_name[i], argv[0]))
				continue;
			dr_select[i] = 1;
			ndrives++;
		}
		argc--, argv++;
E 13
	}
E 2
D 13
	lseek(mf, (long)nl[X_DK_BUSY].n_value, 0);
E 13
I 13
	for (i = 0; i < dk_ndrive && ndrives < 4; i++) {
		if (dr_select[i] || dk_mspw[i] == 0.0)
			continue;
		for (cp = defdrives; *cp; cp++)
			if (strcmp(dr_name[i], *cp) == 0) {
				dr_select[i] = 1;
				ndrives++;
				break;
			}
	}
	for (i = 0; i < dk_ndrive && ndrives < 4; i++) {
		if (dr_select[i])
			continue;
		dr_select[i] = 1;
		ndrives++;
	}
	if (argc > 1)
		iter = atoi(argv[1]);
	signal(SIGCONT, printhdr);
loop:
	if (--tohdr == 0)
		printhdr();
	lseek(mf, (long)nl[X_DK_BUSY].n_value, L_SET);
E 13
 	read(mf, &s.dk_busy, sizeof s.dk_busy);
D 13
 	lseek(mf, (long)nl[X_DK_TIME].n_value, 0);
 	read(mf, s.dk_time, sizeof s.dk_time);
 	lseek(mf, (long)nl[X_DK_XFER].n_value, 0);
 	read(mf, s.dk_xfer, sizeof s.dk_xfer);
 	lseek(mf, (long)nl[X_DK_WDS].n_value, 0);
 	read(mf, s.dk_wds, sizeof s.dk_wds);
 	lseek(mf, (long)nl[X_TK_NIN].n_value, 0);
E 13
I 13
 	lseek(mf, (long)nl[X_DK_TIME].n_value, L_SET);
 	read(mf, s.dk_time, dk_ndrive*sizeof (long));
 	lseek(mf, (long)nl[X_DK_XFER].n_value, L_SET);
 	read(mf, s.dk_xfer, dk_ndrive*sizeof (long));
 	lseek(mf, (long)nl[X_DK_WDS].n_value, L_SET);
 	read(mf, s.dk_wds, dk_ndrive*sizeof (long));
	lseek(mf, (long)nl[X_DK_SEEK].n_value, L_SET);
	read(mf, s.dk_seek, dk_ndrive*sizeof (long));
 	lseek(mf, (long)nl[X_TK_NIN].n_value, L_SET);
E 13
 	read(mf, &s.tk_nin, sizeof s.tk_nin);
D 13
 	lseek(mf, (long)nl[X_TK_NOUT].n_value, 0);
E 13
I 13
 	lseek(mf, (long)nl[X_TK_NOUT].n_value, L_SET);
E 13
 	read(mf, &s.tk_nout, sizeof s.tk_nout);
D 13
	lseek(mf, (long)nl[X_DK_SEEK].n_value, 0);
	read(mf, s.dk_seek, sizeof s.dk_seek);
	lseek(mf, (long)nl[X_CP_TIME].n_value, 0);
E 13
I 13
	lseek(mf, (long)nl[X_CP_TIME].n_value, L_SET);
E 13
	read(mf, s.cp_time, sizeof s.cp_time);
D 13
	lseek(mf, (long)nl[X_DK_MSPW].n_value, 0);
	read(mf, s.dk_mspw, sizeof s.dk_mspw);
I 9
	lseek(mf, (long)nl[X_HZ].n_value, 0);
	read(mf, &hz, sizeof hz);
I 10
	lseek(mf, (long)nl[X_PHZ].n_value, 0);
	read(mf, &phz, sizeof phz);
	if (phz)
		hz = phz;
E 10
E 9
	for (i = 0; i < DK_NDRIVE; i++) {
E 13
I 13
	for (i = 0; i < dk_ndrive; i++) {
		if (!dr_select[i])
			continue;
E 13
#define X(fld)	t = s.fld[i]; s.fld[i] -= s1.fld[i]; s1.fld[i] = t
		X(dk_xfer); X(dk_seek); X(dk_wds); X(dk_time);
	}
	t = s.tk_nin; s.tk_nin -= s1.tk_nin; s1.tk_nin = t;
	t = s.tk_nout; s.tk_nout -= s1.tk_nout; s1.tk_nout = t;
	etime = 0;
	for(i=0; i<CPUSTATES; i++) {
		X(cp_time);
		etime += s.cp_time[i];
	}
	if (etime == 0.0)
		etime = 1.0;
D 9
	etime /= 60.0;
E 9
I 9
	etime /= (float) hz;
E 9
	printf("%4.0f%5.0f", s.tk_nin/etime, s.tk_nout/etime);
D 13
	for (i=0; i<DK_NDRIVE; i++)
		if (s.dk_mspw[i] != 0.0)
E 13
I 13
	for (i=0; i<dk_ndrive; i++)
		if (dr_select[i])
E 13
			stats(i);
	for (i=0; i<CPUSTATES; i++)
		stat1(i);
	printf("\n");
I 11
	fflush(stdout);
E 11
contin:
D 13
	--iter;
	if(iter)
	if(argc > 1) {
		sleep(atoi(argv[1]));
E 13
I 13
	if (--iter && argc > 0) {
		sleep(atoi(argv[0]));
E 13
		goto loop;
	}
}

I 13
printhdr()
{
	register int i;

	printf("      tty");
	for (i = 0; i < dk_ndrive; i++)
		if (dr_select[i])
			printf("          %3.3s ", dr_name[i]);
	printf("         cpu\n");
	printf(" tin tout");
	for (i = 0; i < dk_ndrive; i++)
		if (dr_select[i])
			printf(" bps tps msps ");
	printf(" us ni sy id\n");
	tohdr = 19;
}

E 13
stats(dn)
{
	register i;
	double atime, words, xtime, itime;

D 13
	if (s.dk_mspw[dn] == 0.0) {
E 13
I 13
	if (dk_mspw[dn] == 0.0) {
E 13
		printf("%4.0f%4.0f%5.1f ", 0.0, 0.0, 0.0);
		return;
	}
	atime = s.dk_time[dn];
D 9
	atime /= 60.0;
E 9
I 9
	atime /= (float) hz;
E 9
	words = s.dk_wds[dn]*32.0;	/* number of words transferred */
D 13
	xtime = s.dk_mspw[dn]*words;	/* transfer time */
E 13
I 13
	xtime = dk_mspw[dn]*words;	/* transfer time */
E 13
	itime = atime - xtime;		/* time not transferring */
D 13
/*
	printf("\ndn %d, words %8.2f, atime %6.2f, xtime %6.2f, itime %6.2f\n",
	    dn, words, atime, xtime, itime);
*/
E 13
	if (xtime < 0)
		itime += xtime, xtime = 0;
	if (itime < 0)
		xtime += itime, itime = 0;
D 8
	printf("%4.0f", s.dk_seek[dn]/etime);
E 8
I 8
	printf("%4.0f", words/512/etime);
E 8
	printf("%4.0f", s.dk_xfer[dn]/etime);
	printf("%5.1f ",
	    s.dk_seek[dn] ? itime*1000./s.dk_seek[dn] : 0.0);
D 13
/*
	printf("%4.1f",
	    s.dk_xfer[dn] ? xtime*1000./s.dk_xfer[dn] : 0.0);
*/
E 13
}

stat1(o)
{
	register i;
	double time;

	time = 0;
	for(i=0; i<CPUSTATES; i++)
		time += s.cp_time[i];
	if (time == 0.0)
		time = 1.0;
D 11
	printf("%3.0f", 100*s.cp_time[o]/time);
E 11
I 11
	printf("%3.0f", 100.*s.cp_time[o]/time);
E 11
I 3
}

D 7
/*
 * Read the drive names out of kmem.
 * ARGH ARGH ARGH ARGH !!!!!!!!!!!!
 */

E 7
D 13
#define steal(where, var) lseek(mf, where, 0); read(mf, &var, sizeof var);
E 13
I 13
#define steal(where, var) \
    lseek(mf, where, L_SET); read(mf, &var, sizeof var);
E 13
I 7

#ifdef vax
I 13
#include <vaxuba/ubavar.h>
#include <vaxmba/mbavar.h>

E 13
E 7
read_names()
{
	struct mba_device mdev;
	register struct mba_device *mp;
	struct mba_driver mdrv;
	short two_char;
	char *cp = (char *) &two_char;
	struct uba_device udev, *up;
	struct uba_driver udrv;

	mp = (struct mba_device *) nl[X_MBDINIT].n_value;
	up = (struct uba_device *) nl[X_UBDINIT].n_value;
D 6
	if (mp == 0 || up == 0)
E 6
I 6
D 13
	if (up == 0)
E 6
	{
E 13
I 13
	if (up == 0) {
E 13
		fprintf(stderr, "iostat: Disk init info not in namelist\n");
		exit(1);
	}
I 6
D 7
	if (mp)
E 6
	while(1)
	{
E 7
I 7
	if (mp) for (;;) {
E 7
		steal(mp++, mdev);
		if (mdev.mi_driver == 0)
			break;
		if (mdev.mi_dk < 0 || mdev.mi_alive == 0)
			continue;
		steal(mdev.mi_driver, mdrv);
		steal(mdrv.md_dname, two_char);
D 13
		sprintf(dr_name[mdev.mi_dk], "%c%c%d", cp[0], cp[1], mdev.mi_unit);
E 13
I 13
		sprintf(dr_name[mdev.mi_dk], "%c%c%d",
		    cp[0], cp[1], mdev.mi_unit);
E 13
	}
D 7
	while(1)
	{
E 7
I 7
	if (up) for (;;) {
E 7
		steal(up++, udev);
		if (udev.ui_driver == 0)
			break;
		if (udev.ui_dk < 0 || udev.ui_alive == 0)
			continue;
		steal(udev.ui_driver, udrv);
		steal(udrv.ud_dname, two_char);
D 13
		sprintf(dr_name[udev.ui_dk], "%c%c%d", cp[0], cp[1], udev.ui_unit);
E 13
I 13
		sprintf(dr_name[udev.ui_dk], "%c%c%d",
		    cp[0], cp[1], udev.ui_unit);
I 14
	}
}
#endif

#ifdef tahoe
#include <tahoevba/vbavar.h>

/*
 * Read the drive names out of kmem.
 */
read_names()
{
	struct vba_device udev, *up;
	struct vba_driver udrv;
	short two_char;
	char *cp = (char *)&two_char;

	up = (struct vba_device *) nl[X_VBDINIT].n_value;
	if (up == 0) {
		fprintf(stderr, "vmstat: Disk init info not in namelist\n");
		exit(1);
	}
	for (;;) {
		steal(up++, udev);
		if (udev.ui_driver == 0)
			break;
		if (udev.ui_dk < 0 || udev.ui_alive == 0)
			continue;
		steal(udev.ui_driver, udrv);
		steal(udrv.ud_dname, two_char);
		sprintf(dr_name[udev.ui_dk], "%c%c%d",
		     cp[0], cp[1], udev.ui_unit);
E 14
E 13
D 12
	}
E 3
}
I 7
#endif

#ifdef sun
read_names()
{
	struct mb_device mdev;
	register struct mb_device *mp;
	struct mb_driver mdrv;
	short two_char;
	char *cp = (char *) &two_char;

	mp = (struct mb_device *) nl[X_MBDINIT].n_value;
	if (mp == 0) {
		fprintf(stderr, "iostat: Disk init info not in namelist\n");
		exit(1);
	}
	for (;;) {
		steal(mp++, mdev);
		if (mdev.md_driver == 0)
			break;
		if (mdev.md_dk < 0 || mdev.md_alive == 0)
			continue;
		steal(mdev.md_driver, mdrv);
		steal(mdrv.mdr_dname, two_char);
		sprintf(dr_name[mdev.md_dk], "%c%c%d", cp[0], cp[1], mdev.md_unit);
E 12
	}
}
#endif
E 7
E 1
