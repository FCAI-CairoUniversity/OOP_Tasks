#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Stack
{
    protected: //NOTE: can't be private
        int size; //size of stack array
        int *st; //stack: array of integers
        int top; //index to top of stack
    public:
        Stack() //default constructor
        {
           top = -1;
           size=5;
           st=new int [size];      
        }
        Stack(int s) //constructor
        { top = -1;
          size=s;
          st=new int [s];
         }
        void push(int var) //put number on stack
        { st[++top] = var; }
        int pop() //take number off stack
        { return st[top--]; }
};
class Stack2 : public Stack
{
    public:
       
        void push(int var) //put number on stack
        {
            if(top >= size-1) //error if stack full
            { 
                   cout << "\nError: stack is full"; 
                   return;
             }
            Stack::push(var); //call push() in Stack class
        }
        int pop() //take number off stack
        {
            if(top < 0) //error if stack empty
            { 
                   cout << "\nError: stack is empty\n"; 
                   return -1;
             }
            return Stack::pop(); //call pop() in Stack class
        }
};

int main(int argc, char *argv[])
{
    Stack2 s1;
    s1.push(11); //stack [11]
    s1.push(22);//stack [11,22]
    s1.push(33);//stack [11,22,33]
    cout << s1.pop(); //33
    cout << endl << s1.pop();  //22
    cout << endl << s1.pop();  //11
    cout << endl << s1.pop(); //Error, stack is empty
    cout << endl;
   
    system("PAUSE");
    return 0;
}
