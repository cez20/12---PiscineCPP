/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:56:27 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/09 23:16:56 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "[DEFAULT CONSTRUCTOR] Called ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "[CONSTRUCTOR] ScavTrap constructor has been called and creates robot named " << getName() 
			  << " derived from ClapTrap" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	std::cout << "[COPY CONSTRUCTOR] ScavTrap copy constructor has been called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "[DESTRUCTOR] ScavTrap destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "[OPERATOR OVERLOAD] Equal assignement operator called" << std::endl;
	
	if (this != &rhs)
		this->_name = rhs.getName();
		this->_hitpoints = rhs.getHitpoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getDamage();
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScavTrap::guardGate(){

	std::cout << "[GUARDGATE METHOD] ScravTrap " << getName() << " is now in mode GateKeeper!" << std::endl;
}

void		ScavTrap::attack(const std::string & target){

	if (this->_energyPoints == 0)
	{
		std::cout << "Sorry we can't proceed with attack because we no longer have energy points" << std::endl;
		return ;
	}
	std::cout << "[ATTACK] ScavTrap " << getName() << " attacks " << target << " with HIS OWN attack type. " 
			  << " This takes 2 energy points away!" << std::endl;
	this->_energyPoints -= 2;
}

/* ************************************************************************** */