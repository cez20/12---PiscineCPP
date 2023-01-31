/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:55:32 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 12:02:25 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_Class.hpp"

Sample::Sample(int v): _foo(v) {

	std::cout << "Constructor called " << std::endl;
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