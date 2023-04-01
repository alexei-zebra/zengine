#ifndef OBJECTS_CUBE_H_
#define OBJECTS_CUBE_H_

#include "Object.h"

using namespace glm;

class Cube: public Object {
    int type = 1;

public:
    bool is_cube() {
        return true;
    };

};

#endif /* OBJECTS_CUBE_H_ */
