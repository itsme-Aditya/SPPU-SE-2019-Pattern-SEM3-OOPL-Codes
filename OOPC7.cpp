#include <iostream>
#include <map>
using namespace std;

void display(map<string, int> statesPopulation) {
    map<string, int>::iterator it;
    it = statesPopulation.begin();
    while (it != statesPopulation.end()) {
        cout << "\nSTATE: " << it->first;
        cout << "\nPOPULATION: " << it->second << endl;
        it++;
    }
}
void addState(map<string, int> &statesPopulation) {
    int population, n;
    string name;
    cout << "Enter number of states to add: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter state name: ";
        cin >> name;
        cout << "Enter state population: ";
        cin >> population;
        statesPopulation.insert({name, population});
    }
}
void delet(map<string, int> &statesPopulation) {
    string name;
    cout << "Enter name of the state to delete: ";
    cin >> name;
    statesPopulation.erase(name);
}
void search(map<string, int> statesPopulation) {
    string name;
    cout << "Enter name of the state to search: ";
    cin >> name;
    cout << "The population of " << name << " is " << statesPopulation[name] << endl;
}
int main() {
    int ch;
    map<string, int> data;
    while (true) {
        cout << "-------------MENU-------------\n1) Add states\n2) Display\n3) Delete\n4) Search\n5) Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            addState(data);
            break;
        case 2:
            display(data);
            break;
        case 3:
            delet(data);
            break;
        case 4:
            search(data);
            break;
        case 5:
            return 0;
        default:
            cout << "Enter valid choice" << endl;
            break;
        }
    }
    return 0;
}