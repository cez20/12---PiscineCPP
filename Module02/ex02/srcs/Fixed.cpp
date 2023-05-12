/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:14:59 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/12 14:51:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

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

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b) 
{
  	if (a < b)
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed &a, Fixed &b) 
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b) 
{
  	if (a > b)
		return (a);
	return (b);
}


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(): _nbr(0) { }


Fixed::Fixed(int const & nbr): _nbr(nbr << this->_fractionalBits){ }


Fixed::Fixed(float const & nbr): _nbr(float_to_fixed(nbr, _fractionalBits)){ }


Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return ;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {}


/*
** ------------------------ COMPARISON OPERATION OVERLOAD ----------------------
*/

bool				Fixed::operator>( Fixed const & rhs ) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool				Fixed::operator<(Fixed const & rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool				Fixed::operator>=( Fixed const & rhs ) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}
 
bool				Fixed::operator<=( Fixed const & rhs ) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool				Fixed::operator==( Fixed const & rhs ) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool				Fixed::operator!=( Fixed const & rhs ) const
{
	return (this->getRawBits() != rhs.getRawBits());
}




/*
** ------------------------ ARITHMETIC OPERATION OVERLOAD ----------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	if (this != &rhs)
		this->_nbr = rhs.getRawBits();
		
	return *this;	
}

Fixed 	  			Fixed::operator+ (Fixed const & rhs) const
{
	Fixed	newInstance;
	
	int newNbr = this->getRawBits() + rhs.getRawBits();
	newInstance.setRawBits(newNbr);

	return (newInstance);
}

Fixed 	  			Fixed::operator- (Fixed const & rhs) const
{
	Fixed	newInstance;
	
	int newNbr = this->getRawBits() - rhs.getRawBits();
	newInstance.setRawBits(newNbr);

	return (newInstance);
}

Fixed 	  			Fixed::operator* (Fixed const & rhs) const
{	
	Fixed	newInstance;
	
	int newNbr = this->getRawBits() * rhs.getRawBits();
	newInstance.setRawBits(newNbr >> 8);

	return (newInstance);	
}

Fixed 	  			Fixed::operator/ (Fixed const & rhs) const
{
	Fixed	newInstance;
	
	int newNbr = this->getRawBits() / rhs.getRawBits();
	newInstance.setRawBits(newNbr << 8);

	return (newInstance);
}

/*
** ------------------------ INCREMENTATION/DECREMENTATION OPERATOR OVERLOAD  ----------------------
*/

Fixed  	&	Fixed::operator++ ()
{
	this->_nbr++;
	return (*this);
}

Fixed  		Fixed::operator++ (int) 
{
	Fixed tmp(*this); 

	this->_nbr++;
	return (tmp);
}

Fixed &	  			Fixed::operator-- ()
{
	this->_nbr--;
	return (*this);
}

Fixed			Fixed::operator-- (int) 
{
	Fixed tmp(*this); 

	this->_nbr--;
	return (tmp);
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