h49795
s 00001/00001/00241
d D 4.2 87/04/06 12:16:32 bostic 2 1
c printf format/argument mismatch
e
s 00242/00000/00000
d D 4.1 83/02/11 15:44:08 rrh 1 0
c date and time created 83/02/11 15:44:08 by rrh
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include <stdio.h>
#include "1.incl.h"
#include "1.defs.h"
#include"def.h"

extern int match[], symclass[],  action[], newstate[];
extern char symbol[];
long *hashtab;
int *value, *chain;

extern FILE *infd;


parse()
	{int i,j,found,current, someread;
	char c;

	hash_init();
	routinit();
	line_init();

	someread = 0;			/* indicates haven't read part of a routine */

	empseek(0);
	endbuf = getline(&endline, &endchar, &endcom, & comchar);
	if (progress && endbuf != -1) fprintf(stderr,"parsing\n");
	while(endbuf != -1)			/* getline returns -1 when no more input */
		{
		someread = 1;
		if (progress > 0)
			{
			for (i = begline; i <= endline; i++)
				if (!(i % progress)) fprintf(stderr,"parsing line %d\n",i);
			}
		current = 0;
		for (i = 0; i < endbuf; i++)
			{

			c = buffer[i];
			if(c != '~') 
				{
				found = 0;
				if ( (current < 0 || current >= snum) && current != ABORT)
					{
					strerr("in parsing:","","");
D 2
					fprintf(stderr,"line %d of file, parser in invalid state", begline,current);
E 2
I 2
					fprintf(stderr,"line %d of file, parser in invalid state", current);
E 2
					fprintf(stderr,"treating it as straight line code\n");
					current = ABORT;
					}
				else
					for (j = match[current];  j < match[current + 1]; j++)
						{
						if ((symclass[j] == 0 && c == symbol[j]) ||
						    (symclass[j] != 0 && classmatch(c,symclass[j]) ))
							{found = 1;  break;
							}
						}
				if (!found)
					{
					error("in syntax:","","");
					fprintf(stderr,"between lines %d and %d of file\n",begline, endline);
					if (debug)
					fprintf(stderr,"symbol '%c' does not match entries for state %d\n",c,current);
					fprintf(stderr,"treating it as straight line code\n");
					current = ABORT;
					}
				else if (!action[j])  
					current = newstate[j];
				else
					{
					current = act(action[j],c,i);
					if (current == nulls)  current = newstate[j];
					}
				if (current == ABORT)  break;
				if (current == endrt)
					{
					return(1);
					}
				}
			}
		line_init();
		endbuf = getline(&endline, &endchar, &endcom,&comchar);
		}
	if (someread) return(1);
	else return(0);
	}


hash_init()
	{
	int i;
	hashtab = challoc(sizeof(*hashtab) * maxhash);
	chain = challoc(sizeof(*chain) * maxhash);
	value = challoc(sizeof(*value) * maxhash);
	for (i = 0; i < maxhash; i++)
		{
		hashtab[i] = -1L;
		value[i] = -2;
		chain[i] = 0;
		}
	}


hash_check()
	{
	int i;
	for (i = 0; i < maxhash; ++i)
		if (value[i] == -2 && hashtab[i] != -1L)
			{
			error("in syntax; label used but does not appear as statement label:","","");
			fprintf(stderr,"%D\n",hashtab[i]);
			routerr = 1;
			}
	}

hash_free()
	{
	chfree(hashtab,sizeof(*hashtab) * maxhash);
	hashtab = 0;
	chfree(chain,sizeof(*chain) * maxhash);
	chain = 0;
	chfree(value,sizeof(*value) * maxhash);
	value = 0;
	}
hash(x)
long x;
	{
	int quo, rem, hcount, temp;

	ASSERT(x >= 0L, hash);
	quo = x/maxhash;
	rem = x - (quo * maxhash);
	if (quo == 0)  quo = 1;

	temp = rem;
	for (hcount=0; (hashtab[temp] != -1L) && (hashtab[temp] != x) && (hcount<maxhash); hcount++)
		temp = (temp + quo)%maxhash;
	if(hcount>=maxhash) faterr("hash table overflow - too many labels","","");
	hashtab[temp] = x;
	return(temp);
	}

addref(x,ptr)				/* put ptr in chain for x or assign value of x to *ptr */
long x;
int *ptr;
	{
	int index;
	index = hash(x);

	if (value[index]  == -1)
		{			/* x already assigned value */
		*ptr = chain[index];
		return;
		}
	
	/* add ptr to chain */
	
	if (chain[index] == 0)
		*ptr = 0;
	else
		*ptr = chain[index];
	chain[index] = ptr;
	}

fixvalue (x,ptr)
long x;
int ptr;
	{
	int *temp1, *temp2, index, temp0;
	index = hash(x);

	while (index != -2)
		{			/* trace chain of linked labels */

		if (value[index]  == -1)
			{
			error("in syntax:  ","","");
			fprintf(stderr,"attempt to redefine value of label %D between lines %d and %d\n",
				x,begline,endline);
			routerr = 1;
			return;
			}
	
		temp1 = &chain[index];		/* trace chain for each label */
		while (temp1 != 0)
			{
			temp2 = *temp1;
			*temp1 = ptr;
			temp1 = temp2;
			}
		temp0 = index;
		index = value[index];
		value[temp0] = -1;
		}
	}

connect(x,y)
long x,y;
	{
	int *temp, index, temp2;
	index = hash(x);

	if (value[index] == -1)
		fixvalue(y, chain[index]);
	else
		{
		if (y == implicit)
		{		/* attach implicit chain to x chain */
		temp = &chain[index];
	
		while (*temp != 0)
			temp = *temp;
	
		*temp = chain[hash(y)];
		}
		temp2 = index;		/* attach y linked labels to x linked labels */
		while (value[temp2] >= 0)
			temp2 = value[temp2];
		if (y == implicit)
			value[temp2] = value[hash(y)];
		else
			value[temp2] = hash(y);
		}
	if (y == implicit)  clear(y);
	}
	
	
clear(x)
long x;
	{
	int index;
	index = hash(x);
	value[index] = -2;
	chain[index] = 0;
	hashtab[index] = -1L;
	}


E 1
