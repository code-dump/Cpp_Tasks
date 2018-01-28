
/******** This programm shows how to interrupt thread ********/

#include <iostream>
#include <fstream>
#include <windows.h>
#include <mutex>
#include <thread>
#include <string>

#include <condition_variable>	//thread break 
using namespace std;

mutex mtx;
condition_variable convar;
bool _var = false;
bool ret() { return _var; }

void foo()
{
	ofstream log;
	string str;
	static int nFoo = 0;
	while (true)
	{
		std::unique_lock<mutex> ulm(mtx);	//smart mutex
		convar.wait(ulm, ret);		//when ret = true, thread will be unlocked
		log.open("MtLog.log", ios_base::app);	//write from new line
		str = "Foo is: " + to_string(++nFoo) + '\n';
		log.write(str.c_str(), str.length());
		log.close();
		Sleep(500);
	}

}

void bar()
{
	while (true)
	{
		char answer;
		cout << "\ny/n?: ";
		cin >> answer;
		cin.clear();

		if (answer == 'y')
		{
			_var = true;
			convar.notify_one();		//waiting thread is notified with _var = true
		}
		if (answer == 'n')
		{
			_var = false;
		}
	}
}


int main()
{
	thread t1(foo);
	thread t2(bar);

	t1.detach();
	t2.join();
}


