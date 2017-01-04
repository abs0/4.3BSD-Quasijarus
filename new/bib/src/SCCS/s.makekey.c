h03249
s 00001/00000/00078
d D 2.2 83/09/23 15:45:25 garrison 5 3
c 
e
s 00002/00001/00077
d R 2.2 83/09/23 15:39:32 garrison 4 3
c Included changes from Arizona
e
s 00000/00000/00078
d D 2.1 83/06/22 14:24:46 garrison 3 2
c Make new release before sending it to Arizona for new changes.
e
s 00003/00001/00075
d D 1.2 83/06/14 16:47:34 rrh 2 1
c add sccs keywords per BSD conventions. Fix format strings so 
c pdp-11 style %D is now %ld, to not interact with sccs
e
s 00076/00000/00000
d D 1.1 83/06/06 11:37:25 garrison 1 0
c date and time created 83/06/06 11:37:25 by garrison
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
I 5
#
E 5
E 2

# include "stdio.h"
# include "ctype.h"
# include "bib.h"

char    commlist[MAXCOMM]=   /*  list of strings of common words         */
     "";
int firsttime = 1;

/*  makekey(p,max_klen,common):  compresses *p into a key
        folds upper to lower case.  ignores non-alphanumeric
        drops keys of length <= 1.
        drops words in common (name of file of words, one per line)
            (first call determines common for all later calls)
*/
makekey(p,max_klen,common)
char *p;
int  max_klen;          /* max key length */
char *common;
{   register char *from, *to, *stop;

    if (firsttime) {firsttime= 0; load_comm(common); }

    from= p; to= p; stop= max_klen+p;
    while (*from != NULL  &&  to < stop)
    {   if      (islower(*from))      *to++ = *from++;
        else if (isdigit(*from))      *to++ = *from++;
        else if (isupper(*from))    { *to++ = tolower(*from);  from++; }
        else                          from++;
    }
    *to= NULL;

    if (to<=p+1 ||
        lookup(commlist, p) )  *p= NULL;
}

/*  list is a string of null terminated strings, final string is null.
    p is a null terminated string.
    return 1 if p is a string in list, 0 ow.
*/
int lookup(list,p)
char *list, *p;
{   int len;
    len= strlen(list);
    while (len!=0 && strcmp(list,p)!=0)
    {   list += (len+1);
        len= strlen(list);
    }
    return(len!=0);
}

/*  read file common into commlist
*/
load_comm(common)
char *common;
{   FILE    *commfile;          /*  stream of common words                  */
    char *p, *stop;
    commfile= fopen(common,"r");
    if (commfile==NULL) fprintf(stderr, "cannot open '%s'\n", common);
    else
    {   /* read commfile into commlist  */
            p= commlist;    stop= commlist+MAXCOMM-1;
            while (p<stop && ((*p= getc(commfile))!=EOF))
            {   if (*p=='\n')   *p= NULL;
                p++;
            }
            if  (*p==EOF)  *p= NULL;
            else
            {   fprintf(stderr, "invert: too many common words\n");
                commlist[0]= NULL;
            }
        fclose(commfile);
    }
}

E 1
