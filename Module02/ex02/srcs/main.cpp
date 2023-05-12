/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:56:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/12 15:41:47 by cemenjiv         ###   ########.fr       */
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
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                              MANDATORY TESTS                                      *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "\n";
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "\n";

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                   COMPARISON OPERATORS(<, >, <=, >=, ==, !=)                      *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	Fixed	a1(100);
	Fixed	b1(5);
	Fixed	c1(100);
	Fixed	d1(5);
	
	std::cout << "\n";
	std::cout << "Is a1 (100) >   b1 (5)   =   " << (a1 > b1) << std::endl;
	std::cout << "Is a1 (100) <   b1 (5)   =   " << (a1 < b1) << std::endl;
	std::cout << "Is a1 (100) >=  c1 (100) =   " << (a1 >= c1) << std::endl;
	std::cout << "Is b1 (5)   <=  d1 (5)   =   " << (b1 <= d1) << std::endl;
	std::cout << "Is a1 (100) ==  c1 (100) =   " << (a1 == c1) << std::endl;
	std::cout << "Is b1 (5)   !=  d1 (5)   =   " << (b1 != d1) << std::endl;
	std::cout << "\n";

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                   ARITHMETIC OPERATORS(+, -, *, /)                                *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	Fixed a2(10.05f);
	Fixed b2(2);

	std::cout << "\n";
	std::cout << "The result of a2 (10.05f) + b2 (2) is: "  << a2 + b2 << std::endl;
	std::cout << "The result of a2 (10.05f) - b2 (2) is: "  << a2 - b2 << std::endl;
	std::cout << "The result of a2 (10.05f) * b2 (2) is: "  << a2 * b2 << std::endl;
	std::cout << "The result of a2 (10.05f) / b2 (2) is: "   << a2 / b2 << std::endl;
	std::cout << "\n";

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*              INCREMENTATION/DECREMENTATION OPERATORS(++a, a++, --a, a--)          *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	Fixed a3;
	Fixed b3;
	
	std::cout << "\n";
	std::cout << "Initial value:             " 	<< a3 	<< std::endl;
	std::cout << "After PRE-INCREMENTATION:  " 	<< ++a3 	<< std::endl;
	std::cout << "Reprinting value:          " 	<< a3 	<< std::endl;
	std::cout << "After POST-INCREMENTATION: " 	<< a3++ 	<< std::endl;
	std::cout << "Reprinting value:          " 	<< a3 	<< std::endl;
	
	std::cout << "\n";
	std::cout << "Initial value:             " 	<< b3 << std::endl;
	std::cout << "After PRE-DECREMENTATION:  " 	<< --b3 << std::endl;
	std::cout << "Reprinting value:          " 	<< b3 << std::endl;
	std::cout << "After POST-DECREMENTATION: " 	<< b3-- << std::endl;
	std::cout << "Reprinting value:          " 	<< b3 << std::endl;
	std::cout << "\n";

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                         MIN/MAX OVERLOAD - MEMBER FUNCTIONS                       *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	Fixed	a4(100);
	Fixed	b4(5);
	Fixed	c4(100);
	Fixed	d4(5);
	
	std::cout << "\n";
	std::cout << "Which number is smaller between a (100)  and b (5) ? " << "    Answer: " << Fixed::min(a4, b4) << std::endl;
	std::cout << "Which number is smaller between c (100)  and d (5) ? " << "    Answer: " << Fixed::min(c4, d4) << std::endl;
	std::cout << "Which number is bigger between  a (100)  and b (5) ? " << "    Answer: " << Fixed::max(a4, b4) << std::endl;
	std::cout << "Which number is bigger between  c (100)  and d (5) ? " << "    Answer: " << Fixed::max(c4, d4) << std::endl;
	std::cout << "\n";

	return 0;
}