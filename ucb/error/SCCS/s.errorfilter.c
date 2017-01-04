h26852
s 00010/00005/00163
d D 5.3 88/06/29 18:50:50 bostic 5 4
c install approved copyright notice
e
s 00009/00003/00159
d D 5.2 88/06/06 21:51:31 bostic 4 3
c written by Robert Henry; add Berkeley specific header
e
s 00010/00001/00152
d D 5.1 85/05/31 11:40:49 dist 3 2
c Add copyright
e
s 00016/00016/00137
d D 1.2 82/01/22 17:55:35 rrh 2 1
c Re proceduralization in errortouch for clarity.
c Added -T (terse option)
c Added typedefs, and changed textual form of structures
c changed argument to vi to begin searching from line 1, instead of line $
e
s 00153/00000/00000
d D 1.1 80/10/16 09:46:31 root 1 0
c date and time created 80/10/16 09:46:31 by root
e
u
U
t
T
I 1
D 3
static	char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 5
E 4
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif /* not lint */
E 4

E 3
#include <stdio.h>
#include <ctype.h>
#include <pwd.h>
#include "error.h"

char	*lint_libs[] = {
	IG_FILE1,
	IG_FILE2,
	IG_FILE3,
	IG_FILE4,
	0
};
extern	char*	processname;
int	lexsort();
/*
 *	Read the file ERRORNAME of the names of functions in lint
 *	to ignore complaints about.
 */
getignored(auxname)
	char	*auxname;
{
D 2
	register	int	i;
			FILE	*fyle;
			char	inbuffer[256];
			int	uid;
			char	filename[128];
			char	*username;
			struct	passwd *passwdentry;
E 2
I 2
	reg	int	i;
		FILE	*fyle;
		char	inbuffer[256];
		int	uid;
		char	filename[128];
		char	*username;
		struct	passwd *passwdentry;
E 2

	nignored = 0;
	if (auxname == 0){	/* use the default */
		if ( (username = (char *)getlogin()) == NULL){
			username = "Unknown";
			uid = getuid();
			if ( (passwdentry = (struct passwd *)getpwuid(uid)) == NULL){
				return;
			}
		} else {
			if ( (passwdentry = (struct passwd *)getpwnam(username)) == NULL)
				return;
		}
		strcpy(filename, passwdentry->pw_dir);
D 2
		strcat(filename, ERRORNAME);
E 2
I 2
		(void)strcat(filename, ERRORNAME);
E 2
	} else
D 2
		strcpy(filename, auxname);
E 2
I 2
		(void)strcpy(filename, auxname);
E 2
#ifdef FULLDEBUG
	printf("Opening file \"%s\" to read names to ignore.\n",
		filename);
#endif
	if ( (fyle = fopen(filename, "r")) == NULL){
#ifdef FULLDEBUG
		fprintf(stderr, "%s: Can't open file \"%s\"\n",
			processname, filename);
#endif
		return;
	}
	/*
	 *	Make the first pass through the file, counting lines
	 */
	for (nignored = 0; fgets(inbuffer, 255, fyle) != NULL; nignored++)
		continue;
	names_ignored = (char **)Calloc(nignored+1, sizeof (char *));
	fclose(fyle);
	if (freopen(filename, "r", fyle) == NULL){
#ifdef FULLDEBUG
		fprintf(stderr, "%s: Failure to open \"%s\" for second read.\n",
			processname, filename);
#endif
		nignored = 0;
		return;
	}
	for (i=0; i < nignored && (fgets (inbuffer, 255, fyle) != NULL); i++){
		names_ignored[i] = strsave(inbuffer);
D 2
		substitute(names_ignored[i], '\n', '\0');
E 2
I 2
		(void)substitute(names_ignored[i], '\n', '\0');
E 2
	}
	qsort(names_ignored, nignored, sizeof *names_ignored, lexsort);
#ifdef FULLDEBUG
	printf("Names to ignore follow.\n");
	for (i=0; i < nignored; i++){
		printf("\tIgnore: %s\n", names_ignored[i]);
	}
#endif
}

int lexsort(cpp1, cpp2)
	char	**cpp1, **cpp2;
{
	return(strcmp(*cpp1, *cpp2));
}

int search_ignore(key)
	char	*key;
{
D 2
	register	int	ub, lb;
	register	int	halfway;
			int	order;
E 2
I 2
	reg	int	ub, lb;
	reg	int	halfway;
		int	order;
E 2

	if (nignored == 0)
		return(-1);
	for(lb = 0, ub = nignored - 1; ub >= lb; ){
		halfway = (ub + lb)/2;
		if ( (order = strcmp(key, names_ignored[halfway])) == 0)
			return(halfway);
		if (order < 0)	/*key is less than probe, throw away above*/
			ub = halfway - 1;
		 else
			lb = halfway + 1;
	}
	return(-1);
}

/*
 *	Tell if the error text is to be ignored.
 *	The error must have been canonicalized, with
 *	the file name the zeroth entry in the errorv,
 *	and the linenumber the second.
 *	Return the new categorization of the error class.
 */
Errorclass discardit(errorp)
D 2
	register	struct	error_desc	*errorp;
E 2
I 2
	reg	Eptr	errorp;
E 2
{
D 2
			int	language;
	register	int	i;
E 2
I 2
		int	language;
	reg	int	i;
E 2
	Errorclass	errorclass = errorp->error_e_class;

	switch(errorclass){
		case	C_SYNC:
		case	C_NONSPEC:
		case	C_UNKNOWN:	return(errorclass);
		default:	;
	}
	if(errorp->error_lgtext < 2){
		return(C_NONSPEC);
	}
	language = errorp->error_language;
	if(language == INLINT){
		if (errorclass != C_NONSPEC){	/* no file */
			for(i=0; lint_libs[i] != 0; i++){
				if (strcmp(errorp->error_text[0], lint_libs[i]) == 0){
					return(C_DISCARD);
				}
			}
		}
		/* check if the argument to the error message is to be ignored*/
		if (ispunct(lastchar(errorp->error_text[2])))
			clob_last(errorp->error_text[2], '\0');
		if (search_ignore(errorp->error_text[errorclass == C_NONSPEC ? 0 : 2]) >= 0){
			return(C_NULLED);
		}
	}
	return(errorclass);
}
E 1
