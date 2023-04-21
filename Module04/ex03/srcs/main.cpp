/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/21 14:15:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	/*
	** ----------------TESTING MAIN() FUNCTION INSIDE PDF  ----------------
	*/
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	/*
	** ----------------TESTING MATERIAS INSTANCIATION AND CLONE() FUNCTION  ----------------
	*/

	// AMateria* materia1 = new Cure();
	// AMateria* materia2 = materia1->clone();
	// AMateria* materia3 = new Ice();
	// AMateria* materia4 = materia3->clone();

	// delete materia1;
	// delete materia2;
	// delete materia3;
	// delete materia4;

	/*
	** ----------------TESTING CHARACTER EQUIP(), UNEQUIP(), USE() ----------------
	*/

	// Character character("Robert");

	// character.equip(new Ice);
	// character.equip(new Ice);
	// character.equip(new Cure);
	// character.equip(new Cure);
	// character.equip(new Ice); // Additional Material will immmediately be deleted because inventory alredy full
	// character.printInventory();

	// character.unequip(1);
	// character.unequip(1);
	// character.unequip(3);
	// character.printInventory();

	// Character character1("Cindy");
	// character.use(0, character1);
	// character.use(3, character1);
	// character.use(1, character1); // Will do nothing because _inventory is empty at index [1]

	/*
	** ----------------TESTING CHARACTER DEEP COPY WHEN COPY CONSTRUCTOR AND ASSIGNEMENT OPERATOR ----------------
	*/

	// Character character2("Cesar");
	// character2.equip(new Ice);
	// character2.equip(new Ice);
	// character2.equip(new Cure);
	// character2.equip(new Cure);
	// Character character3 = character2;

	// std::cout << character2.getName() << std::endl;
	// character2.printInventory();

	// std::cout << character3.getName() << std::endl;
	// character3.printInventory();


	return (0);
}
