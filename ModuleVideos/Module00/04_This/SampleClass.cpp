/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SampleClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:29:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 07:16:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SampleClass.hpp"

// Ce Fichier permet de definir comment les actions a realiser par le constructor et le destructor 

Sample::Sample(void) {
	
	std::cout << "Constructor called" << std::endl;
	this->foo = 42;
	std::cout << "This.foo est egal a: " << this->foo << std::endl;

	this->bar();
	return; // Prendre note qu'il n'y aucun type de retour dans les classes (aucune type de retourn avec Sample)
}

Sample::~Sample(void) {
	
	std::cout << "Destructor called" << std::endl;
	return; // L'utilisation de return n'est pas obligatoire car aucun retour, mais cela indique fin de notre code (plus clean)
}

void	Sample::bar(void) {

	std::cout << "Function member 'Bar' called" << std::endl;
	return;
}