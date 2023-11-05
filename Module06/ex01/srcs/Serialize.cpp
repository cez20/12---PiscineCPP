#include "Serialize.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serialize::Serialize()
{
	std::cout << "[DEFAULT CONSTRUCTOR] has been called" << std::endl;
}

Serialize::Serialize( const Serialize & src )
{
	std::cout << "[COPY CONSTRUCTOR] has been called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serialize::~Serialize()
{
	std::cout << "[DESTRUCTOR] has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serialize &				Serialize::operator=( Serialize const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t	Serialize::serialize(Data	*ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}


/* ************************************************************************** */