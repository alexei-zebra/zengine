#include "Objects.h"

void Objects::add_object(Object* obj){
    objects[len] = obj;
    len++;
}
void Objects::set_object(Object* obj, int i){
    if (i < len) objects[i] = obj;
}

Object* Objects::get_object(int i){
    if (i < len) return objects[i];
}

int Objects::get_len(){
    return len;
}