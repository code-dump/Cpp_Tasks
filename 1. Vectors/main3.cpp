#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
	vector<string>vecStrAlph1{{ 'a', 'b', 'c', 'd' },
							  { 'e', 'f', 'g', 'h' },
							  { 'i', 'j', 'k', 'l' } };
	cout << "\nAlphabetVector1 contains: ";
	for (int column = 0; column < vecStrAlph1.size(); column++)		//vecStrAlph1.size() - q-ty of columns
	{
		cout << "\n ";
		for (int row = 0; row < vecStrAlph1[column].length(); row++)		//vecStrAlph1[column].length() - length of column
		{
			cout << vecStrAlph1[column][row] << " ";
		}
	}


	vector<string>vecStrAlph2;
	vecStrAlph2.push_back("mnop");
	vecStrAlph2.push_back("qrst");
	vecStrAlph2.push_back("uvwx");
	vecStrAlph2.push_back(" yz ");

	cout << "\nAlphabetVector2 contains: ";
	for (int column = 0; column < vecStrAlph2.size(); column++)
	{
		cout << "\n ";
		for (int row = 0; row < vecStrAlph2[column].length(); row++)
		{
			cout << vecStrAlph2[column][row] << " ";
		}
	}

	vector<string>vecStrEnding;
	vecStrEnding.assign(9, "_");		//vecStrEnding.assign(9, "_") - filling vector with component
	cout << endl;
	copy(vecStrEnding.begin(), vecStrEnding.end(), ostream_iterator<string>(cout, ""));





	vector<int>::iterator pit;		//creating iterator for vector
	vector<int>vecNum(10);		//reserving space for 10 elements
	cout << "\nVector contains: ";
	for (int i = 0; i < vecNum.size(); i++) vecNum[i] = i;		//filling space
	for (pit = vecNum.begin(); pit < vecNum.end(); pit++) cout << *pit << " ";		//showing elements
	cout << "\nVector capacity: " << vecNum.capacity();		//showing capacity
	cout << "\nVector reverse: ";
	for (auto rit = vecNum.rbegin(); rit < vecNum.rend(); rit++) cout << *rit << " ";		//rbegin/rend - reversed func
	cout << endl;
	vecNum.clear();		//clearing space
	cout << "\nVector erased!";
	cout << "\nVector size: " << vecNum.size();
	cout << endl;

	return 0;
}