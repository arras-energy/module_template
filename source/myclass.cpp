// myclass.cpp

#include "gridlabd.h"
#include "myclass.h"

// TODO: choose optional declarations
EXPORT_PRECOMMIT(myclass);
EXPORT_SYNC(myclass);
EXPORT_COMMIT(myclass);
EXPORT_FINALIZE(myclass);

// TODO: initialize any class globals
char1024 myclass::my_class_global = "a default value";

// TODO: specify the class configuration
static unsigned long long class_config = 0x00
    | PC_AUTOLOCK // TODO: specify AUTOLOCK when publishing properties (almost always needed)
    | PC_OBSERVER // TODO: specify OBSERVER when subscribing to other object's properties (almost always needed)
    | PC_PRETOPDOWN // TODO: only specify PRETOPDOWN when using presync()
    | PC_BOTTOMUP // TODO: only specify BOTTOMUP when using sync()
    | PC_POSTTOPDOWN; // TODO: only specify POSTDOWNDOWN when using postsync()

// required declarations
EXPORT_CREATE(myclass);
EXPORT_INIT(myclass);
CLASS *myclass::oclass = NULL;
myclass *myclass::defaults = NULL;

myclass::myclass(MODULE *module)
{
    if (oclass==NULL)
    {
        oclass = gld_class::create(module,"myclass",sizeof(myclass),class_config);
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
            
            // TODO: publish all the public properties
            PT_double, "my_double[unit]", get_my_double_offset(),
                // TODO: specify property options
                PT_DEFAULT, "0 unit", // TODO: specify a default value when it is not defined in the model
                PT_REQUIRED, // TODO: indicates the value must be provided in the model
                PT_OUTPUT, // TODO: indicates the value is updated by this class
                PT_DESCRIPTION, "a double property of myclass", // TODO: provide brief help text
            PT_complex, "my_complex[unit]", get_my_complex_offset(),
                // TODO: specify property options
            PT_char8, "my_char8", get_my_char8_offset(),
                // TODO: specify property options
            PT_char32, "my_char32", get_my_char32_offset(),
                // TODO: specify property options
            PT_char256, "my_char256", get_my_char256_offset(),
                // TODO: specify property options
            PT_char1024, "my_char1024", get_my_char1024_offset(),
                // TODO: specify property options
            PT_object, "my_object", get_my_object_offset(),
                // TODO: specify property options

            NULL)<1)
        {
                throw "unable to public myclass properties";
        }

        // TODO: public globals (if any)
        gl_global_create("module_template::my_class_global",PT_char1024,(const char*)my_class_global,NULL);
    }
}

int myclass::create(void) 
{
    // TODO: set any values needed before the object properties are defined
    return 1; /* return 1 on success, 0 on failure */
}

int myclass::init(OBJECT *parent)
{
    // TODO: check defined properties and finish initialization
    //       return 0 on failure
    //       return 1 on success
    //       return 2 to defer success and try again later (.e.g, depends on another object yet to initialize)
    return 1;
}

TIMESTAMP myclass::precommit(TIMESTAMP t1)
{
    // TODO: called once each time the clock is going to advanced to t1
    //       return TS_INVALID to indicate an error
    //       return TIMESTAMP to indicate clock should advance
    //       return TS_NEVER to indicate steady state
    return TS_NEVER; 
}

TIMESTAMP myclass::presync(TIMESTAMP t1)
{
    // TODO: called once each for each pre-topdown sync pass
    //       return TS_INVALID to indicate an error
    //       return TIMESTAMP to indicate clock should advance
    //       return TS_NEVER to indicate steady state
    //       return t1 to indicate sync iteration is required
    return TS_NEVER;
}

TIMESTAMP myclass::sync(TIMESTAMP t1)
{
    // TODO: called once each for each bottom-up sync pass
    //       return TS_INVALID to indicate an error
    //       return TIMESTAMP to indicate clock should advance
    //       return TS_NEVER to indicate steady state
    //       return t1 to indicate sync iteration is required
    return TS_NEVER;
}

TIMESTAMP myclass::postsync(TIMESTAMP t1)
{
    // TODO: called once each for each post-topdown sync pass
    //       return TS_INVALID to indicate an error
    //       return TIMESTAMP to indicate clock should advance
    //       return TS_NEVER to indicate steady state
    //       return t1 to indicate sync iteration is required
    return TS_NEVER;
}

TIMESTAMP myclass::commit(TIMESTAMP t0, TIMESTAMP t1)
{
    // TODO: called once after all sync passes advanced the clock
    //       return TS_INVALID to indicate an error
    //       return TIMESTAMP to indicate clock should advance
    //       return TS_NEVER to indicate steady state
    return TS_NEVER;
}

TIMESTAMP myclass::finalize(void)
{
    // TODO: called once after the clock stops
    //       return TS_INVALID to indicate an error
    //       return TS_NEVER to indicate steady state
    return TS_NEVER;
}
