#include "Draw-Object.h"

DrawObject::DrawObject(Primitives* p, Texture* c){
    prim = p;
    circ = c;
}

void DrawObject::draw_cube(Object* cube){
    prim->begin();
    prim->rect(cube->pos.x, cube->pos.y, cube->size, cube->size);
}

void DrawObject::draw_circle(Object* circle){
    prim->texture(circ);
    prim->circle(circle->pos.x, circle->pos.y, circle->size, circle->size);
    prim->begin();
}

void DrawObject::draw_object(Object* obj){
    if (obj->get_type() == 1) draw_cube(obj);
    else draw_circle(obj);
}