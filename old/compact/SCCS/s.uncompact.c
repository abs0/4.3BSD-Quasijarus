h61293
s 00001/00001/00227
d D 4.8 87/12/21 12:23:19 bostic 8 7
c make ANSI compatible
e
s 00037/00035/00191
d D 4.7 84/08/25 23:48:45 sam 7 6
c speed up balanced tree insertion
e
s 00192/00141/00034
d D 4.6 84/08/25 22:05:03 sam 6 5
c rewrite and speed up 
e
s 00002/00000/00173
d D 4.5 84/08/15 11:34:08 ralph 5 4
c fflush before checking ferror in case of filesys full.
e
s 00004/00001/00169
d D 4.4 83/08/11 22:28:55 sam 4 3
c standardize sccs keyword lines
e
s 00001/00001/00169
d D 4.3 83/06/03 15:35:39 edward 3 2
c use MAXNAMLEN and MAXPATHLEN
e
s 00001/00001/00169
d D 4.2 83/05/04 16:39:27 sklower 2 1
c expand limits for 4.1c file system
e
s 00170/00000/00000
d D 4.1 83/02/11 14:56:58 shannon 1 0
c date and time created 83/02/11 14:56:58 by shannon
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

E 4
/*
 *  Uncompact adaptive Huffman code input to output
 *
 *  On - line algorithm
 *
 *  Input file does not contain decoding tree
 *
 *  Written by Colin L. Mc Master (UCB) February 14, 1979
 */
D 6

E 6
#include "compact.h"
I 6
#include <strings.h>
E 6

I 6
union	cio c;
union	cio d;
char	*infname;			/* input file's name */
char	fname[MAXPATHLEN+1];		/* output file's name */
struct	stat status;			/* compacted file status */
E 6

D 6
main (argc, argv)
short argc;
char *argv [ ];
E 6
I 6
int	verbose = 0;

main(argc, argv)
	int argc;
	char *argv[];
E 6
{
D 6
	register short i;
	register struct node *p;
E 6
	register short j;
D 6
	register int m;
	union cio c, d;
	char b;
	longint ic, n;
	char fname [LNAME], *cp;
E 6

D 6
	dir [513] . next = NULL;
E 6
I 6
	argc--, argv++;
	if (argc > 0 && strcmp(*argv, "-v") == 0) {
		verbose++;
		argc--, argv++;
	}
	dir[513].next = NULL;
E 6
	for (head = dir + (j = 513); j--; ) {
		dirp = head--;
D 6
		head -> next = dirp;
E 6
I 6
		head->next = dirp;
E 6
	}
D 6
	bottom = dirp -> pt = dict;
	dict [0] . top [0] = dict [0] . top [1] = dirp;
	dirq = dirp -> next;
	in [EF] . flags = FBIT | SEEN;
E 6
I 6
	bottom = dirp->pt = dict;
D 7
	dict[0].top[LEFT] = dict[0].top[RIGHT] = dirp;
E 7
I 7
	dict[0].sons[LEFT].top = dict[0].sons[RIGHT].top = dirp;
E 7
	dirq = dirp->next;
	in[EF].flags = FBIT | SEEN;
	if (argc == 0)
		exit(uncompact("-"));
	for (j = 0; j < argc; j++) {
		if (uncompact(argv[j]))
			exit(1);
		if (verbose && argc > 0)
			printf("%s uncompacted to %s\n", argv[j], fname);
	}
	exit(0);
}
E 6

D 6
	for (i = 1; ; i++) {
		ic = oc = 0;
		(bottom -> top [1]) -> next = flist;
		bottom -> top [1] = dirp;
		flist = dirq;
		if (i >= argc) {
			uncfp = stdout;
			cfp = stdin;
E 6
I 6
uncompact(file)
	char *file;
{
	int ignore;
	FILE *setup();

D 7
	bottom->top[1]->next = flist;
	bottom->top[1] = dirp;
E 7
I 7
	bottom->sons[RIGHT].top->next = flist;
	bottom->sons[RIGHT].top = dirp;
E 7
	flist = dirq;
I 7
	uncfp = cfp = NULL;
E 7
	if (strcmp(file, "-") != 0) {
		char *cp;

		strcpy(fname, file);
		cp = rindex(fname, '.');
		if (cp == 0 || strcmp(cp, ".C") != 0) {
			fprintf(stderr,
			    "uncompact: %s: File must have .C suffix.\n", file);
D 7
			return;
E 7
I 7
			goto bad;
E 7
E 6
		}
D 6
		else {
			m = -1;
			cp = fname;
			for (j = 0; j < (LNAME - 3) && (*cp = argv [i][j]); j++)
				if (*cp++ == '/') m = j;
			if (cp [-1] == 'C' && cp [-2] == '.') cp [-2] = 0;
			else {
				fprintf (stderr, "%s: File name must end with \".C\"\n", argv [i]);
				if (i == argc - 1) break;
				continue;
			}
D 2
			if (j >= (LNAME - 3) || (j - m) > 15) {
E 2
I 2
D 3
			if (j >= (LNAME - 3) || (j - m) > 256) {
E 3
I 3
			if (j >= (LNAME - 3) || (j - m) > MAXNAMLEN) {
E 3
E 2
				fprintf (stderr, "File name too long -- %s\n", argv [i]);
				if (i == argc - 1) break;
				continue;
			}
			if ((cfp = fopen (argv [i], "r")) == NULL) {
				perror (argv [i]);
				if (i == argc - 1) break;
				continue;
			}
			if ((uncfp = fopen (fname, "w")) == NULL) {
				perror (fname);
				fclose (cfp);
				if (i == argc - 1) break;
				continue;
			}
			fstat (fileno (cfp), &status);
			chmod (fname, status.st_mode & 07777);
E 6
I 6
		*cp = '\0';
		cfp = fopen(file, "r");
		if (cfp == NULL) {
			fprintf(stderr, "uncompact: "), perror(file);
D 7
			return;
E 7
I 7
			goto bad;
E 7
E 6
		}
I 6
		(void) fstat(fileno(cfp), &status);
	} else
		cfp = stdin;
	infname = file;
	uncfp = setup(cfp, &ignore);
	if (uncfp == NULL) {
		if (ignore)
			goto done;
		goto bad;
	}
	decompress(cfp, uncfp);
	fflush(uncfp);
	if (ferror(uncfp) || ferror(cfp)) {
I 7
		fprintf(stderr, "uncompact: ");
E 7
		if (uncfp != stdout) {
			if (ferror(uncfp))
				perror(fname);
			else
				perror(infname);
			(void) unlink(fname);
D 7
		}
E 7
I 7
		} else
			fprintf(stderr,
	    "Unsuccessful uncompact of standard input to standard output.\n");
E 7
		goto bad;
	}
	if (uncfp != stdout && unlink(infname) < 0)
		fprintf(stderr, "uncompact: "), perror(infname);
done:
	if (uncfp != NULL && uncfp != stdout)
		fclose(uncfp);
	if (cfp != NULL)
		fclose(cfp);
	return (0);
bad:
D 7
	fprintf(stderr, "uncompact: ");
	if (strcmp(infname, "-") != 0)
		perror(infname);
	else
		fprintf(stderr,
	    "Unsuccessful uncompact of standard input to standard output.\n");
E 7
I 7
	if (cfp != NULL)
		fclose(cfp);
E 7
	return (1);
}
E 6

D 6
		if ((c . integ = getc (cfp)) != EOF) {
			if ((d . integ = getc (cfp)) != EOF) {
				c . chars . hib = d . integ & 0377;
				c . integ &= 0177777;
				if (c . integ != COMPACTED) goto notcompact;
				if ((c . integ = getc (cfp)) != EOF) {
					putc (c . chars . lob, uncfp);
					ic = 3;
		
					in [NC] . fp = in [EF] . fp = dict [0] . sp [0] . p = bottom = dict + 1;
					bottom -> count [0] = bottom -> count [1] = dict [0] . count [1] = 1;
					dirp -> next = dict [0] . top [1] = bottom -> top [0] = bottom -> top [1] = dirq = NEW;
					dirq -> next = NULL;
					dict [0] . fath . fp = NULL;
					dirq -> pt = bottom -> fath . fp = in [c . integ] . fp = dict;
					in [c . integ] . flags = (FBIT | SEEN);
					in [NC] . flags = SEEN;
					dict [0] . fath . flags = RLEAF;
					bottom -> fath . flags = (LLEAF | RLEAF);
					dict [0] . count [0] = 2;
		
					dict [0] . sp [1] . ch = c . integ;
					bottom -> sp [0] . ch = NC;
					bottom -> sp [1] . ch = EF;
		
					p = dict;
					while ((c . integ = getc (cfp)) != EOF) {
						ic++;
						for (m = 0200; m; ) {
							b = (m & c . integ ? 1 : 0);
							m >>= 1;
							if (p -> fath . flags & (b ? RLEAF : LLEAF)) {
								d . integ = p -> sp [b] . ch;
								if (d . integ == EF) break;
								if (d . integ == NC) {
									uptree (NC);
									d . integ = 0;
									for (j = 8; j--; m >>= 1) {
										if (m == 0) {
											c . integ = getc (cfp);
											ic++;
											m = 0200;
										}
										d . integ <<= 1;
										if (m & c . integ) d . integ++;
									}
									insert (d . integ);
								}
								uptree (d . integ);
								putc (d . chars . lob, uncfp);
								oc++;
								p = dict;
							}
							else p = p -> sp [b] . p;
E 6
I 6
decompress(cfp, uncfp)
	register FILE *cfp, *uncfp;
{
	register struct node *p;
	register short j;
	register int m;
D 8
	register struct cio *dp = &d;
E 8
I 8
	register union cio *dp = &d;
E 8
	char b;

	p = dict;
	while ((c.integ = getc (cfp)) != EOF) {
		for (m = 0200; m; ) {
			b = (m & c.integ ? 1 : 0);
			m >>= 1;
			if (p->fath.flags & (b ? RLEAF : LLEAF)) {
D 7
				dp->integ = p->sp[b].ch;
E 7
I 7
				dp->integ = p->sons[b].sp.ch;
E 7
				if (dp->integ == EF)
					break;
				if (dp->integ == NC) {
					uptree(NC);
					dp->integ = 0;
					for (j = 8; j--; m >>= 1) {
						if (m == 0) {
							c.integ = getc(cfp);
							m = 0200;
E 6
						}
I 6
						dp->integ <<= 1;
						if (m & c.integ)
							dp->integ++;
E 6
					}
I 6
					insert(dp->integ);
E 6
				}
D 6
			}
			else goto notcompact;
E 6
I 6
				uptree(dp->integ);
				putc(dp->chars.lob, uncfp);
				p = dict;
			} else
D 7
				p = p->sp[b].p;
E 7
I 7
				p = p->sons[b].sp.p;
E 7
E 6
		}
D 6
		else {
			notcompact : if (i < argc) {
					     fprintf (stderr, "%s: ", argv [i]);
					     unlink (fname);
				     }
				     if (c . integ == PACKED) fprintf (stderr, "File is packed. Use unpack.\n");
				     else fprintf (stderr, "Not a compacted file.\n");
				     if (i >= argc) break;
				     goto closeboth;
E 6
I 6
	}
}

FILE *
setup(cfp, ignore)
	FILE *cfp;
	int *ignore;
{
	FILE *uncfp = NULL;
	register union cio *dp = &d;
	register union cio *cp = &c;

I 7
	*ignore = 0;
E 7
	dp->integ = getc(cfp);
D 7
	if (*ignore = (dp->integ == EOF))
		goto bad;
	cp->integ = getc(cfp);
	if (*ignore = (cp->integ == EOF))
		goto bad;
	dp->chars.hib = cp->integ & 0377;
E 7
I 7
	if (dp->integ != EOF) {	
		cp->integ = getc(cfp);
		if (cp->integ != EOF)
			dp->chars.hib = cp->integ & 0377;
	} else
		dp->integ = 0;
E 7
	if ((dp->integ &= 0177777) != COMPACTED) {
I 7
		fprintf(stderr, "uncompact: ");
E 7
		if (dp->integ == PACKED)
			fprintf(stderr, "%s: File is packed, use unpack.\n",
			    infname);
		else
			fprintf(stderr, "%s: Not a compacted file.\n", infname);
		*ignore = 1;
		goto bad;
	}
	if (strcmp(infname, "-") != 0) {
		uncfp = fopen(fname, "w");
D 7
		if (uncfp == NULL) {
			perror(fname);
			goto bad;
E 6
		}
E 7
I 7
		if (uncfp == NULL)
			goto bad2;
E 7
I 6
		(void) fchmod(fileno(uncfp), status.st_mode);
	} else
		uncfp = stdout;
	cp->integ = getc(cfp);
	if (cp->integ == EOF)
D 7
		goto bad;
E 7
I 7
		goto bad2;
E 7
	putc(cp->chars.lob, uncfp);
E 6

I 5
D 6
		fflush (uncfp);
E 5
		if (ferror (uncfp) || ferror (cfp))
			if (i < argc) {
				if (ferror (uncfp))
					perror (fname);
				else
					perror (argv [i]);
				fprintf (stderr, "Unable to uncompact %s\n", argv [i]);
				unlink (fname);
				goto closeboth;
			}
			    if (i >= argc) break;
			    fprintf (stderr, "%s uncompacted to %s\n", argv [i], fname);
			    unlink (argv [i]);
		closeboth : fclose (cfp);
		closein   : fclose (uncfp);
			    if (i == argc - 1) break;
			    for (j = 256; j--; ) in [j] . flags = 0;
			    continue;
		fail 	  : fprintf (stderr, "Unsuccessful uncompact of standard input to standard output.\n");
		            break;
E 6
I 6
D 7
	in[NC].fp = in[EF].fp = dict[0].sp[LEFT].p = bottom = dict + 1;
	bottom->count[LEFT] = bottom->count[RIGHT] =
	    dict[0].count[RIGHT] = 1;
	dirp->next = dict[0].top[RIGHT] = bottom->top[LEFT] =
	    bottom->top[RIGHT] = dirq = NEW;
E 7
I 7
	in[NC].fp = in[EF].fp = dict[0].sons[LEFT].sp.p = bottom = dict + 1;
	bottom->sons[LEFT].count = bottom->sons[RIGHT].count =
	    dict[0].sons[RIGHT].count = 1;
	dirp->next = dict[0].sons[RIGHT].top = bottom->sons[LEFT].top =
	    bottom->sons[RIGHT].top = dirq = NEW;
E 7
	dirq->next = NULL;
	dict[0].fath.fp = NULL;
	dirq->pt = bottom->fath.fp = in[cp->integ].fp = dict;
	in[cp->integ].flags = (FBIT | SEEN);
	in[NC].flags = SEEN;
	dict[0].fath.flags = RLEAF;
	bottom->fath.flags = (LLEAF | RLEAF);
D 7
	dict[0].count[LEFT] = 2;
E 7
I 7
	dict[0].sons[LEFT].count = 2;
E 7

D 7
	dict[0].sp[RIGHT].ch = cp->integ;
	bottom->sp[LEFT].ch = NC;
	bottom->sp[RIGHT].ch = EF;
E 7
I 7
	dict[0].sons[RIGHT].sp.ch = cp->integ;
	bottom->sons[LEFT].sp.ch = NC;
	bottom->sons[RIGHT].sp.ch = EF;
E 7
	return (uncfp);
I 7
bad2:
	fprintf(stderr, "uncompact: ");
	perror(fname);
E 7
bad:
	if (uncfp && uncfp != stdout) {
D 7
		perror(fname);
E 7
		(void) unlink(fname);
		fclose(uncfp);
E 6
	}
I 5
D 6
	return (0);
E 6
I 6
	return (NULL);
E 6
E 5
}
E 1
