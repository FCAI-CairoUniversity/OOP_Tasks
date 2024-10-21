#include <iostream>
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
}
