h20082
s 00402/00000/00000
d D 5.1 04/09/03 21:52:26 msokolov 1 0
c date and time created 04/09/03 21:52:26 by msokolov
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <sys/param.h>
#include <sys/file.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

extern char *malloc();
extern int optind;
extern char *optarg;

#define	CFSTATE_GROUND	0
#define	CFSTATE_OPTSET	1
#define	CFSTATE_MAND	2

#define	MASK_DOC	1
#define	MASK_BANNER	2
#define	MASK_ALL	3

#define	OPTHASH_SIZE	61
#define	MAXOPTSETS	10
#define	OPTNAMEMAX	15

struct option {
	char	name[OPTNAMEMAX+1];
	struct	optset *set;
	char	*emitline;
	int	x;
	int	y;
	int	not_banner;
	int	suppress_banner;
	struct	option *nextinset;
	struct	option *nextinhash;
};

struct optset {
	struct	option *firstopt;
	struct	option *docsel;
	struct	option *bannersel;
	int	pagesize;
};

char *printer = "lp";
char *options;
int ncopies = 1;
char spdconf_file[] = "setpagedevice.conf";
FILE *docopts, *banneropts;
int cf_state;
struct optset optsettab[MAXOPTSETS], *curoptset;
int noptsets;
struct option *opthash[OPTHASH_SIZE];
int mandblock_mask;
int suppress_banner;

struct option *findopt();

main(argc, argv)
	char **argv;
{
	register FILE *cf;
	register int c, i, fd;
	register char *cp;
	char line[BUFSIZ];
	register struct option *opt;

	while ((c = getopt(argc, argv, "P:O:#:")) > 0)
		switch (c) {
		case 'P':
			printer = optarg;
			continue;
		case 'O':
			options = optarg;
			continue;
		case '#':
			ncopies = atoi(optarg);
			continue;
		case '?':
			exit(1);
		}
	cf = fopen(spdconf_file, "r");
	if (!cf) {
		perror(spdconf_file);
		exit(1);
	}
	cp = "docopts.ps";
	fd = open(cp, O_WRONLY|O_CREAT|O_TRUNC, 0640);
	if (fd < 0) {
		perror(cp);
		exit(1);
	}
	docopts = fdopen(fd, "w");
	cp = "banneropts.ps";
	fd = open(cp, O_WRONLY|O_CREAT|O_TRUNC, 0640);
	if (fd < 0) {
		perror(cp);
		exit(1);
	}
	banneropts = fdopen(fd, "w");
	fputs("%!\n<<\n", docopts);
	fputs("%!\n<<\n", banneropts);
	while (fgets(line, BUFSIZ, cf)) {
		cp = index(line, '\n');
		if (cp)
			*cp = '\0';
		c = line[0];
		if (c == '\0' || c == '%')
			continue;
		else if (!isspace(c))
			process_headline(line);
		else {
			for (cp = line + 1; isspace(*cp); cp++)
				;
			c = *cp;
			if (c == '\0' || c == '%')
				continue;
			process_ind_line(cp);
		}
	}
	fclose(cf);
	if (options)
		process_options(options);
	for (i = 0; i < noptsets; i++) {
		curoptset = optsettab + i;
		opt = curoptset->docsel;
		if (opt) {
			if (curoptset->pagesize) {
				fprintf(docopts, "\t/PageSize [%d %d]\n",
					opt->x, opt->y);
			}
			if (opt->emitline)
				fprintf(docopts, "\t%s\n", opt->emitline);
		}
		opt = curoptset->bannersel;
		if (opt) {
			if (curoptset->pagesize) {
				fprintf(banneropts, "\t/PageSize [%d %d]\n",
					opt->x, opt->y);
			}
			if (opt->emitline)
				fprintf(banneropts, "\t%s\n", opt->emitline);
		}
	}
	fputs(">> setpagedevice\n", docopts);
	fclose(docopts);
	fputs(">> setpagedevice\n", banneropts);
	fclose(banneropts);
	return(0);
}

process_headline(line)
	register char *line;
{
	register char *cp;

	cf_state = CFSTATE_GROUND;
	for (cp = line; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	if (!strcmp(line, "optset"))
		optset_begin(cp);
	else if (!strcmp(line, "mandatory"))
		mandblock_begin(cp);
	else if (!strcmp(line, "#")) {
		fprintf(docopts, "\t/NumCopies %d\n", ncopies);
		fprintf(banneropts, "\t/NumCopies 1\n");
	} else {
		fprintf(stderr, "%s: invalid directive: %s\n", spdconf_file,
			line);
		exit(1);
	}
}

process_ind_line(line)
	char *line;
{
	switch (cf_state) {
	case CFSTATE_OPTSET:
		optset_indline(line);
		break;
	case CFSTATE_MAND:
		mandblock_indline(line);
		break;
	default:
		fprintf(stderr, "%s: indented line out of place\n",
			spdconf_file);
		exit(1);
	}
}

optset_begin(line)
	char *line;
{
	register char *cp, *np;

	if (noptsets >= MAXOPTSETS) {
		fprintf(stderr, "%s: too many optsets\n", spdconf_file);
		exit(1);
	}
	curoptset = optsettab + noptsets;
	noptsets++;
	bzero(curoptset, sizeof(struct optset));
	for (cp = line; ; ) {
		while (*cp && isspace(*cp))
			cp++;
		if (*cp == '\0' || *cp == '%')
			break;
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		if (!strcmp(np, "pagesize"))
			curoptset->pagesize = 1;
		else {
			fprintf(stderr, "%s: invalid optset qualifier: %s\n",
				spdconf_file, np);
			exit(1);
		}
	}
	cf_state = CFSTATE_OPTSET;
}

optset_indline(line)
	char *line;
{
	register char *optname;
	register char *cp, *np;
	register struct option *opt, **hb;

	for (cp = optname = line; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	if ((cp - optname) > OPTNAMEMAX) {
		fprintf(stderr, "%s: %s: option name too long\n", spdconf_file,
			optname);
		exit(1);
	}
	opt = findopt(optname);
	if (opt) {
		fprintf(stderr, "%s: %s: option redefinition\n", spdconf_file,
			optname);
		exit(1);
	}
	while (isspace(*cp))
		cp++;
	opt = (struct option *) malloc(sizeof(struct option));
	if (!opt) {
		perror("malloc");
		exit(1);
	}
	bzero(opt, sizeof(struct option));
	strcpy(opt->name, optname);
	opt->set = curoptset;
	opt->nextinset = curoptset->firstopt;
	curoptset->firstopt = opt;
	hb = opthash + hashopt(optname);
	opt->nextinhash = *hb;
	*hb = opt;
	while (isalpha(*cp)) {
		for (np = cp; isalpha(*cp); cp++)
			;
		if (isspace(*cp))
			*cp++ = '\0';
		if (!strcmp(np, "def"))
			curoptset->docsel = curoptset->bannersel = opt;
		else if (!strcmp(np, "nb"))
			opt->not_banner = 1;
		else if (!strcmp(np, "sb"))
			opt->suppress_banner = 1;
		else {
			fprintf(stderr,
				"%s: %s: invalid option qualifier: %s\n",
				spdconf_file, optname, np);
			exit(1);
		}
		while (isspace(*cp))
			cp++;
	}
	if (curoptset->pagesize) {
		if (!isdigit(*cp)) {
invpagesize:		fprintf(stderr,
			"%s: %s: invalid or missing page size specification\n",
				spdconf_file, optname);
			exit(1);
		}
		for (np = cp; isdigit(*cp); cp++)
			;
		if (isspace(*cp))
			*cp++ = '\0';
		else if (*cp)
			goto invpagesize;
		opt->x = atoi(np);
		while (isspace(*cp))
			cp++;
		if (!isdigit(*cp))
			goto invpagesize;
		for (np = cp; isdigit(*cp); cp++)
			;
		if (isspace(*cp))
			*cp++ = '\0';
		else if (*cp)
			goto invpagesize;
		opt->y = atoi(np);
		while (isspace(*cp))
			cp++;
	}
	if (*cp && *cp != '%') {
		np = malloc(strlen(cp) + 1);
		if (!np) {
			perror("malloc");
			exit(1);
		}
		strcpy(np, cp);
		opt->emitline = np;
	}
}

mandblock_begin(line)
	char *line;
{
	register char *cp, *np;

	mandblock_mask = MASK_ALL;
	for (cp = line; ; ) {
		while (*cp && isspace(*cp))
			cp++;
		if (*cp == '\0' || *cp == '%')
			break;
		for (np = cp; *cp && !isspace(*cp); cp++)
			;
		if (*cp)
			*cp++ = '\0';
		if (!strcmp(np, "doconly"))
			mandblock_mask = MASK_DOC;
		else if (!strcmp(np, "banneronly"))
			mandblock_mask = MASK_BANNER;
		else {
			fprintf(stderr,
				"%s: invalid mandatory block qualifier: %s\n",
				spdconf_file, np);
			exit(1);
		}
	}
	cf_state = CFSTATE_MAND;
}

mandblock_indline(line)
	char *line;
{
	if (mandblock_mask & MASK_DOC)
		fprintf(docopts, "\t%s\n", line);
	if (mandblock_mask & MASK_BANNER)
		fprintf(banneropts, "\t%s\n", line);
}

hashopt(optname)
	char *optname;
{
	u_long accum;
	u_char *cp;

	for (accum = 0, cp = (u_char*)optname; *cp; cp++)
		accum += *cp;
	return(accum % OPTHASH_SIZE);
}

struct option *
findopt(optname)
	register char *optname;
{
	register struct option *opt;

	for (opt = opthash[hashopt(optname)]; opt; opt = opt->nextinhash)
		if (!strcmp(opt->name, optname))
			break;
	return(opt);
}

process_options(options)
	char *options;
{
	register char *cp, *np;
	register struct option *opt;

	for (cp = options; cp; cp = np) {
		np = index(cp, ',');
		if (np)
			*np++ = '\0';
		opt = findopt(cp);
		if (!opt)			/* ignore unknown options */
			continue;
		opt->set->docsel = opt;
		if (!opt->not_banner)
			opt->set->bannersel = opt;
		if (opt->suppress_banner)
			suppress_banner = 1;
	}
}
E 1
