// myclass.h

#ifndef _MYCLASS_H
#define _MYCLASS_H

class myclass : public gld_object 
{

public:

    // TODO: define the published properties of objects
    GL_ATOMIC(double,my_double);
    GL_ATOMIC(complex,my_complex);
    GL_ATOMIC(bool,my_bool);
    GL_STRING(char8,my_char8);
    GL_STRING(char32,my_char32);
    GL_STRING(char256,my_char256);
    GL_STRING(char1024,my_char1024);
    GL_ATOMIC(object,my_object);

public:

    // TODO: define any global variables
    static char1024 my_class_global;

public:

    // required methods
    myclass(MODULE *module);
    int create(void);
    int init(OBJECT *parent);

public:

    // optional methods
    TIMESTAMP precommit(TIMESTAMP t1);
    TIMESTAMP presync(TIMESTAMP t1);
    TIMESTAMP sync(TIMESTAMP t1);
    TIMESTAMP postsync(TIMESTAMP t1);
    TIMESTAMP commit(TIMESTAMP t0, TIMESTAMP t1);
    TIMESTAMP finalize(void);

public:

    // required static members
    static CLASS *oclass;
    static myclass *defaults;

};

#endif // _MYCLASS_H
