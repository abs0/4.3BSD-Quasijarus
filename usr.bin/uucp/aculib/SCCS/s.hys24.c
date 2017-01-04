h24458
s 00116/00035/00089
d D 1.5 88/05/05 11:14:13 rick 5 4
c fixes from spafford
e
s 00000/00000/00124
d D 1.4 88/05/04 13:56:06 rick 4 3
c fixes from spafford
e
s 00000/00000/00124
d D 1.3 88/04/05 12:31:13 rick 3 2
c fix up hayes24 support
e
s 00000/00002/00124
d D 1.2 88/02/24 20:45:19 rick 2 1
c remove extraneous ifdefs
e
s 00126/00000/00000
d D 1.1 86/01/13 13:51:23 bloom 1 0
c date and time created 86/01/13 13:51:23 by bloom
e
u
U
t
T
I 1
#ifndef lint
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
static char sccsid[] = "%W%	(Berkeley) %G%";
E 5
#endif !lint

#include "../condevs.h"

D 2
#ifdef HAYES2400
E 2
/*
D 5
 *	hyspopn24(telno, flds, dev) connect to hayes smartmodem (pulse call)
 *	hystopn24(telno, flds, dev) connect to hayes smartmodem (tone call)
 *	char *flds[], *dev[];
E 5
I 5
 * hyspopn24(telno, flds, dev) connect to hayes smartmodem (pulse call)
 * hystopn24(telno, flds, dev) connect to hayes smartmodem (tone call)
E 5
 *
D 5
 *	return codes:
 *		>0  -  file number  -  ok
 *		CF_DIAL,CF_DEVICE  -  failed
E 5
I 5
 * return codes: >0  -  file number  -  ok CF_DIAL,CF_DEVICE  -  failed 
E 5
 */

I 5
#include <sys/file.h>
#include <sys/ioctl.h>

E 5
hyspopn24(telno, flds, dev)
char *telno, *flds[];
struct Devices *dev;
{
	return hysopn24(telno, flds, dev, 0);
}

hystopn24(telno, flds, dev)
char *telno, *flds[];
struct Devices *dev;
{
	return hysopn24(telno, flds, dev, 1);
}

/* ARGSUSED */
hysopn24(telno, flds, dev, toneflag)
char *telno;
char *flds[];
struct Devices *dev;
int toneflag;
{
D 5
	int	dh = -1;
E 5
I 5
	int dh = -1;
	int result, ix, speed;
E 5
	char *ii;
	extern errno;
	char dcname[20];
I 5
	char resultbuf[16];
E 5

	sprintf(dcname, "/dev/%s", dev->D_line);
	DEBUG(4, "dc - %s\n", dcname);
	if (setjmp(Sjbuf)) {
		logent(dcname, "TIMEOUT");
		if (dh >= 0)
D 5
			hyscls24(dh);
E 5
I 5
			hyscls24(dh, 0);
E 5
		return CF_DIAL;
	}
	signal(SIGALRM, alarmtr);
	getnextfd();
	alarm(10);
D 5
	dh = open(dcname, 2); /* read/write */
E 5
I 5
	dh = open(dcname, 2);	/* read/write */
E 5
	alarm(0);

	for (ii = telno; *ii; ii++)
		if (*ii == '=')
D 5
		    *ii = ',';
E 5
I 5
			*ii = ',';
E 5

	/* modem is open */
	next_fd = -1;
	if (dh >= 0) {
I 5
		ioctl(dh, TIOCHPCL, 0);
E 5
		fixline(dh, dev->D_speed);
D 5
		write(dh, "\rATZH\r", 6);
		sleep(2);
E 5
		if (dochat(dev, flds, dh)) {
			logent(dcname, "CHAT FAILED");
D 5
			hyscls24(dh);
E 5
I 5
			hyscls24(dh, 0);
E 5
			return CF_DIAL;
		}
D 5
		write(dh, "AT&F&D3&C1E0X1\r", 15);
		if (expect("OK\r\n", dh) != 0) {
E 5
I 5
		hyscls24(dh, 1);/* make sure the line is reset */
		write(dh, "AT&F&D3&C1E0M0X3QV0Y\r", 21);
		if (expect("0\r", dh) != 0) {
E 5
			logent(dcname, "HSM not responding OK");
D 5
			hyscls24(dh);
E 5
I 5
			hyscls24(dh, 0);
E 5
			return CF_DIAL;
		}
		if (toneflag)
			write(dh, "\rATDT", 5);
		else
			write(dh, "\rATDP", 5);
		write(dh, telno, strlen(telno));
		write(dh, "\r", 1);

D 5
		if (expect("CONNECT", dh) != 0) {
			logent("HSM no carrier", _FAILED);
			strcpy(devSel, dev->D_line);
			hyscls24(dh);
E 5
I 5
		if (setjmp(Sjbuf)) {
			logent(dcname, "Modem Hung");
			if (dh >= 0)
				hyscls24(dh, 0);
E 5
			return CF_DIAL;
		}
I 5
		signal(SIGALRM, alarmtr);
		alarm(120);
		do {
			for (ix = 0; ix < 16; ix++) {
				read(dh, resultbuf + ix, 1);
				DEBUG(6, "character read = 0x%X \n", resultbuf[ix]);
				if ((0x7f & resultbuf[ix]) == 0xd)
					break;
			}
E 5

I 5
			result = atol(resultbuf);
			switch (result) {
			case 0:
				logent("HSM Spurious OK response", _FAILED);
				speed = 0;
				break;
			case 1:
				logent("HSM connected at 300 baud!", _FAILED);
				speed = -1;
				break;
			case 2:
				speed = 0;
				DEBUG(4, "Ringing", 0);
				break;
			case 3:
				logent("HSM No Carrier", _FAILED);
				speed = -1;
				break;
			case 4:
				logent("HSM Error", _FAILED);
				speed = -1;
				break;
			case 5:
				speed = 1200;
				break;
			case 6:
				logent("HSM No dialtone", _FAILED);
				speed = -1;
				break;
			case 7:
				logent("HSM detected BUSY", _FAILED);
				speed = -1;
				break;
			case 8:
				logent("HSM No quiet answer", _FAILED);
				speed = -1;
				break;
			case 10:
				speed = 2400;
				break;
			default:
				logent("HSM Unknown response", _FAILED);
				speed = -1;
				break;
			}

		} while (speed == 0);

		alarm(0);

		if (speed < 0) {
			strcpy(devSel, dev->D_line);
			hyscls24(dh, 0);
			return CF_DIAL;
		} else if (speed != dev->D_speed) {
			DEBUG(4, "changing line speed to %d baud\n", speed);
			fixline(dh, speed);
		}
E 5
	}
	if (dh < 0) {
		logent(dcname, "CAN'T OPEN");
		return dh;
	}
	DEBUG(4, "hayes ok\n", CNULL);
	return dh;
}

D 5
hyscls24(fd)
int fd;
E 5
I 5
hyscls24(fd, flag)
int fd, flag;
E 5
{
	char dcname[20];
I 5
	int fff = FREAD;
E 5

	if (fd > 0) {
		sprintf(dcname, "/dev/%s", devSel);
D 5
		DEBUG(4, "Hanging up fd = %d\n", fd);
		sleep(1);
/*
 * Since we have a getty sleeping on this line, when it wakes up it sends
 * all kinds of garbage to the modem.  Unfortunatly, the modem likes to
 * execute the previous command when it sees the garbage.  The previous
 * command was to dial the phone, so let's make the last command reset
 * the modem.
 */
		write(fd, "\r+++", 4);
E 5
I 5
		if (flag)
			DEBUG(4, "Resetting fd = %d\n", fd);
		else
			DEBUG(4, "Hanging up fd = %d\n", fd);
		/*
		 * Since we have a getty sleeping on this line, when it wakes
		 * up it sends all kinds of garbage to the modem. 
		 * Unfortunatly, the modem likes to execute the previous
		 * command when it sees the garbage.  The previous command
		 * was to dial the phone, so let's make the last command
		 * reset the modem. 
		 */
		if (!flag)
			fixline(fd, 2400);
		write(fd, "\r", 1);
E 5
		sleep(2);
I 5
		write(fd, "+++", 3);
		sleep(3);
E 5
		write(fd, "\rATH\rATZ\r", 9);
		sleep(2);
D 5
		close(fd);
		delock(devSel);
E 5
I 5
		ioctl(fd, TIOCFLUSH, &fff);

		if (!flag) {
			close(fd);
			delock(devSel);
		}
E 5
	}
}
D 2
#endif HAYES2400
E 2
E 1
