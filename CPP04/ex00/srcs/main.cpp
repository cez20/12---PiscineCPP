/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/11 17:58:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "The Animal type is a: " << j->getType() << std::endl;
	std::cout << "The Animal type is a: " << i->getType() << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound(); // Will output the dog sound 

	delete i;
	delete j;
	delete meta;

	std::cout << "\n\n";

	const WrongAnimal* meta1 = new WrongAnimal();
	const WrongAnimal* i1 = new WrongCat();

	i1->makeSound();
	meta1->makeSound();

	delete i1;
	delete meta1;

	return (0);
}
