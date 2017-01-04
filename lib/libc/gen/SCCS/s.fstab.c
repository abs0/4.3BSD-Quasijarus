h38255
s 00002/00002/00150
d D 5.2 86/03/09 19:46:38 donn 6 5
c added LIBC_SCCS condition for sccs ids
e
s 00007/00001/00145
d D 5.1 85/05/30 10:41:35 dist 5 4
c Add copyright
e
s 00004/00002/00142
d D 4.4 83/06/19 14:28:11 root 4 3
c thanks to wnj
e
s 00026/00014/00118
d D 4.3 83/05/24 10:35:37 sam 3 2
c instead of quotafile, use rq and "quotas"; add search by type
e
s 00093/00076/00039
d D 4.2 83/05/19 22:27:14 sam 2 1
c rewrite to allow variable length strings; add quota file
e
s 00115/00000/00000
d D 4.1 80/12/21 16:50:26 wnj 1 0
c date and time created 80/12/21 16:50:26 by wnj
e
u
U
t
T
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
D 6
#ifndef lint
E 6
I 6
#if defined(LIBC_SCCS) && !defined(lint)
E 6
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif
E 5
I 5
D 6
#endif not lint
E 6
I 6
#endif LIBC_SCCS and not lint
E 6
E 5

E 2
#include <fstab.h>
#include <stdio.h>
#include <ctype.h>

D 2
static	struct	fstab fs;
static	FILE	*fs_file = 0;
E 2
I 2
static	struct fstab fs;
static	char line[BUFSIZ+1];
static	FILE *fs_file = 0;
E 2

D 2
static	char	*fs_string(back, string, lg, end)
	char	*string, *back;
	int	lg;	/* length of field to stuff into */
	char	end;
E 2
I 2
static char *
fsskip(p)
	register char *p;
E 2
{
D 2
	register	char	*cp;
	for (cp = string; *cp && *cp != end; cp++)
		continue;
	if (*cp == '\0') return(0);
	*cp = '\0';
	strncpy(back, string, lg-1);
	return(cp+1);
E 2
I 2

	while (*p && *p != ':')
		++p;
	if (*p)
		*p++ = 0;
	return (p);
E 2
}
D 2
static char *fs_digit(backp, string, end)
	int	*backp;
	char	*string;
	char	end;
E 2
I 2

static char *
fsdigit(backp, string, end)
	int *backp;
	char *string, end;
E 2
{
D 2
	register	int	value = 0;
	register	char	*cp;
	for (cp = string; *cp && isdigit(*cp); cp++){
E 2
I 2
	register int value = 0;
	register char *cp;

	for (cp = string; *cp && isdigit(*cp); cp++) {
E 2
		value *= 10;
		value += *cp - '0';
	}
D 2
	if (*cp == '\0') return(0);
E 2
I 2
	if (*cp == '\0')
D 3
		return (0);
E 3
I 3
		return ((char *)0);
E 3
E 2
	*backp = value;
D 2
	while ( *cp && *cp != end)
E 2
I 2
	while (*cp && *cp != end)
E 2
		cp++;
D 2
	if (*cp == '\0') return(0);
	return(cp+1);
E 2
I 2
	if (*cp == '\0')
D 3
		return (0);
E 3
I 3
		return ((char *)0);
E 3
	return (cp+1);
E 2
}

D 2
static	int	fstabscan(fsp)
	struct	fstab *fsp;
E 2
I 2
static
fstabscan(fs)
	struct fstab *fs;
E 2
{
D 2
	register	char	*cp;
	char	buf[256];
	if (fgets(buf, 256, fs_file) == NULL)
		return(EOF);
	cp = buf;
	cp = fs_string(&fsp->fs_spec[0], cp, FSNMLG, ':');
	if (cp == 0)	return(0);
	cp = fs_string(&fsp->fs_file[0], cp, FSNMLG, ':');
	if (cp == 0)	return(1);
	cp = fs_string(&fsp->fs_type[0], cp, 3, ':');
	if (cp == 0)	return(2);
	cp = fs_digit(&fsp->fs_freq, cp, ':');
	if (cp == 0)	return(3);
	cp = fs_digit(&fsp->fs_passno, cp, '\n');
	if (cp == 0)	return(4);
	return(5);
E 2
I 2
	register char *cp;

	cp = fgets(line, 256, fs_file);
	if (cp == NULL)
		return (EOF);
	fs->fs_spec = cp;
	cp = fsskip(cp);
	fs->fs_file = cp;
	cp = fsskip(cp);
	fs->fs_type = cp;
	cp = fsskip(cp);
D 3
	fs->fs_quotafile = cp;
	cp = fsskip(cp);
E 3
	cp = fsdigit(&fs->fs_freq, cp, ':');
	if (cp == 0)
D 3
		return (4);
E 3
I 3
		return (3);
E 3
	cp = fsdigit(&fs->fs_passno, cp, '\n');
	if (cp == 0)
D 3
		return (5);
	return (6);
E 3
I 3
		return (4);
	return (5);
E 3
E 2
}
	
D 2
int	setfsent()
E 2
I 2
setfsent()
E 2
{
I 2

E 2
	if (fs_file)
		endfsent();
D 2
	if ( (fs_file = fopen(FSTAB, "r")) == NULL){
E 2
I 2
D 4
	if ((fs_file = fopen(FSTAB, "r")) == NULL){
E 4
I 4
	if ((fs_file = fopen(FSTAB, "r")) == NULL) {
E 4
E 2
		fs_file = 0;
D 2
		return(0);
E 2
I 2
		return (0);
E 2
	}
D 2
	return(1);
E 2
I 2
	return (1);
E 2
}

D 2
int endfsent()
E 2
I 2
endfsent()
E 2
{
D 2
	if (fs_file){
E 2
I 2

D 4
	if (fs_file)
E 4
I 4
	if (fs_file) {
E 4
E 2
		fclose(fs_file);
I 4
		fs_file = 0;
	}
E 4
D 2
	}
	return(1);
E 2
I 2
	return (1);
E 2
}

D 2
struct fstab *getfsent()
E 2
I 2
struct fstab *
getfsent()
E 2
{
D 2
	int	nfields;
E 2
I 2
	int nfields;
E 2

D 2
	if ( (fs_file == 0) && (setfsent() == 0) )
		return(0);
E 2
I 2
	if ((fs_file == 0) && (setfsent() == 0))
D 3
		return (0);
E 3
I 3
		return ((struct fstab *)0);
E 3
E 2
	nfields = fstabscan(&fs);
D 2
	if (nfields == EOF || nfields != FSTABNARGS)
		return(0);
	return(&fs);
E 2
I 2
D 3
	if (nfields == EOF || nfields != 6)
		return (0);
E 3
I 3
	if (nfields == EOF || nfields != 5)
		return ((struct fstab *)0);
E 3
	return (&fs);
E 2
}
D 2
struct fstab *getfsspec(name)
	char	*name;
E 2
I 2

struct fstab *
getfsspec(name)
	char *name;
E 2
{
D 2
	register	struct	fstab *fsp;
E 2
I 2
	register struct fstab *fsp;

E 2
	if (setfsent() == 0)	/* start from the beginning */
D 2
		return(0);
	while( (fsp = getfsent()) != 0){
		if (strncmp(fsp->fs_spec, name, sizeof(fsp->fs_spec)) == 0)
			return(fsp);
	}
	return(0);
E 2
I 2
D 3
		return (0);
E 3
I 3
		return ((struct fstab *)0);
E 3
	while((fsp = getfsent()) != 0)
		if (strcmp(fsp->fs_spec, name) == 0)
			return (fsp);
D 3
	return (0);
E 3
I 3
	return ((struct fstab *)0);
E 3
E 2
}
D 2
struct fstab *getfsfile(name)
	char	*name;
E 2
I 2

struct fstab *
getfsfile(name)
	char *name;
E 2
{
D 2
	register	struct fstab *fsp;
E 2
I 2
	register struct fstab *fsp;

E 2
	if (setfsent() == 0)	/* start from the beginning */
D 2
		return(0);
	while ( (fsp = getfsent()) != 0){
		if (strncmp(fsp->fs_file, name, sizeof(fsp->fs_spec)) == 0)
			return(fsp);
	}
	return(0);
E 2
I 2
D 3
		return (0);
E 3
I 3
		return ((struct fstab *)0);
E 3
	while ((fsp = getfsent()) != 0)
		if (strcmp(fsp->fs_file, name) == 0)
			return (fsp);
D 3
	return (0);
E 3
I 3
	return ((struct fstab *)0);
}

struct fstab *
getfstype(type)
	char *type;
{
	register struct fstab *fs;

	if (setfsent() == 0)
		return ((struct fstab *)0);
	while ((fs = getfsent()) != 0)
		if (strcmp(fs->fs_type, type) == 0)
			return (fs);
	return ((struct fstab *)0);
E 3
E 2
}
E 1
