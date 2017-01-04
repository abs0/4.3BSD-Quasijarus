/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * External declarations of global variables
 *
 *	@(#)globals.h	1.34 (IFCTF) 2013/01/13
 */

extern int debug, initdone;
extern char *msdns_directory;
extern char default_msdns_directory[];
extern struct class *class_array[255], *class_list;
extern int classes_needing_fileread, class_fileread_inprogress;
extern int zones_needing_fileread, zone_fileread_inprogress;
extern struct zone *global_zone_list, *zone_fileread_roundrobin;
extern struct ns_anchor *nsanchor_fileread_queue;
extern int nsanchor_fileread_inprogress;

extern fd_set select_for_read, select_for_write, select_for_except;
extern int select_max_fd;
extern struct selectloop_desc *select_desc;
extern time_t current_time;
extern struct timesched *timesched_head;
extern struct query *queryqueue_head, **queryqueue_tail;
extern int zonexfer_children, sigchild_flag;

/* tunable settings */
extern int allow_aa_queries;
extern int askforns_retries_perserver;
extern int askforns_retries_total;
extern int askforns_timeout;
extern int cache_sweep_interval;
extern int child_race_timer;
extern int compress_case_preserve;
extern int compress_new_types;
extern int echo_question;
extern int max_hash_chain;
extern int max_nested_queries;
extern int norec_allow_cached_ans;
extern int norec_allow_cached_ref;
extern int tempfail_cache_dur;
extern int ttl_bump_cname, ttl_bump_ns;
extern int ttl_limit_data;
extern int ttl_limit_ncache;
extern int ttl_limit_ns;
extern int ttl_sensible_min;

extern int num_outbound_udp_sockets;
extern int udpout_debug;
extern struct node *cache_node_list, *cache_sweep_ptr;

/* TCP/AXFR server */
extern int tcpserv_max_conn;
extern int tcpserv_active_conn;
extern int tcpserv_max_idle;
extern int tcpserv_send_timeout;
/* outbound TCP service */
extern struct tcpqueue *tcpqueue_active, *tcpqueue_waitq;
extern int tcpqueue_outstanding, tcpqueue_limit;
extern int outbound_tcp_timeout;

/* truncation stats */
extern int stats_incoming_udp_tc;
extern int stats_tcpretry_success;
extern int stats_tcpretry_fail;
extern int stats_tcpretry_tcagain;
extern int stats_tcpretry_badecho;
extern int stats_outgoing_udp_tc;
extern int stats_outgoing_tcp_tc;
extern int stats_local_ar_tc;
extern int stats_fwd_ar_tc;
