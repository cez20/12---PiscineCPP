#include "ShrubberyCreationAForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationAForm::ShrubberyCreationAForm()
{
}

ShrubberyCreationAForm::ShrubberyCreationAForm( const ShrubberyCreationAForm & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationAForm::~ShrubberyCreationAForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationAForm &				ShrubberyCreationAForm::operator=( ShrubberyCreationAForm const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationAForm const & i )
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