h45816
s 00008/00045/00353
d D 1.4 87/11/23 15:28:47 karels 4 3
c working again, I think
e
s 00002/00002/00396
d D 1.3 87/06/01 20:59:23 sam 3 2
c header file changes (guess this works, noone's complained)
e
s 00011/00001/00387
d D 1.2 86/11/04 21:24:13 karels 2 1
c version working with eagles, many cleanups and fixes
e
s 00388/00000/00000
d D 1.1 86/07/05 17:37:38 sam 1 0
c date and time created 86/07/05 17:37:38 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley/CCI) %G%";
#endif

#include	"vdfmt.h"
#include	"cmd.h"

#define	RESET		1
#define	LIST		2
#define	DELETE		3
#define	FORMAT		4
#define	VERIFY		5
#define	RELOCATE	6
#define	CORRECT		7
#define	INFO		8
#define	PROFILE		9
#define	EXERCISE	10
#define	START		11
I 2
#define	EXIT		12
E 2

static cmd_text_element	commands[] = {
	{ RESET,     "RESET",	  "Reinitialize VDFORMAT, and start over" },
I 2
	{ EXIT,      "EXIT",	  "Terminate program" },
E 2
	{ LIST,	     "List",	  "List operations specified so far" },
	{ DELETE,    "Delete",	  "Delete specific operations" },
	{ FORMAT,    "Format",	  "Format and verify disk surface" },
	{ VERIFY,    "Verify",	  "Destructively verify disk surface" },
	{ RELOCATE,  "Relocate",  "Add known flaws to bad sector map" },
	{ CORRECT,   "Correct",	  "Correct erroneous relocations or drive ID" },
	{ INFO,	     "Info",	  "Display known disk information" },
	{ PROFILE,   "Profile",   "Display seek profile graph of disk" },
	{ EXERCISE,  "Exercise",  "Perform seek exercises on disk" },
	{ START,     "STARt",	  "Start operations" },
	{ 0,	     "",	  "" }
};

D 4
static cmd_text_element	drive_types[20];
E 4

D 4

E 4
/*
**
*/

process_commands()
{
D 4
	int	type, tokens[20];
E 4
I 4
	int	tokens[20];
E 4
	int	*tok_ptr, count;
	int	op_mask = 0;
	char	*cptr;
	boolean	should_start = false;

D 4
	for(type=0; type<ndrives; type++) {
		drive_types[type].cmd_token = (int)&vdconfig[type];
		drive_types[type].cmd_text = vdconfig[type].vc_name;
		drive_types[type].cmd_help = vdconfig[type].vc_type;
I 2
		cptr = drive_types[type].cmd_text;
		while(*cptr) {
			*cptr = toupper(*cptr);
			cptr++;
		}
E 2
	}
	drive_types[type].cmd_token = 0;
E 4
	for(;;) {
I 4
		(void)_setjmp(abort_environ);
E 4
		cur.state = cmd;
		kill_processes = false;
		exdent(-1);
		op_mask = 0;
		printf("vdformat> ");
		count = get_text_cmd(commands, tokens);
		if(kill_processes == true)
			_longjmp(quit_environ, 1);
		tok_ptr = tokens;
		if((*tok_ptr == 0) || !count)
			continue;
		while(*tok_ptr) {
			switch (*tok_ptr) {
			case RESET :
				reset();
				break;
			case LIST :
				list();
				break;
			case DELETE :
				delete();
				break;
			case FORMAT :
				op_mask |= FORMAT_OP;
				break;
			case VERIFY :
				op_mask |= VERIFY_OP;
				break;
			case RELOCATE :
				op_mask |= RELOCATE_OP;
				break;
			case CORRECT :
				op_mask |= CORRECT_OP;
				break;
			case INFO :
				op_mask |= INFO_OP;
				break;
			case PROFILE :
				op_mask |= PROFILE_OP;
				break;
			case EXERCISE :
				op_mask |= EXERCISE_OP;
				break;
			case START :
				should_start = true;
				break;
I 2
			case EXIT:
				exit(0);
				/*NOTREACHED*/
E 2
			default:		/* ignore */
				break;
			}
		tok_ptr++;
		}
		if(op_mask) {
			get_drive_parameters(op_mask);
		}
		if(should_start) {
			start_commands();
			should_start = false;
		}
	}
}


/*
**
*/

static boolean	header_printed = false;

get_drive_parameters(op_mask)
int	op_mask;
{
	int	c_list[20], i, num_pat;

	indent();
	header_printed = false;
	get_ctlr_list(c_list, op_mask);
	if(kill_processes == true) {
		kill_processes = false;
		c_list[0]= -1;
	}
	for(i=0; c_list[i] != -1; i++) {
		int	d_list[40], j;

		indent();
		get_drive_list(c_list[i], d_list, op_mask);
		if(kill_processes == true) {
			kill_processes = false;
			break;
		}
		indent();
		if(op_mask & (FORMAT_OP | VERIFY_OP)) {
			num_pat = get_num_pat();
			if(kill_processes == true) {
				kill_processes = false;
				break;
			}
		}
		for(j=0; d_list[j] != -1; j++) {
D 4
			get_drive_type(c_list[i], d_list[j]);
E 4
I 4
			cur.controller = c_list[i];
			cur.drive = d_list[j];
			C_INFO = &c_info[cur.controller];
			D_INFO = &d_info[cur.controller][cur.drive];
			lab = &D_INFO->label;
			get_drive_type(cur.controller, cur.drive, op_mask);
E 4
			if(kill_processes == true) {
				kill_processes = false;
				break;
			}
			if(op_mask & ~INFO_OP) {
				indent();
				get_drive_id(c_list[i], d_list[j]);
				if(kill_processes == true) {
					kill_processes = false;
					break;
				}
				exdent(1);
			}
			ops_to_do[c_list[i]][d_list[j]].op |= op_mask;
			if(op_mask & (FORMAT_OP | VERIFY_OP))
				ops_to_do[c_list[i]][d_list[j]].numpat=num_pat;
		}
		exdent(1);
	}
	exdent(2);
}

/*
**
*/

get_ctlr_list(c_list, op_mask)
int	*c_list, op_mask;
{
	extern int	ctlr_help();
	register int	i, ctlr;
	int		table[MAXCTLR+10];

	i = 0;
	for(ctlr=0; ctlr<MAXCTLR; ctlr++)
		if(c_info[ctlr].alive == u_true)
			table[i++] = ctlr;
	table[i] = -1;
	/* If only one controller is possible don't ask */
	if(table[1] == -1) {
		*c_list++ = table[0];
		*c_list = -1;
		return;
	}
	for(;;) {
		header_printed = true;
		print("");  /* Force indent */
		print_op_list(op_mask);
		printf(" on which controllers? ");
		get_digit_list(c_list, table, ctlr_help);
		if(kill_processes == true)
			return;
		if(*c_list != -1)
			break;
	}
}


/*
**
*/

ctlr_help()
{
	register int	ctlr;

	indent();
	print("The following controllers are attached to the system:\n");
	indent();
	for(ctlr=0; ctlr<MAXCTLR; ctlr++)
		if(c_info[ctlr].alive == u_true) {
			print("Controller %d, which is a%s %s controller.\n",
			    ctlr, (c_info[ctlr].name[0] == 'S') ? "n" : "",
			    c_info[ctlr].name);
		}
	print("\n");
	exdent(2);
}

static int	max_drive = 0;

/*
**
*/

get_drive_list(ctlr, d_list, op_mask)
int	ctlr, *d_list, op_mask;
{
	extern int	drive_help();
	int		table[MAXDRIVE+10];
	int		i;

D 3
	max_drive = (c_info[ctlr].type == SMDCTLR) ? 4 : 16;
E 3
I 3
	max_drive = (c_info[ctlr].type == VDTYPE_VDDC) ? 4 : 16;
E 3
	for(i=0; i<max_drive; i++)
		table[i] = i;
	table[i] = -1;
	for(;;) {
		if(header_printed == true)
			print("Drives on controller %d? ", ctlr);
		else {
			header_printed = true;
			print("");  /* Force indent */
			print_op_list(op_mask);
			printf(" on which drives? ");
		}
		get_digit_list(d_list, table, drive_help);
		if(kill_processes == true)
			return;
		if(*d_list != -1)
			break;
	}
}
D 4


/*
**
*/

get_drive_type(ctlr, drive)
int	ctlr, drive;
{
	int	tokens[20];
	int	count;

	for(;;) {
		print("Drive type for controller %d, drive %d? ", ctlr, drive);
		if(d_info[ctlr][drive].info != 0)
			printf("(%s) ", d_info[ctlr][drive].info->vc_name);
D 3
		if(c_info[ctlr].type == SMDCTLR)
E 3
I 3
		if(c_info[ctlr].type == VDTYPE_VDDC)
E 3
D 2
			count = get_text_cmd(drive_types+2, tokens);
E 2
I 2
			count = get_text_cmd(drive_types+smddrives, tokens);
E 2
		else
			count = get_text_cmd(drive_types, tokens);
		if(kill_processes == true)
			return;
		if(!*tokens && (d_info[ctlr][drive].info != 0) && !count)
			break;
		if(d_info[ctlr][drive].info = (struct vdconfig *)*tokens)
			break;
	}
}


E 4

/*
**
*/

id_help()
{
	indent();
	print("The following commands are available:\n");
	indent();
	print("STATus - Display formatter state.\n");
	print("QUIT   - Terminate current operation.\n");
	print("");
	print("A module serial can be any number greater than zero.\n");
	exdent(2);
}


/*
**
*/

get_drive_id(ctlr, drive)
int	ctlr, drive;
{
	int	new_id;

	for(;;) {
		print("Module serial number for controller %d, drive %d? ",
		    ctlr, drive);
		if(d_info[ctlr][drive].id != -1)
			printf("(%d) ", d_info[ctlr][drive].id);
		new_id = get_digit_cmd(id_help);
		if(new_id > 0) {
			d_info[ctlr][drive].id = new_id;
			break;
		}
		else if(d_info[ctlr][drive].id != -1) 
			break;
	}
}


/*
**
*/

drive_help()
{
	indent();
	print("Drive numbers 0 through %d may be entered.\n", max_drive-1);
	exdent(1);
}


/*
**
*/

pat_help()
{
	indent();
	print("Between 0 and 16 patterns may be used while verifying.\n");
	exdent(1);
}


/*
**
*/

get_num_pat()
{
	int	table[17+10];
	int	results[17+10];
	int	i;

	for(i=0; i<=16; i++)
		table[i] = i;
	table[i] = -1;
	for(;;) {
		print("Number of patterns to use while verifying? ");
		get_digit_list(results, table, pat_help);
		if(kill_processes == true)
			return 0;
		if(results[0] != -1)
			break;
	}
	return results[0];
}

E 1
