// Hash.h
// Final (GROUP) Project
// Last Updated:	11/24/2018
// Contributors:
// Andey Tuttle		-	Project Leader	(Recursion/Code-Gluer)
// Jeremiah Vaskis	-	Project Member	(Class/Vector Work)
// Spencer Romberg	-	Project Member	(I/O & UI Work)
// Liscensed under Apache 2.0 Liscense

// Header to a custom Hash Algorithm

#ifndef _HASH_H_
#define _HASH_H_

#include "DataEntry.h"

//returns a hashed string of the parameter unhashedString
std::string hash(std::string unhashedString);
std::string hash(std::vector<std::string> d);

//interface to easily hash specific parts of the tree
void hashID(std::vector<DataEntry> & d, int index);
void hashChild(std::vector<DataEntry> & d, int index);
void hashHistory(std::vector<DataEntry> & d, int index);
int update(std::vector<DataEntry> & d, int index);

#endif
