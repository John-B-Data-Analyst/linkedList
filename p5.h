/****************************************************************************************
typedef statement: this is the data type of the items in the list. In our program it is
integer. Data items are represented by the word 'Item'

CONSTRUCTOR

Precondition: none
Postcondition: List is initialized to its null state. In our case this is an empty list
List()

COPY CONSTRUCTOR
Precondition: none
Postcondition: The new list has been initialized as a copy of the initial list
List(const List& source)

DESTRUCTOR
Never needs to be explicitly called. Destroys Lists when the user/program is done with them
to free up memory
Precondition: none
Postcondition: none
~List()

MUTATOR FUNCTIONS

void make_empty()
Precondition: none
Postcondition: The list becomes empty

void insert(const Item& entry)
Precondition: entry is not already in the list
Postcondition: the value entry has been inserted into the correct place in the List

void remove(const Item& target)
Precondition: target is actually in the List
Postcondition: the value target is removed from the List

void operator = (const List& source)
Precondition: The given list has been assigned a copy of the source list

CONSTANT MEMBER FUNCTIONS

bool empty() const
Precondition: none
Postcondition: Return TRUE/1 if the given List is empty, return FALSE/0 if the given List
is not empty

size_t length() const
Precondition: none
Postcondition: The total number of items in the list is returned

bool present(const Item& target) const
Precondition: none
Postcondition: return TRUE/1 if target is actually in the list, return FALSE/0 if target is
not in the list

int kth (int k) const
Precondition: The list cannot be empty. the value k must be at least 1 and smaller than the
total number of items in the list

FRIEND FUNCTION
friend ostream& operator << (ostream& out_s, const List& b)
Precondition: none
Postcondition: All of the values from List b is written to the output stream 

PRIVATE FUNCTION
Node* get_node(const Item& entry, Node* link);
Precondition: The number of the entry must exist
Postcondition: a pointer to a Node is returned
*****************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


#ifndef P5_h
#define P5_h

namespace csci301_P5_1
{
class List
{
	public:
	
	//this is the data type of the items in the list - int. Data items are 
	// represented by the word Item
	typedef int Item;	

	//Constructors
	List() {first = NULL;}
	List(const List& source);
	
	//Destructor
	~List();
	
	// Mutator member functions
	void make_empty();
	void insert(const Item& entry);
	void remove(const Item& target);
	void operator = (const List& source);
	
	// Constant member functions
	bool empty() const {return first == NULL;}
	std::size_t length() const;
	bool present(const Item& target) const;
	Item kth(std::size_t k) const;
	
	// Friend function for the List class
	friend std::ostream& operator << (std::ostream& out_s, const List& l);
	
	private:
	// Private data members:	
	struct Node
	{
		Item data;	
		Node *next;
	};
	
	Node *first;
	
	//Private function:
	Node* get_node(const Item& entry, Node* link);
	
};

}
#endif