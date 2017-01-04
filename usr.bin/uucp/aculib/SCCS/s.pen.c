h29923
s 00000/00002/00101
d D 4.3 88/02/24 20:45:24 rick 3 2
c remove extraneous ifdefs
e
s 00001/00000/00102
d D 4.2 85/10/10 11:38:40 bloom 2 1
c reset alarm after open (from rick@seismo)
e
s 00102/00000/00000
d D 4.1 85/04/03 11:00:27 ralph 1 0
c date and time created 85/04/03 11:00:27 by ralph
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

/*
 *	Speaker's quick and dirty penril hack.  STA 4/1/85.
 */
#include "../condevs.h"
D 3
#ifdef	PENRIL
E 3

penopn(telno, flds, dev)
char *flds[], *telno;
struct Devices *dev;
{
	int	dh;
	int	i, ok = -1;
	char dcname[20];

	sprintf(dcname, "/dev/%s", dev->D_line);
	if (setjmp(Sjbuf)) {
		DEBUG(1, "timeout penril open\n", "");
		logent("penril open", "TIMEOUT");
		if (dh >= 0)
			close(dh);
		delock(dev->D_line);
		return CF_NODEV;
	}
	signal(SIGALRM, alarmtr);
	getnextfd();
	alarm(10);
	dh = open(dcname, 2);
I 2
	alarm(0);
E 2
	next_fd = -1;
	if (dh < 0) {
		DEBUG(4,"%s\n", errno == 4 ? "no carrier" : "can't open modem");
		delock(dev->D_line);
		return errno == 4 ? CF_DIAL : CF_NODEV;
	}

	/* modem is open */
	fixline(dh, dev->D_speed);

	/* translate - to P and = to W for Penril */
	DEBUG(4, "calling %s -> ", telno);
	for (i = 0; i < strlen(telno); ++i) {
		switch(telno[i]) {
		case '-':	/* delay */
			telno[i] = 'P';
			break;
		case '=':	/* await dial tone */
			telno[i] = 'W';
			break;
		case '<':
			telno[i] = 'P';
			break;
		}
	}
	DEBUG(4, "%s\n", telno);
	sleep(1);
	for(i = 0; i < 5; ++i) {	/* make up to 5 tries */
		slowrite(dh, "\r");/* awake, thou lowly Penril! */

		DEBUG(4, "wanted %s ", ">");
		ok = expect(">", dh);
		DEBUG(4, "got %s\n", ok ? "?" : "that");
		if (ok != 0)
			continue;
		slowrite(dh, "K");	/* "K" (enter number) command */
		DEBUG(4, "wanted %s ", "NO.: ");
		ok = expect("NO.: ", dh);
		DEBUG(4, "got %s\n", ok ? "?" : "that");
		if (ok == 0)
			break;
	}

	if (ok == 0) {
		slowrite(dh, telno); /* send telno, send \r */
		slowrite(dh, "\r");
		DEBUG(4, "wanted %s ", "OK");
		ok = expect("OK", dh);
		DEBUG(4, "got %s\n", ok ? "?" : "that");
	}
	if (ok != 0) {
		if (dh > 2)
			close(dh);
		DEBUG(4, "penDial failed\n", "");
		return CF_DIAL;
	}
	else
		DEBUG(4, "penDial ok\n", "");
	return dh;
}

pencls(fd)
int fd;
{
	if (fd > 0) {
		close(fd);
		sleep(5);
		delock(devSel);
	}
}
D 3
#endif PENRIL
E 3
E 1
