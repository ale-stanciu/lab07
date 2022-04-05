//
// Created by User on 4/5/2022.
//

#ifndef LAB07_ENTITY_H
#define LAB07_ENTITY_H


class Entity {
private:
    int nr_apartments;
    int sum;
    char* type;

public:
    Entity();
    Entity(char* t, int s, int nr);
    Entity(const Entity &e);
    char* getType();
    int getSum();
    int getNrApartments();
    void setType(char *t);
    void setSum(int s);
    void setNrApartments(int nr);
    Entity& operator=(const Entity &e);
    bool operator==(const Entity &e);
    ~Entity();
};


#endif //LAB07_ENTITY_H
