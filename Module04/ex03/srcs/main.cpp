/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/18 23:14:51 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

//Different tests that can be done:
// 1- Try to instance Amateria. It doesn't work because it is abstract class
// 2- 

int main()
{
	//AMateria material;   // Impossible to instanciate because this is an abstract class 
	AMateria* material = new Ice();
	AMateria* material1 = new Cure();
	AMateria* clone = material->clone(); // Does a dynamic deep copy of material->clone
	AMateria* clone1 = material1->clone();
	
	delete clone1;
	delete clone;
	delete material1;
	delete material;

	// TESTING THE FUNCTION USE()
	Character character("Robert");
	Character character1("Cindy");
	std::cout << "The character's name is: " << character.getName() << std::endl;

	character1.equip(new Ice);
	character1.equip(new Cure);
	character1.equip(new Cure);
	character1.equip(new Ice);

	character.unequip(2);
	character.unequip(0);
	character.printInventory();

	character.equip(new Ice);
	character.printInventory();
	character.equip(new Ice);
	character.printInventory();

	character1.use(3, character);

	return 0;
}


//MAIN INSIDE PDF
	
	// MateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");
	
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	
	// ICharacter* bob = new Character("bob");
	
	// me->use(0, *bob);
	// me->use(1, *bob);
	
	// delete bob;
	// delete me;
	// delete src;