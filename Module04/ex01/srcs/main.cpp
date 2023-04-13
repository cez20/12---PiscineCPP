/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/13 14:25:04 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	Animal* animal[10];
	
	for(int i = 0; i < 10; i++)
	{
		if (i < 5)
			animal[i] = new Dog(); // 5 Dogs are create in non-contiguous addresses
		else
			animal[i] = new Cat(); // 5 Cats are created in non-contiguous addresses
	}

	for (int i = 0; i < 10; i++)
		animal[i]->makeSound();

	for(int i = 0; i < 10; i++)
		delete	animal[i];


	Cat a;    
	Cat b(a); 


	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	
	// delete j;//should not create a leak
	// delete i;


	return 0;
}
