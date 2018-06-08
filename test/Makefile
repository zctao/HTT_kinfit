################################################################################
#
# Makefile to compile and link C programs
#
# Version valid for Linux machines
#
# "make" compiles and links the specified main programs and modules
# using the specified libraries (if any), and produces the executables
#
# "make clean" removes all files created by "make"
#
# Dependencies on included files are automatically taken care of
#
################################################################################

all: rmxeq mkdep mkxeq
.PHONY: all

GCC = g++

# main programs and required modules
MAIN =  call_HTT
MODULES = HadTopKinFit

# search path for modules

MDIR = ./

# root
#ROOTINCS = $(shell /afs/cern.ch/sw/lcg/app/releases/ROOT/5.28.00/slc4_amd64_gcc34/root/bin/root-config --cflags)
#ROOTLIBS = $(shell /afs/cern.ch/sw/lcg/app/releases/ROOT/5.28.00/slc4_amd64_gcc34/root/bin/root-config --glibs)

# root
ROOTINCS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --glibs)

# gsl
#GSLINCS = $(shell /afs/cern.ch/sw/lcg/external/GSL/1.10/x86_64-slc5-gcc34-opt/bin/gsl-config --cflags)
#GSLLIBS = $(shell /afs/cern.ch/sw/lcg/external/GSL/1.10/x86_64-slc5-gcc34-opt/bin/gsl-config --libs)

# gsl
GSLINCS = $(shell gsl-config --cflags)
GSLLIBS = $(shell gsl-config --libs)


# scheduling and optimization options (such as -DSSE -DSSE2 -DP4)
CFLAGS = -ansi -O3 -Wall

# additional include directories
INCPATH = -I../include $(ROOTINCS) $(GSLINCS)

# additional libraries to be included
LIBS =  $(ROOTLIBS) $(GSLLIBS)  -lGenVector

############################## do not change ###################################

SHELL=/bin/bash

CC=$(GCC)

PGMS= $(MAIN) $(MODULES)

INCDIRS = $(INCPATH)

OBJECTS = $(addsuffix .o,$(MODULES))

LDFLAGS = $(LIBS)

-include $(addsuffix .d,$(PGMS))

# rule to make dependencies

$(addsuffix .d,$(PGMS)): %.d: %.cc Makefile
	@ $(CC) -MM -ansi $(INCDIRS) $< -o $@


# rule to compile source programs

$(addsuffix .o,$(PGMS)): %.o: %.cc Makefile
	$(CC) $< -c $(CFLAGS) $(INCDIRS) -o $@


# rule to link object files

$(MAIN): %: %.o $(OBJECTS) Makefile
	$(CC) $< $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o $@


# produce executables

mkxeq: $(MAIN)


# remove old executables and old error log file

rmxeq:
	@ -rm -f $(MAIN); \
	echo "delete old executables"


# make dependencies

mkdep:  $(addsuffix .d,$(PGMS))
	@ echo "generate tables of dependencies"


# clean directory

clean:
	@ -rm -rf *.d *.o *~ $(MAIN) *.eps *.data plots/*~ plots/*.eps *.a analysis/*~ analysis/*.eps
.PHONY: clean
