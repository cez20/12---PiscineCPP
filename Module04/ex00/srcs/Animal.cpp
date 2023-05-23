/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:24:26 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/23 15:04:56 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(): type("Default animal"){
	std::cout << "[DEFAULT CONSTRUCTOR] Animal default constructor has been called!" << std::endl;
}

Animal::Animal( const Animal & src ){

	std::cout << "[COPY CONSTRUCTOR] Animal Copy constructor has been called!" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal(){
	std::cout << "[DESTRUCTOR] Animal destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal & Animal::operator=( Animal const & rhs )
{
	std::cout << "[OPERATOR OVERLOAD] Animal Equal operator overload has been called!" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Animal::getType() const{

	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "[MAKE SOUND] Animal DOES NOT do any sound because no animal is precised" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */