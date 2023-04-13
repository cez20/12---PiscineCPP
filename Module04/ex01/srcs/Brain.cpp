/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:26:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/13 15:26:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "[DEFAULT CONSTRUCTOR] Brain default constructor has been called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "NOTHING";
}

Brain::Brain( const Brain & src )
{
	std::cout << "[COPY CONSTRUCTOR] Brain copy constructor has been called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "[DESTRUCTOR] Brain destructor has been called" << std::endl; 
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string& Brain::getIdeas(int index)
{
	return (_ideas[index]);
}

void Brain::setIdeas(std::string& idea, int index)
{
    _ideas[index] = idea;
}

/* ************************************************************************** */