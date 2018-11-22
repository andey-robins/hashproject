// Hash.cpp
// Final (GROUP) Project
// Last Updated:	11/21/2018
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
