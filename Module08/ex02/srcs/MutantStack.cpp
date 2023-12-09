#include "MutantStack.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MutantStack::MutantStack()
{
	std::cout << "[DEFAULT CONSTRUCTOR] has been called" << std::endl;
}

MutantStack::MutantStack( const MutantStack & src )
{
	std::cout << "[COPY CONSTRUCTOR] has been called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MutantStack::~MutantStack()
{
	std::cout << "[DESTRUCTOR] has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MutantStack &				MutantStack::operator=( MutantStack const & rhs )
{
	std::cout << "[ASSIGNMENT OPERATOR OVERLOAD] has been called" << std::endl;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


std::stack<T>::container_type::iterator		MutantStack::begin(){

	return std::stack<T>::c.begin();
}
		
std::stack<T>::container_type::iterator		MutantStack::end(){

	return std::stack<T>::c.end();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */