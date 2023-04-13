/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:47:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 10:07:29 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_Class.hpp"

Sample::Sample(void){

	std::cout << "Constructor called " << std::endl;
	
	this->publicFoo = 0;
	std::cout << "publicFoo value: " << this->publicFoo << std::endl;
	
	this->_privateFoo = 0;
	std::cout << "_privateFoo value: " << this->_privateFoo << std::endl;

	this->publicBar();
	this->_privateBar();

	return;
}

Sample::~Sample(void){

	std::cout << "Destructor called " << std::endl;
	return;	
}

void Sample:: publicBar(void) const{

	std::cout << "Member function publicBar called" << std::endl;
	return;
}

void Sample:: _privateBar(void) const{

	std::cout << "Member function privateBar called" << std::endl;
	return;
}
