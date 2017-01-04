/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Global variables are defined here
 */

#ifndef lint
static char sccsid[] = "@(#)globals.c	1.34 (IFCTF) 2013/01/13";
#endif

#include <sys/types.h>

int debug, initdone;
char *msdns_directory;
struct class *class_array[255], *class_list;
int classes_needing_fileread, class_fileread_inprogress;
int zones_needing_fileread, zone_fileread_inprogress;
struct zone *global_zone_list, *zone_fileread_roundrobin;
struct ns_anchor *nsanchor_fileread_queue;
int nsanchor_fileread_inprogress;

fd_set select_for_read, select_for_write, select_for_except;
int select_max_fd;
struct selectloop_desc *select_desc;
time_t current_time;
struct timesched *timesched_head;
struct query *queryqueue_head, **queryqueue_tail = &queryqueue_head;
int zonexfer_children, sigchild_flag;

/* tunable settings */
int allow_aa_queries;
int askforns_retries_perserver = 3;
int askforns_retries_total = 10;
int askforns_timeout = 1;
int cache_sweep_interval = 3600;
int child_race_timer = 30;
int compress_case_preserve;
int compress_new_types;
int echo_question = 1;
int max_hash_chain = 5;
int max_nested_queries = 10;
int norec_allow_cached_ans = 1;
int norec_allow_cached_ref = 1;
int tempfail_cache_dur = 120;
int ttl_bump_cname, ttl_bump_ns;
int ttl_limit_data = 86400 * 7;
int ttl_limit_ncache = 86400 * 2;
int ttl_limit_ns = 86400 * 14;
int ttl_sensible_min = 10;

int num_outbound_udp_sockets;
int udpout_debug;
struct node *cache_node_list, *cache_sweep_ptr;

/* TCP/AXFR server */
int tcpserv_max_conn = 30;
int tcpserv_active_conn;
int tcpserv_max_idle = 60;
int tcpserv_send_timeout = 60;
/* outbound TCP service */
struct tcpqueue *tcpqueue_active, *tcpqueue_waitq;
int tcpqueue_outstanding, tcpqueue_limit = 3;
int outbound_tcp_timeout = 120;

/* truncation stats */
int stats_incoming_udp_tc;
int stats_tcpretry_success;
int stats_tcpretry_fail;
int stats_tcpretry_tcagain;
int stats_tcpretry_badecho;
int stats_outgoing_udp_tc;
int stats_outgoing_tcp_tc;
int stats_local_ar_tc;
int stats_fwd_ar_tc;
