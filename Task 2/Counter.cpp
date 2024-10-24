#include <cstdlib>
#include <iostream>

using namespace std;


class Counter
{
	protected:
			int count;
	public:
			Counter() //default constructor
{
				count=0;
			}
			Counter(int c) //constructor with parameter
{
				count=c;
			}
int getCount ()
{
	return count;
}
void increment()
{
	count++; 	
}
} ;
class CounterDec : public Counter
{
	public:
		void decrement()
		{
			count--;
		}
};


int main(int argc, char *argv[])
{
    CounterDec cd;
	cout<< cd.getCount();  //0
	cd.increment();  //register a student  
	cd.increment(); //register another student
	cd.increment(); //register another student
	cout<< cd.getCount();  //3
	cd.decrement();  //cancel the registration of a student  
	cd.decrement(); // cancel the registration of another student
	cout<< cd.getCount();  //1
    system("PAUSE");
    return 0;
}
