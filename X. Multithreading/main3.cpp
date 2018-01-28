/******** This programm shows how to synchronize threads ********/

#include <windows.h> 
#include <iostream>
#include <mutex>		//thread sync 
#include <thread>		//thread header 
#include <vector>
using namespace std;


struct Line
{
	Line(char* name, char* surname, int year) :
		name(name),
		surname(surname),
		year(year)
	{}

	char* name;
	char* surname;
	int   year;
};

void foo(vector<Line> & vBase, mutex& mtx)
{
	while (1)
	{
		mtx.lock();
		vBase.at(0).year = 1000;
		vBase.at(1).year = 1000;
		vBase.at(2).year = 1000;
		vBase.at(3).year = 1000;
		vBase.at(4).year = 1000;
		mtx.unlock();
	}
}

void boo(vector<Line> & vBase, mutex& mtx)
{
	while (1)
	{
		mtx.lock();
		vBase.at(0).year = 1984;
		vBase.at(1).year = 1991;
		vBase.at(2).year = 1954;
		vBase.at(3).year = 1986;
		vBase.at(4).year = 1921;
		mtx.unlock();
	}
}

void view(vector<Line> & vBase, mutex& mtx)
{
	while (1)
	{
		lock_guard<mutex> lock(mtx);		//smart pointer, will automaticly unlock mtx after ending of block
		cout << "View: ";
		for (auto row : vBase) { cout << row.year << ", "; } cout << endl;
		Sleep(10);
	}
}


int main()
{
	vector<Line> vBase;

	vBase.push_back(Line("Edward", "Johnson", 1984));
	vBase.push_back(Line("Petr", "Osetr", 1991));
	vBase.push_back(Line("Michael", "Notjackson", 1954));
	vBase.push_back(Line("Katy", "Fairy", 1986));
	vBase.push_back(Line("Joseph", "Combenezon", 1921));
	
	mutex mtx;

	thread t1(foo, ref(vBase), ref(mtx));
	thread t2(boo, ref(vBase), ref(mtx));
	thread t3(view, ref(vBase), ref(mtx));

	t1.detach();
	t2.detach();
	t3.join();
	
}

