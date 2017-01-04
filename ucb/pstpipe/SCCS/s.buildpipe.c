h32074
s 00023/00008/00113
d D 5.2 2012/07/23 01:12:16 msokolov 2 1
c updated for the recent changes to pstroff and pstfinish
e
s 00121/00000/00000
d D 5.1 10/10/09 18:56:50 msokolov 1 0
c written, compiles
e
u
U
t
T
I 1
/*
 * This program reads a set of document configuration settings from
 * special header comments in a troff source file and uses them to
 * set up a pipeline invoking pstroff with the right options, preceded
 * by the needed preprocessors and followed by pstfinish if necessary.
 * We construct the pipeline as an sh -c command and then exec /bin/sh.
 *
D 2
 * Written by Michael Sokolov, Quasijarus Project,
E 2
I 2
 * Written by Michael Spacefalcon, Quasijarus Project,
E 2
 * International Free Computing Task Force.
 *
 * This module constructs the pipeline command to be passed to the shell
 * based on the data structures prepared earlier.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <stdio.h>
#include <strings.h>
#include "docreq.h"

D 2
/* these options get set via pstpipe command line */
extern int eightbit_output;
E 2
I 2
/* these options get set via pstpipe command line or auto-determined */
extern int use_bits;
E 2
extern int do_pstfinish;
extern char *pstfinish_minusF;
extern int symbolbugfix;
extern char **sources;
extern int nsources;

char shellcommand[32768];
static char *cmdtailp = shellcommand;
static int sources_done;

static
emit_sources_list()
{
	register int i;

	for (i = 0; i < nsources; i++) {
		*cmdtailp++ = ' ';
		strcpy(cmdtailp, sources[i]);
		cmdtailp = index(cmdtailp, '\0');
	}
	sources_done = 1;
}

static
add_preproc(cmd)
	char *cmd;
{
	strcpy(cmdtailp, cmd);
	cmdtailp = index(cmdtailp, '\0');
	if (!sources_done)
		emit_sources_list();
	*cmdtailp++ = '|';
}

static
add_pstfinish()
{
	strcpy(cmdtailp, "|pstfinish");
	cmdtailp = index(cmdtailp, '\0');
D 2
	if (eightbit_output) {
E 2
I 2
	if (use_bits == 8) {
E 2
		strcpy(cmdtailp, " -8");
		cmdtailp += 3;
	}
D 2
	if (notroffencoding) {
		strcpy(cmdtailp, " -N");
E 2
I 2
	if (pstfinish_req == PSTFINISH_GENTLE) {
		strcpy(cmdtailp, " -g");
E 2
		cmdtailp += 3;
	}
	if (symbolbugfix) {
		strcpy(cmdtailp, " -S");
		cmdtailp += 3;
	}
	if (pstfinish_minusF) {
		sprintf(cmdtailp, " -F%s", pstfinish_minusF);
		cmdtailp = index(cmdtailp, '\0');
	}
	if (languagelevel > 1) {
		sprintf(cmdtailp, " -L%d", languagelevel);
		cmdtailp = index(cmdtailp, '\0');
	}
I 2
	if (pstfinish_doc_opts) {
		*cmdtailp++ = ' ';
		strcpy(cmdtailp, pstfinish_doc_opts);
		cmdtailp = index(cmdtailp, '\0');
	}
E 2
}

build_shell_command()
{
	register int i;
I 2
	int full_finish;
E 2

	for (i = 0; i < npreprocs; i++)
		add_preproc(preprocs[i]);
	strcpy(cmdtailp, "pstroff");
	cmdtailp = index(cmdtailp, '\0');
D 2
	if (do_pstfinish || eightbit_output) {
E 2
I 2
	full_finish = do_pstfinish && pstfinish_req != PSTFINISH_GENTLE;
	if (use_bits == 8 || full_finish) {
E 2
		strcpy(cmdtailp, " -e");
		cmdtailp += 3;
	}
D 2
	if (do_pstfinish || notroffencoding) {
E 2
I 2
	if (use_bits == 7 && doc_text_bits == 8 && !full_finish) {
		strcpy(cmdtailp, " -h");
		cmdtailp += 3;
	}
	if (do_pstfinish) {
E 2
		strcpy(cmdtailp, " -N");
		cmdtailp += 3;
	}
	if (fontlist) {
		sprintf(cmdtailp, " -f%s", fontlist);
I 2
		cmdtailp = index(cmdtailp, '\0');
	}
	if (fontpath) {
		sprintf(cmdtailp, " -F%s", fontpath);
E 2
		cmdtailp = index(cmdtailp, '\0');
	}
	if (macros) {
		*cmdtailp++ = ' ';
		strcpy(cmdtailp, macros);
		cmdtailp = index(cmdtailp, '\0');
	}
	if (!sources_done)
		emit_sources_list();
	else {
		*cmdtailp++ = ' ';
		*cmdtailp++ = '-';
	}
	if (do_pstfinish)
		add_pstfinish();
	*cmdtailp = '\0';
	return(0);
}
E 1
