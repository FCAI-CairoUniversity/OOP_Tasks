#include <bits/stdc++.h>
using namespace std;
class Shape {
protected:
    double dimension1, dimension2;
public:
    Shape(double dim1, double dim2) : dimension1(dim1), dimension2(dim2) {}
    virtual double compute_area() = 0;
    virtual ~Shape() = default;
};
class Triangle : public Shape {
public:
    Triangle(double base, double height) : Shape(base, height) {}

    double compute_area() override {
        return 0.5 * dimension1 * dimension2;
    }
};
class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : Shape(width, height) {}

    double compute_area() override {
        return dimension1 * dimension2;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Triangle>(3.0, 4.0));
    shapes.push_back(make_unique<Rectangle>(5.0, 6.0));
    shapes.push_back(make_unique<Triangle>(7.0, 8.0));
    shapes.push_back(make_unique<Rectangle>(9.0, 10.0));
    shapes.push_back(make_unique<Triangle>(11.0, 12.0));

    for (const auto& shape : shapes) {
        cout << "Area: " << shape->compute_area() << endl;
    }
    return 0;
}
