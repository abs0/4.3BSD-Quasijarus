h36400
s 00008/00008/00566
d D 2.10 87/03/05 20:17:22 garrison 16 15
c rename tmpfile to bibtmpfile to avoid apparent name clash on suns
c (mlvdv)
e
s 00005/00001/00569
d D 2.9 85/07/23 11:10:28 rrh 15 14
c fixed a vax machine dependency.
e
s 00003/00003/00567
d D 2.8 85/06/10 06:17:10 garrison 14 13
c length of key argument can be set with -k in command line.
e
s 00005/00001/00565
d D 2.7 84/10/12 17:33:14 rrh 13 12
c add -d flag to all programs, to change the /usr/lib/bmac directory 
c to whatever the user wants; default is /usr/lib/bmac
e
s 00009/00007/00557
d D 2.6 84/10/12 15:09:51 rrh 12 11
c add -v flag, that forces -f (footnotes), and also places no 
c citation string in the output.  Anticipated use is making bibliographies 
c that are explicitly ordered, such as in vitae (brag sheets)
e
s 00049/00007/00515
d D 2.5 84/03/27 10:15:21 rrh 11 10
c When the [.$C$<fmt> citation.] format is used,
c print out the citation in the currently active format. This prevents
c changing the citation from affecting the entire file, which it used to
c do before.
e
s 00188/00148/00334
d D 2.4 84/01/29 14:52:25 rrh 10 9
c add ALGORITHMS!!!!! Maintain a hash table of references, and
c a hash table of definitions.  use registers. cut down on n^2 algorithms.
c use structures.  These mods made a 11 minute run be 1 minute long.; still
c may be bugs in this
e
s 00020/00002/00462
d D 2.3 84/01/24 12:55:43 rrh 9 7
c Allow [.$C$4D-2 cits....] (for example) buried in citations
c to change the citation format string.  Unfortunately, the citation string
c can only be set once, and effect the entire file.  Also, add citation format
c 9, for printing the entire last name of the principle author.
e
s 00021/00002/00462
d R 2.3 84/01/24 11:46:14 rrh 8 7
c Allow [.$C$4D-2 cits....] (for example) buried in citations
c to change the citation format string.  Unfortunately, the citation string
c can only be set once, and effect the entire file.  Also, add citation format
c 9, for printing the entire last name of the principle author.
e
s 00052/00375/00412
d D 2.2 83/09/23 16:35:07 garrison 7 5
c 
e
s 00053/00376/00411
d R 2.2 83/09/23 15:38:05 garrison 6 5
c Included changes from Arizona
e
s 00000/00000/00787
d D 2.1 83/06/22 14:23:37 garrison 5 4
c Make new release before sending it to Arizona for new changes.
e
s 00004/00000/00783
d D 1.4 83/06/14 16:46:36 rrh 4 3
c add sccs keywords per BSD conventions. Fix format strings so 
c pdp-11 style %D is now %ld, to not interact with sccs
e
s 00021/00004/00762
d D 1.3 83/06/14 15:43:12 rrh 3 2
c bib now prints out `source-file', line line-number: for 
c recording errors; error program can now pick up this format
e
s 00083/00013/00683
d D 1.2 83/06/10 11:05:03 garrison 2 1
c Changed argument syntax so that format control for authors
c and editors is more uniform (both at command level, and in format files).
c Changed rcomp so that, when sorting on the author field, an attempt
c is made to use some other meaningful field if a reference has no
e
s 00696/00000/00000
d D 1.1 83/06/06 11:37:09 garrison 1 0
c date and time created 83/06/06 11:37:09 by garrison
e
u
U
t
T
I 4
#ifndef lint
static char sccsid[] = "%W%	%G%";
#endif not lint
D 7

E 7
E 4
I 1
/*
D 7
   bib - bibliographic formatter
         timothy a. budd, 1/82
         lookup routines supplied by gary levin 2/82
         reworked several new features added, 11/82.
*/
E 7
I 7
        Bib - bibliographic formatter

        Authored by: Tim Budd, University of Arizona, 1983.
                lookup routines written by gary levin 2/82

                version 7/4/83

        Various modifications suggested by:
                David Cherveny - Duke University Medical Center
                Phil Garrison - UC Berkeley
                M. J. Hawley - Yale University




                                                        */
E 7
# include <stdio.h>
# include <ctype.h>
# include "bib.h"

# define HUNTSIZE 512                /* maximum size of hunt string         */
D 7
# define MAXFIELD 250                /* maximum field length                */
E 7
# define MAXREFS  300                /* maximum number of references        */
# define MAXATONCE 35                /* maximum references at one location  */

# define getch(c,fd) (c = getc(fd))
# define echoc(c,ifd,ofd) (getch(c,ifd) == EOF ? c : putc(c,ofd))
# define testc(c,d,ifd,ofd) (getch(c, ifd) == d ? putc(c, ofd) : 0)

/* global variables */
   FILE *rfd;                   /* reference temporary file              */
I 11
#ifndef INCORE
E 11
   char reffile[] = TMPREFFILE ;/* temporary file (see bib.h)            */
I 11
#endif not INCORE
E 11
D 10
   long int refspos[MAXREFS];   /* reference seek positions              */
E 10
I 10
   struct refinfo refinfo[MAXREFS];	/* reference information */
   struct refinfo *refssearch();
   struct refinfo *refshash[HASHSIZE];
E 10
   long int rend = 1;           /* last position in rfd (first char unused)*/
D 10
   int numrefs = -1;            /* number of references generated so far */
E 10
I 10
   int numrefs = 0;            /* number of references generated so far */
E 10
   FILE *tfd;                   /* output of pass 1 of file(s)           */
D 16
   char tmpfile[] = TMPTEXTFILE ; /* output of pass 1                    */
E 16
I 16
   char bibtmpfile[] = TMPTEXTFILE ; /* output of pass 1                    */
E 16
D 13
   char common[] = COMFILE ;    /* common word file                      */
E 13
I 13
   char *common = COMFILE;       /* common word file                      */
E 13
D 10
   char *citestr[MAXREFS];      /* citation strings                      */
E 10
   int  findex = false;         /* can we read the file INDEX ?          */

/* global variables in bibargs */
D 12
   extern int foot, sort, personal;
E 12
I 12
D 14
   extern int foot, doacite, sort, personal;
E 14
I 14
   extern int foot, doacite, sort, max_klen, personal;
E 14
E 12
D 7
   extern int hyphen, ordcite;
   extern char sortstr[], pfile[], citetemplate[];
I 3
   char *bibfname;		/* file name currently reading */
   char *biblineno;		/* line number in that file */
E 7
I 7
   extern int hyphen, ordcite, biblineno;
   extern char sortstr[], pfile[], citetemplate[], bibfname[];
E 7
E 3

I 10
#include <signal.h>
E 10

main(argc, argv)
   int argc;
   char **argv;
{  int rcomp();
I 10
   int intr();
E 10

   /* the file INDEX in the current directory is the default index,
      if it is present */
I 13

   strcpy(BMACLIB, N_BMACLIB);
   strcpy(COMFILE, N_COMFILE);
   strcpy(DEFSTYLE, N_DEFSTYLE);
E 13

I 10
   signal(SIGINT, intr);
E 10
   rfd = fopen( INDXFILE , "r");
   if (rfd != NULL) {
      findex = true;
      fclose(rfd);
      }

I 10
#ifndef INCORE
E 10
   /* open temporaries, reffile will contain references collected in
D 16
      pass 1, and tmpfile will contain text.
E 16
I 16
      pass 1, and bibtmpfile will contain text.
E 16
   */
   mktemp(reffile);
   rfd = fopen(reffile,"w+");
   if (rfd == NULL)
D 10
      error("can't open temporary reference file");
E 10
I 10
      error("can't open temporary reference file, %s", reffile);
E 10
I 7
   putc('x', rfd);      /* put garbage in first position (not used) */
I 10
#endif not INCORE
E 10
E 7
D 16
   mktemp(tmpfile);
   tfd = fopen(tmpfile,"w");
E 16
I 16
   mktemp(bibtmpfile);
   tfd = fopen(bibtmpfile,"w");
E 16
   if (tfd == NULL)
D 10
      error("can't open temporary output file");
E 10
I 10
D 16
      error("can't open temporary output file, %s", tmpfile);
E 16
I 16
      error("can't open temporary output file, %s", bibtmpfile);
E 16
E 10

    /*
       pass1 - read files, looking for citations
               arguments are read by doargs (bibargs.c)
    */

D 3
   if (doargs(argc, argv, DEFSTYLE ) == 0)
E 3
I 3
D 7
   if (doargs(argc, argv, DEFSTYLE ) == 0){
      bibfname = "<stdin>";
E 7
I 7
   if (doargs(argc, argv, DEFSTYLE ) == 0) {
      strcpy(bibfname, "<stdin>");
E 7
E 3
      rdtext(stdin);
I 3
D 7
   }
E 7
I 7
      }
E 7
E 3

   /*
    sort references, make citations, add disambiguating characters
   */

   if (sort)
D 10
      qsort(refspos, numrefs+1, sizeof(long), rcomp);
   makecites(citestr);
E 10
I 10
      qsort(refinfo, numrefs, sizeof(struct refinfo), rcomp);
   makecites();
E 10
   disambiguate();

   /*
   reopen temporaries
   */

   fclose(tfd);
D 16
   tfd = fopen(tmpfile,"r");
E 16
I 16
   tfd = fopen(bibtmpfile,"r");
E 16
   if (tfd == NULL)
D 10
      error("can't open temporary output file for reading");

E 10
I 10
D 16
      error("can't open temporary output file %s for reading", tmpfile);
E 16
I 16
      error("can't open temporary output file %s for reading", bibtmpfile);
E 16
E 10
   /*
   pass 2 - reread files, replacing references
   */
D 10

E 10
   pass2(tfd, stdout);
D 10

   /*
   clean up
   */

E 10
I 10
   cleanup(0);
}
/* interrupt processing */
intr()
{
   cleanup(1);
}
/* clean up and exit */
cleanup(val)
{
E 10
   fclose(tfd);
I 10
#ifndef INCORE
E 10
   fclose(rfd);
D 10
   unlink(tmpfile);
E 10
   unlink(reffile);
D 10
   exit(0);
E 10
I 10
#endif INCORE
#ifndef DEBUG
D 16
   unlink(tmpfile);
E 16
I 16
   unlink(bibtmpfile);
E 16
#endif DEBUG
   exit(val);
E 10
}

/* rdtext - read and process a text file, looking for [. commands */
   rdtext(fd)
   FILE *fd;
{  char lastc, c, d;

I 3
D 7
   biblineno = 0;
E 3
   lastc = 0;
E 7
I 7
   lastc = '\0';
   biblineno = 1;
E 7
   while (getch(c, fd) != EOF)
      if (c == '[' || c == '{')
         if (getch(d, fd) == '.') { /* found a reference */
            if (c == '{') { if (lastc) putc(lastc, tfd);}
            else
D 2
               if (lastc == ' ')       fputs("\\*([<", tfd);
               else if (lastc == '.')  fputs("\\*([.", tfd);
               else if (lastc == ',')  fputs("\\*([,", tfd);
               else if (lastc)         putc(lastc, tfd);
E 2
I 2
D 7
	       switch (lastc) {
	       case ' ': fputs("\\*([<", tfd);
			 break;
               case '.': fputs("\\*([.", tfd);
			 break;
               case ',': fputs("\\*([,", tfd);
			 break;
               case '?': fputs("\\*([?", tfd);
			 break;
               case ':': fputs("\\*([:", tfd);
			 break;
               case ';': fputs("\\*([;", tfd);
			 break;
               case '!': fputs("\\*([!", tfd);
			 break;
               case '"': fputs("\\*([\"", tfd);
			 break;
               case '\'': fputs("\\*(['", tfd);
			 break;
	       default : putc(lastc, tfd);
			 break;
	       }
E 7
I 7
               switch (lastc) {
                  case '\0': break;
                  case ' ': fputs("\\*([<", tfd); break;
                  case '.': case ',': case '?': case ':':
                  case ';': case '!': case '"': case '\'':
                            fputs("\\*([", tfd);  /* fall through */
                  default:  putc(lastc, tfd); break;
                  }
E 7
E 2
            rdcite(fd, c);
            if (c == '[')
D 2
               if (lastc == ' ')       fputs("\\*(>]", tfd);
               else if (lastc == '.')  fputs("\\*(.]", tfd);
               else if (lastc == ',')  fputs("\\*(,]", tfd);
E 2
I 2
D 7
	       switch (lastc) {
	       case ' ': fputs("\\*(<]", tfd);
			 break;
               case '.': fputs("\\*(.]", tfd);
			 break;
               case ',': fputs("\\*(,]", tfd);
			 break;
               case '?': fputs("\\*(?]", tfd);
			 break;
               case ':': fputs("\\*(:]", tfd);
			 break;
               case ';': fputs("\\*(;]", tfd);
			 break;
               case '!': fputs("\\*(!]", tfd);
			 break;
               case '"': fputs("\\*(\"]", tfd);
			 break;
               case '\'': fputs("\\*(']", tfd);
			 break;
	       }
E 2
            lastc = 0;
E 7
I 7
               switch (lastc) {
                  case '\0': break;
                  case ' ': fputs("\\*(>]", tfd); break;
                  case '.': case ',': case '?': case ':':
                  case ';': case '!': case '"': case '\'':
                            fprintf(tfd,"\\*(%c]", lastc); break;
                  }
            lastc = '\0';
E 7
            }
         else {
D 7
            if (lastc) putc(lastc, tfd);
E 7
I 7
            if (lastc != '\0') putc(lastc, tfd);
E 7
            ungetc(d, fd);
            lastc = c;
            }
      else {
D 7
         if (lastc) putc(lastc, tfd);
E 7
I 7
         if (lastc != '\0') putc(lastc, tfd);
E 7
         lastc = c;
I 3
D 7
	 if (c == '\n')
		biblineno++;
E 7
I 7
         if (c == '\n') biblineno++;
E 7
E 3
         }
D 7
   if (lastc) putc(lastc, tfd);
E 7
I 7
   if (lastc != '\0') putc(lastc, tfd);
E 7
}

/* rdcite - read citation information inside a [. command */
   rdcite(fd, ch)
   FILE *fd;
   char ch;
D 10
{  long int n, getref();
E 10
I 10
D 11
{  int n, getref();
E 11
I 11
{  int getref();
E 11
E 10
   char huntstr[HUNTSIZE], c, info[HUNTSIZE];

   if (ch == '[')
D 12
      fputs("\\*([[", tfd);
E 12
I 12
      if (doacite) fputs("\\*([[", tfd);
E 12
   else
D 12
      fputs("\\*([{", tfd);
E 12
I 12
      if (doacite) fputs("\\*([{", tfd);
E 12
   huntstr[0] = info[0] = 0;
   while (getch(c, fd) != EOF)
      switch (c) {
         case ',':
D 10
            n = getref(huntstr);
            if (n > 0)
               fprintf(tfd, "%c%ld%c%s%c", CITEMARK, n, CITEMARK, info, CITEEND);
            else
               fprintf(tfd, "%c0%c%s%s%c", CITEMARK, CITEMARK,
                                           huntstr, info, CITEEND);
E 10
I 10
	    citemark(info, huntstr, (char *)0);
E 10
            huntstr[0] = info[0] = 0;
            break;
D 10

E 10
         case '.':
            while (getch(c, fd) == '.') ;
            if (c == ']') {
D 10
               n = getref(huntstr);
               if (n > 0)
                  fprintf(tfd, "%c%ld%c%s%c\\*(]]", CITEMARK, n,
                                                  CITEMARK, info, CITEEND);
               else
                  fprintf(tfd, "%c0%c%s%s%c\\*(]]", CITEMARK, CITEMARK,
                                              huntstr, info, CITEEND);
E 10
I 10
	       citemark(info, huntstr, "\\*(]]");
E 10
               return;
               }
            else if (c == '}') {
D 10
               n = getref(huntstr);
               if (n > 0)
                  fprintf(tfd, "%c%ld%c%s%c\\*(}]", CITEMARK, n,
                                                    CITEMARK, info, CITEEND);
               else
                  fprintf(tfd, "%c0%c%s%s%c\\*(}]", CITEMARK, CITEMARK,
                                              huntstr, info, CITEEND);
E 10
I 10
	       citemark(info, huntstr, "\\*(}]");
E 10
               return;
               }
            else
               addc(huntstr, c);
            break;

         case '{':
            while (getch(c, fd) != '}')
               if (c == EOF) {
D 10
                  fprintf(stderr, "Error: ill formed reference\n");
                  exit(1);
E 10
I 10
                  error("ill formed reference");
E 10
                  }
                else
                  addc(info, c);
            break;

         case '\n':
I 7
            biblineno++;
E 7
         case '\t':
            c = ' ';   /* fall through */

         default:
            addc(huntstr,c);
         }
   error("end of file reading citation");
}
I 11
char	ncitetemplate[64];
int	changecite;
E 11
I 10
citemark(info, huntstr, tail)
	char *info, *huntstr, *tail;
{
	char c = CITEMARK;
        long int  n;
I 11
	/*
	 *	getref sets ncitetemplate as a side effect
	 */
E 11
	n = getref(huntstr);
I 11
	if (ncitetemplate[0]){
		fprintf(tfd, "%c%s%c", FMTSTART, ncitetemplate, FMTEND);
		ncitetemplate[0] = 0;
	}
E 11
D 12
	fprintf(tfd, "%c%d%c%s%c%s", c ,n, c, info, CITEEND, tail);
E 12
I 12
D 15
	fprintf(tfd, "%c%d%c%s%c%s", c ,n, c, info, CITEEND, doacite?tail:0);
E 15
I 15
	if (doacite && (tail != (char *)0))
	  fprintf(tfd, "%c%d%c%s%c%s", c ,n, c, info, CITEEND, tail);
	else
	  fprintf(tfd, "%c%d%c%s%c", c ,n, c, info, CITEEND);

E 15
E 12
}
E 10

/* addc - add a character to hunt string */
   addc(huntstr, c)
   char huntstr[HUNTSIZE], c;
{  int  i;

   i = strlen(huntstr);
   if (i > HUNTSIZE)
D 10
      error("citation too long");
E 10
I 10
      error("citation too long, max of %d", HUNTSIZE);
E 10
   huntstr[i] = c;
   huntstr[i+1] = 0;
}
D 11

E 11
D 10
/* getref - if an item was already referenced, return its pointer in
                the reference file, otherwise create a new entry */
   long int getref(huntstr)
E 10
I 10
/* getref - if an item was already referenced, return its reference index
                otherwise create a new entry */
   int getref(huntstr)
E 10
   char huntstr[HUNTSIZE];
D 10
{  char rf[REFSIZE], ref[REFSIZE], *r, *hunt();
   int  i, match(), getwrd();
E 10
I 10
{  char rf[REFSIZE], *r, *hunt();
D 11
   reg	int  i;
E 11
   int	match(), getwrd();
E 10
I 9
   char	*realhstr;
I 10
   int hash;
   struct refinfo *rp;
   int	lg;
E 10
E 9

D 9
   r = hunt(huntstr);
E 9
I 9
   realhstr = huntstr;
   if (strncmp(huntstr, "$C$", 3) == 0){
	char *from, *to;
D 11
	for(from = huntstr + 3, to = citetemplate; *from; from++, to++){
E 11
I 11
	changecite++;
	for(from = huntstr + 3, to = ncitetemplate; *from; from++, to++){
E 11
		switch(*from){
		case '\0':
		case ' ':
		case '\n':
		case '\t':	goto outcopy;
		default:	*to = *from;
		}
	}
   outcopy: ;
	*to = 0;
	*from = 0;
	realhstr = from + 1;
   }
   r = hunt(realhstr);
E 9
   if (r != NULL) {
D 10
      /* exapand defined string */
E 10
I 10
      /* expand defined string */
E 10
      strcpy(rf, r);
      free(r);
      expand(rf);
D 10

E 10
      /* see if reference has already been cited */
D 10

      if (foot == false)
         for (i = 0; i <= numrefs; i++) {
             rdref(refspos[i], ref);
             if (strcmp(ref, rf) == 0)
                return(refspos[i]);
          }

E 10
I 10
      if (foot == false && (rp = refssearch(rf))){
		return(rp - refinfo);
      }
E 10
      /* didn't match any existing reference, create new one */
D 10

      numrefs++;
      refspos[numrefs] = rend;
D 7
      fseek(rfd, rend, 0);
E 7
I 7
#ifdef READWRITE
      fixrfd( WRITE );                 /* fix access mode of rfd, if nec. */
#else
      fseek(rfd, rend, 0);             /* go to end of rfd */
#endif
E 7
      i = strlen(rf) + 1;
      fwrite(rf, 1, i, rfd);
      rend = rend + i;
      return(refspos[numrefs]);
E 10
I 10
      if (numrefs >= MAXREFS)
	error("too many references, max of %d", MAXREFS);
      hash = strhash(rf);
      lg = strlen(rf) + 1;
      refinfo[numrefs].ri_pos = rend;
      refinfo[numrefs].ri_length = lg;
      refinfo[numrefs].ri_hp = refshash[hash];
      refinfo[numrefs].ri_n = numrefs;
      refshash[hash] = &refinfo[numrefs];
      wrref(&refinfo[numrefs], rf);
      return(numrefs++);
E 10
      }
   else {
D 3
      fprintf(stderr,"no reference matching %s\n", huntstr);
E 3
I 3
D 9
      bibwarning("no reference matching %s\n", huntstr);
E 9
I 9
      bibwarning("no reference matching %s\n", realhstr);
E 9
E 3
D 10
      return( (long) -1 );
E 10
I 10
      return(-1);
E 10
      }
}
D 10

E 10
I 10
struct refinfo *refssearch(rf)
   char *rf;
{
   char ref[REFSIZE];
   reg	int i;
   int	lg;
   reg	struct refinfo *rp;
   lg = strlen(rf) + 1;
   for (rp = refshash[strhash(rf)]; rp; rp = rp->ri_hp){
	     if (rp->ri_length == lg){
		     rdref(rp, ref);
		     if (strcmp(ref, rf) == 0)
			return(rp);
	     }
   }
   return(0);
}
E 10
D 7
/* rdref - read text for an already cited reference */
   rdref(i, ref)
   long int  i;
   char ref[REFSIZE];
{
   ref[0] = 0;
   fseek(rfd, i, 0);
   fread(ref, 1, REFSIZE, rfd);
}

E 7
/* hunt - hunt for reference from either personal or system index */
   char *hunt(huntstr)
   char huntstr[];
{  char *fhunt(), *r, *p, *q, fname[120];

   if (personal) {
      for (p = fname, q = pfile; ; q++)
         if (*q == ',' || *q == 0) {
            *p = 0;
            if ((r = fhunt(fname, huntstr)) != NULL)
               return(r);
            else if (*q == 0)
               break;
            p = fname;
            }
         else *p++ = *q;
      }
   else if (findex) {
      if ((r = fhunt( INDXFILE , huntstr)) != NULL)
         return(r);
      }
   if ((r = fhunt(SYSINDEX , huntstr)) != NULL)
      return(r);
   return(NULL);
}

/* fhunt - hunt from a specific file */
   char *fhunt(file, huntstr)
   char file[], huntstr[];
{  char *p, *r, *locate();

D 14
   r = locate(huntstr, file, 6, common);
E 14
I 14
   r = locate(huntstr, file, max_klen, common);
E 14

   if (r == NULL)
      return(NULL);  /* error */
   if (*r == 0)
      return(NULL);  /* no match */

   for (p = r; *p; p++)
      if (*p == '\n')
         if (*(p+1) == '\n') { /* end */
            if (*(p+2) != 0)
D 3
               fprintf(stderr,"multiple references match %s\n",huntstr);
E 3
I 3
D 7
               bibwarning("multiple references match %s\n", huntstr);
E 7
I 7
               bibwarning("multiple references match %s\n",huntstr);
E 7
E 3
            *(p+1) = 0;
            break;
            }
         else if (*(p+1) != '%' && *(p+1) != '.') /* unnecessary newline */
            *p = ' ';
   return(r);
}
I 10
struct cite{
	int	num;
	char	*info;
};
citesort(p1, p2)
	struct cite *p1, *p2;
{
	return(p1->num - p2->num);
}
E 10

D 7
/* rcomp - reference comparison routine for qsort utility */
   int rcomp(ap, bp)
   long int *ap, *bp;
{  char ref1[REFSIZE], ref2[REFSIZE], field1[MAXFIELD], field2[MAXFIELD];
   char *p, *q, *getfield();
   int  neg, res;
I 2
   int  fields_found;
E 2

   rdref(*ap, ref1);
   rdref(*bp, ref2);
   for (p = sortstr; *p; p = q) {
      if (*p == '-') {
         p++;
         neg = true;
         }
      else
         neg = false;
      q = getfield(p, field1, ref1);
D 2
      if (q == 0)
         res = 1;
      else if (getfield(p, field2, ref2) == 0)
         res = -1;
      else {
E 2
I 2
      fields_found = true;
      if (q == 0) {
	 res = 1;
	 fields_found = false;
      } else if (strcmp (field1, "") == 0) {	/* field not found */
E 2
         if (*p == 'A') {
I 2
            getfield("F", field1, ref1);
	    if (strcmp (field1, "") == 0) {
               getfield("I", field1, ref1);
	       if (strcmp (field1, "") == 0) {
	          res = 1;
		  fields_found = false;
	       }
	    }
	 } else {
	    res = 1;
	    fields_found = false;
	 }
      }

      if (getfield(p, field2, ref2) == 0) {
	 res = -1;
	 fields_found = false;
      } else if (strcmp (field2, "") == 0) {	/* field not found */
         if (*p == 'A') {
            getfield("F", field2, ref2);
	    if (strcmp (field2, "") == 0) {
               getfield("I", field2, ref2);
	       if (strcmp (field2, "") == 0) {
	          res = -1;
		  fields_found = false;
	       }
	    }
	 } else {
	    res = -1;
	    fields_found = false;
	 }
      }
      if (fields_found) {
         if (*p == 'A') {
E 2
            if (isupper(field1[0]))
               field1[0] -= 'A' - 'a';
            if (isupper(field2[0]))
               field2[0] -= 'A' - 'a';
            }
         res = strcmp(field1, field2);
         }
      if (neg)
         res = - res;
      if (res != 0)
         break;
      }
   if (res == 0)
      if (ap < bp)
         res = -1;
      else
         res = 1;
   return(res);
}

/* makecites - make citation strings */
   makecites(citestr)
   char *citestr[];
{  char ref[REFSIZE], tempcite[100], *malloc();
   int  i;

   for (i = 0; i <= numrefs; i++) {
      rdref(refspos[i], ref);
      bldcite(tempcite, i, ref);
      citestr[i] = malloc(2 + strlen(tempcite)); /* leave room for disambig */
      if (citestr[i] == NULL)
         error("out of storage");
      strcpy(citestr[i], tempcite);
      }
}

/* bldcite - build a single citation string */
   bldcite(cp, i, ref)
   char *cp, ref[];
   int  i;
{  char *p, *q, c, *fp, *np, field[REFSIZE], temp[100], *getfield();
   int  j;

   getfield("F", field, ref);
   if (field[0] != 0)
      for (p = field; *p; p++)
         *cp++ = *p;
   else {
      p = citetemplate;
      field[0] = 0;
      while (c = *p++)
         if (isalpha(c)) {
            q = getfield(p-1, field, ref);
            if (q != 0) {
               p = q;
               for (fp = field; *fp; )
                  *cp++ = *fp++;
               }
            }
         else if (c == '1') {
            sprintf(field,"%d",1 + i);
            for (fp = field; *fp; )
               *cp++ = *fp++;
            }
         else if (c == '2') {
            if (getname(1, field, temp, ref)) {
               np = cp;
               fp = field;
               for (j = 1; j <= 3; j++)
                  if (*fp != 0)
                     *cp++ = *fp++;
               if (getname(2, field, temp, ref))
                  np[2] = field[0];
               if (getname(3, field, temp, ref)) {
                  np[1] = np[2];
                  np[2] = field[0];
                  }
               }
            }
         else if (c == '{') {
            while (*p ^= '}')
               if (*p == 0)
                  error("unexpected end of citation template");
               else
                  *cp++ = *p++;
            p++;
            }
         else if (c == '<') {
            while (*p ^= '>')
               if (*p == 0)
                  error("unexpected end of citation template");
               else
                  *cp++ = *p++;
            p++;
            }
         else if (c != '@')
            *cp++ = c;
      }
   *cp++ = 0;
}

/* getfield - get a single field from reference */
   char *getfield(ptr, field, ref)
   char *ptr, field[], ref[];
{  char *p, *q, temp[100];
   int  n, len, i, getname();

   field[0] = 0;
   if (*ptr == 'A')
      getname(1, field, temp, ref);
   else
      for (p = ref; *p; p++)
         if (*p == '%' && *(p+1) == *ptr) {
            for (p = p + 2; *p == ' '; p++)
               ;
            for (q = field; *p != '\n'; )
               *q++ = *p++;
            *q = 0;
            break;
            }
   n = 0;
   len = strlen(field);
   if (*++ptr == '-') {
      for (ptr++; isdigit(*ptr); ptr++)
         n = 10 * n + (*ptr - '0');
      if (n > len)
         n = 0;
      else
         n = len - n;
      for (i = 0; field[i] = field[i+n]; i++)
         ;
      }
   else if (isdigit(*ptr)) {
      for (; isdigit(*ptr); ptr++)
         n = 10 * n + (*ptr - '0');
      if (n > len)
         n = len;
      field[n] = 0;
      }

   if (*ptr == 'u') {
      ptr++;
      for (p = field; *p; p++)
         if (islower(*p))
            *p = (*p - 'a') + 'A';
      }
   else if (*ptr == 'l') {
      ptr++;
      for (p = field; *p; p++)
         if (isupper(*p))
            *p = (*p - 'A') + 'a';
      }
   return(ptr);
}

/* getname - get the nth name field from reference, breaking into
             first and last names */
   int getname(n, last, first, ref)
   int  n;
   char last[], first[], ref[];
{  char *p;

   for (p = ref; *p; p++)
D 2
      if (*p == '%' & *(p+1) == 'A') {
E 2
I 2
      if (*p == '%' & (*(p+1) == 'A' || *(p+1) == 'E')) {
E 2
         n--;
         if (n == 0) {
            for (p = p + 2; *p == ' '; p++) ;
            breakname(p, first, last) ;
            return(true);
            }
         }
   return(false);
}

/* disambiguate - compare adjacent citation strings, and if equal, add
                  single character disambiguators */
   disambiguate()
{  int i, j;
   char adstr[2];

   for (i = 0; i < numrefs; i = j) {
      j = i + 1;
      if (strcmp(citestr[i], citestr[j])==0) {
         adstr[0] = 'a'; adstr[1] = 0;
         for (j = i+1; strcmp(citestr[i],citestr[j]) == 0; j++) {
            adstr[0] = 'a' + (j-i);
            strcat(citestr[j], adstr);
            if (j == numrefs)
               break;
            }
         adstr[0] = 'a';
         strcat(citestr[i], adstr);
         }
     }
}

E 7
/* putrefs - gather contiguous references together, sort them if called
   for, hyphenate if necessary, and dump them out */
int putrefs(ifd, ofd, footrefs, fn)
FILE *ifd, *ofd;
int  fn, footrefs[];
D 10
{  int  citenums[MAXATONCE];   /* reference numbers */
   char *citeinfo[MAXATONCE];  /* reference information */
   char infoword[HUNTSIZE];    /* information line */
   int  rtop, n, i, j;         /* number of citations being dumped */
   char c, *p, *walloc();
E 10
I 10
{
	struct cite cites[MAXATONCE];
	char	infoword[HUNTSIZE];    /* information line */
	reg	int i;
	reg	char *p;
	reg	int  ncites, n, j;         /* number of citations being dumped */
	char	c, *walloc();
	int neg;
	/*
	 * first gather contiguous references together,
	 * and order them if required     
	 */
E 10

D 10
/* first gather contiguous references together, and order them if
   required      */
E 10
I 10
	ncites = 0;
D 14
	neg = 1;
E 14
	do {
I 14
		neg = 1;
E 14
		n = 0;
		do{
			getch(c, ifd);
			if (isdigit(c))
				n = 10 * n + (c - '0');
			else if (c == '-')
				neg *= -1;
			else if (c == CITEMARK)
				break;
			else
				error("bad cite char 0%03o in pass two",c);
		} while(1);
		if (neg < 0) {     /* reference not found */
			cites[ncites].num = -1;
			cites[ncites].info = 0;
			ncites++;
		} else {
			/*
			 * Find reference n in the references
			 */
			int i;
			for (i = 0; i < numrefs; i++){
				if (refinfo[i].ri_n == n){
					cites[ncites].num = i;
					cites[ncites].info = 0;
					ncites++;
					break;
				}
			}
			if (i == numrefs)
				error("citation	%d not found in pass 2", n);
		}
		if (getch(c, ifd) != CITEEND) {
			for (p = infoword; c != CITEEND ; ) {
				*p++ = c;
				getch(c, ifd);
			}
			*p = 0;
			cites[ncites-1].info = walloc(infoword);
		}
		getch(c, ifd);
	} while (c == CITEMARK);
	ungetc(c, ifd);
	if (ordcite)
		qsort(cites, ncites, sizeof(struct cite), citesort);
E 10

D 10
   rtop = -1;
   do {
      n = 0;
      while (isdigit(getch(c, ifd)))
         n = 10 * n + (c - '0');
      if (c ^= CITEMARK)
         error("inconsistant citation found in pass two");
      if (n == 0) {     /* reference not found */
         rtop++;
         j = rtop;
         citenums[j] = -1;
         citeinfo[j] = 0;
         }
      else {
         for (i = 0; i <= numrefs; i++)
            if (refspos[i] == n) { /* its the ith item in reference list */
               rtop++;
               j = rtop;
               if (ordcite)
                  for ( ; j > 0 && citenums[j-1] > i; j--) {
                     citenums[j] = citenums[j-1];
                     citeinfo[j] = citeinfo[j-1];
                     }
               citenums[j] = i;
               citeinfo[j] = 0;
               break;
               }
         if (i > numrefs)
            error("citation not found in pass two");
         }
      if (getch(c, ifd) != CITEEND) {
         for (p = infoword; c != CITEEND ; ) {
            *p++ = c;
            getch(c, ifd);
            }
         *p = 0;
         citeinfo[j] = walloc(infoword);
         }
      getch(c, ifd);
      }  while (c == CITEMARK);
   ungetc(c, ifd);

   /* now dump out values */
   for (i = 0; i <= rtop; i++) {
      if (citenums[i] >= 0)
         fputs(citestr[citenums[i]], ofd);
      if (citeinfo[i]) {
         fputs(citeinfo[i], ofd);
         free(citeinfo[i]);
         }
      if (hyphen) {
         for (j = 1; j + i <= rtop && citenums[i+j] == citenums[i] + j; j++);
         if (j + i > rtop) j = rtop;
         else j = j + i - 1;
         }
      else
         j = i;
      if (j > i + 1) {
         fputs("\\*(]-", ofd);
         i = j - 1;
         }
      else if (i != rtop)
         fputs("\\*(],", ofd);
      if (foot) {
         fn++;
         footrefs[fn] = citenums[i];
         }
      }
   return(fn);
E 10
I 10
	/* now dump out values */
	for (i = 0; i < ncites; i++) {
D 11
		if (cites[i].num >= 0)
			fputs(refinfo[cites[i].num].ri_cite, ofd);
E 11
I 11
		if (cites[i].num >= 0) {
			if (changecite){
				char tempcite[128];
				char ref[REFSIZE];
				struct refinfo *p;
				/*
				 * rebuild the citation string,
				 * using the current template in effect
				 */
				p = &refinfo[cites[i].num];
				rdref(p, ref);
				bldcite(tempcite, cites[i].num, ref);
				strcat(tempcite, p->ri_disambig);
D 12
				fputs(tempcite, ofd);
E 12
I 12
				if (doacite) fputs(tempcite, ofd);
E 12
			} else {
D 12
				fputs(refinfo[cites[i].num].ri_cite, ofd);
E 12
I 12
				if (doacite) fputs(refinfo[cites[i].num].ri_cite, ofd);
E 12
			}
I 12
			if (!doacite) fputs("\\&", ofd);
E 12
		}
E 11
		if (cites[i].info) {
D 12
			fputs(cites[i].info, ofd);
E 12
I 12
			if (doacite) fputs(cites[i].info, ofd);
			if (!doacite) fputs("\\&", ofd);
E 12
			free(cites[i].info);
		}
		if (hyphen) {
			for (j = 1;
			     j + i <= ncites && cites[i+j].num == cites[i].num + j;
			     j++)/*VOID*/;
			if (j + i > ncites)
				j = ncites;
			else
				j = j + i - 1;
		} else {
			j = i;
		}
		if (j > i + 1) {
			fputs("\\*(]-", ofd);
			i = j - 1;
		} else if (i != ncites - 1) {
			fputs("\\*(],", ofd);
		}
		if (foot) {
			fn++;
			footrefs[fn] = cites[i].num;
		}
	}
	return(fn);
E 10
}

/* pass2 - read pass 1 files entering citation */
   pass2(ifd, ofd)
   FILE *ifd, *ofd;
{
   char c;
   int  i, fn, footrefs[25], dumped;

   fn = -1;
   dumped = foot;
   while (getch(c, ifd) != EOF) {
      while (c == '\n') {
         putc(c, ofd);
         if (foot && fn >= 0) {
            for (i = 0; i <= fn; i++)
                dumpref(footrefs[i], ofd);
            fn = -1;
            }
         if (testc(c, '.', ifd, ofd))
            if (testc(c, '[', ifd, ofd))
               if (testc(c, ']', ifd, ofd)) {
                  while (echoc(c, ifd, ofd) != '\n')
                     ;
                  dumped = true;
D 10
                  for (i = 0; i <= numrefs; i++)
E 10
I 10
                  for (i = 0; i < numrefs; i++){
E 10
                     dumpref(i, ofd);
I 10
		  }
E 10
                  getch(c, ifd);
                  }
         }
D 11
      if (c == CITEMARK)
E 11
I 11
      if (c == FMTSTART)
	 changefmt(ifd);
      else if (c == CITEMARK)
E 11
         fn = putrefs(ifd, ofd, footrefs, fn);
      else if (c != EOF)
         putc(c, ofd);
      }
   if (dumped == false)
D 3
      fprintf(stderr,"Warning: references never dumped\n");
E 3
I 3
D 7
      bibwarning("Warning: references never dumped\n", (char *)0);
E 3
}


/* dumpref - dump reference number i */
   dumpref(i, ofd)
   int i;
   FILE *ofd;
{  char ref[REFSIZE], *p, line[REFSIZE];
   int numauths, maxauths, numeds, maxeds;

   rdref(refspos[i], ref);
   maxauths = maxeds = 0;
   numauths = numeds = 0;
   for (p = ref; *p; p++)
      if (*p == '%')
         if (*(p+1) == 'A') maxauths++;
         else if (*(p+1) == 'E') maxeds++;
   fprintf(ofd, ".[-\n");
   fprintf(ofd, ".ds [F %s\n",citestr[i]);
   fseek(rfd, (long) refspos[i], 0);
   while (fgets(line, REFSIZE, rfd) != NULL) {
      if (line[0] == 0)        break;
      else if (line[0] == '.') fprintf(ofd,"%s",line);
      else {
         if (line[0] == '%') {
            for (p = &line[2]; *p == ' '; p++);
            if (line[1] == 'A')       numauths++;
            else if (line[1] == 'E')  numeds++;

            doline(line[1], p, numauths, maxauths, numeds, maxeds, ofd);
            }
         }
      }
   fprintf(ofd,".][\n");
I 3
}
/*
 *	print out a warning message
 */
bibwarning(msg, arg)
	char	*msg;
	char	*arg;
{
	fprintf(stderr, "`%s', line %d: ", bibfname, biblineno);
	fprintf(stderr, msg, arg);
E 7
I 7
      bibwarning("Warning: references never dumped\n","");
I 11
}
/*
 *	change citation format
 */
changefmt(ifd)
	FILE	*ifd;
{
	char	c;
	char	*to;
	to = ncitetemplate;
	while (getch(c, ifd) != FMTEND)
		*to++ = c;
	*to = 0;
	strcpy(citetemplate, ncitetemplate);
E 11
E 7
E 3
}
E 1
