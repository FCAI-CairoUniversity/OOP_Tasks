#include <bits/stdc++.h>
using namespace std;

template<typename T>
class MyVector{
private:
    T* data;
    size_t capacity;
    size_t currentSize;
    void resizeCapacity(size_t newCapacity) {
        capacity = newCapacity;
        T *temp = new T[capacity];
        for (int i = 0; i < currentSize; ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    };

public:
    MyVector(){
        capacity = 1;
        data = new T[capacity];
        currentSize = 0;
    };
    ~MyVector(){
        delete[] data;
    };

    bool empty() const {
        return capacity == 0;
    };

    void pushBack(const T& value){
        if (currentSize == capacity) {
            resizeCapacity(capacity * 2);
        }
        data[currentSize] = value;
        currentSize++;
    };
    void popBack() {
        currentSize--;
        resizeCapacity(--capacity);
    };

    T max() const {return *max_element(data ,data+currentSize);};
    T min() const{return *min_element(data ,data+currentSize);};
    void sortFN(){sort(data, data+currentSize);};

    T* begin() {return data;};
    T* end() {return data+currentSize;};
};

int main () {
    MyVector<int> vec;
    vec.pushBack(5);
    vec.pushBack(3);
    vec.pushBack(8);
    vec.pushBack(1);

    cout << "Max: " << vec.max() << endl;
    cout << "Min: " << vec.min() << endl;

    vec.sortFN();

    cout << "Sorted: ";
    for (auto it = vec.begin(); it != vec.end() ;it++) {
        cout << *it << " ";
    }
    cout << endl;
    vec.popBack();
    cout << "after removing the last element: ";
    for (auto it = vec.begin(); it != vec.end() ;it++) {
        cout << *it << " ";
    }
    cout << endl << endl;

    MyVector<string> vec2;
    cout<<"HI"<<endl;
    vec2.pushBack("Banana");
    vec2.pushBack("Apple");
    vec2.pushBack("Cherry");

    cout << "Max: " << vec2.max() << endl;
    cout << "Min: " << vec2.min() << endl;

    vec2.sortFN();

    cout << "Sorted: ";
    for (auto it = vec2.begin(); it != vec2.end() ;it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}