h00567
s 00120/00000/00000
d D 4.1 83/02/11 15:44:13 rrh 1 0
c date and time created 83/02/11 15:44:13 by rrh
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
#
#include "def.h"
#define bufsize 1601
char buffer[bufsize];
int bufcount;
extern int errflag;
long stchars;			/* counts number of chars at most recent \n read */
#ifndef unix
long ostchars;
extern long ftell();
#endif
int newline;			/* counts number of lines read so far in file */
extern int rdfree(), comfree(),labfree(), contfree();
extern int rdstand(), comstand(), labstand(), contstand();
extern int (*rline[])();
extern int (*comment[])();
extern int (*getlabel[])();
extern int (*chkcont[])();



flush()
	{bufcount = 0; }

addchar(c)
	{
	buffer[bufcount++] = c;
	}

getline(lastline,lastchar,linecom,charcom)
int *lastline, *linecom;
long *lastchar, *charcom;
				/* set *lastline to number of last line of statement,
				set *lastchar to number of last char of statement,
				set *linecom to number of last line of comment preceding statement */
	{

	int i;
	flush();
	while ( unput1(input1()) != EOF)
		{
		while ( (*comment[inputform])(0)  || blankline() )
			{
			(*rline[inputform])(addchar);
			flush();
			}
		*linecom = newline;
			/* set charcom to number of last char of comment, starting at 0
					if at start of file and no comment, will be -1  */
		*charcom = stchars - 1;
		if (unput1(input1()) == EOF)  break;
		(*getlabel[inputform])(addchar);
		(*rline[inputform])(addchar);
	
		while ( blankline() || ( !(*comment[inputform])(0) &&  (*chkcont[inputform])() ))
			(*rline[inputform])(addchar);
	
		addchar('\0');
		*lastline = newline;
		*lastchar = stchars - 1;
if (debug == 40)
fprintf(stderr,"line %d; bufcount: %d\n",newline,bufcount);
	
		for (i = 5; i < bufcount; ++i)
			if (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n')
				buffer[i] = '~';
		return(bufcount);
		}
	return(-1);
	}


int linechars;			/* counts number of chars read so far in current line */
long newchar;			/* counts number of chars read so far in file */


input1()
	{
	static int c;
	if (c == '\n') linechars = 0;
	c = inchar();
	++linechars;
	++newchar;
	if (c == '\n')
		{
		++newline;
#ifdef unix
 		stchars = newchar; 
#else
		ostchars=stchars; stchars=ftell(infd);
#endif
		}
	return(c);
	}

unput1(c)
	{
	--linechars;
	--newchar;
	unchar(c);
	if (c == '\n')
		{
#ifdef unix
 		stchars = newchar; 
#else
		stchars=ostchars;
#endif
		--newline;
		}
	return(c);
	}




E 1
