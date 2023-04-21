/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/21 12:32:47 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

//Different tests that can be done:
// 1- Try to instance Amateria. It doesn't work because it is abstract class
// 2- 

int main()
{
	//AMateria material;   // Impossible to instanciate because this is an abstract class 
	// AMateria* material = new Ice();
	// AMateria* material1 = new Cure();
	// AMateria* clone = material->clone(); // Does a dynamic deep copy of material->clone
	// AMateria* clone1 = material1->clone();
	
	// delete clone1;
	// delete clone;
	// delete material1;
	// delete material;

	// // TESTING THE CHARACTER EQUIP(), UNEQUIP() AND USE()
	Character character("Robert");
	Character character1("Cindy");

	// EQUIP: Additional Materia is created but immediately deleted since no place in invetory. 
	character.equip(new Ice);
	character.equip(new Cure);
	character.equip(new Cure);
	character.equip(new Ice);
	character.equip(new Cure); // Additional Material 
	character.printInventory();

	// UNEQUIP() and USE(). Unequip an unexisting Materia or using an Unexisting Materia, will do nothing. 
	character.unequip(1);
	character.unequip(3);
	// character.use(1, character1); // Will do nothing 
	// character.use(0, character1);
	// character.use(3, character1);
	character.printInventory();


	//TESTING COPY CONSTRUCTOR AND OPERATOR AFFECTATON;

	// Character charact;
	// charact.equip(new Ice);
	// charact.equip(new Cure);
	// charact.equip(new Cure);
	// charact.equip(new Ice);
	// Character charact1 = charact;  // Le probleme est que le constructeur de charact1 n'est jamais appele 
	
	// IMateriaSource* src = new MateriaSource();
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
	 return 0;

}
