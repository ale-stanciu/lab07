#include "Tests.h"
#include "assert.h"
#include "../Domain/Entity.h"
#include <cstring>
#include "../Repo/Repo.h"
#include "../Service/Service.h"

void test_all()
{
    test_constructor1();
    test_constructor2();
    test_setter_getter();
    testRepo();
    testDelete();
    testModify();
    testService();
}

void test_constructor1()
{
    Entity entity;
    assert(entity.getNrApartments() == 0);
    assert(entity.getSum() == 0);
    assert(entity.getType() == nullptr);
}


void test_constructor2()
{
    char* s = new char[3]{'a', 'p', 'a'};
    Entity entity(1, s, 5, 4);
    assert(entity.getNrApartments() == 4);
    assert(entity.getSum() == 5);
    assert(strcmp(entity.getType(), s) == 0);
}


void test_setter_getter()
{
    Entity entity;
    entity.setSum(10);
    entity.setNrApartments(9);
    char* s = new char[3]{'a', 'p', 'a'};
    entity.setType(s);

    assert(strcmp(entity.getType(),s) == 0);
    assert(entity.getSum() == 10);
    assert(entity.getNrApartments() == 9);
    delete[] s;
}


void testRepo() {
    Repo repo;
    Entity ent1, ent2, ent3;
    const char *s1 = "curent";
    const char *s2 = "apa";
    ent1.setSum(100);
    ent1.setNrApartments(25);
    ent1.setType(const_cast<char *>(s1));

    ent2.setSum(100);
    ent2.setNrApartments(25);
    ent2.setType(const_cast<char *>(s2));

    ent3.setSum(100);
    ent3.setNrApartments(25);
    ent3.setType(const_cast<char *>(s1));
    repo.addEntity(ent1);
    repo.addEntity(ent2);
    repo.addEntity(ent3);

    assert(repo.getSize() == 3);
}

void testDelete()
{
    Repo repo;
    char *s0 = (char*)"apa";
    char *s1 = (char*)"caldura";
    char *s2 = (char*)"gaz";
    char *s3 = (char*)"electricitate";

    Entity ent1(1, s0, 10, 200);
    Entity ent2(2, s1, 20, 500);
    Entity ent3(3, s3, 15, 450);

    repo.addEntity(ent1);
    repo.addEntity(ent2);
    repo.addEntity(ent3);

    repo.deleteEntity(2);

    assert(repo.getSize() == 2);
}


void testModify()
{
    Repo repo;
    const char *s0 = "apa";
    const char *s1 = "caldura";
    const char *s2 = "gaz";
    const char *s3 = "electricitate";

    Entity ent1(1, s0, 10, 200);
    Entity ent2(2, s1, 20, 500);
    Entity ent3(3, s3, 15, 450);
    Entity ent4(4, s2, 40, 1000);

    repo.addEntity(ent1);
    repo.addEntity(ent2);
    repo.addEntity(ent3);

    repo.modifyEntity(ent2, ent4);

    assert(repo.getEntityById(4) == ent4);
    assert(repo.getEntityById(1) == ent1);
    assert(repo.getEntityById(3) == ent3);
}


void testService()
{
    Repo repo;
    Service service(repo);


    const char *s0 = "apa";
    const char *s1 = "caldura";
    const char *s2 = "gaz";
    const char *s3 = "electricitate";

    Entity ent1(1, s0, 10, 200);
    Entity ent2(2, s1, 20, 500);
    Entity ent3(3, s3, 15, 450);
    Entity ent4(4, s2, 40, 1000);


    service.create(ent1);
    service.create(ent2);
    service.create(ent3);

    assert(service.getById(2) == ent2);

    service.update(ent1, ent4);

    assert(service.getById(2) == ent2);
    assert(service.getById(4) == ent4);

    service.deletee(ent4);

    assert(service.getById(2) == ent2);
    assert(repo.getSize() == 0);

}
