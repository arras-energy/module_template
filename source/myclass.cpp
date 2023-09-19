// myclass.cpp

#include "gridlabd.h"
#include "myclass.h"

EXPORT_CREATE_C(myclass,myclass);
EXPORT_INIT_C(myclass,myclass);
EXPORT_COMMIT_C(myclass,myclass);

CLASS *myclass::oclass = NULL;
myclass *myclass::defaults = NULL;

myclass::myclass(MODULE *module)
{
    if (oclass==NULL)
    {
        // register to receive notice for first top down. bottom up, and second top down synchronizations
        oclass = gld_class::create(module,"myclass",sizeof(myclass),PC_AUTOLOCK|PC_OBSERVER);
        if (oclass==NULL)
        {
            throw "unable to register class myclass";
        }
        else
        {
            oclass->trl = TRL_UNKNOWN;
        }

        defaults = this;
        if (gl_publish_variable(oclass,
            
            PT_double, "my_property[unit]", get_my_property_offset(),
                PT_DESCRIPTION, "a property of myclass",
                
            NULL)<1)
        {
                throw "unable to public myclass properties";
        }
    }
}

int myclass::create(void) 
{
    // TODO
    return 1; /* return 1 on success, 0 on failure */
}

int myclass::init(OBJECT *parent)
{
    // TODO
    return 1;
}

TIMESTAMP myclass::commit(TIMESTAMP t1, TIMESTAMP t2)
{
    // TODO
    return TS_NEVER;
}
