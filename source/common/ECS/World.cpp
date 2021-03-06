//
// Created by Aya on 11/17/2020.
//

#include "World.h"
#include "Components/MeshRenderer.h"
#include "Components/Transform.h"
#include "Components/Camera.h"
#include "Components/CameraComponent.h"

#include "Entity.h"
//#include "Components\Camera.h"
Entity* World::createEntity() {
    Entity* e=new Entity();
    Entities.push_back(e);
    return e;
}
vector<Entity *> World::getEntities() {
    return Entities;
}
// this function should be called in main game state 
void World::Rendering(){
    int Size=Entities.size();
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i=0;i<Size;i++)
    {
        if(Entities[i]->getComponent<MeshRenderer>()!=NULL)
        {
            Camera* c=getCameraEntity()->getComponent<Camera>();
            Transform* t=Entities[i]->getComponent<Transform>();
            CameraController* cc=getCameraEntity()->getComponent<CameraController>();
            //if(!c)return;
            //if(!cc)return;
            glm::mat4 vp=c->getProjectionMatrix()*cc->getViewMatrix();
            glm::mat4 matrix1=vp*t->parents_mat(); //*view
            MeshRenderer* mesh=Entities[i]->getComponent<MeshRenderer>();
            our::Mesh* m=mesh->getPointerToMesh();
            our::ShaderProgram* p=mesh->getPointerToProgram();
            //if(!p)return;
            //if(!m) return;
            //if()
           // if(*p) return;

            glUseProgram(*p);
            p->set("transform", matrix1);
            p->set("tint", glm::vec4(0.5,1,1,1));
            m->draw();

        }
    }
}
//won't be used;
glm::mat4 World::getCameraEntityTransform(){
    glm::mat4 mat=glm::mat4(1.0);
    int Size=Entities.size();
    for(int i=0;i<Size;i++)
    {
        if(Entities[i]->getComponent<Camera>()!=NULL)
        {
            Transform* t=Entities[i]->getComponent<Transform>();
            return t->getMatrix();

        }
    }
    return mat;
}
 Entity* World::getCameraEntity(){

    int Size=Entities.size();
    for(int i=0;i<Size;i++)
    {
        if(Entities.at(i)->getComponent<Camera>()!=NULL)
        {
            return Entities.at(i);
        }
    }
    return NULL;
}
World::~World() {

}