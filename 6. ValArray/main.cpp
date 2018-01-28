#include <iostream>
#include <valarray>
#include <iomanip>
using namespace std;





int main()
{
	srand(time(NULL));
	valarray<int> array1(15);
	int arr[15] = { 0,  5,  6,  6,  0,  9,  3,  8,  3,  0,  8,  9,  3,  7,  4 };
	

	cout << setw(20)  << left << "\nFirst array: ";
	for (int i = 0; i < array1.size(); i++)
	{
		array1[i] = rand() % 10;
		cout << setw(2) << array1[i] << " ";
	}
	
	
	cout << setw(20) << left << "\nSecond array:";
	valarray<int> array2(arr, sizeof(arr)/sizeof(arr[0]));  // valarray init by static array
	for (int i = 0; i < array2.size(); i++)
	{
		cout << setw(2) << array2[i] << " ";
	}

	cout << setw(20) << left << "\nFirst + Second:";
	valarray<int> array3 = array1 + array2;
	for (int i = 0; i < array3.size(); i++)
	{
		cout << setw(2) << array3[i] << " ";
	}


	valarray<bool> res(15);

	res = (array1 < array2);       // array of bool value
	cout << setw(20) << left << "\nFirst < Second:";
	for (int i = 0; i < res.size(); i++) {
		cout << setw(2) << res[i] << " ";
	}

	res = (array1 && array2);       // array of bool value
	cout << setw(20) << left << "\nFirst && Second:";
	for (int i = 0; i < res.size(); i++) {
		cout << setw(2) << res[i] << " ";
	}

}


