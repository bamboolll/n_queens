************************************************

		Eight Queens

************************************************

A small program for toying around with the 8-queen problem (or nxn queens). This source package is platform-independent and should compile on any platform supported by Qt. I've created and tested the Windows installer on Windows XP, but I supposed it will also run on any 32bit windows platform supported by Qt-4.6. If you want it to run on a 64bit system you have to
compile it yourself since I don't have such a platform at my disposal.


====================
Changelog:
====================

-------
0.3.4
-------
- Very substantial performance boost

-------
0.3.3
-------
- Fixed a compatibility issue that hindered the code to compile against Qt-4.5.x.

-------
0.3.2
-------
- Using Three Leds to tell the user whether a solution has been found, a solution might still be possible, or no solution possible anymore.
- Introduced toolbar & icons for the menu/toolbar entries.

-------
0.3.1
-------
- Performance improvements.
- Solutions listed in a table now.

-------
0.3.0
-------
- Searching for solutions happens in a separate thread thus keeping the main window responsive.

-------
0.2.1
-------
- You can now decide whether or not the blocked fields are marked with a cross or not using
  tools > Mark Blocked Fields.
- The new version can also be compiled with Qt-4.5.x. The windows and Mac OS X binaries are built  using Qt-4.6.1 and it is recommended you use this or a newer version.


====================
License:
====================

All code except the qled.h qled.cpp and the associated resources in the resources subdirectory are licensed under GPL3. The qled code (http://qt-apps.org/content/show.php/QLed+?content=72482) is thirdparty code licensed under GPL2.
