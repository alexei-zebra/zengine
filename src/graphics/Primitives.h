#ifndef SRC_GRAPHICS_PRIMITIVES_H_
#define SRC_GRAPHICS_PRIMITIVES_H_

#include <stdlib.h>
#include <glm/glm.hpp>

using namespace glm;

class Mesh;
class Texture;

class Primitives {
    float* buffer;
    size_t capacity;
    size_t offset;
    Mesh* mesh;
    size_t index;

    Texture* blank;
    Texture* _texture;

    void vertex(float x, float y,
            float u, float v,
            float r, float g, float b, float a);
    void vertex(vec2 point,
            vec2 uvpoint,
            float r, float g, float b, float a);

public:
    vec4 color;

    Primitives(size_t capacity);
    ~Primitives();

    void begin();
    void texture(Texture* texture);
    void sprite(float x, float y, float w, float h, int atlasRes, int index);
    void point(float x, float y, float r, float g, float b, float a);
    void linec(float x1, float y1, float x2, float y2, float r, float g, float b, float a);
    void line(float x1, float y1, float x2, float y2);

    void rect(float x, float y, float w, float h);
    void rectc(float x, float y, float w, float h, float r, float g, float b, float a);
    void rectt(float x, float y, float w, float h,
            float u, float v, float tx, float ty);
    void rectw(float x, float y, float w, float h, float r, float g, float b, float a);
    void circle(float x, float y, float w, float h);
    void render(unsigned int gl_primitive);
};

#endif /* SRC_GRAPHICS_BATCH2D_H_ */
