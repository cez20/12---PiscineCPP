/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:32:17 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/20 19:26:48 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(): _name()
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
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	std::cout << "[DESTRUCTOR] CHARACTER destructor is called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs)
{
	this->_name = rhs.getName();
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = nullptr;
	}
	return *this;
}


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
	else if (_inventory[idx] == nullptr)
		return ;
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