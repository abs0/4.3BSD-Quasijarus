# 4.3BSD-Quasijarus
Unofficial 4.3BSD-Quasijarus repository to easily track changes from 0 through to 0c, plus the qjsrc-se53pra0 changes

This is intended to provide easy access to the source from the original 4.3BSD Quasijarus, and to provide a base for any patches if desired.

For each release (and the qjsrc-se53pra0 changes)
* src.tar.Z and syssrc.tar.Z have been extracted into . and ./sys respectively
* files.txt contains the files and timestamps from the two tarfiles
* If the release had a setup.txt and qjchanges.txt they have been copied in
* The commit message is the original release notes
* An appropriate tag has been created

For more details on 4.3BSD Quasijarus please see http://gunkies.org/wiki/4.3_BSD_Quasijarus

Please note that this repository contains files that differ only
in case (eg astoks.h and astoks.H), so you will need to clone onto
a case sensitive filesystem.
