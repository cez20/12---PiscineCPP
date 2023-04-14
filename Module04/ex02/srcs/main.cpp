/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/14 12:28:23 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//AAnimal instanciation is possible because the object it refers to is an object
	AAnimal* animal = new Dog();
	animal->makeSound();
	delete animal;

	AAnimal* animal1 = new Cat();
	animal1->makeSound();
	delete animal1;

	//AAnimal instanciation IMPOSSIBLE because AAnimal is an abtract class, because one of its
	// method is pure 

	// AAnimal AAnimal = AAnimal();
	// AAnimal->makeSound();

	return (0);
	
}
