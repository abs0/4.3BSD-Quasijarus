h64000
s 00002/00001/01214
d D 2.12 87/11/16 16:52:13 garrison 17 16
c Fixed printing of multiple name citations in compsurv and astro
c formats
e
s 00056/00042/01159
d D 2.11 87/07/27 16:36:44 bostic 16 15
c checked in for garrison
e
s 00001/00001/01200
d D 2.10 85/11/22 11:33:35 garrison 15 14
c (pfile)
e
s 00009/00005/01192
d D 2.9 85/06/11 16:45:20 garrison 14 13
c incfile: fixed 'D' so that the entire definition of a word will be
c flushed when it has already been defined.
c disambiguate: fixed loop conditions to avoid compares past end of list
e
s 00039/00001/01158
d D 2.8 85/06/10 06:19:40 garrison 13 12
c -l flag added (set key length). 8 citation style added: 
c first two characters of last names of authors up to key length.
e
s 00020/00005/01139
d D 2.7 84/10/12 17:33:29 rrh 12 11
c add -d flag to all programs, to change the /usr/lib/bmac directory 
c to whatever the user wants; default is /usr/lib/bmac
e
s 00009/00000/01135
d D 2.6 84/10/12 15:10:08 rrh 11 10
c add -v flag, that forces -f (footnotes), and also places no 
c citation string in the output.  Anticipated use is making bibliographies 
c that are explicitly ordered, such as in vitae (brag sheets)
e
s 00012/00012/01123
d D 2.5 84/03/27 10:14:48 rrh 10 9
c When the [.$C$<fmt> citation.] format is used,
c print out the citation in the currently active format. This prevents
c changing the citation from affecting the entire file, which it used to
c do before.
e
s 00190/00111/00945
d D 2.4 84/01/29 14:52:42 rrh 9 8
c add ALGORITHMS!!!!! Maintain a hash table of references, and
c a hash table of definitions.  use registers. cut down on n^2 algorithms.
c use structures.  These mods made a 11 minute run be 1 minute long.; still
c may be bugs in this
e
s 00020/00001/01036
d D 2.3 84/01/24 11:46:28 rrh 8 7
c Allow [.$C$4D-2 cits....] (for example) buried in citations
c to change the citation format string.  Unfortunately, the citation string
c can only be set once, and effect the entire file.  Also, add citation format
c 9, for printing the entire last name of the principle author.
e
s 00520/00094/00517
d D 2.2 83/09/23 15:44:28 garrison 7 5
c 
e
s 00521/00095/00516
d R 2.2 83/09/23 15:38:29 garrison 6 5
c Included changes from Arizona
e
s 00000/00000/00611
d D 2.1 83/06/22 14:24:09 garrison 5 4
c Make new release before sending it to Arizona for new changes.
e
s 00004/00000/00607
d D 1.4 83/06/14 16:46:53 rrh 4 3
c add sccs keywords per BSD conventions. Fix format strings so 
c pdp-11 style %D is now %ld, to not interact with sccs
e
s 00004/00000/00603
d D 1.3 83/06/14 15:43:51 rrh 3 2
c bib now prints out `source-file', line line-number: for 
c recording errors; error program can now pick up this format
e
s 00024/00002/00579
d D 1.2 83/06/10 11:05:33 garrison 2 1
c Changed argument syntax so that format control for authors
c and editors is more uniform (both at command level, and in format files).
c Changed rcomp so that, when sorting on the author field, an attempt
c is made to use some other meaningful field if a reference has no
e
s 00581/00000/00000
d D 1.1 83/06/06 11:37:13 garrison 1 0
c date and time created 83/06/06 11:37:13 by garrison
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
I 7
        Authored by: Tim Budd, University of Arizona, 1983.
                version 7/4/83

        Various modifications suggested by:
                David Cherveny - Duke University Medical Center
                Phil Garrison - UC Berkeley
                M. J. Hawley - Yale University




E 7
        read argument strings for bib and listrefs
        do name formatting, printing lines, other actions common to both
                                                        */
# include <stdio.h>
# include <ctype.h>
# include "bib.h"
# define LINELENGTH 1024
# define MAXDEFS     500             /* maximum number of defined words */

/* global variables */
I 7
   char bibfname[120];          /* file name currently being read            */
   int  biblineno;              /* line number currently being referenced    */
E 7
   int  abbrev       = false;   /* automatically abbreviate names            */
   int  capsmcap     = false;   /* print names in caps small caps (CACM form)*/
   int  numrev       = 0;       /* number of authors names to reverse        */
   int  edabbrev     = false;   /* abbreviate editors names ?                */
   int  edcapsmcap   = false;   /* print editors in cap small caps           */
   int  ednumrev     = 0;       /* number of editors to reverse              */
I 13
   int	max_klen     = 6;	/* max size of key			     */
E 13
   int  sort         = false;   /* sort references ? (default no)            */
   int  foot         = false;   /* footnoted references ? (default endnotes) */
I 11
   int  doacite      = true;    /* place citations ? */
E 11
   int  hyphen       = false;   /* hypenate contiguous references            */
   int  ordcite      = true;    /* order multiple citations                  */
   char sortstr[80]  = "1";     /* sorting template                          */
   char trailstr[80] = "";      /* trailing characters to output             */
D 15
   char pfile[120];             /* private file name                         */
E 15
I 15
   char pfile[400];             /* private file name                         */
E 15
   int  personal = false;       /* personal file given ? (default no)        */
   char citetemplate[80] = "1"; /* citation template                         */
D 9
   char *words[MAXDEFS];        /* defined words                             */
   char *defs[MAXDEFS];         /* defined word definitions                  */
   int  wordtop = -1;           /* top of defined words array                */
E 9
I 9
   struct wordinfo words[MAXDEFS];     /* defined words */
   struct wordinfo *wordhash[HASHSIZE];
   struct wordinfo *wordsearch();
   int  wordtop = 0;           /* number of defined words         */
E 9
I 3
D 7
   char *bibfname;
   char *biblineno;
E 7
E 3

/* where output goes */
   extern FILE *tfd;
I 7
/* reference file information */
D 9
   extern long int refspos[];
E 9
I 9
   extern struct refinfo refinfo[];
E 9
   extern char reffile[];
I 9
#ifndef INCORE
E 9
   extern FILE *rfd;
D 9
   extern char *citestr[];
E 9
I 9
#endif not INCORE
E 9
   extern int numrefs;
E 7

/* doargs - read command argument line for both bib and listrefs
            set switch values
            call rdtext on file arguments, after dumping
            default style file if no alternative style is given
*/
   int doargs(argc, argv, defstyle)
   int argc;
   char **argv, defstyle[];
{  int numfiles, i, style;
   char *p, *q, *walloc();
   FILE *fd;

   numfiles = 0;
   style = true;
D 9
   words[0] = walloc("BMACLIB");
   defs[0]  = walloc(BMACLIB);
   wordtop++;
E 9
I 9
D 12
   wordstuff("BMACLIB", BMACLIB);
E 9
   fputs(".ds l] ",tfd);
   fputs(BMACLIB, tfd);
   fputs("\n", tfd);
E 12
I 12
   newbibdir(BMACLIB);
E 12

   for (i = 1; i < argc; i++)
      if (argv[i][0] == '-')
         switch(argv[i][1]) {
D 12

E 12
I 12
			case 'd':
				if (argv[i][2])
					p = &argv[i][2];
				else {  /* take next arg */
					i++;
					p = argv[i];
			}
			newbibdir(p);
E 12
D 2
            case 'a':  abbrev = true;
E 2
I 2
D 7
            case 'a':  for (p = &argv[i][2]; *p; p++) /* author */
                          if (*p == 'a')
E 7
I 7
            case 'a':  for (p = &argv[i][2]; *p; p++)
                          if (*p == 'a' || *p == 0)
E 7
                             abbrev = true;
                           else if (*p == 'x')
                             capsmcap = true;
                           else if (*p == 'r') {
                             if (*(p+1))
                                numrev = atoi(p+1);
                              else
                                numrev = 1000;
                              break;
                              }
E 2
                       break;

            case 'c':  if (argv[i][2] == 0)
D 9
                          error("citation string expected");
E 9
I 9
                          error("citation string expected for 'c'");
E 9
                       else
                          for (p = citetemplate,q = &argv[i][2]; *p++ = *q++; );
                       break;

            case 'e':  for (p = &argv[i][2]; *p; p++)
                          if (*p == 'a')
                             edabbrev = true;
                           else if (*p == 'x')
                             edcapsmcap = true;
                           else if (*p == 'r') {
                             if (*(p+1))
                                ednumrev = atoi(p+1);
                              else
                                ednumrev = 1000;
                              break;
                              }
                       break;

I 13
	    case 'l':  if (argv[i][2]){
                          max_klen  = atoi(&argv[i][2]);
			  if (max_klen > REFSIZE)
			      error("too long key size");
		       } else {
			  error("-l needs a numeric value");
		       }
		       break;

E 13
I 11
            case 'v':  doacite = false;
			/*FALLTHROUGH*/
E 11
            case 'f':  foot = true;
                       hyphen = false;
                       break;

            case 'h':  hyphen = ordcite = true;
                       break;

            case 'n':  for (p = &argv[i][2]; *p; p++)
                          if (*p == 'a')
                             abbrev = false;
I 11
                          else if (*p == 'v')
                             doacite = true;
E 11
                          else if (*p == 'f')
                             foot = false;
                          else if (*p == 'h')
                             hyphen = false;
                          else if (*p == 'o')
                             ordcite = false;
                          else if (*p == 'r')
                             numrev = 0;
                          else if (*p == 's')
                             sort = false;
                          else if (*p == 'x')
                             capsmcap = false;
                       break;

            case 'o':  ordcite = true;
                       break;

            case 'p':  if (argv[i][2])
                          p = &argv[i][2];
                       else {  /* take next arg */
                          i++;
                          p = argv[i];
                          }
                       strcpy(pfile, p);
                       personal = true;
                       break;

D 7
            case 'r':  if (argv[i][2] == 0)
E 7
I 7
            case 'r':  if (argv[i][2] == 0)  /* this is now replaced by -ar */
E 7
                          numrev = 1000;
                       else
                          numrev = atoi(&argv[i][2]);
                       break;

            case 's':  sort = true;
                       if (argv[i][2])
                          for (p = sortstr,q = &argv[i][2]; *p++ = *q++; );
                       break;

D 7
            case 'i':
            case 't':  if (argv[i][1] == 't')
                          style = false;
                       if (argv[i][2])
E 7
I 7
            case 't':  style = false;           /* fall through */
            case 'i':  if (argv[i][2])
E 7
                          p = &argv[i][2];
                       else { /* take next arg */
                          i++;
                          p = argv[i];
                          }
                       incfile(p);
                       break;

D 7
            case 'x':  capsmcap = true;
E 7
I 7
            case 'x':  capsmcap = true; /* this is now replaced by -ax */
E 7
                       break;

            case 0:    if (style) {  /* no style command given, take default */
                          style = false;
                          incfile( defstyle );
                          }
I 3
D 7
		       bibfname = "<stdin>";
E 7
I 7
                       strcpy(bibfname,"<stdin>");
E 7
E 3
                       rdtext(stdin);
                       numfiles++;
                       break;

            default:   fputs(argv[i], stderr);
D 9
                       error(": invalid switch");
E 9
I 9
                       error("'%c' invalid switch", argv[i][1]);
E 9
            }
      else { /* file name */
         numfiles++;
         if (style) {
            style = false;
            incfile( defstyle );
            }
         fd = fopen(argv[i], "r");
         if (fd == NULL) {
D 9
            fputs(argv[i], stderr);
            error(": can't open");
E 9
I 9
            error("can't open file %s", argv[i]);
E 9
            }
         else {
I 3
D 7
            bibfname = argv[i];
E 7
I 7
            strcpy(bibfname, argv[i]);
E 7
E 3
            rdtext(fd);
            fclose(fd);
            }
         }

   if (style) incfile( defstyle );
   return(numfiles);

}

I 12
newbibdir(name)
	char *name;
{
	strreplace(COMFILE, BMACLIB, name);
	strreplace(DEFSTYLE, BMACLIB, name);
	strcpy(BMACLIB, name);
	wordstuff("BMACLIB", BMACLIB);
	fprintf(tfd, ".ds l] %s\n", BMACLIB);
}

E 12
/* incfile - read in an included file  */
incfile(np)
   char *np;
{  char name[120];
   FILE *fd;
I 7
   char *p, line[LINELENGTH], dline[LINELENGTH], word[80], *tfgets();
D 10
   int  i, j, getwrd();
E 10
I 10
   int  i, getwrd();
E 10
E 7

I 7
   strcpy(bibfname, np);
E 7
   fd = fopen(np, "r");
   if (fd == NULL && *np != '/') {
      strcpy(name, "bib.");
      strcat(name, np);
I 7
      strcpy(bibfname, name);
E 7
      fd = fopen(name, "r");
      }
   if (fd == NULL && *np != '/') {
      strcpy(name,BMACLIB);
      strcat(name, "/bib.");
      strcat(name, np);
I 7
      strcpy(bibfname, name);
E 7
      fd = fopen(name, "r");
      }
   if (fd == NULL) {
D 7
      fprintf(stderr,"%s", np);
      error(": can't open");
E 7
I 7
      bibwarning("%s: can't open", np);
      exit(1);
E 7
      }
D 7
   setswitch(fd);
   fclose(fd);
}
E 7

D 7
/* error - report unrecoverable error message */
  error(str)
  char str[];
{
  fputs(str, stderr);
  putc('\n', stderr);
  exit(1);
}

/* tfgets - fgets which trims off newline */
   char *tfgets(line, n, ptr)
   char line[];
   int  n;
   FILE *ptr;
{  char *p;

   p = fgets(line, n, ptr);
   if (p == NULL)
      return(NULL);
   else
      for (p = line; *p; p++)
         if (*p == '\n')
            *p = 0;
   return(line);
}

/* getwrd - place next word from in[i] into out */
int getwrd(in, i, out)
   char in[], out[];
   int i;
{  int j;

   j = 0;
   while (in[i] == ' ' || in[i] == '\n' || in[i] == '\t')
      i++;
   if (in[i])
      while (in[i] && in[i] != ' ' && in[i] != '\t' && in[i] != '\n')
         out[j++] = in[i++];
   else
      i = 0;    /* signals end of in[i..]   */
   out[j] = 0;
   return (i);
}

/* walloc - allocate enough space for a word */
char *walloc(word)
   char *word;
{  char *i, *malloc();
   i = malloc(1 + strlen(word));
   if (i == NULL)
      error("out of storage");
   strcpy(i, word);
   return(i);
}

/* setswitch - set document switch settings from format file */
   setswitch(fp)
   FILE *fp;
{  char *p, line[LINELENGTH], dline[LINELENGTH], word[80];
   int  i, j, getwrd();

   while (tfgets(line, LINELENGTH, fp) != NULL)
E 7
I 7
   /* now go off and process file */
   biblineno = 1;
   while (tfgets(line, LINELENGTH, fd) != NULL) {
      biblineno++;
E 7
      switch(line[0]) {

         case '#': break;

D 2
         case 'A': abbrev = true;
E 2
I 2
         case 'A': for (p = &line[1]; *p; p++)
D 7
                      if (*p == 'A')
E 7
I 7
                      if (*p == 'A' || *p == '\0')
E 7
                         abbrev = true;
                      else if (*p == 'X')
                         capsmcap = true;
                      else if (*p == 'R') {
                         if (*(p+1))
                            numrev = atoi(p+1);
                         else
                            numrev = 1000;
                         break;
                         }
E 2
                   break;

         case 'C': for (p = &line[1]; *p == ' '; p++) ;
                   strcpy(citetemplate, p);
                   break;

         case 'D': if ((i = getwrd(line, 1, word)) == 0)
                      error("word expected in definition");
D 9
                   for (j = 0; j <= wordtop; j++)
                      if (strcmp(word, words[j]) == 0)
                         break;
                   if (j > wordtop) {
                      if ((j = ++wordtop) > MAXDEFS)
                         error("too many defintions");
                      words[wordtop] = walloc(word);
                      }
E 9
I 9
D 14
		   if (wordsearch(word))
E 14
I 14
		   if (wordsearch(word)) { /* already there-toss rest of def.*/
			while(line[strlen(line)-1] == '\\' ) {
                            if (tfgets(line, LINELENGTH, fd) == NULL) break;
			}
E 14
			break;
I 14
		   }
E 14
E 9
                   for (p = &line[i]; *p == ' '; p++) ;
                   for (strcpy(dline, p); dline[strlen(dline)-1] == '\\'; ){
                       dline[strlen(dline)-1] = '\n';
D 7
                       if (tfgets(line, LINELENGTH, fp) == NULL) break;
E 7
I 7
                       if (tfgets(line, LINELENGTH, fd) == NULL) break;
E 7
                       strcat(dline, line);
                       }
D 9
                   defs[j] = walloc(dline);
E 9
I 9
		   wordstuff(word, dline);
E 9
                   break;

         case 'E': for (p = &line[1]; *p; p++)
                      if (*p == 'A')
                         edabbrev = true;
                      else if (*p == 'X')
                         edcapsmcap = true;
                      else if (*p == 'R') {
                         if (*(p+1))
                            ednumrev = atoi(p+1);
                         else
                            ednumrev = 1000;
                         break;
                         }
                   break;

         case 'F': foot = true;
                   hyphen = false;
                   break;

         case 'I': for (p = &line[1]; *p == ' '; p++);
                   expand(p);
                   incfile(p);
                   break;

         case 'H': hyphen = ordcite = true;
                   break;

         case 'O': ordcite = true;
                   break;

D 7
         case 'R': if (line[1] == 0)
E 7
I 7
         case 'R': if (line[1] == 0)  /* this is now replaced by AR */
E 7
                      numrev = 1000;
                   else
                      numrev = atoi(&line[1]);
                   break;

         case 'S': sort = true;
                   for (p = &line[1]; *p == ' '; p++) ;
                   strcpy(sortstr, p);
                   break;

         case 'T': for (p = &line[1]; *p == ' '; p++) ;
                   strcpy(trailstr, p);
                   break;

D 7
         case 'X': capsmcap = true;
E 7
I 7
         case 'X': capsmcap = true;     /* this is now replace by AX */
E 7
                   break;

         default:  fprintf(tfd,"%s\n",line);
D 7
                   while (fgets(line, LINELENGTH, fp) != NULL)
E 7
I 7
                   while (fgets(line, LINELENGTH, fd) != NULL)
E 7
                      fputs(line, tfd);
                   return;
         }
D 7
   return;
E 7
I 7

   }
   /* close up */
   fclose(fd);
E 7
}

I 7
/* bibwarning - print out a warning message */
D 9
  bibwarning(msg, arg)
  char *msg, *arg;
E 9
I 9
  /*VARARGS1*/
  bibwarning(msg, a1, a2)
  char *msg;
E 9
{
  fprintf(stderr,"`%s', line %d: ", bibfname, biblineno);
D 9
  fprintf(stderr, msg, arg);
E 9
I 9
  fprintf(stderr, msg, a1, a2);
I 12
  fprintf(stderr, "\n");
E 12
E 9
}

/* error - report unrecoverable error message */
D 9
  error(str)
  char str[];
E 9
I 9
  /*VARARGS1*/
  error(str, a1, a2)
  char *str;
E 9
{
D 9
  bibwarning("%s\n", str);
  exit(1);
E 9
I 9
  bibwarning(str, a1, a2);
  /*
   *	clean up temp files and exit
   */
  cleanup(1);
E 9
}

I 9
#ifndef INCORE
E 9
#ifdef READWRITE
/*
** fixrfd( mode ) -- re-opens the rfd file to be read or write,
**      depending on the mode.  Uses a static int to save the current mode
**      and avoid unnecessary re-openings.
*/
fixrfd( mode )
register int mode;
{
	static int cur_mode = WRITE;    /* rfd open for writing initially */

	if (mode != cur_mode)
	{
		rfd = freopen(reffile, ((mode == READ)? "r" : "a"), rfd);
		cur_mode = mode;
		if (rfd == NULL)
D 9
		      error("Hell!  Couldn't re-open reference file");
E 9
I 9
		      error("Hell!  Couldn't re-open reference file %s",
			reffile);
E 9
	}
}
#endif
I 9
#endif not INCORE
E 9


/* tfgets - fgets which trims off newline */
   char *tfgets(line, n, ptr)
   char line[];
   int  n;
   FILE *ptr;
D 9
{  char *p;
E 9
I 9
{  reg char *p;
E 9

   p = fgets(line, n, ptr);
   if (p == NULL)
      return(NULL);
   else
      for (p = line; *p; p++)
         if (*p == '\n')
            *p = 0;
   return(line);
}

/* getwrd - place next word from in[i] into out */
int getwrd(in, i, out)
D 9
   char in[], out[];
   int i;
E 9
I 9
   reg char in[], out[];
   reg int i;
E 9
{  int j;

   j = 0;
   while (in[i] == ' ' || in[i] == '\n' || in[i] == '\t')
      i++;
   if (in[i])
      while (in[i] && in[i] != ' ' && in[i] != '\t' && in[i] != '\n')
         out[j++] = in[i++];
   else
      i = 0;    /* signals end of in[i..]   */
   out[j] = 0;
   return (i);
}

/* walloc - allocate enough space for a word */
char *walloc(word)
   char *word;
{  char *i, *malloc();
   i = malloc(1 + strlen(word));
   if (i == NULL)
      error("out of storage");
   strcpy(i, word);
   return(i);
}

E 7
/* isword - see if character is legit word char */
int iswordc(c)
char c;
{
   if (isalnum(c) || c == '&' || c == '_')
      return(true);
   return(false);
}
D 9

/* expand - expand reference, replacing defined words */
E 9
   expand(line)
   char *line;
D 9
{  char line2[REFSIZE], word[LINELENGTH], *p, *q, *w;
   int  replaced, i;
E 9
I 9
{  char line2[REFSIZE], word[LINELENGTH];
   reg	struct wordinfo *wp;
   reg	char *p, *q, *w;
D 10
   reg	int i;
E 10
E 9

D 9
   replaced  = true;
   while (replaced) {
      replaced = false;
      p = line;
      q = line2;
      while (*p) {
         if (isalnum(*p)) {
            for (w = word; *p && iswordc(*p); )
               *w++ = *p++;
            *w = 0;
            for (i = 0; i <= wordtop; i++)
               if (strcmp(word, words[i]) == 0) {
                  strcpy(word, defs[i]);
                  replaced = true;
                  break;
                  }
            for (w = word; *w; )
               *q++ = *w++;
            }
         else
            *q++ = *p++;
         }
      *q = 0;
      p = line;
      q = line2;
      while (*p++ = *q++);
      }
E 9
I 9
	q = line2;
	for (p = line; *p; /*VOID*/){
		if (isalnum(*p)) {
			for (w = word; *p && iswordc(*p); ) *w++ = *p++;
			*w = 0;
			if (wp = wordsearch(word)){
				strcpy(word, wp->wi_def);
				expand(word);
			}
			strcpy(q, word);
			q += strlen(q);
		} else {
			*q++ = *p++;
		}
	}
	*q = 0;
	strcpy(line, line2);
E 9
}

I 9
/* wordstuff- save a word and its definition, building a hash table */
   wordstuff(word, def)
   char *word, *def;
{
   int i;
   if (wordtop >= MAXDEFS)
	error("too many definitions, max of %d", MAXDEFS);
   words[wordtop].wi_length = strlen(word);
   words[wordtop].wi_word = word ? walloc(word) : 0;
   words[wordtop].wi_def = def ? walloc(def) : 0;
   i = strhash(word);
   words[wordtop].wi_hp = wordhash[i];
   wordhash[i] = &words[wordtop];
   wordtop++;
}
   struct wordinfo *wordsearch(word)
   char *word;
{
D 10
   reg int i;
E 10
   reg int lg;
   reg struct wordinfo *wp;
   lg = strlen(word);
   for (wp = wordhash[strhash(word)]; wp; wp = wp->wi_hp){
	if (wp->wi_length == lg && (strcmp(wp->wi_word, word) == 0)){
		return(wp);
	}
   }
   return(0);
}

   int strhash(str)
   reg char *str;
{
   reg int value = 0;
   for (value = 0; *str; value <<= 2, value += *str++)/*VOID*/;
   value %= HASHSIZE;
   if (value < 0)
	value += HASHSIZE;
   return(value);
}

E 9
I 7
/* rdref - read text for an already cited reference */
D 9
   rdref(i, ref)
   long int  i;
E 9
I 9
   rdref(p, ref)
   struct refinfo *p;
E 9
   char ref[REFSIZE];
{
   ref[0] = 0;
I 9
#ifndef INCORE
E 9
#ifdef READWRITE
   fixrfd( READ );                      /* fix access mode of rfd, if nec. */
#endif
D 9
   fseek(rfd, i, 0);
   fread(ref, 1, REFSIZE, rfd);
E 9
I 9
   fseek(rfd, p->ri_pos, 0);
   fread(ref, p->ri_length, 1, rfd);
#else INCORE
   strcpy(ref, p->ri_ref);
#endif INCORE
E 9
}

I 9
/* wrref - write text for a new reference */
   wrref(p, ref)
   struct refinfo *p;
   char ref[REFSIZE];
{
#ifndef INCORE
#ifdef READWRITE
    fixrfd( WRITE );                 /* fix access mode of rfd, if nec. */
#else
    fseek(rfd, p->ri_pos, 0);        /* go to end of rfd */
#endif
    fwrite(ref, p->ri_length, 1, rfd);
#else INCORE
   p->ri_ref = walloc(ref);
#endif INCORE
}

E 9
E 7
/* breakname - break a name into first and last name */
   breakname(line, first, last)
   char line[], first[], last[];
D 9
{  char *p, *q, *r, *t, *f;
E 9
I 9
{  reg char *t, *f, *q, *r, *p;
E 9

   for (t = line; *t != '\n'; t++);
   for (t--; isspace(*t); t--);

   /* now strip off last name */
   for (q = t; isspace(*q) == 0 || ((*q == ' ') & (*(q-1) == '\\')); q--)
      if (q == line)
         break;
   f = q;
D 7
   if (q != line)
E 7
I 7
   if (q != line) {
E 7
      q++;
I 7
      for (; isspace(*f); f--);
      f++;
      }
E 7

D 7
   for (; isspace(*f); f--);

E 7
   /* first name is start to f, last name is q to t */

D 7
   for (r = first, p = line, f++; p != f; )
E 7
I 7
   for (r = first, p = line; p != f; )
E 7
      *r++ = *p++;
   *r = 0;
   for (r = last, p = q, t++; q != t; )
      *r++ = *q++;
   *r = 0;
I 7

E 7
}

/* match - see if string1 is a substring of string2 (case independent)*/
   int match(str1, str2)
D 9
   char str1[], str2[];
{  int  i, j;
E 9
I 9
   reg char str1[], str2[];
{  reg int  j, i;
E 9
   char a, b;

   for (i = 0; str2[i]; i++) {
      for (j = 0; str1[j]; j++) {
         if (isupper(a = str2[i+j]))
            a = (a - 'A') + 'a';
         if (isupper(b = str1[j]))
            b = (b - 'A') + 'a';
         if (a != b)
            break;
         }
      if (str1[j] == 0)
         return(true);
      }
   return(false);
}

/* scopy - append a copy of one string to another */
   char *scopy(p, q)
D 9
   char *p, *q;
E 9
I 9
   reg char *p, *q;
E 9
{
   while (*p++ = *q++)
      ;
   return(--p);
}

I 7
/* rcomp - reference comparison routine for qsort utility */
   int rcomp(ap, bp)
D 9
   long int *ap, *bp;
E 9
I 9
   struct refinfo *ap, *bp;
E 9
{  char ref1[REFSIZE], ref2[REFSIZE], field1[MAXFIELD], field2[MAXFIELD];
D 9
   char *p, *q, *getfield();
E 9
I 9
   reg	char *p, *q;
   char *getfield();
E 9
   int  neg, res;
   int  fields_found;

D 9
   rdref(*ap, ref1);
   rdref(*bp, ref2);
E 9
I 9
   rdref(ap, ref1);
   rdref(bp, ref2);
E 9
   for (p = sortstr; *p; p = q) {
      if (*p == '-') {
         p++;
         neg = true;
         }
      else
         neg = false;
      q = getfield(p, field1, ref1);
      fields_found = true;
      if (q == 0) {
	 res = 1;
	 fields_found = false;
      } else if (strcmp (field1, "") == 0) {	/* field not found */
         if (*p == 'A') {
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

D 10
/* makecites - make citation strings */
E 10
I 10
/* makecites - make standard citation strings, using citetemplate currently in effect */
E 10
D 9
   makecites(citestr)
   char *citestr[];
E 9
I 9
   makecites()
E 9
{  char ref[REFSIZE], tempcite[100], *malloc();
D 9
   int  i;
E 9
I 9
   reg int  i;
E 9

D 9
   for (i = 0; i <= numrefs; i++) {
      rdref(refspos[i], ref);
E 9
I 9
   for (i = 0; i < numrefs; i++) {
      rdref(&refinfo[i], ref);
E 9
      bldcite(tempcite, i, ref);
D 9
      citestr[i] = malloc(2 + strlen(tempcite)); /* leave room for disambig */
      if (citestr[i] == NULL)
E 9
I 9
D 10
      refinfo[i].ri_cite = malloc(2 + strlen(tempcite)); /* leave room for disambig */
E 10
I 10
      refinfo[i].ri_cite = malloc(2 + strlen(tempcite));
E 10
      if (refinfo[i].ri_cite == NULL)
E 9
         error("out of storage");
D 9
      strcpy(citestr[i], tempcite);
E 9
I 9
      strcpy(refinfo[i].ri_cite, tempcite);
E 9
      }
}

/* bldcite - build a single citation string */
   bldcite(cp, i, ref)
   char *cp, ref[];
   int  i;
D 8
{  char *p, *q, c, *fp, field[REFSIZE], *getfield(), *aabet(), *astro();
E 8
I 8
D 9
{  char *p, *q, c, *fp, field[REFSIZE];
E 9
I 9
{  reg char *p, *q, *fp;
   char c;
   char field[REFSIZE];
E 9
D 13
   char *getfield(), *aabet(), *aabetlast(), *astro();
E 13
I 13
D 16
   char *getfield(), *aabet(), *aabetlast(), *fullaabet(), *astro();
E 16
I 16
   char *getfield(), *aabet(), *aabetlast(),
        *fullaabet(), *multfull();
E 16
E 13
E 8

   getfield("F", field, ref);
   if (field[0] != 0)
      for (p = field; *p; p++)
         *cp++ = *p;
   else {
      p = citetemplate;
      field[0] = 0;
      while (c = *p++) {
         if (isalpha(c)) {                      /* field name   */
            q = getfield(p-1, field, ref);
            if (q != 0) {
               p = q;
               for (fp = field; *fp; )
                  *cp++ = *fp++;
               }
            }
         else if (c == '1') {                   /* numeric  order */
            sprintf(field,"%d",1 + i);
            for (fp = field; *fp; )
               *cp++ = *fp++;
            }
         else if (c == '2')                     /* alternate alphabetic */
            cp = aabet(cp, ref);
         else if (c == '3')                     /* Astrophysical Journal style*/
D 16
            cp = astro(cp, ref);
E 16
I 16
            cp = multfull(cp, ref, 3);
         else if (c == '4')                     /* Computing Surveys style*/
            cp = multfull(cp, ref, 2);
E 16
I 13
	 else if (c == '8')			/* Full alphabetic */
	    cp = fullaabet(cp, ref);
E 13
I 8
         else if (c == '9')                     /* Last name of Senior Author*/
            cp = aabetlast(cp, ref);
I 11
	 else if (c == '0') {			/* print nothing */
            for (fp = field; *fp; )
               *cp++ = *fp++;
            }
E 11
E 8
/*       else if (c == '4')          here is how to add new styles */
         else if (c == '{') {                   /* other information   */
            while (*p != '}')
               if (*p == 0)
                  error("unexpected end of citation template");
               else
                  *cp++ = *p++;
            p++;
            }
         else if (c == '<') {
            while (*p != '>') {
               if (*p == 0)
                  error("unexpected end of citation template");
               else
                  *cp++ = *p++;
               }
            p++;
            }
         else if (c != '@')
            *cp++ = c;
         }
      }
   *cp++ = 0;
}

/* alternate alphabetic citation style -
        if 1 author - first three letters of last name
        if 2 authors - first two letters of first, followed by first letter of
                                seond
        if 3 or more authors - first letter of first three authors */
   char *aabet(cp, ref)
   char *cp, ref[];
D 9
{  char field[REFSIZE], temp[100], *np, *fp;
E 9
I 9
{  char field[REFSIZE], temp[100];
   reg char *np, *fp;
E 9
   int j, getname();

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
return(cp);
I 8
}
I 13

/* alternate alphabetic citation style -
	first two characters of last names of all authors
	up to max_klen characters.
*/
   char *fullaabet(cp, ref)
   char *cp, ref[];
{  char field[REFSIZE], temp[100];
   reg char	*fp;
   char	*lastcp;
   int getname();
   int i;

   lastcp = cp + max_klen;
   for (i= 1; getname(i, field, temp, ref); i++) {
      for (fp = field; *fp && (fp < &(field[3])); )
	 if (cp > lastcp)
	     break;
         else if (isalpha(*fp))
	     *cp++ = *fp++;
	 else
	     fp++;
   }
   return(cp);
}

E 13

/* alternate alphabetic citation style -
	entire last name of senior author
*/
   char *aabetlast(cp, ref)
   char *cp, ref[];
{  char field[REFSIZE], temp[100];
D 9
   char	*fp;
E 9
I 9
   reg char	*fp;
E 9
   int getname();

   if (getname(1, field, temp, ref)) {
      for (fp = field; *fp; )
         *cp++ = *fp++;
   }
   return(cp);
E 8
}

D 16
/* Astrophysical Journal style
E 16
I 16
/* 
  Multiple full authors last names (1, 2 or 3 full names).

  If maxauthors<3
E 16
        if 1 author - last name date
        if 2 authors - last name and last name date
I 16
        if 3 or more authors - last name et al. date
  If maxauthors>=3
        if 1 author - last name date
        if 2 authors - last name and last name date
E 16
        if 3 authors - last name, last name and last name date
        if 4 or more authors - last name et al. date */
D 16
   char *astro(cp, ref)
E 16
I 16
   char *multfull(cp, ref, maxauthors)
E 16
   char *cp, ref[];
I 16
   int maxauthors;
E 16
D 9
{  char name1[100], name2[100], name3[100], temp[100], *fp;
E 9
I 9
{  char name1[100], name2[100], name3[100], temp[100];
   reg char *fp;
E 9
   int getname();

   if (getname(1, name1, temp, ref)) {
      for (fp = name1; *fp; )
         *cp++ = *fp++;
D 16
      if (getname(4, name3, temp, ref)) {
         for (fp = " et al."; *fp; )
E 16
I 16
D 17
      if ((maxauthors >= 3) && (getname(4, name3, temp, ref))) {
E 17
I 17
      if (((maxauthors >= 3) && (getname(4, name3, temp, ref)))
	  || ((maxauthors < 3) && (getname(3, name3, temp, ref)))) {
E 17
         for (fp = " \\*(e]"; *fp; )
E 16
            *cp++ = *fp++;
         }
      else if (getname(2, name2, temp, ref)) {
         if (getname(3, name3, temp, ref)) {
            for (fp = "\\*(c]"; *fp; )
               *cp++ = *fp++;
            for (fp = name2; *fp; )
               *cp++ = *fp++;
            for (fp = "\\*(m]"; *fp; )
               *cp++ = *fp++;
            for (fp = name3; *fp; )
               *cp++ = *fp++;
            }
         else {
            for (fp = "\\*(n]"; *fp; )
               *cp++ = *fp++;
            for (fp = name2; *fp; )
               *cp++ = *fp++;
            }
         }
    }
return(cp);
}

/* getfield - get a single field from reference */
   char *getfield(ptr, field, ref)
   char *ptr, field[], ref[];
D 9
{  char *p, *q, temp[100];
E 9
I 9
{  reg	char *p, *q;
   char	temp[100];
E 9
   int  n, len, i, getname();

   field[0] = 0;
   if (*ptr == 'A')
      getname(1, field, temp, ref);
   else
      for (p = ref; *p; p++)
         if (*p == '%' && *(p+1) == *ptr) {
            for (p = p + 2; *p == ' '; p++)
               ;
            for (q = field; (*p != '\n') && (*p != '\0'); )
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
D 9
{  char *p;
E 9
I 9
{  reg char *p;
E 9
   int  m;

   m = n;
   for (p = ref; *p; p++)
      if (*p == '%' & *(p+1) == 'A') {
         n--;
         if (n == 0) {
            for (p = p + 2; *p == ' '; p++) ;
            breakname(p, first, last) ;
            return(true);
            }
         }

   if (n == m)          /* no authors, try editors */
      for (p = ref; *p; p++)
         if (*p == '%' & *(p+1) == 'E') {
            n--;
            if (n == 0) {
               for (p = p + 2; *p == ' '; p++) ;
               breakname(p, first, last) ;
               return(true);
               }
            }

   if (n == m) {        /* no editors, either, try institution */
      first[0] = last[0] = '\0';
      getfield("I", last, ref);
      if (last[0] != '\0')
         return(true);
      }

   return(false);
}

/* disambiguate - compare adjacent citation strings, and if equal, add
                  single character disambiguators */
   disambiguate()
D 9
{  int i, j;
E 9
I 9
{  reg int i, j;
E 9
D 10
   char adstr[2];

E 10
I 10
	char adstr;

E 10
D 14
   for (i = 0; i < numrefs; i = j) {
E 14
I 14
   for (i = 0; i < numrefs-1; i = j) {
E 14
      j = i + 1;
D 9
      if (strcmp(citestr[i], citestr[j])==0) {
E 9
I 9
      if (strcmp(refinfo[i].ri_cite, refinfo[j].ri_cite)==0) {
E 9
D 10
         adstr[0] = 'a'; adstr[1] = 0;
E 10
I 10
         adstr = 'a';
E 10
D 9
         for (j = i+1; strcmp(citestr[i],citestr[j]) == 0; j++) {
E 9
I 9
D 14
         for(j = i+1; strcmp(refinfo[i].ri_cite,refinfo[j].ri_cite) == 0; j++) {
E 14
I 14
         for(j = i+1;
	     j<numrefs && strcmp(refinfo[i].ri_cite,refinfo[j].ri_cite) == 0;
	     j++) {
E 14
E 9
D 10
            adstr[0] = 'a' + (j-i);
E 10
I 10
            adstr = 'a' + (j-i);
E 10
D 9
            strcat(citestr[j], adstr);
E 9
D 14
            if (j == numrefs)
               break;
E 14
I 9
D 10
            strcat(refinfo[j].ri_cite, adstr);
E 10
I 10
	    refinfo[j].ri_disambig[0] = adstr;
E 10
E 9
            }
D 10
         adstr[0] = 'a';
D 9
         strcat(citestr[i], adstr);
E 9
I 9
         strcat(refinfo[i].ri_cite, adstr);
E 10
I 10
	 refinfo[i].ri_disambig[0] = 'a';
E 10
E 9
         }
     }
I 10
  for (i = 0; i < numrefs; i++){
	strcat(refinfo[i].ri_cite, refinfo[i].ri_disambig);
  }
E 10
}


E 7
/* bldname - build a name field
             doing abbreviations, reversals, and caps/small caps
*/
   bldname(first, last, name, reverse)
   char *first, *last, name[];
   int reverse;
{
D 9
   char newfirst[120], newlast[120], *p, *q, *f, *l, *scopy();
E 9
I 9
   char newfirst[120], newlast[120];
   reg char *p, *q, *f, *l;
   char *scopy();
E 9
   int  flag;

   if (abbrev) {
      p = first;
      q = newfirst;
      flag = false;
      while (*p) {
         while (*p == ' ')
            p++;
         if (*p == 0)
            break;
         if (isupper(*p)) {
D 7
            if (flag)
E 7
I 7
            if (flag)           /* between initial gap */
E 7
               q = scopy(q, "\\*(a]");
            flag = true;
            *q++ = *p;
D 7
            *q++ = '.';
E 7
I 7
            q = scopy(q, "\\*(p]");
E 7
            }
         if (*++p == '.')
            p++;
         else while (*p != 0 && ! isspace(*p))
            p++;
         }
      *q = 0;
      f = newfirst;
      }
   else
      f = first;

   if (capsmcap) {
      p = last;
      q = newlast;
      flag = 0;  /* 1 - printing cap, 2 - printing small */
      while (*p)
         if (islower(*p)) {
            if (flag != 2)
               q = scopy(q, "\\s-2");
            flag = 2;
            *q++ = (*p++ - 'a') + 'A';
            }
         else {
            if (flag == 2)
               q = scopy(q,"\\s+2");
            flag = 1;
            *q++ = *p++;
            }
      if (flag == 2)
         q = scopy(q, "\\s+2");
      *q = 0;
      l = newlast;
      }
   else
      l = last;

D 7
   if (reverse)
      sprintf(name, "%s, %s\n", l, f);
E 7
I 7
   if (f[0] == 0)
      sprintf(name, "%s\n", l);
   else if (reverse)
      sprintf(name, "%s\\*(b]%s\n", l, f);
E 7
   else
      sprintf(name, "%s %s\n", f, l);
}

/* prtauth - print author or editor field */
   prtauth(c, line, num, max, ofd, abbrev, capsmcap, numrev)
   char c, *line;
   int  num, max, abbrev, capsmcap, numrev;
   FILE *ofd;
{  char first[LINELENGTH], last[LINELENGTH];

   if (num <= numrev || abbrev || capsmcap) {
      breakname(line, first, last);
      bldname(first, last, line, num <= numrev);
      }
   if (num == 1)
      fprintf(ofd,".ds [%c %s", c, line);
   else if (num < max)
      fprintf(ofd,".as [%c \\*(c]%s", c, line);
   else if (max == 2)
      fprintf(ofd,".as [%c \\*(n]%s", c, line);
   else
      fprintf(ofd,".as [%c \\*(m]%s", c, line);
   if (num == max && index(trailstr, c))
      fprintf(ofd,".ds ]%c %c\n", c, line[strlen(line)-2]);
}

/* doline - actually print out a line of reference information */
   doline(c, line, numauths, maxauths, numeds, maxeds, ofd)
   char c, *line;
   int numauths, maxauths, numeds, maxeds;
   FILE *ofd;
{

   switch(c) {
      case 'A':
          prtauth(c, line, numauths, maxauths, ofd, abbrev, capsmcap, numrev);
          break;

       case 'E':
          prtauth(c, line, numeds, maxeds, ofd, edabbrev, edcapsmcap, ednumrev);
          if (numeds == maxeds)
             fprintf(ofd,".nr [E %d\n", maxeds);
          break;

       case 'P':
          if (index(line, '-'))
             fprintf(ofd,".nr [P 1\n");
          else
             fprintf(ofd,".nr [P 0\n");
          fprintf(ofd,".ds [P %s",line);
          if (index(trailstr, 'P'))
             fprintf(ofd,".ds ]P %c\n",line[strlen(line)-2]);
          break;

       case 'F':
       case 'K': break;

       default:
          fprintf(ofd,".ds [%c %s", c, line);
          if (index(trailstr, c))
             fprintf(ofd,".ds ]%c %c\n", c, line[strlen(line)-2]);
          }
}

I 7
/* dumpref - dump reference number i */
   dumpref(i, ofd)
   int i;
   FILE *ofd;
D 9
{  char ref[REFSIZE], *p, line[REFSIZE];
E 9
I 9
{  char ref[REFSIZE], line[REFSIZE];
   reg char *p, *q;
   char *from;
E 9
   int numauths, maxauths, numeds, maxeds;

D 9
   rdref(refspos[i], ref);
E 9
I 9
D 16
   rdref(&refinfo[i], ref);
E 9
   maxauths = maxeds = 0;
   numauths = numeds = 0;
   for (p = ref; *p; p++)
      if (*p == '%')
         if (*(p+1) == 'A') maxauths++;
         else if (*(p+1) == 'E') maxeds++;
   fprintf(ofd, ".[-\n");
D 9
   fprintf(ofd, ".ds [F %s\n",citestr[i]);
   fseek(rfd, (long) refspos[i], 0);
E 9
I 9
   fprintf(ofd, ".ds [F %s\n", refinfo[i].ri_cite);
E 16
I 16
   if ( i < 0 ) ref[0] = 0; /* ref not found */
   else {
	   rdref(&refinfo[i], ref);
	   maxauths = maxeds = 0;
	   numauths = numeds = 0;
	   for (p = ref; *p; p++)
	      if (*p == '%')
	         if (*(p+1) == 'A') maxauths++;
	         else if (*(p+1) == 'E') maxeds++;
	   fprintf(ofd, ".[-\n");
	   fprintf(ofd, ".ds [F %s\n", refinfo[i].ri_cite);
E 16
#ifndef INCORE
D 16
   fseek(rfd, (long)refinfo[i].ri_pos, 0);
E 9
   while (fgets(line, REFSIZE, rfd) != NULL) {
E 16
I 16
	   fseek(rfd, (long)refinfo[i].ri_pos, 0);
	   while (fgets(line, REFSIZE, rfd) != NULL) {
E 16
D 9
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
E 9
I 9
#else INCORE
D 16
   for (q = line, from = refinfo[i].ri_ref; *from; /*VOID*/) { /*} */
	if (*from == '\n'){
		*q++ = '\n';
		*q = 0;
		q = line;
		from++;
	} else {
		*q++ = *from++;
		continue;
	}
E 16
I 16
	   for (q = line, from = refinfo[i].ri_ref; *from; /*VOID*/) { /*} */
		if (*from == '\n'){
			*q++ = '\n';
			*q = 0;
			q = line;
			from++;
		} else {
			*q++ = *from++;
			continue;
		}
E 16
#endif INCORE
D 16
	switch(line[0]){
	case 0:
		goto doneref;
	case '.':
		fprintf(ofd, "%s", line);
		break;
	case '%':
		switch(line[1]){
		case 'A':	numauths++;	break;
		case 'E':	numeds++;	break;
E 16
I 16
		switch(line[0]){
		case 0:
			goto doneref;
		case '.':
			fprintf(ofd, "%s", line);
			break;
		case '%':
			switch(line[1]){
			case 'A':	numauths++;	break;
			case 'E':	numeds++;	break;
			}
			for (p = &line[2]; *p == ' '; p++) /*VOID*/;
			doline(line[1], p, numauths, maxauths, numeds, maxeds, ofd);
E 16
		}
D 16
		for (p = &line[2]; *p == ' '; p++) /*VOID*/;
		doline(line[1], p, numauths, maxauths, numeds, maxeds, ofd);
	}
E 16
I 16
	   }
	   doneref:;
	   fprintf(ofd,".][\n");
E 16
   }
D 16
   doneref:;
E 9
   fprintf(ofd,".][\n");
E 16
}
E 7
E 1
