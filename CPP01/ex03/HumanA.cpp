/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:09:48 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/30 12:18:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const& name, Weapon& weapon): _nameA(name), _weaponA(weapon){
	std::cout << "Constructor HumanA has been called" << std::endl;
}

std::string HumanA::getNameA(){
	return (this->_nameA);
}

void		HumanA::attack(){

	std::cout << getNameA() << " attacks with their " << _weaponA.getType() << std::endl;
}