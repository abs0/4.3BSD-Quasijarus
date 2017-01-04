h06663
s 00010/00005/00737
d D 5.3 88/06/29 18:51:00 bostic 11 10
c install approved copyright notice
e
s 00009/00003/00733
d D 5.2 88/06/06 21:51:39 bostic 10 9
c written by Robert Henry; add Berkeley specific header
e
s 00010/00001/00726
d D 5.1 85/05/31 11:42:51 dist 9 8
c Add copyright
e
s 00010/00008/00717
d D 1.7 84/09/25 10:28:26 ralph 8 7
c fix -n and -t so files aren't touched.
e
s 00005/00000/00720
d D 1.6 84/06/05 10:53:53 ralph 7 6
c changes to allow it to work from at(1), etc. when there is no tty.
e
s 00071/00008/00649
d D 1.5 82/11/20 18:38:12 rrh 6 4
c Fail safe when overwriting a source file with inserted error messages
c user is queried if he/she should continue, otherwise a copy saved in /tmp
c and error exits
e
s 00071/00008/00649
d R 1.5 82/11/20 18:36:13 rrh 5 4
c Fail safe when overwriting the error source file, to protect
c agains file system full, etc.  User is queried about what to do; as a last
c resort, the file is saved someplace in /tmp
e
s 00058/00010/00599
d D 1.4 82/05/04 12:34:15 rrh 4 3
c Preserves links by writing to /tmp and copying.  Removed #ifdef ERNIE
e
s 00385/00224/00224
d D 1.3 82/01/22 17:56:21 rrh 3 2
c Re proceduralization in errortouch for clarity.
c Added -T (terse option)
c Added typedefs, and changed textual form of structures
c changed argument to vi to begin searching from line 1, instead of line $
e
s 00013/00005/00435
d D 1.2 80/10/16 09:57:32 root 2 1
c If previewed the errors, never look at them again
e
s 00440/00000/00000
d D 1.1 80/10/16 09:46:49 root 1 0
c date and time created 80/10/16 09:46:49 by root
e
u
U
t
T
I 1
D 9
static	char *sccsid = "%W% (Berkeley) %G%";
E 9
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
#endif /* not lint */
E 10

E 9
#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include "error.h"

I 3
/*
 *	Iterate through errors
 */
#define EITERATE(p, fv, i)	for (p = fv[i]; p < fv[i+1]; p++)
#define	ECITERATE(ei, p, lb)	for (ei = lb; p = errors[ei],ei < nerrors; ei++)

#define	FILEITERATE(fi, lb)	for (fi = lb; fi <= nfiles; fi++)
int	touchstatus = Q_YES;

E 3
findfiles(nerrors, errors, r_nfiles, r_files)
D 3
	int	nerrors;
	struct	error_desc	**errors;
	int	*r_nfiles;
	struct	error_desc	****r_files;
E 3
I 3
		int	nerrors;
	Eptr	*errors;
		int	*r_nfiles;
	Eptr	***r_files;
E 3
{
D 3
			int	nfiles;
	struct	error_desc	***files;
E 3
I 3
		int	nfiles;
	Eptr	**files;
E 3

D 3
			char	*currentfilename;
	register	int	errorindex;
			int	fileindex;
	register	struct	error_desc	*errorp;
	/*
	 *	First, go through and count all of the filenames
	 */
	for (errorp = errors[errorindex = 0],nfiles = 0, currentfilename = "\1";
	     errorindex < nerrors;
	     errorp = errors[++errorindex]){
		if (SORTABLE(errorp->error_e_class)){
			if (strcmp(errorp->error_text[0],currentfilename) != 0){
				nfiles++;
				currentfilename = errorp->error_text[0];
			}
		}
	}
	files = (struct error_desc ***)Calloc(nfiles + 3,
		sizeof (struct error_desc**));
E 3
I 3
		char	*name;
	reg	int	ei;
		int	fi;
	reg	Eptr	errorp;

	nfiles = countfiles(errors);

	files = (Eptr**)Calloc(nfiles + 3, sizeof (Eptr*));
E 3
	touchedfiles = (boolean	*)Calloc(nfiles+3, sizeof(boolean));
	/*
D 3
	 *	Now, go through and partition off the error messages
E 3
I 3
	 *	Now, partition off the error messages
E 3
	 *	into those that are synchronization, discarded or
	 *	not specific to any file, and those that were
	 *	nulled or true errors.
	 */
	files[0] = &errors[0];
D 3
	for (errorp = errors[errorindex = 0], fileindex = 0;
	     (errorindex < nerrors) &&
		(NOTSORTABLE(errorp->error_e_class));
	     errorp = errors[++errorindex]){
		continue;
E 3
I 3
	ECITERATE(ei, errorp, 0){
		if ( ! (NOTSORTABLE(errorp->error_e_class)))
			break;
E 3
	}
	/*
D 3
	 *	Now, go through and partition off all error messages
E 3
I 3
	 *	Now, and partition off all error messages
E 3
	 *	for a given file.
	 */
D 3
	files[1] = &errors[errorindex];
E 3
I 3
	files[1] = &errors[ei];
E 3
	touchedfiles[0] = touchedfiles[1] = FALSE;
D 3
	for (errorp = errors[errorindex], currentfilename = "\1", fileindex = 1;
	     errorindex < nerrors; errorp = errors[++errorindex]){
		if ( (errorp->error_e_class == C_NULLED) || (errorp->error_e_class == C_TRUE) ){
			if (strcmp(errorp->error_text[0],currentfilename) != 0){
				currentfilename = errorp->error_text[0];
				touchedfiles[fileindex] = FALSE;
				files[fileindex++] = &errors[errorindex];
E 3
I 3
	name = "\1";
	fi = 1;
	ECITERATE(ei, errorp, ei){
		if (   (errorp->error_e_class == C_NULLED)
		    || (errorp->error_e_class == C_TRUE) ){
			if (strcmp(errorp->error_text[0], name) != 0){
				name = errorp->error_text[0];
				touchedfiles[fi] = FALSE;
				files[fi] = &errors[ei];
				fi++;
E 3
			}
		}
	}
D 3
	files[fileindex] = &errors[nerrors];
E 3
I 3
	files[fi] = &errors[nerrors];
E 3
	*r_nfiles = nfiles;
	*r_files = files;
}

I 3
int countfiles(errors)
	Eptr	*errors;
{
	char	*name;
	int	ei;
	reg	Eptr	errorp;

	int	nfiles;
	nfiles = 0;
	name = "\1";
	ECITERATE(ei, errorp, 0){
		if (SORTABLE(errorp->error_e_class)){
			if (strcmp(errorp->error_text[0],name) != 0){
				nfiles++;
				name = errorp->error_text[0];
			}
		}
	}
	return(nfiles);
}
E 3
char	*class_table[] = {
	/*C_UNKNOWN	0	*/	"Unknown",
	/*C_IGNORE	1	*/	"ignore",
	/*C_SYNC	2	*/	"synchronization",
	/*C_DISCARD	3	*/	"discarded",
	/*C_NONSPEC	4	*/	"non specific",
	/*C_THISFILE	5	*/	"specific to this file",
	/*C_NULLED	6	*/	"nulled",
	/*C_TRUE	7	*/	"true",
	/*C_DUPL	8	*/	"duplicated"
};

int	class_count[C_LAST - C_FIRST] = {0};

filenames(nfiles, files)
	int	nfiles;
D 3
	struct	error_desc	***files;
E 3
I 3
	Eptr	**files;
E 3
{
D 3
	register	int	fileindex;
	register	struct	error_desc	*errorp;
	register	struct	error_desc	**erpp;
			char	*sep = " ";
	register	int	errortype;
	extern		char	*class_table[];
			int	someerrors = 0;
E 3
I 3
	reg	int	fi;
		char	*sep = " ";
	extern	char	*class_table[];
		int	someerrors;
E 3

	/*
D 3
	 *	first, go through and simply dump out errors that
E 3
I 3
	 *	first, simply dump out errors that
E 3
	 *	don't pertain to any file
	 */
D 3
	if (files[1] - files[0] > 0){
	    for(errortype = C_UNKNOWN; NOTSORTABLE(errortype); errortype++){
		if (class_count[errortype] > 0){
			if (errortype > C_SYNC)
				someerrors++;
			fprintf(stdout, "\n\t%d %s errors follow:\n",
				class_count[errortype], class_table[errortype]);
			for (errorp = *(erpp = files[0]);
			     erpp < files[1];
			     errorp = (*++erpp)){
				if (errorp->error_e_class == errortype)
					errorprint(stdout, errorp, TRUE);
			}
		}
	    }
	}
E 3
I 3
	someerrors = nopertain(files);

E 3
	if (nfiles){
		someerrors++;
D 3
		fprintf(stdout, "%d files contain errors:", nfiles);
		for (fileindex = 1; fileindex <= nfiles; fileindex++){
			fprintf(stdout, "%s\"%s\" (%d)",
				sep, (*files[fileindex])->error_text[0],
				files[fileindex+1] - files[fileindex]);
			sep = ", ";
E 3
I 3
		fprintf(stdout, terse
			? "%d file%s"
			: "%d file%s contain%s errors",
			nfiles, plural(nfiles), verbform(nfiles));
		if (!terse){
			FILEITERATE(fi, 1){
				fprintf(stdout, "%s\"%s\" (%d)",
					sep, (*files[fi])->error_text[0],
					files[fi+1] - files[fi]);
				sep = ", ";
			}
E 3
		}
		fprintf(stdout, "\n");
	}
	if (!someerrors)
		fprintf(stdout, "No errors.\n");
}

I 3
/*
 *	Dump out errors that don't pertain to any file
 */
int nopertain(files)
	Eptr	**files;
{
	int	type;
	int	someerrors = 0;
	reg	Eptr	*erpp;
	reg	Eptr	errorp;

	if (files[1] - files[0] <= 0)
		return(0);
	for(type = C_UNKNOWN; NOTSORTABLE(type); type++){
		if (class_count[type] <= 0)
			continue;
		if (type > C_SYNC)
			someerrors++;
		if (terse){
			fprintf(stdout, "\t%d %s errors NOT PRINTED\n",
				class_count[type], class_table[type]);
		} else {
			fprintf(stdout, "\n\t%d %s errors follow\n",
				class_count[type], class_table[type]);
			EITERATE(erpp, files, 0){
				errorp = *erpp;
				if (errorp->error_e_class == type){
					errorprint(stdout, errorp, TRUE);
				}
			}
		}
	}
	return(someerrors);
}

E 3
extern	boolean	notouch;

boolean touchfiles(nfiles, files, r_edargc, r_edargv)
	int	nfiles;
D 3
	struct	error_desc	***files;
E 3
I 3
	Eptr	**files;
E 3
	int	*r_edargc;
	char	***r_edargv;
{
D 3
			char	*currentfilename;
	register	struct	error_desc	*errorp;
	register	int	fileindex;
	register	struct	error_desc	**erpp;
			int		ntrueerrors;
			int		errordest;	/* where errors go*/
			char		*sep;
			boolean		scribbled;
D 2
			int		n_pissed_on;	/* how many files touched*/
E 2
I 2
			int		n_pissed_on;	/* # of file touched*/
			int		previewed;
E 3
I 3
		char	*name;
	reg	Eptr	errorp;
	reg	int	fi;
	reg	Eptr	*erpp;
		int		ntrueerrors;
		boolean		scribbled;
		int		n_pissed_on;	/* # of file touched*/
		int	spread;
E 3

E 2
D 3
	for (fileindex = 1; fileindex <= nfiles; fileindex++){
		fprintf(stdout, "\nFile \"%s\" has %d total error messages.\n",
			currentfilename = (*files[fileindex])->error_text[0],
			files[fileindex+1] - files[fileindex]);
E 3
I 3
	FILEITERATE(fi, 1){
		name = (*files[fi])->error_text[0];
		spread = files[fi+1] - files[fi];
		fprintf(stdout, terse
			? "\"%s\" has %d error%s, "
			: "\nFile \"%s\" has %d error%s.\n"
			, name ,spread ,plural(spread));
E 3
		/*
		 *	First, iterate through all error messages in this file
		 *	to see how many of the error messages really will
		 *	get inserted into the file.
		 */
D 3
		for (erpp = files[fileindex], ntrueerrors = 0;
		     erpp < files[fileindex+1];
		     erpp++){
E 3
I 3
		ntrueerrors = 0;
		EITERATE(erpp, files, fi){
E 3
			errorp = *erpp;
			if (errorp->error_e_class == C_TRUE)
				ntrueerrors++;
		}
D 3
		fprintf(stdout,"\t%d of these errors can be inserted into the file.\n",
E 3
I 3
		fprintf(stdout, terse
		  ? "insert %d\n"
		  : "\t%d of these errors can be inserted into the file.\n",
E 3
			ntrueerrors);

D 3
		/*
		 *	What does the operator want?
		 */
I 2
		previewed = 0;
E 2
		errordest = TOSTDOUT;
		if (oktotouch(currentfilename) && (ntrueerrors > 0) ){
			if (query && inquire("Do you want to preview the errors first?")){
I 2
				previewed = 1;
E 2
				for (erpp = files[fileindex];
				     erpp < files[fileindex + 1];
				     erpp++){
					errorprint(stdout, *erpp, TRUE);
				}
				fprintf(stdout, "\n");
			}
			if (   !query
			    || inquire("Do you want to touch file \"%s\"? ",
					currentfilename)
			){
				errordest = TOTHEFILE;
				if (!probethisfile(currentfilename)){
					errordest = TOSTDOUT;
					fprintf(stdout,
					 "Can't find file \"%s\" to insert error messages into.\n",
						currentfilename);
				} else {
					if (edit(currentfilename))
						errordest = TOSTDOUT;
					else
						touchedfiles[fileindex] = TRUE;
				}
			}
		}
I 2
		if (previewed && (errordest == TOSTDOUT))
			continue;		/* with the next file */
E 2
		/*
		 *	go through and print each error message,
		 *	diverting to the right place
		 */
		if ( (files[fileindex+1] - files[fileindex]) != ntrueerrors)
D 2
			fprintf(stdout,
E 2
I 2
			if (!previewed) fprintf(stdout,
E 2
			    ">>Uninserted error messages for file \"%s\" follow.\n",
			    currentfilename);
		for (erpp = files[fileindex];erpp < files[fileindex+1];erpp++){
			errorp = *erpp;
			if (errorp->error_e_class == C_TRUE){
				switch (errordest){
				  case TOSTDOUT:
D 2
					errorprint(stdout, errorp, TRUE);
					  break;
E 2
I 2
					if (!previewed)
						errorprint(stdout,errorp, TRUE);
					break;
E 2
				  case TOTHEFILE:
					insert(errorp->error_line);
					text(errorp, FALSE);
					break;
				}	/* switch */
			} else {
D 2
				errorprint(stdout, errorp, TRUE);
E 2
I 2
				if (!previewed)
					errorprint(stdout, errorp, TRUE);
E 2
			}
		}	/* end of walking through all errors*/
		if (errordest == TOTHEFILE){
			writetouched();
		}
	}	/* end of walking through all files*/
E 3
I 3
		hackfile(name, files, fi, ntrueerrors);
	}
E 3
	scribbled = FALSE;
D 3
	for (n_pissed_on = 0, fileindex = 1; fileindex <= nfiles; fileindex++){
		scribbled |= touchedfiles[fileindex];
E 3
I 3
	n_pissed_on = 0;
	FILEITERATE(fi, 1){
		scribbled |= touchedfiles[fi];
E 3
		n_pissed_on++;
	}
	if (scribbled){
		/*
		 *	Construct an execv argument
D 3
		 *	We need 1 argument for the editor's name
		 *	We need 1 argument for the initial search string
		 *	We need n_pissed_on arguments for the file names
		 *	We need 1 argument that is a null for execv.
		 *	The caller fills in the editor's name.
		 *	We fill in the initial search string.
		 *	We fill in the arguments, and the null.
E 3
		 */
D 3
		(*r_edargv) = (char **)Calloc(n_pissed_on + 3, sizeof(char *));
		(*r_edargc) =  n_pissed_on + 2;
		(*r_edargv)[1] = "+/###/";
		n_pissed_on = 2;
		fprintf(stdout, "You touched file(s):");
		sep = " ";
		for (fileindex = 1; fileindex <= nfiles; fileindex++){
			if (!touchedfiles[fileindex])
				continue;
			errorp = *(files[fileindex]);
			fprintf(stdout,"%s\"%s\"", sep, errorp->error_text[0]);
			sep = ", ";
			(*r_edargv)[n_pissed_on++] = errorp->error_text[0];
		}
		fprintf(stdout, "\n");
		(*r_edargv)[n_pissed_on] = 0;
E 3
I 3
		execvarg(n_pissed_on, r_edargc, r_edargv);
E 3
		return(TRUE);
	} else {
D 3
		fprintf(stdout, "You didn't touch any files.\n");
E 3
I 3
		if (!terse)
			fprintf(stdout, "You didn't touch any files.\n");
E 3
		return(FALSE);
	}
I 3
}
E 3

D 3
}	/* end of touchfiles*/
int	oktotouch(filename)
E 3
I 3
hackfile(name, files, ix, nerrors)
	char	*name;
	Eptr	**files;
	int	ix;
{
	boolean	previewed;
	int	errordest;	/* where errors go*/

D 8
	previewed = preview(name, nerrors, files, ix);
E 8
I 8
	if (!oktotouch(name)) {
		previewed = FALSE;
		errordest = TOSTDOUT;
	} else {
		previewed = preview(name, nerrors, files, ix);
		errordest = settotouch(name);
	}
E 8

D 8
	errordest = settotouch(name);

E 8
	if (errordest != TOSTDOUT)
		touchedfiles[ix] = TRUE;

	if (previewed && (errordest == TOSTDOUT))
		return;

	diverterrors(name, errordest, files, ix, previewed, nerrors);

D 4
	if (errordest == TOTHEFILE)
		writetouched();
E 4
I 4
	if (errordest == TOTHEFILE){
		/*
		 *	overwrite the original file
		 */
		writetouched(1);
	}
E 4
}

boolean preview(name, nerrors, files, ix)
	char	*name;
	int	nerrors;
	Eptr	**files;
	int	ix;
{
	int	back;
	reg	Eptr	*erpp;

D 8
	if (!oktotouch(name))
		return(false);
E 8
	if (nerrors <= 0)
D 8
		return(false);
	back = false;
E 8
I 8
		return(FALSE);
	back = FALSE;
E 8
	if(query){
		switch(inquire(terse
		    ? "Preview? "
		    : "Do you want to preview the errors first? ")){
		case Q_YES:
		case Q_yes:
D 8
			back = true;
E 8
I 8
			back = TRUE;
E 8
			EITERATE(erpp, files, ix){
				errorprint(stdout, *erpp, TRUE);
			}
			if (!terse)
				fprintf(stdout, "\n");
		default:
			break;
		}
	}
	return(back);
}

int settotouch(name)
	char	*name;
{
	int	dest = TOSTDOUT;

	if (query){
		switch(touchstatus = inquire(terse
			? "Touch? "
			: "Do you want to touch file \"%s\"? ",
			name)){
		case Q_NO:
		case Q_no:
			return(dest);
		default:
			break;
		}
	}

	switch(probethisfile(name)){
	case F_NOTREAD:
		dest = TOSTDOUT;
		fprintf(stdout, terse
			? "\"%s\" unreadable\n"
			: "File \"%s\" is unreadable\n",
			name);
		break;
	case F_NOTWRITE:
		dest = TOSTDOUT;
		fprintf(stdout, terse
			? "\"%s\" unwritable\n"
			: "File \"%s\" is unwritable\n",
			name);
		break;
	case F_NOTEXIST:
		dest = TOSTDOUT;
		fprintf(stdout, terse
			? "\"%s\" not found\n"
			: "Can't find file \"%s\" to insert error messages into.\n",
			name);
		break;
	default:
		dest = edit(name) ? TOSTDOUT : TOTHEFILE;
		break;
	}
	return(dest);
}

diverterrors(name, dest, files, ix, previewed, nterrors)
	char	*name;
	int	dest;
	Eptr	**files;
	int	ix;
	boolean	previewed;
	int	nterrors;
{
	int	nerrors;
	reg	Eptr	*erpp;
	reg	Eptr	errorp;

	nerrors = files[ix+1] - files[ix];

	if (   (nerrors != nterrors)
	    && (!previewed) ){
		fprintf(stdout, terse
			? "Uninserted errors\n"
			: ">>Uninserted errors for file \"%s\" follow.\n",
			name);
	}

	EITERATE(erpp, files, ix){
		errorp = *erpp;
		if (errorp->error_e_class != C_TRUE){
			if (previewed || touchstatus == Q_NO)
				continue;
			errorprint(stdout, errorp, TRUE);
			continue;
		}
		switch (dest){
		case TOSTDOUT:
			if (previewed || touchstatus == Q_NO)
				continue;
			errorprint(stdout,errorp, TRUE);
			break;
		case TOTHEFILE:
			insert(errorp->error_line);
			text(errorp, FALSE);
			break;
		}
	}
}

int oktotouch(filename)
E 3
	char	*filename;
{
	extern		char	*suffixlist;
D 3
	register	char	*src;
	register	char	*pat;
E 3
I 3
	reg	char	*src;
	reg	char	*pat;
E 3
			char	*osrc;

	pat = suffixlist;
	if (pat == 0)
		return(0);
	if (*pat == '*')
		return(1);
	while (*pat++ != '.')
		continue;
	--pat;		/* point to the period */

	for (src = &filename[strlen(filename)], --src;
	     (src > filename) && (*src != '.'); --src)
		continue;
	if (*src != '.')
		return(0);

	for (src++, pat++, osrc = src; *src && *pat; src = osrc, pat++){
		for (;   *src			/* not at end of the source */
		      && *pat			/* not off end of pattern */
		      && *pat != '.'		/* not off end of sub pattern */
		      && *pat != '*'		/* not wild card */
		      && *src == *pat;		/* and equal... */
		      src++, pat++)
			continue;
		if (*src == 0 && (*pat == 0 || *pat == '.' || *pat == '*'))
			return(1);
		if (*src != 0 && *pat == '*')
			return(1);
		while (*pat && *pat != '.')
			pat++;
		if (! *pat)
			return(0);
	}
	return(0);
}
I 3
/*
 *	Construct an execv argument
 *	We need 1 argument for the editor's name
 *	We need 1 argument for the initial search string
 *	We need n_pissed_on arguments for the file names
 *	We need 1 argument that is a null for execv.
 *	The caller fills in the editor's name.
 *	We fill in the initial search string.
 *	We fill in the arguments, and the null.
 */
execvarg(n_pissed_on, r_argc, r_argv)
	int	n_pissed_on;
	int	*r_argc;
	char	***r_argv;
{
	Eptr	p;
	char	*sep;
	int	fi;
E 3

I 3
	(*r_argv) = (char **)Calloc(n_pissed_on + 3, sizeof(char *));
	(*r_argc) =  n_pissed_on + 2;
	(*r_argv)[1] = "+1;/###/";
	n_pissed_on = 2;
	if (!terse){
		fprintf(stdout, "You touched file(s):");
		sep = " ";
	}
	FILEITERATE(fi, 1){
		if (!touchedfiles[fi])
			continue;
		p = *(files[fi]);
		if (!terse){
			fprintf(stdout,"%s\"%s\"", sep, p->error_text[0]);
			sep = ", ";
		}
		(*r_argv)[n_pissed_on++] = p->error_text[0];
	}
	if (!terse)
		fprintf(stdout, "\n");
	(*r_argv)[n_pissed_on] = 0;
}

E 3
FILE	*o_touchedfile;	/* the old file */
FILE	*n_touchedfile;	/* the new file */
char	*o_name;
D 4
char	n_name[32];
char	*canon_name = "ErrorXXXXXX";
E 4
I 4
char	n_name[64];
char	*canon_name = "/tmp/ErrorXXXXXX";
E 4
int	o_lineno;
int	n_lineno;
boolean	tempfileopen = FALSE;
/*
 *	open the file; guaranteed to be both readable and writable
 *	Well, if it isn't, then return TRUE if something failed
 */
boolean edit(name)
	char	*name;
{
	o_name = name;
	if ( (o_touchedfile = fopen(name, "r")) == NULL){
		fprintf(stderr, "%s: Can't open file \"%s\" to touch (read).\n",
			processname, name);
		return(TRUE);
	}
D 3
	strcpy(n_name, canon_name);
	mktemp(n_name);
E 3
I 3
	(void)strcpy(n_name, canon_name);
	(void)mktemp(n_name);
E 3
	if ( (n_touchedfile = fopen(n_name, "w")) == NULL){
		fprintf(stderr,"%s: Can't open file \"%s\" to touch (write).\n",
			processname, name);
		return(TRUE);
	}
	tempfileopen = TRUE;
	n_lineno = 0;
	o_lineno = 0;
	return(FALSE);
}
/*
 *	Position to the line (before, after) the line given by place
 */
D 3
char	edbuffer[BUFSIZ];
E 3
I 3
char	edbuf[BUFSIZ];
E 3
insert(place)
	int	place;
{
	--place;	/* always insert messages before the offending line*/
	for(; o_lineno < place; o_lineno++, n_lineno++){
D 3
		if(fgets(edbuffer, BUFSIZ, o_touchedfile) == NULL)
E 3
I 3
		if(fgets(edbuf, BUFSIZ, o_touchedfile) == NULL)
E 3
			return;
D 3
		fputs(edbuffer, n_touchedfile);
E 3
I 3
		fputs(edbuf, n_touchedfile);
E 3
	}
}

D 3
text(errorp, use_all)
	register	struct	error_desc	*errorp;
	boolean	use_all;
E 3
I 3
text(p, use_all)
	reg	Eptr	p;
		boolean	use_all;
E 3
{
	int	offset = use_all ? 0 : 2;
D 3
	fputs(lang_table[errorp->error_language].lang_incomment, n_touchedfile);
E 3
I 3

	fputs(lang_table[p->error_language].lang_incomment, n_touchedfile);
E 3
	fprintf(n_touchedfile, "%d [%s] ",
D 3
		errorp->error_line,
		lang_table[errorp->error_language].lang_name);
	wordvprint(n_touchedfile,
		errorp->error_lgtext-offset, errorp->error_text+offset);
	fputs(lang_table[errorp->error_language].lang_outcomment,n_touchedfile);
E 3
I 3
		p->error_line,
		lang_table[p->error_language].lang_name);
	wordvprint(n_touchedfile, p->error_lgtext-offset, p->error_text+offset);
	fputs(lang_table[p->error_language].lang_outcomment,n_touchedfile);
E 3
	n_lineno++;
}

D 4
writetouched()
E 4
I 4
/*
 *	write the touched file to its temporary copy,
 *	then bring the temporary in over the local file
 */
writetouched(overwrite)
	int	overwrite;
E 4
{
D 3
	int	bytes_read;
	for(; (bytes_read = fread(edbuffer, 1, sizeof(edbuffer), o_touchedfile))!= NULL; ){
		fwrite(edbuffer, 1, bytes_read, n_touchedfile);
E 3
I 3
D 4
	int	nread;
E 4
I 4
	reg	int	nread;
	reg	FILE	*localfile;
	reg	FILE	*tmpfile;
		int	botch;
I 6
		int	oktorm;
E 6
E 4

I 6
	botch = 0;
	oktorm = 1;
E 6
	while((nread = fread(edbuf, 1, sizeof(edbuf), o_touchedfile)) != NULL){
D 6
		fwrite(edbuf, 1, nread, n_touchedfile);
E 6
I 6
		if (nread != fwrite(edbuf, 1, nread, n_touchedfile)){
			/*
			 *	Catastrophe in temporary area: file system full?
			 */
			botch = 1;
			fprintf(stderr,
			  "%s: write failure: No errors inserted in \"%s\"\n",
			  processname, o_name);
		}
E 6
E 3
	}
	fclose(n_touchedfile);
	fclose(o_touchedfile);
D 4
	unlink(o_name);
D 3
	link(n_name, o_name);	
E 3
I 3
	link(n_name, o_name);
E 4
I 4
	/*
	 *	Now, copy the temp file back over the original
	 *	file, thus preserving links, etc
	 */
D 6
	if (overwrite){
E 6
I 6
	if (botch == 0 && overwrite){
E 6
		botch = 0;
		localfile = NULL;
		tmpfile = NULL;
		if ((localfile = fopen(o_name, "w")) == NULL){
			fprintf(stderr,
				"%s: Can't open file \"%s\" to overwrite.\n",
				processname, o_name);
			botch++;
		}
		if ((tmpfile = fopen(n_name, "r")) == NULL){
			fprintf(stderr, "%s: Can't open file \"%s\" to read.\n",
				processname, n_name);
			botch++;
		}
D 6
		if (!botch){
			while((nread=fread(edbuf, 1, sizeof(edbuf), tmpfile))
					!= NULL){
				fwrite(edbuf, 1, nread, localfile);
			}
		}
E 6
I 6
		if (!botch)
			oktorm = mustoverwrite(localfile, tmpfile);
E 6
		if (localfile != NULL)
			fclose(localfile);
		if (tmpfile != NULL)
			fclose(tmpfile);
	}
I 6
	if (oktorm == 0){
		fprintf(stderr, "%s: Catastrophe: A copy of \"%s\: was saved in \"%s\"\n",
			processname, o_name, n_name);
		exit(1);
	}
E 6
	/*
	 *	Kiss the temp file good bye
	 */
E 4
E 3
	unlink(n_name);
	tempfileopen = FALSE;
I 4
	return(TRUE);
I 6
}
/*
 *	return 1 if the tmpfile can be removed after writing it out
 */
int mustoverwrite(preciousfile, tmpfile)
	FILE	*preciousfile;
	FILE	*tmpfile;
{
	int	nread;

	while((nread = fread(edbuf, 1, sizeof(edbuf), tmpfile)) != NULL){
		if (mustwrite(edbuf, nread, preciousfile) == 0)
			return(0);
	}
	return(1);
}
/*
 *	return 0 on catastrophe
 */
mustwrite(base, n, preciousfile)
	char	*base;
	int	n;
	FILE	*preciousfile;
{
	int	nwrote;

	if (n <= 0)
		return(1);
	nwrote = fwrite(base, 1, n, preciousfile);
	if (nwrote == n)
		return(1);
	perror(processname);
	switch(inquire(terse
	    ? "Botch overwriting: retry? "
	    : "Botch overwriting the source file: retry? ")){
	case Q_YES:
	case Q_yes:
		mustwrite(base + nwrote, n - nwrote, preciousfile);
		return(1);
	case Q_NO:
	case Q_no:
		switch(inquire("Are you sure? ")){
		case Q_YES:
		case Q_yes:
			return(0);
		case Q_NO:
		case Q_no:
			mustwrite(base + nwrote, n - nwrote, preciousfile);
			return(1);
		}
I 7
	default:
		return(0);
E 7
	}
E 6
E 4
}
I 3

E 3
onintr()
{
D 3
	if (inquire("\nInterrupt: Do you want to continue?")){
E 3
I 3
	switch(inquire(terse
	    ? "\nContinue? "
	    : "\nInterrupt: Do you want to continue? ")){
	case Q_YES:
	case Q_yes:
E 3
		signal(SIGINT, onintr);
		return;
I 3
	default:
D 4
		if (tempfileopen)
			writetouched();
E 4
I 4
		if (tempfileopen){
			/*
			 *	Don't overwrite the original file!
			 */
			writetouched(0);
		}
E 4
		exit(1);
E 3
	}
D 3
	if (tempfileopen)
		writetouched();
	exit(1);
E 3
I 3
	/*NOTREACHED*/
E 3
}
I 3

E 3
errorprint(place, errorp, print_all)
	FILE	*place;
D 3
	struct	error_desc	*errorp;
E 3
I 3
	Eptr	errorp;
E 3
	boolean	print_all;
{
	int	offset = print_all ? 0 : 2;

	if (errorp->error_e_class == C_IGNORE)
		return;
	fprintf(place, "[%s] ", lang_table[errorp->error_language].lang_name);
	wordvprint(place,errorp->error_lgtext-offset,errorp->error_text+offset);
	putc('\n', place);
}

D 3
boolean inquire(fmt, a1, a2)
E 3
I 3
int inquire(fmt, a1, a2)
E 3
	char	*fmt;
	/*VARARGS1*/
{
	char	buffer[128];
I 7

	if (queryfile == NULL)
		return(0);
E 7
D 3
	char	ch;
E 3
	for(;;){
		do{
			fflush(stdout);
			fprintf(stderr, fmt, a1, a2);
			fflush(stderr);
		} while (fgets(buffer, 127, queryfile) == NULL);
D 3
		ch = buffer[0];
		if (ch == 'Y' || ch == 'y')
			return(TRUE);
		if (ch == 'N' || ch == 'n')
			return(FALSE);
		fprintf(stderr, "Yes or No only!\n");
E 3
I 3
		switch(buffer[0]){
		case 'Y':	return(Q_YES);
		case 'y':	return(Q_yes);
		case 'N':	return(Q_NO);
		case 'n':	return(Q_no);
		default:	fprintf(stderr, "Yes or No only!\n");
		}
E 3
	}
}

D 3
boolean probethisfile(currentfilename)
	char	*currentfilename;
E 3
I 3
int probethisfile(name)
	char	*name;
E 3
{
	struct stat statbuf;
D 3
	if (stat(currentfilename, &statbuf) != 0)
		return(FALSE);
	if ( (statbuf.st_mode&S_IREAD) && (statbuf.st_mode&S_IWRITE))
		return(TRUE);
	return(FALSE);
E 3
I 3
	if (stat(name, &statbuf) < 0)
		return(F_NOTEXIST);
	if((statbuf.st_mode & S_IREAD) == 0)
		return(F_NOTREAD);
	if((statbuf.st_mode & S_IWRITE) == 0)
		return(F_NOTWRITE);
	return(F_TOUCHIT);
E 3
}
E 1
