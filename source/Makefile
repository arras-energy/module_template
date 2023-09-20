# Module build and install

.NOTPARALLEL: status

.SILENT:

MODULE_NAME = $(subst module_,,$(notdir $(abspath $(PWD)/..)))
SOURCE_FILES = $(wildcard *.cpp)
HEADER_FILES = $(wildcard *.h)

SHARED_FILES = $(subst .cpp,.lo,$(SOURCE_FILES))
OBJECT_FILES = $(subst .cpp,.o,$(SOURCE_FILES))

all: status lib$(MODULE_NAME).la lib$(MODULE_NAME).a lib$(MODULE_NAME).so

lib$(MODULE_NAME).a: $(OBJECT_FILES) 
	echo Creating $@...
	libtool --quiet --tag=CXX --mode=link gcc -o $@ $(SHARED_FILES)

lib$(MODULE_NAME).la: $(OBJECT_FILES) 
	echo Creating $@...
	libtool --quiet --tag=CXX --mode=link gcc --shared $(LDFLAGS) -lpython$(PYTHON_VER) -lstdc++ -lm -lc -o $@ $(SHARED_FILES) -rpath=$(GLD_LIB)

lib$(MODULE_NAME).so: $(SOURCE_FILES) 
	echo Creating $@...
	eval $(foreach F,$(SOURCE_FILES),gcc -fPIC -I$(GLD_SRC)/source -I$(GLD_SRC)/python $(CPPFLAGS) -DHAVE_CONFIG_H -c $F -o $(subst .cpp,.o,$F);) 
	gcc --shared $(LDFLAGS) $(OBJECT_FILES) -lstdc++ -lm -lc -o $@

%.o: %.cpp $(HEADER_FILES)
	echo Compiling $<...
	libtool --quiet --tag=CXX --mode=compile gcc -g -I$(GLD_SRC)/source -I$(GLD_SRC)/python $(CPPFLAGS) -DHAVE_CONFIG_H -O -c $<

status:
	test -d '$(GLD_SRC)' || ( echo "ERROR [make]: you must build in the current gridlabd shell" >/dev/stderr && false )
	test -f '$(GLD_SRC)/source/gridlabd.h' || ( echo "ERROR [make]: gridlabd source must be found at $(GLD_SRC)" >/dev/stderr && false )
	test -f '$(GLD_SRC)/source/build.h' || ( echo "ERROR [make]: you must first build gridlabd in $(GLD_SRC)" >/dev/stderr && false)
	test ! -z '$(shell gridlabd.bin --version=name 2>/dev/null)' || ( echo "ERROR [make]: you must install gridlabd in the system" >/dev/stderr && false)
	echo GLD version....... $(shell gridlabd.bin --version 2>/dev/null)
	echo GLD source........ $(GLD_SRC)
	echo Github branch..... $(shell gridlabd.bin --version=branch 2>/dev/null)
	echo GLD libraries..... $(GLD_LIB)
	echo OS release........ $(shell gridlabd.bin --version=release 2>/dev/null)

clean:
	rm -rf .libs
	rm -f $(OBJECT_FILES)
	rm -f $(SHARED_FILES)
	rm -f lib$(MODULE_NAME).{a,la,so}

$(GLD_LIB)/%: lib%
	echo Installing $@...
	cp $< $@
	chmod 755 $@

check: 
	gridlabd.bin -L $(MODULE_NAME) 2>/dev/null || ( echo "ERROR [make]: $(MODULE_NAME) install failed" && false )

install: all $(GLD_LIB)/$(MODULE_NAME).la $(GLD_LIB)/$(MODULE_NAME).a $(GLD_LIB)/$(MODULE_NAME).so check
	echo "Module $(MODULE_NAME) installed ok"