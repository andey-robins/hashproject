// main.cpp
// Final (GROUP) Project
// Last Updated:	12/4/2018
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
    //written by Spencer Romberg
	std::vector<DataEntry> main_trackingTree;
	DataEntry main_root;
	main_root.setEvent("root event");
	main_root.setParentID("rootParentId");
	main_root.setID(hash(main_root.getParentID() + main_root.getEvent()));
	main_trackingTree.push_back(main_root);
	grow(main_trackingTree);
	int index = 1;
	bool cont = true;


	while (cont) {
		//prompt the user for input
		std::cout << "Type input to add in a data entry. Type print to print out the IDs or a specific ID.\nFor additional information on any of these functions, type help." << endl;
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
			input();
		} else if (nextCommand == "p" || nextCommand == "Print" || nextCommand == "print") {
			bool print_confirm = true;
			string confirm;
			//executes code to print out all of the IDs, or to print out just a specific ID.
			while (print_confirm) {

				std::cout << "Do you wish to print out all of the IDs? (Y/N): ";
				std::cin >> confirm;
				if (confirm == "y" || confirm == "Y") {
					print_all();
					bool print_confirm = false;
				}
				if (confirm == "n" || confirm == "N") {
					print_specific();
					bool print_confirm = false;
				}
			}
		}  else if (nextCommand == "q" || nextCommand == "Quit" || nextCommand == "quit") {

			bool print_confirm = true;
			string confirm;
			//executes code to print out all of the IDs, or to print out just a specific ID.
			while (print_confirm) {

				std::cout << "Are you sure you wish to quit? (Y/N): ";
				std::cin >> confirm;
				if (confirm == "y" || confirm == "Y") {
					bool print_confirm = false;
					bool cont = false;
				} else if (confirm == "n" || confirm == "N") {
					bool print_confirm = false;
					std::cout << std::endl << std::endl;
				}
			}
		}
		std::cout << std::endl;
		}
	    system("pause");
		return 0;

    return 0;
}

void input() {

}

void print_all() {

}

void print_specific() {

}
