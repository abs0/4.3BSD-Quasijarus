h55691
s 00039/00000/01903
d D 7.23 04/03/22 17:47:51 msokolov 173 172
c add ssdma a la dzdma
e
s 00011/00005/01892
d D 7.22 04/03/19 22:51:11 msokolov 172 171
c kludge: KA42 uses KA650 maps for L2 cache
e
s 00039/00014/01858
d D 7.21 04/03/18 19:19:16 msokolov 171 170
c add BabyVAX support (beginnings thereof)
c a few other todo closures and fixes along the way
e
s 00006/00000/01866
d D 7.20 04/02/03 18:39:03 msokolov 170 169
c hook in floating point instruction emulator
e
s 00000/00085/01866
d D 7.19 04/01/11 11:33:31 msokolov 169 168
c same mode emulation vectors moved to emul/emul_samemode.s
e
s 00005/00003/01946
d D 7.18 04/01/03 18:07:36 msokolov 168 167
c new CPU ID logic
e
s 00004/00000/01945
d D 7.17 02/07/11 10:58:15 msokolov 167 166
c add PPPCTL software interrupt
e
s 00006/00000/01939
d D 7.16 99/01/10 00:13:08 msokolov 166 165
c added cvec and br stuff
e
s 00013/00003/01926
d D 7.15 88/09/22 06:36:37 tef 165 164
c must protect qbus map regs on ka650
e
s 00009/00001/01920
d D 7.14 88/08/27 15:50:23 karels 164 163
c allow qbus address space to be enlarged
e
s 00024/00009/01897
d D 7.13 88/08/27 07:01:01 tef 163 162
c Add support for microvax 3000.
e
s 00004/00002/01902
d D 7.12 88/05/27 16:08:52 karels 162 161
c lint
e
s 00002/00000/01902
d D 7.11 88/05/14 11:11:59 karels 161 160
c clear msgbufmapped when mapping turned off
e
s 00181/00041/01721
d D 7.10 88/05/07 14:19:32 karels 160 159
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00001/00001/01761
d D 7.9 88/04/23 12:59:29 karels 159 158
c enlarge kmem map for hungry net if's (should maybe try to compute)
e
s 00008/00008/01754
d D 7.8 88/01/27 23:31:43 mckusick 158 157
c fix broken resume code
e
s 00009/00004/01753
d D 7.7 87/08/07 15:56:15 marc 157 156
c changes for qdss support
e
s 00002/00002/01755
d D 7.6 87/06/20 12:06:01 mckusick 156 155
c camap is replaced by kmempt
e
s 00003/00001/01754
d D 7.5 87/06/15 10:28:42 karels 155 154
c minor performance hack
e
s 00001/00000/01754
d D 7.4 87/04/02 16:33:56 karels 154 153
c print errno if init exec fails
e
s 00068/00014/01686
d D 7.3 87/02/21 11:18:57 karels 153 152
c kdb (for sam; untested); misc.
e
s 00009/00003/01691
d D 7.2 86/08/09 15:09:29 karels 152 151
c generalize uba code to handle Q bus more gracefully
e
s 00001/00001/01693
d D 7.1 86/06/05 17:06:47 mckusick 151 150
c 4.3BSD release version
e
s 00007/00000/01687
d D 6.38 86/06/05 14:30:43 karels 150 147
c uVAX II bug fix
e
s 00001/00001/01690
d R 7.1 86/06/05 00:57:01 mckusick 149 148
c 4.3BSD release version
e
s 00004/00000/01687
d R 6.38 86/06/04 09:13:27 karels 148 147
c bug fix for uVAX II
e
s 00138/00001/01549
d D 6.37 86/04/22 10:48:36 kridle 147 146
c Added MicroVAX II Support (KA630)
e
s 00003/00000/01547
d D 6.36 86/03/12 11:12:59 karels 146 145
c save r10 (boot device); use it to set rootdev and maybe swap, arg and dump devs
e
s 00002/00002/01545
d D 6.35 86/02/23 23:06:14 karels 145 144
c lint
e
s 00002/00000/01545
d D 6.34 86/02/19 00:31:14 karels 144 143
c config doesn't define I_UBA base
e
s 00001/00001/01544
d D 6.33 86/01/08 14:25:34 karels 143 142
c rm bbnnet
e
s 00002/00004/01543
d D 6.32 85/09/16 20:58:45 karels 142 141
c rearrange tocons bits for 8600 support; let's get the useracc
c RW flag right (maybe use symbolic defn's?)
e
s 00003/00001/01544
d D 6.31 85/09/06 17:59:02 karels 141 140
c defines; save regs in panic too
e
s 00016/00011/01529
d D 6.30 85/09/04 08:15:37 karels 140 139
c 8600 defs; expand usrpt and mbmaps for origin 1 maps; use parens
c around args in SYSMAP macro!!!
e
s 00050/00007/01490
d D 6.29 85/08/05 18:20:53 bloom 139 138
c add support for 8600
e
s 00005/00001/01492
d D 6.28 85/08/02 18:10:46 karels 138 137
c add IMP internal software interrupt, move RAW to be checked last
e
s 00001/00001/01492
d D 6.27 85/07/29 10:56:10 bloom 137 136
c TBIA is docummented as "must be zero"
e
s 00007/00001/01486
d D 6.26 85/06/08 13:53:24 mckusick 136 135
c Add copyright
e
s 00027/00000/01460
d D 6.25 85/04/28 17:54:20 karels 135 134
c move icode to locore, as asm instead of hex; exit if can't exec init
e
s 00009/00008/01451
d D 6.24 85/03/11 16:11:57 mckusick 134 133
c new signal code to push all context onto the signal stack
e
s 00031/00028/01428
d D 6.23 85/01/18 11:43:04 karels 133 132
c change badaddr so it can work after autoconfig; use ipl HIGH consistenly,
c use HIGH ipl in resume to avoid rei problems if ipl 31 is used elsewhere
e
s 00002/00002/01454
d D 6.22 84/12/20 15:32:26 karels 132 131
c invalidate after making rpb writable; resume needs ipl 31 if anyone
c ever switches at ipl > 18.
e
s 00002/00002/01454
d D 6.21 84/10/26 08:55:51 karels 131 130
c always count interrupts in per-device code (not twice on 780's
c with VAX750 defined)
e
s 00001/00001/01455
d D 6.20 84/09/08 21:55:01 karels 130 129
c oops, want ubanum, not ubahd
e
s 00034/00003/01422
d D 6.19 84/09/04 20:10:01 mckusick 129 128
c may not sleep before the u. area is dma'ed to disk, so must save
c all registers as the old setjmp/longjmp did.
e
s 00010/00010/01415
d D 6.18 84/08/28 17:51:03 bloom 128 127
c no more ../h
e
s 00058/00044/01367
d D 6.17 84/08/23 16:49:33 mckusick 127 126
c copyin and copyout now take their arguments in registers; 
c cleanup JSBENTRY to only save necessary registers when profiling
e
s 00002/00002/01409
d D 6.16 84/08/22 19:28:58 sam 126 125
c having hardclock call softclock (when possible) leaves priority 
c at splsoft and screwes up picture system; sloppy solution is to make call 
c to picture system external sync routine before hardclock call (may lost ticks?)
e
s 00022/00008/01389
d D 6.15 84/08/21 11:11:12 karels 125 124
c add interrupt counts per device, also software interrupts
e
s 00008/00006/01389
d D 6.14 84/08/12 01:06:05 mckusick 124 122
c Setjmp is now expanded completely inline to save call overhead;
c cleanup copyinstr and copyoutstr to go NBPG*CLSIZE bytes at a time
e
s 00008/00006/01389
d R 6.14 84/08/12 00:26:43 mckusick 123 122
c Setjmp is now completely expanded inline;
c cleanup copyinstr and copyoutstr to go NBPG*CLSIZE bytes at a time
e
s 00090/00065/01305
d D 6.13 84/08/12 00:06:06 mckusick 122 121
c cleanup of Copyin, Copyout, and Fastreclaim;
c add `.align 1' to differentiate rsb'ed routines when profiling;
c reimplement setjmp/longjmp to improve semantics and speed up common case
e
s 00033/00018/01337
d D 6.12 84/07/31 17:13:58 karels 121 120
c ast's set only temporarily, cancelled by swtch;
c clear runrun in swtch after idle; break idle loop out of swtch
c and straighten out the path through swtch
e
s 00056/00043/01299
d D 6.11 84/07/28 14:56:37 mckusick 120 119
c make provision for gathering profile statistics
e
s 00033/00000/01309
d D 6.10 84/07/27 17:21:22 mckusick 119 118
c add copyoutstr to speed up exec
e
s 00025/00019/01284
d D 6.9 84/07/08 21:42:52 mckusick 118 117
c optionally return length of string copied by `copyinstr' and `copystr'
e
s 00078/00000/01225
d D 6.8 84/07/08 16:25:13 mckusick 117 116
c add `copyinstr' and `copystr' to replace `uchar' and `schar'
e
s 00000/00007/01225
d D 6.7 84/03/22 15:20:01 karels 116 115
c dztimer, dhtimer not called from Xsoftclock now
e
s 00002/00001/01230
d D 6.6 84/02/15 11:51:33 karels 115 114
c consistency checks and data structures based on NUBA, not half MAXNUBA
e
s 00007/00007/01224
d D 6.5 84/02/07 17:41:14 karels 114 113
c use cmap.h for bit offsets in Fastreclaim, physical memory limit
e
s 00002/00002/01229
d D 6.4 83/11/07 15:25:38 mckusick 113 111
c fix to Fastreclaim to properly calculated top of user stack based on UPAGES
e
s 00006/00006/01225
d R 6.4 83/09/29 11:05:30 sam 112 111
c move silo sampling to hardclock since softclock is only 
c called "when needed"; this may be too expensive, may need to lower period 
c with a counter
e
s 00001/00000/01230
d D 6.3 83/08/12 18:25:23 sam 111 110
c need ps.h for picture system 2 driver
e
s 00005/00004/01225
d D 6.2 83/08/12 17:14:30 mckusick 110 109
c shave those cycles; save those bits!
e
s 00000/00000/01229
d D 6.1 83/08/01 12:08:01 sam 109 107
c 4.2 distribution
e
s 00000/00000/01229
d R 4.86 83/08/01 12:04:51 sam 108 107
c 4.2 distribution
e
s 00001/00013/01228
d D 4.85 83/08/01 12:02:59 sam 107 105
c add support for second uba on 750; move rpb in front of 
c scb, otherwise it would be at variable location; add nexi numbers 
c for 64K chip controllers and ci
e
s 00000/00000/01241
d R 6.1 83/07/29 07:20:00 sam 106 105
c 4.2 distribution
e
s 00003/00008/01238
d D 4.84 83/07/09 01:20:50 sam 105 103
c don't configure tudma on a 730; don't lower ipl in tudma 
c never know what pl was at the time of interrupt
e
s 00000/00005/01241
d R 4.84 83/07/07 15:47:41 sam 104 103
c don't lower ipl, dangerous
e
s 00012/00005/01234
d D 4.83 83/06/19 18:45:26 mckusick 103 102
c inline expand distpte() in Fastreclaim
e
s 00006/00002/01233
d D 4.82 83/06/17 21:53:01 helge 102 101
c more fixes to tudma (minor)
e
s 00180/00003/01055
d D 4.81 83/06/16 14:40:34 sam 101 100
c merge from monet
e
s 00006/00005/01052
d D 4.80 83/06/02 15:59:18 sam 100 99
c new signals
e
s 00089/00000/00968
d D 4.79 83/05/30 18:38:37 sam 99 98
c Fastreclaim (zoom zoom....)
e
s 00000/00001/00968
d D 4.78 83/04/20 15:12:37 mckusick 98 97
c round-down in profiling instead of incorrect round-up
e
s 00001/00000/00968
d D 4.77 82/12/30 14:26:04 sam 97 96
c need dh.h to test NDH > 0
e
s 00003/00001/00965
d D 4.76 82/12/29 09:57:15 sam 96 94
c copyin & copyout now return EFAULT on failure
e
s 00003/00001/00965
d R 4.76 82/12/28 23:51:36 sam 95 94
c copyin & copyout return EFAULT on failure
e
s 00004/00003/00962
d D 4.75 82/12/17 11:55:51 sam 94 93
c sun merge
e
s 00025/00000/00940
d D 4.74 82/12/09 23:45:12 sam 93 92
c profil returns
e
s 00001/00001/00939
d D 4.73 82/11/03 01:22:40 root 92 91
c add physstrat; typo in locore.s
e
s 00001/00001/00939
d D 4.72 82/10/31 15:24:32 root 91 90
c change trap names to T_&
e
s 00006/00006/00934
d D 4.71 82/10/13 22:13:58 root 90 89
c rearrange header files
e
s 00002/00001/00938
d D 4.70 82/10/09 16:28:17 root 89 88
c fix includes
e
s 00012/00002/00927
d D 4.69 82/09/18 15:11:33 root 88 87
c move dhtimer, dztimer, psextsync calls here to clean clock code
e
s 00002/00025/00927
d D 4.68 82/09/04 09:30:47 root 87 86
c no profiling done here; clock reloaded here
e
s 00024/00004/00928
d D 4.67 82/08/04 23:10:23 mckusick 86 85
c make Copyin and Copyout work for sizes greater than 65535 bytes
e
s 00002/00002/00930
d D 4.66 82/07/15 20:34:56 root 85 84
c silly
e
s 00003/00003/00929
d D 4.65 82/05/26 15:38:44 sam 84 83
c 7ZZ -> 730
e
s 00001/00001/00931
d D 4.64 82/04/11 01:03:04 feldman 83 82
c support for ec driver
e
s 00010/00009/00922
d D 4.63 82/03/19 01:49:53 wnj 82 81
c use only one software interrupt for network
e
s 00001/00000/00930
d D 4.62 82/02/18 08:58:39 root 81 80
c missing flush of translation buffer during Resume's
e
s 00001/00001/00929
d D 4.61 82/01/30 19:53:36 wnj 80 79
c bitl $2, per ross harvey
e
s 00005/00000/00925
d D 4.60 82/01/16 20:58:55 wnj 79 78
c clean crashes! 
e
s 00001/00001/00924
d D 4.59 82/01/12 23:10:21 wnj 78 77
c fix per ark
e
s 00006/00001/00919
d D 4.58 81/11/29 22:21:07 wnj 77 76
c weekend editing
e
s 00002/00002/00918
d D 4.57 81/11/26 11:57:37 wnj 76 75
c before carry to arpavax
e
s 00002/00004/00918
d D 4.56 81/11/08 16:50:52 wnj 75 74
c BBNNET->INET and Netmap->Mbmap
e
s 00008/00001/00914
d D 4.55 81/11/07 11:09:08 wnj 74 73
c fixes per shannon
e
s 00007/00000/00908
d D 4.54 81/10/16 16:45:34 wnj 73 72
c vector for software interrupt
e
s 00000/00000/00908
d D 4.53 81/10/10 10:32:28 wnj 72 70
c 
e
s 00001/00001/00907
d R 4.53 81/08/31 00:34:22 root 71 70
c variable size msgbufmap
e
s 00002/00001/00906
d D 4.52 81/06/15 18:05:59 root 70 69
c fix tableflt botch
e
s 00001/00001/00906
d D 4.51 81/05/26 20:23:13 wnj 69 68
c blbs -> bbs fix per kre
e
s 00005/00004/00902
d D 4.50 81/05/18 01:59:01 wnj 68 67
c s/masterpcbb/masterpaddr/
e
s 00015/00002/00891
d D 4.49 81/05/15 10:32:39 root 67 66
c masterpaddr added
e
s 00003/00000/00890
d D 4.48 81/05/13 16:15:54 wnj 66 65
c dump only once
e
s 00003/00000/00887
d D 4.47 81/05/12 17:18:19 root 65 64
c add tcp/ip
e
s 00002/00000/00885
d D 4.46 81/05/05 21:50:24 wnj 64 63
c save reboot flags in global boothowto
e
s 00001/00000/00884
d D 4.45 81/04/18 11:56:21 wnj 63 62
c set warm start flag in locore.s
e
s 00000/00006/00884
d D 4.44 81/04/17 17:54:04 wnj 62 61
c remove spurious high ipl's
e
s 00001/00000/00889
d D 4.43 81/04/15 02:19:53 wnj 61 60
c fix bug in kernacc() with -2/X
e
s 00002/00002/00887
d D 4.42 81/04/03 00:06:26 root 60 59
c s/730/7ZZ/
e
s 00003/00000/00886
d D 4.41 81/04/02 15:17:14 root 59 58
c nexus zero vector; count uba interrupts
e
s 00004/00003/00882
d D 4.40 81/03/21 15:30:45 wnj 58 57
c add 730 stuff
e
s 00000/00002/00885
d D 4.39 81/03/16 00:53:25 wnj 57 56
c dont conditionally have 4th mba (comet needs it)
e
s 00001/00001/00886
d D 4.38 81/03/13 21:52:06 wnj 56 55
c NNEXUS --> MAXNNEXUS
e
s 00002/00002/00885
d D 4.37 81/03/09 02:40:13 wnj 55 54
c fixes per shannon + s/2/1 in vtrace
e
s 00000/00000/00887
d D 4.36 81/03/09 01:47:15 wnj 54 53
c lint and a few minor fixed
e
s 00004/00000/00883
d D 4.35 81/03/09 00:32:08 wnj 53 52
c lint
e
s 00001/00001/00882
d D 4.34 81/03/08 16:17:44 wnj 52 51
c uba.h --> ubareg.h
e
s 00001/00001/00882
d D 4.33 81/03/06 11:37:25 wnj 51 50
c new format for stray unibus intr printf
e
s 00018/00015/00865
d D 4.32 81/03/02 22:50:02 wnj 50 49
c cmrd
e
s 00013/00024/00867
d D 4.31 81/02/27 02:39:36 wnj 49 48
c before compiling dynamic version
e
s 00007/00002/00884
d D 4.30 81/02/26 12:49:08 wnj 48 47
c fix cpu to be in data space, not bss
e
s 00022/00005/00864
d D 4.29 81/02/26 04:23:41 wnj 47 46
c 750 mchk code; handle no mbas
e
s 00001/00001/00868
d D 4.28 81/02/26 00:00:27 toy 46 45
c s/VAX==780/VAX780
e
s 00002/00001/00867
d D 4.27 81/02/25 14:48:55 wnj 45 44
c new machinecheck call
e
s 00012/00006/00856
d D 4.26 81/02/23 20:32:18 wnj 44 43
c cleanout funny constants and remove alot of .m files
e
s 00004/00004/00858
d D 4.25 81/02/21 21:26:35 wnj 43 42
c Scbbase->scb
e
s 00011/00007/00851
d D 4.24 81/02/19 21:29:07 wnj 42 41
c unify 750/780 startup stuff via ``cold''
e
s 00015/00011/00843
d D 4.23 81/02/18 16:15:51 wnj 41 40
c fixup trap handling and stray interrupt stuff
e
s 00009/00007/00845
d D 4.22 81/02/17 17:26:46 wnj 40 39
c change to 3 isp pages; proc 0 upages in order
e
s 00001/00000/00851
d D 4.21 81/02/16 20:52:23 wnj 39 38
c call fixctlrmask
e
s 00021/00033/00830
d D 4.20 81/02/15 20:30:09 wnj 38 37
c ast and hard/soft clock stuff
e
s 00265/00681/00598
d D 4.19 81/02/15 12:18:59 wnj 37 36
c autoconf macroized version
e
s 00124/00159/01155
d D 4.18 81/02/08 18:34:09 wnj 36 35
c first working autoconf version
e
s 00002/00002/01312
d D 4.17 81/02/08 01:11:48 wnj 35 34
c misc pre-mba changes (non-recursive printf, futz, resuba, %uXX...)
e
s 00090/00106/01224
d D 4.16 81/02/07 15:41:07 wnj 34 33
c rpb, badaddr, other dump stuff
e
s 00078/00014/01252
d D 4.15 81/02/04 02:19:31 kre 33 32
c chkadr (first draft)
e
s 00001/00001/01265
d D 4.14 81/01/29 09:15:03 kre 32 31
c restored UPAGES to 6, that wasn't the problem
e
s 00001/00001/01265
d D 4.13 81/01/28 11:59:59 wnj 31 30
c UPAGES 8; dumpstack 96; msgbufmap; kernacc rounding bug fixed
e
s 00001/00001/01265
d D 4.12 81/01/26 20:30:55 root 30 29
c increased size of dumpstack
e
s 00008/00003/01258
d D 4.11 81/01/15 19:35:46 wnj 29 28
c fixes for saved msgbuf through crashes
e
s 00002/00004/01259
d D 4.10 80/12/30 15:30:29 wnj 28 27
c 
e
s 00025/00002/01238
d D 4.9 80/12/26 12:24:55 wnj 27 26
c fix (sort of) mba stuff
e
s 00000/00001/01240
d D 4.8 80/12/20 01:43:53 wnj 26 25
c dont globl Xwtime
e
s 00003/00587/01238
d D 4.7 80/12/20 01:02:01 wnj 25 24
c split off scb.s ubivec.s
e
s 00001/00001/01824
d D 4.6 80/12/18 02:21:50 wnj 24 23
c should go to INTSTK on machine check, not halt
e
s 00035/00006/01790
d D 4.5 80/12/17 10:15:25 wnj 23 22
c write timout for 750 and added emulex for gregs comet
e
s 00753/00335/01043
d D 4.4 80/12/16 15:59:08 wnj 22 21
c comet changes
e
s 00009/00007/01369
d D 4.3 80/11/24 12:40:45 bill 21 20
c reset uba on uba fault
e
s 00002/00028/01374
d D 4.2 80/11/09 23:39:12 bill 20 19
c get rid of udiv/urem
e
s 00000/00000/01402
d D 4.1 80/11/09 17:33:36 bill 19 18
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00009/00002/01393
d D 3.18 80/11/09 13:10:15 bill 18 17
c change UBA SBI Fault message and UBA error message
e
s 00005/00002/01390
d D 3.17 80/10/19 22:14:14 bill 17 16
c MAXNBUF 128
e
s 00022/00007/01370
d D 3.16 80/10/02 23:02:15 bill 16 15
c MACHK, KSPNOTVAL, CHM? panics, not halts
e
s 00004/00010/01373
d D 3.15 80/10/02 10:41:30 bill 15 14
c first attempt at reboot stuff
e
s 00002/00002/01381
d D 3.14 80/09/09 19:05:47 bill 14 13
c .align 3->2
e
s 00007/00007/01376
d D 3.13 80/08/27 08:36:27 bill 13 12
c buffers allocated in sysmap
e
s 00004/00021/01379
d D 3.12 80/07/29 09:13:35 bill 12 11
c 
e
s 00041/00047/01359
d D 3.11 80/07/26 15:52:16 bill 11 10
c get rid of pushab $ZERmsg once and for all
e
s 00003/00001/01403
d D 3.10 80/07/23 08:58:48 bill 10 9
c clear core correctly
e
s 00001/00001/01403
d D 3.9 80/07/19 20:16:06 bill 9 8
c NBUF->62
e
s 00000/00001/01404
d D 3.8 80/07/19 19:52:27 bill 8 7
c remove halt on SBI fault
e
s 00009/00000/01396
d D 3.7 80/06/22 12:27:44 bill 7 6
c call ubarese
e
s 00001/00001/01395
d D 3.6 80/06/07 02:43:54 bill 6 5
c %H%->%G%
e
s 00003/00000/01393
d D 3.5 80/06/02 12:38:45 bill 5 4
c counter in dz code
e
s 00028/00031/01365
d D 3.4 80/05/18 12:56:45 bill 4 3
c stray interrupts and setjmp/longjmp
e
s 00104/00104/01292
d D 3.3 80/05/18 11:46:00 bill 3 2
c vector stray interrupts to print STRAY and continue
e
s 00001/00001/01395
d D 3.2 80/04/11 10:14:26 bill 2 1
c Sysmap now 6 pages
e
s 01396/00000/00000
d D 3.1 80/04/09 16:08:09 bill 1 0
c date and time created 80/04/09 16:08:09 by bill
e
u
U
f b 
t
T
I 1
D 22
#
# Machine Language Assist for UC Berkeley Virtual Vax/Unix
#
D 4
#	%M%	%I%	%H%
E 4
I 4
D 6
#	%M%		%I%	%H%
E 6
I 6
#	%M%		%I%	%G%
E 6
E 4
#
E 22
I 22
D 37
/*
 * Machine Language Assist for UC Berkeley Virtual Vax/Unix
 *
D 23
 *	%M%	%I%	%G%
E 23
I 23
 *	%M%		%I%	%G%
E 23
 */
E 37
I 37
D 136
/*	%M%	%I%	%E%	*/
E 136
I 136
/*
D 151
 * Copyright (c) 1980 Regents of the University of California.
E 151
I 151
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 151
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 136
E 37
E 22

I 94
D 128
#include "../machine/psl.h"
#include "../machine/pte.h"
E 128
I 128
#include "psl.h"
#include "pte.h"
E 128

I 96
D 128
#include "../h/errno.h"
I 114
#include "../h/cmap.h"
E 128
I 128
#include "errno.h"
#include "cmap.h"
E 128
E 114

E 96
E 94
I 44
D 90
#include "../h/mtpr.h"
#include "../h/trap.h"
E 90
I 90
D 128
#include "../vax/mtpr.h"
#include "../vax/trap.h"
E 90
D 94
#include "../h/psl.h"
#include "../h/pte.h"
E 94
I 47
D 90
#include "../h/cpu.h"
I 49
#include "../h/nexus.h"
D 52
#include "../h/uba.h"
E 52
I 52
#include "../h/ubareg.h"
I 79
#include "../h/cons.h"
E 90
I 90
#include "../vax/cpu.h"
#include "../vax/nexus.h"
D 94
#include "../vaxuba/ubareg.h"
E 94
#include "../vax/cons.h"
E 90
I 87
#include "../vax/clock.h"
E 128
I 128
#include "mtpr.h"
#include "trap.h"
#include "cpu.h"
I 170
#include "cpucond.h"
E 170
#include "nexus.h"
#include "cons.h"
#include "clock.h"
I 139
#include "ioa.h"
I 147
#include "ka630.h"
I 163
#include "ka650.h"
E 163
I 160
#include "ka820.h"
E 160
E 147
E 139
E 128
I 94
#include "../vaxuba/ubareg.h"
I 171
#include "../mdec/vmb.h"
E 171
E 94
E 87
I 82
D 89
#include "../net/in_systm.h"
E 89
E 82
E 79
I 53

I 97
D 116
#include "dh.h"
E 116
E 97
#include "dz.h"
I 173
#include "ss.h"
E 173
I 101
#include "uu.h"
I 111
#include "ps.h"
E 111
E 101
E 53
E 52
E 49
#include "mba.h"
I 115
#include "uba.h"
E 115
E 47

E 44
D 37
	.set	HIGH,31		# mask for total disable
E 37
I 37
	.set	HIGH,0x1f	# mask for total disable
E 37
D 43
	.set	MCKVEC,4	# offset into Scbbase of machine check vector
E 43
I 43
	.set	MCKVEC,4	# offset into scb of machine check vector
E 43
	.set	NBPG,512
	.set	PGSHIFT,9
I 153
	.set	SYSTEM,0x80000000	# virtual address of system start
E 153

D 44
	.set	CLSIZE,2
E 44
D 49
	.set	BSIZE,NBPG*CLSIZE
E 49
D 9
	.set	NBUF,48
E 9
I 9
D 17
	.set	NBUF,62
E 17
I 17
D 44
	.set	MAXNBUF,128
E 17
E 9
D 31
	.set	UPAGES,6	# size of user area, in pages
E 31
I 31
D 32
	.set	UPAGES,8	# size of user area, in pages
E 32
I 32
	.set	UPAGES,6	# size of user area, in pages
E 44
I 40
	.set	NISP,3		# number of interrupt stack pages
E 40
E 32
E 31

D 22
# ====================================
# Trap vectors and C interface for Vax
# ====================================
E 22
I 22
/*
I 37
 * User structure is UPAGES at top of user space.
 */
	.globl	_u
	.set	_u,0x80000000 - UPAGES*NBPG

D 107
/*
E 37
D 25
 * Trap vectors and C interface for Vax
 */ 
E 22

D 22
#
# System control block
#
E 22
I 22
/*
 * System control block
 */
E 22

	.set	INTSTK,1	# handle this interrupt on the interrupt stack
	.set	HALT,3		# halt if this interrupt occurs
D 14
	.align	PGSHIFT
E 14
I 14
D 22
#	.align	PGSHIFT
E 22
I 22
/*	.align	PGSHIFT	*/
E 22
E 14
	.globl	Scbbase
Scbbase:
D 3
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
E 3
D 16
	.long	Xmachcheck + HALT	# machine check interrupt
	.long	Xkspnotval + HALT	# kernel stack not valid
E 16
I 16
D 22
	.long	Xmachcheck + INTSTK	# machine check interrupt
E 22
I 22
D 24
	.long	Xmachcheck + HALT	# machine check interrupt
E 24
I 24
	.long	Xmachcheck + INTSTK	# machine check interrupt
E 24
E 22
	.long	Xkspnotval + INTSTK	# kernel stack not valid
E 16
	.long	Xpowfail + HALT		# power fail
	.long	Xprivinflt		# privileged instruction 
	.long	Xxfcflt			# xfc instruction 
	.long	Xresopflt		# reserved operand 
	.long	Xresadflt		# reserved addressing 
	.long	Xprotflt		# protection and pt length violation
	.long	Xtransflt		# address translation not valid fault 
	.long	Xtracep			# trace pending
	.long	Xbptflt			# bpt instruction
	.long	Xcompatflt		# compatibility mode fault
	.long	Xarithtrap		# arithmetic trap
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
E 3
	.long	Xsyscall		# chmk
D 16
	.long	Xchme+HALT		# chme
	.long	Xchms+HALT		# chms
	.long	Xchmu+HALT		# chmu
E 16
I 16
	.long	Xchme+INTSTK		# chme
	.long	Xchms+INTSTK		# chms
	.long	Xchmu+INTSTK		# chmu
E 16
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# software level 1
	.long	Xrandom + HALT		# software level 2 (asts)
E 3
I 3
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 23
#if VAX==750
	.long	Xwtime + INTSTK		# write timeout
#else
E 23
	.long	Xstray + INTSTK		# unused
I 23
#endif
E 23
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# software level 1
	.long	Xstray + INTSTK		# software level 2 (asts)
E 3
	.long	Xresched		# reschedule nudge
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
E 3
ubabase:
	.long	Xclockint		# clock
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 22
#if VAX==750
	.long	Xconsdin + INTSTK	# tu58 receiver
	.long	Xconsdout + INTSTK	# tu58 transmitter
#else
E 22
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 22
#endif
E 22
E 3
	.long	Xcnrint + INTSTK	# console receiver 
	.long	Xcnxint + INTSTK	# console transmitter

D 22
#
# I/O vectors
#
E 22
I 22
/*
 * I/O vectors
 */
E 22

D 22
# IPL 14
E 22
I 22
/* IPL 14 */
E 22
D 3
	.long	X14stray + INTSTK	# stray!
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 22
#if VAX==780
E 22
E 3
	.long	Xua0int + INTSTK	# UBA 0 br4
I 22
#else
E 22
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
I 22
#endif
E 22
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 22
	.long	Xstray + INTSTK		# unused
E 22
E 3

D 22
# IPL 15
E 22
I 22
/* IPL 15 */
E 22
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 22
#if VAX==780
E 22
E 3
	.long	Xua0int + INTSTK	# UBA 0 br5
I 22
#else
E 22
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
I 22
#endif
E 22
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 22
	.long	Xstray + INTSTK		# unused
#if VAX==780
E 22
E 3
	.long	Xmba0int + INTSTK	# mass bus adapter 0
	.long	Xmba1int + INTSTK	# mass bus adapter 1
I 22
#else
E 22
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 22
#endif
E 22
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 22
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
E 22
E 3

D 22
# IPL 16
E 22
I 22
/* IPL 16 */
E 22
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 22
#if VAX==780
E 22
E 3
	.long	Xua0int + INTSTK	# UBA 0 br6
I 22
#else
E 22
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
I 22
#endif
E 22
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
I 22
	.long	Xstray + INTSTK		# unused
E 22
E 3

D 22
# IPL 17
E 22
I 22
/* IPL 17 */
E 22
D 3
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
	.long	Xrandom + HALT		# unused
E 3
I 3
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
	.long	Xstray + INTSTK		# unused
E 3

D 22
# 0x200
E 22
I 22
/* 0x200 */
#if VAX==750
	.globl	UBVEC
UBVEC:
/* 0x0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x10 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x20 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x30 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x40 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x50 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x60 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x70 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x80 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xrkintr + INTSTK
	.long	Xubastray + INTSTK		# unused
/* 0x90 */
	.long	Xubastray + INTSTK		# unused
	.long	Xtsintr + INTSTK
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0xa0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
D 23
#ifdef notdef
	.long	Xemintr + INTSTK
#else
	.long	Xubastray + INTSTK		# unused
#endif
E 23
I 23
	.long	Xupintr + INTSTK		# Emulex SC-11/21
E 23
/* 0xb0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0xc0 */
	.long	Xdzrint + INTSTK
	.long	Xdzxint + INTSTK
#ifdef notdef
	.long	Xobiint + INTSTK
	.long	Xoboint + INTSTK
#else
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
#endif
/* 0xd0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0xe0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0xf0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x100 */
#if VAX==750
	.long	Xdkxint + INTSTK
	.long	Xdkrint + INTSTK
#else
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
#endif
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x110 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x120 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x130 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x140 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x150 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x160 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x170 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x180 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x190 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x1a0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x1b0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x1c0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x1d0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x1e0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x1f0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x200 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x210 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x220 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x230 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x240 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x250 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x260 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x270 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x280 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x290 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x2a0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x2b0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x2c0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x2d0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x2e0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x2f0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x300 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x310 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x320 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x330 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x340 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x350 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x360 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x370 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x380 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x390 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x3a0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x3b0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x3c0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x3d0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x3e0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
/* 0x3f0 */
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
	.long	Xubastray + INTSTK		# unused
#endif
E 22

D 22
# =====================================
# Produce a core image dump on mag tape
# =====================================
E 22
I 22
/*
E 25
D 34
 * Produce a core image dump on mag tape
E 34
I 34
 * Restart parameter block
 * This is filled in in machdep.c in startup().
 * It MUST be page aligned.
 * When auto-restart occurs, we run restart() in machdep.c, which
 * takes a core-dump and then cold-starts.
E 34
 */ 
E 22
D 34
	.globl	doadump
doadump:
	movl	sp,dumpstack		# save stack pointer
	movab	dumpstack,sp		# reinit stack
	mfpr	$PCBB,-(sp)		# save u-area pointer
	mfpr	$MAPEN,-(sp)		# save value
	mfpr	$IPL,-(sp)		# ...
	mtpr	$0,$MAPEN		# turn off memory mapping
	mtpr	$HIGH,$IPL		# disable interrupts
	pushr	$0x3fff			# save regs 0 - 13
I 7
	calls	$0,_dumptrc		# print out trace information, if any
E 7
	calls	$0,_dump		# produce dump
D 15
	halt
E 15

	.data
	.align	2
	.globl	dumpstack
D 30
	.space	58*4			# separate stack for tape dumps
E 30
I 30
	.space	96*4			# separate stack for tape dumps
E 30
dumpstack: 
E 34
I 34
	.globl	_rpb
_rpb:
	.space	508
erpb:
E 34
	.space	4
E 107
D 34
	.text
E 34
D 36

E 36
I 36
	.globl	_intstack
_intstack:
D 40
	.space	2048
E 40
I 40
	.space	NISP*NBPG
E 40
eintstack:
I 37

E 37
E 36
D 22
#
# Debugging print switches given here so they won't move around
#
E 22
I 22
/*
D 34
 * Debugging print switches given here so they won't move around
E 34
I 34
 * Do a dump.
 * Called by auto-restart.
 * May be called manually.
E 34
 */
E 22
D 34
	.data
E 34
	.align	2
D 34
	.globl	_printsw
_printsw:
	.space	4
	.globl	_coresw
_coresw:
	.space	4
	.text
E 34
I 34
	.globl	_doadump
I 161
	.globl	_msgbufmapped
E 161
_doadump:
	nop; nop				# .word 0x0101
D 37
/* ignore cpu for the time being ... */
#define	_rpbmap	_Sysmap+4
E 37
I 37
D 107
#define	_rpbmap	_Sysmap+8			# scb, UNIvec, rpb, istack*4
E 107
I 107
D 160
#define	_rpbmap	_Sysmap				# rpb, scb, UNI*vec, istack*4
E 160
I 160
#define	_rpbmap	_Sysmap				# rpb, scb, UNIvec[], istack*4
E 160
E 107
E 37
	bicl2	$PG_PROT,_rpbmap
	bisl2	$PG_KW,_rpbmap
I 132
D 133
	mtpr	$_rpb,$TBIS
E 133
I 133
	mtpr	$0,$TBIA
E 133
E 132
I 66
D 67
	tstl	_rpb_RP_FLAG			# dump only once!
	bne	1f
E 67
I 67
	tstl	_rpb+RP_FLAG			# dump only once!
	bneq	1f
E 67
E 66
I 63
	incl	_rpb+RP_FLAG
E 63
D 133
	mtpr	$0,$TBIA
E 133
	movl	sp,erpb
	movab	erpb,sp
	mfpr	$PCBB,-(sp)
	mfpr	$MAPEN,-(sp)
	mfpr	$IPL,-(sp)
I 161
	clrl	_msgbufmapped
E 161
	mtpr	$0,$MAPEN
	mtpr	$HIGH,$IPL
	pushr	$0x3fff
	calls	$0,_dumpsys
I 66
1:
I 79
D 142
	mfpr	$TXCS,r0
	bitl	$TXCS_RDY,r0
	beql	1b
	mtpr	$TXDB_BOOT,$TXDB
E 142
I 142
D 160
	pushl	$TXDB_BOOT
	calls	$1,_tocons
E 160
I 160
	clrl	r11				# boot flags
	calls	$0,_vaxboot
E 160
E 142
E 79
E 66
	halt
E 34

D 22
# =============================
# I/O interrupt vector routines
# =============================
E 22
I 22
/*
D 37
 * I/O interrupt vector routines
E 37
I 37
 * Interrupt vector routines
E 37
 */ 
E 22
D 37

D 22
#
# Physical i/o addresses
#
E 22
I 22
/*
 * Physical i/o addresses
 */
#if VAX==780
E 22
	.set	PHYSMCR,0x20002000	# memory controller register
	.set	PHYSUBA,0x20006000	# uba 0
D 12
	.set	PHYSMBA0,0x20010000	# mba 0
	.set	PHYSMBA1,0x20012000	# mba 1
E 12
	.set	PHYSUMEM,0x2013e000	# unibus memory
I 22
#else
	.set	PHYSMCR,0xf20000
	.set	PHYSUBA,0xf30000
	.set	PHYSUMEM,0xfc0000+0760000
#endif
E 22

D 22
#
# Catch random or unexpected interrupts
#
E 22
I 22
/*
 * Catch random or unexpected interrupts
 */
E 37
E 22
I 17
	.globl	_waittime
E 17
D 37
	.align	2
I 4
D 16
Xrandom:
E 16
E 4
D 3
Xrandom:
E 3
Xmachcheck:
I 17
	clrl	_waittime
E 17
I 16
	pushab	Emachk
	calls	$1,_panic
E 37

D 37
	.align	2
E 16
Xkspnotval:
I 17
	clrl	_waittime
E 17
I 16
	pushab	Eksp
	calls	$1,_panic
E 37
I 37
#define	SCBVEC(name)	.align 2; .globl _X/**/name; _X/**/name
#define	PANIC(msg)	clrl _waittime; pushab 1f; \
			calls $1,_panic; 1: .asciz msg
#define	PRINTF(n,msg)	pushab 1f; calls $n+1,_printf; MSG(msg)
#define	MSG(msg)	.data; 1: .asciz msg; .text
#define	PUSHR		pushr $0x3f
#define	POPR		popr $0x3f
D 38
#define	REI		brw int_ret		/* will be rei when ast's... */
E 38
E 37

I 133
	.data
nofault: .long	0	# where to go on predicted machcheck
	.text
E 133
D 37
	.align	2
E 16
Xpowfail:
E 37
I 37
SCBVEC(machcheck):
I 133
	tstl	nofault
	bneq	1f
E 133
D 41
	PANIC("Machine check");
E 41
I 41
D 45
	PUSHR; PANIC("Machine check");
E 45
I 45
	PUSHR; pushab 6*4(sp); calls $1,_machinecheck; POPR;
	addl2 (sp)+,sp; rei
I 133
	.align	2
1:
	casel	_cpu,$1,$VAX_MAX
0:
	.word	8f-0b		# 1 is 780
	.word	5f-0b		# 2 is 750
	.word	5f-0b		# 3 is 730
I 139
	.word	7f-0b		# 4 is 8600
I 147
D 160
	.word	1f-0b		# ???
	.word	1f-0b		# ???
	.word	1f-0b		# ???
E 160
I 160
	.word	5f-0b		# 5 is 8200
	.word	1f-0b		# 6 is 8800 (unsupported)
	.word	1f-0b		# 7 is 610  (unsupported)
E 160
	.word	1f-0b		# 8 is 630
I 163
D 171
	.word	1f-0b		# 9 is ???
D 165
	.word	1f-0b		# 10 is 650
E 165
I 165
	.word	9f-0b		# 10 is 650
E 171
I 171
	.word	1f-0b		# 9 is 410
	.word	9f-0b		# 0A is 650
	.word	1f-0b		# 0B is 3100
E 171
E 165
E 163
E 147
E 139
5:
D 160
#if defined(VAX750) || defined(VAX730)
E 160
I 160
#if defined(VAX8200) || defined(VAX750) || defined(VAX730)
E 160
	mtpr	$0xf,$MCESR
#endif
	brb	1f
I 139
7:
#if VAX8600
	mtpr	$0,$EHSR
#endif
	brb	1f
E 139
8:
#if VAX780
	mtpr	$0,$SBIFS
#endif
I 165
	brb	1f
9:
#if VAX650
	bitl	$PG_V,_KA650MERRmap
	beql	1f	# don't bother clearing err reg if not mapped in
	movl	$DSER_CLEAR,_ka650merr+4
#endif
E 165
1:
	addl2	(sp)+,sp		# discard mchchk trash
	movl	nofault,(sp)
	rei
I 165

E 165
E 133
E 45
E 41
SCBVEC(kspnotval):
D 41
	PANIC("KSP not valid");
E 41
I 41
D 160
	PUSHR; PANIC("KSP not valid");
E 160
I 160
	PANIC("KSP not valid");
E 160
E 41
SCBVEC(powfail):
E 37
I 16
	halt
D 37

	.align	2
E 16
Xchme:
Xchms:
Xchmu:
D 16
	halt
E 16
I 16
	pushab	Echm
	calls	$1,_panic

Emachk:	.asciz	"Machine check"
Eksp:	.asciz	"KSP not valid"
Echm:	.asciz	"CHM? in kernel"
E 16

D 3
X14stray:
E 3
I 3
	.align	2
Xstray:
E 3
	pushr	$0x3f
	pushab	straym
	calls	$1,_printf
	popr	$0x3f
E 37
I 37
SCBVEC(chme): SCBVEC(chms): SCBVEC(chmu):
D 41
	PANIC("CHM? in kernel");
E 41
I 41
D 160
	PUSHR; PANIC("CHM? in kernel");
E 41
SCBVEC(stray):
D 50
	PUSHR; PRINTF(0,"Stray interrupt\n"); POPR;
E 50
I 50
	PUSHR; PRINTF(0, "stray scb interrupt\n"); POPR;
E 160
I 160
	PANIC("CHM? in kernel");

SCBVEC(nex0zvec):
	PUSHR
	clrl	r0
	brb	1f
SCBVEC(nex1zvec):
	PUSHR
	movl	$1,r0
1:
	cmpl	_cpu,$VAX_8600		# this is a frill
	beql	2f
	mfpr	$IPL,-(sp)
	PRINTF(1, "nexus stray intr ipl%x\n")
	POPR
E 160
E 50
E 37
	rei
I 59
D 160
SCBVEC(nexzvec):
	PUSHR; mfpr $IPL,-(sp); PRINTF(1, "nexus stray intr ipl%x\n"); POPR; rei
E 160
I 160
2:
	pushl	r0
	mfpr	$IPL,-(sp)
	PRINTF(2, "nexus stray intr ipl%x sbia%d\n")
	POPR
	rei

E 160
E 59
I 50
SCBVEC(cmrd):
	PUSHR; calls $0,_memerr; POPR; rei
E 50
I 37
D 160
SCBVEC(wtime):
D 50
	PUSHR; pushl 6*4(sp); PRINTF(1,"Write timeout %x\n"); POPR;
	PANIC("Write timeout");		/* should be rei? */
E 50
I 50
	PUSHR; pushl 6*4(sp); PRINTF(1,"write timeout %x\n"); POPR;
	PANIC("wtimo");
E 160
E 50
E 37

I 160
SCBVEC(wtime):			/* sbi0err on 8600 */
#if VAX8600
	cmpl	_cpu,$VAX_8600
	bneq	wtimo
	PANIC("sbia0 error")
wtimo:
#endif
	PUSHR; pushl 6*4(sp); PRINTF(1, "write timeout %x\n"); POPR
	PANIC("wtimo")

SCBVEC(sbi0fail):
	PANIC("sbia0 fail")
SCBVEC(sbi0alert):
#if VAX8200
	cmpl	_cpu,$VAX_8200
	bneq	alert
	PUSHR; calls $0,_rxcdintr; POPR; rei
alert:
#endif
	PANIC("sbia0 alert")
SCBVEC(sbi0fault):
	PANIC("sbia0 fault")

#ifdef notyet
#if VAX8600
SCBVEC(sbi1fail):
	PANIC("sbia1 fail")
SCBVEC(sbi1alert):
	PANIC("sbia1 alert")
SCBVEC(sbi1fault):
	PANIC("sbia1 fault")
SCBVEC(sbi1err):
	PANIC("sbia1 error")
#endif
#endif

/*
 * BI 0 bus error (8200), or SBI silo compare error (others)
 * VMS boot leaves us 1 BI error to ignore.
 */
#if VAX8200 && 0
	.data
	.align	2
_ignorebi: .globl _ignorebi
	.long	1
	.text
#endif VAX8200

SCBVEC(sbisilo):
#if VAX8200
	cmpl	_cpu,$VAX_8200
	bneq	sbisilo
#if 0
	blbs	_ignorebi,1f
#else
	blbs	_cold,1f
#endif
	PUSHR; pushl $0; calls $1,_bi_buserr; POPR
1:
	rei
#endif
sbisilo:
	PANIC("sbi silo compare error")

/*
 * SCB stray interrupt catcher.  Compute and print the actual
 * SCB vector (for fault diagnosis).
 */
	.align	2
_scbstray: .globl _scbstray
#define	PJ	PUSHR;jsb 1f
	/* 128 of 'em */
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
D 171
#if VAX8600
E 171
I 171
#if VAX8600 || NEED_BABYVAX_SUPPORT
E 171
	/* and another 128, for the second SBIA's scb */
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
#endif
#undef PJ
1:
	subl3	$_scbstray+8,(sp)+,r0
	mfpr	$IPL,-(sp)
	ashl	$-1,r0,-(sp)
/* call a C handler instead? perhaps later */
	PRINTF(2, "stray scb intr vec 0x%x ipl%x\n")
	POPR
	rei

E 160
I 47
#if NMBA > 0
E 47
D 22
#
# Massbus 0 adapter interrupts
#
E 22
I 22
D 37
#if VAX==750
E 22
	.align	2
I 22
D 25
Xubastray:
E 25
I 25
___:
E 25
	pushr	$0x3f
	pushab	UBAstraym
	calls	$1,_printf
	popr	$0x3f
	rei
E 37
I 37
D 57
#if VAX780
E 57
SCBVEC(mba3int):
D 125
	PUSHR; pushl $3; brb 1f
E 125
I 125
	PUSHR; incl _intrcnt+I_MBA3; pushl $3; brb 1f
E 125
D 57
#endif
E 57
SCBVEC(mba2int):
D 125
	PUSHR; pushl $2; brb 1f
E 125
I 125
	PUSHR; incl _intrcnt+I_MBA2; pushl $2; brb 1f
E 125
SCBVEC(mba1int):
D 125
	PUSHR; pushl $1; brb 1f
E 125
I 125
	PUSHR; incl _intrcnt+I_MBA1; pushl $1; brb 1f
E 125
SCBVEC(mba0int):
D 125
	PUSHR; pushl $0
E 125
I 125
	PUSHR; incl _intrcnt+I_MBA0; pushl $0
E 125
1:	calls $1,_mbintr
	POPR
D 38
	REI
E 38
I 38
	incl	_cnt+V_INTR
	rei
I 47
#endif
E 47
E 38
E 37
D 25
#endif
E 25

I 23
D 37
	.align	2
D 26
	.globl	Xwtime
E 26
Xwtime:
	pushr	$0x3f
	pushl	6*4(sp)			# push pc
	pushab	wtime
	calls	$2,_printf
	popr	$0x3f
D 25
	halt
E 25
I 25
	halt				### ?? like a machine check
E 37
I 37
D 140
#if VAX780
E 140
I 140
D 152
#if defined(VAX780) || defined(VAX8600)
E 152
I 152
#ifdef DW780
E 152
E 140
D 42
/* Special register return of IPL and interrupt vector during configuration */
SCBVEC(confuaint):
	mfpr	$IPL,r11
	movl	_curuba,r0
	movl	UBA_BRRVR-0x14*4(r0)[r11],r10
E 37
E 25
	rei
E 23

E 42
I 25
D 37
#endif
E 37
E 25
D 36
#if VAX==780
I 27
#include "hp.h"
#include "ht.h"
E 36
E 27
/*
D 37
 * Massbus 0 adapter interrupts
E 37
I 37
 * Registers for the uba handling code
E 37
 */
D 37
	.align	2
E 22
D 36
Xmba0int:
E 36
I 36
	.globl	_mba0int
_mba0int:
E 36
	pushr	$0x3f			# save r0 - r5
D 36
	movab	MBA0_CSR,r0		# point at mba regs
	movl	MBA_AS(r0),r1		# get attn summary bits
	cvtwl	r1,-(sp)		# push attn summary as arg
	pushl	MBA_SR(r0)		# pass sr as argument
	mnegl	$1,MBA_SR(r0)		# clear attention bit
D 27
	calls	$2,_hpintr		# call rp06 interrupt dispatcher
E 27
I 27
#if (NHP > 0) && HPMBANUM==0
	calls	$2,_hpintr
#else
#if (NHT > 0) && HTMBANUM==0
	calls	$2,_htintr
#else
E 36
	pushl	$0
D 36
	pushl	mbasmsg
	calls	$4,_printf
#endif
#endif
E 27
	brw 	int_ret			# merge with common interrupt code
E 36
I 36
	brb	1f
E 37
I 37
#define	rUBANUM	r0
#define	rUBAHD	r1
#define	rUVEC	r3
#define	rUBA	r4
/* r2,r5 are scratch */
E 37
E 36

I 144
#define	I_UBA	I_UBA0		/* base of UBA interrupt counters */

E 144
I 139
#if NUBA > 4
SCBVEC(ua7int):
	PUSHR; movl $7,rUBANUM; moval _uba_hd+(7*UH_SIZE),rUBAHD; brb 1f
SCBVEC(ua6int):
	PUSHR; movl $6,rUBANUM; moval _uba_hd+(6*UH_SIZE),rUBAHD; brb 1f
SCBVEC(ua5int):
	PUSHR; movl $5,rUBANUM; moval _uba_hd+(5*UH_SIZE),rUBAHD; brb 1f
SCBVEC(ua4int):
	PUSHR; movl $4,rUBANUM; moval _uba_hd+(4*UH_SIZE),rUBAHD; brb 1f
#endif
E 139
D 22
#
# Massbus 1 adapter interrupts
#
E 22
I 22
D 37
/*
 * Massbus 1 adapter interrupts
 */
E 22
	.align	2
D 36
Xmba1int:
	pushr	$0x3f
	movab	MBA1_CSR,r0
	pushl	MBA_AS(r0)
	mnegl	$1,MBA_AS(r0)
	pushl	MBA_SR(r0)		# pass sr as argument
	mnegl	$1,MBA_SR(r0)		# clear attention bit
D 27
	calls	$2,_htintr		# call te16 interrupt dispatcher
E 27
I 27
#if (NHP > 0) && HPMBANUM==1
	calls	$2,_hpintr
#else
#if (NHT > 0) && HTMBANUM==1
	calls	$2,_htintr
#else
E 36
I 36
	.globl	_mba1int
_mba1int:
	pushr	$0x3f			# save r0 - r5
E 36
	pushl	$1
D 36
	pushl	mbasmsg
	calls	$4,_printf
#endif
#endif
E 27
	brw 	int_ret			# return from interrupt
E 36
I 36
	brb	1f
E 36

D 22
#
# Unibus adapter interrupts
#
E 22
I 22
/*
I 36
 * Massbus 2 adapter interrupts
 */
	.align	2
	.globl	_mba2int
_mba2int:
	pushr	$0x3f			# save r0 - r5
	pushl	$2
	brb	1f

#if VAX==780 || VAX==ANY
/*
 * Massbus 3 adapter interrupts
 */
	.align	2
	.globl	_mba3int
_mba3int:
	pushr	$0x3f			# save r0 - r5
	pushl	$3
E 37
I 37
SCBVEC(ua3int):
	PUSHR; movl $3,rUBANUM; moval _uba_hd+(3*UH_SIZE),rUBAHD; brb 1f
SCBVEC(ua2int):
	PUSHR; movl $2,rUBANUM; moval _uba_hd+(2*UH_SIZE),rUBAHD; brb 1f
SCBVEC(ua1int):
	PUSHR; movl $1,rUBANUM; moval _uba_hd+(1*UH_SIZE),rUBAHD; brb 1f
SCBVEC(ua0int):
	PUSHR; movl $0,rUBANUM; moval _uba_hd+(0*UH_SIZE),rUBAHD;
E 37
1:
I 59
D 131
	incl	_cnt+V_INTR
E 131
E 59
D 37
	calls	$1,_mbintr
	brw 	int_ret			# merge with common interrupt code

/*
E 36
 * Unibus adapter interrupts
 */
E 22
	.align	2
D 36
Xua0int:
E 36
I 36
	.globl	_ua0int
_ua0int:
E 36
	pushr	$0x3f  			# save regs 0-5
I 36
	moval	_uba_hd,r1		# r1 = &uba_hd[0]
	brb	1f

	.align	2
	.globl	_ua1int
_ua1int:
	pushr	$0x3f
	moval	_uba_hd+24,r1		# r1 = &uba_hd[1]
	brb	1f

	.align	2
	.globl	_ua2int
_ua2int:
	pushr	$0x3f
	moval	_uba_hd+48,r1		# r1 = &uba_hd[2]
	brb	1f

	.align	2
	.globl	_ua3int
_ua3int:
	pushr	$0x3f
	moval	_uba_hd+72,r1		# r1 = &uba_hd[3]

1:
E 36
	mfpr	$IPL,r2			# get br level
D 36
	movl	UBA0+UBR_OFF-20*4[r2],r3# get unibus device vector
E 36
I 36
	movl	4(r1),r3		# r3 = uba_hd[?].uh_uba
	movl	UBR_OFF-20*4(r3)[r2],r3	# get unibus device vector
E 36
	bleq	ubasrv  		# branch if zero vector
					# ... or UBA service required

D 22
#
# Normal UBA interrupt point - device on a UBA has generated an
# interrupt - r3 holds interrupt vector.  Get the service routine
# address and controller code from the UNIBUS vector area
# and service the interrupt.
#
E 22
I 22
/*
 * Normal UBA interrupt point - device on a UBA has generated an
 * interrupt - r3 holds interrupt vector.  Get the service routine
 * address and controller code from the UNIBUS vector area
 * and service the interrupt.
 */
E 37
I 37
	mfpr	$IPL,r2				/* r2 = mfpr(IPL); */
	movl	UH_UBA(rUBAHD),rUBA		/* uba = uhp->uh_uba; */
	movl	UBA_BRRVR-0x14*4(rUBA)[r2],rUVEC
					/* uvec = uba->uba_brrvr[r2-0x14] */
E 37
E 22
ubanorm:
D 36
	movl	_UNIvec(r3),r1 
E 36
I 36
D 37
	addl2	0xc(r1),r3		# r3 += uba_hd[?].uh_vec
	movl	*(r3),r1 
E 36
	extzv	$27,$4,r1,r0  		# controller code is in 4 most
					# significant bits-1 of ISR addr
	bicl2	$0x78000000,r1		# clear code
	jlbc	r1,ubanpdma		# no pseudo dma here
	jmp 	-1(r1)			# branch to pseudo dma rtn
ubanpdma:
	pushl	r0			# controller code
	calls	$1,(r1)  		# call ISR
	brw	int_ret			# go to common interrupt return

D 22
#
# Come here for zero or negative UBA interrupt vector.
# Negative vector -> UBA requires service.
#
E 22
I 22
/*
 * Come here for zero or negative UBA interrupt vector.
 * Negative vector -> UBA requires service.
 */
E 22
ubasrv:
D 18
	beql	ubapass
E 18
I 18
	jeql	ubapass
E 18
D 22
#
# UBA service required.
# The following 'printf' calls should probably be replaced
# with calls to an error logger and/or some corrective action.
#
E 22
I 22
/*
 * UBA service required.
 * The following 'printf' calls should probably be replaced
 * with calls to an error logger and/or some corrective action.
 */
E 22
	bitl	$CFGFLT,UBA0+UCN_OFF  	# any SBI faults ?
	beql	UBAflt
I 18
D 21
	clrl	_waittime
E 18
	pushr	$0xf  			# save regs 0-3
E 21
I 21
D 22
	pushr	$0x3f  			# save regs 0-5
E 22
I 22
D 28
	clrl	_waittime
	pushr	$0xf  			# save regs 0-3
E 28
I 28
	pushr	$0x3f  			# save regs 0-5
E 28
E 22
E 21
I 18
	pushl	UBA0+UCN_OFF
	pushl	UBA0+UST_OFF
	pushab	SBIflt
	calls	$3,_printf
E 18
D 21
	pushab	SBImsg
D 15
	calls	$1,_printf
	popr	$0xf
E 15
I 15
	calls	$1,_panic
#	popr	$0xf
E 21
I 21
D 22
#	pushab	SBImsg
#	calls	$1,_panic
E 22
	movl	UBA0+UCN_OFF,UBA0+UCN_OFF
	calls	$0,_ubareset
	popr	$0x3f
	brw	int_ret
E 21

E 15
D 8
	halt
E 8
D 22
#
# No SBI fault bits set in UBA config reg - must be
# some error bits set in UBA status reg.
#
E 22
I 22
/*
 * No SBI fault bits set in UBA config reg - must be
 * some error bits set in UBA status reg.
 */
E 22
UBAflt:
	movl	UBA0+UST_OFF,r2  	# UBA status reg
D 21
	pushr	$0xf  			# save regs 0-3
E 21
I 21
D 22
	pushr	$0x3f  			# save regs 0-3
E 22
I 22
	pushr	$0x3f  			# save regs 0-5
E 22
E 21
	mfpr	$IPL,-(sp)
	mtpr	$HIGH,$IPL
	pushl	UBA0+UFUBAR_OFF
I 18
	ashl	$2,(sp),(sp)
E 18
	pushl	UBA0+UFMER_OFF
	pushl	r2
	pushab	UBAmsg
	calls	$4,_printf
	mtpr	(sp)+,$IPL
D 21
	popr	$0xf
E 21
I 21
	popr	$0x3f
E 21
	movl	r2,UBA0+UST_OFF		# clear error bits
	bicl2	$0x80000000,r3  	# clear neg bit in vector
	jneq	ubanorm  		# branch if normal UBA interrupt
					# to process
	brw 	int_ret			# restore regs and return
D 22
#
# Zero interrupt vector - count 'em
#
E 22
I 22
/*
 * Zero interrupt vector - count 'em
 */
E 22
ubapass:
	incl	_zvcnt
I 7
	cmpl	_zvcnt,$250000
	jlss	int_ret
D 11
	pushab	$ZERmsg
E 11
I 11
	pushab	ZERmsg
E 11
	calls	$1,_printf
	clrl	_zvcnt
	calls	$0,_ubareset
E 7
	brw 	int_ret
E 37
I 37
	bleq	ubaerror 
	addl2	UH_VEC(rUBAHD),rUVEC		/* uvec += uh->uh_vec */
	bicl3	$3,(rUVEC),r1 
	jmp	2(r1)				/* 2 skips ``pushr $0x3f'' */
ubaerror:
I 125
D 130
	incl _intrcnt+I_UBA[rUBA]
E 130
I 130
D 131
	incl _intrcnt+I_UBA[rUBANUM]
E 131
E 130
E 125
	PUSHR; calls $0,_ubaerror; POPR		/* ubaerror r/w's r0-r5 */
	tstl rUVEC; jneq ubanorm		/* rUVEC contains result */
I 131
	incl _intrcnt+I_UBA[rUBANUM]
	incl	_cnt+V_INTR
E 131
	POPR
	rei
E 37
I 22
#endif
I 23
D 37

E 23
#if VAX==750
/*
 * Console data storage
 */
Xconsdin:
Xconsdout:
	.align	2
E 37
I 37
SCBVEC(cnrint):
D 38
	PUSHR; calls $0,_cnrint; POPR; REI
E 38
I 38
D 125
	PUSHR; calls $0,_cnrint; POPR; incl _cnt+V_INTR; rei
E 125
I 125
	PUSHR; calls $0,_cnrint; POPR
	incl _cnt+V_INTR
	incl _intrcnt+I_CNR
	rei
E 125
E 38
SCBVEC(cnxint):
D 38
	PUSHR; calls $0,_cnxint; POPR; REI
SCBVEC(clockint):
E 38
I 38
D 125
	PUSHR; calls $0,_cnxint; POPR; incl _cnt+V_INTR; rei
E 125
I 125
	PUSHR; calls $0,_cnxint; POPR
	incl _cnt+V_INTR
	incl _intrcnt+I_CNX
	rei
E 125
SCBVEC(hardclock):
E 38
	PUSHR
I 87
	mtpr $ICCS_RUN|ICCS_IE|ICCS_INT|ICCS_ERR,$ICCS
E 87
D 38
	pushl 4+6*4(sp); pushl 4+6*4(sp); calls $2,_clock	# clock(pc,psl)
	POPR; REI
E 38
I 38
D 126
	pushl 4+6*4(sp); pushl 4+6*4(sp);
	calls $2,_hardclock			# hardclock(pc,psl)
E 126
I 88
#if NPS > 0
	pushl	4+6*4(sp); pushl 4+6*4(sp);
	calls	$2,_psextsync
#endif
I 126
	pushl 4+6*4(sp); pushl 4+6*4(sp);
	calls $2,_hardclock			# hardclock(pc,psl)
E 126
E 88
	POPR;
D 125
	incl	_cnt+V_INTR		## temp so not to break vmstat -= HZ
E 125
I 125
	incl	_cnt+V_INTR
	incl	_intrcnt+I_CLOCK
E 125
	rei
SCBVEC(softclock):
	PUSHR
D 88
	pushl 4+6*4(sp); pushl 4+6*4(sp);
	calls $2,_softclock			# softclock(pc,psl)
E 88
I 88
D 116
#if NDZ > 0
	calls	$0,_dztimer
#endif
#if NDH > 0
	calls	$0,_dhtimer
#endif
E 116
	pushl	4+6*4(sp); pushl 4+6*4(sp);
	calls	$2,_softclock			# softclock(pc,psl)
E 88
	POPR; 
I 125
	incl	_cnt+V_SOFT
E 125
	rei
I 140

E 140
I 89
#include "../net/netisr.h"
E 89
I 73
D 75
#ifdef BBNNET
E 75
I 75
D 82
#ifdef INET
E 75
D 76
SCBVEC(netintr):
E 76
I 76
SCBVEC(ipintr):
E 82
I 82
	.globl	_netisr
SCBVEC(netintr):
E 82
E 76
	PUSHR
D 76
	calls $0,_netintr
E 76
I 76
D 82
	calls $0,_ipintr
E 82
I 82
D 138
	bbcc	$NETISR_RAW,_netisr,1f; calls $0,_rawintr; 1:
E 138
I 138
#include "imp.h"
#if NIMP > 0
	bbcc	$NETISR_IMP,_netisr,1f; calls $0,_impintr; 1:
#endif
E 138
D 141
#ifdef INET
E 141
I 141
D 143
#if defined(INET) || defined(BBNNET)
E 143
I 143
#ifdef INET
E 143
E 141
I 89
D 140
#include "../netinet/in_systm.h"
E 140
E 89
	bbcc	$NETISR_IP,_netisr,1f; calls $0,_ipintr; 1:
#endif
#ifdef NS
	bbcc	$NETISR_NS,_netisr,1f; calls $0,_nsintr; 1:
#endif
I 167
#include "ppp.h"
#if NPPP > 0
	bbcc	$NETISR_PPPCTL,_netisr,1f; calls $0,_pppctlintr; 1:
#endif
E 167
I 138
	bbcc	$NETISR_RAW,_netisr,1f; calls $0,_rawintr; 1:
E 138
E 82
E 76
	POPR
I 125
	incl	_cnt+V_SOFT
E 125
	rei
I 140

E 140
I 77
D 82
SCBVEC(rawintr):
	PUSHR
	calls $0,_rawintr
	POPR
	rei
E 77
#endif
E 82
I 74
D 84
#if defined(VAX750) || defined(VAX7ZZ)
E 84
I 84
D 139
#if defined(VAX750) || defined(VAX730)
E 139
I 139
D 160
#if defined(VAX750) || defined(VAX730) || defined(VAX8600)
E 160
E 139
E 84
E 74
E 73
E 38
SCBVEC(consdin):
I 74
D 101
	PUSHR; calls $0,_turintr; POPR; incl _cnt+V_INTR; rei
E 101
I 101
	PUSHR;
I 125
D 160
	incl _intrcnt+I_TUR
E 125
D 105
#if defined(VAX750) && !defined(MRSP)
E 105
I 105
D 139
#if defined(VAX750) && !defined(VAX730) && !defined(MRSP)
E 139
I 139
	casel	_cpu,$VAX_750,$VAX_8600
E 160
I 160
	incl	_intrcnt+I_TUR
	casel	_cpu,$VAX_750,$VAX_8200
E 160
0:
	.word	5f-0b		# 2 is VAX_750
	.word	3f-0b		# 3 is VAX_730
	.word	6f-0b		# 4 is VAX_8600
I 160
	.word	7f-0b		# 5 is VAX_8200
E 160
	halt
5:
#if defined(VAX750) && !defined(MRSP)
E 139
E 105
	jsb	tudma
#endif
D 139
	calls $0,_turintr;
E 139
I 139
3:
#if defined(VAX750) || defined(VAX730)
D 160
	calls $0,_turintr
	brb 2f
E 160
I 160
	calls	$0,_turintr
	brb	2f
E 160
#else
	halt
#endif
I 160
7:
#if VAX8200
	calls	$0,_rx50intr
	brb	2f
#else
	halt
#endif
E 160
6:
#if VAX8600
D 160
	calls $0, _crlintr
E 160
I 160
	calls	$0,_crlintr
E 160
#else
	halt
#endif
2:
E 139
D 160
	POPR;
	incl _cnt+V_INTR;
E 160
I 160
	POPR
	incl	_cnt+V_INTR
E 160
	rei
I 139
D 160
#else
SCBVEC(consdin):
	halt
#endif
E 160

#if defined(VAX750) || defined(VAX730)
E 139
E 101
SCBVEC(consdout):
D 125
	PUSHR; calls $0,_tuxintr; POPR; incl _cnt+V_INTR; rei
E 125
I 125
	PUSHR; calls $0,_tuxintr; POPR
	incl _cnt+V_INTR
	incl _intrcnt+I_TUX
	rei
E 125
#else
D 139
SCBVEC(consdin):
E 74
E 37
	halt
E 139
D 25

/*
 * Dz
 */
	.globl	Xdzrint
	.align	2
Xdzrint:
	pushr	$0x3f
	pushl	$0
	calls	$1,_dzrint
	jmp	int_ret

	.globl	Xdzxint
	.align	2
Xdzxint:
	pushr	$0x3f
	clrl	r0			# show controller 0 (board 0)
	jbr	_dzdma

/*
 * Rk
 */
	.align	2
Xrkintr:
	pushr	$0x3f
	calls	$0,_rkintr
	jbr	int_ret

I 23
Xobiint:
	.align	2
	halt

Xoboint:
	.align	2
	halt

E 23
/*
I 23
 * Emulex SC-11/21
 */
	.align	2
Xupintr:
	pushr	$0x3f
	calls	$0,_upintr
	jbr	int_ret

/*
E 23
 * Dk
 */
	.align	2
Xdkrint:
	pushr	$0x3f
	calls	$0,_dkrint
	jbr	int_ret
	.align	2
Xdkxint:
	pushr	$0x3f
	calls	$0,_dkxint
	jbr	int_ret

/*
 * Ts
 */
	.align	2
Xtsintr:
	pushr	$0x3f
	calls	$0,_tsintr
	jbr	int_ret
E 25
D 37
#endif
E 37
I 37
SCBVEC(consdout):
	halt
I 74
#endif
E 74
E 37

I 53
#if NDZ > 0
E 53
E 22
D 37
	.data
I 22
#if VAX==780
E 22
	.globl	_zvcnt
_zvcnt:	.space	4
I 22
#endif
E 22
I 5
	.globl	_dzdcnt
_dzdcnt:.space	4
E 5
	.text
E 37
I 37
D 38
/* THIS SHOULD BE GOTTEN RID OF... WE SHOULD USE AST'S TO FORCE RESCHEDS */
int_ret:
	incl	_cnt+V_INTR
	bitl	$PSL_CURMOD,4(sp)	# CRUD
	beql	1f			# CRUD
	tstb	_runrun			# CRUD
	beql	1f			# CRUD
	mtpr	$0x18,$IPL		# CRUD
	mtpr	$3,$SIRR		# CRUD
1:	rei
E 37

E 38
D 22
#
# DZ pseudo dma routine:
#	r0 - controller number
#
E 22
I 22
/*
 * DZ pseudo dma routine:
 *	r0 - controller number
 */
E 22
	.align	1
D 101
	.globl	_dzdma
_dzdma:
E 101
I 101
	.globl	dzdma
dzdma:
E 101
D 22
#	bisw2	$4,*_draddr	# leading edge for dr11-c
E 22
	mull2	$8*20,r0
	movab	_dzpdma(r0),r3		# pdma structure base
					# for this controller
dzploop:
	movl	r3,r0	
	movl	(r0)+,r1		# device register address
	movzbl	1(r1),r2		# get line number
	bitb	$0x80,r2		# TRDY on?
	beql	dzprei			# no	
I 5
D 37
	incl	_dzdcnt		## loop trips
E 37
E 5
	bicb2	$0xf8,r2		# clear garbage bits
	mull2	$20,r2
	addl2	r2,r0			# point at line's pdma structure
	movl	(r0)+,r2		# p_mem
	cmpl	r2,(r0)+		# p_mem < p_end ?
	bgequ	dzpcall			# no, go call dzxint
	movb	(r2)+,6(r1)		# dztbuf = *p_mem++
	movl	r2,-8(r0)
	brb 	dzploop			# check for another line
dzprei:
D 22
#	bicw2	$4,*_draddr	# trailing edge for dr11-c
E 22
D 37
	popr	$0x3f
E 37
I 37
	POPR
E 37
	incl	_cnt+V_PDMA
	rei

dzpcall:
D 36
	pushl	(r0)			# push tty address
	calls	$1,_dzxint		# call interrupt rtn
E 36
I 36
	pushl	r3
	pushl	(r0)+			# push tty address
	calls	$1,*(r0)		# call interrupt rtn
	movl	(sp)+,r3
E 36
	brb 	dzploop			# check for another line
I 173
#endif

#if NSS > 0
/*
 * ss pseudo dma routine:
 *	r0 - controller number (ignored since there is only one ss)
 */
	.align	1
	.globl	ssdma
ssdma:
	movab	_sspdma,r3		# pdma structure base
					# for this controller
ssploop:
	movl	r3,r0	
	movl	(r0)+,r1		# device register address
	movzbl	1(r1),r2		# get line number
	bitb	$0x80,r2		# TRDY on?
	beql	ssprei			# no	
	bicb2	$0xf8,r2		# clear garbage bits
	mull2	$20,r2
	addl2	r2,r0			# point at line's pdma structure
	movl	(r0)+,r2		# p_mem
	cmpl	r2,(r0)+		# p_mem < p_end ?
	bgequ	sspcall			# no, go call dzxint
	movb	(r2)+,0xC(r1)		# dztbuf = *p_mem++
	movl	r2,-8(r0)
	brb 	ssploop			# check for another line
ssprei:
	POPR
	incl	_cnt+V_PDMA
	rei

sspcall:
	pushl	r3
	pushl	(r0)+			# push tty address
	calls	$1,*(r0)		# call interrupt rtn
	movl	(sp)+,r3
	brb 	ssploop			# check for another line
E 173
I 101
#endif

#if NUU > 0 && defined(UUDMA)
/*
 * Pseudo DMA routine for tu58 (on DL11)
 *	r0 - controller number
 */
	.align	1
	.globl	uudma
uudma:
	movl	_uudinfo[r0],r2
	movl	16(r2),r2		# r2 = uuaddr
	mull3	$48,r0,r3
	movab	_uu_softc(r3),r5	# r5 = uuc

	cvtwl	2(r2),r1		# c = uuaddr->rdb
	bbc	$15,r1,1f		# if (c & UUDB_ERROR)
	movl	$13,16(r5)		#	uuc->tu_state = TUC_RCVERR;
	rsb				#	let uurintr handle it
1:
	tstl	4(r5)			# if (uuc->tu_rcnt) {
	beql	1f
	movb	r1,*0(r5)		#	*uuc->tu_rbptr++ = r1
	incl	(r5)
	decl	4(r5)			#	if (--uuc->tu_rcnt)
	beql	2f			#		done
	tstl	(sp)+
	POPR				# 	registers saved in ubglue.s
	rei				# }
2:
	cmpl	16(r5),$8		# if (uuc->tu_state != TUS_GETH)
	beql	2f			# 	let uurintr handle it
1:
	rsb
2:
	mull2	$14,r0			# sizeof(uudata[ctlr]) = 14
	movab	_uudata(r0),r4		# data = &uudata[ctlr];
	cmpb	$1,(r4)			# if (data->pk_flag != TUF_DATA)
	bneq	1b
#ifdef notdef
	/* this is for command packets */
	beql	1f			# 	r0 = uuc->tu_rbptr
	movl	(r5),r0
	brb	2f
1:					# else
#endif
	movl	24(r5),r0		# 	r0 = uuc->tu_addr
2:
	movzbl	1(r4),r3		# counter to r3 (data->pk_count)
	movzwl	(r4),r1			# first word of checksum (=header)
	mfpr	$IPL,-(sp)		# s = spl5();
	mtpr	$0x15,$IPL		# to keep disk interrupts out
	clrw	(r2)			# disable receiver interrupts
3:	bbc	$7,(r2),3b		# while ((uuaddr->rcs & UUCS_READY)==0);
	cvtwb	2(r2),(r0)+		# *buffer = uuaddr->rdb & 0xff
	sobgtr	r3,1f			# continue with next byte ...
	addw2	2(r2),r1		# unless this was the last (odd count)
	brb	2f

1:	bbc	$7,(r2),1b		# while ((uuaddr->rcs & UUCS_READY)==0);
	cvtwb	2(r2),(r0)+		# *buffer = uuaddr->rdb & 0xff
	addw2	-2(r0),r1		# add to checksum..
2:
	adwc	$0,r1			# get the carry
	sobgtr	r3,3b			# loop while r3 > 0
/*
 * We're ready to get the checksum
 */
1:	bbc	$7,(r2),1b		# while ((uuaddr->rcs & UUCS_READY)==0);
	cvtwb	2(r2),12(r4)		# get first (lower) byte
1:	bbc	$7,(r2),1b
	cvtwb	2(r2),13(r4)		# ..and second
	cmpw	12(r4),r1		# is checksum ok?
	beql	1f
	movl	$14,16(r5)		# uuc->tu_state = TUS_CHKERR
	brb	2f			# exit
1:
	movl	$11,16(r5)		# uuc->tu_state = TUS_GET (ok)
2:
	movw	$0x40,(r2)		# enable receiver interrupts
	mtpr	(sp)+,$IPL		# splx(s);
	rsb				# continue processing in uurintr
#endif

D 105
#if defined(VAX750) && !defined(MRSP)
E 105
I 105
D 139
#if defined(VAX750) && !defined(VAX730) && !defined(MRSP)
E 139
I 139
#if defined(VAX750) && !defined(MRSP)
E 139
E 105
/*
D 105
 * Pseudo DMA routine for console tu58 
E 105
I 105
 * Pseudo DMA routine for VAX-11/750 console tu58 
E 105
 *   	    (without MRSP)
 */
	.align	1
	.globl	tudma
tudma:
	movab	_tu,r5			# r5 = tu
	tstl	4(r5)			# if (tu.tu_rcnt) {
	beql	3f
	mfpr	$CSRD,r1		# get data from tu58
	movb	r1,*0(r5)		#	*tu.tu_rbptr++ = r1
	incl	(r5)
	decl	4(r5)			#	if (--tu.tu_rcnt)
	beql	1f			#		done
	tstl	(sp)+
	POPR				# 	registers saved in ubglue.s
	rei				# 	data handled, done
1:					# }
	cmpl	16(r5),$8		# if (tu.tu_state != TUS_GETH)
	beql	2f			# 	let turintr handle it
3:
	rsb
2:
	movab	_tudata,r4		# r4 = tudata
	cmpb	$1,(r4)			# if (tudata.pk_flag != TUF_DATA)
	bneq	3b			# 	let turintr handle it
1:					# else
	movl	24(r5),r1		# get buffer pointer to r1
	movzbl	1(r4),r3		# counter to r3
	movzwl	(r4),r0			# first word of checksum (=header)
	mtpr	$0,$CSRS		# disable receiver interrupts
3:
	bsbw	5f			# wait for next byte
	mfpr	$CSRD,r5
	movb	r5,(r1)+		# *buffer = rdb
	sobgtr	r3,1f			# continue with next byte ...
	mfpr	$CSRD,r2		# unless this was the last (odd count)
	brb	2f

1:	bsbw	5f			# wait for next byte
	mfpr	$CSRD,r5
	movb	r5,(r1)+		# *buffer = rdb
	movzwl	-2(r1),r2		# get the last word back from memory
2:
	addw2	r2,r0			# add to checksum..
	adwc	$0,r0			# get the carry
	sobgtr	r3,3b			# loop while r3 > 0
/*
 * We're ready to get the checksum.
 */
	bsbw	5f
	movab	_tudata,r4
	mfpr	$CSRD,r5
	movb	r5,12(r4)		# get first (lower) byte
	bsbw	5f
	mfpr	$CSRD,r5
	movb	r5,13(r4)		# ..and second
	movab	_tu,r5
	cmpw	12(r4),r0		# is checksum ok?
	beql	1f
	movl	$14,16(r5)		# tu.tu_state = TUS_CHKERR
	brb	2f			# exit
1:
	movl	$11,16(r5)		# tu.tu_state = TUS_GET
2:
	mtpr	$0x40,$CSRS		# enable receiver interrupts
	rsb				# continue processing in turintr
/*
 * Loop until a new byte is ready from
 * the tu58, make sure we don't loop forever
 */
5:
D 102
	movl	$10000,r5		# loop max 10000 times
E 102
I 102
D 105
	mfpr	$IPL,-(sp)		# can't loop at ipl7, better
	mtpr	$0x15,$IPL		# move down to 5
E 105
	movl	$5000,r5		# loop max 5000 times
E 102
1:
	mfpr	$CSRS,r2
	bbs	$7,r2,1f
	sobgtr	r5,1b
	movab	_tu,r5
	movl	$13,16(r5)		# return TUS_RCVERR
I 102
D 105
	mtpr	(sp)+,$IPL
E 105
E 102
	tstl	(sp)+			# and let turintr handle it
D 102
	mtpr	$0x40,$CSRS		# enable receiver interrupts
E 102
I 102
D 105
	rsb				# before we go back to turintr
E 105
E 102
1:
I 102
D 105
	mtpr	(sp)+,$IPL
E 105
E 102
	rsb
E 101
I 53
#endif
E 53

D 22
#
# Console receiver interrupt
#
E 22
I 22
/*
I 160
 * BI passive release things.
 */
SCBVEC(passiverel):
	rei				# well that was useless

/*
E 160
D 37
 * Console receiver interrupt
E 37
I 37
 * Stray UNIBUS interrupt catch routines
E 37
 */
E 22
D 37
	.align	2
Xcnrint:
	pushr	$0x3f			# save registers 0 - 5
	calls	$0,_cnrint
	brb 	int_ret			# merge

D 22
#
# Console transmit interrupt
#
E 22
I 22
/*
 * Console transmit interrupt
 */
E 22
	.align	2
Xcnxint:
	pushr	$0x3f			# save registers 0 - 5
	calls	$0,_cnxint
	brb 	int_ret

D 22
#
# Clock interrupt
#
E 22
I 22
/*
 * Clock interrupt
 */
E 22
	.align	2
Xclockint:
	pushr	$0x3f			# save regs 0 - 5
	pushl	4+6*4(sp)		# push psl
	pushl	4+6*4(sp)		# push pc
	calls	$2,_clock
	brb 	int_ret

D 22
#
# Common code for interrupts.
# At this point, the interrupt stack looks like:
#
#	r0	<- isp
#	...
#	r5
#	pc
#	psl
#
E 22
I 22
/*
 * Common code for interrupts.
 * At this point, the interrupt stack looks like:
 *
 *	r0	<- isp
 *	...
 *	r5
 *	pc
 *	psl
 */
E 22

int_ret:
	incl	_cnt+V_INTR
D 22
#	bbssi	$0,idleflag,int_r0	# escape from idle() if old switch code
#int_r0:
E 22
	popr	$0x3f			# restore regs 0 - 5
	bitl	$PSL_CURMOD,4(sp)	# interrupt from user mode?
	beql	int_r1			# no, from kernel, just rei
	tstb	_runrun			# should we reschedule?
	beql	int_r1			# no, just rei
D 22
#
# If here, interrupt from user mode, and time to reschedule.
# To do this, we set a software level 3 interrupt to
# change to kernel mode, switch stacks, and format
# kernel stack for a `qswitch' trap to force a reschedule.
#
E 22
I 22
/*
 * If here, interrupt from user mode, and time to reschedule.
 * To do this, we set a software level 3 interrupt to
 * change to kernel mode, switch stacks, and format
 * kernel stack for a `qswitch' trap to force a reschedule.
 */
E 22
	mtpr	$0x18,$IPL
	mtpr	$3,$SIRR		# request level 1 software interrupt
int_r1:
	rei 				# return to interrupted process

D 22
# ==================================
# User area virtual addresses
# ==================================
E 22
I 22
/*
 * User area virtual addresses
 */ 
E 22

	.globl	_u
	.set	_u,0x80000000 - UPAGES*NBPG
I 36
#define	vaddr(x)	((((x)-_Sysmap)/4)*NBPG+0x80000000)
#define	MAP(mname, vname, npte)			\
mname:	.globl	mname;				\
	.space	npte*4;				\
	.globl	_/**/vname;			\
	.set	_/**/vname,vaddr(mname)
E 36

E 37
	.data
I 7
	.align	2
I 41
#define	PJ	PUSHR;jsb _Xustray
E 41
E 7
D 36
	.globl	_Sysmap
_Sysmap:
D 2
	.space	4*NBPG
E 2
I 2
	.space	6*NBPG
E 2
UBA0map:
	.space	16*4
	.globl	_umbabeg
	.set	_umbabeg,((UBA0map-_Sysmap)/4)*512+0x80000000
UMEMmap:
	.space	16*4
I 22
#if VAX==780
E 22
D 12
MBA0map:
E 12
I 12
	.globl	_MBA0map
_MBA0map:
E 12
	.space	16*4
D 12
MBA1map:
E 12
I 12
	.globl	_MBA1map
_MBA1map:
E 12
	.space	16*4
I 22
#endif
E 22
umend:
	.globl	_umbaend
	.set	_umbaend,((umend-_Sysmap)/4)*512+0x80000000
E 36
I 36
D 37
MAP(	_Sysmap		,Sysbase	,6*NBPG/4	)
MAP(	UBA0map		,umabeg		,16		)
MAP(	UMEMmap		,__junk1	,16		)
MAP(	_Nexmap		,nexus		,16*16		)
MAP(	umend		,umbaend	,0		)
MAP(	_Usrptmap	,usrpt		,2*NBPG		)
MAP(	_Forkmap	,forkutl	,UPAGES		)
MAP(	_Xswapmap	,xswaputl	,UPAGES		)
MAP(	_Xswap2map	,xswap2utl	,UPAGES		)
MAP(	_Swapmap	,swaputl	,UPAGES		)
MAP(	_Pushmap	,pushutl	,UPAGES		)
MAP(	_Vfmap		,vfutl		,UPAGES		)
MAP(	CMAP1		,CADDR1		,1		)
MAP(	CMAP2		,CADDR2		,1		)
MAP(	_mcrmap		,mcr		,1		)
MAP(	_mmap		,vmmap		,1		)
MAP(	_bufmap		,buffers	,MAXNBUF*CLSIZE	)
MAP(	_msgbufmap	,msgbuf		,CLSIZE		)
MAP(	_camap		,cabase		,32*CLSIZE	)
MAP(	ecamap		,calimit	,0		)
E 37
I 37
	.globl	_catcher
_catcher:
D 41
	PUSHR
	jsb	_Xustray		# this (& PUSHR) make exactly 8 bytes
	.space	1016			# makes exactly 1 K bytes
E 41
I 41
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
E 41
E 37
E 36

I 42
D 44
	.data
E 44
	.globl	_cold
I 166
	.globl	_br
	.globl	_cvec
E 166
D 44
_cold:
	.long	1
E 44
I 44
_cold:	.long	1
I 166
_br:	.long	0
_cvec:	.long	0
E 166
D 49
	.globl	_cmap
_cmap:	.long	0
	.globl	_ecmap
_ecmap:	.long	0
E 49
	.data

E 44
E 42
D 36
	.globl	_Usrptmap
_Usrptmap:
	.space	8*NBPG
	.globl	_usrpt
	.set	_usrpt,((_Usrptmap-_Sysmap)/4)*NBPG+0x80000000

	.globl	_Forkmap
_Forkmap:
	.space	4*UPAGES
	.globl	_forkutl
	.set	_forkutl,((_Forkmap-_Sysmap)/4)*NBPG+0x80000000

	.globl	_Xswapmap
_Xswapmap:
	.space	4*UPAGES
	.globl	_xswaputl
	.set	_xswaputl,((_Xswapmap-_Sysmap)/4)*NBPG+0x80000000

	.globl	_Xswap2map
_Xswap2map:
	.space	4*UPAGES
	.globl	_xswap2utl
	.set	_xswap2utl,((_Xswap2map-_Sysmap)/4)*NBPG+0x80000000

	.globl	_Swapmap
_Swapmap:
	.space	4*UPAGES
	.globl	_swaputl
	.set	_swaputl,((_Swapmap-_Sysmap)/4)*NBPG+0x80000000

	.globl	_Pushmap
_Pushmap:
	.space	4*UPAGES
	.globl	_pushutl
	.set	_pushutl,((_Pushmap-_Sysmap)/4)*NBPG+0x80000000

	.globl	_Vfmap
_Vfmap:
	.space	4*UPAGES
	.globl	_vfutl
	.set	_vfutl,((_Vfmap-_Sysmap)/4)*NBPG+0x80000000

CMAP1:
	.space	4
	.set	CADDR1,((CMAP1-_Sysmap)/4)*NBPG+0x80000000
CMAP2:
	.space	4
	.set	CADDR2,((CMAP2-_Sysmap)/4)*NBPG+0x80000000

	.globl	_mcrmap
_mcrmap:
	.space	4
	.globl	_mcr
	.set	_mcr,((_mcrmap-_Sysmap)/4)*NBPG+0x80000000

	.globl	_mmap
_mmap:
	.space	4
	.globl	_vmmap
	.set	_vmmap,((_mmap-_Sysmap)/4)*NBPG+0x80000000

I 13
	.globl	_bufmap
_bufmap:
D 17
	.space	4*NBUF*CLSIZE
E 17
I 17
	.space	4*MAXNBUF*CLSIZE
E 17
	.globl	_buffers
	.set	_buffers,((_bufmap-_Sysmap)/4)*NBPG+0x80000000
D 34
	.globl	eSysmap
E 34
I 29
	.globl	_msgbufmap
_msgbufmap:
	.space	4*CLSIZE
	.globl	_msgbuf
	.set	_msgbuf,((_msgbufmap-_Sysmap)/4)*NBPG+0x80000000
I 34
	.globl	_camap
_camap:
	.globl	_cabase
	.set	_cabase,((_camap-_Sysmap)/4)*NBPG+0x80000000
	.space	4*32*CLSIZE
ecamap:
	.globl	_calimit
	.set	_calimit,((ecamap-_Sysmap)/4)*NBPG+0x80000000
	.globl	eSysmap
E 36
E 34
E 29
E 13
D 37
eSysmap:
D 36
	.set	Syssize,(eSysmap-_Sysmap)/4
E 36
I 36
	.set	_Syssize,(eSysmap-_Sysmap)/4
E 37
E 36
	.text
I 37
SCBVEC(ustray):
I 42
	blbc	_cold,1f
	mfpr	$IPL,r11
I 166
	movl	r11,_br
E 166
	subl3	$_catcher+8,(sp)+,r10
	ashl	$-1,r10,r10
I 166
	movl	r10,_cvec
E 166
	POPR
	rei
1:
E 42
D 41
	PUSHR
E 41
I 41
	subl3	$_catcher+8,(sp)+,r0
	ashl	$-1,r0,-(sp)
E 41
	mfpr	$IPL,-(sp)
D 40
	subl3	$_catcher,28(sp),-(sp)
E 40
I 40
D 41
	subl3	$_catcher,6*4+4(sp),-(sp)
E 40
	ashl	$-1,(sp),(sp)
D 40
	PRINTF(2, "Stray unibus interrupt (%x) (IPL %x)\n")
E 40
I 40
	PRINTF(2, "Stray unibus interrupt (%o) (IPL %x)\n")
E 41
I 41
D 51
	PRINTF(2, "STRAY UNIBUS INTR IPL %x VEC %o\n")
E 51
I 51
	PRINTF(2, "uba?: stray intr ipl %x vec %o\n")
E 51
E 41
E 40
	POPR
D 41
	tstl	(sp)+
E 41
D 38
	REI
E 38
I 38
	rei
E 38
E 37

I 147
D 163
#ifdef VAX630
E 163
I 163
D 169
#if VAX630 || VAX650
E 169
E 163
E 147
D 22
# ==============================
# Trap and fault vector routines
# ==============================
E 22
I 22
/*
I 147
D 169
 * Emulation OpCode jump table:
 *	ONLY GOES FROM 0xf8 (-8) TO 0x3B (59)
 */
#define EMUTABLE	0x43
#define NOEMULATE	.long noemulate
#define	EMULATE(a)	.long _EM/**/a
	.globl	_emJUMPtable
_emJUMPtable:
/* f8 */	EMULATE(ashp);	EMULATE(cvtlp);	NOEMULATE;	NOEMULATE
/* fc */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 00 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 04 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 08 */	EMULATE(cvtps);	EMULATE(cvtsp);	NOEMULATE;	EMULATE(crc)
/* 0c */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 10 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 14 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 18 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 1c */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 20 */	EMULATE(addp4);	EMULATE(addp6);	EMULATE(subp4);	EMULATE(subp6)
/* 24 */	EMULATE(cvtpt);	EMULATE(mulp);	EMULATE(cvttp);	EMULATE(divp)
/* 28 */	NOEMULATE;	EMULATE(cmpc3);	EMULATE(scanc);	EMULATE(spanc)
/* 2c */	NOEMULATE;	EMULATE(cmpc5);	EMULATE(movtc);	EMULATE(movtuc)
/* 30 */	NOEMULATE;	NOEMULATE;	NOEMULATE;	NOEMULATE
/* 34 */	EMULATE(movp);	EMULATE(cmpp3);	EMULATE(cvtpl);	EMULATE(cmpp4)
/* 38 */	EMULATE(editpc); EMULATE(matchc); EMULATE(locc); EMULATE(skpc)
#endif

/*
E 169
E 147
 * Trap and fault vector routines
 */ 
I 37
D 85
#define	TRAP(a)	pushl $a; brw alltraps
E 85
I 85
D 91
#define	TRAP(a)	pushl $a; jbr alltraps
E 91
I 91
#define	TRAP(a)	pushl $T_/**/a; jbr alltraps
E 91
E 85
E 37
E 22

D 22
#
# Reschedule trap (Software level 3 interrupt)
#
E 22
I 22
D 37
/*
 * Reschedule trap (Software level 3 interrupt)
E 37
I 37
D 38
/*					# CRUD
 * Reschedule trap (Software level 3)	# CRUD
 *					# CRUD
 * SHOULD DO THIS WITH AST'S.		# CRUD
E 38
I 38
/*
 * Ast delivery (profiling and/or reschedule)
E 38
E 37
 */
E 22
D 37
	.align	2
Xresched:
	mtpr	$0,$IPL			# lower ipl
	pushl	$0			# dummy code
	pushl	$RESCHED		# type
	bitl	$PSL_CURMOD,12(sp)
	bneq	alltraps
	addl2	$8,sp
	mtpr	$HIGH,$IPL
	rei
E 37
I 37
D 38
SCBVEC(resched):			# CRUD
	mtpr	$0,$IPL			# CRUD
	pushl	$0			# CRUD
	pushl	$RESCHED		# CRUD
	bitl	$PSL_CURMOD,12(sp)	# CRUD
	bneq	alltraps		# CRUD
	addl2	$8,sp			# CRUD
	mtpr	$HIGH,$IPL		# CRUD
	rei				# CRUD
E 37

E 38
I 38
SCBVEC(astflt):
	pushl $0; TRAP(ASTFLT)
I 170

E 170
E 38
D 22
#
# Privileged instruction fault
#
E 22
I 22
D 37
/*
 * Privileged instruction fault
 */
E 22
	.align	2
Xprivinflt:
	pushl	$0			# push dummy code
	pushl	$PRIVINFLT		# push type
	brw 	alltraps		# merge

D 22
#
# Xfc instruction fault
#
E 22
I 22
/*
 * Xfc instruction fault
 */
E 22
	.align	2
Xxfcflt:
	pushl	$0			# push dummy code value
	pushl	$XFCFLT			# push type value
	brw 	alltraps		# merge

D 22
#
# Reserved operand fault
#
E 22
I 22
/*
 * Reserved operand fault
 */
E 22
	.align	2
Xresopflt:
	pushl	$0			# push dummy code value
	pushl	$RESOPFLT		# push type value
	brw 	alltraps		# merge

D 22
#
# Reserved addressing mode fault
#
E 22
I 22
/*
 * Reserved addressing mode fault
 */
E 22
	.align	2
Xresadflt:
	pushl	$0			# push dummy code value
	pushl	$RESADFLT		# push type value
	brw 	alltraps		# merge with common code

D 22
#
# Bpt instruction fault
#
E 22
I 22
/*
 * Bpt instruction fault
 */
E 22
	.align	2
Xbptflt:
	pushl	$0			# push dummy code value
	pushl	$BPTFLT			# push type value
	brw 	alltraps		# merge with common code

D 22
#
# Compatibility mode fault
#
E 22
I 22
/*
 * Compatibility mode fault
 */
E 22
	.align	2
Xcompatflt:
	pushl	$COMPATFLT		# push type value
	brw 	alltraps		# merge with common code

D 22
#
# Trace trap
#
E 22
I 22
/*
 * Trace trap
 */
E 22
	.align	2
Xtracep:
	pushl	$0			# push dummy code value
	pushl	$TRCTRAP		# push type value
	brw 	alltraps		# go do it

D 22
#
# Arithmetic trap
#
E 22
I 22
/*
 * Arithmetic trap
 */
E 22
	.align	2
Xarithtrap:
	pushl	$ARITHTRAP		# push type value
	brw 	alltraps		# merge with common code

D 22
#
# Protection and segmentation fault
#
E 22
I 22
/*
 * Protection and segmentation fault
 */
E 22
	.align	2
Xprotflt:
	blbs	(sp),segflt		# check for pt length violation
	addl2	$4,sp			# pop fault param word 
	pushl	$PROTFLT
	brw 	alltraps

D 22
#
# Segmentation fault
#
E 22
I 22
/*
 * Segmentation fault
 */
E 37
I 37
SCBVEC(privinflt):
I 170
#if EMULFFLT || EMULDFLT || EMULGFLT || EMULHFLT
	jsb	_Resinstr_check_emul
#endif
E 170
	pushl $0; TRAP(PRIVINFLT)
I 170

E 170
SCBVEC(xfcflt):
	pushl $0; TRAP(XFCFLT)
SCBVEC(resopflt):
	pushl $0; TRAP(RESOPFLT)
SCBVEC(resadflt):
	pushl $0; TRAP(RESADFLT)
SCBVEC(bptflt):
	pushl $0; TRAP(BPTFLT)
SCBVEC(compatflt):
	TRAP(COMPATFLT);
I 153
SCBVEC(kdbintr):
D 160
	pushl $0; TRAP(KDBTRAP);
E 160
I 160
	pushl $0; TRAP(KDBTRAP)
E 160
E 153
SCBVEC(tracep):
	pushl $0; TRAP(TRCTRAP)
SCBVEC(arithtrap):
	TRAP(ARITHTRAP)
SCBVEC(protflt):
	blbs	(sp)+,segflt
	TRAP(PROTFLT)
E 37
E 22
segflt:
D 37
	addl2	$4,sp
	pushl	$SEGFLT
	brb 	alltraps

D 22
#
# Translation Not Valid Fault
#
E 22
I 22
/*
 * Translation Not Valid Fault
 */
E 22
	.align  2
Xtransflt:
	bbs	$1,(sp),tableflt	# check for page table fault
	addl2	$4,sp			# pop fault parameter word
	pushl	$PAGEFLT		# push type value
	brb	alltraps

D 22
#
# Page table fault
#
E 22
I 22
/*
 * Page table fault
 */
E 37
I 37
	TRAP(SEGFLT)
I 147

D 169
/*
 * The following is called with the stack set up as follows:
 *
 *	  (sp):	Opcode
 *	 4(sp):	Instruction PC
 *	 8(sp):	Operand 1
 *	12(sp):	Operand 2
 *	16(sp):	Operand 3
 *	20(sp):	Operand 4
 *	24(sp):	Operand 5
 *	28(sp):	Operand 6
 *	32(sp):	Operand 7 (unused)
 *	36(sp):	Operand 8 (unused)
 *	40(sp):	Return PC
 *	44(sp):	Return PSL
 *	48(sp): TOS before instruction
 *
 * Each individual routine is called with the stack set up as follows:
 *
 *	  (sp):	Return address of trap handler
 *	 4(sp):	Opcode (will get return PSL)
 *	 8(sp):	Instruction PC
 *	12(sp):	Operand 1
 *	16(sp):	Operand 2
 *	20(sp):	Operand 3
 *	24(sp):	Operand 4
 *	28(sp):	Operand 5
 *	32(sp):	Operand 6
 *	36(sp):	saved register 11
 *	40(sp):	saved register 10
 *	44(sp):	Return PC
 *	48(sp):	Return PSL
 *	52(sp): TOS before instruction
 */

SCBVEC(emulate):
D 163
#ifdef VAX630
E 163
I 163
#if VAX630 || VAX650
E 163
	movl	r11,32(sp)		# save register r11 in unused operand
	movl	r10,36(sp)		# save register r10 in unused operand
	cvtbl	(sp),r10		# get opcode
	addl2	$8,r10			# shift negative opcodes
	subl3	r10,$EMUTABLE,r11	# forget it if opcode is out of range
	bcs	noemulate
	movl	_emJUMPtable[r10],r10	# call appropriate emulation routine
	jsb	(r10)		# routines put return values into regs 0-5
	movl	32(sp),r11		# restore register r11
	movl	36(sp),r10		# restore register r10
	insv	(sp),$0,$4,44(sp)	# and condition codes in Opcode spot
	addl2	$40,sp			# adjust stack for return
	rei
noemulate:
	addl2	$48,sp			# adjust stack for
D 163
#endif VAX630
E 163
I 163
#endif
E 163
	.word	0xffff			# "reserved instruction fault"
SCBVEC(emulateFPD):
	.word	0xffff			# "reserved instruction fault"
E 169
E 147
SCBVEC(transflt):
D 69
	blbs	(sp)+,tableflt
E 69
I 69
D 70
	bbs	$1,(sp)+,tableflt
E 70
I 70
D 80
	bitl	$1,(sp)+
E 80
I 80
	bitl	$2,(sp)+
E 80
	bnequ	tableflt
I 99
D 114
	jsb	Fastreclaim		# try and avoid pagein
E 114
I 114
 	jsb	Fastreclaim		# try and avoid pagein
E 114
E 99
E 70
E 69
	TRAP(PAGEFLT)
E 37
E 22
tableflt: 
D 37
	addl2	$4,sp			# pop fault parameter word
	pushl	$TABLEFLT		# push type value
	brb	alltraps
E 37
I 37
	TRAP(TABLEFLT)
E 37

D 22
#
# all traps but syscalls...
#
E 22
I 22
D 37
/*
 * all traps but syscalls...
 */
E 37
E 22
alltraps:
D 37
	mfpr	$USP,-(sp)		# get usp
	calls	$0,_trap		# $0 so ret wont pop args
E 37
I 37
	mfpr	$USP,-(sp); calls $0,_trap; mtpr (sp)+,$USP
E 37
	incl	_cnt+V_TRAP
D 37
	mtpr	(sp)+,$USP		# restore usp
E 37
	addl2	$8,sp			# pop type, code
D 37
	mtpr	$HIGH,$IPL		# make sure we are not going to
					# a higher IPL
E 37
I 37
	mtpr	$HIGH,$IPL		## dont go to a higher IPL (GROT)
E 37
	rei

D 22
#
# CHMK trap (syscall trap)
#
# Kernel stack on entry:
#
#	code	<- ksp
#	pc
#	psl
#
#
# Stack (parameters) at calls to _trap or _syscall
#
#	usp	<- ksp
#	type
#	code
#	pc
#	psl
#
E 22
I 22
D 37
/*
 * CHMK trap (syscall trap)
 *
 * Kernel stack on entry:
 *
 *	code	<- ksp
 *	pc
 *	psl
 *
 *
 * Stack (parameters) at calls to _trap or _syscall
 *
 *	usp	<- ksp
 *	type
 *	code
 *	pc
 *	psl
 */
E 22

	.align	2
Xsyscall:
	pushl	$SYSCALL		# push type value
	mfpr	$USP,-(sp)		# get usp
	calls	$0,_syscall		# $0 so ret wont pop args
E 37
I 37
SCBVEC(syscall):
D 92
	pushl	$SYSCALL
E 92
I 92
	pushl	$T_SYSCALL
E 92
	mfpr	$USP,-(sp); calls $0,_syscall; mtpr (sp)+,$USP
E 37
	incl	_cnt+V_SYSCALL
D 37
	mtpr	(sp)+,$USP		# restore usp
E 37
	addl2	$8,sp			# pop type, code
D 37
	mtpr	$HIGH,$IPL		# make sure we are not going to
					# a higher IPL
E 37
I 37
	mtpr	$HIGH,$IPL		## dont go to a higher IPL (GROT)
E 37
	rei

D 22
# ==============
# Initialization
# ==============
#
#	IPL == 1F
#	MAPEN == off
#	SCBB, PCBB not set
#	SBR, SLR not set
#	ISP, KSP not set
#
E 22
I 22
/*
I 37
 * System page table
I 140
 * Mbmap and Usrptmap are enlarged by CLSIZE entries
 * as they are managed by resource maps starting with index 1 or CLSIZE.
E 140
 */ 
#define	vaddr(x)	((((x)-_Sysmap)/4)*NBPG+0x80000000)
#define	SYSMAP(mname, vname, npte)			\
_/**/mname:	.globl	_/**/mname;		\
D 140
	.space	npte*4;				\
E 140
I 140
	.space	(npte)*4;				\
E 140
	.globl	_/**/vname;			\
	.set	_/**/vname,vaddr(_/**/mname)

	.data
	.align	2
D 49
	SYSMAP(Sysmap	,Sysbase	,6*NBPG/4	)
E 49
I 49
D 50
	SYSMAP(Sysmap	,Sysbase	,SYSPTSIZE/4	)
E 50
I 50
	SYSMAP(Sysmap	,Sysbase	,SYSPTSIZE	)
E 50
E 49
D 140
	SYSMAP(UMBAbeg	,umbabeg	,0		)
D 49
	SYSMAP(Nexmap	,nexus		,16*16		)
	SYSMAP(UMEMmap	,umem		,16*4		)
E 49
I 49
D 56
	SYSMAP(Nexmap	,nexus		,16*NNEXUS	)
E 56
I 56
	SYSMAP(Nexmap	,nexus		,16*MAXNNEXUS	)
E 56
D 83
	SYSMAP(UMEMmap	,umem		,16*MAXNUBA	)
E 83
I 83
D 115
	SYSMAP(UMEMmap	,umem		,512*MAXNUBA	)
E 115
I 115
D 139
	SYSMAP(UMEMmap	,umem		,512*NUBA	)
E 139
I 139
	SYSMAP(UMEMmap	,umem		,UBAPAGES*NUBA	)
	SYSMAP(Ioamap	,ioa		,MAXNIOA*IOAMAPSIZ/NBPG	)
E 139
E 115
E 83
E 49
	SYSMAP(UMBAend	,umbaend	,0		)
D 49
	SYSMAP(Usrptmap	,usrpt		,2*NBPG		)
E 49
I 49
D 50
	SYSMAP(Usrptmap	,usrpt		,USRPTSIZE/4	)
E 50
I 50
	SYSMAP(Usrptmap	,usrpt		,USRPTSIZE	)
E 140
E 50
E 49
	SYSMAP(Forkmap	,forkutl	,UPAGES		)
	SYSMAP(Xswapmap	,xswaputl	,UPAGES		)
	SYSMAP(Xswap2map,xswap2utl	,UPAGES		)
	SYSMAP(Swapmap	,swaputl	,UPAGES		)
	SYSMAP(Pushmap	,pushutl	,UPAGES		)
	SYSMAP(Vfmap	,vfutl		,UPAGES		)
	SYSMAP(CMAP1	,CADDR1		,1		)
	SYSMAP(CMAP2	,CADDR2		,1		)
D 140
	SYSMAP(mcrmap	,mcr		,1		)
E 140
	SYSMAP(mmap	,vmmap		,1		)
I 140
	SYSMAP(alignmap	,alignutl	,1		)	/* XXX */
E 140
D 49
	SYSMAP(bufmap	,buffers	,MAXNBUF*CLSIZE	)
E 49
D 74
	SYSMAP(msgbufmap,msgbuf		,CLSIZE		)
E 74
I 74
	SYSMAP(msgbufmap,msgbuf		,MSGBUFPTECNT	)
I 140
	SYSMAP(Mbmap	,mbutl		,NMBCLUSTERS*CLSIZE+CLSIZE )
E 140
E 74
D 49
	SYSMAP(camap	,cabase		,32*CLSIZE	)
E 49
I 49
D 156
	SYSMAP(camap	,cabase		,16*CLSIZE	)
E 156
I 156
D 159
	SYSMAP(kmempt	,kmembase	,100*CLSIZE	)
E 159
I 159
	SYSMAP(kmempt	,kmembase	,200*CLSIZE	)
E 159
E 156
I 120
#ifdef	GPROF
	SYSMAP(profmap	,profbase	,600*CLSIZE	)
#endif
I 171
	SYSMAP(vmbinfomap,vmb_info	,128		)
E 171
E 120
E 49
D 156
	SYSMAP(ecamap	,calimit	,0		)
E 156
I 156
	SYSMAP(ekmempt	,kmemlimit	,0		)
E 156
I 65
D 75
#ifdef BBNNET
	SYSMAP(Netmap	,netutl		,NNETPAGES*CLSIZE)
#endif
E 75
I 75
D 77
	SYSMAP(Mbmap	,mbutl		,NMBPAGES*CLSIZE)
E 77
I 77
D 140
	SYSMAP(Mbmap	,mbutl		,NMBCLUSTERS*CLSIZE)
E 140
I 140

	SYSMAP(UMBAbeg	,umbabeg	,0		)
	SYSMAP(Nexmap	,nexus		,16*MAXNNEXUS	)
I 164
#ifdef QBA
#if (QBAPAGES+UBAIOPAGES) > (UBAPAGES+UBAIOPAGES)*NUBA 
	SYSMAP(UMEMmap	,umem		,(QBAPAGES+UBAIOPAGES) )
#else
E 164
D 152
	SYSMAP(UMEMmap	,umem		,UBAPAGES*NUBA	)
E 152
I 152
D 160
	SYSMAP(UMEMmap	,umem		,(UBAPAGES+UBAIOPAGES)*NUBA	)
E 160
I 160
	SYSMAP(UMEMmap	,umem		,(UBAPAGES+UBAIOPAGES)*NUBA )
I 164
#endif
#else /* QBA */
	SYSMAP(UMEMmap	,umem		,(QBAPAGES+UBAIOPAGES)*NUBA )
#endif /* QBA */
E 164
E 160
#if VAX8600
E 152
	SYSMAP(Ioamap	,ioa		,MAXNIOA*IOAMAPSIZ/NBPG	)
D 152
	SYSMAP(UMBAend	,umbaend	,0		)
E 152
I 152
#endif
I 160
#if VAX8200 || VAX630
	SYSMAP(Clockmap	,ka630clock	,1		)
#endif
#if VAX8200
	/* alas, the clocks on the 8200 and 630 are not quite identical */
	/* they could be shared for now, but this seemed cleaner */
	.globl _ka820clock; .set _ka820clock,_ka630clock
	SYSMAP(Ka820map	,ka820port	,1		)
	SYSMAP(RX50map	,rx50device	,1		)
#ifdef notyet
	SYSMAP(BRAMmap	,ka820bootram	,KA820_BRPAGES	)
	SYSMAP(EEPROMmap,ka820eeprom	,KA820_EEPAGES	)
#endif
#endif
E 160
E 152
I 147
#if VAX630
D 160
	SYSMAP(Clockmap	,cldevice	,1		)
E 160
	SYSMAP(Ka630map	,ka630cpu	,1		)
I 163
#endif
#if VAX650
D 172
 	SYSMAP(KA650MERRmap	,ka650merr	,1		)
 	SYSMAP(KA650CBDmap	,ka650cbd	,1		)
 	SYSMAP(KA650SSCmap	,ka650ssc	,3		)
 	SYSMAP(KA650IPCRmap	,ka650ipcr	,1		)
 	SYSMAP(KA650CACHEmap	,ka650cache	,KA650_CACHESIZE/NBPG )
E 172
I 172
	SYSMAP(KA650MERRmap	,ka650merr	,1		)
	SYSMAP(KA650SSCmap	,ka650ssc	,3		)
	SYSMAP(KA650IPCRmap	,ka650ipcr	,1		)
#endif
#if VAX650 || VAX3100
	/*
	 * XXX This is a kludge - using KA650 structures for a different CPU
	 * But KA42's L2 cache is close enough to the 650's
	 */
	SYSMAP(KA650CBDmap	,ka650cbd	,1		)
	SYSMAP(KA650CACHEmap	,ka650cache	,KA650_CACHESIZE/NBPG )
E 172
#endif
I 171
#if NEED_BABYVAX_SUPPORT
	SYSMAP(Babyvaxmap,bv_regs	,8		)
#endif
E 171
#ifdef QBA
E 163
I 157
D 160
	/* 
	 * qvss and qdss can't coexist - one map will suffice 
E 160
I 160
	/*
D 164
	 * qvss and qdss can't coexist - one map will suffice
E 164
I 164
	 * qvss and qdss don't coexist - one map will suffice
E 164
E 160
	 * for either. qvss is 256K each and qdss is 64K each.
	 */
E 157
I 152
#include "qv.h"
D 157
#if NQV > 0
	SYSMAP(QVmap	,qvmem		,512*NQV	)
E 152
#endif
I 152
#endif
E 157
I 157
#include "qd.h"
D 160
#if NQV > 0 || NQD > 0	
E 160
I 160
#if NQV > 0 || NQD > 0
E 160
	SYSMAP(QVmap	,qvmem		,((512*NQV)+(128*NQD)))
D 163
#endif /* NQV || NQD */
#endif /* VAX630 */
E 163
I 163
#endif
#endif
E 163
E 157
	SYSMAP(UMBAend	,umbaend	,0		)
E 152
E 147

	SYSMAP(Usrptmap	,usrpt		,USRPTSIZE+CLSIZE )
E 140
E 77
E 75
E 65

eSysmap:
I 67
	.globl	_Syssize
E 67
	.set	_Syssize,(eSysmap-_Sysmap)/4
	.text

/*
E 37
 * Initialization
 *
D 37
 *	IPL == 1F
 *	MAPEN == off
 *	SCBB, PCBB not set
 *	SBR, SLR not set
 *	ISP, KSP not set
E 37
I 37
 * ipl 0x1f; mapen 0; scbb, pcbb, sbr, slr, isp, ksp not set
I 171
 *
 * We are called as a procedure with 0 or 1 arguments.
 * The optional argument is a pointer to vmb_info for the VMB boot path.
 * This argument may be 0, which is equivalent to not passing it at all.
E 171
E 37
 */
I 48
	.data
	.globl	_cpu
_cpu:	.long	0
I 168
	.globl	_cpusid
_cpusid: .long	0
	.globl	_cpusie
_cpusie: .long	0
E 168
	.text
E 48
E 22
	.globl	start
start:
D 37
	.word	0x0000
D 22
	mtpr	$HIGH,$IPL		# no interrupts yet
	mtpr	$Scbbase,$SCBB		# set SCBB
	mtpr	$_Sysmap,$SBR		# set SBR
	mtpr	$Syssize,$SLR		# set SLR
	mtpr	$_Sysmap,$P0BR		# set temp P0BR
	mtpr	$Syssize,$P0LR		# set temp P0LR
	movl	$_intstack+2048,sp	# set ISP
#
# Initialize I/O adapters.
#
D 12
	movl	$1,PHYSMBA0+4		# init & interrupt enable
	movl	$4,PHYSMBA0+4		# init & interrupt enable
	movl	$1,PHYSMBA1+4		# init & interrupt enable
	movl	$4,PHYSMBA1+4		# init & interrupt enable
E 12
	movl	$1,PHYSUBA+4		# init & interrupt enable
	movl	$0x78,PHYSUBA+4		# init & interrupt enable
E 22
I 22
	mtpr	$HIGH,$IPL			## no interrupts yet
D 36
	mtpr	$Scbbase-0x80000000,$SCBB	# set SCBB
E 36
I 36
	mtpr	$_Scbbase-0x80000000,$SCBB	# set SCBB
E 36
	mtpr	$_Sysmap-0x80000000,$SBR	## set SBR
D 36
	mtpr	$Syssize,$SLR			## set SLR
E 36
I 36
	mtpr	$_Syssize,$SLR			## set SLR
E 36
	mtpr	$_Sysmap,$P0BR			## set temp P0BR
D 36
	mtpr	$Syssize,$P0LR			## set temp P0LR
E 36
I 36
	mtpr	$_Syssize,$P0LR			## set temp P0LR
E 37
I 37
	.word	0
I 139
D 171
	mtpr	$0,$ICCS
E 171
I 171
	tstl	(ap)			# arg present?
	beql	1f			# if not, skip ahead
	movl	4(ap),_vmbinfo		# otherwise, save the address passed
1:	mtpr	$0,$ICCS
E 171
E 139
I 50
/* set system control block base and system page table params */
E 50
	mtpr	$_scb-0x80000000,$SCBB
D 50
	mtpr	$_Sysmap-0x80000000,$SBR	## GROT ??
	mtpr	$_Syssize,$SLR			## GROT ??
	mtpr	$_Sysmap,$P0BR			## GROT ??
	mtpr	$_Syssize,$P0LR			## GROT ??
E 37
E 36
D 40
	movl	$_intstack+2048,sp		# set ISP
E 40
I 40
	movl	$_intstack+NISP*NBPG,sp		# set ISP
E 50
I 50
	mtpr	$_Sysmap-0x80000000,$SBR
	mtpr	$_Syssize,$SLR
/* double map the kernel into the virtual user addresses of phys mem */
	mtpr	$_Sysmap,$P0BR
	mtpr	$_Syssize,$P0LR
/* set ISP and get cpu type */
	movl	$_intstack+NISP*NBPG,sp
E 50
I 47
D 168
	mfpr	$SID,r0
D 48
	extzv	$24,$8,r0,_cpu
E 48
I 48
	movab	_cpu,r1
	extzv	$24,$8,r0,(r1)
E 168
I 168
	calls	$0,_cpuid
E 168
E 48
E 47
E 40
I 34
D 37
/*
 * Initialize RPB
 */
E 37
I 37
/* init RPB */
E 37
	movab	_rpb,r0
	movl	r0,(r0)+			# rp_selfref
	movab	_doadump,r1
	movl	r1,(r0)+			# rp_dumprout
	movl	$0x1f,r2
	clrl	r3
D 37
1:
	addl2	(r1)+,r3
	sobgtr	r2,1b
E 37
I 37
1:	addl2	(r1)+,r3; sobgtr r2,1b
E 37
	movl	r3,(r0)+			# rp_chksum
D 37

E 34
#if VAX==780
/*
 * Initialize UBA
 */
D 29
	movl	$1,PHYSUBA+4		# init
E 29
	movl	$0x78,PHYSUBA+4		# ienable
#endif
E 22

D 33
	movl	Scbbase+MCKVEC,r5	# save machine check entry
D 11
	movab	startint+INTSTK,Scbbase+MCKVEC	# set new vector address
E 11
I 11
	movab	2f+INTSTK,Scbbase+MCKVEC	# set new vector address
E 33
E 11
D 22
#
# Will now see how much memory there really is
# in 64kb chunks.  Save number of bytes in r7.
#
E 22
I 22
/*
 * Will now see how much memory there really is
 * in 64kb chunks.  Save number of bytes in r7.
 */
E 37
I 37
D 171
/* count up memory */
E 37
E 22
D 33
	mtpr	$HIGH-1,$IPL		# allow machine check interrupts
	clrl	r7
E 33
I 33
D 34
	clrl	r1
E 34
I 34
	clrl	r7
E 34
E 33
D 11
startlp:
E 11
I 11
D 37
1:
E 11
D 33
	tstl	(r7)			# this chunk really there?
D 11
	acbl	$8096*1024-1,$64*1024,r7,startlp	# loop till mach check
	brb 	startint		# full load of memory
E 11
I 11
	acbl	$8096*1024-1,$64*1024,r7,1b	# loop till mach check
	brb 	2f			# full load of memory
E 33
I 33
D 34
	jsb	chkadr			# does this addr exist ?
	beql	1f
	acbl	$8096*1024-1,$64*1024,r1,1b
E 33
E 11

E 34
I 34
	pushl	$4		# test long word access
	pushl	r7		# to (r7)
	calls	$2,_badaddr
	tstl	r0
	bneq	1f
E 37
I 37
1:	pushl	$4; pushl r7; calls $2,_badaddr; tstl r0; bneq 9f
E 171
I 171
/*
 * Did we boot in the traditional BSD way?  If we did, count up memory.
 * But if we booted via VMB, take physmem from the vmb_info structure and
 * set maxmem to protect it.
 *
 * Note that counting up memory may not work on all machines and VMB booting
 * may be required for some.  On the KA410 BabyVAX, for example, the cheap
 * hardware (standard cell) has no NXM indication at all (!).
 */
	movl	_vmbinfo,r8
	beql	1f
	movl	INFO_MEMSIZ(r8),r7
	jbr	9f
1:	clrl	r7
1:	pushl	$4; pushl r7; calls $2,_badaddr; tstl r0; bneq 2f
E 171
E 37
D 78
	acbl	$8096*1024-1,$64*1024,r7,1b
E 78
I 78
D 114
	acbl	$8192*1024-1,$64*1024,r7,1b
E 114
I 114
	acbl	$MAXMEM*1024-1,$64*1024,r7,1b
E 114
E 78
E 34
D 33
	.align	2
D 11
startint:
E 11
I 11
2:
I 22
#if VAX==780
E 22
E 11
	mtpr	$0,$SBIFS		# clear sbi fault status
I 22
#endif
E 22
	movl	r5,Scbbase+MCKVEC	# restore machine check vector
	movl	$_intstack+2048,sp	# reset interrupt stack pointer
E 33
I 33
D 37
1:
D 34
	movl	r1,r7			# save addr end of mem
E 34
I 34

E 34
E 33
D 22
#
# calculate size of cmap[] based on available memory, and allocate space for it
#
E 22
I 22
/*
D 34
 * calculate size of cmap[] based on available memory, and allocate space for it
E 34
I 34
 * calculate size of cmap[] based on available memory,
 * and allocate space for it
E 34
 */
E 37
I 37
D 171
9:
E 171
I 171
2:	movl	r7,r8
E 171
I 150
D 163
#ifdef  VAX630
/* leave an area for uVAX II console scratch pad at the top */
E 163
I 163
#if  VAX630 || VAX650
D 165
/* leave an area for uVAX console scratch pad at the top */
E 165
I 165
/* reserved area at top of memory for processor specific use */
E 165
E 163
	cmpb	_cpu,$VAX_630
D 163
	bneq	1f
	subl2   $4096,r7
E 163
I 163
	beql	1f
	cmpb	_cpu,$VAX_650
D 171
	bneq	2f
E 171
I 171
	bneq	9f
E 171
I 165
	subl2	$32768,r7	# space for Qbus map registers
D 171
	brb	2f
E 171
I 171
	brb	9f
E 171
E 165
E 163
1:
I 163
D 165
	subl2   $4096,r7
E 165
I 165
D 171
	subl2   $4096,r7	# space for console scratchpad
E 165
2:
E 171
I 171
	subl2   $4096,r8	# space for console scratchpad
E 171
E 163
#endif
I 171
9:
E 171
E 150
D 49
/* allocate space for cmap[] */
E 37
E 22
	movab	_end,r5
D 37
	movl	r5,_cmap
D 11
	bbss	$31,_cmap,cm0
cm0:
E 11
I 11
	bbss	$31,_cmap,0f; 0:
E 37
I 37
	movl	r5,_cmap; bbss $31,_cmap,0f; 0:
E 37
E 11
	subl3	r5,r7,r1
	divl2	$(NBPG*CLSIZE)+CMSIZE,r1
	mull2	$CMSIZE,r1
	addl3	_cmap,r1,_ecmap
E 49
D 22
#
# Clear memory starting with kernel bss, and extra pages for
# proc 0 u. and proc 0 paget.
#
E 22
I 22
D 37
/*
 * Clear memory starting with kernel bss, and extra pages for
 * proc 0 u. and proc 0 paget.
 */
E 37
I 37
/* clear memory from kernel bss and pages for proc 0 u. and page table */
E 37
E 22
D 153
	movab	_edata,r6
D 10
	movab	_ecmap,r5		# clear to end of cmap[]
E 10
I 10
D 49
	movl	_ecmap,r5		# clear to end of cmap[]
E 49
I 49
	movab	_end,r5
E 49
D 11
	bbcc	$31,r5,strtclr0
strtclr0:
E 11
I 11
	bbcc	$31,r5,0f; 0:
E 153
I 153
	movab	_edata,r6; bicl2 $SYSTEM,r6
	movab	_end,r5; bicl2 $SYSTEM,r5
D 160
#ifdef KDB
E 160
I 160
#ifdef KADB
E 160
	subl2	$4,r5
1:	clrl	(r6); acbl r5,$4,r6,1b		# clear just bss
	addl2	$4,r5
	bbc	$6,r11,0f			# check RB_KDB
	bicl3	$SYSTEM,r9,r5			# skip symbol & string tables
D 162
	bicl3	$SYSTEM,r9,r6
E 162
I 162
	bicl3	$SYSTEM,r9,r6			# r9 obtained from boot
E 162
#endif
0:	bisl3	$SYSTEM,r5,r9			# convert to virtual address
	addl2	$NBPG-1,r9			# roundup to next page
E 153
E 11
E 10
	addl2	$(UPAGES*NBPG)+NBPG+NBPG,r5
D 11
strtclr:
E 11
I 11
D 37
1:
E 11
	clrq	(r6)
D 11
	acbl	r5,$8,r6,strtclr
E 11
I 11
	acbl	r5,$8,r6,1b
E 11

D 22
#
# Finagle _trap and _syscall to save r0-r11 so
# that it won't be necessary to pushr/popr what
# the (already time consuming) calls is prepared to do.
# The fact that this is done is well known (e.g. in the definition
# of the stack offsets of the registers in ../h/reg.h)
# 
E 22
I 22
/*
 * Finagle _trap and _syscall to save r0-r11 so
 * that it won't be necessary to pushr/popr what
 * the (already time consuming) calls is prepared to do.
 * The fact that this is done is well known (e.g. in the definition
 * of the stack offsets of the registers in ../h/reg.h)
 */ 
E 22
	bisw2	$0x0fff,_trap		# so _trap saves r0-r11
	bisw2	$0x0fff,_syscall	# so _syscall saves r0-r11

D 22
#
# Initialize system page table
#
E 22
I 22
/*
 * Initialize system page table
I 36
 *
 * First part (scb, unibus vectors and interrupt stack)
 * is r/w except for the rpb, which sits above the interrupt
 * stack acting as a red zone.  Then comes the kernel text
 * which is read only, and then the r/w kernel data.
 * (The scb and the unibus vector they are made read only after
 * they are filled in by the configuration code.)
E 36
 */
E 37
I 37
1:	clrq	(r6); acbl r5,$8,r6,1b
/* trap() and syscall() save r0-r11 in the entry mask (per ../h/reg.h) */
I 141
/* panic() is convenient place to save all for debugging */
E 141
	bisw2	$0x0fff,_trap
	bisw2	$0x0fff,_syscall
I 141
	bisw2	$0x0fff,_panic
E 141
I 39
	calls	$0,_fixctlrmask
E 39
D 133
/* initialize system page table: scb and int stack writeable */
E 133
I 133
/* initialize system page table: uba vectors and int stack writeable */
E 133
E 37
I 36
	clrl	r2
D 37
	movab	eintstack,r1
	bbcc	$31,r1,0f; 0:
	ashl	$-9,r1,r1
1:
	bisl3	$PG_V|PG_KW,r2,_Sysmap[r2]	# fill data entries
	aoblss	r1,r2,1b
E 37
I 37
	movab	eintstack,r1; bbcc $31,r1,0f; 0: ashl $-PGSHIFT,r1,r1
1:	bisl3	$PG_V|PG_KW,r2,_Sysmap[r2]; aoblss r1,r2,1b
D 133
/* make rpb read-only as red zone for interrupt stack */
E 133
I 133
D 160
/* make rpb, scb read-only as red zone for interrupt stack */
E 160
I 160
/*
 * make rpb read-only as red zone for interrupt stack
 * (scb(s) and UNIvec are write-protected later)
 */
E 160
E 133
E 37
	bicl2	$PG_PROT,_rpbmap
	bisl2	$PG_KR,_rpbmap
E 36
E 22
D 37
	movab	_etext+NBPG-1,r1	# end of kernel text segment
D 11
	bbcc	$31,r1,strt1		# turn off high order bit
strt1:
E 11
I 11
	bbcc	$31,r1,0f; 0:		# turn off high order bit
E 11
	ashl	$-9,r1,r1		# last page of kernel text
D 34
	clrl	r2			# point at first kernel text page
E 34
I 34
D 36
	clrl	r2
E 36
E 34
D 11
strtlp1:
E 11
I 11
1:
E 11
	bisl3	$PG_V|PG_KR,r2,_Sysmap[r2]	# initialize page table entry
D 11
	aoblss	r1,r2,strtlp1		# fill text entries
E 11
I 11
	aoblss	r1,r2,1b		# fill text entries
E 11
	addl3	_ecmap,$NBPG-1,r1	# end of cmap[]
D 11
	bbcc	$31,r1,strt2		# turn off high order bit
strt2:
E 11
I 11
	bbcc	$31,r1,0f; 0:		# turn off high order bit
E 11
	ashl	$-9,r1,r1		# last page of kernel data
D 11
strtlp2:
E 11
I 11
1:
E 11
	bisl3	$PG_V|PG_KW,r2,_Sysmap[r2]	# fill data entries
D 11
	aoblss	r1,r2,strtlp2
E 11
I 11
	aoblss	r1,r2,1b
E 11
D 22
#
# initialize memory controller mapping
#
E 22
I 22
/*
 * initialize memory controller mapping
 */
E 22
	movl	$PHYSMCR/NBPG,r1
	movab	_mcrmap,r2
	bisl3	$PG_V|PG_KW,r1,(r2)
D 22
#
D 13
# Initialize I/O space page table entries
E 13
I 13
# Initialize UNIBUS page table entries
E 13
#
E 22
I 22
/*
 * Initialize UNIBUS page table entries
 */
E 22
	movl	$PHYSUBA/NBPG,r1	# page frame number for uba
	movab	UBA0map,r2		# page table address
	movab	15(r1),r3		# last pt entry
D 11
strtlp3:
E 11
I 11
1:
E 11
	bisl3	$PG_V|PG_KW,r1,(r2)+	# init pt entry
D 11
	aobleq	r3,r1,strtlp3
E 11
I 11
	aobleq	r3,r1,1b
E 11
	movl	$PHYSUMEM/NBPG,r1
	movab	UMEMmap,r2		# page table address
	movab	15(r1),r3		# limit
D 11
strtlp4:
E 11
I 11
1:
E 11
	bisl3	$PG_V|PG_KW,r1,(r2)+
D 11
	aobleq	r3,r1,strtlp4
E 11
I 11
	aobleq	r3,r1,1b
E 11
D 12
	movl	$PHYSMBA0/NBPG,r1
	movab	MBA0map,r2
	movab	15(r1),r3
D 11
strtlp5:
E 11
I 11
1:
E 11
	bisl3	$PG_V|PG_KW,r1,(r2)+
D 11
	aobleq	r3,r1,strtlp5
E 11
I 11
	aobleq	r3,r1,1b
E 11
	movl	$PHYSMBA1/NBPG,r1
	movab	MBA1map,r2
	movab	15(r1),r3
D 11
strtlp6:
E 11
I 11
1:
E 11
	bisl3	$PG_V|PG_KW,r1,(r2)+
D 11
	aobleq	r3,r1,strtlp6
E 11
I 11
	aobleq	r3,r1,1b
E 11

E 12
	mtpr	$1,$TBIA		# invalidate all trans buffer entries
	mtpr	$1,$MAPEN		# turn on memory mapping
D 11
	jmp 	*$startmap		# put system virtual address in pc
E 11
I 11
	jmp 	*$0f			# put system virtual address in pc
E 11
D 22
#
# Now we move forward, virtually.
#
E 22
I 22
/*
 * Now we move forward, virtually.
 */
E 22
D 11
startmap:
E 11
I 11
0:
E 11
	ashl	$-9,r7,_maxmem		# set maxmem = btoc(r7)
E 37
I 37
/* make kernel text space read-only */
	movab	_etext+NBPG-1,r1; bbcc $31,r1,0f; 0: ashl $-PGSHIFT,r1,r1
D 147
1:	bisl3	$PG_V|PG_KR,r2,_Sysmap[r2]; aoblss r1,r2,1b
E 147
I 147
1:	bisl3	$PG_V|PG_URKR,r2,_Sysmap[r2]; aoblss r1,r2,1b
E 147
D 49
/* make kernel data, bss, core map read-write */
	addl3	_ecmap,$NBPG-1,r1; bbcc	$31,r1,0f; 0:; ashl $-PGSHIFT,r1,r1
E 49
I 49
D 50
/* make kernel data, bss */
	movab	_end+NBPG-1,r1; bbcc	$31,r1,0f; 0:; ashl $-PGSHIFT,r1,r1
E 50
I 50
/* make kernel data, bss, read-write */
D 153
	movab	_end+NBPG-1,r1; bbcc $31,r1,0f; 0:; ashl $-PGSHIFT,r1,r1
E 153
I 153
	bicl3	$SYSTEM,r9,r1; ashl $-PGSHIFT,r1,r1
E 153
E 50
E 49
1:	bisl3	$PG_V|PG_KW,r2,_Sysmap[r2]; aoblss r1,r2,1b
/* now go to mapped mode */
D 137
	mtpr	$1,$TBIA; mtpr $1,$MAPEN; jmp *$0f; 0:
E 137
I 137
	mtpr	$0,$TBIA; mtpr $1,$MAPEN; jmp *$0f; 0:
E 137
/* init mem sizes */
D 171
	ashl	$-PGSHIFT,r7,_maxmem
E 37
	movl	_maxmem,_physmem
E 171
I 171
	ashl	$-PGSHIFT,r7,_physmem
	ashl	$-PGSHIFT,r8,_maxmem
E 171
	movl	_maxmem,_freemem
D 37

D 22
#
# Setup context for proc[0] == Scheduler
#
# First page: paget for proc[0]
# Next UPAGES: _u for proc[0]
# Initialize (slightly) the pcb.
#
E 22
I 22
/*
 * Setup context for proc[0] == Scheduler
 *
 * First page: paget for proc[0]
 * Next UPAGES: _u for proc[0]
 * Initialize (slightly) the pcb.
 */
E 37
I 37
/* setup context for proc[0] == Scheduler */
E 37
E 22
D 49
	addl3	_ecmap,$NBPG-1,r6
E 49
I 49
D 153
	movab	_end+NBPG-1,r6
E 153
I 153
D 160
	bicl3	$SYSTEM,r9,r6
E 153
E 49
	bicl2	$NBPG-1,r6		# make page boundary
E 160
I 160
	bicl3	$SYSTEM|(NBPG-1),r9,r6	# make phys, page boundary
E 160
D 22
#
# set up u area page table
#
E 22
I 22
D 37
/*
 * set up u area page table
 */
E 37
I 37
/* setup page table for proc[0] */
E 37
E 22
D 11
	bbcc	$31,r6,strt3
strt3:
E 11
I 11
D 153
	bbcc	$31,r6,0f; 0:
E 153
E 11
D 37
	ashl	$-9,r6,r3			# r3 = btoc(r6)
E 37
I 37
	ashl	$-PGSHIFT,r6,r3			# r3 = btoc(r6)
E 37
	bisl3	$PG_V|PG_KW,r3,_Usrptmap	# init first upt entry
I 40
	incl	r3
E 40
	movab	_usrpt,r0
	mtpr	r0,$TBIS
I 37
/* init p0br, p0lr */
E 37
	mtpr	r0,$P0BR
	mtpr	$0,$P0LR
I 37
/* init p1br, p1lr */
E 37
	movab	NBPG(r0),r0
	movl	$0x200000-UPAGES,r1
	mtpr	r1,$P1LR
	mnegl	r1,r1
	moval	-4*UPAGES(r0)[r1],r2
	mtpr	r2,$P1BR
D 37
	movl	$UPAGES,r2
	movab	_u+NBPG*UPAGES,r1
D 11
	jbr	strt3b
strt3a:
E 11
I 11
	jbr	2f
1:
E 11
	incl	r3
	moval	-NBPG(r1),r1
E 37
I 37
/* setup mapping for UPAGES of _u */
D 40
	movl	$UPAGES,r2; movab _u+NBPG*UPAGES,r1; jbr 2f
1:	incl	r3
E 40
I 40
	movl	$UPAGES,r2; movab _u+NBPG*UPAGES,r1; addl2 $UPAGES,r3; jbr 2f
1:	decl	r3
E 40
	moval	-NBPG(r1),r1;
E 37
	bisl3	$PG_V|PG_URKW,r3,-(r0)
	mtpr	r1,$TBIS
D 11
strt3b:
	sobgeq	r2,strt3a
E 11
I 11
D 37
2:
	sobgeq	r2,1b
E 11

	movab	UPAGES*NBPG(r1),PCB_KSP(r1)	# init ksp
	mnegl	$1,PCB_ESP(r1)			# invalidate esp
	mnegl	$1,PCB_SSP(r1)			# invalidate ssp
	movl	r1,PCB_USP(r1)			# set user sp
E 37
I 37
D 40
2:	sobgeq r2,1b
E 40
I 40
2:	sobgeq	r2,1b
E 40
/* initialize (slightly) the pcb */
	movab	UPAGES*NBPG(r1),PCB_KSP(r1)
	mnegl	$1,PCB_ESP(r1)
	mnegl	$1,PCB_SSP(r1)
	movl	r1,PCB_USP(r1)
E 37
	mfpr	$P0BR,PCB_P0BR(r1)
	mfpr	$P0LR,PCB_P0LR(r1)
	movb	$4,PCB_P0LR+3(r1)		# disable ast
	mfpr	$P1BR,PCB_P1BR(r1)
	mfpr	$P1LR,PCB_P1LR(r1)
	movl	$CLSIZE,PCB_SZPT(r1)		# init u.u_pcb.pcb_szpt
I 153
D 162
	movl	r9,PCB_R9(r1)			# r9 obtained from boot
E 162
I 162
	movl	r9,PCB_R9(r1)
E 162
E 153
I 146
	movl	r10,PCB_R10(r1)
E 146
I 15
	movl	r11,PCB_R11(r1)
E 15
D 37

E 37
D 11
	movab	strt3c,PCB_PC(r1)		# initial pc
E 11
I 11
	movab	1f,PCB_PC(r1)			# initial pc
E 11
	clrl	PCB_PSL(r1)			# mode(k,k), ipl=0
D 37
	ashl	$9,r3,r3
E 37
I 37
	ashl	$PGSHIFT,r3,r3
E 37
	mtpr	r3,$PCBB			# first pcbb
D 22
#
# set regs, p0br, p0lr, p1br, p1lr
# astlvl, ksp and change to kernel mode
#
E 22
I 22
D 37
/*
 * set regs, p0br, p0lr, p1br, p1lr
 * astlvl, ksp and change to kernel mode
 */
E 37
I 37
/* set regs, p0br, p0lr, p1br, p1lr, astlvl, ksp and change to kernel mode */
E 37
E 22
	ldpctx
	rei
D 37

D 22
#
# put signal trampoline code in u. area
#
E 22
I 22
/*
 * put signal trampoline code in u. area
 */
E 22
D 11
strt3c:
E 11
I 11
1:
E 11
	movab	_u,r0
E 37
I 37
/* put signal trampoline code in u. area */
1:	movab	_u,r0
E 37
D 100
	movc3	$12,sigcode,PCB_SIGC(r0)
E 100
I 100
D 134
	movc3	$16,sigcode,PCB_SIGC(r0)
E 134
I 134
	movc3	$19,sigcode,PCB_SIGC(r0)
I 146
/* save boot device in global _bootdev */
	movl	r10,_bootdev
E 146
E 134
E 100
I 64
/* save reboot flags in global _boothowto */
	movl	r11,_boothowto
I 162
#ifdef KADB
E 162
I 153
/* save end of symbol & string table in global _bootesym */
	subl3	$NBPG-1,r9,_bootesym
I 162
#endif
E 162
E 153
E 64
I 37
/* calculate firstaddr, and call main() */
D 49
	addl3	_ecmap,$NBPG-1,r0; bbcc	$31,r0,0f; 0:; ashl $-PGSHIFT,r0,-(sp)
	calls	$1,_main
E 49
I 49
D 153
	movab	_end+NBPG-1,r0; bbcc $31,r0,0f; 0:; ashl $-PGSHIFT,r0,-(sp)
E 153
I 153
	bicl3	$SYSTEM,r9,r0; ashl $-PGSHIFT,r0,-(sp)
E 153
	addl2	$UPAGES+1,(sp); calls $1,_main
E 49
/* proc[1] == /etc/init now running here; run icode */
D 50
	pushl	$PSL_CURMOD|PSL_PRVMOD
	pushl	$0
	rei
E 50
I 50
	pushl	$PSL_CURMOD|PSL_PRVMOD; pushl $0; rei
E 50
E 37

D 37
	addl3	_ecmap,$NBPG-1,r0		# calculate firstaddr
D 11
	bbcc	$31,r0,strt4
strt4:
E 11
I 11
	bbcc	$31,r0,0f; 0:
E 11
	ashl	$-9,r0,-(sp)			# convert to clicks and stack
	calls	$1,_main			# startup, fork off /etc/init.vm
D 22
#
# proc[1] == /etc/init now running here.
# execute code at location 0, in user mode.
#
E 22
I 22
/*
 * proc[1] == /etc/init now running here.
 * execute code at location 0, in user mode.
 */
E 22
	pushl	$PSL_CURMOD|PSL_PRVMOD		# psl, user mode, ipl = 0
	pushl	$0				# pc, $location 0
	rei 					# do /etc/init.vm

D 22
#
# signal trampoline code
# it is known that this code takes exactly 12 bytes
# in ../h/pcb.h and in the movc3 above
#
E 22
I 22
/*
 * signal trampoline code
 * it is known that this code takes exactly 12 bytes
 * in ../h/pcb.h and in the movc3 above
 */
E 37
I 37
D 100
/* signal trampoline code: it is known that this code takes exactly 12 bytes */
/* in ../h/pcb.h and in the movc3 above */
E 100
I 100
D 134
/* signal trampoline code: it is known that this code takes exactly 16 bytes */
E 134
I 134
/* signal trampoline code: it is known that this code takes exactly 19 bytes */
E 134
/* in ../vax/pcb.h and in the movc3 above */
E 100
E 37
E 22
sigcode:
D 100
	calls	$3,1(pc)
E 100
I 100
D 134
	calls	$4,5(pc)			# params pushed by sendsig
	chmk	$139				# cleanup mask and onsigstack
E 100
	rei
D 37
	.word	0x7f
	callg	(ap),*12(ap)			# registers 0-6 (6==sp/compat)
E 37
I 37
	.word	0x7f				# registers 0-6 (6==sp/compat)
D 100
	callg	(ap),*12(ap)
E 100
I 100
	callg	(ap),*16(ap)
E 100
E 37
I 33
	ret
E 134
I 134
	calls	$4,8(pc)	# params pushed by sendsig
	movl	sp,ap		# calls frame built by sendsig
	chmk	$103		# cleanup mask and onsigstack
	halt			# sigreturn() does not return!
	.word	0x3f		# registers 0-5
	callg	(ap),*16(ap)	# call the signal handler
	ret			# return to code above
E 134
I 37

I 135
	.set	exec,11
	.set	exit,1
	.globl	_icode
	.globl	_initflags
	.globl	_szicode
/*
 * Icode is copied out to process 1 to exec /etc/init.
 * If the exec fails, process 1 exits.
 */
_icode:
	pushab	b`argv-l0(pc)
l0:	pushab	b`init-l1(pc)
l1:	pushl	$2
	movl	sp,ap
	chmk	$exec
I 154
	pushl	r0
E 154
	chmk	$exit

init:	.asciz	"/etc/init"
	.align	2
_initflags:
	.long	0
argv:	.long	init+5-_icode
	.long	_initflags-_icode
	.long	0
_szicode:
	.long	_szicode-_icode

E 135
E 37
I 34
/*
 * Primitives
 */ 
E 34

I 120
#ifdef GPROF
#define	ENTRY(name, regs) \
	.globl _/**/name; .align 1; _/**/name: .word regs; jsb mcount
D 127
#define	JSBENTRY(name) \
E 127
I 127
#define	JSBENTRY(name, regs) \
E 127
	.globl _/**/name; _/**/name: \
D 127
	movl fp,-(sp); movab -12(sp),fp; movq r0,-(sp); jsb mcount; \
	movq (sp)+,r0; movl (sp)+,fp
E 127
I 127
	movl fp,-(sp); movab -12(sp),fp; pushr $(regs); jsb mcount; \
	popr $(regs); movl (sp)+,fp
E 127
#else
#define	ENTRY(name, regs) \
	.globl _/**/name; .align 1; _/**/name: .word regs
D 127
#define	JSBENTRY(name) \
E 127
I 127
#define	JSBENTRY(name, regs) \
E 127
	.globl _/**/name; _/**/name:
#endif GPROF
I 127
#define R0 0x01
#define R1 0x02
#define R2 0x04
#define R3 0x08
#define R4 0x10
#define R5 0x20
E 127
#define R6 0x40

E 120
/*
D 34
 * address existence check
 *
 *	check address in r1 to see if we can reference it without
 *	destroying everything (like the whole world)
 *
 *	address should be a physical addr if mapping is disabled,
 *	or a virtual addr otherwise
 *
 *	return (in r0) :
 *		0	if address cannot be referenced at all
 *		1	if a byte reference succeeds
 *		2	if a word ref succeeds
 *		3	both byte and word
 *		4	if a long ref succeeds
 *		5,6,7	various other combinations
 *
 *		plus, to make life easy for assembly code hackers,
 *		set the CC to reflect r0
 *
 *	destroys r4 & r5, r1 unaltered
E 34
I 34
 * badaddr(addr, len)
 *	see if access addr with a len type instruction causes a machine check
 *	len is length of access (1=byte, 2=short, 4=long)
E 34
 */
D 34

chkadr:
	mfpr	$IPL,r4
	mtpr	$HIGH-1,$IPL		# permit mch chk ints only
					# (the -1 is a hangover, a mch chk
					# intr will happen anyway)
	movl	Scbbase+MCKVEC,r5	# save mch chk intr vec
	movab	9f+INTSTK,Scbbase+MCKVEC # and replace it with something useful

	clrl	r0			# assume no legal references

	pushab	1f			# return addr in case of mch chk
	tstl	(r1)			# can we ref this as a long ?
	addl2	$4,r0			# yes - set flag
1:
	tstl	(sp)+			# pop retn addr

	pushab	1f
	tstw	(r1)			# same for word ref
	addl2	$2,r0
1:
	tstl	(sp)+

	pushab	1f
	tstb	(r1)			# and for byte ref
	incl	r0
1:
	tstl	(sp)+

	movl	r5,Scbbase+MCKVEC	# restore mch chk intr vec
	mtpr	r4,$IPL			# and intr prio
	tstl	r0			# just for assembly hackers
	rsb

E 34
I 34
	.globl	_badaddr
_badaddr:
	.word	0
	movl	$1,r0
	mfpr	$IPL,r1
	mtpr	$HIGH,$IPL
D 36
	movl	Scbbase+MCKVEC,r2
E 36
I 36
D 43
	movl	_Scbbase+MCKVEC,r2
E 43
I 43
D 133
	movl	_scb+MCKVEC,r2
E 133
E 43
E 36
	movl	4(ap),r3
	movl	8(ap),r4
D 36
	movab	9f+INTSTK,Scbbase+MCKVEC
	bbc	$1,r4,1f; tstb	(r3)
1:	bbc	$2,r4,1f; tstw	(r3)
1:	bbc	$3,r4,1f; tstl	(r3)
E 36
I 36
D 43
	movab	9f+INTSTK,_Scbbase+MCKVEC
E 43
I 43
D 133
	movab	9f+INTSTK,_scb+MCKVEC
E 133
I 133
	movab	2f,nofault		# jump to 2f on machcheck
E 133
E 43
	bbc	$0,r4,1f; tstb	(r3)
1:	bbc	$1,r4,1f; tstw	(r3)
1:	bbc	$2,r4,1f; tstl	(r3)
E 36
1:	clrl	r0			# made it w/o machine checks
D 36
2:	movl	r2,Scbbase+MCKVEC
E 36
I 36
D 43
2:	movl	r2,_Scbbase+MCKVEC
E 43
I 43
D 133
2:	movl	r2,_scb+MCKVEC
E 133
I 133
2:	clrl	nofault
E 133
E 43
E 36
	mtpr	r1,$IPL
	ret
E 34
D 133
	.align	2
D 34
9:					# machine checks come here
E 34
I 34
9:
I 47
D 48
	casel	_cpu,$0,$VAX_MAX-1
E 48
I 48
D 55
	casel	_cpu,$1,$VAX_MAX-1
E 55
I 55
	casel	_cpu,$1,$VAX_MAX
E 55
E 48
0:
D 58
	.word	8f-0b		# 0 is 780
	.word	5f-0b		# 1 is 750
E 58
I 58
	.word	8f-0b		# 1 is 780
	.word	5f-0b		# 2 is 750
D 60
	.word	5f-0b		# 3 is 730
E 60
I 60
D 84
	.word	5f-0b		# 3 is 7ZZ
E 84
I 84
	.word	5f-0b		# 3 is 730
E 84
E 60
E 58
5:
D 58
#if VAX750
E 58
I 58
D 60
#if defined(VAX750) || defined(VAX730)
E 60
I 60
D 84
#if defined(VAX750) || defined(VAX7ZZ)
E 84
I 84
#if defined(VAX750) || defined(VAX730)
E 84
E 60
E 58
D 55
	mtpr	$0xf,MCESR
E 55
I 55
	mtpr	$0xf,$MCESR
E 55
#endif
	brb	1f
8:
E 47
E 34
D 46
#if VAX==780
E 46
I 46
#if VAX780
E 46
	mtpr	$0,$SBIFS
#endif
I 47
1:
E 47
D 34
	addl2	(sp)+,sp		# discard mch check trash
	movl	8(sp),(sp)		# return to place requested
E 34
I 34
	addl2	(sp)+,sp		# discard mchchk trash
	movab	2b,(sp)
E 34
	rei
E 133
D 34

	.globl	_chkadr
_chkadr:				# C entry to above
	.word	0
	movl	4(ap),r1
	jsb	chkadr
E 33
	ret

D 22
# ==========
# Primitives
# ==========
E 22
I 22
/*
 * Primitives
 */ 
E 34
E 22
D 87

_addupc:	.globl	_addupc
D 47
	.word	0x0000
E 47
I 47
	.word	0x0
E 47
	movl	8(ap),r2		# &u.u_prof
	subl3	8(r2),4(ap),r0		# corrected pc
D 11
	blss	addret
E 11
I 11
	blss	9f
E 11
	extzv	$1,$31,r0,r0		# logical right shift
	extzv	$1,$31,12(r2),r1	# ditto for scale
	emul	r1,r0,$0,r0
	ashq	$-14,r0,r0
	tstl	r1
D 11
	bneq	addret
E 11
I 11
	bneq	9f
E 11
	incl	r0
D 28
	bicb2	$1,r0
D 11
	blss	addret
E 11
I 11
	blss	9f
E 28
I 28
	bicl2	$1,r0
E 28
E 11
	cmpl	r0,4(r2)		# length
D 11
	bgequ	addret
E 11
I 11
	bgequ	9f
E 11
	addl2	(r2),r0			# base
	probew	$3,$2,(r0)
D 11
	beql	adderr
E 11
I 11
	beql	8f
E 11
	addw2	12(ap),(r0)
D 11
addret:
E 11
I 11
9:
E 11
	ret
D 11
adderr:
E 11
I 11
8:
E 11
	clrl	12(r2)
	ret
E 87

I 93
D 120
_addupc:	.globl	_addupc
	.word	0x0
E 120
I 120
/*
 * update profiling information for the user
 * addupc(pc, &u.u_prof, ticks)
 */
ENTRY(addupc, 0)
E 120
	movl	8(ap),r2		# &u.u_prof
	subl3	8(r2),4(ap),r0		# corrected pc
	blss	9f
	extzv	$1,$31,r0,r0		# logical right shift
	extzv	$1,$31,12(r2),r1	# ditto for scale
	emul	r1,r0,$0,r0
	ashq	$-14,r0,r0
	tstl	r1
	bneq	9f
D 98
	incl	r0
E 98
	bicl2	$1,r0
	cmpl	r0,4(r2)		# length
	bgequ	9f
	addl2	(r2),r0			# base
	probew	$3,$2,(r0)
	beql	8f
	addw2	12(ap),(r0)
9:
	ret
8:
	clrl	12(r2)
	ret

I 117
/*
 * Copy a null terminated string from the user address space into
 * the kernel address space.
I 118
 *
 * copyinstr(fromaddr, toaddr, maxlength, &lencopied)
E 118
 */
D 120
	.globl	_copyinstr
_copyinstr:
	.word	0x40			# save r6
E 120
I 120
ENTRY(copyinstr, R6)
E 120
	movl	12(ap),r6		# r6 = max length
D 118
	jlss	9f
E 118
I 118
	jlss	8f
E 118
	movl	4(ap),r1		# r1 = user address
D 124
	bicl3	$~(NBPG-1),r1,r2	# r2 = bytes on first page
	subl3	r2,$NBPG,r2
E 124
I 124
	bicl3	$~(NBPG*CLSIZE-1),r1,r2	# r2 = bytes on first page
	subl3	r2,$NBPG*CLSIZE,r2
E 124
	movl	8(ap),r3		# r3 = kernel address
1:
	cmpl	r6,r2			# r2 = min(bytes on page, length left);
	jgeq	2f
	movl	r6,r2
2:
D 118
	subl2	r2,r6			# update bytes left count
E 118
	prober	$3,r2,(r1)		# bytes accessible?
D 118
	jeql	9f
E 118
I 118
	jeql	8f
	subl2	r2,r6			# update bytes left count
I 147
#ifdef NOSUBSINST
	# fake the locc instr. for processors that don't have it
	movl	r2,r0
6:
	tstb	(r1)+
	jeql	5f
	sobgtr	r0,6b
	jbr	7f
5:
	decl	r1
	jbr	3f
7:
#else
E 147
E 118
	locc	$0,r2,(r1)		# null byte found?
	jneq	3f
I 147
#endif
E 147
	subl2	r2,r1			# back up pointer updated by `locc'
	movc3	r2,(r1),(r3)		# copy in next piece
D 124
	movl	$NBPG,r2		# check next page
E 124
I 124
	movl	$(NBPG*CLSIZE),r2	# check next page
E 124
	tstl	r6			# run out of space?
	jneq	1b
D 118
	clrb	-(r1)			# null terminate what fit and return
	jbr	8f
E 118
I 118
	movl	$ENOENT,r0		# set error code and return
	jbr	9f
E 118
3:
I 118
	tstl	16(ap)			# return length?
	beql	4f
	subl3	r6,12(ap),r6		# actual len = maxlen - unused pages
	subl2	r0,r6			#	- unused on this page
	addl3	$1,r6,*16(ap)		#	+ the null byte
4:
E 118
	subl2	r0,r2			# r2 = number of bytes to move
	subl2	r2,r1			# back up pointer updated by `locc'
	incl	r2			# copy null byte as well
	movc3	r2,(r1),(r3)		# copy in last piece
	clrl	r0			# redundant
	ret
8:
D 118
	movl	$ENOENT,r0
	ret
9:
E 118
	movl	$EFAULT,r0
I 118
9:
	tstl	16(ap)
	beql	1f
	subl3	r6,12(ap),*16(ap)
1:
E 118
	ret

/*
I 119
 * Copy a null terminated string from the kernel
 * address space to the user address space.
 *
 * copyoutstr(fromaddr, toaddr, maxlength, &lencopied)
 */
D 120
	.globl	_copyoutstr
_copyoutstr:
	.word	0x40			# save r6
E 120
I 120
ENTRY(copyoutstr, R6)
E 120
	movl	12(ap),r6		# r6 = max length
	jlss	8b
	movl	4(ap),r1		# r1 = kernel address
	movl	8(ap),r3		# r3 = user address
D 124
	bicl3	$~(NBPG-1),r3,r2	# r2 = bytes on first page
	subl3	r2,$NBPG,r2
E 124
I 124
	bicl3	$~(NBPG*CLSIZE-1),r3,r2	# r2 = bytes on first page
	subl3	r2,$NBPG*CLSIZE,r2
E 124
1:
	cmpl	r6,r2			# r2 = min(bytes on page, length left);
	jgeq	2f
	movl	r6,r2
2:
	probew	$3,r2,(r3)		# bytes accessible?
	jeql	8b
	subl2	r2,r6			# update bytes left count
I 147
#ifdef NOSUBSINST
	# fake the locc instr. for processors that don't have it
	movl	r2,r0
6:
	tstb	(r1)+
	jeql	5f
	sobgtr	r0,6b
	jbr	7f
5:
	decl	r1
	jbr	3b
7:
#else
E 147
	locc	$0,r2,(r1)		# null byte found?
	jneq	3b
I 147
#endif
E 147
	subl2	r2,r1			# back up pointer updated by `locc'
	movc3	r2,(r1),(r3)		# copy in next piece
D 124
	movl	$NBPG,r2		# check next page
E 124
I 124
	movl	$(NBPG*CLSIZE),r2	# check next page
E 124
	tstl	r6			# run out of space?
	jneq	1b
	movl	$ENOENT,r0		# set error code and return
	jbr	9b

/*
E 119
 * Copy a null terminated string from one point to another in
 * the kernel address space.
I 118
 *
 * copystr(fromaddr, toaddr, maxlength, &lencopied)
E 118
 */
D 120
	.globl	_copystr
_copystr:
	.word	0x40			# save r6
E 120
I 120
ENTRY(copystr, R6)
E 120
	movl	12(ap),r6		# r6 = max length
D 118
	jlss	9b
E 118
I 118
	jlss	8b
E 118
	movl	4(ap),r1		# r1 = src address
	movl	8(ap),r3		# r3 = dest address
1:
	movzwl	$65535,r2		# r2 = bytes in first chunk
	cmpl	r6,r2			# r2 = min(bytes in chunk, length left);
	jgeq	2f
	movl	r6,r2
2:
	subl2	r2,r6			# update bytes left count
I 147
#ifdef NOSUBSINST
	# fake the locc instr. for processors that don't have it
	movl	r2,r0
6:
	tstb	(r1)+
	jeql	5f
	sobgtr	r0,6b
	jbr	7f
5:
	decl	r1
	jbr	3b
7:
#else
E 147
	locc	$0,r2,(r1)		# null byte found?
D 118
	jneq	3f
E 118
I 118
	jneq	3b
I 147
#endif
E 147
E 118
	subl2	r2,r1			# back up pointer updated by `locc'
	movc3	r2,(r1),(r3)		# copy in next piece
	tstl	r6			# run out of space?
	jneq	1b
D 118
	clrb	-(r1)			# null terminate what fit and return
	jbr	8b
3:
	subl2	r0,r2			# r2 = number of bytes to move
	subl2	r2,r1			# back up pointer updated by `locc'
	incl	r2			# copy null byte as well
	movc3	r2,(r1),(r3)		# copy in last piece
	clrl	r0			# redundant
	ret
E 118
I 118
	movl	$ENOENT,r0		# set error code and return
	jbr	9b

E 118
D 120

E 117
E 93
_Copyin:	.globl	_Copyin		# <<<massaged for jsb by asm.sed>>>
E 120
I 120
/* 
 * Copy specified amount of data from user space into the kernel
 * Copyin(from, to, len)
I 127
 *	r1 == from (user source address)
 *	r3 == to (kernel destination address)
 *	r5 == length
E 127
 */
I 122
	.align	1
E 122
D 127
JSBENTRY(Copyin)
E 120
	movl	12(sp),r0		# copy length
	blss	ersb
D 122
	movl	4(sp),r1		# copy user address
	cmpl	$NBPG,r0		# probing one page or less ?
	bgeq	cishort			# yes
ciloop:
	prober	$3,$NBPG,(r1)		# bytes accessible ?
	beql	ersb			# no
	addl2	$NBPG,r1		# incr user address ptr
	acbl	$NBPG+1,$-NBPG,r0,ciloop	# reduce count and loop
cishort:
E 122
I 122
	movl	4(sp),r1		# r1 = user src address
	movl	8(sp),r3		# r3 = kernel dest addr
	cmpl	$(NBPG*CLSIZE),r0	# probing one page or less ?
	bleq	1f			# no
E 122
	prober	$3,r0,(r1)		# bytes accessible ?
E 127
I 127
JSBENTRY(Copyin, R1|R3|R5)
	cmpl	r5,$(NBPG*CLSIZE)	# probing one page or less ?
	bgtru	1f			# no
	prober	$3,r5,(r1)		# bytes accessible ?
E 127
	beql	ersb			# no
D 86
	movc3	12(sp),*4(sp),*8(sp)
	clrl	r0
E 86
I 86
D 122
	movl	4(sp),r1
	movl	8(sp),r3
	jbr	2f
E 122
I 122
D 127
	movc3	r0,(r1),(r3)
	clrl	r0			#redundant
E 127
I 127
	movc3	r5,(r1),(r3)
/*	clrl	r0			# redundant */
E 127
	rsb
E 122
1:
I 127
	blss	ersb			# negative length?
	pushl	r6			# r6 = length
	movl	r5,r6
E 127
D 122
	subl2	r0,12(sp)
E 122
I 122
	bicl3	$~(NBPG*CLSIZE-1),r1,r0	# r0 = bytes on first page
	subl3	r0,$(NBPG*CLSIZE),r0
	addl2	$(NBPG*CLSIZE),r0	# plus one additional full page
	jbr	2f

ciloop:
E 122
	movc3	r0,(r1),(r3)
I 122
	movl	$(2*NBPG*CLSIZE),r0	# next amount to move
E 122
2:
D 122
	movzwl	$65535,r0
	cmpl	12(sp),r0
	jgtr	1b
	movc3	12(sp),(r1),(r3)
E 122
I 122
D 127
	cmpl	r0,12(sp)
E 127
I 127
	cmpl	r0,r6
E 127
	bleq	3f
D 127
	movl	12(sp),r0
E 127
I 127
	movl	r6,r0
E 127
3:
	prober	$3,r0,(r1)		# bytes accessible ?
D 127
	beql	ersb			# no
	subl2	r0,12(sp)		# last move?
E 127
I 127
	beql	ersb1			# no
	subl2	r0,r6			# last move?
E 127
	bneq	ciloop			# no

	movc3	r0,(r1),(r3)
E 122
D 127
	clrl	r0			#redundant
E 127
I 127
/*	clrl	r0			# redundant */
	movl	(sp)+,r6		# restore r6
E 127
E 86
	rsb

I 127
ersb1:
	movl	(sp)+,r6		# restore r6
E 127
ersb:
D 96
	mnegl	$1,r0
E 96
I 96
	movl	$EFAULT,r0
E 96
	rsb

D 120
_Copyout: 	.globl	_Copyout	# <<<massaged for jsb by asm.sed >>>
E 120
I 120
/* 
 * Copy specified amount of data from kernel to the user space
 * Copyout(from, to, len)
I 127
 *	r1 == from (kernel source address)
 *	r3 == to (user destination address)
 *	r5 == length
E 127
 */
I 122
	.align	1
E 122
D 127
JSBENTRY(Copyout)
E 120
D 122
	movl	12(sp),r0		# get count
E 122
I 122
	movl	12(sp),r0		# copy length
E 122
	blss	ersb
D 122
	movl	8(sp),r1		# get user address
	cmpl	$NBPG,r0		# can do in one probew?
	bgeq	coshort			# yes
coloop:
	probew	$3,$NBPG,(r1)		# bytes accessible?
	beql	ersb			# no 
	addl2	$NBPG,r1		# increment user address
	acbl	$NBPG+1,$-NBPG,r0,coloop	# reduce count and loop
coshort:
	probew	$3,r0,(r1)		# bytes accessible?
E 122
I 122
	movl	4(sp),r1		# r1 = kernel src address
	movl	8(sp),r3		# r3 = user dest addr
	cmpl	$(NBPG*CLSIZE),r0	# moving one page or less ?
	bleq	1f			# no
	probew	$3,r0,(r3)		# bytes writeable?
E 127
I 127
JSBENTRY(Copyout, R1|R3|R5)
	cmpl	r5,$(NBPG*CLSIZE)	# moving one page or less ?
	bgtru	1f			# no
	probew	$3,r5,(r3)		# bytes writeable?
E 127
E 122
	beql	ersb			# no
D 86
	movc3	12(sp),*4(sp),*8(sp)
	clrl	r0
E 86
I 86
D 122
	movl	4(sp),r1
	movl	8(sp),r3
	jbr	2f
E 122
I 122
D 127
	movc3	r0,(r1),(r3)
	clrl	r0			#redundant
E 127
I 127
	movc3	r5,(r1),(r3)
/*	clrl	r0			# redundant */
E 127
	rsb
E 122
1:
I 127
	blss	ersb			# negative length?
	pushl	r6			# r6 = length
	movl	r5,r6
E 127
D 122
	subl2	r0,12(sp)
E 122
I 122
	bicl3	$~(NBPG*CLSIZE-1),r3,r0	# r0 = bytes on first page
	subl3	r0,$(NBPG*CLSIZE),r0
	addl2	$(NBPG*CLSIZE),r0	# plus one additional full page
	jbr	2f

coloop:
E 122
	movc3	r0,(r1),(r3)
I 122
	movl	$(2*NBPG*CLSIZE),r0	# next amount to move
E 122
2:
D 122
	movzwl	$65535,r0
	cmpl	12(sp),r0
	jgtr	1b
	movc3	12(sp),(r1),(r3)
	clrl	r0				#redundant
E 122
I 122
D 127
	cmpl	r0,12(sp)
E 127
I 127
	cmpl	r0,r6
E 127
	bleq	3f
D 127
	movl	12(sp),r0
E 127
I 127
	movl	r6,r0
E 127
3:
	probew	$3,r0,(r3)		# bytes writeable?
D 127
	beql	ersb			# no
	subl2	r0,12(sp)		# last move?
E 127
I 127
	beql	ersb1			# no
	subl2	r0,r6			# last move?
E 127
	bneq	coloop			# no

	movc3	r0,(r1),(r3)
D 127
	clrl	r0			#redundant
E 127
I 127
/*	clrl	r0			# redundant */
	movl	(sp)+,r6		# restore r6
E 127
E 122
E 86
	rsb

D 22
#
# non-local goto's
#
E 22
I 22
/*
 * non-local goto's
 */
I 124
#ifdef notdef		/* this is now expanded completely inline */
E 124
I 122
	.align	1
E 122
E 22
D 4
	.globl	_setjmp
_setjmp:
	.word	0xfc0				# r6-r11
	movl	4(ap),r0			# address save area
	movl	sp,(r0)+			# frame location
	movc3	$13*4,(fp),(r0)			# frame itself
	ret					# movc3 sets r0=0
E 4
I 4
D 120
	.globl	_Setjmp
_Setjmp:
E 120
I 120
D 127
JSBENTRY(Setjmp)
E 127
I 127
JSBENTRY(Setjmp, R0)
E 127
E 120
D 122
	movq	r6,(r0)+
	movq	r8,(r0)+
	movq	r10,(r0)+
	movq	r12,(r0)+
	addl3	$4,sp,(r0)+
	movl	(sp),(r0)
E 122
I 122
	movl	fp,(r0)+	# current stack frame
	movl	(sp),(r0)	# resuming pc
E 122
	clrl	r0
	rsb
I 124
#endif
E 124
E 4

I 122
D 129
#define PCLOC 16
E 129
I 129
#define PCLOC 16	/* location of pc in calls frame */
#define APLOC 8		/* location of ap,fp in calls frame */
E 129
	.align	1
E 122
D 4
	.globl	_longjmp
_longjmp:
	.word	0x0
	movq	4(ap),r6			# addr save area, value
lj1:
	movl	(r6)+,r8
	movl	11*4(r6),r0			# no. params to be popped
	moval	12*4(r8)[r0],r0			# sp value after ret
	cmpl	r0,sp				# must be a pop
	bgequ	lj3
	pushab	lj2
E 4
I 4
D 120
	.globl	_Longjmp
_Longjmp:
E 120
I 120
D 127
JSBENTRY(Longjmp)
E 127
I 127
JSBENTRY(Longjmp, R0)
E 127
E 120
D 122
	movq	(r0)+,r6
	movq	(r0)+,r8
	movq	(r0)+,r10
	movq	(r0)+,r12
	movl	(r0)+,r1
	cmpl	r1,sp				# must be a pop
	bgequ	lj2
	pushab	lj1
E 122
I 122
	movl	(r0)+,newfp	# must save parameters in memory as all
	movl	(r0),newpc	# registers may be clobbered.
1:
	cmpl	fp,newfp	# are we there yet?
	bgequ	2f		# yes
	moval	1b,PCLOC(fp)	# redirect return pc to us!
	ret			# pop next frame
2:
	beql	3f		# did we miss our frame?
	pushab	4f		# yep ?!?
E 122
E 4
	calls	$1,_panic
D 4
lj3:
	movl	r8,r9
	movq	r8,fp				# new fp, sp
	movc3	$13*4,(r6),(fp)			# recreate frame
	movl	r7,r0
	bneq	_ret				# must be != 0
	incl	r0
_ret:
	ret
E 4
I 4
D 122
lj2:
	movl	r1,sp
	jmp	*(r0)				# ``rsb''
E 122
I 122
3:
	movl	newpc,r0	# all done, just return to the `setjmp'
	jmp	(r0)		# ``rsb''
E 122
E 4

D 4
lj2:	.asciz	"longjmp"
E 4
I 4
D 122
lj1:	.asciz	"longjmp"
E 122
I 122
	.data
newpc:	.space	4
newfp:	.space	4
4:	.asciz	"longjmp"
	.text
I 129
/*
 * setjmp that saves all registers as the call frame may not
 * be available to recover them in the usual mannor by longjmp.
 * Called before swapping out the u. area, restored by resume()
 * below.
 */
ENTRY(savectx, 0)
	movl	4(ap),r0
	movq	r6,(r0)+
	movq	r8,(r0)+
	movq	r10,(r0)+
	movq	APLOC(fp),(r0)+	# save ap, fp
	addl3	$8,ap,(r0)+	# save sp
	movl	PCLOC(fp),(r0)	# save pc
	clrl	r0
	ret
E 129
E 122
E 4

I 153
D 160
#ifdef KDB
E 160
I 160
#ifdef KADB
E 160
/*
 * C library -- reset, setexit
 *
 *	reset(x)
 * will generate a "return" from
 * the last call to
 *	setexit()
 * by restoring r6 - r12, ap, fp
 * and doing a return.
 * The returned value is x; on the original
 * call the returned value is 0.
 */
D 160
ENTRY(setexit)
E 160
I 160
ENTRY(setexit, 0)
E 160
	movab	setsav,r0
	movq	r6,(r0)+
	movq	r8,(r0)+
	movq	r10,(r0)+
	movq	8(fp),(r0)+		# ap, fp
	movab	4(ap),(r0)+		# sp
	movl	16(fp),(r0)		# pc
	clrl	r0
	ret

D 160
ENTRY(reset)
E 160
I 160
ENTRY(reset, 0)
E 160
	movl	4(ap),r0	# returned value
	movab	setsav,r1
	movq	(r1)+,r6
	movq	(r1)+,r8
	movq	(r1)+,r10
	movq	(r1)+,r12
	movl	(r1)+,sp
	jmp 	*(r1)

	.data
	.align  2
setsav:	.space	10*4
	.text
#endif

E 153
	.globl	_whichqs
	.globl	_qs
	.globl	_cnt

	.globl	_noproc
	.comm	_noproc,4
	.globl	_runrun
	.comm	_runrun,4

D 22
#
# The following primitives use the fancy VAX instructions
# much like VMS does.  _whichqs tells which of the 32 queues _qs
# have processes in them.  Setrq puts processes into queues, Remrq
# removes them from queues.  The running process is on no queue,
# other processes are on a queue related to p->p_pri, divided by 4
# actually to shrink the 0-127 range of priorities into the 32 available
# queues.
#
E 22
I 22
/*
 * The following primitives use the fancy VAX instructions
 * much like VMS does.  _whichqs tells which of the 32 queues _qs
 * have processes in them.  Setrq puts processes into queues, Remrq
 * removes them from queues.  The running process is on no queue,
 * other processes are on a queue related to p->p_pri, divided by 4
 * actually to shrink the 0-127 range of priorities into the 32 available
 * queues.
 */
E 22

D 22
#
# Setrq(p), using fancy VAX instructions.
#
# Call should be made at spl6(), and p->p_stat should be SRUN
#
E 22
I 22
/*
 * Setrq(p), using fancy VAX instructions.
 *
D 145
 * Call should be made at spl6(), and p->p_stat should be SRUN
E 145
I 145
 * Call should be made at splclock(), and p->p_stat should be SRUN
E 145
 */
I 122
	.align	1
E 122
E 22
D 120
	.globl	_Setrq		# <<<massaged to jsb by "asm.sed">>>
_Setrq:
E 120
I 120
D 127
 JSBENTRY(Setrq)
E 127
I 127
D 153
 JSBENTRY(Setrq, R0)
E 153
I 153
JSBENTRY(Setrq, R0)
E 153
E 127
E 120
	tstl	P_RLINK(r0)		## firewall: p->p_rlink must be 0
	beql	set1			##
	pushab	set3			##
	calls	$1,_panic		##
set1:
	movzbl	P_PRI(r0),r1		# put on queue which is p->p_pri / 4
	ashl	$-2,r1,r1
	movaq	_qs[r1],r2
	insque	(r0),*4(r2)		# at end of queue
	bbss	r1,_whichqs,set2	# mark queue non-empty
set2:
	rsb

set3:	.asciz	"setrq"

D 22
#
# Remrq(p), using fancy VAX instructions
#
# Call should be made at spl6().
#
E 22
I 22
/*
 * Remrq(p), using fancy VAX instructions
 *
D 145
 * Call should be made at spl6().
E 145
I 145
 * Call should be made at splclock().
E 145
 */
I 122
	.align	1
E 122
E 22
D 120
	.globl	_Remrq		# <<<massaged to jsb by "asm.sed">>>
_Remrq:
E 120
I 120
D 127
 JSBENTRY(Remrq)
E 127
I 127
D 153
 JSBENTRY(Remrq, R0)
E 153
I 153
JSBENTRY(Remrq, R0)
E 153
E 127
E 120
	movzbl	P_PRI(r0),r1
	ashl	$-2,r1,r1
	bbsc	r1,_whichqs,rem1
	pushab	rem3			# it wasn't recorded to be on its q
	calls	$1,_panic
rem1:
	remque	(r0),r2
	beql	rem2
	bbss	r1,_whichqs,rem2
rem2:
	clrl	P_RLINK(r0)		## for firewall checking
	rsb

rem3:	.asciz	"remrq"

I 67
/*
D 68
 * Materpaddr is the p->p_addr of the running process on the master
E 68
I 68
 * Masterpaddr is the p->p_addr of the running process on the master
E 68
 * processor.  When a multiprocessor system, the slave processors will have
D 68
 * an array of spavepaddr's.
E 68
I 68
 * an array of slavepaddr's.
E 68
 */
	.globl	_masterpaddr
	.data
_masterpaddr:
	.long	0

I 121
D 153
	.set	ASTLVL_NONE,4
E 153
E 121
	.text
E 67
sw0:	.asciz	"swtch"
I 121

E 121
D 22
#
# Swtch(), using fancy VAX instructions
#
E 22
I 22
/*
I 121
 * When no processes are on the runq, Swtch branches to idle
 * to wait for something to come ready.
 */
	.globl	Idle
Idle: idle:
I 155
	movl	$1,_noproc
E 155
	mtpr	$0,$IPL			# must allow interrupts here
I 153
1:
E 153
	tstl	_whichqs		# look for non-empty queue
	bneq	sw1
D 153
	brb	idle
E 153
I 153
	brb	1b
E 153

badsw:	pushab	sw0
	calls	$1,_panic
	/*NOTREACHED*/

/*
E 121
 * Swtch(), using fancy VAX instructions
 */
I 122
	.align	1
E 122
E 22
D 120
	.globl	_Swtch
_Swtch:				# <<<massaged to jsb by "asm.sed">>>
E 120
I 120
D 127
JSBENTRY(Swtch)
E 127
I 127
JSBENTRY(Swtch, 0)
E 127
E 120
D 155
	movl	$1,_noproc
E 155
D 121
	clrl	_runrun
E 121
I 121
	incl	_cnt+V_SWTCH
E 121
sw1:	ffs	$0,$32,_whichqs,r0	# look for non-empty queue
D 121
	bneq	sw1a
	mtpr	$0,$IPL			# must allow interrupts here
D 85
	brw	sw1			# this is an idle loop!
E 85
I 85
	jbr	sw1			# this is an idle loop!
E 85
sw1a:	mtpr	$0x18,$IPL		# lock out all so _whichqs==_qs
E 121
I 121
	beql	idle			# if none, idle
	mtpr	$0x18,$IPL		# lock out all so _whichqs==_qs
E 121
D 153
	bbcc	r0,_whichqs,sw1		# proc moved via lbolt interrupt
E 153
I 153
	bbcc	r0,_whichqs,sw1		# proc moved via interrupt
E 153
	movaq	_qs[r0],r1
	remque	*(r1),r2		# r2 = p = highest pri process
D 121
	bvc	sw2			# make sure something was there
sw1b:	pushab	sw0
	calls	$1,_panic
E 121
I 121
	bvs	badsw			# make sure something was there
E 121
D 153
sw2:	beql	sw3
E 153
I 153
	beql	sw2
E 153
	insv	$1,r0,$1,_whichqs	# still more procs in this queue
D 153
sw3:
E 153
I 153
sw2:
E 153
	clrl	_noproc
I 121
	clrl	_runrun
I 155
#ifdef notdef
E 155
D 132
	mtpr	$ASTLVL_NONE,$ASTLVL	# cancel scheduling ast's
E 132
E 121
	tstl	P_WCHAN(r2)		## firewalls
D 121
	bneq	sw1b			##
	movzbl	P_STAT(r2),r3		##
	cmpl	$SRUN,r3		##
	bneq	sw1b			##
E 121
I 121
	bneq	badsw			##
	cmpb	P_STAT(r2),$SRUN	##
	bneq	badsw			##
I 155
#endif
E 155
E 121
	clrl	P_RLINK(r2)		##
D 68
	ashl	$PGSHIFT,*P_ADDR(r2),r0	# r0 = pcbb(p)
E 68
I 68
	movl	*P_ADDR(r2),r0
I 121
#ifdef notdef
	cmpl	r0,_masterpaddr		# resume of current proc is easy
	beql	res0
#endif
E 121
	movl	r0,_masterpaddr
	ashl	$PGSHIFT,r0,r0		# r0 = pcbb(p)
E 68
D 22
#	mfpr	$PCBB,r1		# resume of current proc is easy
#	cmpl	r0,r1
#	beql	res0
E 22
I 22
D 121
/*	mfpr	$PCBB,r1		# resume of current proc is easy
 *	cmpl	r0,r1
 */	beql	res0
E 22
	incl	_cnt+V_SWTCH
E 121
D 22
# fall into...
E 22
I 22
/* fall into... */
E 22

D 22
#
# Resume(pf)
#
E 22
I 22
/*
 * Resume(pf)
 */
E 22
D 120
	.globl	_Resume		# <<<massaged to jsb by "asm.sed">>>
_Resume:
E 120
I 120
D 127
JSBENTRY(Resume)
E 127
I 127
JSBENTRY(Resume, R0)
E 127
E 120
D 132
	mtpr	$0x18,$IPL			# no interrupts, please
E 132
I 132
D 133
	mtpr	$0x1f,$IPL			# no interrupts, please
E 133
I 133
	mtpr	$HIGH,$IPL			# no interrupts, please
E 133
E 132
D 37
	movl	CMAP2,_u+PCB_CMAP2	# yech
E 37
I 37
	movl	_CMAP2,_u+PCB_CMAP2	# yech
E 37
	svpctx
	mtpr	r0,$PCBB
	ldpctx
I 67
D 68
	mfpr	$PCBB,_masterpcbb
E 68
E 67
D 37
	movl	_u+PCB_CMAP2,CMAP2	# yech
E 37
I 37
	movl	_u+PCB_CMAP2,_CMAP2	# yech
I 81
	mtpr	$_CADDR2,$TBIS
E 81
E 37
res0:
	tstl	_u+PCB_SSWAP
D 121
	beql	res1
E 121
I 121
	bneq	res1
	rei
res1:
E 121
D 4
	movl	_u+PCB_SSWAP,r6
E 4
I 4
D 129
	movl	_u+PCB_SSWAP,r0
E 129
I 129
	movl	_u+PCB_SSWAP,r0			# longjmp to saved context
E 129
E 4
	clrl	_u+PCB_SSWAP
D 4
	movab	lj1,(sp)
E 4
I 4
D 129
	movab	_Longjmp,(sp)
E 129
I 129
D 158
	movq	(r0)+,r6
	movq	(r0)+,r8
	movq	(r0)+,r10
	movq	(r0)+,r12
	movl	(r0)+,r1
E 158
I 158
	movq	(r0)+,r6			# restore r6, r7
	movq	(r0)+,r8			# restore r8, r9
	movq	(r0)+,r10			# restore r10, r11
	movq	(r0)+,r12			# restore ap, fp
	movl	(r0)+,r1			# saved sp
E 158
	cmpl	r1,sp				# must be a pop
	bgequ	1f
	pushab	2f
	calls	$1,_panic
	/* NOTREACHED */
1:
D 158
	movl	r1,sp
	movl	(r0),(sp)			# address to return to
E 129
E 4
	movl	$PSL_PRVMOD,4(sp)		# ``cheating'' (jfr)
E 158
I 158
	movl	r1,sp				# restore sp
	pushl	$PSL_PRVMOD			# return psl
	pushl	(r0)				# address to return to
E 158
D 121
res1:
E 121
	rei
I 129

2:	.asciz	"ldctx"
E 129

D 22
#
# {fu,su},{byte,word}, all massaged by asm.sed to jsb's
#
E 22
I 22
/*
 * {fu,su},{byte,word}, all massaged by asm.sed to jsb's
 */
I 122
	.align	1
E 122
E 22
D 120
	.globl	_Fuword
_Fuword:
E 120
I 120
D 127
JSBENTRY(Fuword)
E 127
I 127
JSBENTRY(Fuword, R0)
E 127
E 120
	prober	$3,$4,(r0)
	beql	fserr
	movl	(r0),r0
	rsb
fserr:
	mnegl	$1,r0
	rsb

I 122
	.align	1
E 122
D 120
	.globl	_Fubyte
_Fubyte:
E 120
I 120
D 127
JSBENTRY(Fubyte)
E 127
I 127
JSBENTRY(Fubyte, R0)
E 127
E 120
	prober	$3,$1,(r0)
	beql	fserr
	movzbl	(r0),r0
	rsb

I 122
	.align	1
E 122
D 120
	.globl	_Suword
_Suword:
E 120
I 120
D 127
JSBENTRY(Suword)
E 127
I 127
JSBENTRY(Suword, R0|R1)
E 127
E 120
	probew	$3,$4,(r0)
	beql	fserr
	movl	r1,(r0)
	clrl	r0
	rsb

I 122
	.align	1
E 122
D 120
	.globl	_Subyte
_Subyte:
E 120
I 120
D 127
JSBENTRY(Subyte)
E 127
I 127
JSBENTRY(Subyte, R0|R1)
E 127
E 120
	probew	$3,$1,(r0)
	beql	fserr
	movb	r1,(r0)
	clrl	r0
	rsb

D 22
#
# Copy 1 relocation unit (NBPG bytes)
# from user virtual address to physical address
#
E 22
I 22
/*
 * Copy 1 relocation unit (NBPG bytes)
 * from user virtual address to physical address
 */
E 22
D 120
_copyseg: 	.globl	_copyseg
D 47
	.word	0x0000
E 47
I 47
	.word	0x0
E 120
I 120
ENTRY(copyseg, 0)
E 120
E 47
D 62
	mfpr	$IPL,r0		# get current pri level
	mtpr	$HIGH,$IPL	# turn off interrupts
E 62
D 37
	bisl3	$PG_V|PG_KW,8(ap),CMAP2
E 37
I 37
	bisl3	$PG_V|PG_KW,8(ap),_CMAP2
E 37
D 36
	mtpr	$CADDR2,$TBIS	# invalidate entry for copy 
	movc3	$NBPG,*4(ap),CADDR2
E 36
I 36
	mtpr	$_CADDR2,$TBIS	# invalidate entry for copy 
	movc3	$NBPG,*4(ap),_CADDR2
E 36
D 15
	bicl3	$PG_V|PG_M|PG_KW,CMAP2,r1
	cmpl	r1,8(ap)
	beql	okcseg
badcseg:
	halt
	jmp	badcseg
okcseg:
E 15
D 62
	mtpr	r0,$IPL		# restore pri level
E 62
	ret

D 22
#
# zero out physical memory
# specified in relocation units (NBPG bytes)
#
E 22
I 22
/*
 * zero out physical memory
 * specified in relocation units (NBPG bytes)
 */
E 22
D 120
_clearseg: 	.globl	_clearseg
D 47
	.word	0x0000
E 47
I 47
	.word	0x0
E 120
I 120
ENTRY(clearseg, 0)
E 120
E 47
D 62
	mfpr	$IPL,r0		# get current pri level
	mtpr	$HIGH,$IPL	# extreme pri level
E 62
D 37
	bisl3	$PG_V|PG_KW,4(ap),CMAP1
E 37
I 37
	bisl3	$PG_V|PG_KW,4(ap),_CMAP1
E 37
D 36
	mtpr	$CADDR1,$TBIS
	movc5	$0,(sp),$0,$NBPG,CADDR1
E 36
I 36
	mtpr	$_CADDR1,$TBIS
	movc5	$0,(sp),$0,$NBPG,_CADDR1
E 36
D 62
	mtpr	r0,$IPL		# restore pri level
E 62
	ret

D 22
#
# Check address.
# Given virtual address, byte count, and rw flag
# returns 0 on no access.
#
E 22
I 22
/*
 * Check address.
 * Given virtual address, byte count, and rw flag
 * returns 0 on no access.
 */
E 22
D 120
_useracc:	.globl	_useracc
D 47
	.word	0x0000
E 47
I 47
	.word	0x0
E 120
I 120
ENTRY(useracc, 0)
E 120
E 47
	movl	4(ap),r0		# get va
	movl	8(ap),r1		# count
	tstl	12(ap)			# test for read access ?
	bneq	userar			# yes
	cmpl	$NBPG,r1			# can we do it in one probe ?
	bgeq	uaw2			# yes
uaw1:
	probew	$3,$NBPG,(r0)
	beql	uaerr			# no access
	addl2	$NBPG,r0
	acbl	$NBPG+1,$-NBPG,r1,uaw1
uaw2:
	probew	$3,r1,(r0)
	beql	uaerr
	movl	$1,r0
	ret

userar:
	cmpl	$NBPG,r1
	bgeq	uar2
uar1:
	prober	$3,$NBPG,(r0)
	beql	uaerr
	addl2	$NBPG,r0
	acbl	$NBPG+1,$-NBPG,r1,uar1
uar2:
	prober	$3,r1,(r0)
	beql	uaerr
	movl	$1,r0
	ret
uaerr:
	clrl	r0
	ret

D 22
#
# kernacc - check for kernel access privileges
#
# We can't use the probe instruction directly because
# it ors together current and previous mode.
#
E 22
I 22
/*
 * kernacc - check for kernel access privileges
 *
 * We can't use the probe instruction directly because
 * it ors together current and previous mode.
 */
E 22
D 120
	.globl	_kernacc
_kernacc:
D 47
	.word	0x0000
E 47
I 47
	.word	0x0
E 120
I 120
 ENTRY(kernacc, 0)
E 120
E 47
	movl	4(ap),r0	# virtual address
	bbcc	$31,r0,kacc1
I 61
	bbs	$30,r0,kacerr
E 61
	mfpr	$SBR,r2		# address and length of page table (system)
I 22
	bbss	$31,r2,0f; 0:
E 22
	mfpr	$SLR,r3
	brb	kacc2
kacc1:
	bbsc	$30,r0,kacc3
	mfpr	$P0BR,r2	# user P0
	mfpr	$P0LR,r3
	brb	kacc2
kacc3:
	mfpr	$P1BR,r2	# user P1 (stack)
	mfpr	$P1LR,r3
kacc2:
	addl3	8(ap),r0,r1	# ending virtual address
I 29
	addl2	$NBPG-1,r1
E 29
D 37
	ashl	$-9,r0,r0	# page number
	ashl	$-9,r1,r1
E 37
I 37
	ashl	$-PGSHIFT,r0,r0
	ashl	$-PGSHIFT,r1,r1
E 37
	bbs	$31,4(ap),kacc6
	bbc	$30,4(ap),kacc6
	cmpl	r0,r3		# user stack
	blss	kacerr		# address too low
	brb	kacc4
kacc6:
	cmpl	r1,r3		# compare last page to P0LR or SLR
D 29
	bgeq	kacerr		# address too high
E 29
I 29
	bgtr	kacerr		# address too high
E 29
kacc4:	
	movl	(r2)[r0],r3
	bbc	$31,4(ap),kacc4a
	bbc	$31,r3,kacerr	# valid bit is off
kacc4a:
	cmpzv	$27,$4,r3,$1	# check protection code
	bleq	kacerr		# no access allowed
	tstb	12(ap)
	bneq	kacc5		# only check read access
	cmpzv	$27,$2,r3,$3	# check low 2 bits of prot code
	beql	kacerr		# no write access
kacc5:
D 29
	aobleq	r1,r0,kacc4	# next page
E 29
I 29
	aoblss	r1,r0,kacc4	# next page
E 29
	movl	$1,r0		# no errors
	ret
kacerr:
	clrl	r0		# error
	ret
I 99
/*
 * Extracted and unrolled most common case of pagein (hopefully):
 *	resident and not on free list (reclaim of page is purely
 *	for the purpose of simulating a reference bit)
 *
 * Built in constants:
D 114
 *	CLSIZE of 2, USRSTACK of 0x7ffff000, any bit fields
 *	in pte's or the core map
E 114
I 114
 *	CLSIZE of 2, any bit fields in pte's
E 114
 */
D 103
	.globl	Fastreclaim
E 103
	.text
I 103
	.globl	Fastreclaim
E 103
Fastreclaim:
	PUSHR
I 120
#ifdef GPROF
	movl	fp,-(sp)
	movab	12(sp),fp
	jsb	mcount
	movl	(sp)+,fp
#endif GPROF
E 120
	extzv	$9,$23,28(sp),r3	# virtual address
	bicl2	$1,r3			# v = clbase(btop(virtaddr)); 
	movl	_u+U_PROCP,r5		# p = u.u_procp 
					# from vtopte(p, v) ...
I 122
	movl	$1,r2			# type = CTEXT;
E 122
	cmpl	r3,P_TSIZE(r5)
D 122
	jgequ	2f			# if (isatsv(p, v)) {
	ashl	$2,r3,r4
	addl2	P_P0BR(r5),r4		#	tptopte(p, vtotp(p, v));
	movl	$1,r2			#	type = CTEXT;
	jbr	3f
2:
D 113
	subl3	P_SSIZE(r5),$0x3ffff8,r0
E 113
I 113
	subl3	P_SSIZE(r5),$(0x400000-UPAGES),r0
E 122
I 122
	jlssu	1f			# if (isatsv(p, v)) {
	addl3	P_TSIZE(r5),P_DSIZE(r5),r0
E 122
E 113
	cmpl	r3,r0
D 122
	jgequ	2f			# } else if (isadsv(p, v)) {
	ashl	$2,r3,r4
	addl2	P_P0BR(r5),r4		#	dptopte(p, vtodp(p, v));
E 122
I 122
	jgequ	2f
E 122
	clrl	r2			#	type = !CTEXT;
I 122
1:
	ashl	$2,r3,r4
	addl2	P_P0BR(r5),r4		#	tptopte(p, vtotp(p, v));
E 122
	jbr	3f
2:
	cvtwl	P_SZPT(r5),r4		# } else (isassv(p, v)) {
	ashl	$7,r4,r4
D 113
	subl2	$(0x3ffff8+UPAGES),r4
E 113
I 113
	subl2	$0x400000,r4
E 113
	addl2	r3,r4
	ashl	$2,r4,r4
	addl2	P_P0BR(r5),r4		#	sptopte(p, vtosp(p, v));
	clrl	r2			# 	type = !CTEXT;
3:					# }
	bitb	$0x82,3(r4)
	beql	2f			# if (pte->pg_v || pte->pg_fod)
	POPR; rsb			#	let pagein handle it
2:
	bicl3	$0xffe00000,(r4),r0
	jneq	2f			# if (pte->pg_pfnum == 0)
	POPR; rsb			# 	let pagein handle it 
2:
	subl2	_firstfree,r0
	ashl	$-1,r0,r0	
	incl	r0			# pgtocm(pte->pg_pfnum) 
D 114
	mull2	$12,r0
E 114
I 114
	mull2	$SZ_CMAP,r0
E 114
	addl2	_cmap,r0		# &cmap[pgtocm(pte->pg_pfnum)] 
	tstl	r2
	jeql	2f			# if (type == CTEXT &&
D 114
	jbc	$29,4(r0),2f		#     c_intrans)
E 114
I 114
	jbc	$C_INTRANS,(r0),2f	#     c_intrans)
E 114
	POPR; rsb			# 	let pagein handle it
2:
D 114
	jbc	$30,4(r0),2f		# if (c_free)
E 114
I 114
	jbc	$C_FREE,(r0),2f		# if (c_free)
E 114
	POPR; rsb			# 	let pagein handle it 
2:
	bisb2	$0x80,3(r4)		# pte->pg_v = 1;
	jbc	$26,4(r4),2f		# if (anycl(pte, pg_m) 
	bisb2	$0x04,3(r4)		#	pte->pg_m = 1;
2:
	bicw3	$0x7f,2(r4),r0
	bicw3	$0xff80,6(r4),r1
	bisw3	r0,r1,6(r4)		# distcl(pte);
	ashl	$PGSHIFT,r3,r0
	mtpr	r0,$TBIS
	addl2	$NBPG,r0
	mtpr	r0,$TBIS		# tbiscl(v); 
	tstl	r2
	jeql	2f			# if (type == CTEXT) 
D 103
	pushl	r4
	pushl	r3
	pushl	P_TEXTP(r5)		#	distpte(p->p_textp,
	calls	$3,_distpte		#	    vtotp(p, v), pte); 
E 103
I 103
	movl	P_TEXTP(r5),r0
	movl	X_CADDR(r0),r5		# for (p = p->p_textp->x_caddr; p; ) {
	jeql	2f
	ashl	$2,r3,r3
3:
	addl3	P_P0BR(r5),r3,r0	#	tpte = tptopte(p, tp);
	bisb2	$1,P_FLAG+3(r5)		#	p->p_flag |= SPTECHG;
	movl	(r4),(r0)+		#	for (i = 0; i < CLSIZE; i++)
	movl	4(r4),(r0)		#		tpte[i] = pte[i];
	movl	P_XLINK(r5),r5		#	p = p->p_xlink;
	jneq	3b			# }
E 103
2:					# collect a few statistics...
D 110
	incl	_cnt+V_FAULTS		# cnt.v_faults++; 
E 110
	incl	_u+U_RU+RU_MINFLT	# u.u_ru.ru_minflt++;
D 110
	incl	_cnt+V_PGREC		# cnt.v_pgrec++;
	incl	_cnt+V_FASTPGREC	# cnt.v_fastpgrec++;
	incl	_cnt+V_TRAP		# cnt.v_trap++;
E 110
I 110
	moval	_cnt,r0
	incl	V_FAULTS(r0)		# cnt.v_faults++; 
	incl	V_PGREC(r0)		# cnt.v_pgrec++;
	incl	V_FASTPGREC(r0)		# cnt.v_fastpgrec++;
	incl	V_TRAP(r0)		# cnt.v_trap++;
E 110
	POPR
	addl2	$8,sp			# pop pc, code
	mtpr	$HIGH,$IPL		## dont go to a higher IPL (GROT)
	rei
E 99
D 37

D 20
#
# unsigned int divide:
#	(int) i = udiv( (int)dvdnd , (int) divis)
#
#  unsigned int remainder:
#	(int) j = urem( (int)dvdnd , (int) divis)
#
	.text
	.align	1
	.globl	_udiv
_udiv :
	.word	0  			# no reg save
	movl	4(ap),r0  		# dividend
	clrl	r1
	ediv	8(ap),r0,r0,r1  	# quotient in r0
	ret

#	.globl	_urem
#	.align 	1
#_urem:
#	.word	0
#	movl	4(ap),r0
#	clrl	r1
#	ediv	8(ap),r0,r1,r0  	#  remainder in r0
#	ret

E 20
D 22
# ==============
# Error messages
# ==============
E 22
I 22
/*
 * Error messages
 */ 
E 22

	.data
I 18
D 35
SBIflt:	.asciz	"UBA SBI Fault SR %X CNFGR %X\n"
E 35
I 35
SBIflt:	.asciz	"UBA SBI Fault SR %x CNFGR %x\n"
E 35
E 18
D 22
SBImsg: .asciz	"SBI fault\n"
E 22
D 18
UBAmsg: .asciz	"UBA error UBASR %X, FMER %X, FUBAR %X\n"
E 18
I 18
D 20
UBAmsg: .asciz	"UBA error SR %x, FMER %x, FUBAR %o\n"
E 18
straym: .asciz	"Stray Interrupt\n"
E 20
I 20
UBAmsg:	.asciz	"UBA error SR %x, FMER %x, FUBAR %o\n"
straym:	.asciz	"Stray Interrupt\n"
E 20
I 7
ZERmsg:	.asciz	"ZERO VECTOR "
I 23
D 35
wtime:	.asciz	"write timeout %X\n"
E 35
I 35
wtime:	.asciz	"write timeout %x\n"
E 35
I 27
mbasmsg:.asciz	"stray interrupt mba %d\n"
E 27
E 23
E 7

D 22
#
# Junk.
#
D 13

# these should be memall'ed
	.data
	.globl _buffers
	.align  PGSHIFT
_buffers:	.space NBUF*BSIZE
E 13

#
# This is needed when running old-style switch code.
# Be sure to enable setting of idleflag in interrupt code above also.
#
#_idle:	.globl	_idle
#	.word	0x0000
#	mtpr	$0,$IPL			# enable interrupts
#waitloc:
#	blbc	idleflag,waitloc	# loop until interrupt
#ewaitloc:
#	bbcci	$0,idleflag,idle1	# clear idle escape flag
#idle1:
#	ret
#	.data
#	.globl	_waitloc
#	.globl	_ewaitloc
D 14
#	.align	2
E 14
I 14
#l	.align	2
E 14
#_waitloc:	.long	waitloc
#_ewaitloc:	.long	ewaitloc
#idleflag:	.long	0
#	.text

E 22
I 22
#if VAX==750
UBAstraym: .asciz "Stray UBA Interrupt\n"
#endif
E 37
E 22
E 1
