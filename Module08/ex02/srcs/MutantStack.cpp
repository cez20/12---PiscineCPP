#include "MutantStack.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template < typename T >
MutantStack<T>::MutantStack()
{
	std::cout << "[DEFAULT CONSTRUCTOR] has been called" << std::endl;
}

template < typename T >
MutantStack<T>::MutantStack( const MutantStack<T> & src )
{
	std::cout << "[COPY CONSTRUCTOR] has been called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template < typename T >
MutantStack<T>::~MutantStack()
{
	std::cout << "[DESTRUCTOR] has been called" << std::endl;

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template < typename T >
MutantStack<T> &				MutantStack<T>::operator=( MutantStack<T> const & rhs )
{
	std::cout << "[ASSIGNMENT OPERATOR OVERLOAD] has been called" << std::endl;
	(void)rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

template class MutantStack<int>;
template class MutantStack<float>;
template class MutantStack<double>;


/* ************************************************************************** */