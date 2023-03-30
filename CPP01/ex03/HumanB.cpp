/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:44:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/30 11:54:08 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string const& name): _nameB(name), _weaponB(nullptr){
	
	std::cout << "Constructor HumanB has been called" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon){
	this->_weaponB = &weapon;
}

std::string HumanB::getNameB(){
	return (this->_nameB);
}

void		HumanB::attack(){
	if (_weaponB == nullptr)
		std::cout << "HumanB cannot attacks because it has no weapon!" << std::endl;
	else
		std::cout << getNameB() << " attacks with their " << _weaponB->getType() << std::endl;
}
