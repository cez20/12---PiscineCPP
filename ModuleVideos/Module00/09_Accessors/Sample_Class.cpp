/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:55:32 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 11:59:01 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_Class.hpp"

Sample::Sample(void){

	std::cout << "Constructor called " << std::endl;
	
	std::cout << "This->getFoo:" << this->getFoo() << std::endl; // Prints result of foo with help of function getFoo()
	return;
}

Sample::~Sample(void){

	std::cout << "Destructor called " << std::endl;
	return;
}

int	Sample::getFoo(void)	const{

	return this->_foo; // Fonction to get value of _foo 

}

int Sample::compare (Sample * other) const {

	if (this->_foo < other->getFoo())
		return -1;
	else if (this->_foo > other->getFoo())
		return 1;

	return 0;
}
