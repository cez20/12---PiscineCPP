/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:08:38 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/05 13:22:39 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {

	Fixed a; // "Default constructor called". Creates object a of type Fixed
	Fixed b( a ); // "Copy constructor called". Creates object b of type Fixed. It copies the values of object a
	Fixed c; //
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

/* Different steps in main program

1- Default constructor is called 
2- Copy constructor is called 
	a)"Inside copy constructor", we use = operator that has been recreated (operation )
	b)"Copy assignement operator called". We dereference pointer *this (value of this which referer to whole instance) is equaled to src
	c)"getRawBits is called inside the  Copy assignment operator fuction
	d) Default constructor is called.
	e) c = b : Copy assignement operator is called, followed by getRaws bits
	f) getRawBits is officially called again for a
	g) Value is printed out
	h) getRawBits is officially called again for b
	i) Value is printed out
	j) getRawBits is officially called again for c
	k) Value is printed out
	l) Destructor i called for each function. 
*/

// Notes:
// Computer is able to detect, when an operator is used as usual (ex: int = 56) and when it is not ()