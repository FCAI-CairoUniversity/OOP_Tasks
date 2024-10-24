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
class CounterDecV2 : public Counter
{
	public:
        CounterDecV2():Counter() //call the default 
                              //constructor of base class
        {}
        CounterDecV2(int c): Counter(c) //constructor with              
                          //parameter calls the base constructor 
        {}
        void decrement()
        {
        	count--;
        }
};


int main(int argc, char *argv[])
{
    CounterDecV2 cd(10);
	cout<< cd.getCount();  //10
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
