//
// Created by User on 4/5/2022.
//

#ifndef LAB07_ENTITY_H
#define LAB07_ENTITY_H


class Entity {
private:
    int nr_apartments;
    int sum;
    int id;
    char* type;

public:
    Entity();
    Entity(int id, const char* t, int s, int nr);
    Entity(const Entity &e);
    char* getType();
    int getSum();
    int getNrApartments();
    void setType(const char *t);
    void setSum(int s);
    void setNrApartments(int nr);
    Entity& operator=(const Entity &e);
    bool operator==(const Entity &e);
    bool isValid();
    int getId();
    void setId(int id);
    ~Entity();
};


#endif //LAB07_ENTITY_H
