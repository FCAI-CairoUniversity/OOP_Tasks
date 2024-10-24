#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


class Employee
{
private:
	string name;
	int id;
	double netPay;
public:
	Employee(string n, int i): name(n), id(i)
	{}
   void setNetPay(double np)
   {
        netPay=np;
   }
 
    void calculateSalary() 
    { 
         cout<<"Error, missing info. Try to call from a derived class";
    }
    void printEmployeeInfo()
    {
         cout<< "name:"<<name<<", ID:"<<id<<", Salary:"<<netPay<<endl;
    }
};
class HourlyEmployee : public Employee
{
	private:
		double ratePerHour;
		double workingHours;
    public:
    HourlyEmployee(string name, int id): Employee(name, id)
		{}
    void calculateSalary()  //overriding
	{
         setNetPay( ratePerHour* workingHours);
	}
	void setRatePerHour(double r)
    {
         ratePerHour=r;
     }
	void setWorkingHours(double h)
    {
         workingHours=h;
     }	
};
class SalariedEmployee : public Employee
{
	private:
		double salary;
    public:
    SalariedEmployee(string name, int id): Employee(name, id)
    {
    salary=0;                        
  }
    void calculateSalary()  //overriding
	{
			setNetPay( salary);
	}
	double getSalary()
    {
         return salary;
     }
	void setSalary(double s)
    {
         salary=s;
         setNetPay(salary);
     }
};


int main(int argc, char *argv[])
{
    HourlyEmployee hala("Hala",12201);
	SalariedEmployee ali("Ali",12202);
	hala.setRatePerHour(20);
	hala.setWorkingHours(90);
    hala.calculateSalary();
    hala.printEmployeeInfo();
    ali.setSalary(1500);
    ali.printEmployeeInfo();
    
    system("PAUSE");
    return 0;
}
