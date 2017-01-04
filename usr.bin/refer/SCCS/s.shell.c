h41583
s 00031/00000/00000
d D 4.1 83/05/06 23:50:07 tut 1 0
c date and time created 83/05/06 23:50:07 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif
/*
 * SORTS UP.
 * IF THERE ARE NO EXCHANGES (IEX=0) ON A SWEEP
 * THE COMPARISON GAP (IGAP) IS HALVED FOR THE NEXT SWEEP
 */
shell (n, comp, exch)
int (*comp)(), (*exch)();
{
	int igap, iplusg, iex, i, imax;
	igap=n;
	while (igap > 1)
	{
		igap /= 2;
		imax = n-igap;
		do
		    {
			iex=0;
			for(i=0; i<imax; i++)
			{
				iplusg = i + igap;
				if ((*comp) (i, iplusg) ) continue;
				(*exch) (i, iplusg);
				iex=1;
			}
		} 
		while (iex>0);
	}
}
E 1
