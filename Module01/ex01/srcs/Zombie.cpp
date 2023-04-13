/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:23:08 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/27 14:57:27 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void): _name(""){
	std::cout << "Constructor has been called and initialized all Zombies names to NULL " << std::endl;
}

Zombie::~Zombie(void){
	std::cout << "Destructor has been called" << std::endl;
}

void Zombie::setName(std::string name){
	
	_name = name;
	std::cout << "Name has been set with help of setter" << std::endl;
}

std::string Zombie::getName(){
	
	return (_name);
}

void Zombie::announce(){

	std::cout << "The name of the zombie is: " << getName() << std::endl;
}
