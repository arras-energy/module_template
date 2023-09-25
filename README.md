[![validate](https://github.com/arras-energy/module_template/actions/workflows/validate.yml/badge.svg)](https://github.com/arras-energy/module_template/actions/workflows/validate.yml)

# Prerequisites

To develop a new module, you must install the development version of HiPAS GridLAB-D. To verify you have the right version use the `make status` target:

~~~
make status
~~~

This should output the current `gridlabd` system installation, e.g.,

~~~
GLD version....... HiPAS GridLAB-D 4.3.3-230922 (develop) Darwin
GLD include....... /usr/local/opt/gridlabd/4.3.3-230922-develop-darwin_22-x86_64/include
GLD libraries..... /usr/local/opt/gridlabd/4.3.3-230922-develop-darwin_22-x86_64/lib/gridlabd
~~~

# User install 

Users do not need to install the development of GridLAB-D, provided you are using version 4.3.3 or later. Users should can a module using the `gridlabd install` tool, e.g.,

~~~
gridlabd install MODULENAME
~~~

# Developer build and install

To build and install the module, open a GridLAB-D shell and `install` make target

~~~
git clone https://github.com/arras-energy/module_MODULENAME
cd module_MODULENAME
gridlabd shell
cd source
make install
~~~

You can verify the module installation using the command `make check` or `gridlabd -L MODULENAME`.

After you commit your code to a branch, you can test the install using the command

~~~
gridlabd install --branch=BRANCH MODULENAME
~~~
