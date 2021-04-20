/*
Invariant:
- The items in the List are stored in a linked list in ascending order
- The member variable called 'first' is a pointer that points to the first node in the
Linked List. If it is an empty List, first points to the nullptr.
*/
#include <cassert>         // Provides assert()
#include <cstdlib>         // Provides size_t
#include <iostream>
#include <iomanip>         // Provides setw()
#include <fstream>
#include "p5.h"
using namespace std;


namespace csci301_P5_1
{
	//Copy constructor
	List::List(const List& source)
	{
		Node* p;
		Node* last;
		
		if(source.first == NULL)
			first = NULL;
		else
		{
			first = get_node(source.first -> data, NULL);	//copy the first node 
			last = first;
			p = source.first -> next;
			while(p != NULL)		//copy remaining Nodes
			{
				last -> next = get_node(p -> data, NULL);
				last = last -> next;
				p = p -> next;
			}
		}
	}
	
	//Destructor
	List::~List()
	{
		Node* temp;
		
		while(first != NULL)
		{
			temp = first;
			first = first -> next;
			delete temp;
		}
	}
	
	//Mutator member functions
	void List::make_empty()
	{
		Node* temp;
		
		while(first != NULL)
		{
			temp = first;
			first = first -> next;
			delete temp;
		}
	}
	
	void List::insert(const Item& entry)
	{
		Node *prev;
		
		//assert(!present(entry));
		
		if(first == NULL || entry < first -> data)
			first = get_node(entry, first);
		else
		{
			prev = first;
			while(prev->next != NULL && prev->next->data < entry)
				prev = prev->next;
			prev->next = get_node(entry, prev->next);
		}
	}
	
	void List::remove(const Item& target)
	{
		Node *temp;
		Node *prev;
		
		//assert(present(target));
		
		prev = first;
		if(prev->data == target)
		{
			first = first->next;
			delete prev;
		}
		else
		{
			while(prev->next != NULL && prev->next->data < target)
				prev = prev->next;
			temp = prev->next;
			prev->next = temp->next;
			delete temp;
		}
	}
	
	void List::operator = (const List& source)
	{
		Node* p;
		Node* last;
		
		if(&source != this)
		{
			make_empty();
			if(source.first != NULL)
			{
				first = get_node(source.first->data, NULL);	//copy the first Node
				last = first;
				p = source.first->next;
				while(p != NULL)
				{
					last->next = get_node(p->data, NULL);
					last = last->next;
					p = p->next;
				}
			}
		}
	}

	
	// Constant member functions
	
	size_t List::length() const
	{
		Node *cursor;
		size_t count;
		
		count = 0;
		for(cursor = first; cursor != NULL; cursor = cursor->next)
			count++;
		
		return count;
	}
	
	bool List::present(const Item& target) const
	{
		Node* cursor;
		
		for(cursor = first; 
			cursor != NULL && cursor->data != target;
			cursor = cursor->next)
			;
		return(cursor != NULL);
	}
	
	List::Item List::kth(size_t k) const
	{
		Node *cursor;
		size_t count;
		
		//assert(1 <= k && k <= length());
		
		cursor = first;
		for(count = 1;count < k; count++)
			cursor = cursor->next;
			
		return cursor->data;
	}
	
	//Friend Function
	ostream& operator << (ostream& out_s, const List& l)
	{
		List::Node *cursor;
		
		out_s << '(';
		for(cursor = l.first;
		    cursor != NULL && cursor->next != NULL;
		    cursor = cursor->next)
		    		out_s << cursor->data;
		if(cursor != NULL)
			out_s << cursor->data;
		out_s << ')';
		
		return out_s;
	}
	
	//Private Function:
	List::Node* List::get_node(const Item& entry, Node* link)
	{
		Node *temp;
		
		temp = new Node;
		temp -> data = entry;
		temp -> next = link;
		return temp;
	}
}