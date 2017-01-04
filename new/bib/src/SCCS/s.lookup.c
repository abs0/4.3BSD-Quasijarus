h19270
s 00014/00005/00087
d D 2.5 85/06/10 06:23:13 garrison 9 8
c added 'A' flag. 
c prints all the hits in all the bib indexes.
e
s 00016/00001/00076
d D 2.4 84/10/12 17:41:52 rrh 8 6
c add -d flag to all programs, to change the /usr/lib/bmac directory 
e
s 00013/00000/00077
d R 2.4 84/10/12 17:34:11 rrh 7 6
c add -d flag to all programs, to change the /usr/lib/bmac directory 
c to whatever the user wants; default is /usr/lib/bmac
e
s 00003/00000/00074
d D 2.3 84/01/24 07:45:00 rrh 6 5
c add -f flag to lookup that prints out the reference file containing
c the citation
e
s 00000/00004/00074
d D 2.2 83/09/23 15:45:18 garrison 5 3
c 
e
s 00001/00005/00073
d R 2.2 83/09/23 15:39:24 garrison 4 3
c Included changes from Arizona
e
s 00000/00000/00078
d D 2.1 83/06/22 14:24:43 garrison 3 2
c Make new release before sending it to Arizona for new changes.
e
s 00004/00000/00074
d D 1.2 83/06/14 16:47:30 rrh 2 1
c add sccs keywords per BSD conventions. Fix format strings so 
c pdp-11 style %D is now %ld, to not interact with sccs
e
s 00074/00000/00000
d D 1.1 83/06/06 11:37:23 garrison 1 0
c date and time created 83/06/06 11:37:23 by garrison
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
# include "stdio.h"
# include "streams.h"
# include "bib.h"

char *locate();

I 6
int     fflag =   0;        /*  print out file names                    */
I 9
int     Aflag =   0;        /*  print hits from All indexes 		*/
E 9
E 6
int     max_klen =   6;     /*  max length of keys                      */
char    *common =           /*  name of file of common words            */
            COMFILE;
char    INDEX[maxstr] =     /*  name of index file                      */
            INDXFILE;

int     argc;
char    **argv;

main(argcount,arglist)
int argcount;
char **arglist;
{   char *refs;
    char keys[maxstr];
    char *p,*q;
    char one_index[maxstr];
I 9
    int found;
E 9

I 8
    strcpy(BMACLIB, N_BMACLIB);
    strcpy(COMFILE, N_COMFILE);
    strcpy(DEFSTYLE, N_DEFSTYLE);

E 8
    argc= argcount-1;
    argv= arglist+1;
    flags();

    /*  add SYSINDEX to search path.  all names are comma terminated */
	strcat(INDEX, ",");
	strcat(INDEX, SYSINDEX);
	strcat(INDEX, ",");

    while (fgets(keys,maxstr,stdin)!=NULL)
D 9
    {   for (p = one_index, q = INDEX; *q != 0 ; q++)
E 9
I 9
    {	found = 0;
	for (p = one_index, q = INDEX; *q != 0 ; q++)
E 9
	    if (*q == ',' )
	    {   *p = 0;
	        refs = locate(keys, one_index, max_klen, common);
		if( refs==NULL )
		{   fprintf(stderr,
			"%s removed from index list.\n", one_index);
		    /* delete this file name (shift remainder on top) */
			strcpy(q-strlen(one_index),q+1);
			q = q-strlen(one_index)-1;
		}
D 9
                if (refs!=NULL && *refs!=NULL) break;
E 9
I 9
                if (refs!=NULL && *refs!=NULL)
		{
		    printf("%s", refs);
		    free(refs);
		    found = 1;
		    if (!Aflag) break;
		}
E 9
	        p = one_index;
	    }
	    else *p++ = *q;

D 9
        if (refs==NULL || *refs==NULL)  printf("No references found.\n");
        else                            printf("%s", refs);
        if (refs!=NULL) free(refs);
E 9
I 9
        if (!found)  printf("No references found.\n");
E 9
    }
    exit(0);
}
D 5
int fileflag;
E 5

# define    operand     (strlen(*argv+2)==0 ? (argv++,argc--,*argv) : *argv+2)

flags()
D 8
{   for (; argc>0 && *argv[0]=='-';  argc--,argv++)
E 8
I 8
{
    char *p;
    for (; argc>0 && *argv[0]=='-';  argc--,argv++)
E 8
    {   switch ((*argv)[1])
        {   case 'l':   max_klen= atoi(operand);
                        break;
I 6
	    case 'f':	fflag++;
			break;
E 6
            case 'c':   common=  operand;
                        break;
I 9
	    case 'A':	Aflag++;
			break;
E 9
            case 'p':   strcpy(INDEX,operand);
                        break;
I 8
	    case 'd':
		p = &argv[0][2];
		if (!p) { 
			argv++;
			p = &argv[0][0];
		}
		strreplace(COMFILE, BMACLIB, p);
		strcpy(BMACLIB, p);
		break;
E 8
D 5
	    case 'f':	fileflag = 1;
			break;
E 5
            default:    fprintf(stderr, "unknown flag '%s'\n", *argv);
        }
    }
}
E 1
