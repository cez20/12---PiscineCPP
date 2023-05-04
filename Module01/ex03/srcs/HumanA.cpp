/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:09:48 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/04 12:54:41 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const& name, Weapon& weapon): _nameA(name), _weaponA(weapon){
	std::cout << "[HUMAN A CONSTRUCTOR WI/ ARGS] Constructor has been called" << std::endl;
}

std::string HumanA::getNameA(){
	return (this->_nameA);
}

void		HumanA::attack(){

	std::cout << getNameA() << " attacks with their " << _weaponA.getType() << std::endl;
}