// main.cpp
// Final (GROUP) Project
// Last Updated:	12/8/2018
// Contributors:
// Andey Tuttle		-	Project Leader	(Recursion/Code-Gluer)
// Jeremiah Vaskis	-	Project Member	(Class/Vector Work)
// Spencer Romberg	-	Project Member	(I/O & UI Work)
// Liscensed under Apache 2.0 Liscense

// Main class for Tracking Tree project

#include "UnitTests.h"

int main() {

    //test all of project's individual pieces, uncomment testDriver() to run.
    //testDriver();

    //main functionality
    //UI/UX by Spencer Romberg
    //hooks to tracking tree by Andey Tuttle

	std::vector<DataEntry> trackingTree;
	DataEntry root;

    std::string firstEvent;
    std::cout << "Please enter in the first event." << std::endl;
    getline(std::cin, firstEvent);
	root.setEvent(firstEvent);
	root.setParentID("nUs667YlDW"); //this ID was randomly generated with random.org
	root.setID(hash(root.getParentID() + root.getEvent()));
	trackingTree.push_back(root);
	grow(trackingTree);
	int index = 1;

    //main loop variable
	bool cont = true;
    std::string nextCommand;


	while (cont) {
		//prompt the user for input
		std::cout << std::endl << std::endl << std::endl << "Type input to add in a data entry. Type print to print out the IDs or a specific ID.\nFor additional information on any of these functions, type help." << std::endl;
		//get the user input for the command
		getline(std::cin, nextCommand);
		if (nextCommand == "h" || nextCommand == "Help" || nextCommand == "help") {

			std::cout << "--------------------------------------TUTORIAL-----------------------------------------------" << std::endl;
			std::cout << "To add in user input, type in input. Doing so will allow you to add raw input into the vector," << std::endl;
			std::cout << "which will automatically be sorted." << std::endl << std::endl;
			std::cout << "To print out all of the IDs in the tree, type print. After this, you will be asked to print a" << std::endl;
			std::cout << "specific ID or all the IDs." << std::endl << std::endl;
			std::cout << "To quit the program, type quit. After this, the program will ask you if you want to quit." << std::endl;
			std::cout << "If you choose to do so, then the program will close, otherwise it will continue." << std::endl;
			std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
		}
		if (nextCommand == "i" || nextCommand == "Input" || nextCommand == "input") {

            //executes code to enter a new input into the vector
			std::cout << "Enter in the event: " << std::endl;
            std::string tempEvent;
            getline(std::cin, tempEvent);

            //check to see if the tree is full
            if (index > trackingTree.size()) {
                grow(trackingTree);
            }

            //push out the new entry
            newEntry(trackingTree, index, tempEvent);
            index++;

		} else if (nextCommand == "p" || nextCommand == "Print" || nextCommand == "print") {
			bool print_confirm = true;
			std::string confirm;
			//executes code to print out all of the IDs, or to print out just a specific ID.
			std::cout << "Do you wish to print out a visualization of the tree? (Y/N): ";
			getline(std::cin, confirm);

			if (confirm == "y" || confirm == "Y") {
                //visualise the tree
                std::cout << std::endl << "Root Node:";
                trackingTree[0].printTop();

				for (int i = 1; i < index; i++) {
                    std::cout << std::endl << "Child of node " << floor((i - 1) / 2.0);
                    trackingTree[i].printTop();
                }

			} else if (confirm == "n" || confirm == "N") {
                //print out a specific element
                std::cout << "Please enter the ID of the element to view in its entirety." << std::endl;
                std::string tempId;
                getline(std::cin, tempId);

                //go through the elemnts to find the element
                int foundIndex = -1;

                for (int i = 0; i < index; i++) {
                    if (trackingTree[i].getID() == tempId) {
                        foundIndex = i;
                    }
                }

                //print the event if it's found or an error if it isn't
                if (foundIndex != -1) {
                    trackingTree[foundIndex].printTop();
                    trackingTree[foundIndex].printLhist();
                    trackingTree[foundIndex].printRhist();
                } else {
                    std::cout << "Invalid ID entered, type 'h' for help." << std::endl;
                }

			} else {
                //not y/n input
                std::cout << "Invalid command, please enter 'h' to see help." << std::endl;
            }

		}  else if (nextCommand == "q" || nextCommand == "Quit" || nextCommand == "quit") {

            //quit the program
			std::string confirm;

			std::cout << "Are you sure you wish to quit? (Y/N): ";
			getline(std::cin, confirm);
			if (confirm == "y" || confirm == "Y") {
				break;
			} else {
                std::cout << "Enter 'h' to get help with this program." << std::endl;
            }
		}
    }

    //note: to run through visual studio, uncomment the below system pause.
    //system("pause");

    return 0;
}
