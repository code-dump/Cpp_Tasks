#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	int array_size = 0;
	cout << "\nInput size of array: ";
	cin >> array_size;
	vector<int>array1(array_size);

	cout << "\nInput elemets of array" << endl;
	for (int i = 0; i < array_size; i++)
	{
		cin >> array1[i];
	}

	cout << "\nYour array: ";
	if (!array1.empty())														//func: if array is NOT empty
	{
		copy(array1.begin(), array1.end(), ostream_iterator<int>(cout, " "));	//func: output 
		cout << "\nConsists of " << array_size << " elements";
	}
	

	vector<int>array2 = array1;
	cout << "\nNew array now equal to old one: ";
	if (!array2.empty())
	{
		copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));
		cout << "\nConsists of " << array_size << " elements";
	}

	cout << "\nFirst element of this array: " << array2.front() << endl;		//func: return first element
	cout << "Last element of this array: " << array2.back() << endl;			//func: return last element

	array1.clear();																//func: delete all elements
	array2.push_back(42);														//func: add element in the end of array
	cout << "Updated array: ";
	copy(array2.begin(), array2.end(), ostream_iterator<int>(cout, " "));
	return 0;
}