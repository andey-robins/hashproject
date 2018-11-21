// DataEntry_WithTests.cpp
// Final (GROUP) Project
// Last Updated:	11/21/2018
// Contributors:
// Andey Tuttle		-	Project Leader	(Recursion/Code-Gluer)
// Jeremiah Vaskis	-	Project Member	(Class/Vector Work)
// Spencer Romberg	-	Project Member	(I/O & UI Work)
// Liscensed under Apache 2.0 Liscense

// Addresses GitHub Issue #1 https://github.com/andeyt/hashproject/issues/1

#include "DataEntry.h"

// Set Functions
void DataEntry::setID(std::string s) {
	// Fixed length string of 8 characters (case insensitive)
	// Stores ONLY the first 8 characters
	ID = s.substr(0,8);
}
void DataEntry::setParentID(std::string s) {
	// Fixed length string of 8 characters
	// Stores ONLY the first 8 characters
	ParentID = s.substr(0,8);
}
void DataEntry::setEvent(std::string s) {
	// Variable string length; Up to 1024 characters
	int MaxLength = 1024;
	// Stores ONLY the first MaxLength characters
	if (s.size() <= MaxLength) {
		Event = s;
	}
	else {
		std::cout << std::endl << std::endl << "Input Cut Down to " << MaxLength << " long..." << std::endl << std::endl;
		Event = s.substr(0, MaxLength);
	}
}
void DataEntry::setLhash(std::string s) {
	// Stores ONLY the first 8 characters
	Lhash = s.substr(0, 8);
}
void DataEntry::setRhash(std::string s) {
	// Stores ONLY the first 8 characters
	Rhash = s.substr(0,8);
}
void DataEntry::setLhist(std::string Node) {
	// Adds the particular Node to the Left History Vector
	Lhist.push_back(Node);
}
void DataEntry::setRhist(std::string Node) {
	// Adds the particular Node to the Right History Vector
	Rhist.push_back(Node);
}

// Get Functions
std::string DataEntry::getID() {
	return ID;
}
std::string DataEntry::getParentID() {
	return ParentID;
}
std::string DataEntry::getEvent() {
	return Event;
}
std::string DataEntry::getLhash() {
	return Lhash;
}
std::string DataEntry::getRhash() {
	return Lhash;
}
std::vector<std::string> DataEntry::getLhist() {
	return Lhist;
}
std::vector<std::string> DataEntry::getRhist() {
	return Rhist;
}

// Print Functions
// Prints everything BUT the history vectors
void DataEntry::printTop() {
	std::cout << std::endl;
	std::cout << "ID:\t\t" << ID << std::endl;
	std::cout << "ParentID:\t" << ParentID << std::endl;
	std::cout << "Event:\t\t" << Event << std::endl;
	std::cout << "Lhash:\t\t" << Lhash << std::endl;
	std::cout << "Rhash:\t\t" << Lhash << std::endl;
}
// Prints Left history vector
void DataEntry::printLhist() {
	std::cout << std::endl;

	if (Lhist.empty()) {
		std::cout << std::endl << "Lhist:\t\tEMPTY" << std::endl;
	}
	else {
		std::cout << "Lhist:" << std::endl;
		for (int i = 0; i < Lhist.size(); i++) {
			std::cout << Lhist[i] << std::endl;
		}
	}
}
// Prints Right history vector
void DataEntry::printRhist() {
	std::cout << std::endl;

	if (Rhist.empty()) {
		std::cout << std::endl << "Rhist is Empty" << std::endl;
	}
	else {
		std::cout << "Rhist:" << std::endl;
		for (int i = 0; i < Rhist.size(); i++) {
			std::cout << Rhist[i] << std::endl;
		}
	}
}

// Empty?
bool DataEntry::is_empty() {
	if (Event == "") {
		return true;
	}
	else {
		return false;
	}
}

// Constructors
// I don't know if I have a good grasp on Constructors,
// here is a default constructor, and some commented out code
// for what I guess could be some other types?
// I think how you implement you main code would determine how
// many constructor types you would need beyond this.
// Default:
//DataEntry() = default;
// Event input:
// DOES NOT update anything else, also is_empty() only checks "Event"
// so unless you immediately set[variable name] all of the other stuff
// then there could be a node that would not be completely initialized
// not having ID's, Hashes, etc.
//DataEntry(string s) {
//	setEvent(s);
//}
