#include<iostream>
using namespace std;

class Base
{
private:
		int x;
protected:
		int y;
public:
		Base(){
			x = 3;
		}
		friend void printXY();
};

class Derived:public Base
{
public:
		Derived(){
			y = 5;
		}
};
void printXY(){
Base b;
Derived d;
cout<<"X = "<<b.x<<endl; //line 1
cout<<"Y = "<<d.y<<endl; //line 2
}
int main(){
    printXY();

}
