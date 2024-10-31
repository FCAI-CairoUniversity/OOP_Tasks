#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;
    // Helper function to convert inches to feet if inches exceed 12
    void convert_inches_to_feets() {
        feet += inches / 12;
        inches %= 12;
    }

public:
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {
        convert_inches_to_feets();
    }

    void print(){
        cout<<endl<<"feet number: "<<feet<<" feet"<<endl;
        cout<<"inches number: "<<inches<<" inches"<<endl;
    }
    friend void compare(Distance& d1,Distance& d2);
    int get_total_inches() {
        return feet * 12 + inches;
    }
};
Distance max(Distance& d1, Distance& d2) {
    return (d1.get_total_inches() > d2.get_total_inches()) ? d1 : d2;
}
void compare(Distance& d1, Distance& d2) {
    if (d1.get_total_inches() > d2.get_total_inches()) {
        cout<<endl << "Larger distance is: ";
        d1.print();
    }
    else if (d1.get_total_inches() < d2.get_total_inches()) {
        cout<<endl << "Larger distance is: ";
        d2.print();
    }
    else {
        cout<<endl << "Both distances are equal: ";
        d1.print();
    }
}
int main() {
    Distance d1(2, 6);
    Distance d2(3, 4);
    cout << "Distance 1: ";
    d1.print();
    cout << "Distance 2: ";
    d2.print();
    Distance larger = max(d1, d2);
    cout << "Larger distance (using max function): ";
    larger.print();
    cout << "Comparing using friend function: ";
    compare(d1, d2);
    return 0;
}
