#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice(): AMateria()
{
	this->setType("ice");
	std::cout << "[DEFAULT CONSTRUCTOR] ICE default constructor is called" << std::endl;
}

Ice::Ice(std::string &name): AMateria(name)
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

Ice &				Ice::operator=( Ice const & rhs )
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
	std::cout << "I am in clone function inside ICE instance" << std::endl;
	return (0);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */