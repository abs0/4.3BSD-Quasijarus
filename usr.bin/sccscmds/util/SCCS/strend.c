static char Sccsid[] "@(#)strend	2.2";
char *strend(p)
register char *p;
{
	while (*p++)
		;
	return(--p);
}
