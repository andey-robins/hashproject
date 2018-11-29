// Hash.cpp
// Final (GROUP) Project
// Last Updated:	11/28/2018
// Contributors:
// Andey Tuttle		-	Project Leader	(Recursion/Code-Gluer)
// Jeremiah Vaskis	-	Project Member	(Class/Vector Work)
// Spencer Romberg	-	Project Member	(I/O & UI Work)
// Liscensed under Apache 2.0 Liscense

// Custom Hash algorithm

#include "Hash.h"

//custom hash function
//returns a hash of the uhashed string passed as a parameter
std::string hash(std::string unhashedString) {

    int sum = 0;

    for (int i = 0; i < unhashedString.size(); i++) {
        sum += int(unhashedString[i]) * (i + 1);
    }

    std::string ssum = std::to_string(sum);

    for (int i = 0; i < ssum.size(); i++) {
        sum += int(ssum[i]) * (i + 1) * pow(100, i);
    }

    std::string sssum = ssum;
    std::reverse(sssum.begin(), sssum.end());

    for (int i = 0; i < sssum.size(); i++) {
        sum += int(sssum[i]) * int(ssum[i]) * pow(10, i);
    }

    std::ostringstream s;
    s << std::hex << sum;
    std::string out = s.str();
    s.clear();

    return out;
}

//take a new event and set up the node in the tree with everything it can
void newEntry(std::vector<DataEntry> & d, int index, std::string event) {

    int parentIndex;

    if (index % 2 == 0) {
        parentIndex = floor((index - 1) / 2.0);
    } else {
        parentIndex = floor(index / 2.0);
    }

    d[index].setParentID(d[parentIndex].getID());
    d[index].setEvent(event);
    d[index].setID(hash(d[parentIndex].getID() + d[index].getEvent()));

    //track up the tree, updating as you go
    updateParent(d, parentIndex, index);
}


//grow the tracking tree to have a new row of elements
void grow(std::vector<DataEntry> & d) {
    int size = d.size();

    for (int i = 0; i <= size; i++) {
        d.push_back(DataEntry());
    }
}


//move up the tree updating as we go
void updateParent(std::vector<DataEntry> & d, int index, int child) {

    //hash the child's contents
    std::string toHash = hash(d[child].getID() + d[child].getParentID() + d[child].getEvent() + d[child].getLhash() + d[child].getRhash());

    int parentIndex;

    //check if the child is left or right
    if (child % 2 == 0) {
        d[index].setRhash(toHash);
        d[index].setRhist(toHash);
        parentIndex = floor((index - 1) / 2.0);
    } else {
        d[index].setLhash(toHash);
        d[index].setLhist(toHash);
        parentIndex = floor(index / 2.0);
    }

    //base exit if the recursion is at the root of the tree
    if (index != 0) {
        updateParent(d, parentIndex, index);
    }
}
