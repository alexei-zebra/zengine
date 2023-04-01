#ifndef OBJECTS_OBJECTS_H_
#define OBJECTS_OBJECTS_H_

#include "Object.h"

class Objects {
    Object** objects = new Object*[255];
    int len = 0;

public:
    // Objects();
    // ~Objects();

    void add_object(Object* obj);
    void set_object(Object* obj,int i);
    Object* get_object(int i);
    void delete_object(int i);
    int get_len();
};

#endif /* OBJECTS_OBJECTS_H_ */
