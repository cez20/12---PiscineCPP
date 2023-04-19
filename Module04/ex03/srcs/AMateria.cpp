/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:32:06 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/18 23:03:47 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : _type("AMateria")
{
	std::cout << "[DEFAULT CONSTRUCTOR] AMateria default constructor is called" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "CONSTRUCTOR NAME] AMateria constructor with name is called" << std::endl;
}

AMateria::AMateria( const AMateria & src )
{
	std::cout << "[COPY CONSTRUCTOR] AMateria copy constructor has been called!" << std::endl;
	*this = src; // Call the operator overload function. 
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	std::cout << "[DESTRUCTOR] AMateria destructor is called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &	AMateria::operator=( AMateria const & rhs )
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

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::setType(std::string const & type)
{
	this->_type = type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria is an abstract class. Function use() cannot be used to attack " << target.getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */