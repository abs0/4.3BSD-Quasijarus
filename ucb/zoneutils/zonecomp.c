/*
 * Michael Sokolov's Domain Name Server (MSDNS)
 *
 * This utility compiles RFC 1035 master files into our binary format.
 */

#ifndef lint
static char sccsid[] = "@(#)zonecomp.c	1.6 (IFCTF) 2011/12/24";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>

extern long atol();
extern char *malloc();

FILE *outf;

struct origin {
	int	or_set;
	int	or_len;
	u_char	or_binary[256];
};

compile_dname_part(text, buf, lenp, filename, lineno)
	char *text, *filename;
	u_char *buf;
	int *lenp;
{
	register u_char *dp = buf;
	u_char *lp;
	int len = 0;
	int lablen;
	register char *cp;
	register int c, i;
	int traildot;

	if (!text[0]) {
		fprintf(stderr,
			"%s: line %d: \"\" is not a valid domain name\n",
			filename, lineno);
		exit(1);
	}
	for (cp = text; *cp; ) {
		if (*cp == '.') {
			if (!cp[1]) {
				traildot = 1;
				goto out;
			}
			fprintf(stderr,
		"%s: line %d: %s: leading or repeated dot in a domain name\n",
				filename, lineno, text);
			exit(1);
		}
		if (len >= 255) {
dn_too_long:		fprintf(stderr,
				"%s: line %d: domain name is too long\n",
				filename, lineno);
			exit(1);
		}
		lp = dp++;
		len++;
		for (lablen = 0; *cp && *cp != '.'; lablen++) {
			if (lablen >= MAXLABEL) {
				fprintf(stderr,
			"%s: line %d: %s: domain name label is too long\n",
					filename, lineno, text);
				exit(1);
			}
			if (len >= 255)
				goto dn_too_long;
			c = *cp++;
			if (c == '\\') {
				if (!*cp) {
					fprintf(stderr,
					"%s: line %d: %s: dangling \'\\\'\n",
						filename, lineno, text);
					exit(1);
				}
				if (isdigit(*cp)) {
					c = 0;
					for (i = 0; i < 3 && isdigit(*cp); i++){
						c *= 10;
						c += *cp++ - '0';
					}
				} else
					c = *cp++;
			}
			*dp++ = c;
			len++;
		}
		*lp = lablen;
		if (!*cp) {
			traildot = 0;
			goto out;
		}
		cp++;	/* skip over the dot */
	}
	traildot = 1;
out:	*lenp = len;
	return(traildot);
}

compile_dname(arg, origin, buf, filename, lineno)
	char *arg, *filename;
	register u_char *buf;
	register struct origin *origin;
{
	int len;
	register int totlen;

	if (!strcmp(arg, "@"))
		len = 0;
	else if (compile_dname_part(arg, buf, &len, filename, lineno)) {
		buf[len] = 0;
		return(len + 1);
	}
	if (!origin || !origin->or_set) {
		fprintf(stderr,
		"%s: line %d: relative domain name with no origin defined\n",
			filename, lineno);
		exit(1);
	}
	totlen = len + origin->or_len;
	if (totlen > 255) {
		fprintf(stderr,
			"%s: line %d: domain name + origin is too long\n",
			filename, lineno);
		exit(1);
	}
	bcopy(origin->or_binary, buf + len, origin->or_len);
	buf[totlen] = 0;
	return(totlen + 1);
}

compile_charstring(text, buf, filename, lineno)
	char *text, *filename;
	u_char *buf;
{
	register u_char *dp = buf + 1;
	int len;
	register char *cp = text;
	register int c, i;

	for (len = 0; *cp; len++) {
		if (len >= 255) {
			fprintf(stderr,
				"%s: line %d: character-string is too long\n",
				filename, lineno);
			exit(1);
		}
		c = *cp++;
		if (c == '\\') {
			if (!*cp) {
				fprintf(stderr,
					"%s: line %d: %s: dangling \'\\\'\n",
					filename, lineno, text);
				exit(1);
			}
			if (isdigit(*cp)) {
				c = 0;
				for (i = 0; i < 3 && isdigit(*cp); i++){
					c *= 10;
					c += *cp++ - '0';
				}
			} else
				c = *cp++;
		}
		*dp++ = c;
	}
	buf[0] = len;
	return(len + 1);
}

struct token_parse_state {
	FILE	*filep;
	char	*filename;
	int	*lineno;
	int	in_paren;
	char	*line;
};

char *
get_token(state)
	register struct token_parse_state *state;
{
	static char contline[512];
	register char *cp = state->line;
	char *np;

restart:
	while (isspace(*cp))
		cp++;
	if (!*cp || *cp == ';') {
		if (!state->in_paren) {
			state->line = cp;
			return(NULL);
		}
		if (!fgets(contline, sizeof contline, state->filep)) {
			fprintf(stderr, "%s: EOF within parentheses\n",
				state->filename);
			exit(1);
		}
		++*state->lineno;
		cp = contline;
		goto restart;
	}
	if (*cp == '(') {
		cp++;
		if (state->in_paren) {
			fprintf(stderr, "%s: line %d: nested \'(\'\n",
				state->filename, *state->lineno);
			exit(1);
		}
		state->in_paren = 1;
		goto restart;
	}
	if (*cp == ')') {
		cp++;
		if (!state->in_paren) {
			fprintf(stderr, "%s: line %d: unmatched \')\'\n",
				state->filename, *state->lineno);
			exit(1);
		}
		state->in_paren = 0;
		goto restart;
	}
	if (*cp == '\"') {
		for (np = ++cp; *cp && *cp != '\"'; )
			if (*cp++ == '\\' && *cp)
				cp++;
		if (*cp != '\"') {
			fprintf(stderr,
				"%s: line %d: unterminated quoted string\n",
				state->filename, *state->lineno);
			exit(1);
		}
		*cp++ = '\0';
		state->line = cp;
		return(np);
	}
	for (np = cp; *cp && !isspace(*cp); cp++)
		if (*cp == ';' || *cp == '(' || *cp == ')' || *cp == '\"') {
			fprintf(stderr,
	"%s: line %d: UNIMPLEMENTED: unquoted token ending in special char\n",
				state->filename, *state->lineno);
			exit(1);
		}
	if (isspace(*cp))
		*cp++ = '\0';
	state->line = cp;
	return(np);
}

is_num_string(s)
	char *s;
{
	register char *cp = s;

	if (!*cp)
		return(0);
	while (*cp)
		if (!isdigit(*cp++))
			return(0);
	return(1);
}

struct typekw {
	char	*kw;
	int	typeval;
} rr_types[] = {
	{"A", T_A},
	{"CNAME", T_CNAME},
	{"HINFO", T_HINFO},
	{"MB", T_MB},
	{"MD", T_MD},
	{"MF", T_MF},
	{"MG", T_MG},
	{"MINFO", T_MINFO},
	{"MR", T_MR},
	{"MX", T_MX},
	{"NS", T_NS},
	{"PTR", T_PTR},
	{"SOA", T_SOA},
	{"TXT", T_TXT},
	{"WKS", T_WKS},
	{NULL, 0}
};

get_rr_type(str)
	register char *str;
{
	register struct typekw *kwp;

	for (kwp = rr_types; kwp->kw; kwp++)
		if (!strcmp(kwp->kw, str))
			return(kwp->typeval);
	return(-1);
}

compile_rr(filename, lineno, owner, rr, origin, class, ttl, filep)
	char *filename, *owner, *rr;
	register struct origin *origin;
	int *lineno, *class;
	u_long *ttl;
	FILE *filep;
{
	u_char ownerbin[MAXDNAME], rdata[9000], *rdptr;
	int ownerbin_len;
	int type;
	struct rrfixed fix;
	struct token_parse_state tokstate;
	register char *token;
	register int i;
	u_long ul;
	int wksmax;

	ownerbin_len = compile_dname(owner, origin, ownerbin,
					filename, *lineno);
	tokstate.filep = filep;
	tokstate.filename = filename;
	tokstate.lineno = lineno;
	tokstate.in_paren = 0;
	tokstate.line = rr;

	for (;;) {
		token = get_token(&tokstate);
		if (!token) {
			fprintf(stderr, "%s: line %d: RR type missing\n",
				filename, *lineno);
			exit(1);
		}
		if (is_num_string(token))
			*ttl = atol(token);
		else if (!strcmp(token, "IN"))
			*class = C_IN;
		else if (!strcmp(token, "CS"))
			*class = C_CS;
		else if (!strcmp(token, "CH"))
			*class = C_CHAOS;
		else if (!strcmp(token, "HS"))
			*class = C_HS;
		else
			break;
	}
	type = get_rr_type(token);
	if (type < 0) {
		fprintf(stderr, "%s: line %d: %s: unknown type/class keyword\n",
			filename, *lineno, token);
		exit(1);
	}
	if (!*class) {
		fprintf(stderr, "%s: line %d: RR class isn't set\n",
			filename, *lineno);
		exit(1);
	}

	rdptr = rdata;
	switch (type) {
	/* all the simple domain-name ones */
	case T_CNAME:
	case T_MB:
	case T_MD:
	case T_MF:
	case T_MG:
	case T_MR:
	case T_NS:
	case T_PTR:
		token = get_token(&tokstate);
		if (!token) {
rdata_missing:		fprintf(stderr, "%s: line %d: RDATA missing\n",
				filename, *lineno);
			exit(1);
		}
		rdptr += compile_dname(token, origin, rdptr, filename, *lineno);
		break;
	/* other class-independent types */
	case T_HINFO:
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		rdptr += compile_charstring(token, rdptr, filename, *lineno);
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		rdptr += compile_charstring(token, rdptr, filename, *lineno);
		break;
	case T_MINFO:
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		rdptr += compile_dname(token, origin, rdptr, filename, *lineno);
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		rdptr += compile_dname(token, origin, rdptr, filename, *lineno);
		break;
	case T_MX:
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		if (!is_num_string(token)) {
num_expected:		fprintf(stderr, "%s: line %d: numeric value expected\n",
				filename, *lineno);
			exit(1);
		}
		i = atoi(token);
		PUTSHORT(i, rdptr);
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		rdptr += compile_dname(token, origin, rdptr, filename, *lineno);
		break;
	case T_SOA:
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		rdptr += compile_dname(token, origin, rdptr, filename, *lineno);
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		rdptr += compile_dname(token, origin, rdptr, filename, *lineno);
		for (i = 0; i < 5; i++) {
			token = get_token(&tokstate);
			if (!token)
				goto rdata_missing;
			if (!is_num_string(token))
				goto num_expected;
			ul = atol(token);
			PUTLONG(ul, rdptr);
		}
		break;
	case T_TXT:
		for (i = 0; token = get_token(&tokstate); i++) {
			if (i >= 16) {
				fprintf(stderr,
		"%s: line %d: TXT record implementation limit exceeded\n",
					filename, *lineno);
				exit(1);
			}
			rdptr += compile_charstring(token, rdptr, filename,
							*lineno);
		}
		if (!i) {
			fprintf(stderr,
	"%s: line %d: TXT record requires at least one character-string\n",
				filename, *lineno);
			exit(1);
		}
		break;
	/* IN-specific */
	case T_A:
		if (*class != C_IN) {
not_in_class:		fprintf(stderr,
		"%s: line %d: %s records are only supported for class IN\n",
				filename, *lineno, token);
			exit(1);
		}
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		ul = inet_addr(token);
		if (ul == INADDR_NONE) {
invalid_ipv4:		fprintf(stderr, "%s: line %d: A %s: invalid address\n",
				filename, *lineno, token);
			exit(1);
		}
		bcopy(&ul, rdptr, 4);
		rdptr += 4;
		break;
	case T_WKS:
		if (*class != C_IN)
			goto not_in_class;
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		ul = inet_addr(token);
		if (ul == INADDR_NONE)
			goto invalid_ipv4;
		bcopy(&ul, rdptr, 4);
		rdptr += 4;
		/* protocol */
		token = get_token(&tokstate);
		if (!token)
			goto rdata_missing;
		if (!is_num_string(token)) {
wks_mnemonic:		fprintf(stderr,
				"%s: line %d: WKS mnemonics not implemented\n",
				filename, *lineno);
			exit(1);
		}
		*rdptr++ = atoi(token);
		/* the fun part */
		bzero(rdptr, 8192);
		wksmax = 0;
		while (token = get_token(&tokstate)) {
			if (!is_num_string(token))
				goto wks_mnemonic;
			i = atoi(token);
			if (i < 0 || i > 65535) {
				fprintf(stderr,
				"%s: line %d: %s: invalid WKS port number\n",
					filename, *lineno, token);
				exit(1);
			}
			rdptr[i>>3] |= 0x80 >> (i & 7);
			if (i > wksmax)
				wksmax = i;
		}
		rdptr += (wksmax + 8) >> 3;
		break;
	default:
		fprintf(stderr,
			"%s: line %d: BUG: RDATA not handled for type %d\n",
			filename, *lineno, type);
		exit(1);
	}

	/* output */
	fix.type = htons(type);
	fix.class = htons(*class);
	fix.ttl = htonl(*ttl);
	fix.rdlength = htons(rdptr - rdata);
	fwrite(ownerbin, 1, ownerbin_len, outf);
	fwrite(&fix, 1, RRFIXEDSZ, outf);
	fwrite(rdata, 1, rdptr - rdata, outf);
}

parse_file(srcfile, srcf, origin)
	char *srcfile;
	FILE *srcf;
	register struct origin *origin;
{
	char owner[256];
	char linebuf[512];
	int lineno;
	register char *cp, *a1, *a2;
	int class;
	u_long ttl;
	struct origin include_origin;
	FILE *incf;

	owner[0] = '\0';
	class = 0;
	ttl = 0;
	for (lineno = 1; fgets(linebuf, sizeof linebuf, srcf); lineno++) {
		if (!linebuf[0] || linebuf[0] == ';')
			continue;
		if (isspace(linebuf[0])) {
			for (cp = linebuf; isspace(*cp); cp++)
				;
			if (!*cp || *cp == ';')
				continue;
			if (!owner[0]) {
				fprintf(stderr,
					"%s: line %d: RR with no owner\n",
					srcfile, lineno);
				exit(1);
			}
			compile_rr(srcfile, &lineno, owner, cp, origin,
				   &class, &ttl, srcf);
		} else {
			for (cp = linebuf; *cp && !isspace(*cp); cp++)
				;
			if (!*cp) {
syntaxerr:			fprintf(stderr, "%s: line %d: invalid syntax\n",
					srcfile, lineno);
				exit(1);
			}
			*cp++ = '\0';
			while (isspace(*cp))
				cp++;
			if (!*cp || *cp == ';')
				goto syntaxerr;
			if (!strcmp(linebuf, "$ORIGIN")) {
				for (a1 = cp; *cp && !isspace(*cp); cp++)
					;
				if (*cp)
					*cp++ = '\0';
				if (!compile_dname_part(a1, origin->or_binary,
					&origin->or_len, srcfile, lineno)) {
					fprintf(stderr,
				"%s: line %d: $ORIGIN must be absolute\n",
						srcfile, lineno);
					exit(1);
				}
				origin->or_set = 1;
			} else if (!strcmp(linebuf, "$INCLUDE")) {
				for (a1 = cp; *cp && !isspace(*cp); cp++)
					;
				if (*cp)
					*cp++ = '\0';
				while (isspace(*cp))
					cp++;
				if (!*cp || *cp == ';')
					bcopy(origin, &include_origin,
						sizeof(struct origin));
				else {
				    for (a2 = cp; *cp && !isspace(*cp); )
					cp++;
				    if (*cp)
					*cp++ = '\0';
				    include_origin.or_len = compile_dname(a2,
					origin, include_origin.or_binary,
					srcfile, lineno) - 1;
				    include_origin.or_set = 1;
				}
				incf = fopen(a1, "r");
				if (!incf) {
					perror(a1);
					exit(1);
				}
				parse_file(a1, incf, &include_origin);
			} else {
				if (strlen(linebuf)+1 > sizeof owner) {
					fprintf(stderr,
				"%s: line %d: the RR owner name is too long\n",
						srcfile, lineno);
					exit(1);
				}
				strcpy(owner, linebuf);
				compile_rr(srcfile, &lineno, owner, cp, origin,
					   &class, &ttl, srcf);
			}
		}
	}
	fclose(srcf);
}

main(argc, argv)
	char **argv;
{
	static char magic[] = "BINZONE\200";
	struct origin origin;
	char *srcfile, *immed_output, *final_output;
	extern char *optarg;
	extern int optind;
	register int c;
	FILE *srcf;

	origin.or_set = 0;
	immed_output = NULL;
	while ((c = getopt(argc, argv, "o:O:")) != EOF)
		switch (c) {
		case 'o':
			if (immed_output)
				goto usage;
			immed_output = optarg;
			continue;
		case 'O':
			compile_dname_part(optarg, origin.or_binary,
					   &origin.or_len, optarg, 0);
			origin.or_set = 1;
			continue;
		default:
		usage:
			fprintf(stderr,
			"usage: %s [-o outfile] [-O origin] masterfile\n",
				argv[0]);
			exit(1);
		}
	if (argc - optind != 1)
		goto usage;
	srcfile = argv[optind];

	srcf = fopen(srcfile, "r");
	if (!srcf) {
		perror(srcfile);
		exit(1);
	}

	if (immed_output)
		final_output = NULL;
	else {
		c = strlen(srcfile) + 5;
		final_output = malloc(c);
		if (!final_output) {
mallocfail:		perror("malloc");
			exit(1);
		}
		strcpy(final_output, srcfile);
		strcat(final_output, ".bin");
		immed_output = malloc(c);
		if (!immed_output)
			goto mallocfail;
		strcpy(immed_output, srcfile);
		strcat(immed_output, ".tmp");
	}

	outf = fopen(immed_output, "w");
	if (!outf) {
		perror(immed_output);
		exit(1);
	}
	fwrite(magic, 1, 8, outf);
	parse_file(srcfile, srcf, &origin);
	fclose(outf);

	if (final_output && rename(immed_output, final_output) < 0) {
		fprintf(stderr, "%s: unable to rename final output to %s\n",
			argv[0], final_output);
		exit(1);
	}
	exit(0);
}
