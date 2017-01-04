h25401
s 00010/00005/00186
d D 4.7 88/02/24 20:44:49 rick 7 6
c make more forgiving with hayes clones
e
s 00000/00001/00191
d D 4.6 86/02/12 17:31:47 bloom 6 5
c move define of USR2400 to uucp.h
e
s 00018/00008/00174
d D 4.5 86/01/13 14:07:53 bloom 5 4
c 2 sets of fixes from rick adams
e
s 00031/00021/00151
d D 4.4 85/10/10 11:37:12 bloom 4 3
c still more changes from rick@seismo
e
s 00027/00001/00145
d D 4.3 85/06/24 10:56:01 bloom 3 2
c fixes from rick adams
e
s 00004/00006/00142
d D 4.2 85/06/23 15:19:06 bloom 2 1
c fixes and changes fom rick adams
e
s 00148/00000/00000
d D 4.1 85/01/22 13:04:26 ralph 1 0
c date and time created 85/01/22 13:04:26 by ralph
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "../condevs.h"

D 7
#ifdef HAYES
E 7
I 4
D 6
#define USR2400	/* U.S. Robotics Courier 2400 */
E 6
#ifdef USR2400
#define DROPDTR
I 5
/*
 * The "correct" switch settings for a USR Courier 2400 are
 * 	Dialin/out:	0 0 1 1 0 0 0 1 0 0
 *	Dialout only:	0 0 1 1 1 1 0 1 0 0
 * where 0 = off and 1 = on
 */
E 5
#endif USR2400

E 4
D 2
/***
E 2
I 2
/*
E 2
 *	hyspopn(telno, flds, dev) connect to hayes smartmodem (pulse call)
 *	hystopn(telno, flds, dev) connect to hayes smartmodem (tone call)
 *	char *flds[], *dev[];
 *
 *	return codes:
 *		>0  -  file number  -  ok
 *		CF_DIAL,CF_DEVICE  -  failed
 */

hyspopn(telno, flds, dev)
char *telno, *flds[];
struct Devices *dev;
{
	return hysopn(telno, flds, dev, 0);
}

hystopn(telno, flds, dev)
char *telno, *flds[];
struct Devices *dev;
{
	return hysopn(telno, flds, dev, 1);
}

/* ARGSUSED */
hysopn(telno, flds, dev, toneflag)
char *telno;
char *flds[];
struct Devices *dev;
int toneflag;
{
D 5
	int	dh = -1;
E 5
	extern errno;
	char dcname[20];
I 3
	char cbuf[MAXPH];
	register char *cp;
	register int i;
I 5
	int dh = -1, nrings = 0;
E 5
E 3

	sprintf(dcname, "/dev/%s", dev->D_line);
	DEBUG(4, "dc - %s\n", dcname);
	if (setjmp(Sjbuf)) {
		logent(dcname, "TIMEOUT");
		if (dh >= 0)
D 5
			close(dh);
E 5
I 5
			hyscls(dh);
E 5
		return CF_DIAL;
	}
	signal(SIGALRM, alarmtr);
	getnextfd();
	alarm(10);
	dh = open(dcname, 2); /* read/write */
	alarm(0);

	/* modem is open */
	next_fd = -1;
	if (dh >= 0) {
		fixline(dh, dev->D_speed);
		if (dochat(dev, flds, dh)) {
			logent(dcname, "CHAT FAILED");
D 5
			close(dh);
E 5
I 5
			hyscls(dh);
E 5
			return CF_DIAL;
		}
D 2
		write(dh, "ATH\r", 4);
E 2
I 2
D 4
		write(dh, "ATV1H\r", 6);
E 4
I 4
		write(dh, "ATV1E0H\r", 8);
E 4
E 2
		if (expect("OK\r\n", dh) != 0) {
			logent(dcname, "HSM seems dead");
D 4
			close(dh);
E 4
I 4
			hyscls(dh);
E 4
			return CF_DIAL;
		}
I 4
#ifdef USR2400
D 5
		write(dh, "ATX6\r", 5);
E 5
I 5
		write(dh, "ATX6S7=44\r", 10);
E 5
		if (expect("OK\r\n", dh) != 0) {
			logent(dcname, "HSM seems dead");
			hyscls(dh);
			return CF_DIAL;
		}
#endif USR2400
E 4
		if (toneflag)
			write(dh, "\rATDT", 5);
		else
I 5
#ifdef USR2400
			write(dh, "\rATD", 4);
#else HAYES
E 5
			write(dh, "\rATDP", 5);
I 5
#endif HAYES
E 5
		write(dh, telno, strlen(telno));
		write(dh, "\r", 1);

D 3
		if (expect("CONNECT", dh) != 0) {
E 3
I 3
		if (setjmp(Sjbuf)) {
			logent(dcname, "TIMEOUT");
			strcpy(devSel, dev->D_line);
			hyscls(dh);
			return CF_DIAL;
		}
		signal(SIGALRM, alarmtr);
I 5
		alarm(2*MAXMSGTIME);
E 5
D 4
		alarm(MAXMSGTIME);
		cp = cbuf;
		while (read(dh, cp ,1) == 1)
			if (*cp >= ' ')
				break;
		cp++;
		while (cp < &cbuf[MAXPH] && read(dh, cp, 1) == 1 && *cp++ != '\n')
			;
		alarm(0);
		*cp = '\0';
E 4
I 4
		do {
D 5
			alarm(MAXMSGTIME);
E 5
			cp = cbuf;
			while (read(dh, cp ,1) == 1)
				if (*cp >= ' ')
					break;
			while (++cp < &cbuf[MAXPH] && read(dh, cp, 1) == 1 && *cp != '\n')
				;
			alarm(0);
			*cp-- = '\0';
			if (*cp == '\r')
				*cp = '\0';
			DEBUG(4,"\nGOT: %s", cbuf);
D 5
		} while (strncmp(cbuf, "RING", 4) == 0);
E 5
I 5
			alarm(MAXMSGTIME);
D 7
		} while (strncmp(cbuf, "RING", 4) == 0 && nrings++ < 5);
E 7
I 7
		} while ((strncmp(cbuf, "RING", 4) == 0 ||
			 strncmp(cbuf, "RRING", 5) == 0) && nrings++ < 5);
E 7
E 5
E 4
		if (strncmp(cbuf, "CONNECT", 7) != 0) {
E 3
D 4
			logent("HSM no carrier", _FAILED);
E 4
I 4
			logent(cbuf, _FAILED);
E 4
			strcpy(devSel, dev->D_line);
			hyscls(dh);
			return CF_DIAL;
I 3
		}
I 7
#undef DONTRESETBAUDRATE
#ifndef DONTRESETBAUDRATE
E 7
D 4
		DEBUG(4,"\nGOT: %s", cbuf);
E 4
		i = atoi(&cbuf[8]);
		if (i > 0 && i != dev->D_speed) {	
			DEBUG(4,"Baudrate reset to %d\n", i);
			fixline(dh, i);
E 3
		}
I 7
#endif /* DONTRESETBAUDRATE */
E 7

	}
	if (dh < 0) {
		logent(dcname, "CAN'T OPEN");
		return dh;
	}
	DEBUG(4, "hayes ok\n", CNULL);
	return dh;
}

hyscls(fd)
int fd;
{
	char dcname[20];
#ifdef DROPDTR
	struct sgttyb hup, sav;
#endif

	if (fd > 0) {
		sprintf(dcname, "/dev/%s", devSel);
		DEBUG(4, "Hanging up fd = %d\n", fd);
#ifdef DROPDTR
		/*
		 * code to drop DTR -- change to 0 baud then back to default.
		 */
		gtty(fd, &hup);
		gtty(fd, &sav);
		hup.sg_ispeed = B0;
		hup.sg_ospeed = B0;
		stty(fd, &hup);
		sleep(2);
		stty(fd, &sav);
		/*
		 * now raise DTR -- close the device & open it again.
		 */
		sleep(2);
		close(fd);
		sleep(2);
		fd = open(dcname, 2);
D 4
		/*
		 * Since we have a getty sleeping on this line, when it wakes up it sends
		 * all kinds of garbage to the modem.  Unfortunatly, the modem likes to
		 * execute the previous command when it sees the garbage.  The previous
		 * command was to dial the phone, so let's make the last command reset
		 * the modem.
		 */
E 4
I 4
		stty(fd, &sav);
E 4
#else
		sleep(3);
		write(fd, "+++", 3);
#endif
		sleep(3);
D 2
		write(fd, "ATH\r", 4);
		if (expect("ATH", fd) || expect("OK\r\n", fd))
			logent(devSel, "HSM did not respond to ATH");
E 2
D 7
		write(fd, "ATZ\r", 4);
E 7
I 7
		write(fd, "ATH\r", 4);
/*
E 7
D 2
		if (expect("ATZ", fd) || expect("OK\r\n", fd))
E 2
I 2
		if (expect("OK",fd) != 0)
E 2
			logent(devSel, "HSM did not respond to ATZ");
I 5
D 7
		write(fd, "ATH\r", 4);
E 7
I 7
*/
E 7
E 5
		sleep(1);
I 7
		write(fd, "ATZ\r", 4);
		sleep(1);
E 7
		close(fd);
		delock(devSel);
	}
}
D 5

E 5
D 7
#endif HAYES
E 7
I 2
D 5

E 5
E 2
E 1
