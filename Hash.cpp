// Hash.cpp
// Final (GROUP) Project
// Last Updated:	11/24/2018
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

//custom hash function to interface with a vector
std::string hash(std::vector<std::string> d) {

    std::string s;

    for (int i = 0; i < d.size(); i++) {
        s += d[i];
    }

    return hash(s);
}

//hash the id of the passed in data object
void hashID(std::vector<DataEntry> & d, int index) {
    d[index].setID(hash(d[index].getParentID() + d[index].getEvent()));
}

//hash of the children
void hashChild(std::vector<DataEntry> & d, int index) {

    std::cout << index << ", " << std::endl;
    //left
    if (index * 2 < d.size()) {
        //exists
        d[index].setLhash(hash(d[index * 2].getEvent().substr(0,4)) + hash(d[index].getLhist()).substr(0,4));
    } else {
        //doesn't
        d[index].setLhash(NULL);
    }

    std::cout << "finish left" << std::endl;

    //right
    if (index * 2 + 1 < d.size()) {
        //exists
        d[index].setRhash(hash(d[index * 2 + 1].getEvent().substr(0,4)) + hash(d[index].getRhist()).substr(0,4));
    } else {
        //doesn't
        d[index].setRhash(NULL);
    }

    hashHistory(d, index);
}

//push back history changes
void hashHistory(std::vector<DataEntry> & d, int index) {
    std::cout << "index" << std::endl;
    d[index].setRhist(d[index].getRhash());
    d[index].setLhist(d[index].getLhash());
}

//recursively update up the tree
int update(std::vector<DataEntry> & d, int index) {

    std::cout << index << std::endl;

    if (index == 0) {
        //base case
        return 0;
    } else {
        std::cout << "test" << std::endl;
        hashChild(d, index);
        update(d, index / 2);
    }

    //this should never happen, but it'll panic the program if it does.
    return -1;
}
