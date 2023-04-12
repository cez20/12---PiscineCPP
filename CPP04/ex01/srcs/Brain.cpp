#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "[DEFAULT CONSTRUCTOR] Brain default constructor has been called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
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

// Brain &				Brain::operator=( Brain const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */