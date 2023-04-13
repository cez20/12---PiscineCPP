/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample1_Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 07:27:35 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 08:05:34 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample1_Class.hpp"

Sample1::Sample1(char p1, int p2, float p3) {   //Important ici de reecrire le constructeur avec ses parametres 

	std::cout << "Constructor called" << std::endl;

	this->a1 = p1;
	std::cout << "La valeur de a1 est: " << this->a1 << std::endl;

	this->a2 = p2;
	std::cout << "La valeur de a2 est: " << this->a2 << std::endl;

	this->a3 = p3;
	std::cout << "La valeur de a3 est: " << this->a3 << std::endl;
	
	return;
}

Sample1::~Sample1(void){

	std::cout << "Destructor called" << std::endl;
	return;
}
