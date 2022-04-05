#include "Tests.h"
#include "assert.h"
#include "../Domain/Entity.h"
#include <cstring>
#include <string>
#include "../Repo/Repo.h"

void test_all()
{
    test_constructor1();
    test_setter();
    test_getter();
    testRepo();
}

void test_constructor1()
{
    Entity entity;
    assert(entity.getNrApartments() == 0);
    assert(entity.getSum() == 0);
    assert(entity.getType() == nullptr);
}

/*
void test_constructor2()
{
    char* s = new char[3]{'a', 'p', 'a'};
    Entity entity(s, 5, 4);
    assert(entity.)

}
*/

void test_setter()
{
    Entity entity;
    entity.setSum(10);
    entity.setNrApartments(9);
    char* s = new char[3]{'a', 'p', 'a'};
    entity.setType(s);

    //assert(strcmp(entity.getType(),s) == 0);
    assert(entity.getSum() == 10);
    assert(entity.getNrApartments() == 9);
    delete[] s;
}

void test_getter()
{
    Entity entity;
    char* s = new char[3]{'a', 'p', 'a'};
    entity.setSum(10);
    entity.setNrApartments(9);
    entity.setType(s);

    //assert(strcmp(entity.getType(),s) == 0);
    assert(entity.getSum() == 10);
    assert(entity.getNrApartments() == 9);
    delete[]s;
}

void testRepo() {
    Repo repo;
    Entity ent1, ent2;
    char *s1 = new char[3]{'g', 'a', 'z'};
    ent1.setSum(100);
    ent1.setNrApartments(25);
    ent1.setType(s1);

    char *s2 = new char[3]{'a', 'p', 'a'};
    ent1.setSum(100);
    ent1.setNrApartments(25);
    ent1.setType(s1);

    ent1.setSum(100);
    ent1.setNrApartments(25);
    ent1.setType(s1);
    repo.addEntity(ent1);
    repo.addEntity(ent2);

    assert(repo.getSize() == 3);
    delete[]s1;
    delete[]s2;
}