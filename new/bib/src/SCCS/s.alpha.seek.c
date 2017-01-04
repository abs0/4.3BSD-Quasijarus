h57991
s 00002/00001/00073
d D 2.2 83/09/23 15:44:22 garrison 5 3
c 
e
s 00003/00002/00072
d R 2.2 83/09/23 15:37:58 garrison 4 3
c Included changes from Arizona
e
s 00000/00000/00074
d D 2.1 83/06/22 14:23:31 garrison 3 2
c Make new release before sending it to Arizona for new changes.
e
s 00003/00001/00071
d D 1.2 83/06/14 16:46:30 rrh 2 1
c add sccs keywords per BSD conventions. Fix format strings so 
c pdp-11 style %D is now %ld, to not interact with sccs
e
s 00072/00000/00000
d D 1.1 83/06/06 11:37:07 garrison 1 0
c date and time created 83/06/06 11:37:07 by garrison
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
# include "streams.h"
# define  nexttry           ((high+low)/2)

/*  alpha_seek(stream, word, s_size, fold)
        seeks the first line in stream that is at least word.
    assumes that stream is a sorted file of lines.  (last char must be \n)
    if fold, assumes that word is lowercase and folds stream to lowercase.
    s_size = size of stream
    returns 1 if word = line, 0 o.w.
*/
int alpha_seek(stream, word, s_size, fold)
FILE *stream;
char *word;
long int s_size;
int  fold;
{   long int high, low, mid;    /*  point to beginning of a line in stream  */
    int      ans;               /*  line(low) < word <= line(high)          */
    char     line[maxstr];


    /*  initialize low (return if first line >= word)       */
        low= 0L;
        pos(low); getline(stream, line);
        if (fold) foldline(line);
        ans= strcmp(line,word);

        if ( ans >= 0)
        {   pos(low);   return(ans==0); }

    /*  initialize high to "line" after last line           */
        high= s_size;

    mid= nextline(stream, nexttry );
    while (mid < high )
    {   getline(stream,line);
        if (fold) foldline(line);
        if (strcmp(line,word) < 0)    low=  mid;
        else                          high= mid;
        mid= nextline(stream, nexttry );
    }

    /* linear search from low to high   */
        low= nextline(stream,low);
        for(;;)
        {   if (low>=high)      break;

            getline(stream,line);
            if (fold) foldline(line);
            ans=strcmp(line,word);

            if (ans>=0)         break;
            low= ftell(stream);
        }

    pos(low);
D 5
    if (low=high)   return(0);
E 5
I 5
    if (low==high)  return(0);
E 5
    else            return(ans==0);
}


/*  foldline(p):    change all uppercase to lowercase in string p
*/
foldline(p)
char *p;
{   for (; *p!=NULL;  p++)
    {   if (isupper(*p))    *p = tolower(*p);
    }
}
E 1
