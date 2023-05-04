/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:23:08 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/04 12:17:41 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void): _name(""){
	std::cout << "Constructor has been called" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << "Destructor has been called" << std::endl;
}

void Zombie::setName(std::string name){
	
	_name = name;
}

std::string Zombie::getName(){
	
	return (_name);
}

void Zombie::announce(){

	std::cout << "Zombie's name is: " << getName() << std::endl;
}
