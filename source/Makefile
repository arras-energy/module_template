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
	eval $(foreach F,$(SOURCE_FILES),gcc -fPIC -I'$(GLD_INC)/gridlabd' $(CPPFLAGS) -DHAVE_CONFIG_H -c $F -o $(subst .cpp,.o,$F);) 
	gcc --shared $(LDFLAGS) $(OBJECT_FILES) -lstdc++ -lm -lc -o $@

%.o: %.cpp $(HEADER_FILES)
	echo Compiling $<...
	libtool --quiet --tag=CXX --mode=compile gcc -g -I'$(GLD_INC)/gridlabd' $(CPPFLAGS) -DHAVE_CONFIG_H -O -c $<

status:
	test -x '$(shell which gridlabd)' || ( echo "ERROR [make]: you must install gridlabd in the system" >/dev/stderr && false)
	test -d '$(GLD_INC)/gridlabd' || ( echo "ERROR [make]: you must make in a gridlabd shell" >/dev/stderr && false)
	test -f '$(GLD_INC)/gridlabd/build.h' || ( echo "ERROR [make]: the system gridlabd install does not include build headers $(GLD_INC)" >/dev/stderr && false)
	echo GLD version....... '$(shell gridlabd --version=all 2>/dev/null)'
	echo GLD include....... '$(GLD_INC)'
	echo GLD libraries..... '$(GLD_LIB)'

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
