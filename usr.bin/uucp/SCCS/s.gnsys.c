h37098
s 00018/00006/00124
d D 5.6 88/04/05 12:06:33 rick 6 5
c use syslog for errors, increase max number of systems,support whitespace seperators instead of just blank
e
s 00013/00019/00117
d D 5.5 88/02/24 20:00:42 rick 5 4
c rewrite to use native readdir() routines. massive spedup
e
s 00029/00004/00107
d D 5.4 85/06/20 09:48:18 bloom 4 3
c fixes from rick adams
e
s 00013/00032/00098
d D 5.3 85/01/22 14:08:53 ralph 3 2
c bug fixes and changes from Rick Adams
e
s 00001/00001/00129
d D 5.2 83/07/02 18:05:39 sam 2 1
c include fixes
e
s 00130/00000/00000
d D 5.1 83/07/02 17:57:01 sam 1 0
c date and time created 83/07/02 17:57:01 by sam
e
u
U
t
T
I 1
#ifndef lint
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
D 6
static char sccsid[] = "%W%	%G%";
E 6
I 6
static char sccsid[] = "%W%	(Berkeley) %G%";
E 6
E 5
#endif

D 3
/*
 * Mods:
 * The "retry" code below prevents uucico from calling
 * a site which it has called earlier.
 * Also, uucico does callok() only once for each system.
 * Done by unc!smb
 */

E 3
#include "uucp.h"
D 4
#include <sys/types.h>
E 4
#ifdef	NDIR
#include "ndir.h"
#else
D 2
#include <dir.h>
E 2
I 2
#include <sys/dir.h>
E 2
#endif

D 3

E 3
D 4
#define LSIZE 100	/* number of systems to store */
E 4
I 4
D 6
#define LSIZE 128	/* number of systems to store */
E 6
I 6
#define LSIZE 512	/* number of systems to store */
E 6
E 4
#define WSUFSIZE 6	/* work file name suffix size */

I 4
/*LINTLIBRARY*/

E 4
D 3
/*******
 *	gnsys(sname, dir, pre)
 *	char *sname, *dir, pre;
 *
 *	gnsys  -  this routine will return the next
 *	system name which has work to be done.
E 3
I 3
/*
 *	this routine will return the next system name which has work to be done.
 *	"sname" is a string of size DIRSIZ - WSUFSIZE.
E 3
 *	"pre" is the prefix for work files.
 *	"dir" is the directory to search.
D 3
 *	"sname" is a string of size DIRSIZ - WSUFSIZE.
E 3
 *
 *	return codes:
D 4
 *		0  -  no more names
E 4
 *		1  -  name returned in sname
I 4
 *		SUCCESS  -  no more names
E 4
 *		FAIL  -  bad directory
 */
D 5

E 5
gnsys(sname, dir, pre)
char *sname, *dir, pre;
{
D 5
	register char *s, *p1, *p2;
	char px[3];
E 5
I 5
	register DIR *dirp;
	register struct direct *dentp;
E 5
	static char *list[LSIZE];
D 5
	static int nitem=0, n=0, base=0;
	char systname[NAMESIZE], filename[NAMESIZE];
	DIR *dirp;
E 5
I 5
	static int nitem = 0, n = 0, base = 0;
	char systname[NAMESIZE];
E 5

retry:
D 5
	px[0] = pre;
	px[1] = '.';
	px[2] = '\0';
E 5
	if (nitem == base) {
		/* get list of systems with work */
		int i;
D 3
		dirp = opendir(subdir(dir,pre), "r");
E 3
I 3
		dirp = opendir(subdir(dir,pre));
E 3
D 6
		ASSERT(dirp != NULL, "BAD DIRECTORY", dir, 0);
E 6
I 6
		if (dirp == NULL) {
			syslog(LOG_ERR, "opendir(%s) failed: %m",
				subdir(dir,pre));
			cleanup(FAIL);
		}
E 6
		for (i = base; i < LSIZE; i++)
			list[i] = NULL;
D 5
		while (gnamef(dirp, filename) != 0) {
			if (!prefix(px, filename))
E 5
I 5
		while (dentp = readdir(dirp)) {
			register char *s, *p1, *p2;
			if (dentp->d_name[0] != pre || dentp->d_name[1] != '.')
E 5
				continue;
D 5
			p2 = filename + strlen(filename)
				- WSUFSIZE;
			p1 = filename + strlen(px);
E 5
I 5
			p2 = dentp->d_name + dentp->d_namlen - WSUFSIZE;
			p1 = dentp->d_name + 2;
E 5
			for(s = systname; p1 <= p2; p1++)
				*s++ = *p1;
			*s = '\0';
			if (systname[0] == '\0')
				continue;
			nitem = srchst(systname, list, nitem);
D 5
			if (LSIZE <= nitem) break;
E 5
I 5
D 6
			if (LSIZE <= nitem)
E 6
I 6
			if (LSIZE <= nitem) {
				syslog(LOG_WARNING,
					"%s: Increase LSIZE in gnsys.c",
					systname);
E 6
				break;
I 6
			}
E 6
E 5
		}
D 5

E 5
		closedir(dirp);
	}

	if (nitem == base) {
		for (n = 0; n < nitem; n++)
			if (list[n] != NULL)
				free(list[n]);
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
	}
D 5
	while(nitem > n) {
E 5
I 5
	while (nitem > n) {
E 5
I 4
		/* We only have at most a SYSNSIZE character site name encoded
		 * in the file. However, we would like to use the full sitename
		 * if possible. If the number of chars in list[n] is < SYSNSIZE
		 * then the sitename could not have been truncated and
		 * we don't bother to check. Otherwise, we scan SYSFILE
		 * looking for the fullname and return it if we find it
		 */
E 4
		strcpy(sname, list[n++]);
I 4
		if (strlen(sname) >= SYSNSIZE) {
			register FILE *fp;
			register char *p;
			char line[MAXFULLNAME];
			fp = fopen(SYSFILE, "r");
D 6
			ASSERT(fp != NULL, CANTOPEN, SYSFILE, 0);
E 6
I 6
			if (fp == NULL) {
				syslog(LOG_ERR, "fopen(%s) failed: %m",
					SYSFILE);
				cleanup(FAIL);
			}
E 6
			while (cfgets(line, sizeof(line), fp) != NULL) {
D 6
				p = index(line, ' ');
E 6
I 6
				p = strpbrk(line, " \t");
E 6
				if (p)
					*p = '\0';
				if (strncmp(sname, line, SYSNSIZE) == SAME) {
					strncpy(sname, line, MAXBASENAME);
					break;
				}
			}
			fclose(fp);
		}
E 4
		if (callok(sname) == 0)
D 3
			return(1);
E 3
I 3
			return 1;
E 3
	}
	base = n = nitem;
	goto retry;
}

D 3
/***
 *	srchst(name, list, n)
 *	char *name, **list;
 *	int n;
E 3
I 3
/*
 *	this routine will do a linear search of list (list) to find name (name).
 *	If the name is not found, it is added to the list.
 *	The number of items in the list (n) is returned (incremented if a
 *	name is added).
E 3
 *
D 3
 *	srchst  -  this routine will do a linear search
 *	of list (list) to find name (name).
 *	If the name is not found, it is added to the
 *	list.
 *	The number of items in the list (n) is
 *	returned (incremented if a name is added).
 *
E 3
 *	return codes:
 *		n - the number of items in the list
 */
D 5

E 5
srchst(name, list, n)
char *name;
register char **list;
int n;
{
	register int i;
	register char *p;

	for (i = 0; i < n; i++)
		if (strcmp(name, list[i]) == 0)
			break;
	if (i >= n) {
		if ((p = calloc((unsigned)strlen(name) + 1, sizeof (char)))
			== NULL)
D 3
			return(n);
E 3
I 3
			return n;
E 3
		strcpy(p, name);
		list[n++] = p;
	}
D 3
	return(n);
E 3
I 3
	return n;
E 3
}
E 1
