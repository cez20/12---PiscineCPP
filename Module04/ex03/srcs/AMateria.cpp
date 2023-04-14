#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria() : _type("AMateria")
{
	std::cout << "[DEFAULT CONSTRUCTOR] AMateria defaults constructor is called" << std::endl;
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

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */