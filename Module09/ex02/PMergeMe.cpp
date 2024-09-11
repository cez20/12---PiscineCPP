#include "PMergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PMergeMe::PMergeMe()
{
}

PMergeMe::PMergeMe( const PMergeMe & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PMergeMe::~PMergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PMergeMe &				PMergeMe::operator=( PMergeMe const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PMergeMe const & i )
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