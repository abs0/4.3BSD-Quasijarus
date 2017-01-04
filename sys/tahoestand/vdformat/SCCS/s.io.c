h10323
s 00020/00016/00375
d D 1.7 88/06/07 14:33:05 karels 7 6
c fix relocate (I think) and correct, add command to clear corrections,
c don't preserve user- and verify-detected flaws on reformat; *don't* pass
c structures back and forth incessantly
e
s 00020/00026/00371
d D 1.6 88/05/31 08:44:15 karels 6 5
c clean up error reporting
e
s 00126/00049/00271
d D 1.5 87/11/23 15:28:36 karels 5 4
c working again, I think
e
s 00053/00053/00267
d D 1.4 87/06/01 20:59:18 sam 4 3
c header file changes (guess this works, noone's complained)
e
s 00001/00000/00319
d D 1.3 86/12/19 14:27:01 karels 3 2
c move vdtimeout here
e
s 00013/00004/00306
d D 1.2 86/11/04 21:24:08 karels 2 1
c version working with eagles, many cleanups and fixes
e
s 00310/00000/00000
d D 1.1 86/07/05 17:37:36 sam 1 0
c date and time created 86/07/05 17:37:36 by sam
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


/*
**
*/

static cmd_text_element	nul_table[] = {
	{ 0,	"",	"" }
};

I 2
int wait_for_char;
I 3
int vdtimeout;
E 3
E 2
char	*clean_up = "Cleaning up...  Please wait.\n";


/*
**
*/

poll(wait)
int	wait;
{
I 5
	register struct vddevice *addr = C_INFO->addr;
E 5
	int	tokens[10];
I 2
D 7
	int	didmsg = 0;
E 7
E 2

I 2
D 7
	wait_for_char = 0;
E 7
I 7
	if (kill_processes == false)
		wait_for_char = 0;
E 7
E 2
D 5
	vdtimeout = wait*1000*1000;
	uncache(&(dcb.operrsta));
D 4
	while (!((dcb.operrsta) & (DCBCMP | DCBABT))) {
E 4
I 4
	while (!((dcb.operrsta) & (DCBS_DONE | DCBS_ABORT))) {
E 5
I 5
	vdtimeout = wait*1000;
	for (;;) {
		uncache(&(dcb.operrsta));
		if (dcb.operrsta & (DCBS_DONE | DCBS_ABORT))
			break;
E 5
E 4
D 2
		if(kill_processes == false && input()) {
E 2
I 2
D 7
		if (input()) {
E 7
I 7
		if (kill_processes == false && input()) {
E 7
E 2
			get_text_cmd(nul_table, tokens);
D 2
			if(kill_processes == true) {
E 2
I 2
D 7
			if (didmsg == 0 && kill_processes == true) {
				didmsg = 1;
E 7
I 7
			if (kill_processes == true) {
E 7
E 2
				indent();
				print(clean_up);
				exdent(1);
			}
		}
D 5
		vdtimeout--;
		uncache(&(dcb.operrsta));
		if (vdtimeout <= 0) {
D 4
			if(C_INFO.type == SMDCTLR)
E 4
I 4
			if(C_INFO.type == VDTYPE_VDDC)
E 5
I 5
		if (vdtimeout-- <= 0) {
			if(C_INFO->type == VDTYPE_VDDC)
E 5
E 4
				printf("\nVDDC");
			else
				printf("\nSMD-E");
			printf(": Controller timeout");
D 4
			VDDC_ABORT(C_INFO.addr, C_INFO.type);
E 4
I 4
D 5
			VDABORT(C_INFO.addr, C_INFO.type);
E 5
I 5
abort:
			VDABORT(addr, C_INFO->type);
E 5
E 4
			DELAY(30000);
			break;
		}
I 5
		DELAY(1000);
E 5
	}
D 5
	if((vdtimeout > 0)) {
D 4
		if(C_INFO.type == SMD_ECTLR) {
			uncache(&(C_INFO.addr->cdr_csr));
			while(C_INFO.addr->cdr_csr & CS_GO) {
E 4
I 4
		if(C_INFO.type == VDTYPE_SMDE) {
			uncache(&(C_INFO.addr->vdcsr));
			while(C_INFO.addr->vdcsr & CS_GO) {
E 4
				DELAY(50);
D 4
				uncache(&(C_INFO.addr->cdr_csr));
E 4
I 4
				uncache(&(C_INFO.addr->vdcsr));
E 5
I 5
	if ((vdtimeout > 0)) {
		if (C_INFO->type == VDTYPE_SMDE) {
			for (;;) {
				uncache(&(addr->vdcsr));
				if ((addr->vdcsr & CS_GO) == 0)
					break;
				DELAY(1000);
				if (vdtimeout-- <= 0) {
					printf("\nSMD-E timed out clearing GO");
					goto abort;
				}
E 5
E 4
			}
I 5
			DELAY(300);
E 5
		}
		DELAY(500);
	}
I 5
	DELAY(200);
E 5
D 4
	if((dcb.opcode == RD) || (dcb.opcode == RD_RAW))
E 4
I 4
	if((dcb.opcode == VDOP_RD) || (dcb.opcode == VDOP_RDRAW))
E 4
D 2
		mtpr(0, PADC);
E 2
I 2
		mtpr(PADC, 0);
E 2
	uncache(&(dcb.operrsta));
I 2
	uncache(&(dcb.err_code));
	wait_for_char = 1;
E 2
}


/*
**	Access_with_no_trailer is used to perform controller functions which
** require no data movement.
*/

access_with_no_trailer(function, wait_time)
int	function, wait_time;
{
	dcb.opcode = function;		/* command */
D 4
	dcb.intflg = NOINT;
	dcb.nxtdcb = (fmt_dcb *)0;	/* end of chain */
E 4
I 4
	dcb.intflg = DCBINT_NONE;
	dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
E 4
	dcb.operrsta  = 0;
D 4
	dcb.devselect = (function == VDSTART) ? 0 : (char)cur.drive;
E 4
I 4
D 5
	dcb.devselect = (function == VDOP_START) ? 0 : (char)cur.drive;
E 5
I 5
	dcb.devselect = (function == VDOP_START) ? 0 :
	    ((char)cur.drive | lab->d_devflags);
E 5
E 4
	dcb.trailcnt = (char)0;
D 4
	mdcb.firstdcb = &dcb;
	mdcb.vddcstat = 0;
	VDDC_ATTENTION(C_INFO.addr, &mdcb, C_INFO.type);	
E 4
I 4
	mdcb.mdcb_head = &dcb;
	mdcb.mdcb_status = 0;
D 5
	VDGO(C_INFO.addr, (u_long)&mdcb, C_INFO.type);	
E 5
I 5
	VDGO(C_INFO->addr, (u_long)&mdcb, C_INFO->type);	
E 5
E 4
	poll(wait_time);
	if(vdtimeout <= 0) {
		printf(" during startup operation.\n");
		_longjmp(abort_environ, 1);
	}
	return dcb.operrsta;
}

I 5
vread(sn, buf, seccnt)
int sn, seccnt;
char *buf;
{
D 7
	return (vrdwr(sn, buf, seccnt, VDOP_RD));
E 7
I 7
	int ret;

	ret = vrdwr(sn, buf, seccnt, VDOP_RD);
	if (ret == 0)
		vd_error("read");
	return (ret);
E 7
}
E 5

I 5
vwrite(sn, buf, seccnt)
int sn, seccnt;
char *buf;
{
D 7
	return (vrdwr(sn, buf, seccnt, VDOP_WD));
}
E 7
I 7
	int ret;
E 7

I 7
	ret = vrdwr(sn, buf, seccnt, VDOP_WD);
	if (ret == 0)
		vd_error("write");
	return (ret);
};

E 7
vrdwr(sn, buf, seccnt, op)
int sn, seccnt, op;
char *buf;
{
	dskadr	dskaddr;

	dskaddr.cylinder = sn / lab->d_secpercyl;
	sn %= lab->d_secpercyl;
	dskaddr.track = sn / lab->d_nsectors;
	dskaddr.sector = sn % lab->d_nsectors;
	if (access_dsk(buf, &dskaddr, op, seccnt, 1) & DCBS_HARD)
		return (0);
	return (seccnt);
}

E 5
/*
**	access_dsk is used by other routines to do reads and writes to the disk.
** The status of the read / write is returned to the caller for processing.
*/

access_dsk(buf, dskaddr, func, count, wait)
char	*buf;
dskadr	*dskaddr;
int	func, count, wait;
{
	cur.daddr.cylinder = dskaddr->cylinder;
	cur.daddr.track = dskaddr->track;
I 2
	wait_for_char = 0;
E 2
	dcb.opcode = func;		/* format sector command */
D 4
	dcb.intflg = NOINT;
	dcb.nxtdcb = (fmt_dcb *)0;	/* end of chain */
E 4
I 4
	dcb.intflg = DCBINT_NONE;
	dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
E 4
	dcb.operrsta  = 0;
D 5
	dcb.devselect = (char)cur.drive;
E 5
I 5
	dcb.devselect = (char)cur.drive | lab->d_devflags;
E 5
D 4
	if(func == SEEK) {
		dcb.trailcnt = (char)(sizeof(trseek) / sizeof(long));
E 4
I 4
	if(func == VDOP_SEEK) {
		dcb.trailcnt = (char)(sizeof(struct trseek) / sizeof(long));
E 4
		dcb.trail.sktrail.skaddr.cylinder = dskaddr->cylinder;
		dcb.trail.sktrail.skaddr.track = dskaddr->track;
		dcb.trail.sktrail.skaddr.sector = dskaddr->sector;
D 5
	}
	else {
E 5
I 5
	} else {
E 5
D 4
		dcb.trailcnt = (char)(sizeof(trrw) / sizeof(long));
		dcb.trail.rwtrail.memadr = buf; 
E 4
I 4
		dcb.trailcnt = (char)(sizeof(struct trrw) / sizeof(long));
		dcb.trail.rwtrail.memadr = (u_long)buf; 
E 4
D 5
		dcb.trail.rwtrail.wcount=count*(SECSIZ/sizeof(short));
E 5
I 5
		dcb.trail.rwtrail.wcount=count*(lab->d_secsize/sizeof(short));
E 5
		dcb.trail.rwtrail.disk.cylinder = dskaddr->cylinder;
		dcb.trail.rwtrail.disk.track = dskaddr->track;
		dcb.trail.rwtrail.disk.sector = dskaddr->sector;
	}
D 4
	mdcb.firstdcb = &dcb;
	mdcb.vddcstat = 0;
	VDDC_ATTENTION(C_INFO.addr, &mdcb, C_INFO.type);
E 4
I 4
	mdcb.mdcb_head = &dcb;
	mdcb.mdcb_status = 0;
D 5
	VDGO(C_INFO.addr, (u_long)&mdcb, C_INFO.type);
E 5
I 5
	VDGO(C_INFO->addr, (u_long)&mdcb, C_INFO->type);
E 5
E 4
	if(wait) {
D 5
		poll(2*60);
E 5
I 5
		poll(10);
E 5
		if(vdtimeout <= 0) {
			printf(" in access_dsk.\n");
			_longjmp(abort_environ, 1);
		}
	}
I 2
	wait_for_char = 1;
E 2
	return dcb.operrsta;
}


/*
**	Spin_up_drive starts the drives on a controller and waits around for
** the drive to spin up if it is not already spinning.
*/

spin_up_drive()
{
D 4
	VDDC_RESET(C_INFO.addr, C_INFO.type);
	if(C_INFO.type == SMD_ECTLR) {
		C_INFO.addr->cdr_csr =  0;
		C_INFO.addr->mdcb_tcf =  AM_ENPDA;
		C_INFO.addr->dcb_tcf =  AM_ENPDA;
		C_INFO.addr->trail_tcf =  AM_ENPDA;
		C_INFO.addr->data_tcf =  AM_ENPDA;
		C_INFO.addr->cdr_ccf = CCF_SEN | 0x8 | CCF_STS |
E 4
I 4
D 5
	VDRESET(C_INFO.addr, C_INFO.type);
	if(C_INFO.type == VDTYPE_SMDE) {
		C_INFO.addr->vdcsr =  0;
		C_INFO.addr->vdtcf_mdcb =  AM_ENPDA;
		C_INFO.addr->vdtcf_dcb =  AM_ENPDA;
		C_INFO.addr->vdtcf_trail =  AM_ENPDA;
		C_INFO.addr->vdtcf_data =  AM_ENPDA;
		C_INFO.addr->vdccf = CCF_SEN | 0x8 | CCF_STS |
E 5
I 5
	register struct vddevice *addr = C_INFO->addr;

	VDRESET(addr, C_INFO->type);
	if(C_INFO->type == VDTYPE_SMDE) {
		addr->vdcsr =  0;
		addr->vdtcf_mdcb =  AM_ENPDA;
		addr->vdtcf_dcb =  AM_ENPDA;
		addr->vdtcf_trail =  AM_ENPDA;
		addr->vdtcf_data =  AM_ENPDA;
		addr->vdccf = CCF_SEN | 0x8 | CCF_STS |
E 5
E 4
		    XMD_32BIT | BSZ_16WRD | CCF_ERR |
		    CCF_ENP | CCF_EPE | CCF_EDE | CCF_ECE;
	}
D 4
	access_with_no_trailer(INIT, 10);
	access_with_no_trailer(DIAG, 20);
E 4
I 4
	access_with_no_trailer(VDOP_INIT, 10);
	access_with_no_trailer(VDOP_DIAG, 20);
E 4
	configure_drive(0);
}

/*
**	Configure_drive tells the controller what kind of drive is attached
** on a particular line.
*/

configure_drive(pass)
int	pass;
{
I 5
	register struct vddevice *addr = C_INFO->addr;
	register i;

top:
E 5
D 4
	dcb.opcode = RSTCFG;		/* command */
	dcb.intflg = NOINT;
	dcb.nxtdcb = (fmt_dcb *)0;	/* end of chain */
E 4
I 4
	dcb.opcode = VDOP_CONFIG;		/* command */
	dcb.intflg = DCBINT_NONE;
	dcb.nxtdcb = (struct dcb *)0;	/* end of chain */
E 4
D 5
	dcb.operrsta  = 0;
	dcb.devselect = (char)cur.drive;
	dcb.trail.rstrail.ncyl = CURRENT->vc_ncyl;
	dcb.trail.rstrail.nsurfaces = CURRENT->vc_ntrak;
D 4
	if(C_INFO.type == SMDCTLR)
E 4
I 4
	if(C_INFO.type == VDTYPE_VDDC)
E 5
I 5
	dcb.operrsta = 0;
	dcb.devselect = cur.drive | lab->d_devflags;
	dcb.trail.rstrail.ncyl = lab->d_ncylinders;
	dcb.trail.rstrail.nsurfaces = lab->d_ntracks;
	if(C_INFO->type == VDTYPE_VDDC)
E 5
E 4
		dcb.trailcnt = (char)2;
	else {
D 5
		dcb.trailcnt = (char)4;
		dcb.trail.rstrail.nsectors = CURRENT->vc_nsec;
		dcb.trail.rstrail.slip_sec = CURRENT->vc_nslip;
		dcb.trail.rstrail.recovery = 0x00;
D 4
		C_INFO.addr->cyl_skew = (*C_INFO.cylinder_skew)();
		C_INFO.addr->trk_skew = (*C_INFO.track_skew)();
E 4
I 4
		C_INFO.addr->vdcylskew = (*C_INFO.cylinder_skew)();
		C_INFO.addr->vdtrackskew = (*C_INFO.track_skew)();
E 5
I 5
		dcb.trailcnt = sizeof (struct treset)/sizeof (long);
		dcb.trail.rstrail.nsectors = lab->d_nsectors;
		dcb.trail.rstrail.slip_sec = lab->d_sparespertrack;
		dcb.trail.rstrail.recovery = VDRF_NONE;
		addr->vdcylskew = lab->d_cylskew;
		addr->vdtrackskew = lab->d_trackskew;
D 7
/*
E 7
		addr->vdsecsize = lab->d_secsize/sizeof(short);
D 7
*/
E 7
E 5
E 4
	}
I 6
D 7
/*
E 6
I 5
printf("devsel %x, ncyl %d, ntrk %d, nsec %d, slip %d, cylskew %d, trackskew %d, secsize %d\n", dcb.devselect, dcb.trail.rstrail.ncyl, dcb.trail.rstrail.nsurfaces, dcb.trail.rstrail.nsectors, dcb.trail.rstrail.slip_sec, lab->d_cylskew, lab->d_trackskew, lab->d_secsize);
I 6
*/
E 7
E 6
E 5
D 4
	mdcb.firstdcb = &dcb;
	mdcb.vddcstat = 0;
	VDDC_ATTENTION(C_INFO.addr, &mdcb, C_INFO.type);
E 4
I 4
	mdcb.mdcb_head = &dcb;
	mdcb.mdcb_status = 0;
D 5
	VDGO(C_INFO.addr, (u_long)&mdcb, C_INFO.type);
E 5
I 5
	VDGO(addr, (u_long)&mdcb, C_INFO->type);
E 5
E 4
	poll(5);
	if(vdtimeout <= 0) {
		printf(" during drive configuration.\n");
D 5
		_longjmp(abort_environ, 1);
E 5
I 5
		goto bad;
E 5
	}
D 4
	if(dcb.operrsta & (NOTCYLERR | DRVNRDY)) {
E 4
I 4
D 5
	if(dcb.operrsta & (DCBS_OCYL | DCBS_NRDY)) {
E 5
I 5
	if(dcb.operrsta & VDERR_HARD) {
		if (C_INFO->type == VDTYPE_SMDE) {
			if (lab->d_devflags == 0) {
				lab->d_devflags = VD_ESDI;
				goto top;
			}
#ifdef notdef
printf("vdstatus %x\n", addr->vdstatus[cur.drive]);
			if ((addr->vdstatus[cur.drive] & STA_US) == 0) {
				printf("Drive not present\n\n");
				goto bad;
			}
#endif
		}
		if ((dcb.operrsta & (DCBS_OCYL|DCBS_NRDY)) == 0) {
			printf("drive config error\n");
			goto bad;
		}
E 5
E 4
		if(pass) {
			printf("\nDrive failed to start!\n\n");
D 5
			_longjmp(abort_environ, -1);
E 5
I 5
			goto bad;
E 5
		}
I 2
		printf("\ndrive not ready, attempting to spin up...");
E 2
D 4
		access_with_no_trailer(VDSTART, (cur.drive * 6) + 62);
E 4
I 4
D 5
		access_with_no_trailer(VDOP_START, (cur.drive * 6) + 62);
E 4
		DELAY((cur.drive * 5500000) + 62000000);
E 5
I 5
		access_with_no_trailer(VDOP_START, 62);
		for (i = 0; i < 620; i++) {
			if (C_INFO->type == VDTYPE_SMDE &&
			    addr->vdstatus[cur.drive] & STA_UR)
				break;
			DELAY(100000);
		}
E 5
I 2
		printf(" retrying drive configuration\n");
E 2
D 5
		configure_drive(1);
E 5
I 5
		pass++;
		lab->d_devflags = 0;
		goto top;
E 5
	}
I 5
	D_INFO->alive = u_true;
	return;
bad:
	D_INFO->alive = u_false;
	_longjmp(abort_environ, -1);
E 5
}


/*
** 	data_ok checks an error status word for bit patterns
**  associated with error conditions from the VDDC controller.  If a hardware
D 6
**  error is present then the problem is reported on the console and the program
**  is halted.  If a data error is present the a zero is returned.
E 6
I 6
**  error is present then the problem is reported on the console.
**  If a data error is present the a zero is returned.
E 6
**  If everything is OK then a 1 is returned.
*/

data_ok()
{
	register int	status = dcb.operrsta;

	if(status & HARD_ERROR){
D 4
		if(status & DRVNRDY)
E 4
I 4
D 6
		if(status & DCBS_NRDY)
E 4
			printf("\nDrive is not ready!");
D 4
		else if(status & INVDADR)
E 4
I 4
		else if(status & DCBS_IVA)
E 4
			printf("\nInvalid disk address issued!");
D 4
		else if(status & DNEMEM)
E 4
I 4
		else if(status & DCBS_NEM)
E 4
			printf("\nNon-existent memory error!");
D 4
		else if(status & PARERR)
E 4
I 4
		else if(status & DCBS_DPE)
E 4
			printf("\nMain memory parity error!");
D 4
		else if(status & OPABRT) 
E 4
I 4
		else if(status & DCBS_OAB) 
E 4
			printf("\nCPU aborted operation!");
D 4
		else if(status & WPTERR)
E 4
I 4
		else if(status & DCBS_WPT)
E 4
			printf("\nDrive is write protected!");
D 4
		else if(status & DSEEKERR)
E 4
I 4
		else if(status & DCBS_SKI)
E 4
			printf("\nDisk seek error!");
D 4
		else if(status & CTLRERR)
E 4
I 4
		else if(status & DCBS_CHE)
E 4
			printf("\nController hardware error!");
		else
			printf("\nNot on cylinder error!");
		printf("   Status = 0x%lx", status);
D 4
		if(C_INFO.type == SMD_ECTLR)
E 4
I 4
D 5
		if(C_INFO.type == VDTYPE_SMDE)
E 5
I 5
		if(C_INFO->type == VDTYPE_SMDE)
E 5
E 4
			printf("  Error code =  0x%x", dcb.err_code & 0xff);
		printf("\n");
		printf("cylinder = %d, track = %d,", dcb.err_cyl, dcb.err_trk);
		printf(" sector = %d, op = 0x%x\n", dcb.err_sec, dcb.opcode);
E 6
I 6
		vd_error("data transfer");
		printf("  op = 0x%x\n", dcb.opcode);
E 6
		reset_controller();
		dcb.operrsta &= HEADER_ERROR;
	}
	return (int)(!(status & (DATA_ERROR | HEADER_ERROR)));
I 6
}

vd_error(s)
	char *s;
{
	register int	status = dcb.operrsta;

D 7
	print("error at sector %d (cyl %d trk %d sect %d),\n",
	    to_sector(cur.daddr), dcb.err_cyl & 0xfff, dcb.err_trk,
E 7
I 7
	print("%s error at sector %d (cyl %d trk %d sect %d),\n",
	    s, to_sector(cur.daddr), dcb.err_cyl & 0xfff, dcb.err_trk,
E 7
	    dcb.err_sec);
	print("  status=%b", dcb.operrsta, VDERRBITS);
	if (C_INFO->type == VDTYPE_SMDE)
		printf(", ecode=0x%x", dcb.err_code);
D 7
	printf("\n");
E 7
I 7
	printf(".\n");
E 7
E 6
}


/*
**
*/

reset_controller()
{
	printf("Resetting controller.  Please wait...\n");
	spin_up_drive();
	printf("Controller was reset successfully.\n");
}

/*
**
*/

static	int	indent_count;


/*
**
*/

indent()
{
	indent_count += 2;
}


/*
**
*/

exdent(count)
int	count;
{
	if(count == -1)
		indent_count = 0;
	else
		indent_count -= count * 2;
	if(indent_count < 0)
			indent_count = 0;
}


/*
**
*/
/*VARARGS1*/
print(par0, par1, par2, par3, par4, par5, par6)
char	*par0, *par1, *par2, *par3, *par4, *par5, *par6;
{
	register int	count = indent_count;

	while(count--)
		printf(" ");
	printf(par0, par1, par2, par3, par4, par5, par6);
	DELAY((strlen(par0) + 20) * 9000);
}
D 2

E 2
E 1
