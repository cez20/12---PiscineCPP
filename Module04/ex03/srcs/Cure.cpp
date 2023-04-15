#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure(): AMateria()
{
	this->setType("cure");
	std::cout << "[DEFAULT CONSTRUCTOR] Cure default constructor is called" << std::endl;
}

Cure::Cure(std::string &type): AMateria(type)
{
	std::cout << "[CONSTRUCTOR] CURE constructor with name is called" << std::endl;
}

Cure::Cure( const Cure & src )
{
	std::cout << "[COPY CONSTRUCTOR] CURE copy constructor is called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure()
{
	std::cout << "[DESTRUCTOR] CURE destructor is called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &				Cure::operator=( Cure const & rhs )
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

AMateria* Cure::clone() const
{
	std::cout << "I am in clone function inside CURE instance" << std::endl;
	return (0);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */