#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;
    Complex() {
        real = 0;
        imag = 0;
    }
    Complex(double a, double b) {
        real = a;
        imag = b;
    }
    Complex operator +(const Complex& obj2) {
        return Complex(real + obj2.real, imag + obj2.imag);
    }
    Complex operator -(const Complex& obj2) {
        return Complex(real - obj2.real, imag - obj2.imag);
    }
    Complex operator *(const Complex& obj2) {
        return Complex(real * obj2.real - imag * obj2.imag, real * obj2.imag + imag * obj2.real);
    }
    Complex operator /(const Complex& obj2) {
        return Complex(real * obj2.real + imag * obj2.imag / obj2.real * obj2.real + obj2.imag * obj2.imag, imag * obj2.real - real * obj2.imag / obj2.real * obj2.real + obj2.imag * obj2.imag);
    }
    void display() {
        cout << real << "+" << "(" << imag << ")" << "i";
    }
};

int main() 
{
    double real1, imag1, real2, imag2;
    cout << "Enter real part of first number: ";
    cin >> real1;
    cout << "Enter imaginary part of first number: ";    
    cin >> imag1;
    cout << "Enter real part of second number: ";
    cin >> real2;
    cout << "Enter imaginary part of second number: ";
    cin >> imag2;
    
    Complex def;
    Complex one(real1, imag1);
    Complex two(real2, imag2);
    
    cout << "\n\nDefault complex number is: ";
    def.display();
    cout << "\nFirst complex number is: ";
    one.display();
    cout << "\nSecond complex number is: ";
    two.display();
    
    Complex sum = one + two;
    Complex diff = one - two;
    Complex prod = one * two;
    Complex div = one / two;
    
    cout << "\n\nSum of the two complex number is: ";
    sum.display();
    cout << "\nDifference of the two complex number is: ";
    diff.display();
    cout << "\nProduct of the two complex number is: ";
    prod.display();
    cout << "\nDivision of the two complex number is: ";
    div.display();

    return 0;
}
