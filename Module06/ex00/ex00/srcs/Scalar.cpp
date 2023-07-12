#include "Scalar.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Scalar::Scalar()
{
}

Scalar::Scalar(std::string const & input): _input(input), _c(0)
{
	analyzeInput();
}

// Scalar::Scalar( const Scalar & src )
// {

// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Scalar::~Scalar()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Scalar &				Scalar::operator=( Scalar const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, Scalar const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Scalar::analyzeInput()
{
	//char* end;

    _error = false;
	// If input received is of length 1 and is not a digit and really a character
    if (_input.length() == 1 && std::isdigit(_input[0]) == 0)
	{
        std::cout << "I am here" << std::endl;
		_c = _input[0];
	}




}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */