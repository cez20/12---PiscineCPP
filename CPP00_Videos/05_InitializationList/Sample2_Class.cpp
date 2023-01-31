/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample2_Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 07:27:35 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 08:52:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample2_Class.hpp"

Sample2::Sample2(char p1, int p2, float p3): a1(p1), a2(p2), a3(p3) {   //Important ici de reecrire le constructeur avec ses parametres 

	std::cout << "Constructor called" << std::endl;
	std::cout << "Valeur de a1: " << this->a1 << std::endl;
	std::cout << "Valeur de a2: " << this->a2 << std::endl;
	std::cout << "Valeur de a3: " << this->a3 << std::endl;

	return;
}

Sample2::~Sample2(void) {

	std::cout << "Destructor called" << std::endl;
	return;
}

