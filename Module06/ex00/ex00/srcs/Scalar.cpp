#include "Scalar.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Scalar::Scalar()
{
}

Scalar::Scalar(std::string const & input): _input(input), _char(0)
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

bool	Scalar::isInteger(std::string input)
{
	std::istringstream iss(input);
    int value;

	if ((iss >> value) && input.find(".") == std::string::npos){
		std::cout << "Parsed integer: " << input << std::endl;
		this->_int = value;
		return (1);
    } else {
        std::cout << "Failed to parse integer." << std::endl;
		return (0);
    }
}

void	Scalar::analyzeInput()
{
	//char* end;

    _error = false;
    if (_input.length() == 1 && std::isdigit(_input[0]) == 0)
	{
		type = isChar;
		this->_char = _input[0];
	}
	else if (isInteger(this->_input))
	{
		type = isInt;

		// I have to put a sentence here this->_int  = at an integer value 
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */