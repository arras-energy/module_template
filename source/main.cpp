// External module for GridLAB-D
// Copyright (C) 2023 Regents of Leland Stanford Junior University

#define DLMAIN

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#include "gridlabd.h"

// TODO: include all the class header files here
#include "myclass.h"

// TODO: declare module globals here
char1024 my_module_global = "a default value";

EXPORT CLASS *init(CALLBACKS *fntable, MODULE *module, int argc, char *argv[])
{
    if (set_callback(fntable)==NULL)
    {
        errno = EINVAL;
        return NULL;
    }

    INIT_MMF(consumer);

    // TODO: construct the module's classes here
    new myclass(module);

    // TODO: publish any module globals here
    gl_global_create("module_template::my_module_global",PT_char1024,(const char*)my_module_global,NULL);

    // TODO: always return the first class registered
    return myclass::oclass;
}


EXPORT int do_kill(void*)
{
    // TODO: free global memory (if any)
    return 0;
}

EXPORT int check()
{
    // TODO: run module checks (if any)
    return 0;
}
