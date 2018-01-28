#include <iostream>
#include <valarray>
using namespace std;





int main()
{
	valarray<int> arr(-1, 20);
	cout << "\nArray: ";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	arr[slice(5, 3, 2)] = 2;
	arr[slice(0, 3, 1)] = 6;
	arr[slice(8, 7, 3)] = 4;
	cout << "\nArray after slice: ";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	arr[slice(0, 19, 2)] = pow(static_cast<valarray<int>> (arr[slice(0, 19, 2)]), 2);
	cout << "\nArray with every second element doubled: ";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	
	return 0;
}


