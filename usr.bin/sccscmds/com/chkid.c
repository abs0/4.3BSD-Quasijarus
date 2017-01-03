# include	"../hdr/defines.h"

SCCSID(@(#)chkid	2.1);

chkid(line)
char *line;
{
	register char *lp;
	extern int Did_id;

	if (!Did_id && any('%',line))
		for(lp=line; *lp != 0; lp++) {
			if(lp[0] == '%' && lp[1] != 0 && lp[2] == '%') {
				Did_id++;
				break;
			}
		}
	return(Did_id);
}
