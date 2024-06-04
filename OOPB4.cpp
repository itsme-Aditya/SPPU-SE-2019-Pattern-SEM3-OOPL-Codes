#include <iostream>
#include <fstream>
using namespace std;

class employee {
    char name[20];
    int id;
    float salary;
public:
    void getdata() {
        cin >> name;
        cin >> id;
        cin >> salary;
    }
    void display() {
        cout << "\n" << name << "\t" << id << "\t" << salary;
    }
};
int main() {
    int i, n;
    employee o[5];
    fstream f;
    
    f.open("input.txt");
    cout << "Enter number of employees to store: ";
    cin >> n;
    cout << "Enter information of employees(name id salary): ";
    for (i = 0; i < n; i++) {
        o[i].getdata();
        f.write((char*)&o[i], sizeof(o[i]));
    }        
    f.close();
    
    f.open("input.txt", ios::in);
    cout << "\nInformation of employees as follows: ";
    cout << "\nNAME\tID\tSALARY";
    for (i = 0; i < n; i++) {
        f.read((char*)&o[i], sizeof(o[i]));
        o[i].display();
    }
    f.close();
    return 0;
}
