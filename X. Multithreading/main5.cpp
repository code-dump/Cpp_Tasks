
/******** This programm shows how to interrupt thread ********/

#include <iostream>
#include <windows.h>
#include <thread>
#include <string>
#include <future> // thread break only once
using namespace std;



bool task(int n, string dots)
{
	Sleep(n*100);
	cout << n << ": ";
	return true;
}

void task_f(future<int> &f)
{
	int n = f.get();
	Sleep(n * 100);
	cout << n << ": DONE" << endl;
}

int main()
{
  //Alternatives:


	// First method 
	{
		future<bool> ft = async(task, 3, "; ");

		if (ft.get())		//programm waiting until thread will return value
		{
			cout << "DONE1" << endl;
		}
	}

	// Second method 
	{
		packaged_task<bool(int, string)> tsk(task);		//package

		future<bool> ret = tsk.get_future();
		thread th(move(tsk), 2, "; ");
		if (ret.get())		//programm waiting until thread will return value
		{
			cout << "DONE2" << endl;
		}
		th.join();
	}

	// Third method :: seting value by yourself
	{
		promise<int> num;
		future<int> ft = num.get_future();
		thread t1(task_f, ref(ft));

		num.set_value(1);		//thread waiting until programm will give it some value

		t1.join();
	}

}

