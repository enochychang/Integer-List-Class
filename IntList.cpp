#include <iostream>
#include "IntList.h"

using std::cout;

// struct IntNode {
//     int data;
//     IntNode* next;
//     IntNode(int data) : data(data), next(0) {}
// };

//Encapsulated (Private) Data Fields

	// IntNode* head;
	// IntNode* tail;
	
//Public Interface (Public Member Functions)

	//Deallocates all remaining dynamically allocated memory 
	//(all remaining IntNodes).
		IntList::~IntList() {
			IntNode* accessor = head;
			IntNode* temp;
			while (accessor != 0) {
				temp = accessor->next;
				delete accessor;
				accessor = temp;
			}
		}

	//Displays to a single line all of the int values stored in the list, 
	//each separated by a space. This function does NOT output a newline 
	//or space at the end.
		void IntList::display() const {
			IntNode* accessor = head;
			while (accessor != 0) {
				if (accessor->next == 0) {
					cout << accessor->data;
				}
				else {
					cout << accessor->data << " ";
				}
				accessor = accessor->next;
			}
		}

	//Inserts a data value (within a new node) at the front end of the list.
		void IntList::push_front(int value) {
			IntNode* temp = head;
			head = new IntNode(value);
			head->next = temp;
		}

	//Removes the value (actually removes the node that contains the value) 
	//at the front end of the list. Does nothing if the list is already empty.
		void IntList::pop_front() {
			if (empty()) {
				return;
			}
			else {
				IntNode* temp = head->next;
				if (head == tail) {
					delete head;
					head = temp;
					tail = temp;
				}
				else {
					delete head;
					head = temp;
				}
			}
		}

	//Returns true if the list does not store any data values (does not have 
	//any nodes), otherwise returns false.
		bool IntList::empty() const {
			//ternary operator
			return (head == 0) ? true : false;
		}



