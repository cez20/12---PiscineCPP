/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:53:52 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/11 22:50:18 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base {
public:
    Base(){std::cout <<"I called the Base class constructor" << std::endl;}
	virtual void foo() {
        std::cout << "Base::foo()" << std::endl;
    }
};

class Derived : public Base {
public:
	Derived(){std::cout << "I called the Derived class constructor" << std::endl;}
    virtual void foo(){
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
	
	Derived derived;
	Base & base = derived;
	
	base.foo();
    return 0;
}


/* In the given example, the function foo() is not being called as an overridden function because the object ptr is of type Base, not a pointer or reference to Base or Derived.

When you create an object of the Derived class and assign it to an object of the Base class, the object slicing happens, where only the base part of the derived class is retained, and the derived part is sliced off. This means that the derived class's constructor is called to initialize the derived part of the object, but that derived part is then lost when it is assigned to a base class object.

So when you call the foo() function through the ptr object, it calls the foo() function of the Base class, not the Derived class. This is because the object ptr is of type Base, and the function foo() is not a virtual function in the Base class. Therefore, it does not create a function override.

To create a function override, you can use a pointer or reference to the base class and assign it to an object of the derived class, like this:

scss

Base* ptr = new Derived();
ptr->foo();

In this case, the foo() function of the Derived class is called, because the function is marked as virtual in the Base class and overridden in the Derived class, and the function call is made through a pointer to the base class. */