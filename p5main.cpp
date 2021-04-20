// Created By: John Blee
// Due 15 February 2015
// CSCI 301, Dr. Julstrom
// Project 5
/* This program utilizes a menu to implement a linked list. The List is defined in a class
that is included in this main program. When the class object is defined, the program uses
a do-while loop and switch statement to power the menu. The loop waits for input, and the
switch statement carries out the correct operation based on the user input.
*/

#include <cassert>         // Provides assert()
#include <cstdlib>         // Provides size_t
#include <iostream>
#include <iomanip>         // Provides setw()
#include <fstream>
#include "p5.h"
using namespace std;
using namespace csci301_P5_1;

void displayMenu();

int main()
{
	char letter;
	int value, numElements, present, kth;
	bool empty;
	List listOne;
	
	displayMenu();			//Call the function to display the menu
	do
	{
		cout << "--> ";		//Issue a prompt
		cin >> letter;		//Read a command letter
		switch (letter)		//Carry out the command
		{
		  case 'e':
		  		cout << "The list has been reinitialized to empty.\n";
		  		listOne.make_empty();
		  		break;
		  		
		  case 'i': cin >> value;
		  		cout << value << " has been inserted into the list.\n";
		  		listOne.insert(value);
		  		break;
		  
		  case 'r': cin >> value;
		  		cout << value << " has been removed from the list.\n";
		  		listOne.remove(value);
		  		break;
		  
		  case 'm': 
		  		empty = listOne.empty();
		  		if(empty == 1)
		  			cout << "The list is empty.\n";
		  		else
		  			cout << "The list is NOT empty.\n";
		  		break;
		  
		  case 'l':
		  		numElements = listOne.length();
		  		cout << "There are " << numElements << " elements in the list.\n";
		  		break;
		  
		  case 'p': cin >> value;
		  		present = listOne.present(value);
		  		if(present == 1)
		  			cout << value << " is in the list.\n";
		  		else
		  			cout << value << " is NOT in the list.\n";
		  		break;
		  
		  case 'k': cin >> value;
		  		cout << "code to display the " << value << "th value in the list\n";
		  		kth = listOne.kth(value);
		  		cout << "The " << value << "th value of the list is " << kth << ".\n";
		  		break;
		  
		  case 'w':
		  		cout << "Here are the contents of the list:\n";
		  		cout << listOne << endl;
		  		break;
		  
		  case 'h': displayMenu();
		  		break;
		  		
		}
	}while(letter != 'q');			// quit program when 'q' is selected

	return 0;
}

/****************************************************************************************/
//Precondition: none
//Postcondition: the following code is displayed in the terminal
void displayMenu()
{
	cout << endl;
	cout << "This program responds to commands the user enters to" << endl;
	cout << "manipulate an ordered list of integers, which is" << endl;
	cout << "initially empty. In the following commands, k1 is a" << endl;
	cout << "position in the list, and v is an integer." << endl;
	cout << " e -- Re-initialize the list to be empty." << endl;
	cout << " i v -- Insert the value v into the list." << endl;
	cout << " r v -- Remove the value v from the list." << endl;
	cout << " m -- Is the list empty?" << endl;
	cout << " l -- Report the length of the list." << endl;
	cout << " p v -- Is the value v present in the list?" << endl;
	cout << " k k1 -- Report the k1th value in the list." << endl;
	cout << " w -- Write out the list." << endl;
	cout << " h -- See this menu." << endl;
	cout << " q -- Quit." << endl << endl;
}
/****************************************************************************************/
