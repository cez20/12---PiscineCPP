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
	// if ( this != &rhs )
	// {
	// 	this->_value = rhs.getValue();
	// }
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Serialize const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


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


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */