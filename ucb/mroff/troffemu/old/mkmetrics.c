#include <sys/param.h>
#include <sys/file.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

extern char *malloc();

#define	HASH_SIZE	61

struct chnamemap {
	char	name[32];
	int	code;
	int	width;
	char	bbox[32];
	struct	chnamemap *next;
};

struct chnamemap *chnamehash[HASH_SIZE];

main(argc, argv)
	char **argv;
{
	argv++;
	argc--;
	if (argc != 1) {
		fputs("usage: mkmetrics afmfil\n", stderr);
		exit(1);
	}
	read_troff_encoding();
	parse_afm_file(argv[0]);
	produce_output();
	return(0);
}

parse_afm_file(afmfile)
	char *afmfile;
{
	register FILE *afm;
	char line[256];			/* AFM spec limits lines to 255 chars */
	int lineno, started = 0, inchmetrics = 0;
	register char *cp, *np;
	register int i, x;
	char *chname, *bbox;

	if ((afm = fopen(afmfile, "r")) == NULL) {
		perror(afmfile);
		exit(1);
	}
	for (lineno = 1; fgets(line, 256, afm); lineno++) {
		for (cp = line; isspace(*cp); cp++)
			;
		if (!*cp)
			continue;
		for (np = cp; *cp; cp++)
			if (isspace(*cp)) {
				*cp++ = '\0';
				break;
			}
		if (!started) {
			if (strcmp(np, "StartFontMetrics")) {
				fprintf(stderr, "%s is not a valid AFM file\n",
					afmfile);
				exit(1);
			}
			started = 1;
			continue;
		}
		if (inchmetrics) {
			if (!strcmp(np, "EndCharMetrics")) {
				inchmetrics = 0;
				continue;
			}
			for (i = x = -1, chname = NULL; ; ) {
				while (isspace(*cp))
					cp++;
				if (!strcmp(np, "B"))
					bbox = cp;
				else if (!strcmp(np, "WX"))
					x = widthtoi(cp);
				else if (!strcmp(np, "N"))
					chname = cp;
				cp = index(cp, ';');
				if (!cp)
					break;
				cp++;
				while (isspace(*cp))
					cp++;
				if (!*cp)
					break;
				for (np = cp; *cp; cp++)
					if (isspace(*cp)) {
						*cp++ = '\0';
						break;
					}
			}
			if ((cp = chname) == NULL)
				continue;
			for (; *cp; cp++)
				if (isspace(*cp) || *cp == ';') {
					*cp = '\0';
					break;
				}
			cp = index(bbox, ';');
			while (isspace(cp[-1]))
				cp--;
			*cp = '\0';
			register_chmetrics(chname, x, bbox);
			continue;
		}
		if (!strcmp(np, "EndFontMetrics")) {
			fclose(afm);
			return(0);
		}
		if (!strcmp(np, "StartCharMetrics")) {
			inchmetrics = 1;
			continue;
		}
	}
	fprintf(stderr, "%s: read error or premature EOF\n", afmfile);
	exit(1);
}

read_troff_encoding()
{
	register FILE *f;
	static char filename[] = "/usr/lib/pstroff/TroffEncoding.ps";
	char line[256];
	register int code = 0;
	register char *cp, *np;

	f = fopen(filename, "r");
	if (!f) {
		perror(filename);
		exit(1);
	}
	/* skip the first 3 lines */
	fgets(line, 256, f);
	fgets(line, 256, f);
	fgets(line, 256, f);
	while (fgets(line, 256, f)) {
		for (cp = line; ; ) {
			while (isspace(*cp))
				cp++;
			switch (*cp++) {
			case '\0':
			case '%':
				goto nextline;
			case ']':
				fclose(f);
				return(0);
			case '/':
				for (np = cp; *cp; cp++) {
					if (isspace(*cp)) {
						*cp++ = '\0';
						break;
					}
					if (*cp == '%') {
						*cp = '\0';
						break;
					}
				}
				register_chname(code++, np);
				break;
			default:
				fputs("TroffEncoding.ps: parse error\n",
					stderr);
				exit(1);
			}
		}
nextline:	continue;
	}
	fputs("TroffEncoding.ps: read error or premature EOF\n", stderr);
	exit(1);
}

register_chname(code, name)
	int code;
	register char *name;
{
	register struct chnamemap *map;
	register struct chnamemap *np, **npp;

	for (npp = chnamehash + hash_chname(name); np = *npp; npp = &np->next)
		if (!strcmp(np->name, name))
			return;

	map = (struct chnamemap *) malloc(sizeof(struct chnamemap));
	if (!map) {
		perror("malloc");
		exit(1);
	}
	strcpy(map->name, name);
	map->code = code;
	map->width = -1;
	map->next = NULL;
	*npp = map;
}

register_chmetrics(name, width, bbox)
	register char *name;
	int width;
	char *bbox;
{
	register struct chnamemap *map;

	for (map = chnamehash[hash_chname(name)]; map; map = map->next)
		if (!strcmp(map->name, name)) {
			map->width = width;
			strcpy(map->bbox, bbox);
			return;
		}
}

hash_chname(name)
	char *name;
{
	u_long accum;
	u_char *cp;

	for (accum = 0, cp = (u_char*)name; *cp; cp++)
		accum += *cp;
	return(accum % HASH_SIZE);
}

widthtoi(cp)
	register char *cp;
{
	int accum;

	for (accum = 0; isdigit(*cp); cp++)
		accum = accum * 10 + (*cp - '0');
	if (*cp++ != '.')
		return(accum);
	if (*cp >= '5' && *cp <= '9')
		accum++;
	return(accum);
}

produce_output()
{
	register struct chnamemap *map, **hb, **end;

	for (hb = chnamehash, end = hb + HASH_SIZE; map = *hb; hb++)
		for (; map; map = map->next)
			printf("/%s [%d %d 0 %s] rd\n", map->name, map->code,
				map->width, map->bbox);
}
