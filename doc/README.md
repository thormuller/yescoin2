Yescoin 0.9.99 BETA
=====================

Copyright (c) 2009-2014 Yescoin Developers


Setup
---------------------
[Yescoin Core](http://yescoin.org/en/download) is the original Yescoin client and it builds the backbone of the network. However, it downloads and stores the entire history of Yescoin transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once. If you would like the process to go faster you can [download the blockchain directly](bootstrap.md).

Running
---------------------
The following are some helpful notes on how to run Yescoin on your native platform. 

### Unix

You need the Qt4 run-time libraries to run Yescoin-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/yescoin-qt (GUI, 32-bit) or bin/32/yescoind (headless, 32-bit)
- bin/64/yescoin-qt (GUI, 64-bit) or bin/64/yescoind (headless, 64-bit)



### Windows

Unpack the files into a directory, and then run yescoin-qt.exe.

### OSX

Drag Yescoin-Qt to your applications folder, and then run Yescoin-Qt.

### Need Help?

* See the documentation at the [Yescoin Wiki](https://en.yescoin.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#yescoin](http://webchat.freenode.net?channels=yescoin) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=yescoin).
* Ask for help on the [YescoinTalk](https://yescointalk.org/) forums, in the [Technical Support board](https://yescointalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build Yescoin on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-msw.md)

Development
---------------------
The Yescoin repo's [root README](https://github.com/yescoin/yescoin/blob/master/README.md) contains relevant information on the development process and automated testing.

- [Coding Guidelines](coding.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/yescoin/doxygen/)
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)

### Resources
* Discuss on the [YescoinTalk](https://yescointalk.org/) forums, in the [Development & Technical Discussion board](https://yescointalk.org/index.php?board=6.0).
* Discuss on [#yescoin-dev](http://webchat.freenode.net/?channels=yescoin) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=yescoin-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](http://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
