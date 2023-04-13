/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integerClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:01:46 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/03 15:25:57 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "integerClass.hpp"

Integer::Integer( int const n): _n(n){
	std::cout << "Constructor called with value " << n << std::endl;
	return ;
}

Integer::~Integer(void){

	std::cout << "Destructor called with value " << this->_n << std::endl;
}

int Integer::getValue(void) const {

	return (this->_n);
}

Integer & Integer::operator=( Integer const & rhs)
{
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rhs.getValue() << std::endl;

	this->_n = rhs.getValue();

	return *this; // this est toujours un pointeur vers la classe actuelle. Retourne *this veut donc dire 
				  // qu'on retourne la classe elle-meme  
}

Integer		Integer::operator+( Integer const & rhs) const
{
	std::cout << "Addition operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	return Integer(this->_n + rhs.getValue());
}

std::ostream & operator<<( std::ostream & o, Integer const & rhs)
{

	o << rhs.getValue();
	return (o);
}