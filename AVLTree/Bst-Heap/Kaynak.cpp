#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <queue>
#include<fstream>
#include <chrono>




int * myarray = new int[600001];
int heapnum = 1;
void traverseheap() {
	for (int i = 1; i < heapnum; i++) {
		cout << myarray[i] << " ";
	}
	cout << endl;
}

void insertHeap(int number) {
	myarray[heapnum] = number;
	int counter = heapnum;
	heapnum++;
	bool flag = true;
	while (counter > 1 && flag) {
		if (myarray[counter] < myarray[counter / 2]) {
			int temp = myarray[counter];
			myarray[counter] = myarray[counter / 2];
			myarray[counter / 2] = temp;
		}
		else {
			flag = false;
		}
		counter = counter / 2;
	}
	//traverseheap();
}
void deleteHeap() {
	int counter = 1;
	heapnum--;
	int temp = myarray[counter];
	myarray[counter] = myarray[heapnum];
	myarray[heapnum] = temp;
	bool flag = true;
	while (flag) {
		if (counter * 2 + 1 < heapnum) {
			if (myarray[counter] <= myarray[counter * 2] && myarray[counter] <= myarray[counter * 2 + 1]) {
				flag = false;

			}
			else {
				if (myarray[counter * 2 + 1] < myarray[counter * 2]) {
					temp = myarray[counter];
					myarray[counter] = myarray[counter * 2 + 1];
					myarray[counter * 2 + 1] = temp;
					counter = counter * 2 + 1;

				}
				else {
					temp = myarray[counter];
					myarray[counter] = myarray[counter * 2];
					myarray[counter * 2] = temp;
					counter = counter * 2;
				}

			}
		}
		else {
			if (counter * 2 < heapnum && myarray[counter] > myarray[counter * 2]) {

				temp = myarray[counter];
				myarray[counter] = myarray[counter * 2];
				myarray[counter * 2] = temp;


			}
			flag = false;

		}
	}
	//traverseheap();
}

struct bstnode {
	int data;
	bstnode *left;
	bstnode *right;
	bstnode(int a) {
		data = a;
		left = NULL;
		right = NULL;
	}
};
bstnode *root = NULL;
void insertbst(bstnode * node, bstnode *prev, int insertdata) {
	if (node == NULL) {
		bstnode *newnode = new bstnode(insertdata);
		node = newnode;
		if (prev->data <= node->data) {
			prev->right = node;
		}
		else
		{
			prev->left = node;
		}
		//cout << insertdata << "eklendi" << endl;
	}
	else if (node->data <= insertdata) {
		insertbst(node->right, node, insertdata);
	}
	else {
		insertbst(node->left, node, insertdata);
	}

}
void insertstart(int data) {
	if (root == NULL) {
		bstnode *newnode = new bstnode(data);
		root = newnode;

	}
	else if (root->data <= data) {

		insertbst(root->right, root, data);
	}
	else {

		insertbst(root->left, root, data);
	}
}
bool searchbst(bstnode *node, int data) {
	if (node == NULL) {
		return false;
	}
	else if (node->data == data) {
		return true;
	}
	else if (node->data < data) {
		return searchbst(node->right, data);
	}
	else {
		return searchbst(node->left, data);
	}
}
void searchanswer(int data) {
	if (searchbst(root, data)) {
		//cout << data << " bulundu." << endl;
	}
	else {
		cout << data << " bulunamadý." << endl;
	}
}
int leftmostreplacebst(bstnode *node, bstnode * prev) {
	if (node->right == NULL) {

		if (node->left == NULL) {
			if (prev->data <= node->data) {
				prev->right = NULL;
			}
			else
			{
				prev->left = NULL;
			}
		}
		else {
			if (prev->data <= node->data) {
				prev->right = node->left;
			}
			else
			{
				prev->left = node->left;
			}

		}
		return node->data;
	}
	else {
		return leftmostreplacebst(node->right, node);
	}
}
void deletebst(bstnode *node, bstnode *prev, int data) {
	if (node == NULL) {
		//cout << data << " Not Found!" << endl;
		return;
	}
	else if (node->data == data) {
		//cout << data << " Deleted!" << endl;
		//checkleftmost;
		if (node->left == NULL) {
			if (prev == NULL) {
				node = node->right;
			}
			else
			{
				if (prev->data <= node->data) {
					prev->right = node->right;
				}
				else
				{
					prev->left = node->right;
				}

			}
		}
		else
		{
			node->data = leftmostreplacebst(node->left, node);

		}
	}
	else if (node->data < data) {
		return deletebst(node->right, node, data);
	}
	else {
		return deletebst(node->left, node, data);
	}
}
void traversebst(bstnode *node) {
	if (node == NULL) {
		return;
	}

	else if (node == root) {

	}
	if (node->right != NULL) {

		traversebst(node->right);
	}
	if (node->left != NULL) {

		traversebst(node->left);
	}



}

int main() {
	int insertNum, del, search;
	string insertData, deleteData, searchData;
	ifstream insertFile, deleteFile, searchFile;
	insertFile.open("insert.txt");
	deleteFile.open("deletion.txt");
	searchFile.open("search.txt");
	vector<int> v;
	

	int choose;
	cout << "Choose your task : " << endl;
	cout << "1. Heap : \n2. BST : " << endl;
	cin >> choose;

	if (choose == 1) {
		cout << "Choose your task : " << endl;
		cout << "1. Insert : \n2. Delete :" << endl;
		cin >> choose;
		if (choose == 1) {
			//Insert
			auto start = std::chrono::high_resolution_clock::now();
			while (getline(insertFile, insertData)) {
				insertNum = stoi(insertData);

				insertHeap(insertNum);

			}

			auto finish = std::chrono::high_resolution_clock::now();
			std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
		}
		else if (choose == 2) {
			//Delete
			int a= 50000;
			
			while (getline(insertFile, insertData)) {
				insertNum = stoi(insertData);

				insertHeap(insertNum);

			}
			auto start = std::chrono::high_resolution_clock::now();

			for (int i = 0; i < a; i++) {

				deleteHeap();



			}
			auto finish = std::chrono::high_resolution_clock::now();
			std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";

		}
		else {
			cout << "Please enter a number which is in choice" << endl;
		}

	}
	else if (choose == 2) {
		cout << "Choose your task : " << endl;
		cout << "1. Insert : \n2. Delete : \n3. Search :" << endl;
		cin >> choose;
		if (choose == 1) {
			// Insert
			auto start = std::chrono::high_resolution_clock::now();
			while (getline(insertFile, insertData)) {
				insertNum = stoi(insertData);

				insertstart(insertNum);


			}

			auto finish = std::chrono::high_resolution_clock::now();
			std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
		}
		else if (choose == 2) {
			//Delete
			while (getline(insertFile, insertData)) {
				insertNum = stoi(insertData);

				insertstart(insertNum);


			}
			auto start = std::chrono::high_resolution_clock::now();

			while (getline(deleteFile, deleteData)) {
				del = stoi(deleteData);
				deletebst(root, NULL, del);

			}

			auto finish = std::chrono::high_resolution_clock::now();
			std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";

		}
		else if (choose == 3) {
			//Search
			while (getline(insertFile, insertData)) {
				insertNum = stoi(insertData);

				insertstart(insertNum);


			}
			auto start = std::chrono::high_resolution_clock::now();
			while (getline(searchFile, searchData)) {
				search = stoi(searchData);

				searchanswer(search);


			}
			auto finish = std::chrono::high_resolution_clock::now();
			std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";


		}
		else {
			cout << "Please enter a number which is in choice" << endl;
		}
	}

	
	


	return 0;


}