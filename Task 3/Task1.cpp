#include<iostream>
using namespace std;
/*
    output : I'm base
             I'm derived
*/
class base
{
public:
    virtual void say() { cout << "\n I'm base \n"; }
};

class derived: public base
{
public:
		void say() { cout << "\n I'm derived \n"; }
};

int main()
{
    base *pb;
    base mybase;
    derived myderived;

    pb=&mybase;
    pb->say();

    pb=&myderived;
    pb->say();

    system("PAUSE");
    return 0;
}
