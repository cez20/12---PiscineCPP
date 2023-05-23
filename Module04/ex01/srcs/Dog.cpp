/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:27:11 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/23 16:05:37 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): Animal()
{
	std::cout << "[DEFAULT CONSTRUCTOR] Dog default constructor has been called!" << std::endl;
	type = "Dog";
	this->_ptrBrain = new Brain();
	
}

Dog::Dog( const Dog & src ): Animal()
{
	std::cout << "[COPY CONSTRUCTOR] Dog copy constructor has been called!" << std::endl;
	this->_ptrBrain = new Brain();
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "[DESTRUCTOR] Dog destructor has been called" << std::endl;
	delete this->_ptrBrain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "[OPERATOR OVERLOAD] Cat Equal operator overload has been called!" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		for (int i = 0; i < 100 ; i++)
			this->_ptrBrain->setIdea(rhs._ptrBrain->getIdea(i), i);
    }
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound() const
{
	std::cout << "[MAKE SOUND] The Dog says WOOF WOOF!" << std::endl;
}

Brain*			Dog::getBrain()
{
	return (this->_ptrBrain);	
}



/* ************************************************************************** */