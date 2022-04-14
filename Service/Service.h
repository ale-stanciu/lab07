//
// Created by User on 4/14/2022.
//

#ifndef LAB07_SERVICE_H
#define LAB07_SERVICE_H


#include "../Repo/Repo.h"

class Service {
private:
    Repo repo;
public:
    Service();
    explicit Service(Repo &repo);
    ~Service();
    void create(Entity &entity);
    void update(Entity oldEntity, Entity newEntity);
    void deletee(Entity entity);
    Entity getById(int id);
    vector<Entity> getAll();
};


#endif //LAB07_SERVICE_H
