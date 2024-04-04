#include "L2_dsm.h"
#include <iostream>
#include <cassert>

int main() {
    // Test for constructor DSM(int elementCount) and size
    DSM dsm1(7);
    assert(dsm1.size() == 7);

    // Test for constructor DSM(vector<string> element_names) and size
    DSM dsm2({"A", "B", "C", "Y"});
    assert(dsm2.size() == 4);

    // Test for set_element_name(int id, string name)
    dsm1.setElementName(0, "X");
    dsm1.setElementName(1, "B");
    assert(dsm1.getName(0) == "X");
    assert(dsm1.getName(1) == "B");

    // Test for add_link(string from_element, string to_element, float weight) and have_link
    dsm1.addLink("X", "B", 1.5f);
    assert(dsm1.haveLink("X", "B"));
    assert(dsm1.linkWeight("X", "B") == 1.5f);

    // Test for delete_link(string from_element, string to_element)
    dsm1.deleteLink("X", "B");
    assert(!dsm1.haveLink("X", "B"));

    // Test for count_all_links()
    assert(dsm1.countAllLinks() == 0);

    // Test for count_to_links(string element_name)
    dsm2.addLink("A", "Y", 2.0f);
    assert(dsm2.countToLinks("Y") == 1);

    // Test for count_from_links(string element_name)
    assert(dsm2.countFromLinks("A") == 1);

    cout << "All tests passed!";
    return 0;
}

