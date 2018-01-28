#include <deque>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	deque<string> dqString;
	dqString.push_back(string("Micro"));
	cout << "\nDeque contains " << dqString.size() << " elements";
	dqString.push_front(string("Roland "));
	dqString.push_back(string("Cube"));	
	cout << "\nNow deque contains " << dqString.size() << " elements";

	cout << "\nYou've entered: ";
	copy(dqString.begin(), dqString.end(), ostream_iterator<string>(cout));

	dqString.pop_front();
	dqString.pop_back();
	dqString.resize(2, " NULL ");
	cout << "\nNow deque contains " << dqString.size() << " elements";
	cout << "\nIt's become: ";
	copy(dqString.begin(), dqString.end(), ostream_iterator<string>(cout));

	cout << endl;


    return 0;
}

