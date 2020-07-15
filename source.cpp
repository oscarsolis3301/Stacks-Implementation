// Using the header file
#include "Header.h"

// Using enum for the menu
// Used throughout the program - In the main function
enum Menu {End, Push, Pop, isEmpty, Peek, Size};

// Class for the stacks
// Used through the program - In the main function
class stacks {
	public: // Public section of the class
		stack <string> names; // (Public) - names - stack
		stack <char> genders; // (Public) - genders - stack
		stack <int> ages; // (Public) - ages - stack
		string name; // (Public) - name - string
		char gender; // (Public) - gender - char
		int age; // (Public) - age - int
};

/**********************************************************************
* AUTHOR   : Oscar Solis-Pacheco
* LAB #9   : Implement a Stack
* CLASS    : CS1B
* SECTION  : MTWTH: 5p - 7:20p
* Due Date : 7/06/2020
***********************************************************************/

/***********************************************************************
*
* IMPLEMENT A STACK
*
* ----------------------------------------------------------------------
* This program will implement a stack in order to be able to push, pop,
* peek, check the size, and check if the stack is empty.
* ---------------------------------------------------------------------
* INPUT:
* choice:	Will get the choice from the user and turn it into the enum
*
* OUTPUT:
* stacks:	Will display a specific item depending on what the user chooses
*************************************************************************/

int main() {
/***********************************************************************
* CONSTANTS
* ---------------------------------------------------------------------------
* OUTPUT - USED FOR CLASS HEADING
* ---------------------------------------------------------------------------
* PROGRAMMER	: Oscar Solis-Pacheco
* CLASS			: CS1B
* SECTION		: MTWTH: 5:00p - 7:20p
* LAB			: 9
* LAB_NAME		: Implement a Stack
************************************************************************/
	// Displaying the class header
	DisplayClassHeader();
	// Getting the stack
	stacks stack;
	// Declaring the choice variable
	int choice;
	// Assigning zero to it
	choice = 0;
	// Creating the loop control variable
	bool run;
	// Assigning true to it
	run = true;
	// Creating the program loop
	while (run) {
		// Getting the enum
		Menu options;
		// Assigning the enum
		options = End;
		// Getting the menu
		menu();
		// Getting the choice from the user
		cin >> choice;
		// If they didn't choose a number
			if (cin.fail()) {
				// Display error message
			cout << "\n\n***** Please enter a NUMBER between 0 and 5 *****\n\n";
				// Clear what they chose
			cin.clear();
				// Allow them to choose something else
			cin.ignore(1000, '\n');
			// If they chose zero it ends the program
			}else if (choice == 0) {
				// End the loop
				run = false;
				// If they choose one it will push a person to the stack
			} else if (choice == 1) {
				// Assigning push to the enum
				options = Push;
				// If they choose two it will pop the most recent person
			} else if (choice == 2) {
				// Assigning pop to the enum
				options = Pop;
				// If they choose three check if the stack is empty
			} else if (choice == 3) {
				// Assigning isEmpty to the enum
				options = isEmpty;
				// If they choose four, peek
			} else if (choice == 4) {
				// Assigning peek to the enum
				options = Peek;
				// If they choose five then check the size of the stack
			} else if (choice == 5) {
				// Assigning size to the enum
				options = Size;
				// If their chose is less than zero, then that's an error
			} else if (choice < 0) {
				// Error message
				cout << "\n***** The number " << choice << " is an invalid entry     *****\n";
				// Error message
				cout << "***** Please enter a number between 0 and 5 *****\n\n";
				// If their chose is more than five, then that's an error
			} else if (choice > 5) {
				// Error message
				cout << "\n***** The number " << choice << " is an invalid entry      *****\n"; 
				// Error message
				cout << "***** Please enter a number between 0 and 5 *****\n\n";
			}
			// Checking for option one (PUSH)
		 if (options == 1) {
			 // Asking who they want to add
			 cout << endl << "Who would you like to add? " << endl << endl;
			 // Asking for the name of the person they wish to add
				cout << "Enter Name:\t";
				// Clearing for the user
				cin.ignore(1000, '\n');
				// Getting a full name
				getline(cin, stack.name);
				// Pushing the full name to the stack
				stack.names.push(stack.name);
				// Asking for the gender
				cout << "Enter Gender:   ";
				// Getting the gender
				cin >> stack.gender;
				// Pushing the gender to the stack
				stack.genders.push(stack.gender);
				// Asking for the age
				cout << "Enter Age:\t";
				// Getting the age
				cin >> stack.age;
				// Pushing the age to the stack
				stack.ages.push(stack.age);
				// New line
				cout << endl;
				// If they chose option two (POP)
			} else if (options == 2) {
				// If it is not empty
				if (!stack.names.empty()) {
					// Display message
					cout << "\nPOPPING\n";
					// Display message with name from stack
					cout << "Name:\t" << stack.names.top() << endl;
					// Display message with gender from stack
					cout << "Gender: " << stack.genders.top() << endl;
					// Display message with age from stack
					cout << "Age:\t" << stack.ages.top() << endl << endl;
					// Pop name
					stack.names.pop();
					// Pop gender
					stack.genders.pop();
					// Pop age
					stack.ages.pop(); 
				// Else it is empty
				} else {
					// Error message that the stack is empty
					cout << "\nCan\'t POP from an empty stack!" << endl << endl;
				}
				// IF they choose option three (ISEMPTY)
			} else if (options == 3) {
				// If the stack is NOT empty
				if (!stack.names.empty()) {
					// Display message that the stack is NOT empty
					cout << "\nThe stack is NOT empty." << endl << endl;
				}
				// Else it is empty
				else {
					// Display message that the stack is empty
					cout << "\nYes, the stack is empty." << endl << endl;
				}
				// If they choose option four (PEEKING)
			} else if (options == 4) {
				// Checking if the stack is not empty
				if (!stack.names.empty()) {
					// Display message
					cout << "\nPEEKING at\n";
					// Display message with name of who we peeking
					cout << "Name:\t" << stack.names.top() << endl;
					// Display message of the gender we peeking at
					cout << "Gender: " << stack.genders.top() << endl;
					// Display message of the age we are peeking at
					cout << "Age:\t" << stack.ages.top() << endl << endl;
				// Else the stack is empty
				} else {
					// Display message that the stack is empty
					cout << "\nThere is nobody to PEEK at!!" << endl << endl;
				}
				// If they choose option five (SIZE)
			} else if (options == 5) {
				 // Check if the stack is NOT empty
				if (!stack.names.empty()) {
					// Checking if there is only one person on the stack
					if (stack.names.size() == 1) {
						// Display message for one person on the stack
						cout << "\nThere is one person on the stack." << endl << endl;
						// Else there are more than one person on the stack
					} else {
						// Display message for more than one person on the stack
						cout << "\nThere are " << stack.names.size() << " people on the stack." << endl << endl;
					}
					// Else the stack is empty
				} else {
					// Display message that the stack is empty
					cout << "\nNobody is on the stack!" << endl << endl;
				} // Close else
			} // Close else if
	} // End of while loop
} // End of main function


/* MENU FUNCTION **************
*
*
* Displays the menu to the user
*******************************/
void menu()
{
	cout << "STACK MENU:" << endl;
	cout << "1-Add a person (PUSH)" << endl;
	cout << "2-Remove a person (POP)" << endl;
	cout << "3-Is the stack empty? (ISEMPTY)" << endl;
	cout << "4-Who is on top? (PEEK)" << endl;
	cout << "5-How many people are there(SIZE)" << endl;
	cout << "0-to Exit" << endl;
	cout << "Enter a command? ";
} // END OF MENU FUNCTION
