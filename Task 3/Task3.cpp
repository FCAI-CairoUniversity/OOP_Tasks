#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.00f) {}

    virtual void set_data() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore();
    }

    virtual void get_data() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }

    virtual ~Publication() = default;
};

class Book : public Publication {
private:
    int page_count;

public:
    Book() : page_count(0) {}

    void set_data() override {
        Publication::set_data();
        cout << "Enter page count: ";
        cin >> page_count;
        cin.ignore();
    }

    void get_data() const override {
        Publication::get_data();
        cout << "Page Count: " << page_count << endl;
    }
};

class Tape : public Publication {
private:
    float playing_time;

public:
    Tape() : playing_time(0.00f) {}

    void set_data() override {
        Publication::set_data();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
        cin.ignore();
    }

    void get_data() const override {
        Publication::get_data();
        cout << "Playing Time: " << playing_time << " minutes" << endl;
    }
};

int main() {
    Publication* pub_ptr;

    Book book;
    Tape tape;

    cout << "Enter data for Book:"<<endl;
    pub_ptr = &book;
    pub_ptr->set_data();

    cout <<endl<< "Enter data for Tape:"<<endl;
    pub_ptr = &tape;
    pub_ptr->set_data();

    cout <<endl<< "Displaying Book Data:"<<endl;
    pub_ptr = &book;
    pub_ptr->get_data();

    cout <<endl<< "Displaying Tape Data:"<<endl;
    pub_ptr = &tape;
    pub_ptr->get_data();
    return 0;
}
