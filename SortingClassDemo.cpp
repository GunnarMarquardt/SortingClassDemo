//280 Sorting Class Demo.cpp
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

const int MAX_CHARS = 1;
const int MAX_STRINGS = 10;

void cr(int n = 1) {
	for (int i = 0; i < n; i++)
		cout << endl;
} //cr

class Sorter {
private:
	string workspace[MAX_STRINGS];
	string randomString();
public:
	Sorter();
	void load();
	void display();
	void bubbleSort();
	bool isSorted();
	void selectionSort();
	void swap(string*, string*);
	void shellSort();
};

Sorter::Sorter() { // empty constructor
}

string Sorter::randomString() {
	//pre:	none
	//post:	return a string of MAX_CHARS random lowercase characters
	string s = "";
	for (int i = 0; i < MAX_CHARS; i++) {
		char randomChar = char(rand() % 26 + 97);
		s += randomChar;
	}
	return s;
} //randomString

void Sorter::load() {
	//pre:	none
	//post:	workspace is loaded with random strings
	for (int i = 0; i < MAX_STRINGS; i++)
		workspace[i] = randomString();
} //load

void Sorter::display() {
	//pre:	none
	//post:	display workspace elements, separated by blanks
	//		for testing purposes with VERY small arrays
	for (int i = 0; i < MAX_STRINGS; i++)
		cout << workspace[i] << " ";
	cout << endl; 
} //display

void Sorter::bubbleSort() {
	//pre:	none
	//post:	the workspace array is sorted in ascending order
	for (int pass = 0; pass < MAX_STRINGS - 1; pass++) {
		for (int pos = 0; pos < MAX_STRINGS - pass - 1; pos++) {
			if (workspace[pos] > workspace[pos + 1]) {
				string temp = workspace[pos];
				workspace[pos] = workspace[pos + 1];
				workspace[pos + 1] = temp;
			}
		}
	}
} //bubbleSort

void Sorter::swap(string *a, string *b) {
	string temp = *a;
	*a = *b;
	*b = temp; 
}

void Sorter::selectionSort() {
	//pre: none
	//post: the workspace array is sorted in ascending order
	int min_index;
	int temp;
	for (int incr = 0; incr < MAX_STRINGS-1; incr++) {
		min_index = incr; 
		for (int j = incr + 1; j < MAX_STRINGS; j++) {
			if (workspace[j] < workspace[min_index]) min_index = j; 
		}
		swap(&workspace[min_index], &workspace[incr]);
	}
}

void Sorter::shellSort() {
	//pre: none
	//post: the workspace array is sorted in ascending order
	for (int gap = MAX_STRINGS / 2; gap > 0; gap /= 2) {
		for (int incr = gap; incr < MAX_STRINGS; incr++) {
			string temp = workspace[incr];
			for (int j = incr - gap; j >= 0; j -= gap) {
				if (workspace[j + gap] >= workspace[j])
					break;
				else swap(&workspace[j], &workspace[j + gap]); 
			}
		}
	}
}

bool Sorter::isSorted() {
	//pre:	none
	//post: returns true if the workspace is ascending sorted,
	//		false otherwise
	for (int i = 0; i < MAX_STRINGS - 1; i++)
		if (workspace[i] > workspace[i + 1])
			return false;
	return true;
} //isSorted

int main() {
	int input;
	char yesNo;
	Sorter s1 = Sorter(); //use s1 with bubble sort
	Sorter s2 = Sorter(s1); //use s2 with selection sort
	Sorter s3 = Sorter(s1); //use s3 with insertion sort
	Sorter s4 = Sorter(s1); //use s4 with shell sort
	Sorter s5 = Sorter(s1); //use s5 with quick sort

	while (1) {
		cout << "---------------------------------------------" << endl;
		cout << "Let's use some sorting algorithms!!" << endl;
		cout << "Enter 1 to perform a bubble sort " << endl;
		cout << "Enter 2 to perform a selection sort " << endl;
		cout << "Enter 3 to perform an insertion sort " << endl;
		cout << "Enter 4 to perform a shell sort " << endl;
		cout << "Enter 5 to perform a quick sort " << endl;
		cout << "Enter 6 to quit the program " << endl;
		cout << "---------------------------------------------" << endl << endl;
		cout << "Enter your choice: "; 
		cin >> input;
		switch (input) {
		case 1:
			s1.load();
			cout << "display unsorted array? (Y/N): "; 
			cin >> yesNo;
			if (yesNo == 'Y') {
				cout << "Here is the unsorted array: " << endl;
				s1.display();
				cout << endl; 
			}
			srand(time(NULL));
			clock_t start, stop;

			//test bubble sort
			start = clock();
			s1.bubbleSort();
			stop = clock();
			if (!s1.isSorted()) {
				cout << "Error: bubble sort failed";
				cr(2);
				exit(EXIT_FAILURE);
			}
			else {
				double elapsedTime = ((double)stop - start) / CLOCKS_PER_SEC;
				cout << "Bubble sort time: " << elapsedTime << endl;
				s1.display();
			}
			cr(2);
			break;
		case 2:
			s2.load();
			cout << "display unsorted array? (Y/N): ";
			cin >> yesNo;
			if (yesNo == 'Y') {
				s2.display();
				cout << endl;
			}
			srand(time(NULL));
			clock_t start1, stop1;

			//test selecion sort
			start1 = clock();
			s2.selectionSort(); 
			stop1 = clock();
			if (!s2.isSorted()) {
				cout << "Error: selection sort failed";
				cr(2);
				exit(EXIT_FAILURE);
			}
			else {
				double elapsedTime = ((double)stop1 - start1) / CLOCKS_PER_SEC;
				cout << "selection sort time: " << elapsedTime << endl;
				s2.display();
			}
			cr(2);
			break;
		case 3:
			cout << "This has not been built yet! " << endl;
			break;
		case 4:
			s3.load();
			cout << "display unsorted array? (Y/N): ";
			cin >> yesNo;
			if (yesNo == 'Y') {
				s3.display();
				cout << endl;
			}
			srand(time(NULL));
			clock_t start3, stop3;

			//test selecion sort
			start1 = clock();
			s3.shellSort();
			stop1 = clock();
			if (!s3.isSorted()) {
				cout << "Error: shell sort failed";
				cr(2);
				exit(EXIT_FAILURE);
			}
			else {
				double elapsedTime = ((double)stop1 - start1) / CLOCKS_PER_SEC;
				cout << "selection sort time: " << elapsedTime << endl;
				s3.display();
			}
			cr(2);
			break;
		case 5:
			cout << "This has not been built yet! " << endl;
			break;
		case 6:
			cout << "Program TERMINATED" << endl;
			exit(0);
			break;
		}
	}

	//test selection sort

	//test insertion sort

	//test shell sort

	//test quick sort
	
	return 0;
}
