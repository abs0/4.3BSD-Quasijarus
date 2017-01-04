h21528
s 00040/00004/00210
d D 5.3 86/01/12 15:26:22 sam 6 5
c add tahoe
e
s 00015/00008/00199
d D 5.2 85/12/11 16:07:27 bloom 5 4
c fix problem with losing /vmunix in the middle, a bit of lint cleanup
e
s 00007/00001/00200
d D 5.1 85/05/30 16:20:33 mckusick 4 3
c Add copyright
e
s 00094/00028/00107
d D 1.3 85/05/01 01:33:18 sam 3 2
c major rework; fixup netstat stuff; pull disk cmds into common file; change 
c everthing related to disks to use dk_ndrive and global selction; use getw where possible
e
s 00003/00001/00132
d D 1.2 84/08/09 19:13:47 mckusick 2 1
c update to new sources from sam; weed out unnecessary #includes
e
s 00133/00000/00000
d D 1.1 84/08/09 17:59:24 mckusick 1 0
c date and time created 84/08/09 17:59:24 by mckusick
e
u
U
t
T
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 4
I 1
#ifndef lint
D 3
static char sccsid[] = "%W% (Lucasfilm) %G%";
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
D 4
#endif
E 4
I 4
#endif not lint
E 4

#include "systat.h"
D 2

E 2
I 2
D 3
#include <sys/param.h>
E 3
E 2
#include <sys/buf.h>
I 2
D 3
#include <sys/file.h>
E 3
I 3
#include <ctype.h>

static struct nlist nlst[] = {
#define	X_DK_NDRIVE	0
	{ "_dk_ndrive" },
#define	X_DK_MSPW	1
	{ "_dk_mspw" },
E 3
E 2
#ifdef vax
D 3
#include <vaxuba/ubavar.h>
#include <vaxmba/mbavar.h>
E 3
I 3
D 6
#define	X_MBDINIT	2
E 6
I 6
#define	X_MBDINIT	(X_DK_MSPW+1)
E 6
	{ "_mbdinit" },
D 6
#define	X_UBDINIT	3
E 6
I 6
#define	X_UBDINIT	(X_DK_MSPW+2)
E 6
	{ "_ubdinit" },
E 3
#endif
#ifdef sun
D 3
#include <sundev/mbvar.h>
E 3
I 3
D 6
#define	X_MBDINIT	2
E 6
I 6
#define	X_MBDINIT	(X_DK_MSPW+1)
E 6
	{ "_mbdinit" },
E 3
#endif
I 6
#ifdef tahoe
#define	X_VBDINIT	(X_DK_MSPW+1)
	{ "_vbdinit" },
#endif
E 6
I 2
D 3
#include <ctype.h>
E 3
I 3
	{ "" },
};
E 3
E 2

D 3
char dr_name[DK_NDRIVE][10];
E 3
I 3
dkinit()
{
	register int i;
	register char *cp;
	static int once = 0;
	static char buf[1024];
E 3

I 3
	if (once)
D 5
		return;
	once = 1;
E 5
I 5
		return(1);
E 5
	nlist("/vmunix", nlst);
	if (nlst[X_DK_NDRIVE].n_value == 0) {
		error("dk_ndrive undefined in kernel");
D 5
		return;
E 5
I 5
		return(0);
E 5
	}
	dk_ndrive = getw(nlst[X_DK_NDRIVE].n_value);
	if (dk_ndrive <= 0) {
		error("dk_ndrive=%d according to /vmunix", dk_ndrive);
D 5
		return;
E 5
I 5
		return(0);
E 5
	}
	dk_mspw = (float *)calloc(dk_ndrive, sizeof (float));
	lseek(kmem, nlst[X_DK_MSPW].n_value, L_SET);
	read(kmem, dk_mspw, dk_ndrive * sizeof (float));
	dr_name = (char **)calloc(dk_ndrive, sizeof (char *));
	dk_select = (int *)calloc(dk_ndrive, sizeof (int));
	for (cp = buf, i = 0; i < dk_ndrive; i++) {
		dr_name[i] = cp;
		sprintf(dr_name[i], "dk%d", i);
		cp += strlen(dr_name[i]) + 1;
		if (dk_mspw[i] != 0.0)
			dk_select[i] = 1;
	}
D 5
	read_names();
E 5
I 5
D 6
	if (! read_names()) {
E 6
I 6
	if (!read_names()) {
E 6
		free(dr_name);
		free(dk_select);
		free(dk_mspw);
		return(0);
	}
	once = 1;
	return(1);
E 5
}

dkcmd(cmd, args)
	char *cmd, *args;
{

        if (prefix(cmd, "display") || prefix(cmd, "add")) {
                dkselect(args, 1, dk_select);
		return (1);
        }
        if (prefix(cmd, "ignore") || prefix(cmd, "delete")) {
                dkselect(args, 0, dk_select);
		return (1);
        }
        if (prefix(cmd, "drives")) {
		register int i;

                move(CMDLINE, 0); clrtoeol();
                for (i = 0; i < dk_ndrive; i++)
                        if (dk_mspw[i] != 0.0)
                                printw("%s ", dr_name[i]);
                return (1);
        }
	return (0);
}

E 3
#define steal(where, var) \
	lseek(kmem, where, L_SET); read(kmem, &var, sizeof var);

#ifdef vax
D 3
read_names(mp, up)
	register struct mba_device *mp;
	register struct uba_device *up;
E 3
I 3
#include <vaxuba/ubavar.h>
#include <vaxmba/mbavar.h>

read_names()
E 3
{
D 5
	static int once = 0;
E 5
	struct mba_device mdev;
	struct mba_driver mdrv;
	short two_char;
	char *cp = (char *)&two_char;
	struct uba_device udev;
	struct uba_driver udrv;
I 3
	register struct mba_device *mp;
	register struct uba_device *up;
E 3

D 3
	if (once)
		return;
	once++;
	if (up == 0) {
E 3
I 3
	mp = (struct mba_device *)nlst[X_MBDINIT].n_value;
	up = (struct uba_device *)nlst[X_UBDINIT].n_value;
	if (mp == 0 && up == 0) {
E 3
		error("Disk init info not in namelist\n");
D 5
		return;
E 5
I 5
		return(0);
E 5
	}
	if (mp) for (;;) {
		steal(mp++, mdev);
		if (mdev.mi_driver == 0)
			break;
		if (mdev.mi_dk < 0 || mdev.mi_alive == 0)
			continue;
		steal(mdev.mi_driver, mdrv);
		steal(mdrv.md_dname, two_char);
		sprintf(dr_name[mdev.mi_dk], "%c%c%d",
		    cp[0], cp[1], mdev.mi_unit);
	}
	if (up) for (;;) {
		steal(up++, udev);
		if (udev.ui_driver == 0)
			break;
		if (udev.ui_dk < 0 || udev.ui_alive == 0)
			continue;
		steal(udev.ui_driver, udrv);
		steal(udrv.ud_dname, two_char);
		sprintf(dr_name[udev.ui_dk], "%c%c%d",
		    cp[0], cp[1], udev.ui_unit);
	}
I 5
	return(1);
E 5
}
#endif

#ifdef sun
D 3
/*VARARGS*/
read_names(mp)
	register struct mb_device *mp;
E 3
I 3
#include <sundev/mbvar.h>

read_names()
E 3
{
	static int once = 0;
	struct mb_device mdev;
	struct mb_driver mdrv;
	short two_char;
	char *cp = (char *) &two_char;
I 3
	register struct mb_device *mp;
E 3

D 3
	if (once)
		return;
	once++;
E 3
I 3
	mp = (struct mb_device *)nlst[X_MBDINIT].n_value;
E 3
	if (mp == 0) {
		error("Disk init info not in namelist\n");
D 5
		return;
E 5
I 5
		return(0);
E 5
	}
	for (;;) {
		steal(mp++, mdev);
		if (mdev.md_driver == 0)
			break;
		if (mdev.md_dk < 0 || mdev.md_alive == 0)
			continue;
		steal(mdev.md_driver, mdrv);
		steal(mdrv.mdr_dname, two_char);
		sprintf(dr_name[mdev.md_dk], "%c%c%d",
		    cp[0], cp[1], mdev.md_unit);
	}
I 5
	return(1);
I 6
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

	up = (struct vba_device *) nlst[X_VBDINIT].n_value;
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
	}
E 6
E 5
}
#endif

dkselect(args, truefalse, selections)
	char *args;
	int truefalse, selections[];
{
	register char *cp;
	register int i;
	char *index();

	cp = index(args, '\n');
	if (cp)
		*cp = '\0';
	for (;;) {
		for (cp = args; *cp && isspace(*cp); cp++)
			;
		args = cp;
		for (; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		if (cp - args == 0)
			break;
D 3
		for (i = 0; i < DK_NDRIVE; i++)
E 3
I 3
		for (i = 0; i < dk_ndrive; i++)
E 3
			if (strcmp(args, dr_name[i]) == 0) {
D 3
				selections[i] = truefalse;
E 3
				if (dk_mspw[i] != 0.0)
D 3
					if (truefalse == 0)
						ndrives--;
					else
						ndrives++;
E 3
I 3
					selections[i] = truefalse;
				else
					error("%s: drive not configured",
					    dr_name[i]);
E 3
				break;
			}
D 3
		if (i >= DK_NDRIVE)
E 3
I 3
		if (i >= dk_ndrive)
E 3
			error("%s: unknown drive", args);
		args = cp;
	}
}
E 1
