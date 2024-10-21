#include<iostream>
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
}
