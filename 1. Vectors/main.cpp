#include <iostream>
#include <vector>
#include <iterator>								// header file or iterator

using namespace std;

int main()
{
	vector<int> EmptyVector;					//empty vector
	EmptyVector.reserve(3);						//reserving memory for 5 vector elements

	vector<int> Vector(5);					    //vector of 5 zero elements

	for (int i = 0; i < Vector.size(); i++) Vector[i] = i;
		
	vector <int> VectorCopy(Vector);			//making copy of vector
	for (int i = 0; i < VectorCopy.size(); i++) cout << VectorCopy[i] << ' ';
	if (VectorCopy == Vector) cout << "\nCopying completed" << endl;

	EmptyVector.insert(EmptyVector.end(), 9);
	EmptyVector.insert(EmptyVector.end(), 6);
	EmptyVector.insert(EmptyVector.end(), 3);
	
	copy										//output operation
	(
		EmptyVector.begin(),					//begin
		EmptyVector.end(),						//end
		ostream_iterator<int>(cout, " ")		//output stream iterator
	);

	return 0;
}

