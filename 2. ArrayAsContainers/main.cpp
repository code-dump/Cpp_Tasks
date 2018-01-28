#include <iostream>
#include <iterator>
#include <algorithm>										//algorithm header
using namespace std;

bool SortCriteria(int a, int b);

int main()
{
	int Array[] = { -5, 12, -8, 0, 9 };
	cout << "\nOrigin array: ";
	copy(Array, Array + 5, ostream_iterator<int>(cout, " ")); //func(pointer to first element, -/-/- last element, stream)
	
	sort(Array, Array + 5);									//func: sorting array from array.begin() to array.end()
	cout << "\nSorted array: ";
	copy(Array, Array + 5, ostream_iterator<int>(cout, " "));

	sort(Array, Array + 5, SortCriteria);					 //func(begin, end, bool func: if return is (a > b) - descendingly)
	cout << "\nReverse sorted array: ";
	copy(Array, Array + 5, ostream_iterator<int>(cout, " "));


	return 0;
}

bool SortCriteria(int a, int b)
{
	return(a > b);
}