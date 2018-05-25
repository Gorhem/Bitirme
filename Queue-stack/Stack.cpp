//@authors
//Mehmet Taha SAHIN 130144049
//Gorhem Gokturk SAKA 130144046
//

#include <iostream>
#include "Stack.h"

using namespace std;

void Stack::push(int elem) {
	/*cout << "Enter your element to be inserted the queue:" << endl;
	cin >> elem;*/
	Node* pointer = new Node;
	pointer->data = elem;
	pointer->next = NULL;
	if (head == NULL) {
		head = pointer;
	}
	else if (head->next == NULL) {
		Node* temp = head;
		//cout << temp->data;
		pointer->next = temp;
		//cout << pointer->next->data;
		tail = temp;
		//cout << tail->data;
		head = pointer;
	}
	else {
		Node* temp = head;
		pointer->next = temp;
		head = pointer;
	}
	//cout << "Element has been inserted in the queue!" << endl;
}

void Stack::pop() {
	if (head == NULL) {
		cout << "Stack is empty!" << endl;
	}
	else {
		Node* temp = head;
		head = head->next;

		delete temp;
	}
	
	
}

int Stack::peek() {
	
	return head->data;

}

void Stack::displayStack() {
	Node* pointer1 = head;
	if (head == NULL) {
		cout << "Queue is empty!" << endl;
	}
	else
		cout << "Elements of your QUEUE!" << endl;
	while (pointer1 != NULL) {
		cout << pointer1->data << endl;
		pointer1 = pointer1->next;
	}
	cout << "End" << endl;
}

bool Stack::isEmpty() {
	if (head == NULL) {
		return true;
	}
	return false;
}

void Stack::clear() {
	while (!isEmpty()) {
		pop();
	}
	
}


void Stack::menu() {
	while (choice != 7)
	{

		cout << "===============================================================" << "\n";
		cout << "              MENU - Stack(FILO - First In Last Out)                                 " << "\n";
		cout << "===============================================================" << "\n";
		cout << "     1. Push" << "\n";
		cout << "     2. Pop" << "\n";
		cout << "     3. Peek" << "\n";
		cout << "     4. Is Empty?" << "\n";
		cout << "     5. Clear" << "\n";
		cout << "     6. Display Stack" << "\n";
		cout << "     7. Exit" << "\n";
		cout << "===============================================================" << "\n";
		cout << endl;
		cout << "===============================================================" << "\n";
		cout << endl;
		cout << endl;
		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter your element to be inserted the queue:" << endl;
	        cin >> elem;
			push(elem);
			break;
		case 2:
			pop();
			break;
		case 3:
			cout<< "You peeek " << peek();
			break;
		case 4:
			if (isEmpty()) {
				cout << "Stack is empty!";
			}
			else {
				cout << "Stack is not empty!";
			}
			break;
		case 5:
			clear();
			cout << "Stack cleared";
			break;
		case 6:
			//cout << head->data << tail->data;
			displayStack();
			break;
		default:
			cout << "Please enter correct choice(1-7)!!";
			break;
		}
	}
}