#include <iostream>

// using namespace std;

// class A1 {
// public:
//     A1() { cout << "A1"; }
//     virtual ~A1() { cout << "~A1"; }
// };

// class A2 {
// public:
//     A2() { cout << "A2"; }
//     ~A2() { cout << "~A2"; }
// };

// class B : public A1, A2 {
// public:
//     B() { cout << "B"; }
//     ~B() { cout << "~B"; }
// };

// int main() {
//     A1* pa1 = new B;
//     delete pa1;

//     return 0;
// }

class Animal{
public:
    Animal() {std::cout << "Animal constructor called " << std::endl;}
    virtual ~Animal() { std::cout << "Animal destructor called" << std::endl; }
};

class Dog : public Animal {
public:
    Dog() {std::cout << "Dog constructor called" << std::endl;}
    ~Dog() {std::cout << "Dog destructor called" << std::endl;}
};

int main(){

    Animal* animal1 = new Dog;   // A base class can point to a derived object
    delete animal1;

    return (0);
}