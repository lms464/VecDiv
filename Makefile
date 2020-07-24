VERSION=1.0
TCLINC=/usr/include/tcl
# Change this to point to your local VMD installation!
PLUGINDIR=${HOME}/local/vmd-1.9.4/vmd/plugins/LINUXAMD64/tcl

CPP=g++
#CPPFLAGS=-fpic -g -I${TCLINC}
CPPFLAGS=-fpic -O3 -I${TCLINC} -Wall
# LIBS=-Wl,-Bstatic -lfftw -Wl,-Bdynamic
#LIBS=-lfftw3f

all: vecdiv.so pkgIndex.tcl vecdiv.tar.gz

# vecdiv: vecdiv.cpp 
# 	$(CPP) -g -O3 vecdiv.cpp -o vecdiv #$(LIBS)

vecdiv.so: vecdiv.o
	$(CPP) -shared vecdiv.o -o vecdiv.so #$(LIBS)

vecdiv.tar.gz: vecdiv.cpp Makefile
	tar czf vecdiv${VERSION}.tar.gz vecdiv.cpp Makefile pkgIndex.tcl

pkgIndex.tcl: vecdiv.so
	tclsh mkindex.tcl

clean:
	rm *.o *.so *.tar.gz

install: all
	mkdir -p ${PLUGINDIR}/vecdiv${VERSION} && \
		rsync -av vecdiv.so pkgIndex.tcl ${PLUGINDIR}/vecdiv${VERSION}/. 