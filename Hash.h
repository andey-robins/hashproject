// Hash.h
// Final (GROUP) Project
// Last Updated:	11/28/2018
// Contributors:
// Andey Tuttle		-	Project Leader	(Recursion/Code-Gluer)
// Jeremiah Vaskis	-	Project Member	(Class/Vector Work)
// Spencer Romberg	-	Project Member	(I/O & UI Work)
// Liscensed under Apache 2.0 Liscense

// Header to a custom Hash Algorithm

#include "DataEntry.h"
#include <iomanip>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <cmath>

//returns a hashed string of the parameter unhashedString
std::string hash(std::string unhashedString);

//recursive update functions
void updateParent(std::vector<DataEntry> & d, int index, int child);
void grow(std::vector<DataEntry> & d);
void newEntry(std::vector<DataEntry> & d, int index, std::string event);
