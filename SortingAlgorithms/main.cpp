#include <stdio.h>
#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;


void bubbleSort(int* myArray, int length) {
	bool isItOrdered = false;
	
	while (!isItOrdered) {
		isItOrdered = true;
		for (int i = 0; i < length - 1; i++) {
			if (myArray[i] > myArray[i + 1]) {
				swap(myArray[i], myArray[i + 1]);
				isItOrdered = false;
			}
			
		}
		length--;
	}
	

}
void bubbleSort2(int* myArray, int length) {
	bool isItOrdered = false;

	while (!isItOrdered) {
		isItOrdered = true;
		for (int i = 0; i < length - 1; i++) {
			if (myArray[i] > myArray[i + 1]) {
				int temp = myArray[i]; 
				myArray[i] = myArray[i+1];
				myArray[i + 1] = temp;
				isItOrdered = false;
			}

		}
		length--;
	}


}
void insertionSort(int* myArray, int length) {

	for (int i = 1; i < length; i++) {
		int j = i;
		while (j > 0 && myArray[j] < myArray[j - 1]) {
			swap(myArray[j], myArray[j-1]);

			j--;
		}

	}


}
void insertionSort2(int* myArray, int length) {

	for (int i = 1; i < length; i++) {
		int x = myArray[i];
		int j = i;
		while (j > 0 && x < myArray[j - 1]) {
			myArray[j] = myArray[j - 1];

			j--;
		}
		myArray[j] = x;

	}


}
void selectionSort(int* myArray, int length) {

	for (int i = 0; i < length; i++) {

		int imin = i;

		for (int j = i + 1; j < length; j++) {
			
			if (myArray[j] < myArray[imin]) {
			imin = j;
			}

			

			
		}
		if (imin != i) {
			swap(myArray[i], myArray[imin]);
		}
		/*for (int k = 0; k < 10; k++) {
		cout << myArray[k] << " ";

		}
		cout << endl;*/
	}


}
void mergeSort(int* myArray, int* newArray, int firstIndex,int lastIndex ) {
	int length = lastIndex - firstIndex + 1;
	
	if (length > 1) {
		
		mergeSort(myArray, newArray, firstIndex, firstIndex + (length / 2 - 1));
		mergeSort(myArray, newArray, firstIndex +(length / 2), lastIndex);
		
		for (int i = firstIndex; i <= lastIndex; i++) {
			newArray[i] = myArray[i];
		}
		/*for (int i = 0; i < 10; i++) {
			cout << newArray[i] << " " ;

		}
		cout << endl;*/
		int newIndex = firstIndex;
		int j = firstIndex + (length / 2);
		for (int i = firstIndex; i <= firstIndex + (length / 2 - 1); i++) {
			if (j == lastIndex+1) {
				myArray[newIndex] = newArray[i];
				newIndex++;
			}
			else if (newArray[i] > newArray[j]) {
				myArray[newIndex] = newArray[j];
				newIndex++;
				j++;
				i--;
			}
			else {
				myArray[newIndex] = newArray[i];
				newIndex++;
			}

		}
		/*while (j != lastIndex+1) {
			myArray[newIndex] = newArray[j];
			newIndex++;
			j++;
		}
		for (int i = 0; i < 10; i++) {
			cout << myArray[i] << " " ;

		}
		cout << endl;*/

	}


	


}

void quickSort(int* myArray, int firstIndex, int lastIndex) {
	
	   if (lastIndex - firstIndex >= 1) {
		   //cout << firstIndex;
		int y = lastIndex - 1;
		int i = firstIndex;
		for (i = firstIndex; i < y +1; i++) {
			if (myArray[i] >= myArray[lastIndex]) {
				
				
					while (myArray[y] >= myArray[lastIndex] && y > i ) {
						y--;
					}
					swap(myArray[i], myArray[y]);
					y--;
				
				
				/*for (int i = firstIndex; i <= lastIndex; i++) {
					cout << myArray[i] << " ";

				}
				cout << endl;*/
			}
			
		}
		if (myArray[i - 1] > myArray[lastIndex]) {
			swap(myArray[i - 1], myArray[lastIndex]);
		}
		
		/*for (int z = firstIndex; z <= lastIndex; z++) {
			cout << myArray[z] << " ";

		}
		cout << endl;*/

		
			
		quickSort(myArray, firstIndex, i-1);
		quickSort(myArray, i, lastIndex);
		}
	


}










void radixSort(int* MyArray, int length, int** MyArray0to9) {

	int max = MyArray[0];
	for (int i = 1; i < length; i++)
		if (MyArray[i] > max)
			max = MyArray[i];
	//cout << max << endl;
	

	for (int exp = 1; max / exp > 0; exp *= 10) {

		int count[10] = { 0 };
		for (int i = 0; i < length; i++) {
			MyArray0to9[(MyArray[i] / exp) % 10][count[(MyArray[i] / exp) % 10]] = MyArray[i];
			count[(MyArray[i] / exp) % 10]++;

		}
		/*for (int f = 0; f < 10; f++) {
			for(int z = 0; z < length; z++) {
				cout << MyArray0to9[f][z] << "\t";

			}
			cout << endl;
		}
		cout << endl;
		for (int f = 0; f < 10; f++) {
			cout << count[f] << " ";

		}
		cout << endl;*/
		int z = 0;
		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < count[i]; y++) {
				
				MyArray[z] = MyArray0to9[i][y];
			
				z++;
			}
				

		}
		

	}


}



void toTheSelectionSort(int* myArray, int length) {
	int* sortingArray = new int[length];
	for (int i = 0; i < length; ++i) {
	 
		sortingArray[i] = myArray[i];
	}
	
	
	////////////////
	auto start = chrono::high_resolution_clock::now();
	selectionSort(sortingArray, length);
	auto finish = chrono::high_resolution_clock::now();
	cout << "Selection Sort: " <<chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\n";

	////////////////
	/*for (int i = 0; i < length; i++) {
		cout << sortingArray[i] << " ";

	}*/
	delete[] sortingArray;

}
void toTheInsertionSort(int* myArray, int length) {
	int* sortingArray = new int[length];
	for (int i = 0; i < length; ++i) {

		sortingArray[i] = myArray[i];
	}


	/////////////////
	/*auto start = chrono::high_resolution_clock::now();
	insertionSort(sortingArray, length);
	auto finish = chrono::high_resolution_clock::now();
	cout << "Insertion Sort: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\n";*/
	////////////////
	
	for (int i = 0; i < length; ++i) {

		sortingArray[i] = myArray[i];
	}
	/*for (int i = 0; i < length; i++) {
		cout << sortingArray[i] << " ";

	}*/

	/////////////////
	auto start = chrono::high_resolution_clock::now();
	insertionSort2(sortingArray, length);
	auto finish = chrono::high_resolution_clock::now();
	cout << "Insertion Sort 2: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\n";
	/////////////////



	/*for (int i = 0; i < length; i++) {
	cout << sortingArray[i] << " ";

	}*/
	delete[] sortingArray;



}
void toTheBubbleSort(int* myArray, int length) {
	int* sortingArray = new int[length];
	for (int i = 0; i < length; ++i) {

		sortingArray[i] = myArray[i];
	}
	

	////////////////
	/*start = chrono::high_resolution_clock::now();
	bubbleSort(sortingArray, length);
	finish = chrono::high_resolution_clock::now();
	cout << "Bouble Sort: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\n";*/
	////////////////

	for (int i = 0; i < length; ++i) {

		sortingArray[i] = myArray[i];
	}
	/*for (int i = 0; i < length; i++) {
		cout << sortingArray[i] << " ";

	}*/


	////////////////
	auto start = chrono::high_resolution_clock::now();
	bubbleSort2(sortingArray, length);
	auto finish = chrono::high_resolution_clock::now();
	cout << "Bouble Sort 2: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\n";
	////////////////
	

	/*for (int i = 0; i < length; i++) {
	cout << sortingArray[i] << " ";

	}*/
	delete[] sortingArray;




}
void toTheMergeSort(int* myArray, int length) {

	int* sortingArray = new int[length];
	for (int i = 0; i < length; ++i) {

		sortingArray[i] = myArray[i];
	}

	int* workonArray = new int[length];
	for (int i = 0; i < length; i++) {
		workonArray[i] = 0;

	}



	////////////////
	auto start = chrono::high_resolution_clock::now();
	mergeSort(sortingArray, workonArray, 0, length - 1);
	auto finish = chrono::high_resolution_clock::now();
	cout << "Merge Sort: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\n";
	////////////////
	/*for (int i = 0; i < length; i++) {
	cout << sortingArray[i] << " ";

	}*/
	delete[] sortingArray;
	delete[] workonArray;


}
void toTheQuickSort(int* myArray, int length) {

	int* sortingArray = new int[length];
	
	for (int i = 0; i < length; ++i) {

		sortingArray[i] = myArray[i];
	}


	////////////////
	auto start = chrono::high_resolution_clock::now();
	quickSort(sortingArray, 0, length - 1);
	auto finish = chrono::high_resolution_clock::now();
	cout << "Ouick Sort: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\n";
	////////////////
	/*for (int i = 0; i < length; i++) {
	cout << sortingArray[i] << " ";

	}*/
	delete[] sortingArray;



}
void toTheRadixSort(int* myArray, int length) {
	int* sortingArray = new int[length];
	for (int i = 0; i < length; ++i) {

		sortingArray[i] = myArray[i];
	}
	


	////////////////
	auto start = chrono::high_resolution_clock::now();
	int** boxArray = new int*[10];
	for (int i = 0; i < 10; ++i) {
		boxArray[i] = new int[length];

	}
	
	radixSort(sortingArray, length, boxArray);
	auto finish = chrono::high_resolution_clock::now();
	cout << "Radix Sort: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\n";
	////////////////
	/*for (int i = 0; i < length; i++) {
	cout << sortingArray[i] << " ";

	}*/
	delete[] sortingArray;
	delete[] boxArray;



}
void ascendingOrder(int* myArray, int length) {
	for (int i = 0; i < length; i++) {
		//cin >> ali[i];
		myArray[i] = i;


	}


}
void descendingOrder(int* myArray, int length) {
	for (int i = 0; i < length; i++) {
		//cin >> ali[i];
		myArray[i] = length-i;


	}


}
void randomOrder(int* myArray, int length) {
	srand(time(NULL));

	for (int i = 0; i < length; i++) {
		//cin >> ali[i];
		myArray[i] = rand() % 100000;


	}

}



int main(int argc, char* argv[])
{
	
	
	if (argc != 5) {
		cout << "Number of Command Arguments Must be 5.";

	}
	else {
		cout << argv[1] <<" " << argv[2]<< " " << argv[3]<< " "  << argv[4]<< "\n";
		string str1 = "-s";
		string str2 = "-o";
		string Random = "R";
		string Ascending = "A";
		string Descending = "D";
		if (str1.compare(argv[1]) == 0) {
			int length;
			length = atoi(argv[2]);
			if (str2.compare(argv[3]) == 0) {
				
				if (Random.compare(argv[4]) == 0) {
					int* myArray = new int[length];

					randomOrder(myArray, length);

					toTheBubbleSort(myArray, length);
					toTheInsertionSort(myArray, length);
					toTheSelectionSort(myArray, length);
					toTheMergeSort(myArray, length);
					toTheQuickSort(myArray, length);
					toTheRadixSort(myArray, length);
				}
				else if (Ascending.compare(argv[4]) == 0) {
					int* myArray = new int[length];

					ascendingOrder(myArray, length);


					toTheBubbleSort(myArray, length);
					toTheInsertionSort(myArray, length);
					toTheSelectionSort(myArray, length);
					toTheMergeSort(myArray, length);
					toTheQuickSort(myArray, length);
					toTheRadixSort(myArray, length);
				}
				else if(Descending.compare(argv[4]) == 0){
					int* myArray = new int[length];

					descendingOrder(myArray, length);


					toTheBubbleSort(myArray, length);
					toTheInsertionSort(myArray, length);
					toTheSelectionSort(myArray, length);
					toTheMergeSort(myArray, length);
					toTheQuickSort(myArray, length);
					toTheRadixSort(myArray, length);
				}else {
					cout << "You should write right arguments";
				}


			}
			else {
				cout << "You should write right arguments";
			}

			
		}
		else {
			cout << "You should write right arguments";
		}

	}
	
	
	

	

	/*for (int i = 0; i < length; i++) {
		cout << myArray[i] << " ";

	}

	cout << endl;*/
	


	

	
	
	
	/*for (int i = 0; i < length; i++) {
		cout << myArray[i] << " ";

	}*/

	
	
    return 0;
}

