h34862
s 00010/00014/00099
d D 5.4 86/07/25 18:03:49 bloom 5 3
c fix comments at beginning of line, fix buffer pointer handling
e
s 00002/00005/00108
d R 5.4 86/07/18 17:27:37 bloom 4 3
c clean up comment handling some more, keep shells straight
e
s 00002/00000/00111
d D 5.3 86/07/18 14:10:23 bloom 3 2
c ignore comments starting at beginning of line
e
s 00002/00002/00109
d D 5.2 86/03/09 19:49:15 donn 2 1
c added LIBC_SCCS condition for sccs ids
e
s 00111/00000/00000
d D 5.1 85/11/08 18:14:31 mckusick 1 0
c date and time created 85/11/08 18:14:31 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 2
#ifndef lint
E 2
I 2
#if defined(LIBC_SCCS) && !defined(lint)
E 2
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif not lint
E 2
I 2
#endif LIBC_SCCS and not lint
E 2

#include <sys/param.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdio.h>

#define SHELLS "/etc/shells"

/*
 * Do not add local shells here.  They should be added in /etc/shells
 */
static char *okshells[] =
    { "/bin/sh", "/bin/csh", 0 };

D 5
static int inprogress;
E 5
static char **shells, *strings;
I 5
static char **curshell = NULL;
E 5
extern char **initshells();

/*
 * Get a list of shells from SHELLS, if it exists.
 */
char *
getusershell()
{
	char *ret;
D 5
	static char **shells;
E 5

D 5
	if (!inprogress)
		shells = initshells();
	ret = *shells;
	if (*shells != NULL)
		shells++;
E 5
I 5
	if (curshell == NULL)
		curshell = initshells();
	ret = *curshell;
	if (ret != NULL)
		curshell++;
E 5
	return (ret);
}

endusershell()
{
	
	if (shells != NULL)
		free((char *)shells);
	shells = NULL;
	if (strings != NULL)
		free(strings);
	strings = NULL;
D 5
	inprogress = 0;
E 5
I 5
	curshell = NULL;
E 5
}

setusershell()
{

D 5
	shells = initshells();
E 5
I 5
	curshell = initshells();
E 5
}

static char **
initshells()
{
	register char **sp, *cp;
	register FILE *fp;
	struct stat statb;
	extern char *malloc(), *calloc();

D 5
	inprogress = 1;
E 5
	if (shells != NULL)
		free((char *)shells);
	shells = NULL;
	if (strings != NULL)
		free(strings);
	strings = NULL;
	if ((fp = fopen(SHELLS, "r")) == (FILE *)0)
		return(okshells);
	if (fstat(fileno(fp), &statb) == -1) {
		(void)fclose(fp);
		return(okshells);
	}
	if ((strings = malloc((unsigned)statb.st_size)) == NULL) {
		(void)fclose(fp);
		return(okshells);
	}
	shells = (char **)calloc((unsigned)statb.st_size / 3, sizeof (char *));
	if (shells == NULL) {
		(void)fclose(fp);
		free(strings);
		strings = NULL;
		return(okshells);
	}
	sp = shells;
	cp = strings;
	while (fgets(cp, MAXPATHLEN + 1, fp) != NULL) {
I 3
D 5
		if (*cp == '#')
			continue;
E 3
		while (*cp != '/' && *cp != '\0')
E 5
I 5
		while (*cp != '#' && *cp != '/' && *cp != '\0')
E 5
			cp++;
D 5
		if (*cp == '\0')
E 5
I 5
		if (*cp == '#' || *cp == '\0')
E 5
			continue;
		*sp++ = cp;
		while (!isspace(*cp) && *cp != '#' && *cp != '\0')
			cp++;
		*cp++ = '\0';
	}
	*sp = (char *)0;
	(void)fclose(fp);
	return (shells);
}
E 1
