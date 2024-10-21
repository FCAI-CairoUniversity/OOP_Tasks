#include <bits/stdc++.h>
using namespace std;

class Books {
private:
    string name, author, isbm;
    double price;
    static int count;
public:
    Books (string n = "Unknown", string a = "Unknown", string i = "Unknown", double p = 0.0) {
        name = n, author = a, isbm = i;
        price = p, count++;
    }

    static int getCount () {return count;}
    bool operator < ( Books& b2) const;
};

bool Books::operator < ( Books& b2) const {
    return price < b2.price;
}

int Books::count = 0;
int main () {
    Books book1("Math 3", "Dr. Mostafa", "123", 50);
    Books book2("OOP", "Dr. Mohammed El-Ramly", "456", 150);
    Books book3("Network", "Dr. Mohammed Hamed", "456", 275);

    if (book1 < book2) {
        cout << "The first book price is less than the second book price." << endl;
    }
    else {
        cout << "The second book price is less than the first book price." << endl;
    }
    cout << "The number of books = " << book2.getCount() << endl;
    return 0;
}