
Debian
====================
This directory contains files used to package jobecoind/jobecoin-qt
for Debian-based Linux systems. If you compile jobecoind/jobecoin-qt yourself, there are some useful files here.

## jobecoin: URI support ##


jobecoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install jobecoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your jobecoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/jobecoin128.png` to `/usr/share/pixmaps`

jobecoin-qt.protocol (KDE)

