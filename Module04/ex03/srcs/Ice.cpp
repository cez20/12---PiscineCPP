/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:32:46 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/18 22:32:47 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice(): AMateria()
{
	this->setType("ice");
	std::cout << "[DEFAULT CONSTRUCTOR] ICE default constructor is called" << std::endl;
}

Ice::Ice(std::string & type): AMateria(type)
{
	std::cout << "[CONSTRUCTOR] ICE constructor with name is called" << std::endl;
}

Ice::Ice( const Ice & src ): AMateria()
{
	std::cout << "[COPY CONSTRUCTOR] ICE copy constructor is called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice()
{
	std::cout << "[DESTRUCTOR] ICE destructor is called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &				Ice::operator=( Ice const & rhs)
{
	if (this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria* Ice::clone() const
{
	std::cout << "[CLONE] Create an ICE clone, by creating a new instance of Ice" << std::endl;
	return new Ice();
}

void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */