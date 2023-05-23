/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:27:04 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/23 16:02:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): AAnimal()
{
	std::cout << "[DEFAULT CONSTRUCTOR] Cat default constructor has been called!" << std::endl;
	type = "Cat";
	this->_ptrBrain = new Brain();
	
}

Cat::Cat( const Cat & src ): AAnimal()
{
	std::cout << "[COPY CONSTRUCTOR] Cat copy constructor has been called!" << std::endl;
	this->_ptrBrain = new Brain();
	*this = src; // Call the operator overload function. 
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "[DESTRUCTOR] Cat destructor has been called" << std::endl;
	delete this->_ptrBrain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
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

void	Cat::makeSound() const
{
	std::cout << "[MAKE SOUND] The Cat says MEOW MEOW!" << std::endl;
}

Brain*			Cat::getBrain()
{
	return (this->_ptrBrain);	
}


/* ************************************************************************** */