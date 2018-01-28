/******** This programm is the begining of my MT learning ********/

#include <iostream>
#include <windows.h>
#include <thread>
#include <iomanip>

using namespace std;


void foo(int n)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "\n" << i << ": Foo(" << n << ") ->" << this_thread::get_id();
		Sleep(700);
	}
}

void boo(int n)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "\n" << i << ": Boo(" << n << ") ->" << this_thread::get_id() ;
		Sleep(700);
	}
}


int main()
{
	cout << setw(5) << "\nMAIN() STARTED" << endl;
	
	cout << "\nHardware concurrency: " << thread::hardware_concurrency() << endl;
	thread t1(foo, 0);
	thread t2(boo, 1);
	
	if (t1.joinable())		//is it connected??
		t1.join();			//connect it to main() thread

	t2.detach();			//main() thread will not wait for t2. now it's independent
	cout << "\nMain() ->" << this_thread::get_id() << endl;

	cout << setw(5) << "\nMAIN() ENDED" << endl;
	system("pause");

}

