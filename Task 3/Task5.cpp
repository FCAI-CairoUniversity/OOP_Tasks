#include<iostream>
using namespace std;

class Location{
private:
    double longitude;
    double latitude;
public:
    Location():longitude(0.0),latitude (0.0){}
    Location(double _longitude,double _latitude)
    {
        longitude = _longitude;
        latitude = _latitude;
    }
void print(){
    cout<<"(Longitude: "<<longitude<<", Latitude: "<<latitude<<")"<<endl;
}

friend Location operator+(Location,Location);
friend Location operator-(Location,Location);
friend Location operator*(Location,Location);
friend bool operator ==(Location,Location);
friend bool operator !=(Location,Location);
};
Location operator+(Location x, Location y){
    Location result;
    result.longitude = x.longitude + y.longitude;
    result.latitude = x.latitude + y.latitude;
    return result;
}
Location operator-(Location x, Location y){
    Location result;
    result.longitude = x.longitude - y.longitude;
    result.latitude = x.latitude - y.latitude;
    return result;
}
Location operator*(Location x, Location y){
    Location result;
    result.longitude = x.longitude * y.longitude;
    result.latitude = x.latitude * y.latitude;
    return result;
}
bool operator==(Location x, Location y){
    return (x.longitude==y.longitude && x.latitude==y.latitude);
}
bool operator !=(Location x, Location y){
    return !(x == y);
}
int main(){
    Location loc1(3.124,7.444);
    Location loc2(21.332,56.677);
    cout<<"Loc1 + Loc2 = ";
    (loc1+loc2).print();
    cout<<"Loc1 - Loc2 = ";
    (loc1-loc2).print();
    cout<<"Loc1 * Loc2 = ";
    (loc1*loc2).print();

    if(loc1 == loc2){
        cout<<"locations are equal\n";
    }
    else{
        cout<<"locations are not equal\n";
    }
    system("PAUSE");
    return 0;
}
