//@authors
//Mehmet Taha SAHIN 130144049
//Gorhem Gokturk SAKA 130144046
//


#ifndef STACK_H
#define STACK_H
#include <string>
#include "linklist.h"


class Stack {
	struct Node* head, *tail;
public:
	Stack() {
		head = tail = NULL;
	}
	void push(int elem);
	void pop();
	int peek();
	bool isEmpty();
	void clear();
	void displayStack();
	void menu();
	int elem;
	int choice;
};




#endif
