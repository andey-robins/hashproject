// UnitTests.cpp
// Final (GROUP) Project
// Last Updated:	11/28/2018
// Contributors:
// Andey Tuttle		-	Project Leader	(Recursion/Code-Gluer)
// Jeremiah Vaskis	-	Project Member	(Class/Vector Work)
// Spencer Romberg	-	Project Member	(I/O & UI Work)
// Liscensed under Apache 2.0 Liscense

// A set of unit tests for all aspects of the Tracking Tree Project

#include "UnitTests.h"

//main driver test. Call this function to test all functions in UnitTests.cpp
//written by Andey Tuttle
//last updated November 28, 2018
void testDriver() {
    std::cout << "Project up." << std::endl;

    std::cout << "Testing DataEntry Class..." << std::endl;
    dataEntryTest();
    std::cout << "DataEntry Class test completed." << std::endl << std::endl;

    std::cout << "Testing Hash Algorithm..." << std::endl;
    hashTest();
    std::cout << "Hash Algorithm test completed." << std::endl << std::endl;

    std::cout << "Testing Structure..." << std::endl;
    structureTest();
    std::cout << "Structure test completed." << std::endl << std::endl;

    std::cout << "Spinning Project down." << std::endl;
}

//test of the DataEntry class
//written by Jeremiah Vaskis
//last updated November 21, 2018
void dataEntryTest() {
	// The follow code test out the functions:
	// setID, setParentID, setEvent, setLhash, setRhash, setLhist, setRhist
	// getID, getParentID, getEvent, getLhash, getRhash, getLhist, getRhist
	// printTop, printLhist, printRhist, is_empty

	std::string Input = "123456789A123456789B123456789C";

	std::cout << std::endl << "Intial String: " << std::endl;
	std::cout << Input << std::endl << std::endl;


	std::cout << std::endl << "Creating New DataEntry: A" << std::endl;
	DataEntry A;

	std::cout << std::endl << "Is empty?: " << A.is_empty() << std::endl;

	std::cout << std::endl << "Printing New DataEntry Top information:" << std::endl;
	A.printTop();
	std::cout << std::endl << "Updating Top elements..." << std::endl;
	A.setID(Input);
	A.setParentID(Input);
	A.setEvent(Input);
	A.setLhash(Input);
	A.setRhash(Input);
	A.printTop();

	std::cout << std::endl << "Is empty?: " << A.is_empty() << std::endl;

	A.printLhist();
	std::cout << std::endl << "Updating Lhist First Time..." << std::endl;
	A.setLhist(A.getID());
	A.printLhist();
	std::cout << std::endl << "Updating Lhist Second Time..." << std::endl;
	A.setLhist(A.getID());
	A.printLhist();

	A.printRhist();
	std::cout << std::endl << "Updating Rhist First Time..." << std::endl;
	A.setRhist(A.getID());
	A.printRhist();
	std::cout << std::endl << "Updating Rhist Second Time..." << std::endl;
	A.setRhist(A.getID());
	A.printRhist();

	std::cout << std::endl << "Creating New DataEntry: B" << std::endl;
	DataEntry(B);
	std::string BString = "Trololololololol";

	std::cout << std::endl << "Updating Top elements..." << std::endl;
	B.setID(BString);
	B.setParentID(BString);
	B.setEvent(BString);
	B.setLhash(BString);
	B.setRhash(BString);
	B.printTop();

	std::cout << std::endl << "Updating Rhist Third Time..." << std::endl;
	A.setRhist(B.getID());
	A.printRhist();


	std::cout << std::endl << std::endl;

}

// test of the Hash functions
// written by Andey Tuttle
// last updated November 21, 2018
void hashTest() {

    //the following code will demonstrate that the hash function produces results as expected

    std::string stringTohash = "thisisunhashed";
    std::cout << "Attempting to hash string: " << stringTohash << std::endl;
    std::string hashedString = hash(stringTohash);
    std::cout << "Hashed String            : " << hashedString << std::endl << std::endl;

    stringTohash = "this is another unshashed string";
    std::cout << "Attempting to hash string: " << stringTohash << std::endl;
    hashedString = hash(stringTohash);
    std::cout << "Hashed String            : " << hashedString << std::endl << std::endl;

    stringTohash = "yet another unhashed string that goes on for such a long time, oh my god just stop already";
    std::cout << "Attempting to hash string: " << stringTohash << std::endl;
    hashedString = hash(stringTohash);
    std::cout << "Hashed String            : " << hashedString << std::endl << std::endl;

}

// test of the recursive hash update functions
// written by Andey Tuttle
// last updated November 28, 2018
void structureTest() {

    //the following code shows that the recusive updates of the tree function as expected

    //declarations for the structure test
    std::vector<DataEntry> trackingTree;
    DataEntry root;
    root.setEvent("this is the root event");
    root.setParentID("rootParentId");
    root.setID(hash(root.getParentID() + root.getEvent()));
    trackingTree.push_back(root);
    grow(trackingTree);
    int index = 1;

    //actual conduct of the structure test
    trackingTree[index].printTop();
    newEntry(trackingTree, index, "This is the second event");
    trackingTree[index].printTop();
    index++;
    trackingTree[0].printTop();

    newEntry(trackingTree, index, "This is the third event");
    trackingTree[0].printTop();
    index++;

    grow(trackingTree);
    newEntry(trackingTree, index, "This is the fourth event");
    trackingTree[0].printTop();
}
