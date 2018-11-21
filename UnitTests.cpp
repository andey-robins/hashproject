// UnitTests.cpp
// Final (GROUP) Project
// Last Updated:	11/21/2018
// Contributors:
// Andey Tuttle		-	Project Leader	(Recursion/Code-Gluer)
// Jeremiah Vaskis	-	Project Member	(Class/Vector Work)
// Spencer Romberg	-	Project Member	(I/O & UI Work)
// Liscensed under Apache 2.0 Liscense

// A set of unit tests for all aspects of the Tracking Tree Project

#include "UnitTests.h"

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
