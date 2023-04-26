#include "PresidentialPardonAForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonAForm::PresidentialPardonAForm()
{
}

PresidentialPardonAForm::PresidentialPardonAForm( const PresidentialPardonAForm & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonAForm::~PresidentialPardonAForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonAForm &				PresidentialPardonAForm::operator=( PresidentialPardonAForm const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonAForm const & i )
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