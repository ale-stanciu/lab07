//
// Created by User on 4/5/2022.
//

#ifndef LAB07_REPO_H
#define LAB07_REPO_H

#include "../Domain/Entity.h"
#include <vector>
using namespace std;
class Repo {
private:
    Entity entities[100];
    int noEntities;

public:
    Repo();
    ~Repo();
    void addEntity(Entity &e);
    Entity getEntityFromPosition(int pos);
    int getSize();
    vector <Entity> getAll();
};


#endif //LAB07_REPO_H
