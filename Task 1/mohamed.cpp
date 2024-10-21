/**#include <iostream>
using namespace std;
// Task1
class Time {
private:
    int hours, minutes, seconds;

public:
    Time() {
        hours = minutes = seconds = 0;
    }
    void setter(int hrs, int mts, int scnd) {
        seconds += scnd;
        minutes += mts+seconds / 60;
        hours += hrs + minutes / 60;
        seconds %= 60;
        minutes %= 60;
        hours %= 24;
    }
    bool operator<(const Time& t) const {
        if (hours < t.hours) return true;
        if (hours == t.hours && minutes < t.minutes) return true;
        if (hours == t.hours && minutes == t.minutes && seconds < t.seconds) return true;
        return false;
    }
    bool operator==(const Time& t) const {
        return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
    }
    void increament_time(int inc_hours, int inc_minutes, int inc_seconds) {
        seconds += inc_seconds;
        minutes += inc_minutes + seconds / 60;
        hours += inc_hours + minutes / 60;
        seconds %= 60;
        minutes %= 60;
        hours %= 24;
    }
    void print_time() {
        if (hours < 10) {
            cout << "0" << hours << " : ";
        }
        else {
            cout << hours << " : ";
        }
        if (minutes < 10) {
            cout << "0" << minutes << " : ";
        }
        else {
            cout << minutes << " : ";
        }
        if (seconds < 10) {
            cout << "0" << seconds << endl;
        }
        else {
            cout << seconds << endl;
        }
    }
};

int main() {
    cout<<"Menu"<<endl;
    cout<<"1: add time to time"<<endl;
    cout<<"2: Comparison two times"<<endl;
    cout<<"Enter your choice: ";
    int x;
    cin>>x;
    if(x==1){
        Time t1;
        int hrs, mnts, sec;
        cout << "Enter hour: ";
        cin >> hrs;
        cout << "Enter minutes: ";
        cin >> mnts;
        cout << "Enter seconds: ";
        cin >> sec;
        t1.setter(hrs, mnts, sec);
        cout << "Current time: ";
        t1.print_time();

        int hrs2, mnts2, sec2;
        cout << "Enter added hour: ";
        cin >> hrs2;
        cout << "Enter added minutes: ";
        cin >> mnts2;
        cout << "Enter added seconds: ";
        cin >> sec2;
        t1.increament_time(hrs2, mnts2, sec2);
        cout << "Time after increment: ";
        t1.print_time();
    }
    else if(x==2){
        cout<<"1: Check equality"<<endl;
        cout<<"2: check who is smaller"<<endl;
        int y;
        cin>>y;
        if(y==1){
            Time t1;
            int hrs, mnts, sec;
            cout << "Enter first hours: ";
            cin >> hrs;
            cout << "Enter first minutes: ";
            cin >> mnts;
            cout << "Enter first seconds: ";
            cin >> sec;
            t1.setter(hrs, mnts, sec);
            Time t2;
            int hrs2, mnts2, sec2;
            cout << "Enter second hours: ";
            cin >> hrs2;
            cout << "Enter second minutes: ";
            cin >> mnts2;
            cout << "Enter second seconds: ";
            cin >> sec2;
            t2.setter(hrs2, mnts2, sec2);
            if(t1==t2){
                cout<<"Two times are equal"<<endl;
            }
            else{
                cout<<"There is no equality"<<endl;
            }
        }
        else if(y==2){
            Time t1;
            int hrs, mnts, sec;
            cout << "Enter first hours: ";
            cin >> hrs;
            cout << "Enter first minutes: ";
            cin >> mnts;
            cout << "Enter first seconds: ";
            cin >> sec;
            t1.setter(hrs, mnts, sec);
            Time t2;
            int hrs2, mnts2, sec2;
            cout << "Enter second hours: ";
            cin >> hrs2;
            cout << "Enter second minutes: ";
            cin >> mnts2;
            cout << "Enter second seconds: ";
            cin >> sec2;
            t2.setter(hrs2, mnts2, sec2);
            if(t1<t2){
                cout<<"t1 is smaller than t2"<<endl;
            }
            else if(t2<t1){
                cout<<"t2 is smaller than t1"<<endl;
            }
            else{
                cout<<"t2 equals t1"<<endl;
            }
        }
    }
    return 0;
}**/
// Task2
/**#include<iostream>
using namespace std;
class Box{
private:
       double length; // Length of a box
       double width; // width of a box
       double height; // Height of a box
     public:
       /**double length; // Length of a box
       double width; // width of a box
       double height; // Height of a box
       Box(double x1,double x2,double x3){
           length = x1;
           width = x2;
           height = x3;
       }
       void setter(double x1,double x2,double x3){
            length = x1;
            width = x2;
            height = x3;
       }
       void print_volume(){
           cout<<"Volume: "<<length*width*height<<endl;
       }
};
int main(){
    Box box1(4.0, 6.0, 3.0);
    box1.print_volume();
    cout<<endl;
    Box box2(10.0, 12.0, 13.0);
    box2.print_volume();
}**/
// Task3
/**#include <iostream>
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
}**/
// Task4
/**#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;
    string isbn;
    static int bookCount;

public:
    Book(string t, string a, double p, string i) : title(t), author(a), price(p), isbn(i) {
        bookCount++; // Increment the count every time a new book is created
    }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getPrice() const { return price; }
    string getISBN() const { return isbn; }
    void displayBookDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "ISBN: " << isbn << endl;
    }
    static int getBookCount() {
        return bookCount;
    }
};
int Book::bookCount = 0;

int main() {
    Book b1("1984", "George Orwell", 9.99, "9780451524935");
    Book b2("To Kill a Mockingbird", "Harper Lee", 7.99, "9780061120084");
    Book b3("The Great Gatsby", "F. Scott Fitzgerald", 10.99, "9780743273565");
    cout << "Book 1 details:" << endl;
    b1.displayBookDetails();
    cout << endl;
    cout << "Book 2 details:" << endl;
    b2.displayBookDetails();
    cout << endl;
    cout << "Book 3 details:" << endl;
    b3.displayBookDetails();
    cout << endl;
    cout << "Total number of books created: " << Book::getBookCount() << endl;

    return 0;
}**/
