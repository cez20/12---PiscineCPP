/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:27:11 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/13 15:27:12 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): Animal()
{
	type = "Dog";
	this->_ptrBrain = new Brain();
	std::cout << "[DEFAULT CONSTRUCTOR] Dog default constructor has been called!" << std::endl;
}

Dog::Dog( const Dog & src ): Animal()
{
	this->_ptrBrain = new Brain();
	std::cout << "[COPY CONSTRUCTOR] Dog copy constructor has been called!" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->_ptrBrain;
	std::cout << "[DESTRUCTOR] Dog destructor has been called" << std::endl;
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
    }
	// std::string word = "ALLO";
	// this->_ptrBrain->setIdeas(word, 0);
	// std::cout << "The address of rhs brain is: " << rhs._ptrBrain->getIdeas(0) << std::endl;
	// std::cout << "The address of THIS OBJECT brain is: " << _ptrBrain->getIdeas(0) << std::endl;
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound() const
{
	std::cout << "[MAKE SOUND] The Dog says WOOF WOOF!" << std::endl;
}


/* ************************************************************************** */