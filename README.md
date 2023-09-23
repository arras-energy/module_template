[![validate](https://github.com/arras-energy/module_template/actions/workflows/validate.yml/badge.svg)](https://github.com/arras-energy/module_template/actions/workflows/validate.yml)

# Prerequisites

You must install the development version of HiPAS GridLAB-D. To verify you have the right version use the `make status` target:

~~~
make status
~~~

This should output the current `gridlabd` system installation, e.g.,

~~~
GLD version....... HiPAS GridLAB-D 4.3.3-230731
GLD source........ /usr/local/opt/gridlabd/4.3.3-230731-develop-darwin_22-x86_64/src
Github branch..... develop
GLD libraries..... /usr/local/opt/gridlabd/4.3.3-230731-develop-darwin_22-x86_64/lib/gridlabd
OS release........ Darwin 22.4.0
~~~

# Build and Install

To build and install the module, open a GridLAB-D shell and `install` make target

~~~
gridlabd shell
cd source
make install
~~~

You can verify the module installation using the command `make check` or `gridlabd -L MODULENAME`.
