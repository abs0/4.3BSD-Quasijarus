h48330
s 00004/00006/00131
d D 1.7 88/03/04 16:22:36 bostic 7 6
c move UNIX out; retry is local, check dv_name itself, minor cleanup
e
s 00027/00067/00110
d D 1.6 87/04/02 16:28:31 karels 6 5
c use "opendev" instead of contructing dev by hand
e
s 00002/00002/00175
d D 1.5 86/12/18 23:51:57 karels 5 4
c eliminate magic constants
e
s 00023/00001/00154
d D 1.4 86/11/25 17:06:28 sam 4 3
c kdb additions
e
s 00007/00006/00148
d D 1.3 86/11/25 16:44:23 karels 3 2
c compensate for lack of r10 from CP
e
s 00071/00033/00083
d D 1.2 86/07/16 08:31:54 sam 2 1
c handle revised boot device encoding; change disk names (more work)
e
s 00116/00000/00000
d D 1.1 86/01/12 18:04:56 sam 1 0
c date and time created 86/01/12 18:04:56 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/
D 2
/*	boot.c	6.1	83/07/29	*/
E 2

#include "../machine/mtpr.h"

#include "param.h"
#include "inode.h"
#include "fs.h"
#include "vm.h"
#include "saio.h"
#include "reboot.h"

#include <a.out.h>

/*
 * Boot program... arguments passed in r10 and r11 determine
 * whether boot stops to ask for system name and which device
 * boot comes from.
 */

D 2
/*	r11 = 0 -> automatic boot, load file '/vmunix' */
/*	r11 = 1 -> ask user for file to load */

E 2
D 6
/* Types in r10 specifying major device */
D 2
char	devname[][3] = {
	'f','s','d',	/* 0 = fsd */
	's','m','d',	/* 1 = smd or cmd */
	'x','f','d',	/* 2 = xfd */
	'x','s','d',	/* 2 = xsd */
	'c','y','p',	/* 3 = cypher tape */
E 2
I 2
char	devname[][2] = {
D 3
#ifdef notyet
E 3
	0, 0,		/* 0 = ud */
D 3
	'd','k',	/* 1 = vd */
E 3
I 3
	'd','k',	/* 1 = vd/dk */
E 3
	0, 0,		/* 2 = xp */
	'c','y',	/* 3 = cy */
D 3
#else
	'd','k',	/* default = vd */
#endif
E 3
E 2
};
I 2
#define	MAXTYPE	(sizeof(devname) / sizeof(devname[0]))
E 6
I 3
#define	DEV_DFLT	1		/* vd/dk */
E 3
E 2

D 2
#ifdef FSD
char line[100] = "fsd(0,0)vmunix";
#endif
#ifdef SMD
char line[100] = "smd(0,0)vmunix";
#endif
#ifdef XFD
char line[100] = "xfd(0,0)vmunix";
#endif
#ifdef XSD
char line[100] = "xsd(0,0)vmunix";
#endif
#ifdef JUSTASK
E 2
I 2
D 6
#define	UNIX	"vmunix"
E 6
I 6
D 7
#define	UNIX	"/vmunix"
E 7
E 6
E 2
char line[100];
D 2
#endif
E 2

D 7
int	retry = 0;
E 7
I 6
extern	unsigned opendev;
extern	unsigned bootdev;
E 6

main()
{
D 6
	register dummy;		/* skip r12 */
	register howto, devtype;	/* howto=r11, devtype=r10 */
D 2
	int io;
E 2
I 2
	int io, i;
	register type, part, unit;
	register char *cp;
	long atol();
E 6
I 6
	register char *cp;		/* skip r12 */
D 7
	register unsigned howto, devtype;	/* howto=r11, devtype=r10 */
	int io, type;
E 7
I 7
	register u_int howto, devtype;	/* howto=r11, devtype=r10 */
	int io, retry, type;
E 7
E 6
E 2

I 2
D 6

E 6
E 2
#ifdef lint
	howto = 0; devtype = 0;
#endif
I 6
	if ((devtype & B_MAGICMASK) != B_DEVMAGIC)
		devtype = DEV_DFLT << B_TYPESHIFT;	/* unit, partition 0 */
	bootdev = devtype;
	printf("\nBoot\n");
E 6
D 2
	printf("\nBoot\n");
E 2
#ifdef JUSTASK
	howto = RB_ASKNAME|RB_SINGLE;
I 2
#else
I 3
D 6
	if ((devtype & B_MAGICMASK) != B_DEVMAGIC)
		devtype = DEV_DFLT << B_TYPESHIFT;	/* unit, partition 0 */
E 3
	type = (devtype >> B_TYPESHIFT) & B_TYPEMASK;
	unit = (devtype >> B_UNITSHIFT) & B_UNITMASK;
	unit += 8 * ((devtype >> B_ADAPTORSHIFT) & B_ADAPTORMASK);
	part = (devtype >> B_PARTITIONSHIFT) & B_PARTITIONMASK;
E 6
	if ((howto & RB_ASKNAME) == 0) {
D 6
		if (type >= 0 && type <= MAXTYPE && devname[type][0]) {
			cp = line;
			*cp++ = devname[type][0];
			*cp++ = devname[type][1];
			*cp++ = '(';
			if (unit >= 10)
				*cp++ = unit / 10 + '0';
			*cp++ = unit % 10 + '0';
			*cp++ = ',';
D 3
			*cp++ = part + '0';
E 3
I 3
			if (part >= 10)
				*cp++ = part / 10 + '0';
			*cp++ = part % 10 + '0';
E 3
			*cp++ = ')';
			strcpy(cp, UNIX);
		} else
			howto = RB_SINGLE|RB_ASKNAME;
E 6
I 6
		type = (devtype >> B_TYPESHIFT) & B_TYPEMASK;
D 7
		if ((unsigned)type < ndevs && devsw[type].dv_name[0])
E 7
I 7
		if ((unsigned)type < ndevs && devsw[type].dv_name)
E 7
			strcpy(line, UNIX);
		else
			howto |= RB_SINGLE|RB_ASKNAME;
E 6
	}
E 2
#endif
D 7
	for (;;) {
E 7
I 7
	for (retry = 0;;) {
E 7
I 2
D 6
		printf("\nBoot\n");
E 6
E 2
		if (howto & RB_ASKNAME) {
			printf(": ");
			gets(line);
I 6
			if (line[0] == 0) {
				strcpy(line, UNIX);
				printf(": %s\n", line);
			}
E 6
		} else
			printf(": %s\n", line);
		io = open(line, 0);
D 2
		if (io >= 0)
			copyunix(howto, io);
E 2
I 2
		if (io >= 0) {
D 6
			if (howto & RB_ASKNAME) {
				/*
				 * Build up devtype register to pass on to
				 * booted program.
				 */ 
				cp = line;
				for (i = 0; i <= MAXTYPE; i++)
					if ((devname[i][0] == cp[0]) && 
					    (devname[i][1] == cp[1]))
					    	break;
				if (i <= MAXTYPE) {
					devtype = i << B_TYPESHIFT;
					cp += 3;
					i = *cp++ - '0';
					if (*cp >= '0' && *cp <= '9')
						i = i * 10 + *cp++ - '0';
					cp++;
					devtype |= ((i % 8) << B_UNITSHIFT);
					devtype |= ((i / 8) << B_ADAPTORSHIFT);
					devtype |= atol(cp) << B_PARTITIONSHIFT;
				}
			}
			devtype |= B_DEVMAGIC;
			copyunix(howto, devtype, io);
E 6
I 6
			copyunix(howto, opendev, io);
E 6
			close(io);
D 6
			howto = RB_SINGLE|RB_ASKNAME;
E 6
I 6
			howto |= RB_SINGLE|RB_ASKNAME;
E 6
		}
E 2
		if (++retry > 2)
			howto |= RB_SINGLE|RB_ASKNAME;
	}
}

/*ARGSUSED*/
D 2
copyunix(howto, io)
	register io, howto;
E 2
I 2
copyunix(howto, devtype, io)
	register io, howto, devtype;	/* NOTE ORDER */
E 2
{
D 4
	struct exec x;
E 4
I 4
	register int esym;		/* must be r9 */
E 4
	register int i;
D 2
	char *addr;
E 2
I 2
	register char *addr;
I 4
	struct exec x;
E 4
E 2

	i = read(io, (char *)&x, sizeof x);
	if (i != sizeof x ||
D 6
	    (x.a_magic != 0407 && x.a_magic != 0413 && x.a_magic != 0410))
		_stop("Bad format\n");
E 6
I 6
	    (x.a_magic != 0407 && x.a_magic != 0413 && x.a_magic != 0410)) {
		printf("Bad format\n");
		return;
	}
E 6
	printf("%d", x.a_text);
	if (x.a_magic == 0413 && lseek(io, 0x400, 0) == -1)
		goto shread;
D 5
	if (read(io, (char *)0x800, x.a_text) != x.a_text)
E 5
I 5
	if (read(io, (char *)RELOC, x.a_text) != x.a_text)
E 5
		goto shread;
D 5
	addr = (char *)(x.a_text + 0x800);
E 5
I 5
	addr = (char *)(x.a_text + RELOC);
E 5
	if (x.a_magic == 0413 || x.a_magic == 0410)
		while ((int)addr & CLOFSET)
			*addr++ = 0;
	printf("+%d", x.a_data);
	if (read(io, addr, x.a_data) != x.a_data)
		goto shread;
	addr += x.a_data;
	printf("+%d", x.a_bss);
I 4
	if (howto & RB_KDB && x.a_syms) {
		for (i = 0; i < x.a_bss; i++)
			*addr++ = 0;
		*(int *)addr = x.a_syms;		/* symbol table size */
		addr += sizeof (int);
		printf("[+%d", x.a_syms);
		if (read(io, addr, x.a_syms) != x.a_syms)
			goto shread;
		addr += x.a_syms;
		if (read(io, addr, sizeof (int)) != sizeof (int))
			goto shread;
		i = *(int *)addr - sizeof (int);	/* string table size */
		addr += sizeof (int);
		printf("+%d]", i);
		if (read(io, addr, i) != i)
			goto shread;
		addr += i;
		esym = roundup((int)addr, sizeof (int));
		x.a_bss = 0;
	} else
		howto &= ~RB_KDB;
E 4
	x.a_bss += 32*1024;	/* slop */
	for (i = 0; i < x.a_bss; i++)
		*addr++ = 0;
	x.a_entry &= 0x1fffffff;
	printf(" start 0x%x\n", x.a_entry);
	mtpr(PADC, 0);		/* Purge data cache */
	mtpr(PACC, 0);		/* Purge code cache */
D 2
	if ((howto & RB_DCOFF) == 0) 
		mtpr(DCR, 1);	/* Enable data cache */
E 2
I 2
	mtpr(DCR, 1);		/* Enable data cache */
E 2
	(*((int (*)()) x.a_entry))();
I 2
	return;
E 2
shread:
D 6
	_stop("Short read\n");
E 6
I 6
	printf("Short read\n");
	return;
E 6
}
E 1
