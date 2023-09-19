// myclass.h

#ifndef _MYCLASS_H
#define _MYCLASS_H

class myclass : public gld_object {
public:
    GL_ATOMIC(double,my_property);

public:
    /* required implementations */
    myclass(MODULE *module);
    int create(void);
    int init(OBJECT *parent);
    TIMESTAMP commit(TIMESTAMP t1, TIMESTAMP t2);

public:
    static CLASS *oclass;
    static myclass *defaults;
};

#endif // _MYCLASS_H
