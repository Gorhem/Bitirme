#include <iostream>

#include "avlTree.h"
#include <fstream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <chrono>
using namespace std;
void avlWriteDotFile(avlTree avl) {
	FILE * pFile;
	pFile = fopen("myFileAvl.txt", "w");
	if (pFile != NULL)
	{
		avl.to_bst_print_dot(pFile);

		fclose(pFile);
	}
}

void avlOperations(int choose) {


	int insertNum, deleteNum, searchNum;
	string insertData, deleteData, searchData;
	ifstream insertFile, deleteFile, searchFile;
	insertFile.open("insert.txt");
	deleteFile.open("deletion.txt");
	searchFile.open("search.txt");

	avlTree avl;
	

	if (choose == 1) {
		auto start = std::chrono::high_resolution_clock::now();
		while (getline(insertFile, insertData)) {
			insertNum = stoi(insertData);

			avl.avlInsert(insertNum);


		}

		auto finish = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
		avlWriteDotFile(avl);
	}
	else if (choose == 2) {
		while (getline(insertFile, insertData)) {
			insertNum = stoi(insertData);

			avl.avlInsert(insertNum);


		}
		auto start = std::chrono::high_resolution_clock::now();
		while (getline(deleteFile, deleteData)) {
			deleteNum = stoi(deleteData);

			avl.avlDelete(deleteNum);


		}

		auto finish = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
	}
	else if (choose == 3) {
		while (getline(insertFile, insertData)) {
			insertNum = stoi(insertData);

			avl.avlInsert(insertNum);


		}
		//avl.tobstsearch(2);
		auto start = std::chrono::high_resolution_clock::now();
		while (getline(searchFile, searchData)) {
			searchNum = stoi(searchData);

			avl.tobstsearch(searchNum);


		}

		auto finish = std::chrono::high_resolution_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";
	}
	
}

int main() {

	int choose;
	cout << "Choose your task : " << endl;
	cout << "1. Insert : \n2. Delete : \n3. Search :" << endl;
	cin >> choose;

	avlOperations(choose);
	

	
	return 0;
}