h05417
s 00001/00001/00232
d D 2.6 87/03/05 17:43:43 garrison 9 8
c ls -l locate.
e
s 00005/00003/00228
d D 2.5 85/06/11 16:47:19 garrison 8 7
c corrected memory allocation count using fflag option (mlvdv)
e
s 00004/00004/00227
d D 2.4 85/06/10 06:20:54 garrison 7 6
c fixed botches with the memory allocation.
e
s 00010/00000/00221
d D 2.3 84/01/24 07:44:52 rrh 6 5
c add -f flag to lookup that prints out the reference file containing
c the citation
e
s 00014/00020/00207
d D 2.2 83/09/23 15:45:06 garrison 5 3
c 
e
s 00015/00021/00206
d R 2.2 83/09/23 15:39:13 garrison 4 3
c Included changes from Arizona
e
s 00000/00000/00227
d D 2.1 83/06/22 14:24:38 garrison 3 2
c Make new release before sending it to Arizona for new changes.
e
s 00003/00004/00224
d D 1.2 83/06/14 16:47:21 rrh 2 1
c add sccs keywords per BSD conventions. Fix format strings so 
c pdp-11 style %D is now %ld, to not interact with sccs
e
s 00228/00000/00000
d D 1.1 83/06/06 11:37:21 garrison 1 0
c date and time created 83/06/06 11:37:21 by garrison
e
u
U
t
T
I 1
D 2
#
E 2
#ifndef lint
D 2
static char sccsid[] = "%Z%%M% %I% %G%";
#endif lint
E 2
I 2
static char sccsid[] = "%W%	%G%";
#endif not lint
I 5
#
E 5
E 2

# include   "stdio.h"
# include   "streams.h"
# include   "ctype.h"
D 9
# define    maxrefs      200
E 9
I 9
# define    maxrefs      1000
E 9

struct reftype{
D 5
    char reffile[64];		/* rrh: still may be too short */
E 5
I 5
    char reffile[maxstr];
E 5
    long int start, length;
    };

D 7
char *malloc();
E 7
I 7
char *calloc();
E 7
char *rindex();
char *stripkeys();
int   fetchref();
D 5
int fileflag;
E 5

/*  locate(keys, name, max_klen, common):
        Returns a string containing all references pointed to by name
        that contain all keys in keys.  Common is name of common word file.
D 7
    Pointer returned comes from malloc.  Use free to return storage.
E 7
I 7
    Pointer returned comes from calloc.  Use free to return storage.
E 7
    NB A zero length string returned if nothing is found.
       A NULL pointer indicates an error accessing the file "name".
*/
I 6
int fflag;	/* set if want the reference string to have the file name*/
E 6
char *locate(keys,name,max_klen,common)
char *keys, *name, *common;
int  max_klen;          /* max key length */
{   static  char oldname[maxstr] = "";  /* oldname is name of stream index */
    static  FILE *index = NULL;
    static  long int i_size;            /* size of index                   */
    static  char oldtext[maxstr];       /* oldtext is the path to stream   */
D 5
    static  char workbuf[10240];	/* work buffer */
E 5
    static  FILE *text = NULL;		/*  text.  if it is a relative     */
    static  int  pathlen;		/*  path, it is relative to index  */
					/*  directory.                     */
					/* oldname[0..pathlen-1] is index  */
					/*  directory                      */
    int  len;
    char key[maxstr];                   /* refs[i] is a line of index for  */
    struct reftype  refs[maxrefs];      /* all keys up to key              */

    int  refcnt, copied, comp;          /* refcnt = # of refs               */
                                        /* copied = # of refs copied        */
                                        /* comp   = # of refs compared      */
    struct reftype ref;
    char   str[maxstr];
    int    more;

    long int ans;
    int i,j;
    unsigned total;
    char *allrefs, *next;               /* all refs (separated by null line)*/
    char *p;

    /*  open index */
        if  (strcmp(oldname,name)!=0)
        {   if (index) fclose(index);
            if (text) fclose(text);
            strcpy(oldname,name);
            strcpy(oldtext,"");
            /*  determine pathlen   */
                p= rindex(oldname, '/');
                if      (p!=NULL)           pathlen= p-oldname+1;
                else                        pathlen= 0;

            index= fopen(oldname,"r");
            if (index==NULL)
            {   fprintf(stderr, "locate: cannot open %s\n", oldname);
		strcpy(oldname, "");
                return(NULL);
            }
            else
            {   fseek(index,0L,2);     /*  seeks last newline      */
                i_size= ftell(index);
            }

        }

    /*  load references to first key  */
        keys= stripkeys(keys,key, max_klen, common);
	if (*key==NULL)
	{ fprintf(stderr,"locate: no keys for citation\n");
D 7
	  allrefs = malloc(1);
E 7
I 7
	  allrefs = (char *) calloc(1, sizeof (char));
E 7
	  if (allrefs==NULL)
	  {  fprintf(stderr, 
	       "locate: insufficient space for references\n");
	     exit(1);
	  }
	  *allrefs= NULL;
	  return(allrefs);
	}
        len= strlen(key);
        strcat(key," ");
        alpha_seek(index, key, i_size, 0);
        key[len]= NULL;                     /*  strip blank off */

        refcnt= 0;
        fscanf(index,"%s ", str);
        if (strcmp(str,key) == 0)
        {   str[0]= NULL;
            while (refcnt < maxrefs && fetchref(index, str, &ref) )
            {   refs[refcnt]= ref;
                refcnt++;
            }
        }

        if (refcnt==maxrefs)
            fprintf(stderr,
		"locate: first key (%s) matched too many refs\n", key);

    /*  intersect the reference sets for remaining keys with first set */
        while (*keys!=NULL)
        {   keys= stripkeys(keys, key, max_klen, common);
            if (*key==NULL) continue;

            len= strlen(key);
            strcat(key," ");
            alpha_seek(index, key, i_size, 0);
            key[len]= NULL;

            fscanf(index,"%s ", str);
            if (strcmp(str,key) != 0)  refcnt= 0;   /*  no matching refs */

            copied= 0; comp= 0; more= fetchref(index, str, &ref);
            while (comp < refcnt && more)
            {   /*  ans= ref-refs[comp]    */
                    ans= strcmp(ref.reffile, refs[comp].reffile);
                    if (ans==0)     ans= ref.start-refs[comp].start;
                    if (ans==0)     ans= ref.length-refs[comp].length;
                if (ans<0)  more= fetchref(index, str, &ref);
                if (ans==0) { refs[copied]= refs[comp]; comp++; copied++;
                              more= fetchref(index, str, &ref);}
                if (ans>0)  comp++;
            }

            refcnt= copied;
        }

D 5
    /* copy refs into the work buffer */
        next= workbuf;
E 5
I 5
    total= 0;
D 8
    for (i=0; i<refcnt; i++)    total += refs[i].length+1;
I 6
    if (fflag){
	total += strlen(refs[i].reffile) + 1;
E 8
I 8
    for (i=0; i<refcnt; i++) {
        total += refs[i].length+1;
        if (fflag){
	    total += strlen(refs[i].reffile) + 1;
        }
E 8
    }
E 6

D 7
    allrefs= malloc(total+1);
E 7
I 7
    allrefs= (char *) calloc(total+1, sizeof (char));
E 7
    if (allrefs==NULL)
    {   fprintf(stderr, "locate: insufficient space for references\n");
	exit(1);
    }

    /* copy refs into allrefs */
        next= allrefs;
E 5
        for (i=0; i<refcnt; i++)
        {   /*  open text */
                if (strcmp(oldtext,refs[i].reffile) != 0)
                {   strcpy(oldtext,refs[i].reffile);
		    if (oldtext[0]=='/')
		    {   /* absolute path */
			strcpy(str,oldtext);
		    } else
		    {   /* relative name */
			strncpy(str, oldname, pathlen);  str[pathlen]= NULL;
			strcat(str, oldtext);
		    }
                    if (text) fclose(text);
                    text= fopen(str, "r");
                    if (text==NULL)
                    {   fprintf(stderr, "locate: cannot open %s\n", str);
			strcpy(oldtext, "");
                        return(NULL);
                    }
                }
            fseek(text, refs[i].start, 0);
I 6
	    if (fflag){
		strcat(next, refs[i].reffile);
		next += strlen(next);
		*next++ = '\n';
		*next = 0;
	    }
E 6
D 5
	    {
		register char *from;
		if (fileflag){
			from = oldtext;
			while(*next++ = *from++) /*VOID*/ ;
			next[-1] = '\n';
		}
	    }
E 5
            for (j=0; j<refs[i].length; j++)    *next++ = getc(text);
            *next++ = '\n';
        }
        *next = NULL;
D 5
    allrefs = malloc(strlen(workbuf) + 1);
    if (allrefs == NULL) {
	fprintf(stderr, "No space left for allrefs\n");
	exit(1);
    }
    strcpy(allrefs, workbuf);
E 5
    return(allrefs);
}



/*  stripkeys(line,key,max_klen, common):
        assigns to key the first key in line
        and returns a pointer to the position following the key
*/
char *stripkeys(line,key,max_klen,common)
char *line, *key;
int  max_klen;
char *common;
{   char *p;

    do
    {   while (isspace(*line))   line++;

        p= key;
        while (*line!=NULL && !isspace(*line))
        {   *p++ = *line++;
        }
        *p= NULL;

        makekey(key, max_klen, common);
    }   while (*key==NULL && *line!=NULL);
    return(line);
}

/*  read a reference pair from stream into *ref.  if file not given,
    use oldfile. return 1 if pair found, 0 ow.
*/
int fetchref(stream, oldfile, ref)
FILE *stream;
char *oldfile;
struct reftype *ref;
{   char cntl;

    fscanf(stream, "%c", &cntl);
    if (cntl=='\n') {return (0);}
    if (cntl==':')  fscanf(stream, "%s", oldfile);
    strcpy(ref->reffile, oldfile);
D 2
    fscanf(stream, "%D/%D", &ref->start, &ref->length);
E 2
I 2
D 5
    fscanf(stream, "%ld/%ld", &ref->start, &ref->length);
E 5
I 5
    fscanf(stream, "%D/%D", &ref->start, &ref->length);
E 5
E 2
    return(1);
}
E 1
