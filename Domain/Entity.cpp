#include "Entity.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

Entity::Entity()
{
    this->nr_apartments = 0;
    this->sum = 0;
    this->type = nullptr;
}

Entity::Entity(int id,const char* t, int s, int nr)
{
    this->type = new char[strlen(t) + 1];
    strcpy_s(this->type, sizeof this->type, t);
    this->sum = s;
    this->nr_apartments = nr;
    this->id = id;
}

Entity::Entity(const Entity &e)
{
    this->type = new char[strlen(e.type) + 1];
    strcpy_s(this->type, sizeof this->type, e.type);
    this->nr_apartments = e.nr_apartments;
    this->sum = e.sum;
    this->id = e.id;
}

Entity::~Entity()
{
    if(this->type)
    {
        this->type = nullptr;
        this->nr_apartments = 0;
        this->sum = 0;
        this->id = 0;
    }
    //delete[] this->type;
}

char* Entity::getType()
{
    return type;

}

int Entity::getSum()
{
    return this->sum;
}

int Entity::getNrApartments()
{
    return this->nr_apartments;
}

void Entity::setType(const char *t)
{
    this->type = new char[strlen(t) + 1];
    strcpy_s(this->type, sizeof this->type, t);
}


void Entity::setSum(int s)
{
    this->sum = s;
}

void Entity::setNrApartments(int nr)
{
    this->nr_apartments = nr;
}

Entity& Entity::operator=(const Entity &e)
{
    this->setType(e.type);
    this->setNrApartments(e.nr_apartments);
    this->setSum(e.sum);
    this->setId(e.id);
    return *this;
}

bool Entity::operator==(const Entity &e)
{
    return ((strcmp(this->type, e.type) == 0) && (this->sum == e.sum) && (this->nr_apartments == e.nr_apartments));
}

bool Entity::isValid()
{
    const char *s0 = "apa";
    const char *s1 = "caldura";
    const char *s2 = "gaz";
    const char *s3 = "electricitate";

    vector<const char*>utilities = {s0,s1,s2,s3};

    for(auto &s:utilities)
    {
        if(strcmp(s, type) == 0)
        {
            return true;
        }
    }
}

int Entity::getId()
{
    return id;
}

void Entity::setId(int id)
{
    this->id = id;
}