/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:41:16 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/05 21:49:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _nbr(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src){
	
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl; // Why do we say copy 

	if (this != &rhs)
		this->_nbr = rhs.getRawBits();

	return *this;	
}

int	Fixed::getRawBits(void) const{
	
	std::cout << "getRawBits function called" << std::endl; // Why do we say copy 
	return (this->_nbr); // Verify if it is right variable that I return
}

void	Fixed::setRawBits(int const raw){
	
	this->_nbr = raw;
}
