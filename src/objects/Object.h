#ifndef OBJECTS_OBJECT_H_
#define OBJECTS_OBJECT_H_

#define CUBE_OBJECT 1
#define CIRCLE_OBJECT 2

#include <glm/glm.hpp>

using namespace glm;

class Object {
    int type = 0;

public:
    vec2 pos = vec2(0);
    float size = 128;
    Object(int t){
        type = t;
    };
    Object(int t, vec2 p){
        type = t;
        pos = p;
    };
    // ~Object();
    bool is_cube() {
        if (type == 1) return true;
    };

    bool is_circle() {
        if (type == 2) return true;
    };

    int get_type(){
        return type;
    };
};

#endif /* OBJECTS_OBJECT_H_ */
