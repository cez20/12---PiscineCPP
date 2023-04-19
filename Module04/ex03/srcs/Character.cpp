/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:32:17 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/18 23:13:03 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(): _name("")
{
	std::cout << "[DEFAULT CONSTRUCTOR] CHARACTER default constructor is called" << std::endl;
	for(int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(std::string const & name): _name(name)
{
	std::cout << "[DEFAULT CONSTRUCTOR] CHARACTER constructor with argument NAME is called" << std::endl;
	for(int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}


Character::Character( const Character & src )
{
	std::cout << "[COPY CONSTRUCTOR] CHARACTER copy constructor is called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	//delete[] _inventory;  // Est-ce que cette option pourrait marcher d'une facon quelconque 
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	std::cout << "[DESTRUCTOR] CHARACTER destructor is called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Character &				Character::operator=( Character const & rhs)
// {
// 	(void)rhs;
// 	// Est-ce que cela ne va pas pas efface les AMateria de la src?
// 	// Il faudrait imprimer les AMAteria de la src une fois la copie termine pour voir si elle reste. 
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if(rhs._inventory[i]->getType() == "ice")
// 		{
// 			std::cout << "I am here" << std::endl;
// 			std::cout << "The AMateria is Ice" << std::endl;
// 			delete this->_inventory[i];  // I think this might cause problem.
// 			this->_inventory[i] = new Ice();
// 		}
// 		else if(rhs._inventory[i]->getType() == "cure")
// 		{
// 			std::cout << "The AMateria is Cure" << std::endl;
// 			delete this->_inventory[i];  // Maybe I have to erase the rhs._inventory[0] instead. 
// 			this->_inventory[i] = new Cure();
// 		}
// 	}
// 	return *this;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	int index = 0;
	
	while (index < 4 && _inventory[index] != nullptr)
		index++;
	if (index >= 4)
		delete m; // J'efface le AMateria passe en parametre, car
	else
		_inventory[index] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "The index provided does not exist in inventory!" << std::endl;
	else
	{
		_inventory[idx] = nullptr;
		std::cout << "AMateria at index " << idx << " has been removed from inventory." << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx] != nullptr)
		_inventory[idx]->use(target);
}

void	Character::printInventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != nullptr)
			std::cout << "Inventory[" << i << "] is a: " << _inventory[i]->getType() << std::endl;
		else
			std::cout << "Inventory[" << i << "] is a NULLPTR!" << std::endl;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */