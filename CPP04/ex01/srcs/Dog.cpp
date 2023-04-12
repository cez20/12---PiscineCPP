#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << "[DEFAULT CONSTRUCTOR] Dog default constructor has been called!" << std::endl;
	type = "Dog";
	this->_dogPtrToBrain = new Brain();
}

Dog::Dog( const Dog & src )
{
	std::cout << "[COPY CONSTRUCTOR] Dog copy constructor has been called!" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->_dogPtrToBrain;
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
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound() const
{
	std::cout << "[MAKE SOUND] The Dog says WOOF WOOF!" << std::endl;
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */