/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:56:27 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/07 13:51:38 by cemenjiv         ###   ########.fr       */
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
	std::cout << "Called ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap constructor has been called and creates a robot derived "
			  << "from ClapTrap Cesar" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	std::cout << "ScavTrap copy constructor has been called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
// {
// 	std::cout << "Equal assignement operator called" << std::endl;
	
// 	// if (this != &rhs)
// 	// 	this->_name = rhs.getName();
// 	// 	this->_hitpoints = rhs.getHitpoints();
// 	// 	this->_energyPoints = rhs.getEnergyPoints();
// 	// 	this->_attackDamage = rhs.getDamage();
		
// 	return (*this);
// }

// std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScavTrap::guardGate(){

	std::cout << "ScravTrap " << getName() << " is now in mode GateKeeper!" << std::endl;
}

void		ScavTrap::attack(const std::string & target){

	std::cout << "ScavTrap " << getName() << " attacks " << target << " with HIS OWN attack type" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */