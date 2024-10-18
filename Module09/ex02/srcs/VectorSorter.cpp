#include "VectorSorter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template<typename T>
VectorSorter<T>::VectorSorter()
{
}

template<typename T>
VectorSorter<T>::VectorSorter( const VectorSorter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template<typename T>
VectorSorter<T>::~VectorSorter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template<typename T>
VectorSorter<T> &				VectorSorter<T>::operator=( VectorSorter const & rhs )
{
	(void)rhs;
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */