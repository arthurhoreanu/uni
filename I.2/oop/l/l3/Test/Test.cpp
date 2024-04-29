#include "Test.h"
#include <cassert>

//All tests
void Test::tests() {
    testRepository();
}

//Tests for repository
void Test::testRepository() {
    Repository repo;
    // Test add and retrieve elements
    Medicine m1("Aspenter", "Terapia", "2025", 4, 15);
    repo.add(m1);
    assert(repo.getAll().size() == 1);
    assert(repo.getAll().front().getName() == "Aspenter");
    // Test remove element
    repo.del(m1);
    assert(repo.getAll().size() == 0);
}