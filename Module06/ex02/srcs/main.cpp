/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:29:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/11/03 15:45:20 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*   generate(void){

	int random = 1 + (rand() % 3);

	if (random == 1)
		return new A;
	else if (random == 2)
		return new B;
	else if (random == 3)
		return new C;
	else 
		return (NULL);
}

void	identify(Base *p){

	if(dynamic_cast<A*>(p))
		std::cout << "Base pointer true type is A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "Base pointer true type is B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "Base pointer true type is C" << std::endl;
	else
		std::cout << "There is an ERROR" << std::endl;
}

void	identify(Base &p){

	try{
		A & test = dynamic_cast<A&>(p);
		(void)test;
		std::cout << "Base reference true type is A" << std::endl;
	} catch (std::bad_cast &bc){
	}
	try{
		B& test2 = dynamic_cast<B&>(p);
		(void)test2;
		std::cout << "Base reference true type is B" << std::endl;
	} catch (std::bad_cast &bc){
	}
	try{
		C& test3 = dynamic_cast<C&>(p);
		(void)test3;
		std::cout << "Base reference true type is C" << std::endl;
	} catch (std::bad_cast &bc){
	}
}


int main ()
{
    srand((unsigned) time(NULL));
      
    Base *instance1 = generate();
    identify(instance1);
    identify(*instance1);
    
    Base *instance2 = generate();
    identify(instance2);
    identify(*instance2);

    Base *instance3 = generate();
    identify(instance3);
    identify(*instance3);
}