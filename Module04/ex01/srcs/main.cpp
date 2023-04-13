/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/13 17:10:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// ARRAY OF ANIMAL OBJECTS : HALF IS DOG, HALF IS CAT
	// VALIDATION THAT CORRECT OBJECT IS CREATED IS TESTED THROUGH MAKE SOUND
	// DELETE ALL OBJECT USING "ANIMAL "

	Animal* animal[10];
	
	for(int i = 0; i < 10; i++)
	{
		if (i < 5)
			animal[i] = new Dog(); 
		else
			animal[i] = new Cat();
	}

	for (int i = 0; i < 10; i++)
		animal[i]->makeSound();

	for(int i = 0; i < 10; i++)
		delete	animal[i];

	// SHALLOW COPY VS DEEP COPY - CAT VERSION 

	Cat a;
	Cat b(a);

	a.getBrain()->printIdea(0);
	b.getBrain()->printIdea(0);
	
	a.getBrain()->setIdea("MEOW", 0);

	a.getBrain()->printIdea(0);
	b.getBrain()->printIdea(0);
	
	b = a;
	
	a.getBrain()->printIdea(0);
	b.getBrain()->printIdea(0);

	// // SHALLOW COPY VS DEEP COPY - DOG VERSION 

	Dog a1;
	Dog b1(a1);

	a1.getBrain()->printIdea(0);
	b1.getBrain()->printIdea(0);
	
	a1.getBrain()->setIdea("WOOF", 0);

	a1.getBrain()->printIdea(0);
	b1.getBrain()->printIdea(0);
	
	b1 = a1;
	
	a1.getBrain()->printIdea(0);
	b1.getBrain()->printIdea(0);


	// TESTING LEAKS - NO LEAK SHOULD BE VISIBLE

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;

	return 0;
}
