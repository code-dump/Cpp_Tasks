#include <iostream>
#include <list>     
#include <iterator> 
#include <ctime>
#include <cstdlib>
using namespace std;


int main()
{
	list<int> MyList;
	for(int i = 0; i < 10; i++) MyList.push_back(i);
	
	cout << "\nList: ";
	copy(MyList.begin(), MyList.end(), ostream_iterator<int>(cout, " "));
	//for(int i = 0; i < 10; i++) cout << MyList[i];  ---- doesn't work

	cout << "\nFirst element: " << MyList.front();
	cout << "\nLast element: " << MyList.back();


	list<int> myList; // empty list
	srand(42);// rand

	for (int i = 0; i < 15; i++) {
		myList.push_back(rand() % 20); // add elements
	}

	cout << "\nList: ";
	copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));

	myList.sort();   // sort by dec
	cout << "\nSorted list: ";
	copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));

	myList.unique();   // delete duplicates from list
	cout << "\nList with unique elements: ";
	copy(myList.begin(), myList.end(), ostream_iterator<int>(cout, " "));

	list<int> myList2; // another empty list
	for (int i = 0; i < 15; i++) {
		myList2.push_back(i); // add new elements
	}

	cout << "\nList2: ";
	copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));

	myList2.merge(myList);	//uniting lists
	cout << "\nUnite list: ";
	copy(myList2.begin(), myList2.end(), ostream_iterator<int>(cout, " "));


	cout << endl; return 0;
}


