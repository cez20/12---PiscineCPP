/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:26:11 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/13 15:26:16 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal(): type("NONE"){
	std::cout << "[DEFAULT CONSTRUCTOR] AAnimal default constructor has been called!" << std::endl;
}

AAnimal::AAnimal( const AAnimal & src ){

	std::cout << "[COPY CONSTRUCTOR] AAnimal Copy constructor has been called!" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal(){
	std::cout << "[DESTRUCTOR] AAnimal destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal & AAnimal::operator=( AAnimal const & rhs )
{
	std::cout << "[OPERATOR OVERLOAD] AAnimal Equal operator overload has been called!" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string AAnimal::getType() const{

	return (this->type);
}

void	AAnimal::makeSound() const
{
	std::cout << "[MAKE SOUND] AAnimal DOES NOT do any sound because no AAnimal is precised" << std::endl;
}

/* ************************************************************************** */