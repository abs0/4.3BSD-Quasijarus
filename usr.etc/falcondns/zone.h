/*
 * MSDNS zone management structures
 *
 *	@(#)zone.h	1.14 (IFCTF) 2011/12/17
 */

#ifndef	__ZONE_H
#define	__ZONE_H

#include <stdio.h>
#include "defs.h"

struct zone {
	int	z_refcount;	/* AXFR-out ops need to hold it from deletion */
	struct	class *z_class;
	/* the following two are appended to the same */
	/* malloced chunk after the struct itself */
	char	*z_ascii_domname;
	struct	dname *z_dname;
	struct	catalog *z_catnode;
	char	z_filename[MAX_FILENAME+1];
	int	z_flags;
	struct	zone *z_next_perclass;
	struct	zone **z_backref_perclass;
	struct	zone *z_next_global;
	struct	zone **z_backref_global;
	struct	node *z_activetree;
	struct	node *z_tree_inprogress;	/* being read from file */
	FILE	*z_fileread;
	int	z_fileread_rrcount;
	struct	node *z_fileread_lastnode;
	time_t	z_file_mtime;
	struct	timesched *z_refresh;
	/* remote/secondary zone support */
	u_long	z_fromaddr_config;
	u_long	z_fromaddr_current;
	struct	query *z_mname_query;
	struct	tcpquery *z_soa_check;
	int	z_puller_pid;
	char	z_temp_filename[16];
};

/* z_flags definitions */
#define	Z_FILEREAD_NEEDED		0x8000
#define	Z_LOAD_FAILED			0x4000
#define	Z_LOST_IN_MALLOC		0x2000
#define	Z_RETRYING			0x0008
#define	Z_DEL_CANDIDATE			0x0004
#define	Z_EXPIRED			0x0002
#define	Z_REMOTE			0x0001

#endif	/* include guard */
