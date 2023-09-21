[![validate](https://github.com/arras-energy/module_template/actions/workflows/validate.yml/badge.svg)](https://github.com/arras-energy/module_template/actions/workflows/validate.yml)

# Prerequisites

You must install HiPAS GridLAB-D as follows:

~~~
git clone https://arras.energy/gridlabd -b develop
cd gridlabd
./build.sh --clean --parallel --system
~~~

Then you must link your source code to the installed system source using the following command:
~~~
ln -sf $PWD $(gridlabd --printenv | grep GLD_SRC | cut -f2 -d=)
~~~

You can verify that this worked using the command in the module's source folder (not the `gridlabd` source folder):

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

To build and install the module, use the `make` and `make install` commands. You can verify the module installation using the command `make check` or `gridlabd -L MODULENAME`.

