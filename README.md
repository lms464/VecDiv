# VecDiv

## Now redundant! Curret vector math functions kn VMD support essentially this

TCL used in VMD has various vec commands. It did not have a vecdiv (a inverse of the vecmul). While not nesisarily the most useful, it's an atempt to get my feet wet in expanding my coding.

    vecdiv {1.0 2.0 3.0} {2.0 2.0 2.0}
    0.5 1.0 1.5

This script needs further clean up!

To build;

	$ tar xf qwrap.tar.gz
	# update the PLUGINDIR var in Makefile
	$ make
	$ make install

*Note*: 
1. More testing is required. This will work with lists produced from atomselect commands
2. I have not fixed the load path, it will need to be called from the the local local/vmd-1.9.X/vmd/plugins/LINUXAMD64/tcl/vecdiv1.0/ directory
3. The _lrepeat_ function is not compatable with vecdiv, I am unsure why at this time
4. Most of this code is based on https://stackoverflow.com/questions/10832265/tcl-api-how-to-get-a-list-from-tcl and https://github.com/jhenin/qwrap !