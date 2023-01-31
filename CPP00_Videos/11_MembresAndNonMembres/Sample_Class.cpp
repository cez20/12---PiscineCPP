/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:55:32 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 13:35:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_Class.hpp"

Sample::Sample(void) {

	std::cout << "Constructor called " << std::endl;
	Sample::_nbInst += 1;   // Lorsque le constructeur est appele on incremente la variable non-membre de 1 
	return;
}

Sample::~Sample(void){

	std::cout << "Destructor called " << std::endl;
	Sample::_nbInst -= 1; // Lorsque le destrcuteur est appele on diminue la variable non-membre de 1 
	return;
}

int Sample::getNbInst(void){

	return Sample::_nbInst;
}

int Sample::_nbInst = 0; // On declare la variable prive _nbInst a 0.