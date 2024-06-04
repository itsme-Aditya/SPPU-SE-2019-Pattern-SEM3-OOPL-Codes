#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    char name[20];
    int code, cost, quantity;

    bool operator ==(const Item& obj) {
        return code == obj.code;
    }
    bool operator <(const Item& obj) {
        return code < obj.code;
    }
};
vector<Item> items;
void print(const Item& obj) {
    cout << "\nName: " << obj.name;
    cout << "\nCode: " << obj.code;
    cout << "\nCost: " << obj.cost;
    cout << "\nQuantity: " << obj.quantity;
}
void display() {
    for_each(items.begin(), items.end(), print);
}
void insert() {
    Item obj;
    cout << "Enter item name: ";
    cin >> obj.name;
    cout << "Enter item code: ";
    cin >> obj.code;
    cout << "Enter item cost: ";
    cin >> obj.cost;
    cout << "Enter item quantity: ";
    cin >> obj.quantity;
    items.push_back(obj);
}
void del() {
    vector<Item>::iterator p;
    Item obj;
    cout << "Enter item code to delete: ";
    cin >> obj.code;
    p = find(items.begin(), items.end(), obj);
    if (p == items.end()) {
        cout << "\nItem not found";
    }
    else {
        items.erase(p);
    }
}
void search() {
    vector<Item>::iterator p;
    Item obj;
    cout << "Enter item code to search for: ";
    cin >> obj.code;
    p  = find(items.begin(), items.end(), obj);
    if (p == items.end()) {
        cout << "\nItem not found";
    }
    else {
        cout << "Item found";
        cout << "\nName: " << p->name;
        cout << "\nCode: " << p->code;
        cout << "\nCost: " << p->cost;
        cout << "\nQuantity: " << p->quantity; 
    }
}
bool compare(const Item& obj1, const Item& obj2) {
    return obj1.cost < obj2.cost;
}
int main() {
    int ch;
    while (true) {
        cout << "-----------MENU-----------";
        cout << "\n1) Insert";
        cout << "\n2) Display";
        cout << "\n3) Delete";
        cout << "\n4) Sort";
        cout << "\n5) Search";
        cout << "\n6) Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            del();
            break;
        case 4:
            sort(items.begin(), items.end(), compare);
            cout << "\nSorted on cost";
            break;
        case 5:
            search();
            break;
        case 6:
            return 0;
        default:
            cout << "Enter valid choice";
            break;
        }
    }
    return 0;
}
