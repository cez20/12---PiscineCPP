/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/16 21:54:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define YEL "\e[0;33m"
# define REDB "\e[41m"

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                         MANDATORY TESTS IN PDF                                    *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
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

	std::cout << "\n";
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "\n";
	
	delete bob;
	delete me;
	delete src;

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*               TESTING MATERIAS INSTANCIATION AND CLONE() FUNCTIONS                *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;	

	AMateria* materia1 = new Cure();
	AMateria* materia2 = materia1->clone();
	AMateria* materia3 = new Ice();
	AMateria* materia4 = materia3->clone();

	std::cout << "\n";
	delete materia1;
	delete materia2; 
	delete materia3;
	delete materia4;

	// std::cout << GRN"*************************************************************************************" RESET << std::endl;
    // std::cout << GRN"*               TESTING EQUIP(), UNEQUIP(), USE() FUNCTIONS                         *" RESET << std::endl;
    // std::cout << GRN"*************************************************************************************" RESET << std::endl;	

	// Character character("Robert");

	// character.equip(new Ice);
	// character.equip(new Ice);
	// character.equip(new Cure);
	// character.equip(new Cure);

	// std::cout << RED "\nInventory is full (4 items). Any additional Materia is created and then deleted on the spot" RESET << std::endl;
	// character.equip(new Ice); // Additional Material will immmediately be deleted because inventory already full

	// std::cout << RED "\nPrinting character inventory and address of Materia" RESET << std::endl;
	// character.printInventory();

	// std::cout << RED "\nRemoving materias from character's inventory" RESET << std::endl;
	// character.unequip(1);
	// character.unequip(1);
	// character.unequip(3);

	// std::cout << RED "\nReprinting character inventory and address of Materia" RESET << std::endl;
	// character.printInventory();

	// std::cout << RED "\nCharacter use his Materias against Cindy" RESET << std::endl;
	// Character character1("Cindy");
	// character.use(0, character1);
	// character.use(3, character1);
	// character.use(1, character1); // Will do nothing because _inventory is empty at index [1]

		std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*               TESTING EQUIP(), UNEQUIP(), USE() FUNCTIONS                         *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;	

	Character* character = new Character("Robert");

	character->equip(new Ice);
	character->equip(new Ice);
	character->equip(new Cure);
	character->equip(new Cure);

	std::cout << RED "\nInventory is full (4 items). Any additional Materia is created and then deleted on the spot" RESET << std::endl;
	character->equip(new Ice); // Additional Material will immmediately be deleted because inventory already full

	std::cout << RED "\nPrinting character inventory and address of Materia" RESET << std::endl;
	character->printInventory();

	std::cout << RED "\nRemoving materias from character's inventory" RESET << std::endl;
	character->unequip(1);
	character->unequip(1);
	character->unequip(3);

	std::cout << RED "\nReprinting character inventory and address of Materia" RESET << std::endl;
	character->printInventory();

	std::cout << RED "\nCharacter use his Materias against Cindy" RESET << std::endl;
	Character* character1 = new Character("Cindy");
	character->use(0, *character1);
	character->use(1, *character1);
	character->use(3, *character1);

	delete character1;
	delete character;


	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*     TESTING CHARACTER DEEP COPY WHEN COPY CONSTRUCTOR AND ASSIGNEMENT OPERATOR    *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;	

	Character character2("Cesar");
	character2.equip(new Ice);
	character2.equip(new Ice);
	character2.equip(new Cure);
	character2.equip(new Cure);
	Character character3 = character2;

	std::cout << character2.getName() << std::endl;
	character2.printInventory();

	std::cout << character3.getName() << std::endl;
	character3.printInventory();


	return (0);
}
