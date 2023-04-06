/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:10 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/05 20:53:42 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name): _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0) {

	std::cout << "Constructor is called" << std::endl;
}

ClapTrap::~ClapTrap() {
	
	std::cout << "Destructor is called" << std::endl;
}

void ClapTrap::attack(const std::string & target){
	
	if (this->_hitpoints == 0 || this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << "cannot attack due to lack of hitpoints or energy";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks "  << target << " causing his enemy to lose " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){

	if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << "cannot be attacked a he is dead" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " takes a hit of " << amount << " energy points " << std::endl;
		this->_energyPoints -= amount;
	}	
}

void ClapTrap::beRepaired(unsigned int amount){

	std::cout << "ClapTrap " << getName() << " is being repaired. ";
	this->_energyPoints--;
	std::cout << "He gained " << amount << " hitpoints!" << std::endl;
	this->_hitpoints += amount;
}

void	ClapTrap::getInfo(){

	std::cout << "ClapTrap name is " << getName() << " and he has " << getHitpoints() << " hitpoints and " << getEnergyPoints() << " energy points!" << std::endl;
}

std::string ClapTrap::getName(){
	return (this->_name);
}

int ClapTrap::getHitpoints(){
	return (this->_hitpoints);
}

int ClapTrap::getEnergyPoints(){
	return (this->_energyPoints);
}





