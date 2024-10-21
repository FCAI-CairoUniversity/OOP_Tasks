#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    long ID;
    int group;
public:
   static int studentCount;
};
int Student::studentCount = 0;
int main()
{
   Student s1, s2, s3;
   s1.studentCount = 1;
   s2.studentCount = 2;         // Because it's static value of last value will be saved on others
   s3.studentCount = 3;
   cout << s1.studentCount << endl;
   cout << s2.studentCount << endl;
   cout << s3.studentCount << endl;

   system("pause");
   return 0;
}
