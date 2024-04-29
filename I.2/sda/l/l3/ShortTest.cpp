#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"

void testAll() {
    Set s;
    assert(s.isEmpty() == true);
    assert(s.size() == 0);
    assert(s.add(5)==true);
    assert(s.add(1)==true);
    assert(s.add(10)==true);
    assert(s.add(7)==true);
    assert(s.add(1)==false);
    assert(s.add(10)==false);
    assert(s.add(-3)==true);
    assert(s.size() == 5);
    assert(s.search(10) == true);
    assert(s.search(16) == false);
    assert(s.remove(1) == true);
    assert(s.remove(6) == false);
    assert(s.size() == 4);

    SetIterator it = s.iterator();
    it.first();
    int sum = 0;
    while (it.valid()) {
        TElem e = it.getCurrent();
        sum += e;
        it.next();
    }
    assert(sum == 19);

    Set s1;
    Set s2;
    assert(s1.isEmpty() == true);
    assert(s2.isEmpty() == true);
    assert(s1.add(5)==true);
    assert(s1.add(7)==true);
    assert(s1.add(9)==true);
    assert(s1.add(5)==false);
    assert(s2.add(4)==true);
    assert(s2.add(6)==true);
    assert(s2.add(8)==true);
    Set unionSet = s1.unionWith(s2);
    unionSet.print();
}