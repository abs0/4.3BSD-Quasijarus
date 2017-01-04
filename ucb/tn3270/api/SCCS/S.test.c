h65254
s 00022/00000/00237
d D 1.6 88/03/28 13:47:01 bostic 6 5
c add Berkeley specific header
e
s 00026/00000/00211
d D 1.5 87/06/15 23:26:55 minshall 5 4
c Add a copy loop.
e
s 00002/00000/00209
d D 1.4 87/06/15 14:55:18 minshall 4 3
c Name changes, send/receive sequence numbers, conversation flow, 
c api_exch_flush().
e
s 00190/00014/00019
d D 1.3 87/05/25 16:26:38 minshall 3 2
c This version works better than the last.
e
s 00007/00000/00026
d D 1.2 87/05/25 10:04:26 minshall 2 1
c Yet another cut (this one runs on the PC).
e
s 00026/00000/00000
d D 1.1 87/05/25 08:55:59 minshall 1 0
c date and time created 87/05/25 08:55:59 by minshall
e
u
U
t
T
I 6
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

E 6
I 2
D 3
#include "apilib.h"
E 3
#include <stdio.h>
E 2
I 1

I 3
#include "../api/api.h"
#include "apilib.h"
#include "../ctlr/oia.h"

I 5
static char mybuffer[2000];

E 5
api_perror(string)
char *string;
{
    fprintf(stderr, "Error: [0x%x/0x%x:0x%x/0x%x] from %s.\n",
	api_sup_fcn_id, api_sup_errno,
	api_fcn_fcn_id, api_fcn_errno, string);
}


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


E 3
main()
{
I 5
    register int i;
E 5
D 3
    int gate;
E 3
I 3
    int session_id;
    OIA oia;
    QuerySessionIdParms id;
    QuerySessionParametersParms pa;
    QuerySessionCursorParms cu;
    ConnectToKeyboardParms conn;
    DisconnectFromKeyboardParms disc;
    WriteKeystrokeParms wr;
    DisableInputParms disable;
    EnableInputParms enable;
    CopyStringParms copy;
    ReadOiaGroupParms re;
    NameArray namearray;
E 3
I 2

    if (api_init() == 0) {
	fprintf(stderr, "API function not available.\n");
	return 1;
    }
E 2

D 3
    if ((gate = api_name_resolve("SESSMGR")) == -1) {
	printf("api_sup_errno = 0x%x.\n", api_sup_errno);
E 3
I 3
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
E 3
    } else {
D 3
	printf("SESSMGR is %d.\n", gate);
E 3
I 3
	printf("Session short name 0x%x, type is ",
				namearray.name_array_element.short_name);
	printf("%s", session_type(namearray.name_array_element.type));
	printf(", session ID is: 0x%x\n",
				namearray.name_array_element.session_id);
E 3
    }
D 3
    if ((gate = api_name_resolve("KEYBOARD")) == -1) {
	printf("api_sup_errno = 0x%x.\n", api_sup_errno);
E 3
I 3
    session_id = namearray.name_array_element.session_id;

    pa.rc = pa.function_id = 0;
    pa.session_id = session_id;
    if (api_query_session_parameters(&pa) == -1) {
	api_perror("api_query_session_parameters");
E 3
    } else {
D 3
	printf("KEYBOARD is %d.\n", gate);
E 3
I 3
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
E 3
    }
D 3
    if ((gate = api_name_resolve("COPY")) == -1) {
	printf("api_sup_errno = 0x%x.\n", api_sup_errno);
E 3
I 3

    cu.rc = cu.function_id = 0;
    cu.session_id = session_id;
    if (api_query_session_cursor(&cu) == -1) {
	api_perror("api_query_session_cursor");
E 3
    } else {
D 3
	printf("COPY is %d.\n", gate);
E 3
I 3
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
	printf("at row %d, column %d.\n", cu.row_address, cu.column_address);
E 3
    }
D 3
    if ((gate = api_name_resolve("OIAM")) == -1) {
	printf("api_sup_errno = 0x%x.\n", api_sup_errno);
E 3
I 3

    re.rc = re.function_id = 0;
    re.session_id = session_id;
    re.oia_buffer = (char far *) &oia;
    re.oia_group_number = API_OIA_ALL_GROUPS;
    if (api_read_oia_group(&re) == -1) {
	api_perror("api_read_oia_group");
E 3
    } else {
D 3
	printf("OIAM is %d.\n", gate);
E 3
I 3
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
E 3
    }
I 3

    conn.rc = conn.function_id = 0;
    conn.session_id = session_id;
    conn.event_queue_id = conn.input_queue_id = 0;
    conn.intercept_options = 0;
    if (api_connect_to_keyboard(&conn) == -1) {
	api_perror("api_connect_to_keyboard");
    } else {
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
    } else {
	printf("Disabled.\n");
    }

    wr.rc = wr.function_id = 0;
    wr.session_id = session_id;
    wr.connectors_task_id = 0;
    wr.options = OPTION_SINGLE_KEYSTROKE;
    wr.number_of_keys_sent = 0;
    wr.keystroke_specifier.keystroke_entry.scancode = 0x3a;
    wr.keystroke_specifier.keystroke_entry.shift_state = 0;
    if (api_write_keystroke(&wr) == -1) {
	api_perror("api_write_keystroke");
    } else {
	if (wr.number_of_keys_sent != 1) {
	    fprintf(stderr,
			"write_keystroke claims to have sent %d keystrokes.\n",
			wr.number_of_keys_sent);
	} else {
	    printf("Keystroke sent.\n");
	}
    }

    enable.rc = enable.function_id = 0;
    enable.session_id = session_id;
    enable.connectors_task_id = 0;
    if (api_enable_input(&enable) == -1) {
	api_perror("api_enable");
    } else {
	printf("Enabled.\n");
    }

    disc.rc = disc.function_id = 0;
    disc.session_id = session_id;
    disc.connectors_task_id = 0;
    if (api_disconnect_from_keyboard(&disc) == -1) {
	api_perror("api_disconnect_from_keyboard");
    } else {
	printf("Disconnected from keyboard.\n");
    }
I 5
    /* Time copy services */

    for (i = 0; i < 100; i++) {
	copy.copy_mode = 0;
	copy.rc = copy.function_id = 0;
	copy.source.session_id = session_id;
	copy.source.characteristics = 0;
	copy.source.session_type = TYPE_DFT;
	copy.source.begin = 0;

	copy.source_end = 1920;

	copy.target.session_id = 0;
	copy.target.buffer = mybuffer;
	copy.target.characteristics = 0;
	copy.target.session_type = TYPE_DFT;

	if (api_copy_string(&copy) == -1) {
	    api_perror("api_copy_string");
	    break;
	}
    }
    printf("Copied data out.\n");
E 5

I 4
    (void) api_finish();

E 4
    return 0;
E 3
}
E 1
