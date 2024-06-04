#include<iostream>
using namespace std;

class Publication {
    protected:
    float price;
    string title;
    void inputdata() {
        cout << "\nEnter Title:";
        cin >> title;
        cout << "Enter price:";
        cin >> price;
        if (price < 0) {
            price = 0;
        }
    }
    void printdata() {
        cout << "\nTitle:" << title;
        cout << "\nPrice:" << price << " rupees";
    }
};

class Book: public Publication {
    int page_count;
    public:
    void setdata() {
        cout << "Enter book details:";
        inputdata();
        cout << "Enter page count:";
        cin >> page_count;
        if (page_count < 0) {
            page_count = 0;
        }
    }
    void getdata() {
        cout << "\n\nBook details:";
        printdata();
        cout << "\nPage count:" << page_count << " pages";
    }
};

class Tape: public Publication {
    float play_time;
    public:
    void setdata() {
        cout << "\nEnter tape details:";
        inputdata();
        cout << "Enter play time:";
        cin >> play_time;
        if (play_time < 0) {
            play_time = 0;
        }
    }
    void getdata() {
        cout << "\n\nTape details:";
        printdata();
        cout << "\nPlay time:" << play_time << " minutes\n";
    }
};

int main()
{
    Book obj1;
    Tape obj2;
    obj1.setdata();
    obj2.setdata();
    obj1.getdata();
    obj2.getdata();
    return 0;
}
