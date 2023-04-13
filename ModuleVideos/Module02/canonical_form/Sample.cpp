/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:51:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/03 16:03:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.hpp"

Sample::Sample(void) : _foo(0) {

	std::cout << "Default constructor called" << std::endl;
	return;	
}

Sample::Sample(int const n): _foo(n){

	std::cout << "Parametric Constructor called" << std::endl;
	return ; 
}

Sample::Sample (Sample const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Sample:: ~Sample(void){

	std::cout << "Destructor called" << std::endl;
	return;
}

int Sample::getFoo(void) const{
	return this->_foo;
}

Sample & Sample::operator=(Sample const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &rhs)
		this->_foo = rhs.getFoo();

	return *this;	
}

std::ostream &	operator<<(std::ostream & o, Sample const & i){

	o << "The value of _foo is : " << i.getFoo();

	return (o);
}