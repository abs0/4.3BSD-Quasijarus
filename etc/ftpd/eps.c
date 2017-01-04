/* EPS functions for ftpd */

#ifndef lint
static char sccsid[] = "@(#)eps.c	5.1 (Berkeley) 05/01/12";
#endif

#include <sys/param.h>
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include <pwd.h>

extern struct passwd *pw;

int epsquota;

isepsname(s)
	char *s;
{
	register char *cp;
	register int i;

	cp = s;
	if (*cp++ != 'e')
		return(0);
	if (*cp++ != 'p')
		return(0);
	if (*cp++ != 's')
		return(0);
	for (i = 0; i < 6; i++)
		if (!isdigit(*cp++))
			return(0);
	if (!*cp)
		return(1);
	else
		return(0);
}

eps_readaccount(account)
	char *account;
{
	register FILE *f;
	register char *cp;
	char buf[16];
	static char dir[MAXPATHLEN+2], cryptpass[16];

	sprintf(dir, "/usr/spool/eps/%s", account);
	f = fopen(dir, "r");
	if (!f)
		return(-1);
	if (!fgets(buf, sizeof(buf), f))
		goto bad;
	cp = index(buf, '\n');
	if (cp)
		*cp = '\0';
	else
		goto bad;
	pw = getpwnam(buf);
	if (!pw)
		goto bad;
	if (!fgets(dir, sizeof(dir), f))
		goto bad;
	cp = index(dir, '\n');
	if (cp)
		*cp = '\0';
	else
		goto bad;
	pw->pw_dir = dir;
	if (!fgets(cryptpass, sizeof(cryptpass), f))
		goto bad;
	cp = index(cryptpass, '\n');
	if (cp)
		*cp = '\0';
	else
		goto bad;
	pw->pw_passwd = cryptpass;
	if (!fgets(buf, sizeof(buf), f))
		goto bad;
	if (!index(buf, '\n'))
		goto bad;
	epsquota = atoi(buf);
	fclose(f);
	return(0);
bad:	fclose(f);
	return(-2);
}
