#include <iostream>
#include <bitset>
#include <iomanip>  // setw()
using namespace std;

template <class T>
bool problemo(T x)
{
	try
	{
		if(x > 255 || x < 1) throw 404;
	}
	catch (int a)
	{
		cout << "\nCaught exception number:  " << a << endl;
		return false;
	}
	cout << "\nNo exception detected!" << endl;
	return true;
};


int main()
{
	bitset<8> number;		//1 byte

	cout << "Binary form or numbers: \n";
	for (int i = 0; i < 21; i++)
	{
		number = i;
		cout << setw(3)					 // width of output field
            << number.to_ulong()		 // from binary to decimal
			<< " = " << number << endl;
	}

	cout << "\n\nInput value from 1 to 255: ";
	int value, x = 0;
	cin >> x;
	if (problemo(x)) value = x;


	bitset<8> message(value);
	cout << setw(5) << value << " =   " << message << endl;
	bitset<8> msg1 = message;		//invert
	message = message.flip();
	cout << " ~invert: " << message;
	
	bitset<8> msg2 = msg1 | message;		// OR
	cout << endl << msg1 << " | " << message << " = " << msg2;
	bitset<8> msg3 = msg1 & message;		// AND
	cout << endl << msg1 << " & " << message << " = " << msg3;
	bitset<8> msg4 = msg1 ^ message;		// XOR
	cout << endl << msg1 << " ^ " << message << " = " << msg4;

	cout << endl; return 0;
}

