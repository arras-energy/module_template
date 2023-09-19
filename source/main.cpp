// Consumer module for GridLAB-D
// Copyright (C) 2023 Regents of Leland Stanford Junior University

#define DLMAIN

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#include "gridlabd.h"
#include "consumer.h"

EXPORT CLASS *init(CALLBACKS *fntable, MODULE *module, int argc, char *argv[])
{
    if (set_callback(fntable)==NULL)
    {
        errno = EINVAL;
        return NULL;
    }

    INIT_MMF(consumer);

    new consumer(module);

    /* always return the first class registered */
    return consumer::oclass;
}


EXPORT int do_kill(void*)
{
    /* if global memory needs to be released, this is a good time to do it */
    return 0;
}

EXPORT int check()
{
    /* if any objects have bad filenames, they'll fail on init() */
    return 0;
}
