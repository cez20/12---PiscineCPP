#include "FormsList.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FormsList::FormsList()
{
}

FormsList::FormsList( const FormsList & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FormsList::~FormsList()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FormsList &				FormsList::operator=( FormsList const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, FormsList const & i )
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