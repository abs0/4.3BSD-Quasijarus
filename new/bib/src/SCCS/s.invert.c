h49148
s 00005/00005/00195
d D 2.6 87/03/05 20:21:54 garrison 11 10
c rename tmpfile to bibtmpfile to avoid apparent name clash on suns
c (mlvdv)
e
s 00001/00001/00199
d D 2.5 85/09/10 12:38:47 mckusick 10 9
c bmac moves to /usr/new/lib
e
s 00001/00000/00199
d D 2.4 84/10/23 09:12:12 ralph 9 8
c fix exit code (0).
e
s 00016/00002/00183
d D 2.3 84/10/12 17:41:45 rrh 8 6
c add -d flag to all programs, to change the /usr/lib/bmac directory 
e
s 00016/00002/00183
d R 2.3 84/10/12 17:33:57 rrh 7 6
c add -d flag to all programs, to change the /usr/lib/bmac directory 
c to whatever the user wants; default is /usr/lib/bmac
e
s 00009/00009/00176
d D 2.2 83/10/06 17:23:32 garrison 6 3
c fixed formats on new version so as not to conflict with
c SCCS keywords
e
s 00009/00009/00176
d R 2.2 83/10/06 14:33:02 garrison 5 3
c 
e
s 00010/00010/00175
d R 2.2 83/09/23 15:38:58 garrison 4 3
c Included changes from Arizona
e
s 00000/00000/00185
d D 2.1 83/06/22 14:24:20 garrison 3 2
c Make new release before sending it to Arizona for new changes.
e
s 00012/00009/00173
d D 1.2 83/06/14 16:47:06 rrh 2 1
c add sccs keywords per BSD conventions. Fix format strings so 
c pdp-11 style %D is now %ld, to not interact with sccs
e
s 00182/00000/00000
d D 1.1 83/06/06 11:37:16 garrison 1 0
c date and time created 83/06/06 11:37:16 by garrison
e
u
U
t
T
I 1
D 2
#
E 2
I 2
#ifndef lint
static char sccsid[] = "%W%	%G%";
#endif not lint
D 6

E 6
I 6
#
E 6
E 2
/*  input:  records of lines, separated by blank lines
    output: key:file1 start/length ... start/length:file2 start/length ...
*/

# include "stdio.h"
# include "streams.h"
# include "bib.h"
# define isnull(x)  (*(x) == NULL)
# define makelow(c) ('A'<=(c) && (c)<='Z' ? (c)-'A'+'a' : c)

int     max_kcnt = 100;     /*  max number of keys                      */
int     max_klen =   6;     /*  max length of keys                      */
char    *ignore =           /*  string of line starts to ignore         */
            "CNOPVX";
char    *common =           /*  name of file of common words            */
            COMFILE;
char    *INDEX=             /*  name of output file                     */
            INDXFILE;

D 11
char    *tmpfile =          /*  name of temporary file                  */
E 11
I 11
char    *bibtmpfile =          /*  name of temporary file                  */
E 11
            INVTEMPFILE;

int	silent = 0;	    /*  0 => statistics printed			*/
			    /*  1 => no statisitics printed		*/

char *sort_it =
        "sort -u +0 -1 +1 -2 +2n -3 +3n %s -o %s";
char sortcmd[maxstr];

int     argc;
char    **argv;

main(argcount,arglist)
int argcount;
char **arglist;
{   char            *filename;
    FILE            *input, *output;
    long int        start,length;
    char            word[maxstr];
    int             kcnt;
    char            tag_line[maxstr];

    long int	    records = 0;  /*  number of records read           */
    long int	    keys    = 0;  /*  number of keys read (occurences) */
    long int	    distinct;     /*  number of distinct keys          */
    long int	    shorten();

I 8
    strcpy(COMFILE, N_COMFILE);
    strcpy(BMACLIB, N_BMACLIB);

E 8
    argc= argcount-1;
    argv= arglist+1;
D 11
    mktemp(tmpfile);
    output= fopen(tmpfile,"w");
E 11
I 11
    mktemp(bibtmpfile);
    output= fopen(bibtmpfile,"w");
E 11

    for ( flags() ; argc>0 ; argc--, argv++ ,flags() )
    {   /* open input file              */
            filename=   *argv;
            input=      fopen(filename,"r");
            if (input==NULL)
            {   fprintf(stderr, "invert: error in open of %s\n", filename);
                continue;
            }
            start=      0L;
            length=     0L;

        for(;;) /* each record  */
        {   /* find start of next record (exit if none)     */
                start= nextrecord(input,start+length);
                if (start==EOF)   break;
            records++;
	    kcnt= 0;
            length= recsize(input,start);
D 2
            sprintf(tag_line, " %s %D %D\n", filename, start, length);
E 2
I 2
D 6
            sprintf(tag_line, " %s %ld %ld\n", filename, start, length);
E 6
I 6
            sprintf(tag_line, " %s %d %d\n", filename, start, length);
E 6
E 2

            while (ftell(input) < start+length && kcnt < max_kcnt)
            {   getword(input,word,ignore);
                makekey(word,max_klen,common);
                if (!isnull(word))
                {   fputs(word,output); fputs(tag_line,output);
                    kcnt++; keys++;
                }
            }
        }
        fclose(input);
    }
    fclose(output);

D 11
    sprintf(sortcmd, sort_it, tmpfile, tmpfile);
E 11
I 11
    sprintf(sortcmd, sort_it, bibtmpfile, bibtmpfile);
E 11
    system(sortcmd);

D 11
    distinct = shorten(tmpfile,INDEX);
E 11
I 11
    distinct = shorten(bibtmpfile,INDEX);
E 11
    if( silent == 0 )
	fprintf(stderr,
D 2
	    "%D documents   %D distinct keys  %D key occurrences\n",
E 2
I 2
D 6
	    "%ld documents   %ld distinct keys  %ld key occurrences\n",
E 6
I 6
	    "%d documents   %d distinct keys  %d key occurrences\n",
E 6
E 2
	    records, distinct, keys);
I 9
    exit(0);
E 9
}



/*  Flag    Meaning                             Default
    -ki     Keys per record                     100
    -li     max Length of keys                  6
    -%str   ignore lines that begin with %x     CNOPVX
            where x is in str
            str is a seq of chars
D 8
    -cfile  file contains Common words          /usr/src/local/bib/common
E 8
I 8
D 10
    -cfile  file contains Common words          /usr/lib/bib/common
E 10
I 10
    -cfile  file contains Common words          /usr/new/lib/bib/common
E 10
E 8
            do not use common words as keys
    -pfile  name of output file                 INDEX
    -s	    do not print statistics		statistics printed
*/

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
        {   case 'k':   max_kcnt= atoi(operand);
                        break;
            case 'l':   max_klen= atoi(operand);
                        break;
            case 'c':   common=  operand;
                        break;
            case '%':   ignore=  *argv+2;
                        break;
            case 'p':   INDEX=  operand;
                        break;
	    case 's':	silent= 1;
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
            default:    fprintf(stderr, "unknown flag '%s'\n", *argv);
        }
    }
}


/*  shorten(inf,outf): file "inf" consists of lines of the form:
        key file start length
    sorted by key and file.  replace lines with the same key
    with one line of the form:
        key:file1 start/length ... start/length:file2 start/length ...
    rename as file "outf"
    returns number of lines in output
*/
long shorten(inf,outf)
char *inf, *outf;
{   FILE *in, *out;
    char line[maxstr];
    char key[maxstr],  newkey[maxstr],
         file[maxstr], newfile[maxstr];
    long int start, length;
    long int lines = 0;

    in=  fopen(inf, "r");
    out= fopen(outf, "w");
    if (in==NULL || out==NULL)
    {   fprintf(stderr, "invert: error in opening file for compression\n");
        return(0);
    }

    getline(in,line);
D 2
    sscanf(line,"%s%s%D%D", key, file, &start, &length);
    fprintf(out, "%s :%s %D/%D", key, file, start, length);
E 2
I 2
D 6
    sscanf(line,"%s%s%ld%ld", key, file, &start, &length);
    fprintf(out, "%s :%s %ld/%ld", key, file, start, length);
E 6
I 6
    sscanf(line,"%s%s%d%d", key, file, &start, &length);
    fprintf(out, "%s :%s %d/%d", key, file, start, length);
E 6
E 2
    for ( getline(in, line) ; !feof(in);  getline(in, line))
D 2
    {   sscanf(line,"%s%s%D%D", newkey, newfile, &start, &length);
E 2
I 2
D 6
    {   sscanf(line,"%s%s%ld%ld", newkey, newfile, &start, &length);
E 6
I 6
    {   sscanf(line,"%s%s%d%d", newkey, newfile, &start, &length);
E 6
E 2
        if (strcmp(key,newkey)!=0)
        {   strcpy(key, newkey);
            strcpy(file, newfile);
D 2
            fprintf(out, "\n%s :%s %D/%D",  key, file, start, length);
E 2
I 2
D 6
            fprintf(out, "\n%s :%s %ld/%ld",  key, file, start, length);
E 6
I 6
            fprintf(out, "\n%s :%s %d/%d",  key, file, start, length);
E 6
E 2
	    lines++;
        }
        else if (strcmp(file,newfile)!=0)
        {   strcpy(file,newfile);
D 2
            fprintf(out, ":%s %D/%D", file, start, length);
E 2
I 2
D 6
            fprintf(out, ":%s %ld/%ld", file, start, length);
E 6
I 6
            fprintf(out, ":%s %d/%d", file, start, length);
E 6
E 2
        }
        else
D 2
            fprintf(out, " %D/%D", start, length);
E 2
I 2
D 6
            fprintf(out, " %ld/%ld", start, length);
E 6
I 6
            fprintf(out, " %d/%d", start, length);
E 6
E 2
    }
    fprintf(out, "\n");
    lines++;

    fclose(in); fclose(out);
    unlink(inf);
    return (lines);
}
E 1
