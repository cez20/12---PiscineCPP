/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:10 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/07 13:44:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(): _name("Henri"), _hitpoints(5), _energyPoints(5), _attackDamage(0){
	std::cout << "Default constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitpoints(100), _energyPoints(50), _attackDamage(20) {

	std::cout << "Claptrap " << this->_name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src){

	std::cout << "ClapTrap copy constructor has been called" << std::endl;
	*this = src;
}

/*
** ------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() {
	
	std::cout << "ClapTrap " << getName() << " destructor is called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs){
	
	std::cout << "Copy assignement operator called" << std::endl;
	
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

void ClapTrap::attack(const std::string & target){
	
	std::cout << "ClapTrap " << this->_name << " attacks "  << target << " causing his enemy to lose " 
			  << _attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){

	if (amount > this->_hitpoints)
		amount = this->_hitpoints;
	std::cout << "ClapTrap " << this->_name << " takes a hit of " << amount << " points of damage. " 
			  <<  "His hitpoints is reduced by " << amount << " points" << std::endl;
	this->_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){

	if (amount > this->_energyPoints)
		amount = this->_energyPoints;
	std::cout << "ClapTrap " << getName() << " is being repaired. This takes 1 energy point!" << std::endl;
	this->_hitpoints += amount;
	this->_energyPoints--;

}

void	ClapTrap::getInfo(){

	std::cout << "ClapTrap name is " << getName() 
			  << ". It has " << getHitpoints() << " hitpoints."
			  << " It has " << getEnergyPoints() << " energy points."
			  << " Its attack generates " << getDamage() << " of damage!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName() const{
	return (this->_name);
}

int ClapTrap::getHitpoints() const{
	return (this->_hitpoints);
}

int ClapTrap::getEnergyPoints() const{
	return (this->_energyPoints);
}

int ClapTrap::getDamage() const{
	return (this->_attackDamage);
}
