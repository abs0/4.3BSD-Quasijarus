h41669
s 00015/00018/00644
d D 3.2 88/03/28 12:18:29 bostic 12 11
c add Berkeley specific headers
e
s 00000/00000/00662
d D 3.1 87/08/11 10:21:01 minshall 11 10
c New version numbering.
e
s 00025/00000/00637
d D 1.10 87/07/16 16:03:00 minshall 10 9
c Add sccs, copyrights.
e
s 00001/00001/00636
d D 1.9 87/07/15 15:42:49 minshall 9 8
c Fix bug in parameter to find_input_area.
e
s 00004/00005/00633
d D 1.8 87/07/15 15:27:47 minshall 8 7
c New directory structure.
e
s 00005/00002/00633
d D 1.7 87/07/09 10:42:34 minshall 7 6
c Fix null-pointer problem.
e
s 00014/00010/00621
d D 1.6 87/07/03 16:04:25 minshall 6 5
c Remove getopt(3) (not on PC).
e
s 00003/00003/00628
d D 1.5 87/07/03 15:52:22 minshall 5 4
c Fixes for PC version.
e
s 00002/00001/00629
d D 1.4 87/06/19 12:53:38 minshall 4 3
c Directory changes.
e
s 00119/00032/00511
d D 1.3 87/06/16 17:18:37 minshall 3 2
c This version actually works!
e
s 00507/00042/00036
d D 1.2 87/06/16 12:39:40 minshall 2 1
c This version sends the command over.
e
s 00078/00000/00000
d D 1.1 87/06/09 15:46:49 minshall 1 0
c date and time created 87/06/09 15:46:49 by minshall
e
u
U
t
T
I 10
/*
D 12
 *	Copyright (c) 1984-1987 by the Regents of the
 *	University of California and by Gregory Glenn Minshall.
E 12
I 12
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
E 12
 *
D 12
 *	Permission to use, copy, modify, and distribute these
 *	programs and their documentation for any purpose and
 *	without fee is hereby granted, provided that this
 *	copyright and permission appear on all copies and
 *	supporting documentation, the name of the Regents of
 *	the University of California not be used in advertising
 *	or publicity pertaining to distribution of the programs
 *	without specific prior permission, and notice be given in
 *	supporting documentation that copying and distribution is
 *	by permission of the Regents of the University of California
 *	and by Gregory Glenn Minshall.  Neither the Regents of the
 *	University of California nor Gregory Glenn Minshall make
 *	representations about the suitability of this software
 *	for any purpose.  It is provided "as is" without
 *	express or implied warranty.
E 12
I 12
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 12
 */

#ifndef lint
I 12
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 12
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif	/* not lint */
E 12
I 12
#endif /* not lint */
E 12

E 10
I 1
D 2
/*
 * getmore - get another buffer from the host.
 */
E 2
I 2
#include <stdio.h>
E 2

D 2
void
getmore(buffer)
char	buffer[];
E 2
I 2
D 4
#include "apilib.h"
E 4
I 4
D 8
#include <apilib/apilib.h>
E 8
I 8
#include <api/apilib.h>
E 8

E 4
#include "tncomp.h"


D 8
#include "../api/api.h"

E 8
I 8
#include "../ctlr/api.h"
E 8
#include "../ctlr/function.h"
#include "../ctlr/hostctlr.h"
#include "../ctlr/oia.h"
#include "../ctlr/screen.h"

D 5
#include "../ascii/disp_asc.h"
#include "../ascii/astosc.h"
E 5
I 5
D 8
#include "../apilib/disp_asc.h"
#include "../apilib/astosc.h"
E 8
I 8
#include "../api/disp_asc.h"
#include "../api/astosc.h"
E 8
E 5

#include "../general/general.h"

ScreenImage Host[MAXSCREENSIZE];

static char
D 3
    a_send_sequence[SMALL_LENGTH+1],
    a_ack_sequence[SMALL_LENGTH+1],
    a_checksum[SMALL_LENGTH+1],
    data_array[LARGE_LENGTH+1];
E 3
I 3
    a_send_sequence[SEND_SEQUENCE_LENGTH+1],
    a_ack_sequence[ACK_SEQUENCE_LENGTH+1],
    a_checksum[CHECKSUM_LENGTH+1],
    data_array[DATA_LENGTH+1];
E 3

static int
    verbose,
I 3
    blocks,
E 3
    enter_index,
    clear_index,
    ScreenSize,
    session_id;

static unsigned int
    send_sequence,
D 3
    ack_sequence,
E 3
I 3
    ack_sequence = -1,
E 3
    checksum;

api_perror(string)
char *string;
E 2
{
D 2
    static int next_out = 0, next_in = -1;
E 2
I 2
    fprintf(stderr, "Error: [0x%x/0x%x:0x%x/0x%x] from %s.\n",
	api_sup_fcn_id, api_sup_errno,
	api_fcn_fcn_id, api_fcn_errno, string);
}
E 2

D 2
    while (seq_out != next_out) {
	set_seq(++next_in);
	enter_key();
	wait_for_unlocked();
	seq_out = get_seq_out();
	if (seq_out > next_out) {	/* OOPS */
	    fprintf(stderr, "Sequence number error: expected 0x%d, got 0x%d.\n",
		    next_out, seq_out);
	    pf3_key();
	    exit(3);
E 2
I 2

char *
session_type(type)
int	type;
{
    switch (type) {
    case TYPE_WSCTL:
	return "work station control";
    case TYPE_DFT:
	return "distributed function terminal";
    case TYPE_CUT:
	return "control unit terminal";
    case TYPE_NOTEPAD:
	return "notepad";
    case TYPE_PC:
	return "personal computer";
    default:
	return "(UNKNOWN)";
    }
}

static int
I 3
wait_for_ps_or_oia()
{
#if	defined(unix)
    return api_ps_or_oia_modified();
#endif	/* defined(unix) */
}


static int
E 3
wait_for_unlock()
{
    OIA oia;
    ReadOiaGroupParms re;
I 3
    static char zeroes[sizeof oia.input_inhibited] = { 0 };
E 3

    do {
	re.rc = re.function_id = 0;
	re.session_id = session_id;
	re.oia_buffer = (char far *) &oia;
	re.oia_group_number = API_OIA_ALL_GROUPS;
	if (api_read_oia_group(&re) == -1) {
	    api_perror("api_read_oia_group");
	    return -1;
	} else if (verbose) {
	    if (IsOiaReady3274(&oia)) {
		printf("3274 ready, ");
	    }
	    if (IsOiaMyJob(&oia)) {
		printf("my job, ");
	    }
	    if (IsOiaInsert(&oia)) {
		printf("insert mode, ");
	    }
	    if (IsOiaSystemLocked(&oia)) {
		printf("system locked, ");
	    }
	    if (IsOiaTWait(&oia)) {
		printf("terminal wait, ");
	    }
	    printf("are some bits from the OIA.\n");
E 2
	}
I 2
D 3
    } while (IsOiaSystemLocked(&oia) || IsOiaTWait(&oia));
E 3
I 3
	/* We turned this on, so turn it off now */
	ResetOiaApiInhibit(&oia);
	if (memcmp(zeroes, oia.input_inhibited, sizeof oia.input_inhibited)) {
	    if (wait_for_ps_or_oia() == -1) {
		return -1;
	    }
	}
    } while (memcmp(zeroes, oia.input_inhibited, sizeof oia.input_inhibited));
E 3
    return 0;
}

static int
initialize()
{
    QuerySessionIdParms id;
    QuerySessionParametersParms pa;
    QuerySessionCursorParms cu;
    ConnectToKeyboardParms conn;
    DisableInputParms disable;
    NameArray namearray;

    if (api_init() == 0) {
	fprintf(stderr, "API function not available.\n");
	return -1;
E 2
    }
I 2

    id.rc = 0;
    id.function_id = 0;
    id.option_code = ID_OPTION_BY_NAME;
    id.data_code = 'E';
    id.name_array = &namearray;
    namearray.length = sizeof namearray;
    if (api_query_session_id(&id)) {
	api_perror("api_query_session_id");
    } else if (namearray.number_matching_session == 0) {
	fprintf(stderr, "query_session_id:  No matching sessions!\n");
	return -1;
    } else if (verbose) {
	printf("Session short name 0x%x, type is ",
				namearray.name_array_element.short_name);
	printf("%s", session_type(namearray.name_array_element.type));
	printf(", session ID is: 0x%x\n",
				namearray.name_array_element.session_id);
    }
    session_id = namearray.name_array_element.session_id;

    pa.rc = pa.function_id = 0;
    pa.session_id = session_id;
    if (api_query_session_parameters(&pa) == -1) {
	api_perror("api_query_session_parameters");
	return -1;
    } else if (verbose) {
	printf("Session type %s, ", session_type(pa.session_type));
	if (pa.session_characteristics&CHARACTERISTIC_EAB) {
	    printf(" has EAB, ");
	}
	if (pa.session_characteristics&CHARACTERISTIC_PSS) {
	    printf(" has PSS, ");
	}
	printf("%d rows, %d columns ", pa.rows, pa.columns);
	if (pa.presentation_space) {
	    printf("presentation space at 0x%x:0x%x.\n",
		FP_SEG(pa.presentation_space), FP_OFF(pa.presentation_space));
	} else {
	    printf("(no direct presentation space access).\n");
	}
    }
    ScreenSize = pa.rows*pa.columns;
    if (pa.session_characteristics&CHARACTERISTIC_EAB) {
	fprintf(stderr,
    "tncomp utilities not designed to work with extended attribute buffers.\n");
	return -1;
    }

    if (verbose) {
	cu.rc = cu.function_id = 0;
	cu.session_id = session_id;
	if (api_query_session_cursor(&cu) == -1) {
	    api_perror("api_query_session_cursor");
	} else {
	    printf("cursor");
	    if (cu.cursor_type&CURSOR_INHIBITED_AUTOSCROLL) {
		printf(" inhibited autoscroll");
	    }
	    if (cu.cursor_type&CURSOR_INHIBITED) {
		printf(" inhibited");
	    }
	    if (cu.cursor_type&CURSOR_BLINKING) {
		printf(" blinking");
	    } else {
		printf(" not blinking");
	    }
	    if (cu.cursor_type&CURSOR_BOX) {
		printf(" box ");
	    } else {
		printf(" not box ");
	    }
	    printf("at row %d, column %d.\n",
				cu.row_address, cu.column_address);
	}
    }

    conn.rc = conn.function_id = 0;
    conn.session_id = session_id;
    conn.event_queue_id = conn.input_queue_id = 0;
    conn.intercept_options = 0;
    if (api_connect_to_keyboard(&conn) == -1) {
	api_perror("api_connect_to_keyboard");
    } else if (verbose) {
	if (conn.first_connection_identifier) {
	    printf("First keyboard connection.\n");
	} else {
	    printf("Not first keyboard connection.\n");
	}
    }

    disable.rc = disable.function_id = 0;
    disable.session_id = session_id;
    disable.connectors_task_id = 0;
    if (api_disable_input(&disable) == -1) {
	api_perror("api_disable_input");
	return -1;
    } else if (verbose) {
	printf("Disabled.\n");
    }

    if ((enter_index = ascii_to_index("ENTER")) == -1) {
	return -1;
    }
    if ((clear_index = ascii_to_index("CLEAR")) == -1) {
	return -1;
    }

    return 0;				/* all ok */
E 2
}

I 2
static int
send_key(index)
int	index;
{
    WriteKeystrokeParms wr;
    extern struct astosc astosc[];
E 2

I 2
    wait_for_unlock();

    wr.rc = wr.function_id = 0;
    wr.session_id = session_id;
    wr.connectors_task_id = 0;
    wr.options = OPTION_SINGLE_KEYSTROKE;
    wr.number_of_keys_sent = 0;
    wr.keystroke_specifier.keystroke_entry.scancode = astosc[index].scancode;
    wr.keystroke_specifier.keystroke_entry.shift_state
						= astosc[index].shiftstate;
    if (api_write_keystroke(&wr) == -1) {
	api_perror("api_write_keystroke");
	return -1;
    } else if (wr.number_of_keys_sent != 1) {
	fprintf(stderr, "write_keystroke claims to have sent %d keystrokes.\n",
		    wr.number_of_keys_sent);
	return -1;
    } else if (verbose) {
	printf("Keystroke sent.\n");
    }
I 3
    if (wait_for_ps_or_oia() == -1) {
	return -1;
    }
E 3
    return 0;
}

static int
terminate()
{
    EnableInputParms enable;
    DisconnectFromKeyboardParms disc;

    enable.rc = enable.function_id = 0;
    enable.session_id = session_id;
    enable.connectors_task_id = 0;
    if (api_enable_input(&enable) == -1) {
	api_perror("api_enable");
	return -1;
    } else if (verbose) {
	printf("Enabled.\n");
    }

    disc.rc = disc.function_id = 0;
    disc.session_id = session_id;
    disc.connectors_task_id = 0;
    if (api_disconnect_from_keyboard(&disc) == -1) {
	api_perror("api_disconnect_from_keyboard");
	return -1;
    } else if (verbose) {
	printf("Disconnected from keyboard.\n");
    }

    (void) api_finish();

    return 0;
}


static int
get_screen()
{
    CopyStringParms copy;
    /* Time copy services */

    wait_for_unlock();

    copy.copy_mode = 0;
    copy.rc = copy.function_id = 0;
    copy.source.session_id = session_id;
    copy.source.buffer = 0;
    copy.source.characteristics = 0;
    copy.source.session_type = TYPE_DFT;
    copy.source.begin = 0;

    copy.source_end = ScreenSize;

    copy.target.session_id = 0;
    copy.target.buffer = (char *) &Host[0];
    copy.target.characteristics = 0;
    copy.target.session_type = TYPE_DFT;

    if (api_copy_string(&copy) == -1) {
	api_perror("api_copy_string");
	return -1;
    }
    return 0;
}
D 3
put_at(offset, from, length)
E 3
I 3


put_at(offset, from, length, attribute)
E 3
int	offset;
char	*from;
int	length;
{
    CopyStringParms copy;
D 3
    /* Time copy services */
E 3

    wait_for_unlock();

    copy.copy_mode = 0;
    copy.rc = copy.function_id = 0;
    copy.source.session_id = 0;
    copy.source.buffer = from;
    copy.source.characteristics = 0;
    copy.source.session_type = TYPE_DFT;
    copy.source.begin = 0;

    copy.source_end = length-1;

    copy.target.session_id = session_id;
    copy.target.buffer = 0;
    copy.target.characteristics = 0;
    copy.target.session_type = TYPE_DFT;
    copy.target.begin = offset;

    if (api_copy_string(&copy) == -1) {
	api_perror("api_copy_string");
	return -1;
    }
    return 0;
}

static void
translate(input, output, table, length)
char *input, *output, table[];
int length;
{
    unsigned char *indices = (unsigned char *) input;

    while (length--) {
	*output++ = table[*indices++];
    }
}

static int
D 3
find_input_area()
E 3
I 3
find_input_area(from)
int	from;
E 3
{
D 5
#define	FieldDec()	(0)		/* We don't really use this */
E 5
I 5
#define	FieldDec(p)	(0)		/* We don't really use this */
E 5
    register int i, attr;

D 3
    for (i = 0; i < MAXSCREENSIZE; ) {
E 3
I 3
    for (i = from; i < MAXSCREENSIZE; ) {
E 3
	if (IsStartField(i)) {
	    attr = FieldAttributes(i);
	    i++;
	    if (!IsProtectedAttr(i, attr)) {
		return i;
	    }
	} else {
	    i++;
	}
    }
    return -1;
}


static void
getascii(offset, to, length)
int	offset;				/* Where in screen */
char	*to;				/* Where it goes to */
int	length;				/* Where to put it */
{
    translate(Host+offset, to, disp_asc, length);
}

static int
D 3
putascii(offset, from, length)
E 3
I 3
putascii(offset, from, length, before)
E 3
int	offset;				/* Where in screen */
char	*from;				/* Where it comes from */
int	length;				/* Where to put it */
I 3
int	before;				/* How much else should go */
E 3
{
    translate(from, Host+offset, asc_disp, length);
D 3
    if (put_at(offset, (char *) Host+offset, length) == -1) {
E 3
I 3
    if (put_at(offset-before,
			(char *) Host+offset-before, length+before) == -1) {
E 3
	return -1;
    }
    return 0;
}

static int
ack()
{
I 3
    static char ack_blanks[sizeof a_ack_sequence] = {0};

    if (ack_blanks[0] == 0) {
	int i;

	for (i = 0; i < sizeof ack_blanks; i++) {
	    ack_blanks[i] = ' ';
	}
    }

    memcpy(a_ack_sequence, ack_blanks, sizeof a_ack_sequence);
E 3
    sprintf(a_ack_sequence, "%d", ack_sequence);
    a_ack_sequence[strlen(a_ack_sequence)] = ' ';
D 3
    translate(a_ack_sequence, a_ack_sequence, asc_disp, SMALL_LENGTH);
    if (put_at(ACK_SEQUENCE, a_ack_sequence, SMALL_LENGTH) == -1) {
E 3
I 3
    Host[ACK_SEQUENCE-1] |= ATTR_MDT;
    if (putascii(ACK_SEQUENCE, a_ack_sequence, ACK_SEQUENCE_LENGTH, 1) == -1) {
E 3
	return -1;
    }
    return 0;
}
D 3
	
E 3
I 3

static int
formatted_correct()
{
    if ((find_input_area(SEND_SEQUENCE-1) != SEND_SEQUENCE) ||
	    (find_input_area(SEND_SEQUENCE) != ACK_SEQUENCE) ||
	    (find_input_area(ACK_SEQUENCE) != CHECKSUM) ||
	    (find_input_area(CHECKSUM) != DATA)) {
	return -1;
    } else {
	return 0;
    }
}


E 3
E 2
main(argc, argv)
int	argc;
char	*argv[];
{
I 2
    register int i;
E 2
    int data_length, input_length;
    char ascii[8];			/* Lots of room */
D 2
    char data_array[2000];
E 2
    FILE *outfile;
I 2
    char *data;
I 7
    char *argv0 = argv[0];
E 7
D 6
    extern int optind;
E 6
E 2

I 6
    argc--;
    argv++;
E 6
D 2
    if (argc < 2) {
E 2
I 2
    /* Process any flags */
D 3
    while ((i = getopt(argc, argv, "v")) != EOF) {
E 3
I 3
D 6
    while ((i = getopt(argc, argv, "vb")) != EOF) {
E 3
	switch (i) {
E 6
I 6
D 7
    while (argv[0][0] == '-') {
E 7
I 7
    while (argc && (argv[0][0] == '-')) {
E 7
	switch (argv[0][1]) {
E 6
	case 'v':
	    verbose = 1;
I 3
	    break;
	case 'b':
	    blocks = 1;
	    break;
E 3
	}
I 6
	argc--;
	argv++;
E 6
    }

D 6
    if ((argc-optind) < 2) {
E 6
I 6
    if ((argc) < 2) {
E 6
E 2
D 7
	fprintf(stderr, "usage: %s local.file remote.file [remote.options]\n");
E 7
I 7
	fprintf(stderr,
		"usage: %s [-b] [-v] local.file remote.file [remote.options]\n",
			argv0);
E 7
	exit(1);
    }

    /* Open the local file */
D 2
    if ((outfile = fopen(argv[1], "w") == NULL) {
E 2
I 2
D 6
    if ((outfile = fopen(argv[optind], "w")) == NULL) {
E 6
I 6
    if ((outfile = fopen(argv[0], "w")) == NULL) {
E 6
E 2
	perror("fopen");
	exit(2);
    }
I 6
    argc--;
    argv++;
E 6

I 2
D 6
    optind++;

E 6
    if (initialize() == -1) {
	return -1;
    }

E 2
    /* build the command line */
    data = data_array;
D 2
    strcpy(data, "TNCOMP");
E 2
I 2
    strcpy(data, "TNCOMP SEND");
E 2
    data += strlen(data);
D 2
    while (argc--) {
E 2
I 2
D 6
    for (; optind < argc; optind++) {
E 6
I 6
    while (argc--) {
E 6
E 2
	*data++ = ' ';
D 2
	strcpy(data, *argv);
	data += strlen(*argv);
	argv++;
E 2
I 2
D 6
	strcpy(data, argv[optind]);
	data += strlen(argv[optind]);
E 6
I 6
	strcpy(data, argv[0]);
	data += strlen(argv[0]);
	argv++;
E 6
E 2
    }
I 2
    if (verbose) {
	printf("%s\n", data_array);
    }
    if (get_screen() == -1) {
	return -1;
    }
    data_length = strlen(data_array);
D 9
    if ((i = find_input_area()) == -1) {		/* Get an input area */
E 9
I 9
    if ((i = find_input_area(0)) == -1) {		/* Get an input area */
E 9
	if (send_key(clear_index) == -1) {
	    return -1;
	}
D 3
	if ((i = find_input_area()) == -1) {		/* Try again */
E 3
I 3
	if ((i = find_input_area(0)) == -1) {		/* Try again */
E 3
	    fprintf(stderr, "Unable to enter command line.\n");
	    return -1;
	}
    }
D 3
    if (putascii(i, data_array, data_length) == -1) {
E 3
I 3
    if (i == 0) {
	Host[ScreenSize-1] |= ATTR_MDT;
    } else {
	Host[i-1] |= ATTR_MDT;
    }
    if (putascii(i, data_array, data_length, 1) == -1) {
E 3
	return -1;
    }
    if (send_key(enter_index) == -1) {
	return -1;
    }
    do {
	if (get_screen() == -1) {
	    return -1;
	}
D 3
	i = find_input_area();
    } while (i != SEND_SEQUENCE);
E 3
I 3
    } while (formatted_correct() == -1);
E 3
E 2

D 2
    /* send it across */

    while (!memcmp(data, " EOF", 4)) {
	if (data_length == 0) {
	    data_length = getmore(data_array);
	    data = data_array;
E 2
I 2
    do {
I 3
	if (get_screen() == -1) {
	    return -1;
	}
E 3
	/* For each screen */
D 3
	getascii(SEND_SEQUENCE, a_send_sequence, SMALL_LENGTH);
E 3
I 3
	if (formatted_correct() == -1) {
	    fprintf(stderr, "Bad screen written by host.\n");
	    return -1;
	}
	/* If MDT isn't reset in the sequence number, go around again */
	if (Host[ACK_SEQUENCE-1]&ATTR_MDT) {
	    if (wait_for_ps_or_oia() == -1) {
		return -1;
	    }
	    continue;
	}
	getascii(SEND_SEQUENCE, a_send_sequence, SEND_SEQUENCE_LENGTH);
E 3
	send_sequence = atoi(a_send_sequence);
D 3
	getascii(CHECKSUM, a_checksum, SMALL_LENGTH);
E 3
I 3
	getascii(CHECKSUM, a_checksum, CHECKSUM_LENGTH);
E 3
	checksum = atoi(a_checksum);
D 3
	getascii(DATA, data_array, LARGE_LENGTH);
E 3
I 3
	getascii(DATA, data_array, DATA_LENGTH);
E 3
	data = data_array;
	if (send_sequence != (ack_sequence+1)) {
D 3
	    ack();
E 3
I 3
	    if (ack() == -1) {
		return -1;
	    }
E 3
	    data = "1234";		/* Keep loop from failing */
	    if (send_key(enter_index) == -1) {
		return -1;
	    }
	    if (get_screen() == -1) {
		return -1;
	    }
	    continue;
E 2
	}
D 2
	memcpy(ascii, data, 4);
	data+= 4;
	ascii[4] = 0;
	input_length = atoi(ascii);
	if ((input_length > 1) || (input_length != 1) || (data[0] != ' ')) {
	    if (fwrite(data, sizeof (char), input_length, outfile) == NULL) {
		perror("fwrite");
		exit(9);
E 2
I 2

D 3
	while (data_length && !memcmp(data, " EOF", 4)) {
E 3
I 3
	data_length = DATA_LENGTH;
	while (data_length && memcmp(data, " EOF", 4)
						&& memcmp(data, "    ", 4)) {
E 3
	    memcpy(ascii, data, 4);
D 3
	    data+= 4;
	    data -= 4;
E 3
I 3
	    data += 4;
	    data_length -= 4;
E 3
	    ascii[4] = 0;
	    input_length = atoi(ascii);
D 3
	    if ((input_length > 1) || (input_length != 1) || (data[0] != ' ')) {
E 3
I 3
	    /* CMS can't live with zero length records */
	    if ((input_length > 1) ||
			((input_length == 1) && (data[0] != ' '))) {
E 3
		if (fwrite(data, sizeof (char),
D 3
					input_length, outfile) == NULL) {
E 3
I 3
					input_length, outfile) == 0) {
E 3
		    perror("fwrite");
		    exit(9);
		}
E 2
	    }
I 2
	    fprintf(outfile, "\n");
	    data += input_length;
	    data_length -= input_length;
E 2
	}
D 2
	printf("\n");
	data += input_length;
	data_length -= input_length;
E 2
I 2
D 3
	if (send_key(enter_index) == -1) {
E 3
I 3

	ack_sequence = send_sequence;
	if (blocks) {
	    printf("#");
	    fflush(stdout);
	}
	if (ack() == -1) {
E 3
	    return -1;
	}
D 3
	if (get_screen() == -1) {
E 3
I 3
	if (send_key(enter_index) == -1) {
E 3
	    return -1;
	}
D 3
    } while (!memcmp(data, " EOF", 4));
E 3
I 3
    } while (memcmp(data, " EOF", 4));
E 3

I 3
    if (blocks) {
	printf("\n");
    }
E 3
    if (terminate() == -1) {
	return -1;
E 2
    }
I 2
    return 0;
E 2
}
E 1
