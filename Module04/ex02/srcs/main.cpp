/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/16 21:12:06 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define YEL "\e[0;33m"
# define REDB "\e[41m"

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                         INSTANCIATION OF DOG = POSSIBLE                           *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	AAnimal* animal = new Dog();
	animal->makeSound();
	delete animal;

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                         INSTANCIATION OF CAT = POSSIBLE                           *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;

	AAnimal* animal1 = new Cat();
	animal1->makeSound();
	delete animal1;

	// std::cout << GRN"*************************************************************************************" RESET << std::endl;
    // std::cout << GRN"*                  INSTANCIATION OF AANIMAL = IMPOSSIBLE (ABSTRACT CLASS)           *" RESET << std::endl;
    // std::cout << GRN"*************************************************************************************" RESET << std::endl;

	// AAnimal AAnimal;
	// AAnimal->makeSound();
	
	return (0);
	
}
