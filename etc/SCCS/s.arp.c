h65252
s 00028/00002/00406
d D 5.6 88/06/30 14:28:36 bostic 12 11
c taken off the net; done by SUN
e
s 00128/00069/00280
d D 5.5 88/03/01 18:31:33 bostic 11 10
c add getopt, general cleanup, make it work with dead kernels
e
s 00017/00007/00332
d D 5.4 87/11/18 18:36:40 mckusick 10 9
c support for full arp syntax (4.3BSD/etc/99 from guy@sun.com (Guy Harris))
e
s 00001/00002/00338
d D 5.3 87/04/06 09:59:42 bostic 9 8
c sscanf argument count fix
e
s 00044/00023/00296
d D 5.2 86/02/21 12:30:25 karels 8 7
c accept host by number; only wait for nameserver once
e
s 00000/00000/00319
d D 5.1 86/02/16 23:03:17 karels 7 6
c bring up to release 5
e
s 00010/00004/00309
d D 1.4 86/01/09 18:51:11 karels 6 3
c print trailer flag, allow it to be set
e
s 00002/00000/00313
d R 1.4 86/01/09 18:26:41 karels 5 3
c print trailer flag
e
s 00001/00000/00313
d R 1.4 86/01/08 20:04:26 karels 4 3
c print value of new trailer flag
e
s 00003/00003/00310
d D 1.3 85/10/09 14:32:13 bloom 3 2
c return value incorrect, portability fixes (from ks@purdue)
e
s 00009/00011/00304
d D 1.2 85/05/30 12:48:47 karels 2 1
c no more struct ether_addr's
e
s 00315/00000/00000
d D 1.1 84/03/30 08:38:00 karels 1 0
c date and time created 84/03/30 08:38:00 by karels
e
u
U
f b 
t
T
I 12
/*
 * Copyright (c) 1984 Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Sun Microsystems, Inc.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

E 12
I 1
#ifndef lint
D 12
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 12
I 12
char copyright[] =
"%Z% Copyright (c) 1984 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 12

/*
 * arp - display, set, and delete arp table entries
 */

D 11
#include <stdio.h>
#include <sys/types.h>
E 11
I 11
#include <machine/pte.h>

#include <sys/param.h>
#include <sys/vmmac.h>
#include <sys/file.h>
E 11
#include <sys/socket.h>
D 11
#include <netinet/in.h>
E 11
#include <sys/ioctl.h>
D 11
#include <errno.h>
E 11
I 11

E 11
#include <netdb.h>
D 11
#include <nlist.h>
E 11
I 11
#include <netinet/in.h>
E 11
#include <net/if.h>
#include <netinet/if_ether.h>

I 11
#include <errno.h>
#include <nlist.h>
#include <stdio.h>

E 11
extern int errno;
I 11
static int kflag;
E 11

main(argc, argv)
I 11
	int argc;
E 11
	char **argv;
{
D 11
	if (argc >= 2 && strcmp(argv[1], "-a") == 0) {
		char *kernel = "/vmunix", *mem = "/dev/kmem";
E 11
I 11
	int ch;
E 11

D 11
		if (argc >= 3)
			kernel = argv[2];
		if (argc >= 4)
			mem = argv[3];
		dump(kernel, mem);
		exit(0);
	}
	if (argc == 2) {
		get(argv[1]);
		exit(0);
	}
	if (argc >= 4 && strcmp(argv[1], "-s") == 0) {
D 10
		set(argc-2, &argv[2]);
E 10
I 10
		if (set(argc-2, &argv[2]))
			exit(1);
E 10
		exit(0);
	}
	if (argc == 3 && strcmp(argv[1], "-d") == 0) {
		delete(argv[2]);
		exit(0);
	}
	if (argc == 3 && strcmp(argv[1], "-f") == 0) {
D 10
		file(argv[2]);
E 10
I 10
		if (file(argv[2]))
			exit(1);
E 10
		exit(0);
	}
	usage();
	exit(1);
E 11
I 11
	while ((ch = getopt(argc, argv, "adsf")) != EOF)
		switch((char)ch) {
		case 'a': {
			char *mem;

			if (argc > 4)
				usage();
			if (argc == 4) {
				kflag = 1;
				mem = argv[3];
			}
			else
				mem = "/dev/kmem";
			dump((argc >= 3) ? argv[2] : "/vmunix", mem);
			exit(0);
		}
		case 'd':
			if (argc != 3)
				usage();
			delete(argv[2]);
			exit(0);
		case 's':
			if (argc < 4 || argc > 7)
				usage();
			exit(set(argc-2, &argv[2]) ? 1 : 0);
		case 'f':
			if (argc != 3)
				usage();
			exit (file(argv[2]) ? 1 : 0);
		case '?':
		default:
			usage();
		}
	if (argc != 2)
		usage();
	get(argv[1]);
	exit(0);
E 11
}

/*
 * Process a file to set standard arp entries
 */
file(name)
	char *name;
{
	FILE *fp;
D 11
	int i;
E 11
I 11
	int i, retval;
E 11
D 6
	char line[100], arg[4][50], *args[4];
E 6
I 6
	char line[100], arg[5][50], *args[5];
I 10
D 11
	int retval;
E 11
E 10
E 6

	if ((fp = fopen(name, "r")) == NULL) {
		fprintf(stderr, "arp: cannot open %s\n", name);
		exit(1);
	}
	args[0] = &arg[0][0];
	args[1] = &arg[1][0];
	args[2] = &arg[2][0];
	args[3] = &arg[3][0];
I 6
	args[4] = &arg[4][0];
I 10
	retval = 0;
E 10
E 6
	while(fgets(line, 100, fp) != NULL) {
D 6
		i = sscanf(line, "%s %s %s %s", arg[0], arg[1], arg[2], arg[3]);
E 6
I 6
D 9
		i = sscanf(line, "%s %s %s %s", arg[0], arg[1], arg[2], arg[3],
			arg[4]);
E 9
I 9
D 10
		i = sscanf(line, "%s %s %s %s", arg[0], arg[1], arg[2], arg[3]);
E 10
I 10
		i = sscanf(line, "%s %s %s %s %s", arg[0], arg[1], arg[2],
		    arg[3], arg[4]);
E 10
E 9
E 6
		if (i < 2) {
			fprintf(stderr, "arp: bad line: %s\n", line);
I 10
			retval = 1;
E 10
			continue;
		}
D 10
		set(i, args);
E 10
I 10
		if (set(i, args))
			retval = 1;
E 10
	}
	fclose(fp);
I 10
	return (retval);
E 10
}

/*
 * Set an individual arp entry 
 */
set(argc, argv)
I 11
	int argc;
E 11
	char **argv;
{
	struct arpreq ar;
	struct hostent *hp;
	struct sockaddr_in *sin;
D 2
	struct ether_addr *ea;
E 2
I 2
	u_char *ea;
E 2
	int s;
	char *host = argv[0], *eaddr = argv[1];

	argc -= 2;
	argv += 2;
D 8
	hp = gethostbyname(host);
	if (hp == NULL) {
		fprintf(stderr, "arp: %s: unknown host\n", host);
D 3
		return (1);
E 3
I 3
		return;
E 3
	}
E 8
	bzero((caddr_t)&ar, sizeof ar);
D 8
	ar.arp_pa.sa_family = AF_INET;
E 8
	sin = (struct sockaddr_in *)&ar.arp_pa;
D 3
	sin->sin_addr = *(struct in_addr *)hp->h_addr;
E 3
I 3
D 8
	bcopy((char *)hp->h_addr, (char *)&sin->sin_addr, sizeof sin->sin_addr);
E 8
I 8
	sin->sin_family = AF_INET;
	sin->sin_addr.s_addr = inet_addr(host);
	if (sin->sin_addr.s_addr == -1) {
		hp = gethostbyname(host);
		if (hp == NULL) {
			fprintf(stderr, "arp: %s: unknown host\n", host);
D 10
			return;
E 10
I 10
			return (1);
E 10
		}
		bcopy((char *)hp->h_addr, (char *)&sin->sin_addr,
		    sizeof sin->sin_addr);
	}
E 8
E 3
D 2
	ea = (struct ether_addr *)ar.arp_ha.sa_data;
E 2
I 2
	ea = (u_char *)ar.arp_ha.sa_data;
E 2
	if (ether_aton(eaddr, ea))
D 10
		return;
E 10
I 10
		return (1);
E 10
	ar.arp_flags = ATF_PERM;
D 8
	while(argc-- > 0) {
E 8
I 8
	while (argc-- > 0) {
E 8
		if (strncmp(argv[0], "temp", 4) == 0)
			ar.arp_flags &= ~ATF_PERM;
D 11
		if (strncmp(argv[0], "pub", 3) == 0)
E 11
I 11
		else if (strncmp(argv[0], "pub", 3) == 0)
E 11
			ar.arp_flags |= ATF_PUBL;
I 6
D 11
		if (strncmp(argv[0], "trail", 5) == 0)
E 11
I 11
		else if (strncmp(argv[0], "trail", 5) == 0)
E 11
			ar.arp_flags |= ATF_USETRAILERS;
E 6
		argv++;
	}
	
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s < 0) {
D 11
                perror("arp: socket");
                exit(1);
        }
E 11
I 11
		perror("arp: socket");
		exit(1);
	}
E 11
	if (ioctl(s, SIOCSARP, (caddr_t)&ar) < 0) {
		perror(host);
		exit(1);
	}
	close(s);
I 10
	return (0);
E 10
}

D 11

E 11
/*
 * Display an individual arp entry
 */
get(host)
	char *host;
{
	struct arpreq ar;
	struct hostent *hp;
	struct sockaddr_in *sin;
D 2
	struct ether_addr *ea;
E 2
I 2
	u_char *ea;
E 2
	int s;
I 11
	char *inet_ntoa();
E 11

D 8
	hp = gethostbyname(host);
	if (hp == NULL) {
		fprintf(stderr, "arp: %s: unknown host\n", host);
		exit(1);
	}
E 8
	bzero((caddr_t)&ar, sizeof ar);
	ar.arp_pa.sa_family = AF_INET;
	sin = (struct sockaddr_in *)&ar.arp_pa;
D 8
	sin->sin_addr = *(struct in_addr *)hp->h_addr;
E 8
I 8
	sin->sin_family = AF_INET;
	sin->sin_addr.s_addr = inet_addr(host);
	if (sin->sin_addr.s_addr == -1) {
		hp = gethostbyname(host);
		if (hp == NULL) {
			fprintf(stderr, "arp: %s: unknown host\n", host);
			exit(1);
		}
		bcopy((char *)hp->h_addr, (char *)&sin->sin_addr,
		    sizeof sin->sin_addr);
	}
E 8
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s < 0) {
D 11
                perror("arp: socket");
                exit(1);
        }
E 11
I 11
		perror("arp: socket");
		exit(1);
	}
E 11
	if (ioctl(s, SIOCGARP, (caddr_t)&ar) < 0) {
		if (errno == ENXIO)
			printf("%s (%s) -- no entry\n",
			    host, inet_ntoa(sin->sin_addr));
		else
			perror("SIOCGARP");
		exit(1);
	}
	close(s);
D 2
	ea = (struct ether_addr *)ar.arp_ha.sa_data;
E 2
I 2
	ea = (u_char *)ar.arp_ha.sa_data;
E 2
	printf("%s (%s) at ", host, inet_ntoa(sin->sin_addr));
	if (ar.arp_flags & ATF_COM)
		ether_print(ea);
	else
		printf("(incomplete)");
D 6
	if (!(ar.arp_flags & ATF_PERM)) printf(" temporary");
E 6
I 6
D 11
	if (ar.arp_flags & ATF_PERM) printf(" permanent");
E 6
	if (ar.arp_flags & ATF_PUBL) printf(" published");
I 6
	if (ar.arp_flags & ATF_USETRAILERS) printf(" trailers");
E 11
I 11
	if (ar.arp_flags & ATF_PERM)
		printf(" permanent");
	if (ar.arp_flags & ATF_PUBL)
		printf(" published");
	if (ar.arp_flags & ATF_USETRAILERS)
		printf(" trailers");
E 11
E 6
	printf("\n");
}

/*
 * Delete an arp entry 
 */
delete(host)
	char *host;
{
	struct arpreq ar;
	struct hostent *hp;
	struct sockaddr_in *sin;
	int s;

D 8
	hp = gethostbyname(host);
	if (hp == NULL) {
		fprintf(stderr, "arp: %s: unknown host\n", host);
		exit(1);
	}
E 8
	bzero((caddr_t)&ar, sizeof ar);
	ar.arp_pa.sa_family = AF_INET;
	sin = (struct sockaddr_in *)&ar.arp_pa;
D 3
	sin->sin_addr = *(struct in_addr *)hp->h_addr;
E 3
I 3
D 8
	bcopy((char *)hp->h_addr, (char *)&sin->sin_addr, sizeof sin->sin_addr);
E 8
I 8
	sin->sin_family = AF_INET;
	sin->sin_addr.s_addr = inet_addr(host);
	if (sin->sin_addr.s_addr == -1) {
		hp = gethostbyname(host);
		if (hp == NULL) {
			fprintf(stderr, "arp: %s: unknown host\n", host);
			exit(1);
		}
		bcopy((char *)hp->h_addr, (char *)&sin->sin_addr,
		    sizeof sin->sin_addr);
	}
E 8
E 3
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s < 0) {
D 11
                perror("arp: socket");
                exit(1);
        }
E 11
I 11
		perror("arp: socket");
		exit(1);
	}
E 11
	if (ioctl(s, SIOCDARP, (caddr_t)&ar) < 0) {
		if (errno == ENXIO)
			printf("%s (%s) -- no entry\n",
			    host, inet_ntoa(sin->sin_addr));
		else
			perror("SIOCDARP");
		exit(1);
	}
	close(s);
	printf("%s (%s) deleted\n", host, inet_ntoa(sin->sin_addr));
}

struct nlist nl[] = {
#define	X_ARPTAB	0
	{ "_arptab" },
#define	X_ARPTAB_SIZE	1
	{ "_arptab_size" },
I 11
#define	N_SYSMAP	2
	{ "_Sysmap" },
#define	N_SYSSIZE	3
	{ "_Syssize" },
E 11
	{ "" },
};

I 11
static struct pte *Sysmap;

E 11
/*
 * Dump the entire arp table
 */
dump(kernel, mem)
	char *kernel, *mem;
{
D 11
	int mf, arptab_size, sz;
E 11
I 11
	extern int h_errno;
E 11
	struct arptab *at;
	struct hostent *hp;
D 11
	char *host;
I 8
	int bynumber = 0;
I 10
	extern int h_errno;
E 11
I 11
	int bynumber, mf, arptab_size, sz;
	char *host, *malloc();
	off_t lseek();
E 11
E 10
E 8

D 11
	nlist(kernel, nl);
	if(nl[X_ARPTAB_SIZE].n_type == 0) {
E 11
I 11
	if (nlist(kernel, nl) < 0 || nl[X_ARPTAB_SIZE].n_type == 0) {
E 11
		fprintf(stderr, "arp: %s: bad namelist\n", kernel);
		exit(1);
	}
D 11
	mf = open(mem, 0);
	if(mf < 0) {
E 11
I 11
	mf = open(mem, O_RDONLY);
	if (mf < 0) {
E 11
		fprintf(fprintf, "arp: cannot open %s\n", mem);
		exit(1);
	}
D 11
	lseek(mf, (long)nl[X_ARPTAB_SIZE].n_value, 0);
E 11
I 11
	if (kflag) {
		off_t off;

		Sysmap = (struct pte *)
		   malloc((u_int)(nl[N_SYSSIZE].n_value * sizeof(struct pte)));
		if (!Sysmap) {
			fputs("arp: can't get memory for Sysmap.\n", stderr);
			exit(1);
		}
		off = nl[N_SYSMAP].n_value & ~KERNBASE;
		(void)lseek(mf, off, L_SET);
		(void)read(mf, (char *)Sysmap,
		    (int)(nl[N_SYSSIZE].n_value * sizeof(struct pte)));
	}
	klseek(mf, (long)nl[X_ARPTAB_SIZE].n_value, L_SET);
E 11
	read(mf, &arptab_size, sizeof arptab_size);
D 11
	if (arptab_size <=0 || arptab_size > 1000) {
E 11
I 11
	if (arptab_size <= 0 || arptab_size > 1000) {
E 11
		fprintf(stderr, "arp: %s: namelist wrong\n", kernel);
		exit(1);
	}
	sz = arptab_size * sizeof (struct arptab);
D 11
	at = (struct arptab *)malloc(sz);
E 11
I 11
	at = (struct arptab *)malloc((u_int)sz);
E 11
	if (at == NULL) {
D 11
		fprintf(stderr, "arp: can't get memory for arptab\n");
E 11
I 11
		fputs("arp: can't get memory for arptab.\n", stderr);
E 11
		exit(1);
	}
D 11
	lseek(mf, (long)nl[X_ARPTAB].n_value, 0);
E 11
I 11
	klseek(mf, (long)nl[X_ARPTAB].n_value, L_SET);
E 11
	if (read(mf, (char *)at, sz) != sz) {
		perror("arp: error reading arptab");
		exit(1);
	}
	close(mf);
D 11
	for (; arptab_size-- > 0; at++) {
E 11
I 11
	for (bynumber = 0; arptab_size-- > 0; at++) {
E 11
		if (at->at_iaddr.s_addr == 0 || at->at_flags == 0)
			continue;
D 8
		hp = gethostbyaddr((caddr_t)&at->at_iaddr, sizeof at->at_iaddr,
			AF_INET);
E 8
I 8
		if (bynumber == 0)
			hp = gethostbyaddr((caddr_t)&at->at_iaddr,
			    sizeof at->at_iaddr, AF_INET);
		else
			hp = 0;
E 8
		if (hp)
			host = hp->h_name;
D 8
		else
E 8
I 8
		else {
E 8
			host = "?";
I 8
			if (h_errno == TRY_AGAIN)
				bynumber = 1;
		}
E 8
		printf("%s (%s) at ", host, inet_ntoa(at->at_iaddr));
		if (at->at_flags & ATF_COM)
D 2
			ether_print(&at->at_enaddr);
E 2
I 2
			ether_print(at->at_enaddr);
E 2
		else
			printf("(incomplete)");
D 6
		if (!(at->at_flags & ATF_PERM)) printf(" temporary");
E 6
I 6
D 11
		if (at->at_flags & ATF_PERM) printf(" permanent");
E 6
		if (at->at_flags & ATF_PUBL) printf(" published");
I 6
		if (at->at_flags & ATF_USETRAILERS) printf(" trailers");
E 11
I 11
		if (at->at_flags & ATF_PERM)
			printf(" permanent");
		if (at->at_flags & ATF_PUBL)
			printf(" published");
		if (at->at_flags & ATF_USETRAILERS)
			printf(" trailers");
E 11
E 6
		printf("\n");
	}
}

I 11
/*
 * Seek into the kernel for a value.
 */
klseek(fd, base, off)
	int fd, off;
	off_t base;
{
	off_t lseek();

	if (kflag) {	/* get kernel pte */
		base &= ~KERNBASE;
		base = ctob(Sysmap[btop(base)].pg_pfnum) + (base & PGOFSET);
	}
	(void)lseek(fd, base, off);
}

E 11
D 2
ether_print(ea)
	struct ether_addr *ea;
E 2
I 2
ether_print(cp)
	u_char *cp;
E 2
{
D 2
	u_char *cp = &ea->ether_addr_octet[0];

E 2
	printf("%x:%x:%x:%x:%x:%x", cp[0], cp[1], cp[2], cp[3], cp[4], cp[5]);
}

ether_aton(a, n)
	char *a;
D 2
	struct ether_addr *n;
E 2
I 2
	u_char *n;
E 2
{
	int i, o[6];

	i = sscanf(a, "%x:%x:%x:%x:%x:%x", &o[0], &o[1], &o[2],
					   &o[3], &o[4], &o[5]);
	if (i != 6) {
		fprintf(stderr, "arp: invalid Ethernet address '%s'\n", a);
		return (1);
	}
	for (i=0; i<6; i++)
D 2
		n->ether_addr_octet[i] = o[i];
E 2
I 2
		n[i] = o[i];
E 2
	return (0);
}

usage()
{
D 11
	printf("Usage: arp hostname\n");
E 11
I 11
	printf("usage: arp hostname\n");
E 11
	printf("       arp -a [/vmunix] [/dev/kmem]\n");
	printf("       arp -d hostname\n");
D 10
	printf("       arp -s hostname ether_addr [temp] [pub]\n");
E 10
I 10
	printf("       arp -s hostname ether_addr [temp] [pub] [trail]\n");
E 10
	printf("       arp -f filename\n");
I 11
	exit(1);
E 11
}
E 1
