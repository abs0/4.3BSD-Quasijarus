h50108
s 00004/00000/00134
d D 2.5 84/10/12 17:34:06 rrh 8 7
c add -d flag to all programs, to change the /usr/lib/bmac directory 
c to whatever the user wants; default is /usr/lib/bmac
e
s 00001/00001/00133
d D 2.4 84/08/13 17:49:47 rrh 7 6
c changed initialization of numrefs - eduardo.
e
s 00038/00019/00096
d D 2.3 84/01/29 15:26:00 rrh 6 5
c integrate with semantics of bib and bibargs.c
e
s 00083/00085/00032
d D 2.2 83/09/23 15:44:58 garrison 5 3
c 
e
s 00084/00086/00031
d R 2.2 83/09/23 15:39:06 garrison 4 3
c Included changes from Arizona
e
s 00000/00000/00117
d D 2.1 83/06/22 14:24:36 garrison 3 2
c Make new release before sending it to Arizona for new changes.
e
s 00004/00000/00113
d D 1.2 83/06/14 16:47:15 rrh 2 1
c add sccs keywords per BSD conventions. Fix format strings so 
c pdp-11 style %D is now %ld, to not interact with sccs
e
s 00113/00000/00000
d D 1.1 83/06/06 11:37:18 garrison 1 0
c date and time created 83/06/06 11:37:18 by garrison
e
u
U
t
T
I 2
#ifndef lint
static char sccsid[] = "%W%	%G%";
#endif not lint
D 5

E 5
E 2
I 1
/*
D 5
        list all documents in ref index file
E 5
I 5
        Listrefs - list references for bib system

        Authored by: Tim Budd, University of Arizona, 1983.
                lookup routines written by gary levin 2/82

                version 7/4/83

        Various modifications suggested by:
                David Cherveny - Duke University Medical Center
                Phil Garrison - UC Berkeley
                M. J. Hawley - Yale University




E 5
                                                        */
# include <stdio.h>
# include <ctype.h>
# include "bib.h"
# include "streams.h"
D 5
# define MAXLINE 250
E 5
I 5
# define MAXLIST 2000  /* maximum number of references that can be listed */
# define getch(c,fd) (c = getc(fd))
E 5

FILE *tfd;
D 5
int  count = 1;
char refs[REFSIZE], *rp;
E 5

I 6
#ifndef INCORE
E 6
I 5
FILE *rfd;                      /* reference file position */
char reffile[] = TMPREFFILE;    /* temporary file (see bib.h) */
D 6
long int refspos[MAXLIST];      /* references temporary file, seek positions */
E 6
I 6
#endif INCORE
struct refinfo refinfo[MAXLIST];      /* references temporary file, seek positions */
struct refinfo *refshash[HASHSIZE];
E 6
long int rend = 1;              /* last used position in reference file */
D 7
int numrefs = -1;               /* number of references */
E 7
I 7
int numrefs = 0;               /* number of references */
E 7
D 6
char *citestr[MAXLIST];         /* citation strings */
E 6
extern int sort;                /* see if things are to be sorted */
extern char bibfname[];
extern int biblineno;

I 6
#include <signal.h>
E 6
E 5
main(argc, argv)
   int argc;
   char **argv;
D 5
{
E 5
I 5
{  char defult[120];
D 6
   int  i, rcomp();
E 6
I 6
   int  i, rcomp(), intr();
E 6

I 8
   strcpy(BMACLIB, N_BMACLIB);
   strcpy(COMFILE, N_COMFILE);
   strcpy(DEFSTYLE, N_DEFSTYLE);

E 8
I 6
   signal(SIGINT, intr);
E 6
E 5
   tfd = stdout;
D 5
   doargs(argc, argv, "/usr/lib/bmac/bib.list");
E 5
I 5
   strcpy(defult, BMACLIB);
   strcat(defult,"/bib.list");
I 6
#ifndef INCORE
E 6
   mktemp(reffile);
   rfd = fopen(reffile,"w+");
   if (rfd == NULL)
      error("can't open temporary reference file");
   putc('x', rfd);      /* put garbage in first position */
I 6
#endif not INCORE
E 6

   doargs(argc, argv, defult);

   if (sort)
D 6
      qsort(refspos, numrefs+1, sizeof(long), rcomp);
   makecites(citestr);
E 6
I 6
      qsort(refinfo, numrefs, sizeof(struct refinfo), rcomp);
   makecites();
E 6
   disambiguate();

D 6
   for (i = 0; i <= numrefs; i++)
E 6
I 6
   for (i = 0; i < numrefs; i++)
E 6
      dumpref(i, stdout);

E 5
D 6
   exit(0);
E 6
I 6
   cleanup(0);
E 6
}
I 6
intr()
{
  cleanup(1);
}
cleanup(val)
{
#ifndef INCORE
  fclose(rfd);
  unlink(reffile);
#endif not INCORE
  exit(val);
}
E 6

/* rdtext - process a file */
   rdtext(ifile)
   FILE *ifile;
D 5
{
   long int start, length;
   int  i, numauths, numeds;
   char *p, c;
E 5
I 5
{  char c, *p, rec[REFSIZE];
   int i;
I 6
   int hash, lg;
E 6
E 5

D 5
   start = length = 0L;

E 5
I 5
   biblineno = 1;
E 5
   for (;;) {
D 5
      start = nextrecord(ifile, start + length);
      if (start == EOF) break;
      length = recsize(ifile, start);
E 5
I 5
      while (getch(c, ifile) == '\n')
         biblineno++;   /* skip leading newlines */
      if (c == EOF)
         return;
E 5

D 5
      /* count number of authors */
      numauths = numeds = 0;
      p = refs;
      for (i = length; i > 0; i--)
         if ((*p++ = getc(ifile)) == '%') {
            i--;
            c = *p++ = getc(ifile);
            if (c == 'A')
               numauths++;
            else if (c == 'E')
               numeds++;
E 5
I 5
      p = rec;          /* read a reference */
      for (;;) {
         for (*p++ = c; getch(c, ifile) != '\n'; )
            if (c == EOF)
               error("ill formed reference file");
            else
               *p++ = c;
         if (getch(c, ifile) == '\n' || c == EOF) {
            biblineno++;
            *p++ = '\n';
            break;
E 5
            }
I 5
         if (c == '.' || c == '%')
            *p++ = '\n';
         else
            *p++ = ' ';
         }
E 5

      *p = 0;
D 5
      expand(refs);
      rp = refs;
      dumpref(stdout, numauths, numeds);
E 5
I 5
      expand(rec);
E 5

D 5
     }
}

/* get a line from reference file */
   char refgets(line)
   char line[];
{
   char c, *p;

   if (*rp == 0)
      return(0);
   for (p = line;;) {
      while ((c = *rp++) != '\n')
         if (c == 0)
            return(0);
         else
            *p++ = c;
      c = *rp;
      if (c == 0)
         break;
      if (c == '.' || c == '%' || c == '\n')
         break;
      *p++ = ' ';
E 5
I 5
D 6
      if (numrefs++ > MAXLIST)
         error("too many references");
      refspos[numrefs] = rend;
#ifdef READWRITE
      fixrfd( WRITE );          /* fix access mode of rfd, if nec. */
#else
      fseek(rfd, rend, 0);
#endif
      i = strlen(rec) + 1;
      fwrite(rec, 1, i, rfd);
      rend = rend + i;
E 6
I 6
      /* didn't match any existing reference, create new one */
      if (numrefs >= MAXLIST)
	error("too many references, max of %d", MAXLIST);
      hash = strhash(rec);
      lg = strlen(rec) + 1;
      refinfo[numrefs].ri_pos = rend;
      refinfo[numrefs].ri_length = lg;
      refinfo[numrefs].ri_hp = refshash[hash];
      refinfo[numrefs].ri_n = numrefs;
      refshash[hash] = &refinfo[numrefs];
      wrref(&refinfo[numrefs], rec);
      numrefs++;
E 6
E 5
      }
D 5
   *p++ = '\n';
   *p = 0;
   return(' ');
E 5
}
D 6

E 6
D 5
/* dump reference */
   dumpref(ofile, maxauths, maxeds)
   FILE *ofile;
   int maxauths, maxeds;
{
   char line[250], *p;
   int  numauths, numeds;

   fprintf(tfd, ".[-\n");
   fprintf(tfd, ".ds [F %d\n", count++);
   numauths = numeds = 0;
   while (refgets(line) != 0) {
      if (line[0] == '\n')
         break;
      else if (line[0] == '.')
         fprintf(ofile, "%s\n", line);
      else {
         if (line[0] == '%') {
            for (p = &line[2]; isspace(*p); p++);
            if (line[1] == 'A')
               numauths++;
            else if (line[1] == 'E')
               numeds++;
            doline(line[1], p, numauths, maxauths, numeds, maxeds, ofile);
            }
         }
      }
   fprintf(tfd, ".][\n");
}
E 5
E 1
