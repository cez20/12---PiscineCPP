/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/23 15:44:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define YEL "\e[0;33m"
# define REDB "\e[41m"

int main()
{
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                               ARRAY OF 100 BRAINS                                 *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;

	{
		Brain brain1;

		for (int i = 0; i < 100; i++)
			brain1.printIdea(i);
	}

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                                ARRAY HALF DOG, HALF CAT                           *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;

	Animal* animal[10];

	for(int i = 0; i < 6; i++)
	{
		if (i < 3)
			animal[i] = new Dog(); 
		else
			animal[i] = new Cat();
	}

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                                DESTRUCTION OF DOGS AND CATS                       *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;

	for(int i = 0; i < 6; i++)
		delete	animal[i];

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                       SHALLOW COPY VS DEEP COPY - CAT VERSION                     *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;

	{
		Cat a;
		Cat b(a);

		std::cout << "\nPrinting the address of _ptrBrain for instance A: ";	
		std::cout << a.getBrain() << std::endl;
		std::cout << "Printing the address of _ptrBrain for instance B: ";	
		std::cout << b.getBrain() << std::endl;

		std::cout << "\nPrinting the content of Brain[0] for instance A: ";	
		a.getBrain()->printIdea(0);
		std::cout << "\n";
		std::cout << "Printing the content of Brain[0] for instance B: ";	
		b.getBrain()->printIdea(0);
		std::cout << "\n";
		
		a.getBrain()->setIdea("MEOW", 0);

		std::cout << "\nPrinting the content of Brain[0] for instance A after change: ";	
		a.getBrain()->printIdea(0);
		std::cout << "\n";
		std::cout << "Printing the content of Brain[0] for instance B after change: ";	
		b.getBrain()->printIdea(0);
		std::cout << "\n";

		std::cout << "\n";
	}
	
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                             MANDATORY PDF TESTS                                   *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;//should not create a leak
	delete i;

	return 0;
}
