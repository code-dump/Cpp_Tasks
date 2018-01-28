		
	/*This programm decrease num to zero, then increase it to 16*/
	/*   to help me to understand how multithread is working    */


#include <windows.h> 
#include <iostream>
#include <mutex>		//thread sync 
#include <thread>		//thread header 
#include <vector>


using namespace std;


void foo(int& num, mutex& mtx)
{
	while (1)
	{
		mtx.lock();		//lock mutex so boo() can't use it
		num += 2;
		cout << "\nFoo: " << num;
		mtx.unlock();	//unlock mutex so boo() can use it
		if (num>15) break;
		Sleep(500);
	}
}

void boo(int& num, mutex& mtx)
{
	while (1)
	{
		mtx.lock();		//wait until foo unlock mutex. then lock mutex by itself and go
		num -= 2;
		cout << "\nBoo: " << num;
		mtx.unlock();	//unlock mutex for other thread
		if (!num) break;
		Sleep(250);
	}
}


int main()
{
	int num = 10;
	mutex mtx;
	thread t1(foo, ref(num), ref(mtx));		//
	thread t2(boo, ref(num), ref(mtx));		//ref() - cause we can't initialize thread with "link"
	t1.join();
	t2.join();

	system("pause");

}

