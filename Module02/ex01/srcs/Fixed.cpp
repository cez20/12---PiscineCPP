/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:41:16 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/08 11:21:39 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

int const Fixed::_bits = 8;

static int	float_to_fixed(float const f, int const frac_nBits)
{
	float	t;
	int		res;

	t = f * (1 << frac_nBits);
	std::cout << t << std::endl;
	res = (int)roundf(t);
	std::cout << res << std::endl;
	if (f < 0)
	{
		res = -res;
		res = ~res;
		res += 1;
	}
	return (res);
}

Fixed::Fixed(): _nbr(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src){
	
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const & nbr): _nbr(nbr << this->_bits){
	std::cout << "Constructor with INT called" << std::endl;
}

Fixed::Fixed(float const & nbr): _nbr(float_to_fixed(nbr, _bits)){

	std::cout << "Constructor with Float called" << std::endl;
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

int	Fixed::toInt(void) const{

	return (this->_nbr >> this->_bits); // right bit shift to get integer without any fraction portion 
}

int	Fixed::getRawBits(void) const{
	
	std::cout << "getRawBits function called" << std::endl;
	return (this->_nbr);
}

void	Fixed::setRawBits(int const raw){
	
	this->_nbr = raw;
}

std::ostream &	operator<<(std::ostream & output, Fixed const & input){

	//if ()
		output << input.toInt() << std::endl;
	//else
		//output << input.
	return (output);
}
