h61578
s 00033/00027/00306
d D 4.7 84/08/25 23:48:29 sam 7 6
c speed up balanced tree insertion
e
s 00282/00222/00051
d D 4.6 84/08/25 22:04:47 sam 6 5
c rewrite and speed up 
e
s 00021/00021/00252
d D 4.5 84/08/15 11:34:03 ralph 5 4
c fflush before checking ferror in case of filesys full.
e
s 00004/00001/00269
d D 4.4 83/08/11 22:28:45 sam 4 3
c standardize sccs keyword lines
e
s 00001/00001/00269
d D 4.3 83/06/03 15:35:31 edward 3 2
c use MAXNAMLEN and MAXPATHLEN
e
s 00001/00001/00269
d D 4.2 83/05/04 16:39:15 sklower 2 1
c expand limits for 4.1c file system
e
s 00270/00000/00000
d D 4.1 83/02/11 14:56:50 shannon 1 0
c date and time created 83/02/11 14:56:50 by shannon
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
 *  Adaptive Huffman code input to output
 *
 *  On - line algorithm
 *
 *  Does not prepend decoding tree
 *
 *  Written by Colin L. Mc Master (UCB) February 28, 1979
 */
D 6


E 6
I 6
#include <strings.h>
E 6
#include "compact.h"

D 6
union cio d;
int bits;
E 6
I 6
union	cio d;
union	cio c;
int	bits;
char	*infname;			/* input file's name */
char	fname[MAXPATHLEN+1];		/* output file's name */
struct	stat ucfstatus;			/* uncompacted file status */
E 6

I 6
int	verbose = 0;
E 6

D 6
main (argc, argv)
short argc;
char *argv [ ];
E 6
I 6
main(argc, argv)
	int argc;
	char *argv[];
E 6
{
D 6
	register short i, j;
	register int m;
	union cio c;
	short l;
	longint ic, n;
	char *cp, fname [LNAME];
E 6
I 6
	register short j;
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
		exit(compact("-"));
	for (j = 0; j < argc; j++) {
		if (verbose && argc > 0)
			printf("%s: ", argv[j]);
		if (compact(argv[j]))
			exit(1);
	}
	exit(0);
}
E 6

D 6
	for (i = 1; ; i++) {
		ic = oc =  0;
		(bottom -> top [1]) -> next = flist;
		bottom -> top [1] = dirp;
		flist = dirq;
		if (i >= argc) {
			uncfp = stdin;
			cfp = stdout;
E 6
I 6
/*
 * Compact a single file ("-" implies stdin).
 */
compact(file)
	char *file;
{
	int j, ignore;
	FILE *setup();

	for (j = 256; j--; )
		in[j].flags = 0;
D 7
	bottom->top[RIGHT]->next = flist;
	bottom->top[RIGHT] = dirp;
E 7
I 7
	bottom->sons[RIGHT].top->next = flist;
	bottom->sons[RIGHT].top = dirp;
E 7
	flist = dirq;
	cfp = uncfp = NULL;
	if (strcmp(file, "-") != 0) {
		char *cp, *tp;

		/* verify .C suffix fits */
		cp = rindex(file, '/');
		if (cp == 0)
			cp = file;
		else
			cp++;
		tp = index(cp, '\0');
		if (tp - cp > MAXNAMLEN || strlen(file) + 2 >= MAXPATHLEN) {
			fprintf(stderr, "%s: File name too long\n", file);
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
			for (l = 0; l < (LNAME - 3) && (*cp = argv [i][l]); l++)
				if (*cp++ == '/') m = l;
D 2
			if (l >= (LNAME - 3) || (l - m) > 13) {
E 2
I 2
D 3
			if (l >= (LNAME - 3) || (l - m) > 254) {
E 3
I 3
			if (l >= (LNAME - 3) || (l - m) > MAXNAMLEN - 1) {
E 3
E 2
				fprintf (stderr, "%s: File name too long\n", argv [i]);
				if (i == argc - 1) break;
				continue;
			}
			if ((uncfp = fopen (argv [i], "r")) == NULL) {
				perror (argv [i]);
				if (i == argc - 1) break;
				continue;
			}
E 6
I 6
		uncfp = fopen(file, "r");
		if (uncfp == NULL) {
			fprintf(stderr, "compact: "), perror(file);
D 7
			return;
E 7
I 7
			goto bad;
E 7
E 6
		}
I 6
		fstat(fileno(uncfp), &ucfstatus);
		if ((ucfstatus.st_mode & S_IFMT) != S_IFREG) {
			fprintf(stderr, "%s: Not a regular file.\n", file);
D 7
			goto done;
E 7
I 7
			goto bad;
E 7
		}
	} else
		uncfp = stdin;
	infname = file;
E 6

D 6
		fstat (fileno (uncfp), &status);
		if ((status.st_mode & 040000) == 040000) {
			fprintf (stderr, "%s: Can't compact a directory\n", argv [i]);
			if (i < argc) goto closein;
			break;
E 6
I 6
	cfp = setup(uncfp, &ignore);
	if (cfp == NULL) {
		if (ignore)
			goto done;
		goto bad;
	}
	if (compress(uncfp, cfp)) {
		if (cfp != stdout)
			(void) unlink(fname);
D 7
		goto bad;
E 7
I 7
		goto bad2;
E 7
	}
	encode(EF);
	if (bits) {
		d.integ <<= 16 - bits;
		putc(d.chars.hib, cfp);
		if (bits > 8)
			putc(d.chars.lob, cfp);
		bits = 0;
	}
	fflush(cfp);
	if (ferror(uncfp) || ferror(cfp)) {
		if (cfp != stdout) {
I 7
			fprintf(stderr, "compact: ");
E 7
			if (ferror(cfp))
				perror(fname);
			else
				perror(infname);
			(void) unlink(fname);
E 6
		}
I 6
		goto bad;
	}
	if (cfp != stdout) {
		struct stat cfstatus;
		longint csize, ucsize;
E 6

D 6
		if ((d . integ = getc (uncfp)) != EOF) {
			ic++;
			if ((c . integ = getc (uncfp)) != EOF) {
				d . chars . hib = c . integ & 0377;
				if ((d . integ &= 0177777) == COMPACTED) {
					fprintf (stderr, "%s: Already compacted.\n", argv [i]);
					if (i < argc) goto closein;
					break;
				}
				if (d . integ == PACKED) {
					fprintf (stderr, "%s: Already packed using program pack.  Use unpack.\n", argv [i]);
					if (i < argc) goto closein;
					break;
				}
				if (i < argc) {
					*cp++ = '.'; *cp++ = 'C'; *cp = '\0';
					if ((cfp = fopen (fname, "w")) == NULL) {
						perror (fname);
						goto closein;
					}
					chmod (fname, status.st_mode);
				}
				c . integ = COMPACTED;
				putc (c . chars . lob, cfp);
				putc (c . chars . hib, cfp);
				if (ferror (cfp))
					if (i < argc) {
						perror (fname);
						unlink (fname);
						goto closeboth;
					}
					else goto fail;
				bits = 8;
				oc = 2;
				c . integ = d . integ & 0377;
	
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
	
				for (c . integ = ((d . integ >> 8) & 0377); c . integ != EOF; c . integ = getc (uncfp)) {
					ic++;
					if (in [c . integ] . flags & SEEN) encode (c . integ);
					else {
						encode (NC);
						uptree (NC);
						insert (c . integ);
	
						m = 0200;
						for (j = 8; j--; m >>= 1) {
							d . integ <<= 1;
							if (m & c . integ) d . integ++;
							++bits;
							if ((bits &= 017) == 0) {
								putc (d . chars . hib, cfp);
								putc (d . chars . lob, cfp);
								oc += 2;
							}
						}
					}
					if (ferror (cfp))
						if (i < argc) {
							perror (fname);
							unlink (fname);
							goto closeboth;
						}
						else goto fail;
					uptree (c . integ);
	
				}

				if (ferror (uncfp))
					if (i < argc) {
						perror (argv [i]);
						unlink (fname);
						goto closeboth;
					}
					else goto fail;
	
				encode (EF);
	
				if (bits) {
					d . integ <<= (16 - bits);
					oc++;
					putc (d . chars . hib, cfp);
					if (bits > 8) {
						oc++;
						putc (d . chars . lob, cfp);
					}
					bits = 0;
				}
			}
			else oc = ic;
E 6
I 6
		(void) fstat(fileno(cfp), &cfstatus);
		csize = cfstatus.st_size;
		ucsize = ucfstatus.st_size;
		if (csize >= ucsize) {
			fprintf("%s: ", infname);
			(void) unlink(fname);
			printf("Not compacted, does not save bytes.\n");
			goto done;
E 6
		}
I 6
		if (verbose) {
			FILE *fd;
			longint n, m;
E 6

I 5
D 6
		fflush (cfp);
E 5
		if (ferror (uncfp) || ferror (cfp))
			if (i < argc) {
				if (ferror (cfp))
					perror (fname);
				else
					perror (argv [i]);
D 5
				if (oc > 1) {
					unlink (fname);
					goto closeboth;
				}
				goto closein;
E 5
I 5
				unlink (fname);
				goto closeboth;
E 6
I 6
			while (ucsize - csize > 21474) {
				ucsize /= 10;
				csize /= 10;
E 6
E 5
			}
D 6
			else goto fail;
		else {
			if (oc >= ic) {
D 5
				if (i < argc) fprintf (stderr, "%s: ", argv [i]);
				if (i < argc) fprintf (stderr, "Not compacted.  ");
E 5
I 5
				if (i < argc)
					fprintf (stderr, "%s: Not compacted.  ",
						argv [i]);
E 5
				fprintf (stderr, "Does not save bytes.\n");
				if (i < argc) {
D 5
					if (oc > 1) {
						unlink (fname);
						goto closeboth;
					}
					goto closein;
E 5
I 5
					unlink (fname);
					goto closeboth;
E 5
				}
				else break;
			}
			while ((ic - oc) > 21474) {
				ic /= 10;
				oc /= 10;
			}
			n = 100000 * (ic - oc) / ic + 5;
E 6
I 6
			n = 100000 * (ucsize - csize) / ucsize + 5;
E 6
			m = (n % 1000) / 10;
			bits = m % 10 + '0';
D 6
			c . integ = m / 10 + '0';
			if (i < argc) fprintf (stderr, "%s:  ", argv [i]);
			fprintf (stderr, "Compression : %4ld.%c%c%%\n", n / 1000, c . chars . lob, bits);
E 6
I 6
			c.integ = m / 10 + '0';
			printf("%ld.%c%c%% compression\n",
			    n / 1000, c.chars.lob, bits);
E 6
		}
D 6

D 5
			    if (i >= argc) break;
			    unlink (argv [i]);
		closeboth : fclose (cfp);
		closein   : fclose (uncfp);
			    if (i == argc - 1) break;
			    for (j = 256; j--; ) in [j] . flags = 0;
			    continue;
		fail 	  : fprintf (stderr, "Unsuccessful compact of standard input to standard output.\n");
		            break;
E 5
I 5
		if (i >= argc) break;
		unlink (argv [i]);
	closeboth:
		fclose (cfp);
	closein:
		fclose (uncfp);
		if (i == argc - 1) break;
		for (j = 256; j--; )
			in [j] . flags = 0;
E 6
I 6
		if (unlink(infname) < 0)
			fprintf(stderr, "compact: "), perror(infname);
E 6
E 5
	}
I 5
D 6
	exit (0);
fail:
	fprintf (stderr, "Unsuccessful compact of standard input to standard output.\n");
	exit (1);
E 6
I 6
done:
	if (cfp != NULL && cfp != stdout)
		fclose(cfp);
	if (uncfp != NULL)
		fclose(uncfp);
	return (0);
D 7
bad:
E 7
I 7
bad2:
E 7
	fprintf(stderr, "compact: ");
D 7
	if (strcmp(infname, "-") != 0)
E 7
I 7
	if (cfp != stdout)
E 7
		perror(infname);
	else
		fprintf(stderr,
	    "Unsuccessful compact of standard input to standard output.\n");
I 7
bad:
	if (cfp != NULL && cfp != stdout)
		fclose(cfp);
	if (uncfp != NULL)
		fclose(uncfp);
E 7
	return (1);
E 6
E 5
}

D 6
encode (ch)
int ch;
E 6
I 6
encode(ch)
	int ch;
E 6
{
D 6

E 6
	register struct node *pp;
D 6
	register char j;
E 6
I 6
	int stack[17];
	register int stbits = 1, *sp = &stack[0], rbits = bits;
	register union cio *dp = &d;
E 6
	union cio c;
D 6
	int stack [17], stp, stbits;
E 6

D 6
	c . integ = ch;
	stack [stp = 0] = in [c . integ] . flags & FBIT;
	stbits = 1;
	pp = in [c . integ] . fp;
E 6
I 6
	c.integ = ch;
	*sp = in[ch].flags & FBIT;
	pp = in[ch].fp;
E 6

D 6
	while (pp -> fath . fp) {
		stack [stp] <<= 1;
		if (pp -> fath . flags & FBIT) stack [stp]++;
E 6
I 6
	while (pp->fath.fp) {
		*sp <<= 1;
		if (pp->fath.flags & FBIT)
			(*sp)++;
E 6
		stbits++;
D 6
		if ((stbits &= 017) == 0) stp++;
		pp = pp ->  fath . fp;
E 6
I 6
		if ((stbits &= 017) == 0)
			sp++;
		pp = pp->fath.fp;
E 6
	}

	/* pop the output stack */
D 6

	for (stp++; stp--; ) {
		for (j = 0; j < stbits; j++) {
			d . integ <<= 1;
			if (stack [stp] & 01) d . integ++;
			++bits;
			if ((bits &= 017) == 0) {
				putc (d . chars . hib, cfp);
				putc (d . chars . lob, cfp);
				if (ferror (cfp)) return;
				oc += 2;
E 6
I 6
	do {
		while (stbits-- > 0) {
			dp->integ <<= 1;
			if (*sp & 01)
				dp->integ++;
			++rbits;
			if ((rbits &= 017) == 0) {
				putc(dp->chars.hib, cfp);
				putc(dp->chars.lob, cfp);
				if (ferror(cfp))
					goto done;
E 6
			}
D 6
			stack [stp] >>= 1;
E 6
I 6
			*sp >>= 1;
E 6
		}
		stbits = 16;
I 6
	} while (--sp >= &stack[0]);
done:
	bits = rbits;
}

compress(uncfp, cfp)
	register FILE *uncfp, *cfp;
{
	register union cio *dp = &d;
	register union cio *cp = &c;

	cp->integ = (dp->integ >> 8) & 0377;
	for (; cp->integ != EOF; cp->integ = getc(uncfp)) {
		if ((in[cp->integ].flags & SEEN) == 0) {
			register short j, m;

			encode(NC);
			uptree(NC);
			insert(cp->integ);

			m = 0200;
			for (j = 8; j--; m >>= 1) {
				dp->integ <<= 1;
				if (m & cp->integ)
					dp->integ++;
				++bits;
				if ((bits &= 017) == 0) {
					putc(dp->chars.hib, cfp);
					putc(dp->chars.lob, cfp);
				}
			}
		} else
			encode(cp->integ);
		if (ferror(cfp)) {
			perror(fname);
			return (1);
		}
		uptree(cp->integ);
E 6
	}
I 6
	if (ferror(uncfp)) {
		perror(infname);
		return (1);
	}
	return (0);
}

FILE *
setup(uncfp, ignore)
	FILE *uncfp;
	int *ignore;
{
	FILE *cfp = NULL;
	register union cio *dp = &d;
	register union cio *cp = &c;

	dp->integ = getc(uncfp);
	if (*ignore = (dp->integ == EOF))
		goto bad;
	cp->integ = getc(uncfp);
	if (*ignore = (cp->integ == EOF))
		goto bad;
	dp->chars.hib = cp->integ & 0377;
	if ((dp->integ &= 0177777) == COMPACTED) {
		fprintf(stderr, "%s: Already compacted.\n", infname);
		*ignore = 1;
		goto bad;
	}
	if (dp->integ == PACKED) {
		fprintf(stderr,
D 7
		    "%s: Already packed using program pack.  Use unpack.\n",
E 7
I 7
		    "%s: Already packed using pack program, use unpack.\n",
E 7
		    infname);
		*ignore = 1;
		goto bad;
	}
	if (strcmp(infname, "-") != 0) {
		sprintf(fname, "%s.C", infname);
		cfp = fopen(fname, "w");
D 7
		if (cfp == NULL) {
			perror(fname);
			goto bad;
		}
E 7
I 7
		if (cfp == NULL)
			goto bad2;
E 7
		(void) fchmod(fileno(cfp), ucfstatus.st_mode);
	} else
		cfp = stdout;
	cp->integ = COMPACTED;
	putc(cp->chars.lob, cfp);
	putc(cp->chars.hib, cfp);
	if (ferror(cfp))
D 7
		goto bad;
E 7
I 7
		goto bad2;
E 7
	bits = 8;
	cp->integ = dp->integ & 0377;

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
	return (cfp);
D 7
bad:
E 7
I 7
bad2:
E 7
	if (cfp && cfp != stdout) {
D 7
		perror(fname);
E 7
I 7
		fprintf(stderr, "compact: "), perror(fname);
E 7
		(void) unlink(fname);
D 7
		fclose(cfp);
E 7
	}
I 7
bad:
	if (cfp && cfp != stdout)
		fclose(cfp);
E 7
	return (NULL);
E 6
}
E 1
