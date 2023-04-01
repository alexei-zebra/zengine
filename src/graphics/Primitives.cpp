#include "Primitives.h"
#include "Mesh.h"
#include "Texture.h"

#include <GL/glew.h>

#define VERTEX_SIZE 8

Primitives::Primitives(size_t capacity) : capacity(capacity), offset(0), color(1.0f, 1.0f, 1.0f, 1.0f){
    const int attrs[] = {
        2, 2, 4, 0 //null terminator
    };

    buffer = new float[capacity * VERTEX_SIZE];
    mesh = new Mesh(buffer, 0, attrs);
    index = 0;

    unsigned char pixels[] = {
        255, 255, 255, 255,
    };
    blank = new Texture(pixels, 1, 1);
    _texture = nullptr;
}

Primitives::~Primitives(){
    delete blank;
    delete[] buffer;
    delete mesh;
}

void Primitives::begin(){
    _texture = nullptr;
    blank->bind();
}

void Primitives::vertex(float x, float y,
        float u, float v,
        float r, float g, float b, float a) {
    buffer[index++] = x;
    buffer[index++] = y;
    buffer[index++] = u;
    buffer[index++] = v;
    buffer[index++] = r;
    buffer[index++] = g;
    buffer[index++] = b;
    buffer[index++] = a;
}

void Primitives::vertex(vec2 point,
        vec2 uvpoint,
        float r, float g, float b, float a) {
    buffer[index++] = point.x;
    buffer[index++] = point.y;
    buffer[index++] = uvpoint.x;
    buffer[index++] = uvpoint.y;
    buffer[index++] = r;
    buffer[index++] = g;
    buffer[index++] = b;
    buffer[index++] = a;
}

void Primitives::texture(Texture* new_texture){
    if (_texture == new_texture)
        return;
    render(GL_TRIANGLES);
    _texture = new_texture;
    if (new_texture == nullptr)
        blank->bind();
    else
        new_texture->bind();
}

void Primitives::point(float x, float y, float r, float g, float b, float a){
    vertex(x, y, 0, 0, r,g,b,a);
    render(GL_POINTS);
}

void Primitives::linec(float x1, float y1, float x2, float y2, float r, float g, float b, float a){
    vertex(x1, y1, 0, 0, r,g,b,a);
    vertex(x2, y2, 1, 1, r,g,b,a);
    render(GL_LINES);
}
void Primitives::line(float x1, float y1, float x2, float y2){
    const float r = color.r;
    const float g = color.g;
    const float b = color.b;
    const float a = color.a;
    vertex(x1, y1, 0, 0, r,g,b,a);
    vertex(x2, y2, 1, 1, r,g,b,a);
    render(GL_LINES);
}

void Primitives::rectc(float x, float y, float w, float h, float r, float g, float b, float a){
    w /= 2;
    h /= 2;

    vertex(x-w, y-h, 0, 0, r,g,b,a);
    vertex(x-w, y+h, 0, 1, r,g,b,a);
    vertex(x+w, y+h, 1, 1, r,g,b,a);

    vertex(x-w, y-h, 0, 0, r,g,b,a);
    vertex(x+w, y+h, 1, 1, r,g,b,a);
    vertex(x+w, y-h, 1, 0, r,g,b,a);
    render(GL_TRIANGLES);
}
void Primitives::rectw(float x, float y, float w, float h, float r, float g, float b, float a){
    w /= 2;
    h /= 2;

    linec(x-w, y-h, x+w, y-h, r, g, b, a);
    linec(x-w, y-h, x-w, y+h, r, g, b, a);
    linec(x+w, y+h, x+w, y-h, r, g, b, a);
    linec(x+w, y+h, x-w, y+h, r, g, b, a);
}
void Primitives::rect(float x, float y, float w, float h){
    const float r = color.r;
    const float g = color.g;
    const float b = color.b;
    const float a = color.a;

    w /= 2;
    h /= 2;

    vertex(x-w, y-h, 0, 0, r,g,b,a);
    vertex(x-w, y+h, 0, 1, r,g,b,a);
    vertex(x+w, y+h, 1, 1, r,g,b,a);

    vertex(x-w, y-h, 0, 0, r,g,b,a);
    vertex(x+w, y+h, 1, 1, r,g,b,a);
    vertex(x+w, y-h, 1, 0, r,g,b,a);
    render(GL_TRIANGLES);
}
void Primitives::rectt(float x, float y, float w, float h,
        float u, float v, float tx, float ty){
    const float r = color.r;
    const float g = color.g;
    const float b = color.b;
    const float a = color.a;

    w /= 2;
    h /= 2;

    vertex(x-w, y-h, u,    v,    r,g,b,a);
    vertex(x-w, y+h, u,    v+ty, r,g,b,a);
    vertex(x+w, y+h, u+tx, v+ty, r,g,b,a);

    vertex(x-w, y-h, u,    v,    r,g,b,a);
    vertex(x+w, y+h, u+tx, v+ty, r,g,b,a);
    vertex(x+w, y-h, u+tx, v,    r,g,b,a);
    render(GL_TRIANGLES);
}

void Primitives::circle(float x, float y, float w, float h){
    const float r = color.r;
    const float g = color.g;
    const float b = color.b;
    const float a = color.a;

    w /= 1.84;
    h /= 1.84;

    vertex(x,       y,       0.25, 0, r,g,b,a);
    vertex(x-w,     y,       0,    1, r,g,b,a);
    vertex(x-w*0.7, y+h*0.7, 1,    1, r,g,b,a);
    vertex(x,       y+h,     0,    1, r,g,b,a);
    vertex(x+w*0.7, y+h*0.7, 1,    1, r,g,b,a);
    vertex(x+w,     y,       0,    1, r,g,b,a);
    vertex(x+w*0.7, y-h*0.7, 1,    1, r,g,b,a);
    vertex(x,       y-h,     0,    1, r,g,b,a);
    vertex(x-w*0.7, y-h*0.7, 1,    1, r,g,b,a);
    vertex(x-w,     y,       0,    1, r,g,b,a);
    render(GL_TRIANGLE_FAN);
}

void Primitives::sprite(float x, float y, float w, float h, int atlasRes, int index){
    float scale = 1.0f / (float)atlasRes;
    float u = (index % atlasRes) * scale;
    float v = 1.0f - ((index / atlasRes) * scale) - scale;
    rectt(x, y, w, h, u, v, scale, scale);
}

void Primitives::render(unsigned int gl_primitive) {
    mesh->reload(buffer, index / VERTEX_SIZE);
    mesh->draw(gl_primitive);
    index = 0;
}