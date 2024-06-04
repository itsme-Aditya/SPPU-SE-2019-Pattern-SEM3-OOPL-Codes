#include <iostream>
using namespace std;

class personalinfo {
    string license, dob, bldgrp;
public:
    personalinfo();
    personalinfo(const personalinfo&);
    ~personalinfo() {
        cout << "Destructor is called" << endl << "Record deleted successfully";
    }
    friend class student;
};
class student {
    string name, clas, div, address;
    int roll, phone;
    static int count;
public:
    void setdata(personalinfo&);
    void display(personalinfo&);
    inline static void incrementcount() {
        count++;
    }
    inline static void showcount() {
        cout << "Total number of records: " << count;
    }
    student();
    student(const student&);
    ~student() {
        cout << "Destructor is called" << endl << "Student deleted successfully";
    }
};

int student::count;

personalinfo::personalinfo() {
    license = "License number";
    dob = "Date of birth";
    bldgrp = "Blood group";
}

personalinfo::personalinfo(const personalinfo& obj) {
    license = obj.license;
    dob = obj.dob;
    bldgrp = obj.bldgrp;
}

student::student() {
    name = "Name";
    clas = "Class";
    div = "Division";
    roll = 00;
    phone = 0000000000;
    address = "Address";
}

student::student(const student& obj) {
    name = obj.name;
    clas = obj.clas;
    div = obj.div;
    roll = obj.roll;
    phone = obj. phone;
    address = obj.address;
}

void student::setdata(personalinfo& obj) {
    cout << "\nName: ";
    cin >> name;
    cout << "\nClass: ";
    cin >> clas;
    cout << "\nDivision: ";
    cin >> div;
    cout << "\nRoll number: ";
    cin >> roll;
    cout << "\nPhone number: ";
    cin >> phone;
    cout << "\nAddress: ";
    cin >> address;
    cout << "\nLicense number: ";
    cin >> obj.license;
    cout << "\nDate of birth: ";
    cin >> obj.dob;
    cout << "\nBlood group: ";
    cin >> obj.bldgrp;
}
void student::display(personalinfo& obj) {
    cout << "\nName: " << name;
    cout << "\nClass: " << clas;
    cout << "\nDivision: " << div;
    cout << "\nRoll number: " << roll;
    cout << "\nPhone number: " << phone;
    cout << "\nAddress: " << address;
    cout << "\nLicense number: " << obj.license;
    cout << "\nDate of birth: " << obj.dob;
    cout << "\nBlood group: " << obj.bldgrp;
}

int main() {
    personalinfo *p;
    student *s;
    int n;
    cout << "Enter number of students to store: ";
    cin >> n;
    p = new personalinfo[n];
    s = new student[n];
    for (int i = 0; i < n; i++) {
        s[i].setdata(p[i]);
        s[i].display(p[i]);
    }
    return 0;
}
