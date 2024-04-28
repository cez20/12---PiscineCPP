#include "MutantStack.hpp"
#include <stack>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template < typename T >
MutantStack<T>::MutantStack() {}

template < typename T >
MutantStack<T>::MutantStack( const MutantStack<T> & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template < typename T >
MutantStack<T>::~MutantStack() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template < typename T >
MutantStack<T> &				MutantStack<T>::operator=( MutantStack<T> const & rhs )
{
	if (this != &rhs)
	{
		std::stack<T>::operator=(rhs);
	}
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
typename MutantStack<T>::iterator MutantStack<T>::end()
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