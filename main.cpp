// main.cpp
// Final (GROUP) Project
// Last Updated:	11/28/2018
// Contributors:
// Andey Tuttle		-	Project Leader	(Recursion/Code-Gluer)
// Jeremiah Vaskis	-	Project Member	(Class/Vector Work)
// Spencer Romberg	-	Project Member	(I/O & UI Work)
// Liscensed under Apache 2.0 Liscense

// Main class for Tracking Tree project

#include "UnitTests.h"

//function definitions
void grow(std::vector<DataEntry> & d);

int main() {

    std::vector<DataEntry> trackingTree;
    DataEntry root;
    root.setEvent("this is the root event");
    root.setParentID("rootParentId");
    trackingTree.push_back(root);
    grow(trackingTree)

    //test all of project's individual pieces
    testDriver();

    return 0;
}

//grow the tracking tree to have all the elements
void grow(std::vector<DataEntry> & d) {
    int size = d.size();

    for (int i = 0; i <= size; i++) {
        d.push_back(DataEntry());
    }
}
