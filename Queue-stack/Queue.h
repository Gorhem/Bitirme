//@authors
//Mehmet Taha SAHIN 130144049
//Gorhem Gokturk SAKA 130144046
//



#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include "linklist.h"


class Queue {
	struct Node* head, *tail;
public:
	Queue() {
		head = tail = NULL;
	}
	void enQueue(int elem);
	int deQueue();
	void displayQueue();
	void menu();
	int elem;
	int choice;
};




#endif