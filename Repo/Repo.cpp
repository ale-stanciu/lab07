#include "Repo.h"
#include <iostream>
using namespace std;
Repo::Repo()
{
    this->noEntities = 0;
}

Repo::~Repo() = default;

void Repo::addEntity(Entity &e) {
    //if(e.isValid()) {
        this->entities[this->noEntities++] = e;
    //}
    //else {
      //  throw runtime_error("The entity is not valid!");
    //}
}

Entity Repo::getEntityFromPosition(int pos){
    return this->entities[pos];
}

int Repo::getSize(){
    return this->noEntities;
}

vector <Entity> Repo::getAll() {
    vector <Entity> v;
    for( int i=0; i<noEntities; i++)
        v.push_back(v[i]);
    return v;
}

void Repo::deleteEntity(int id)
{
    for(int i=0; i<noEntities; i++){
        if(id == entities[i].getId())
        {
            for(int j =i; j<noEntities-1; j++) {
                entities[j] = entities[j + 1];
            }
            noEntities--;
            }
        }
}

void Repo::modifyEntity(Entity &oldEntity, Entity &newEntity)
{
    for(int i=0; i<noEntities; i++){
        if(entities[i].getId() == oldEntity.getId()) {
            entities[i] = newEntity;
        }
    }
}

Entity Repo::getEntityById(int id) {
    for(Entity &ent: entities){
        if(ent.getId() == id){
            return ent;
        }
    }
    throw runtime_error("There is no entity with this id!");
}

Repo &Repo::operator=(const Repo &repo) {
    if(this != &repo) {
        this->noEntities = repo.noEntities;
        for(int i = 0; i < noEntities; i++) {
            this->entities[i] = repo.entities[i];
        }
    }
    return *this;
}


