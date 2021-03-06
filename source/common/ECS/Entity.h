//
// Created by Aya on 11/17/2020.
//
//#include <string>
#include "Component.h"
#include <string>
#include "vector"
using namespace std;
//#ifndef GFX_LAB_ENTITY_H
//#define GFX_LAB_ENTITY_H

//class Component;
class Entity {
string Name;
vector<Component*> components;
public:
    void addComponent(Component* c);
    void removeComponent(Component* c);
    template<typename T>
    T* getComponent(){
    T* t = nullptr;
    for (auto i : components) {
        if ((t = dynamic_cast<T*>(i)) != nullptr) return t;
    }

    return NULL;
};
~Entity();
};


