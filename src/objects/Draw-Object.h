#ifndef OBJECTS_DRAWOBJECT_H_
#define OBJECTS_DRAWOBJECT_H_

#include <glm/glm.hpp>
#include "Object.h"
#include "../graphics/Primitives.h"

using namespace glm;

class DrawObject {
    vec3 color;
    Primitives* prim;
    Texture* circ;
public:
    DrawObject(Primitives* p, Texture* c);
    void draw_cube(Object* cube);
    void draw_circle(Object* circle);
    void draw_object(Object* obj);
};

#endif /* OBJECTS_DRAWOBJECT_H_ */
