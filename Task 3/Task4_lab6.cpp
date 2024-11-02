#include <iostream>

using namespace std;

class product {
protected:
	string name;
	double price;
	int stock;

public:
	product(string nam, double p, int st) :name(nam), price(p), stock(st){}
	virtual void apply_discount() = 0;
};
class electronics : public product {
public:
	electronics(string nam, double p, int st): product(nam,p,st){}
	void apply_discount()override {
		cout << "Product name: " << name << endl;
		cout << "Before discount: " << price << endl;
		if (price > 100) {
			price *= 0.85;
		}
		cout << "After discount: " << price << endl;
	}
};
class clothing : public product {
public:

	clothing(string nam, double p, int st) : product(nam, p, st) {}
	void apply_discount()override {
		cout << "Product name: " << name << endl;
		cout << "Before discount: " << price << endl;
		if (price > 30) {
			price *= 0.9;
		}
		cout << "After discount: " << price << endl;
	}
};



int main() {
	product* product_ptrs[5];
	electronics lab1("vitus", 400.1,2);
	electronics lab2("HP", 50.1, 8);
	electronics lab3("TV", 101, 5);
	clothing suit1("jacket", 40, 80);
	clothing suit2("Suit", 10, 70);
	product_ptrs[0] = &lab1;
	product_ptrs[1] = &lab2;
	product_ptrs[2] = &lab3;
	product_ptrs[3] = &suit1;
	product_ptrs[4] = &suit2;
	for (int i = 0; i < 5; i++) {
		product_ptrs[i]->apply_discount();
	}
}
