/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/13 10:49:48 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// delete j;//should not create a leak
	// delete i;

	// Animal*	animal = new Dog[5];  // Creer un pointeur animal qui pointe vers un tableau de 10 animal.  

	// delete[] animal;


	Animal* animal[10];

	// In this loop, animal[i] should do a copy of Brain and not keep same memory for dynamically allocated object.
	for(int i = 0; i < 10; i++)
	{
		if (i < 5)
			animal[i] = new Dog(); // Les 5 dogs sont crees dans des adresses qui en sont pas contigues
		else
			animal[i] = new Cat(); // Les 5 cats sont crees dans des adresses qui en sont pas contigues
	}

	for(int i = 0; i < 10; i++)
		delete	animal[i];
	
	return 0;
}
