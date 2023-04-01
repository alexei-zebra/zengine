#ifndef OBJECTS_CIRCLE_H_
#define OBJECTS_CIRCLE_H_

#include "Object.h"

using namespace glm;

class Circle: public Object {
    int type = 2;

public:
    bool is_circle() {
        return true;
    };

};

#endif /* OBJECTS_CIRCLE_H_ */
