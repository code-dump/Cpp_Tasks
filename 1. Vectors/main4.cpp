#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
	vector<int> vecPoint(5);
	vector<int> vecEmpty;
	vecEmpty.reserve(5);
	int i;
	vector<int>::iterator pit;
	int *pointer = vecPoint.data();		//creating pointer to vector using .data()

	for (i = 0; i < vecPoint.size(); pointer[i] = i, i++);

	vecPoint.empty() ? cout << "\n[FV]Vector is empty" : cout << "\n[FV]Vector is not empty";
	vecEmpty.empty() ? cout << "\n[SV]Vector is empty" : cout << "\n[SV]Vector is not empty";

	cout << "\n[FV]Origin vector contains: ";
	for (i = 0; i < vecPoint.size(); i++)
	{
		cout << *pointer << " ";
		pointer++;
	}

	pit = vecPoint.begin();		//iterator points to 0 element
	vecPoint.emplace(pit, 9);	//place value in 0 element
	pit = vecPoint.begin() + 2;
	vecPoint.emplace(pit, 21);	//place value in 2 element
	vecPoint.emplace_back(42);	//place value in the end of vector

	cout << "\n[FV]Transformed vector: ";
	for (i = 0; i < vecPoint.size(); cout << vecPoint[i] << " ", i++);


	return 0;
}