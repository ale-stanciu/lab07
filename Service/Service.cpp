//
// Created by User on 4/14/2022.
//

#include "Service.h"
#include <iostream>

using namespace std;

Service::Service() {};

Service::Service(Repo &repo)
{
    this->repo = repo;
}

Service::~Service() {};

void Service::create(Entity &entity){
    repo.addEntity(entity);
}

void Service::update(Entity oldEntity, Entity newEntity){
    repo.modifyEntity(oldEntity,newEntity);
}

void Service::deletee(Entity entity){
    repo.deleteEntity(entity.getId());
}


Entity Service::getById(int id){
    return repo.getEntityById(id);
}

vector<Entity> Service::getAll() {
    vector<Entity> entities = this->repo.getAll();
    return entities;
}

