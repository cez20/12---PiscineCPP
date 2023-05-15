/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:10 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/15 17:49:29 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(): _name("Default"), _hitpoints(5), _energyPoints(5), _attackDamage(0){
	std::cout << "Default constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "Claptrap " << this->_name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src){

	std::cout << "Copy Constructor has been called" << std::endl;
	*this = src;
}

/*
** ------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() {
	
	std::cout << "Destructor is called" << std::endl;
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
	
	std::cout 	<< "[ATTACK] ClapTrap " << this->_name << " attacks "  << target 
				<< " causing his enemy to lose " << _attackDamage << " points of damage!\n" 
				<< "His energy points are reduced by 1!" << std::endl;
				
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){

	if (amount > this->_hitpoints)
		amount = this->_hitpoints;
		
	std::cout << "[TAKE DAMAGE] ClapTrap " << this->_name << " takes a hit of " << amount << " points of damage.\n" 
			  <<  "His hitpoints are reduced by " << amount << " points" << std::endl;
			  
	this->_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){

	if (amount > this->_energyPoints)
		amount = this->_energyPoints;
		
	std::cout << "[BE REPAIRED] ClapTrap " << getName() << " is being repaired."
			  << " His hitpoints goes up by " << amount << "\n"
			  << "His energy points is reduced by 1!" << std::endl;
	
	this->_hitpoints += amount;
	this->_energyPoints--;
}

void	ClapTrap::getInfo(){

	std::cout << YEL"ClapTrap name is " << getName() << std::endl;
	std::cout << getName() << " has " << getHitpoints() << " hitpoints." << std::endl;
	std::cout << getName() << " has " << getEnergyPoints() << " energy points." RESET << std::endl;
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
