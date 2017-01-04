h43509
s 00001/00000/00127
d D 1.2 2013/01/14 00:40:14 msokolov 2 1
c class ready-to-serve flag implemented
e
s 00127/00000/00000
d D 1.1 2013/01/13 16:42:19 msokolov 1 0
c split from class.c
e
u
U
t
T
I 1
/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Class refresh/reload implementation
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include <ctype.h>
#include <strings.h>
#include <syslog.h>
#include "class.h"
#include "globals.h"
#include "selectloop.h"
#include "zone.h"
#include "tree.h"
#include "nsrec.h"

/*
 * We have two kinds of class reload: soft (normal) and hard.
 * Soft reload means simply re-reading the class definition file,
 * adding any new zones or NS-anchors, detecting changes to zone or
 * NS-anchor arguments, and deleting any zones which no longer appear
 * in the class definition file.  A soft reload is meant to be
 * non-disruptive: if a zone has changed, the old tree won't go away
 * until the new one is ready, no unnecessary discarding of unaffected
 * parts of the active domain data tree, existing zone structures
 * remain intact.
 *
 * Hard reload means first discarding all existing data for the class,
 * i.e., all zones and the entire active domain tree, then reloading
 * the class as if freshly on boot.  A hard reload is service-impacting.
 * To make it a little less inefficient, we do this trick: first make
 * all zones "forget" their active trees, then delete the zones themselves,
 * and finally discard the domain data tree from the root.  We also need
 * to set n_unlinked like the zone tree replacement code does, in order
 * to guard against the corner case of the cache sweeper hitting a NOA
 * held by an outstanding query.
 */

static void
hard_reload_set_unlink(n)
	register struct node *n;
{
	register struct ns_rrset *ns;

	n->n_unlinked = 1;
	if ((ns = n->n_ns) && ns->ns_type == NSTYPE_ANCHOR)
		delete_nsanchor((struct ns_anchor *) ns);
	if (n->n_zonech)
		iterate_node_children(n->n_zonech, hard_reload_set_unlink, 0);
	if (n->n_nzch)
		iterate_node_children(n->n_nzch, hard_reload_set_unlink, 0);
}

class_reload_req(cl, hard)
	register struct class *cl;
{
	register struct zone *z;

	/* abort any previously-started fileread for fresh restart */
	if (cl->c_fileread) {
		FD_CLR(fileno(cl->c_fileread), &select_for_read);
		fclose(cl->c_fileread);
		cl->c_fileread = 0;
		class_fileread_inprogress = 0;
	}
	if (hard) {
I 2
		cl->c_ready_to_serve = 0;
E 2
		for (z = cl->c_zonelist; z; z = z->z_next_perclass)
			z->z_activetree = 0;
		while (z = cl->c_zonelist)
			delete_zone(z);
		if (cl->c_root) {
			hard_reload_set_unlink(cl->c_root);
			free_subtree(cl->c_root);
			cl->c_root = 0;
			syslog(LOG_INFO, "class %d: cleared for hard reload",
				cl->c_class);
		}
	}
	cl->c_fileread_needed = 1;
	classes_needing_fileread++;
	syslog(LOG_INFO, "class %d scheduled for reload", cl->c_class);
}

void
cmd_reload_class(args)
	char *args;
{
	register char *cp, *arg1;
	int classnum, hard;
	register struct class *cl;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isalnum(*cp)) {
badusage:	syslog(LOG_ERR, "usage: reload-class {<num>|all} [hard]");
		return;
	}
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	hard = (*cp == 'h');
	if (!strcmp(arg1, "all")) {
		for (cl = class_list; cl; cl = cl->c_next)
			class_reload_req(cl, hard);
		return;
	}
	if (!isdigit(*arg1))
		goto badusage;
	classnum = atoi(arg1);
	if (classnum >= 255)
		goto badusage;
	cl = class_array[classnum];
	if (!cl) {
		syslog(LOG_ERR, "reload-class: class %d not defined", classnum);
		return;
	}
	class_reload_req(cl, hard);
}
E 1
