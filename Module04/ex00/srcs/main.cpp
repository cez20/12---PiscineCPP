/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/16 13:43:07 by cemenjiv         ###   ########.fr       */
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
#include "WrongCat.hpp"

int main()
{
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                          MANDATORY TESTS (Animal, Dog, Cat)                       *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << "\n";
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "The Animal type is a: " << j->getType() << std::endl;
	std::cout << "The Animal type is a: " << i->getType() << std::endl;
	
	i->makeSound(); // Will output the cat sound. 
	j->makeSound(); // Will output the dog sound 
	meta->makeSound(); // Will output the sound specified in Animal class. 

	delete i;
	delete j;
	delete meta;

	std::cout << "\n";

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                          TESTS (Wrong Animal, Wrong Dog)                          *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << "\n";

	const WrongAnimal* meta1 = new WrongAnimal();
	const WrongAnimal* i1 = new WrongCat();

	i1->makeSound();
	meta1->makeSound();

	delete i1;
	delete meta1;

	return (0);
}
