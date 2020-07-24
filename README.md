# VecDiv

TCL used in VMD has various vec commands. It did not have a vecdiv (and inverse of the vecmul). While not nesisarily the most useful, it's an atempt to get my feet wet in expanding my coding.

    vecdiv {1.0 2.0 3.0} {2.0 2.0 2.0}
    0.5 1.0 1.5

This script needs further clean up!

To build;

	$ tar xf qwrap.tar.gz
	# update the PLUGINDIR var in Makefile
	$ make
	$ make install

*Note*: I have not fixed the load path, it will need to be called from the the local vmd/plugins director