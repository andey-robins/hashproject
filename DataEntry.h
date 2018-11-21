// DataEntry.h
// Final (GROUP) Project
// Last Updated:	11/21/2018
// Contributors:
// Andey Tuttle		-	Project Leader	(Recursion/Code-Gluer)
// Jeremiah Vaskis	-	Project Member	(Class/Vector Work)
// Spencer Romberg	-	Project Member	(I/O & UI Work)
// Liscensed under Apache 2.0 Liscense

// Header for DataEntry class
// Implementation Described in GitHub Issue #1 https://github.com/andeyt/hashproject/issues/1

#ifndef _DATA_ENTRY_H
#define _DATA_ENTRY_H

#include <string>
#include <vector>
#include <iostream>

class DataEntry {
public:
	// Set Functions
	void setID(std::string s);
	void setParentID(std::string s);
	void setEvent(std::string s);
	void setLhash(std::string s);
	void setRhash(std::string s);
	void setLhist(std::string s);
	void setRhist(std::string s);

	// Get Functions
	std::string getID();
	std::string getParentID();
	std::string getEvent();
	std::string getLhash();
	std::string getRhash();
	std::vector<std::string> getLhist();
	std::vector<std::string> getRhist();

    //
    // VARIOUS OTHER FUNCTIONS
    //
	// Print Functions
	// Prints everything BUT the history vectors
	void printTop();
	// Prints Left history vector
	void printLhist();
	// Prints Right history vector
	void printRhist();

	// Empty?
	bool is_empty();

private:
    //data values
	std::string ID		= "";
	std::string ParentID	= "";
	std::string Event	= "";
	std::string Rhash = "";
	std::string Lhash = "";
	std::vector<std::string> Lhist;
	std::vector<std::string> Rhist;

};

#endif
