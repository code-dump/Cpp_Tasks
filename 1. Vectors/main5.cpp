#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int VectorStatus(vector<int>&, vector<int>&);

int main()
{
	int i;
	vector<int> vecOne, vecTwo;
	vector<int>::iterator pit;

	for (i = 0; i < 10; i++)
	{
		vecOne.push_back(i);
		vecTwo.push_back(i * 2);
	}

	VectorStatus(vecOne, vecTwo);



	cout << "\n\t\t*SWAP!*";
	vecOne.swap(vecTwo);
	swap(vecOne.back(), vecTwo.back());
	VectorStatus(vecOne, vecTwo);


	cout << "\n\t\t*INSERT!*";
	pit = vecOne.begin() + 1;
	vecOne.insert(pit, 42);
	pit = vecTwo.begin() + 1;
	vecTwo.insert(pit, 12);
	VectorStatus(vecOne, vecTwo);

	cout << "\n\t\t*RESIZE!*";
	vecOne.resize(20);
	vecTwo.reserve(20);
	VectorStatus(vecOne, vecTwo);

	cout << "\n\t\t*CLEAR!*";
	vecOne.clear();
	vecTwo.clear();
	VectorStatus(vecOne, vecTwo);
	cout << "\n First vector capacity  = " << vecOne.capacity();
	cout << "\n Second vector capacity = " << vecTwo.capacity();

	cout << "\n\t\t*FIT!*";
	vecOne.shrink_to_fit();
	vecTwo.shrink_to_fit();
	VectorStatus(vecOne, vecTwo);
	cout << "\n First vector capacity  = " << vecOne.capacity();
	cout << "\n Second vector capacity = " << vecTwo.capacity();

	cout << endl << endl;

	return 0;
}


int VectorStatus(vector<int>& v1, vector<int>& v2)
{
	cout << "\nFirst vector:  ";
	for (int i = 0; i < v1.size(); cout << v1[i] << " ", i++);
	cout << " --> " << v1.size() << " elements.";

	cout << "\nSecond vector: ";
	for (int i = 0; i < v2.size(); cout << v2[i] << " ", i++);
	cout << " --> " << v2.size() << " elements.";

	return 0;
}

