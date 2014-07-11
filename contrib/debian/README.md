
Debian
====================
This directory contains files used to package yescoind/yescoin-qt
for Debian-based Linux systems. If you compile yescoind/yescoin-qt yourself, there are some useful files here.

## yescoin: URI support ##


yescoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install yescoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your yescoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/yescoin128.png` to `/usr/share/pixmaps`

yescoin-qt.protocol (KDE)

