/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:14:59 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/10 08:15:01 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

static int	float_to_fixed(float const initialFloatNbr, int const fractionalBits)
{
	float	shiftedFloatNbr;
	int		fixedInteger;

	shiftedFloatNbr = initialFloatNbr * (1 << fractionalBits);
	//std::cout << shiftedFloatNbr << std::endl;
	fixedInteger = (int)roundf(shiftedFloatNbr);
	//std::cout << fixedInteger << std::endl;
	return (fixedInteger);
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(): _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const & nbr): _nbr(nbr << this->_fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const & nbr): _nbr(float_to_fixed(nbr, _fractionalBits))
{
	std::cout << "Float constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->_nbr = rhs.getRawBits();

	return *this;	
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int	Fixed::toInt(void) const
{
	return (this->_nbr >> this->_fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return (float)this->_nbr / (float)(1 << this->_fractionalBits);
}

int	Fixed::getRawBits(void) const
{	
	return (this->_nbr);
}

void	Fixed::setRawBits(int const raw)
{	
	this->_nbr = raw;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::ostream &	operator << (std::ostream & output, Fixed const & fixedNbr)
{
	output << fixedNbr.toFloat();
	return (output);
}

/* ************************************************************************** */