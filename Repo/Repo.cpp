#include "Repo.h"
#include <iostream>
using namespace std;
Repo::Repo()
{
    this->noEntities = 0;
}

Repo::~Repo(){}

void Repo::addEntity(Entity &e) {
    this->entities[this->noEntities++] = e;
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

