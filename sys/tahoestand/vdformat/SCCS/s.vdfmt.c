h32372
s 00002/00002/00191
d D 1.6 88/06/07 14:33:15 karels 6 5
c fix relocate (I think) and correct, add command to clear corrections,
c don't preserve user- and verify-detected flaws on reformat; *don't* pass
c structures back and forth incessantly
e
s 00024/00032/00169
d D 1.5 87/11/23 15:29:06 karels 5 4
c working again, I think
e
s 00010/00009/00191
d D 1.4 87/06/01 20:59:28 sam 4 3
c header file changes (guess this works, noone's complained)
e
s 00001/00001/00199
d D 1.3 86/12/22 19:24:39 karels 3 2
c vddcaddr now not relative
e
s 00007/00005/00193
d D 1.2 86/11/04 21:24:17 karels 2 1
c version working with eagles, many cleanups and fixes
e
s 00198/00000/00000
d D 1.1 86/07/05 17:37:44 sam 1 0
c date and time created 86/07/05 17:37:44 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley/CCI) %G%";
#endif

/*
**
*/

#include	"vdfmt.h"

main()
{
	exdent(-1);
D 5
	print("VDFORMAT                   Version 3.0 \n\n");
E 5
I 5
	print("VDFORMAT            Berkeley Version %I% \n\n");
E 5
D 2
	print("Type `Help' for help, `Start' to execute operations.\n\n");
E 2

	for(;;) {
		determine_controller_types();
I 2
		print(
		  "\nType `Help' for help, `Start' to execute operations.\n\n");
E 2
		if(!_setjmp(reset_environ)) {
			init_environment();
			for(;;) {
				if(!_setjmp(quit_environ)) {
					reset_operation_tables();
					process_commands();
				}
				else
					report_unexecuted_ops();
			}
		}
	}
}


/*
**
*/

report_unexecuted_ops()
{
	register int	ctlr, drive;
	char *header = "The following operations will not be executed:\n";

	indent();
	for(ctlr=0; ctlr<MAXCTLR; ctlr++)
		for(drive=0; drive<MAXDRIVE; drive++)
			if(ops_to_do[ctlr][drive].op) {
				print(header);
				if(strlen(header)) {
					indent();
					header = "";
					print(header);
				}
				display_operations(ctlr, drive);
				ops_to_do[ctlr][drive].op = 0;
			}
	exdent(-1);
}


/*
**
*/
I 4
#define	VDBASE	0xffff2000	/* address of first controller */
#define	VDOFF	0x100		/* offset between controllers */
E 4

determine_controller_types()
{
D 6
	extern fmt_err	smd_decode_position(), smd_e_decode_position();
	extern bs_entry	smd_code_position(), smd_e_code_position();
E 6
I 6
	extern fmt_err	*smd_decode_position(), *smd_e_decode_position();
	extern bs_entry	*smd_code_position(), *smd_e_code_position();
E 6
D 5
	extern int	smd_cyl_skew(), smd_trk_skew();
	extern int	smd_e_cyl_skew(), smd_e_trk_skew();
E 5
	register int	ctlr, drive;
I 5
	register ctlr_info *ci;
E 5

	/* Identify which controllers are present and what type they are. */
	num_controllers = 0;
	for(ctlr = 0; ctlr < MAXCTLR; ctlr++) {
D 3
		c_info[ctlr].addr = (cdr *)(vddcaddr[ctlr]+VBIOBASE);
E 3
I 3
D 4
		c_info[ctlr].addr = (cdr *)(vddcaddr[ctlr]);
E 4
I 4
D 5
		c_info[ctlr].addr = (struct vddevice *)(VDBASE+(ctlr*VDOFF));
E 4
E 3
		if(!badaddr(c_info[ctlr].addr, 2)) {
E 5
I 5
		ci = &c_info[ctlr];
		ci->addr = (struct vddevice *)(VDBASE+(ctlr*VDOFF));
		if(!badaddr(ci->addr, 2)) {
E 5
I 2
			printf("controller %d: ", ctlr);
E 2
			num_controllers++;
D 4
			c_info[ctlr].addr->cdr_reset = (unsigned)0xffffffff;
E 4
I 4
D 5
			c_info[ctlr].addr->vdreset = (unsigned)0xffffffff;
E 5
I 5
			ci->addr->vdreset = (unsigned)0xffffffff;
E 5
E 4
			DELAY(1000000);
D 4
			if(c_info[ctlr].addr->cdr_reset!=(unsigned)0xffffffff) {
E 4
I 4
D 5
			if(c_info[ctlr].addr->vdreset!=(unsigned)0xffffffff) {
E 4
				c_info[ctlr].alive = u_true;
D 4
				c_info[ctlr].type = SMDCTLR;
E 4
I 4
				c_info[ctlr].type = VDTYPE_VDDC;
E 4
				c_info[ctlr].name = "VDDC";
				c_info[ctlr].decode_pos = smd_decode_position;
				c_info[ctlr].code_pos = smd_code_position;
				c_info[ctlr].cylinder_skew = smd_cyl_skew;
				c_info[ctlr].track_skew = smd_trk_skew;
E 5
I 5
			if(ci->addr->vdreset!=(unsigned)0xffffffff) {
				ci->alive = u_true;
				ci->type = VDTYPE_VDDC;
				ci->name = "VDDC";
				ci->decode_pos = smd_decode_position;
				ci->code_pos = smd_code_position;
E 5
I 2
D 4
				printf("smd\n");
E 4
I 4
				printf("vddc\n");
E 4
E 2
				DELAY(1000000);
D 2
			}
			else {
E 2
I 2
			} else {
E 2
D 5
				c_info[ctlr].alive = u_true;
D 4
				c_info[ctlr].type = SMD_ECTLR;
E 4
I 4
				c_info[ctlr].type = VDTYPE_SMDE;
E 4
				c_info[ctlr].name = "SMD-E";
D 4
				c_info[ctlr].addr->cdr_reserved = 0x0;
E 4
I 4
				c_info[ctlr].addr->vdrstclr = 0;
E 4
				c_info[ctlr].decode_pos = smd_e_decode_position;
				c_info[ctlr].code_pos = smd_e_code_position;
				c_info[ctlr].cylinder_skew = smd_e_cyl_skew;
				c_info[ctlr].track_skew = smd_e_trk_skew;
E 5
I 5
				ci->alive = u_true;
				ci->type = VDTYPE_SMDE;
				ci->name = "SMD-E";
				ci->addr->vdrstclr = 0;
				ci->decode_pos = smd_e_decode_position;
				ci->code_pos = smd_e_code_position;
E 5
I 2
				printf("smd-e\n");
E 2
				DELAY(3000000);
			}
D 2
		}
		else  {
E 2
I 2
		} else  {
E 2
D 5
			c_info[ctlr].alive = u_false;
D 4
			c_info[ctlr].type = UNKNOWN;
E 4
I 4
			c_info[ctlr].type = -1;
E 5
I 5
			ci->alive = u_false;
			ci->type = -1;
E 5
E 4
		}
D 5
		for(drive=0; drive<MAXDRIVE; drive++) {
E 5
I 5
		for(drive=0; drive<MAXDRIVE; drive++)
E 5
			d_info[ctlr][drive].alive = u_unknown;
D 5
			d_info[ctlr][drive].info = (struct vdconfig *)0;
		}
E 5
	}
	if(num_controllers == 0)
		_stop("vdfmt: I can't find any disk controllers.  Giving up!");
}


/*
**	Init_environment is used to reset everything to it's initial state.
** All previously stored drive information is lost when this command
** is executed.
*/

init_environment()
{
	register int	ctlr, drive;

	/* clear list of operations to do */
	for(ctlr=0; ctlr<MAXCTLR; ctlr++) {
D 5
		for(drive=0; drive<MAXCTLR; drive++) {
E 5
I 5
		for(drive=0; drive<MAXDRIVE; drive++) {
			bzero((char *)&d_info[ctlr][drive],
			    sizeof(d_info[ctlr][drive]));
E 5
			d_info[ctlr][drive].alive = u_unknown;
D 5
			d_info[ctlr][drive].info = (struct vdconfig *)0;
E 5
			d_info[ctlr][drive].id = -1;
D 5
			d_info[ctlr][drive].trk_size = 0;
			d_info[ctlr][drive].num_slip = 0;
			d_info[ctlr][drive].track_skew = 0;
E 5
		}
	}
	/* Init pattern table pointers */
	pattern_address[0] = pattern_0;
	pattern_address[1] = pattern_1;
	pattern_address[2] = pattern_2;
	pattern_address[3] = pattern_3;
	pattern_address[4] = pattern_4;
	pattern_address[5] = pattern_5;
	pattern_address[6] = pattern_6;
	pattern_address[7] = pattern_7;
	pattern_address[8] = pattern_8;
	pattern_address[9] = pattern_9;
	pattern_address[10] = pattern_10;
	pattern_address[11] = pattern_11;
	pattern_address[12] = pattern_12;
	pattern_address[13] = pattern_13;
	pattern_address[14] = pattern_14;
	pattern_address[15] = pattern_15;
	/* Init operations command table */
	operations[0].routine = format;
	operations[0].op_name = "Format";
	operations[0].op_action = "Formatting";
	operations[1].routine = verify;
	operations[1].op_name = "Verify";
	operations[1].op_action = "Verification";
	operations[2].routine = relocate;
	operations[2].op_name = "Relocate";
	operations[2].op_action = "Relocation";
	operations[3].routine = info;
	operations[3].op_name = "Info";
	operations[3].op_action = "Information gathering";
	operations[4].routine = correct;
	operations[4].op_name = "Correct";
	operations[4].op_action = "Correction";
	operations[5].routine = profile;
	operations[5].op_name = "Profile";
	operations[5].op_action = "Profiling";
	operations[6].routine = exercise;
	operations[6].op_name = "Exercise";
	operations[6].op_action = "exercising";
	bad_map = (bs_map *)bs_map_space;
}


/*
**	Reset_operation_tables reinitializes all the  tables that
**  control the sequence of formatter operations.
*/

reset_operation_tables()
{
	register int	ctlr, drive;

	/* clear list of operations to do */
	for(ctlr=0; ctlr<MAXCTLR; ctlr++) {
		for(drive=0; drive<MAXDRIVE; drive++) {
			ops_to_do[ctlr][drive].op = 0;
			ops_to_do[ctlr][drive].numpat = 1;
		}
	}
	kill_processes = false;
}
D 4

E 4
E 1
