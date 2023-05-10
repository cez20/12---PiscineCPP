/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:56:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/10 10:45:51 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define YEL "\e[0;33m"
# define REDB "\e[41m"

#include <iostream>
#include <cmath>
#include "Fixed.hpp"


int main() 
{
	/*
	** ------------------------------- TESTS IN PDF --------------------------------
	*/

	// for b:	each constructor is called separately: constructor with float, constructor with int
	//			Multiplicator operator overload is called, which multiplies Floatnbr * int
	//			Copy constructor operator is called
	//			Assignement operator is called
	//			2 instance that were initially used to create instance b are destroyed 
	
	//Fixed a;
	//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	
	// std::cout << b << std::endl;
	
	// std::cout << Fixed::max( a, b ) << std::endl;


		/*
	** ------------------------------- TESTING ARITHMETIC OPERATI --------------------------------
	*/

	// Fixed const a( Fixed( 5.05f ) + Fixed( 2 ) );
	// Fixed const b( Fixed( 5.05f ) - Fixed( 2 ) );
	// Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );
	// Fixed const d( Fixed( 5.05f ) / Fixed( 2 ) );

	// std::cout << roundf(5.05f * 256) << " + " << (2 << 8) << " = " << a.getRawBits() << std::endl;
	// std::cout << roundf(5.05f * 256) << " - " << (2 << 8) << " = " << b.getRawBits() << std::endl;
	// std::cout << roundf(5.05f * 256) << " * " << (2 << 8) << " = " << c.getRawBits() << std::endl;
	// std::cout << roundf(5.05f * 256) << " / " << (2 << 8) << " = " << d.getRawBits() << std::endl;

	/*
	** ------------------------------- TESTING ARITHMETIC OPERATION --------------------------------
	*/

	Fixed const a( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const b( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const d( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << RED "The number given below are the fixed point representation of "
			  << "the numbers given as parameters above :" RESET << std::endl;
	std::cout << roundf(5.05f * 256) << " + " << (2 << 8) << " = " << a.getRawBits() << std::endl;
	std::cout << roundf(5.05f * 256) << " - " << (2 << 8) << " = " << b.getRawBits() << std::endl;
	std::cout << roundf(5.05f * 256) << " * " << (2 << 8) << " = " << c.getRawBits() << std::endl;
	std::cout << roundf(5.05f * 256) << " / " << (2 << 8) << " = " << d.getRawBits() << std::endl;


	return 0;
}