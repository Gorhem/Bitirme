//@authors
//Mehmet Taha SAHIN 130144049
//Gorhem Gokturk SAKA 130144046
//




#include <iostream>
#include "queue.h"
#include "Stack.h"
#include<fstream>
#include <stdio.h>
#include <string>
#include <chrono>
using namespace std;

bool findTheGoalWithOptimal(string ** myMaze, int size, int cori, int corj, int mazePow, bool decision,int * EECC);
bool findTheGoalWithQueue(string ** myMaze, int size, int cori, int corj, int mazePow, int *EECC) {
	Queue que;
	bool findGoal = false;
	myMaze[cori][corj] = "*";
	int reqTime = 0;
	if (cori - 1 >= 0) {//find upper space
		if (myMaze[cori - 1][corj] == "G") {
			return true;
		}
		else if (myMaze[cori - 1][corj] == " ") {
			que.enQueue((cori-1)*mazePow+corj);
			reqTime++;
			myMaze[cori - 1][corj] = "e";
		}

	}
	

	if (cori + 1 < size) {//find lower space
		if (myMaze[cori + 1][corj] == "G") {
			return true;
		}
		else if (myMaze[cori + 1][corj] == " ") {
			que.enQueue((cori + 1) * mazePow + corj);
			myMaze[cori + 1][corj] = "e";
			reqTime++;
		}

	}


	if (corj - 1 >= 0) {//find left space
		if (myMaze[cori][corj - 1] == "G") {
			return true;
		}
		else if (myMaze[cori][corj - 1] == " ") {
			que.enQueue(cori * mazePow + corj - 1);
			myMaze[cori][corj-1] = "e";
			reqTime++;
		}

	}

	if (corj + 1 < size) {//find right space
		if (myMaze[cori][corj + 1] == "G") {
			return true;
		}
		else if (myMaze[cori][corj + 1] == " ") {
			que.enQueue((cori)* mazePow + corj + 1);
			myMaze[cori][corj + 1] = "e";
			reqTime++;
		}

	}
	
	for (int req = 0; req < reqTime; req++) {
		int deqNumber = que.deQueue();
		if (!findGoal) {
			findGoal = findTheGoalWithQueue(myMaze, size, deqNumber / mazePow, deqNumber % mazePow,mazePow,EECC);
			EECC[0]++;
		}
		else {
			EECC[1]++;
		}
		
	}
	
	if (!findGoal) {
		myMaze[cori][corj] = "e";
	}
	return findGoal;

}

bool findTheGoalWithStack(string ** myMaze, int size, int cori, int corj, int mazePow, int *EECC) {
	Stack sta;
	bool findGoal = false;
	myMaze[cori][corj] = "*";
	int reqTime = 0;
	if (cori - 1 >= 0) {//find upper space
		if (myMaze[cori - 1][corj] == "G") {
			return true;
		}
		else if (myMaze[cori - 1][corj] == " ") {
			sta.push((cori - 1) * mazePow + corj);
			myMaze[cori - 1][corj] = "e";
			reqTime++;
		}

	}


	if (cori + 1 < size) {//find lower space
		if (myMaze[cori + 1][corj] == "G") {
			return true;
		}
		else if (myMaze[cori + 1][corj] == " ") {
			sta.push((cori + 1) * mazePow + corj);
			myMaze[cori + 1][corj] = "e";
			reqTime++;
		}

	}


	if (corj - 1 >= 0) {//find left space
		if (myMaze[cori][corj - 1] == "G") {
			return true;
		}
		else if (myMaze[cori][corj - 1] == " ") {
			sta.push(cori * mazePow + corj - 1);
			myMaze[cori][corj -1] = "e";
			reqTime++;
		}

	}


	if (corj + 1 < size) {//find right space
		if (myMaze[cori][corj + 1] == "G") {
			return true;
		}
		else if (myMaze[cori][corj + 1] == " ") {
			sta.push((cori)* mazePow + corj + 1);
			myMaze[cori][corj+1] = "e";
			reqTime++;
		}

	}
	
	for (int req = 0; req < reqTime; req++) {
		int deqNumber = sta.peek();
		//cout << deqNumber<<endl;
		sta.pop();
		if (!findGoal) {
			findGoal = findTheGoalWithStack(myMaze, size, deqNumber / mazePow, deqNumber % mazePow,mazePow,EECC);
			EECC[0]++;
		}
		else {
			EECC[1]++;
		}

	}

	if (!findGoal) {
		myMaze[cori][corj] = "e";
	}
	return findGoal;

}
/*
bool OptGoalSearch(string ** myMaze, int size, int cori, int corj) {
	if (cori - 1 >= 0) {//find upper space
		if (myMaze[cori - 1][corj] == "G") {
			return true;
		}
	}


	if (cori + 1 < size) {//find lower space
		if (myMaze[cori + 1][corj] == "G") {
			return true;
		}
	}


	if (corj - 1 >= 0) {//find left space
		if (myMaze[cori][corj - 1] == "G") {
			return true;
		}
	}


	if (corj + 1 < size) {//find right space
		if (myMaze[cori][corj + 1] == "G") {
			return true;
		}
	}
	return false;
}
int OptPush(string ** myMaze, int size, int cori, int corj, int mazePow, Stack sta) {
	int reqTime = 0;
	if (cori - 1 >= 0) {//find upper space
		if (myMaze[cori - 1][corj] == " ") {
			sta.push((cori - 1) * mazePow + corj);
			reqTime++;
		}

	}


	if (cori + 1 < size) {//find lower space
		if (myMaze[cori + 1][corj] == " ") {
			sta.push((cori + 1) * mazePow + corj);
			reqTime++;
		}

	}


	if (corj - 1 >= 0) {//find left space
		if (myMaze[cori][corj - 1] == " ") {
			sta.push(cori * mazePow + corj - 1);
			reqTime++;
		}

	}


	if (corj + 1 < size) {//find right space
		if (myMaze[cori][corj + 1] == " ") {
			sta.push((cori)* mazePow + corj + 1);
			reqTime++;
		}

	}
	return reqTime;
}
int OptEnqueue(string ** myMaze, int size, int cori, int corj, int mazePow, Queue que) {
	int reqTime = 0;
	if (cori - 1 >= 0) {//find upper space
		if (myMaze[cori - 1][corj] == " ") {
			que.enQueue((cori - 1)*mazePow + corj);
			reqTime++;
		}

	}


	if (cori + 1 < size) {//find lower space
		if (myMaze[cori + 1][corj] == " ") {
			que.enQueue((cori + 1) * mazePow + corj);
			reqTime++;
		}

	}


	if (corj - 1 >= 0) {//find left space
		if (myMaze[cori][corj - 1] == " ") {
			que.enQueue(cori * mazePow + corj - 1);
			reqTime++;
		}

	}


	if (corj + 1 < size) {//find right space
		if (myMaze[cori][corj + 1] == " ") {
			que.enQueue((cori)* mazePow + corj + 1);
			reqTime++;
		}
	}

	return reqTime;
}
bool OptPeekPush(string ** myMaze, int size, int cori, int corj, int mazePow, Stack sta, int reqTime, bool decision) {
	bool findGoal = false;
	for (int req = 0; req < reqTime; req++) {
		int deqNumber = sta.peek();
		//cout << deqNumber<<endl;
		sta.pop();
		if (!findGoal) {
			findGoal = findTheGoalWithOptimal(myMaze, size, deqNumber / mazePow, deqNumber % mazePow, mazePow, decision);
			decision = !decision;
		}

	}
	return findGoal;
}
bool OptDequeue(string ** myMaze, int size, int cori, int corj, int mazePow, Queue que, int reqTime, bool decision) {
	bool findGoal = false;
	for (int req = 0; req < reqTime; req++) {
		int deqNumber = que.deQueue();
		if (!findGoal) {
				findGoal = findTheGoalWithOptimal(myMaze, size, deqNumber / mazePow, deqNumber % mazePow, mazePow, decision);
				decision = !decision;
		}

	}
	return findGoal;
}
bool findTheGoalWithOptimal(string ** myMaze, int size, int cori, int corj, int mazePow, bool decision) {
	Stack sta;
	Queue que;
	int reqTime;
	bool findGoal;
	myMaze[cori][corj] = "*";
	return OptGoalSearch(myMaze, size, cori, corj);
	if (decision) {
		reqTime = OptPush(myMaze, size, cori, corj, mazePow, sta);
		findGoal = OptPeekPush(myMaze, size, cori, corj, mazePow, sta, reqTime, decision);
	}
	else {
		reqTime = OptEnqueue(myMaze, size, cori, corj, mazePow, que);
		findGoal = OptDequeue(myMaze, size, cori, corj, mazePow, que, reqTime, decision);
	}
	
	if (!findGoal) {
		myMaze[cori][corj] = " ";
	}
	return findGoal;
}
*/
bool findTheGoalWithOptimal(string ** myMaze, int size, int cori, int corj, int mazePow, bool decision, int *EECC) {
	
	if (decision) {
		Queue que;
		bool findGoal = false;
		myMaze[cori][corj] = "*";
		int reqTime = 0;
		if (cori - 1 >= 0) {//find upper space
			if (myMaze[cori - 1][corj] == "G") {
				return true;
			}
			else if (myMaze[cori - 1][corj] == " ") {
				que.enQueue((cori - 1)*mazePow + corj);
				myMaze[cori - 1][corj] = "e";
				reqTime++;
			}

		}


		if (cori + 1 < size) {//find lower space
			if (myMaze[cori + 1][corj] == "G") {
				return true;
			}
			else if (myMaze[cori + 1][corj] == " ") {
				que.enQueue((cori + 1) * mazePow + corj);
				myMaze[cori + 1][corj] = "e";
				reqTime++;
			}

		}


		if (corj - 1 >= 0) {//find left space
			if (myMaze[cori][corj - 1] == "G") {
				return true;
			}
			else if (myMaze[cori][corj - 1] == " ") {
				que.enQueue(cori * mazePow + corj - 1);
				myMaze[cori][corj - 1] = "e";
				reqTime++;
			}

		}


		if (corj + 1 < size) {//find right space
			if (myMaze[cori][corj + 1] == "G") {
				return true;
			}
			else if (myMaze[cori][corj + 1] == " ") {
				que.enQueue((cori)* mazePow + corj + 1);
				myMaze[cori][corj + 1] = "e";
				reqTime++;
			}

		}
		for (int req = 0; req < reqTime; req++) {
			int deqNumber = que.deQueue();
			if (!findGoal) {
				findGoal = findTheGoalWithOptimal(myMaze, size, deqNumber / mazePow, deqNumber % mazePow, mazePow, decision,EECC);
				decision = !decision;
				EECC[0]++;
			}
			else {
				EECC[1]++;
			}

		}

		if (!findGoal) {
			myMaze[cori][corj] = "e";
		}
		return findGoal;


	}
	else {

		Stack sta;
		bool findGoal = false;
		myMaze[cori][corj] = "*";
		int reqTime = 0;
		if (cori - 1 >= 0) {//find upper space
			if (myMaze[cori - 1][corj] == "G") {
				return true;
			}
			else if (myMaze[cori - 1][corj] == " ") {
				sta.push((cori - 1) * mazePow + corj);
				myMaze[cori - 1][corj] = "e";
				reqTime++;
			}

		}


		if (cori + 1 < size) {//find lower space
			if (myMaze[cori + 1][corj] == "G") {
				return true;
			}
			else if (myMaze[cori + 1][corj] == " ") {
				sta.push((cori + 1) * mazePow + corj);
				myMaze[cori + 1][corj] = "e";
				reqTime++;
			}

		}


		if (corj - 1 >= 0) {//find left space
			if (myMaze[cori][corj - 1] == "G") {
				return true;
			}
			else if (myMaze[cori][corj - 1] == " ") {
				sta.push(cori * mazePow + corj - 1);
				myMaze[cori][corj - 1] = "e";
				reqTime++;
			}

		}


		if (corj + 1 < size) {//find right space
			if (myMaze[cori][corj + 1] == "G") {
				return true;
			}
			else if (myMaze[cori][corj + 1] == " ") {
				sta.push((cori)* mazePow + corj + 1);
				myMaze[cori][corj + 1] = "e";
				reqTime++;
			}

		}

		for (int req = 0; req < reqTime; req++) {
			int deqNumber = sta.peek();
			//cout << deqNumber<<endl;
			sta.pop();
			if (!findGoal) {
				findGoal = findTheGoalWithOptimal(myMaze, size, deqNumber / mazePow, deqNumber % mazePow, mazePow, decision,EECC);
				decision = !decision;
				EECC[0]++;
			}
			else {
				EECC[1]++;
			}

		}

		if (!findGoal) {
			myMaze[cori][corj] = "e";
		}
		return findGoal;
	}

}
int main(int argc, char* argv[]) {
	//cout << argc<< endl;
	string inText = "maze.txt";
	string outText = "mazeout.txt";
	bool wHelp = false;
	bool inCoor = false;
	bool outCoor = false;
	int rType = 0;
	if (argc < 1) {
		cout << "You Must Write Command Arguments. If you don't know what to write there write only (-Help)";

	}
	else {
		//cout << argv[0] << " " << argv[1] << " " << argv[2] << " " << argv[5] << "\n";
		
		string Stack1 = "-Stack";
		string Opt = "-Opt";
		string Queue1 = "-Queue";
		string inFile = "-Infile";
		string outFile = "-Outfile";
		string inCoordinate = "-Incoordinate";
		string outCoordinate = "-Outcoordinate";
		string help= "-Help";
		
		for (int i = 1; i < argc; i++) {
			
			if (outFile.compare(argv[i]) == 0) {
				
				outText = argv[i + 1];
				//outText = outText.substr(1, outText.length - 2);
				i++;
			}
			else if(inFile.compare(argv[i]) == 0){
				inText = argv[i + 1];
				//inText = inText.substr(1, inText.length - 2);
				i++;
			}
			else if(inCoordinate.compare(argv[i]) == 0) {
			
				inCoor = true;
			}
			else if (outCoordinate.compare(argv[i]) == 0) {
				outCoor = true;
			}
			else if(help.compare(argv[i]) == 0) {
				wHelp = true;

			}
			else if (Stack1.compare(argv[i]) == 0) {
				

				rType = 1;
			}
			else if (Opt.compare(argv[i]) == 0) {

				rType = 2;
			}
			else if (Queue1.compare(argv[i]) == 0) {

				rType = 3;

			}else {
				cout << "You should write right arguments for " << argv[i];
			}				
		}
	}

	if (wHelp) {
		int choice = 0;
		while (choice != 8)
		{
			cout << "===============================================================" << "\n";
			cout << "                 Command Line Arguments List                   " << "\n";
			cout << "===============================================================" << "\n";
			cout << "     1. -Stack" << "\n";
			cout << "     2. -Opt" << "\n";
			cout << "     3. -Queue" << "\n";
			cout << "     4. -Infile (String)" << "\n";
			cout << "     5. -Outfile (String)" << "\n";
			cout << "     6. -Incoordinate" << "\n";
			cout << "     7. -Outcoordinate" << "\n";
			cout << "     8. Exit" << "\n";
			cout << "===============================================================" << "\n";
			cout << endl;
			cout << "===============================================================" << "\n";
			cout << endl;
			cout << endl;
			cout << "\nEnter your choice 1 to 7 type to learn how is that work (8 for the Exit): ";
			cin >> choice;
			cout << endl;
			cout << endl;
			switch (choice)
			{
			case 1:
				cout << "1. -Stack: " << "If you write this switch program should use the stack-based routing scheme.\n";
				break;
			case 2:
				cout << "2. -Opt: " << "If you write this switch program should use the optimal routing scheme.\n";
				break;
			case 3:
				cout << "3. -Queue: " << "If you write this switch program should use the queue-based routing scheme.\n";
				break;
			case 4:
				cout << "4. -Infile (String): " << "If you write this switch program use the string as the input filename. If the -Infile flag does not appear then program should use the file ``maze.txt'' as the input filename.\n";
				break;
			case 5:
				cout << "5. -Outfile (String): " << "If you write this switch program use the string as the output filename. If the -Outfile flag does not appear then program should use the file ``mazeout.txt'' as the output filename.\n";
				break;
			case 6:
				cout << "6. -Incoordinate: " << "If you write this switch, it means the input file is in the coordinate format. If you do not write this switch, the input file is in the map format.\n";
				break;
			case 7:
				cout << "7. -Outcoordinate: " << "If you write this switch, it means the output file is in the coordinate format. If you do not write this switch, the output file is in the map format.\n";
				break;
			case 8:
				break;
			default:
				cout << "Please enter correct choice(1-8)!!\n";
				break;
			}
			cout << endl;
			cout << endl;
		}
		
	}
	else if (rType==0) {
		cout << "Write the routing type in command line arguments (-Stack, -Opt, -Queue)";
	}
	else {

		ifstream myReadFile;
		myReadFile.open(inText);
		string** myMaze = NULL;
		int mazeSize = 0;
		
		if (myReadFile.is_open()) {
			string STRING;
			getline(myReadFile, STRING); // Saves the line in STRING.
										 //cout << STRING << "\n";
			mazeSize = stoi(STRING);
			myMaze = new string*[mazeSize];
			for (int i = 0; i < mazeSize; i++) {
				myMaze[i] = new string[mazeSize];
			}
			
			if (inCoor) {
				for (int i = 0; i < mazeSize; i++) {
					for (int j = 0; j < mazeSize; j++) {
						myMaze[i][j] = " ";
					}
				}

				while (!myReadFile.eof()) {
					int i, j;
					getline(myReadFile, STRING); // Saves the line in STRING.
												 //cout << STRING << "\n";
					string::size_type loc = STRING.find(" ", 0);
					string::size_type loc1 = STRING.find(" ", loc + 1);
					
					i = stoi(STRING.substr(loc+1,loc1-(loc+1)));	
					j = stoi(STRING.substr(loc1+1));
					myMaze[i][j] = STRING.substr(0, 1);
				}
			}
			else {
				int i = 0;
				while (!myReadFile.eof()) {
					getline(myReadFile, STRING); // Saves the line in STRING.
												 //cout << STRING << "\n";
					for (int j = 0; j < mazeSize; j++) {
						myMaze[i][j] = STRING.substr(j, 1);
					}
					i++;
				}
			}
			
			
		

		}
		/*for (int i = 0; i < mazeSize; i++) {
			for (int j = 0; j < mazeSize; j++) {
				cout << myMaze[i][j];
			}
			cout << endl;
		}*/
		int cori, corj;
		for (int i = 0; i < mazeSize; i++) {

			for (int j = 0; j < mazeSize; j++) {
				if (myMaze[i][j] == "R") {
					cori = i;
					corj = j;
				}
			}

		}
		int EE = 0, CC = 0;
		int * EECC = new int[2];
		EECC[0] = 0;
		EECC[1] = 0;
		bool ifFind = false;
		int mazePow = 10; 
		int tempMSize = mazeSize;
		while(tempMSize / 10 > 0){
			tempMSize = tempMSize / 10;
			mazePow = mazePow*10;
		}
		//cout << mazePow;
		
		if (rType == 1) {
			//cout << "sdfsdf";
			auto start = chrono::high_resolution_clock::now();
			
			if (findTheGoalWithStack(myMaze, mazeSize, cori, corj,mazePow, EECC)) {
				cout << "Goal found! " << EECC[0] << " positions explored, unexplored list contains " << EECC[1] << " positions.\n";
				ifFind = true;
				/*for (int i = 0; i < mazeSize; i++) {
					myMaze[cori][corj] = "R";
					for (int j = 0; j < mazeSize; j++) {
						cout << myMaze[i][j];
					}
					cout << endl;
				}*/
			}
			else {
				cout << "Goal not found! " << EECC[0] << " positions explored.";
			}
			auto finish = chrono::high_resolution_clock::now();
			long mymsec = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();
			
			cout << "@runtime = " << (double) mymsec / 1000000.0 << " msec\n";
		}
		else if (rType == 2) {
			auto start = chrono::high_resolution_clock::now();
			if (findTheGoalWithOptimal(myMaze, mazeSize, cori, corj, mazePow,true,EECC)) {
				cout << "Goal found! " << EECC[0] << " positions explored, unexplored list contains " << EECC[1] << " positions.\n";
				ifFind = true;
				/*for (int i = 0; i < mazeSize; i++) {
					myMaze[cori][corj] = "R";
					for (int j = 0; j < mazeSize; j++) {
						cout << myMaze[i][j];
					}
					cout << endl;

				}*/
			}
			else {
				cout << "Goal not found! " << EECC[0] << " positions explored.";
			}
			auto finish = chrono::high_resolution_clock::now();
			long mymsec = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();

			cout << "@runtime = " << (double)mymsec / 1000000.0 << " msec\n";
		}
		else if (rType == 3) {
			auto start = chrono::high_resolution_clock::now();
			if (findTheGoalWithQueue(myMaze, mazeSize, cori, corj, mazePow,EECC)) {
				cout << "Goal found! " << EECC[0] << " positions explored, unexplored list contains " << EECC[1] << " positions.\n";
				ifFind = true;
				/*for (int i = 0; i < mazeSize; i++) {
					myMaze[cori][corj] = "R";
					for (int j = 0; j < mazeSize; j++) {
						cout << myMaze[i][j];
					}
					cout << endl;
				}*/
			}
			else {
				cout << "Goal not found! " << EECC[0] << " positions explored.";
			}
			auto finish = chrono::high_resolution_clock::now();
			long mymsec = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();

			cout << "@runtime = " << (double)mymsec / 1000000.0 << " msec\n";
		}


		if (ifFind) {
			if (outCoor) {
				ofstream outFile(outText);
				myMaze[cori][corj] = "R";
				for (int i = 0; i < mazeSize; i++) {
					for (int j = 0; j < mazeSize; j++) {
						if (myMaze[i][j] == "*") {
							outFile << "* " << i << " " << j << "\n";
						}
						
					}
				}
				//outFile << "fdsdffsdgs" ;
				outFile.close();
			}
			else {
				ofstream outFile(outText);
				myMaze[cori][corj] = "R";
				for (int i = 0; i < mazeSize; i++) {
					for (int j = 0; j < mazeSize; j++) {
						if (myMaze[i][j] == "e") {
							outFile << " ";
						}
						else {
							outFile << myMaze[i][j];
						}
						
					}
					outFile << endl;
				}
				//outFile << "fdsdffsdgs" ;
				outFile.close();
			}
		}
		
		
	}
		
}
