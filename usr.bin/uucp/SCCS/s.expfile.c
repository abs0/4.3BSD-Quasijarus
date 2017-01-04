h23034
s 00003/00001/00124
d D 5.5 85/06/19 18:42:03 bloom 5 4
c fix from rick adams
e
s 00016/00021/00109
d D 5.4 85/04/10 15:19:44 ralph 4 3
c more changes from rick adams.
e
s 00019/00020/00111
d D 5.3 85/01/22 14:08:16 ralph 3 2
c bug fixes and changes from Rick Adams
e
s 00003/00005/00128
d D 5.2 84/08/30 16:23:49 ralph 2 1
c added network device NET
e
s 00133/00000/00000
d D 5.1 83/07/02 17:56:45 sam 1 0
c date and time created 83/07/02 17:56:45 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "uucp.h"
D 4
#include <sys/types.h>
E 4
#include <sys/stat.h>

I 5
/*LINTLIBRARY*/

E 5
D 4
/*******
 *	expfile(file)	expand file name
 *	char *file;
E 4
I 4
/*
 *	expand file name
E 4
 *
 *	return codes: 0 - Ordinary spool area file
 *		      1 - Other normal file
 *		      FAIL - no Wrkdir name available
 */

expfile(file)
char *file;
{
	register char *fpart, *p;
D 3
	char user[20], *up;
E 3
I 3
	char user[WKDSIZE], *up;
E 3
D 2
	char full[100];
E 2
I 2
	char full[MAXFULLNAME];
E 2
	int uid;

	switch(file[0]) {
	case '/':
D 4
		return(1);
E 4
I 4
		return 1;
E 4
	case '~':
		for (fpart = file + 1, up = user; *fpart != '\0'
D 2
			&& *fpart != '/'; fpart++)
E 2
I 2
D 3
			&& *fpart != '/' && up < user+sizeof(user)-1; fpart++)
E 3
I 3
D 4
			&& *fpart != '/'; fpart++)
E 4
I 4
D 5
			&& *fpart != '/' && up < user+sizeof(user)-1; fpart++)
E 5
I 5
			&& *fpart != '/'; fpart++)
E 5
E 4
E 3
E 2
				*up++ = *fpart;
		*up = '\0';
D 3
		/* ll1b.105, mn, Mark Nettleingham, defend against
		 * null login name in /etc/passwd
		 */
E 3
		if (!*user || gninfo(user, &uid, full) != 0) {
			strcpy(full, PUBDIR);
		}
	
		strcat(full, fpart);
		strcpy(file, full);
D 3
		return(1);
E 3
I 3
		return 1;
E 3
	default:
		p = index(file, '/');
D 2
		strcpy(full, Wrkdir);
		strcat(full, "/");
		strcat(full, file);
E 2
I 2
D 3
		sprintf(full, "%s/%s", Wrkdir, file);
E 3
I 3
		strcpy(full, Wrkdir);
		strcat(full, "/");
		strcat(full, file);
E 3
E 2
		strcpy(file, full);
		if (Wrkdir[0] == '\0')
D 3
			return(FAIL);
E 3
I 3
			return FAIL;
E 3
		else if (p != NULL)
D 3
			return(1);
		return(0);
E 3
I 3
			return 1;
		return 0;
E 3
	}
}


D 4
/***
 *	isdir(name)	check if directory name
 *	char *name;
E 4
I 4
/*
 *	check if directory name
E 4
 *
 *	return codes:  0 - not directory  |  1 - is directory
 */

isdir(name)
char *name;
{
	register int ret;
	struct stat s;

	ret = stat(subfile(name), &s);
	if (ret < 0)
D 3
		return(0);
E 3
I 3
		return 0;
E 3
	if ((s.st_mode & S_IFMT) == S_IFDIR)
D 3
		return(1);
	return(0);
E 3
I 3
		return 1;
	return 0;
E 3
}


D 4
/***
 *	mkdirs(name)	make all necessary directories
 *	char *name;
E 4
I 4
/*
 *	make all necessary directories
E 4
 *
D 4
 *	return 0  |  FAIL
E 4
I 4
 *	return SUCCESS  |  FAIL
E 4
 */

mkdirs(name)
char *name;
{
	int ret, mask;
D 3
	char cmd[100], dir[100];
E 3
I 3
D 4
	char cmd[MAXFULLNAME], dir[MAXFULLNAME];
E 4
I 4
	char dir[MAXFULLNAME];
E 4
E 3
	register char *p;

	for (p = dir + 1;; p++) {
		strcpy(dir, name);
		if ((p = index(p, '/')) == NULL)
D 3
			return(0);
E 3
I 3
D 4
			return 0;
E 4
I 4
			return SUCCESS;
E 4
E 3
		*p = '\0';
		if (isdir(dir))
			continue;

D 3
		/* rti!trt: add chmod ala 4.1c uucp */
E 3
D 4
		sprintf(cmd, "mkdir %s;chmod 0777 %s", dir, dir);
E 4
		DEBUG(4, "mkdir - %s\n", dir);
		mask = umask(0);
D 4
		ret = shio(cmd, CNULL, CNULL, User);
E 4
I 4
		ret = mkdir(dir, 0777);
E 4
		umask(mask);
		if (ret != 0)
D 3
			return(FAIL);
E 3
I 3
			return FAIL;
E 3
	}
I 3
	/* NOTREACHED */
E 3
}

D 4
/***
 *	ckexpf - expfile and check return
E 4
I 4
/*
 *	expfile and check return
E 4
 *		print error if it failed.
 *
D 4
 *	return code - 0 - ok; FAIL if expfile failed
E 4
I 4
 *	return code - SUCCESS - ok; FAIL if expfile failed
E 4
 */

ckexpf(file)
register char *file;
{

	if (expfile(file) != FAIL)
D 3
		return(0);
E 3
I 3
D 4
		return 0;
E 4
I 4
		return SUCCESS;
E 4
E 3

	/*  could not expand file name */
	/* the gwd routine failed */

D 3
	fprintf(stderr, "Can't expand filename (%s). Pwd failed.\n", file+1);
	return(FAIL);
E 3
I 3
	logent("CAN'T EXPAND FILENAME - PWD FAILED", file+1);
	return FAIL;
E 3
}
E 1
