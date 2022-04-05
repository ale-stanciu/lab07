#include "Entity.h"
#include <iostream>
#include <cstring>

Entity::Entity()
{
    this->nr_apartments = 0;
    this->sum = 0;
    this->type = nullptr;
}

Entity::Entity(char* t, int s, int nr)
{
    this->type = new char[strlen(t) + 1];
    strcpy_s(this->type, sizeof this->type, t);
    this->sum = s;
    this->nr_apartments = nr;
    delete[] this->type;
}

Entity::Entity(const Entity &e)
{
    this->type = new char[strlen(e.type) + 1];
    strcpy_s(this->type, sizeof this->type, e.type);
    this->nr_apartments = e.nr_apartments;
    this->sum = e.sum;
    delete[] this->type;
}

Entity::~Entity()
{
    if(this->type)
    {
        this->type = nullptr;
        this->nr_apartments = 0;
        this->sum = 0;
    }
    delete[] this->type;
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

void Entity::setType(char *t)
{
    if(this->type)
        delete[] this->type;
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
    return *this;
}

bool Entity::operator==(const Entity &e)
{
    return ((strcmp(this->type, e.type) == 0) && (this->sum == e.sum) && (this->nr_apartments == e.nr_apartments));
}