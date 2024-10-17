#include "DequeSorter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DequeSorter::DequeSorter()
{
}

DequeSorter::DequeSorter( const DequeSorter & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DequeSorter::~DequeSorter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DequeSorter &				DequeSorter::operator=( DequeSorter const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, DequeSorter const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */