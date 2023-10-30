#include "Scalar.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Scalar::Scalar()
{

}

Scalar::Scalar(std::string entry): _char(0), _int(0), _float(0.0f), _double(0.0), _type(isError) {
	std::cout << "[CONSTRUCTOR w args] has been called" << std::endl;
	// std::cout << "The current entry is: " << entry << std::endl;
	// std::cout << "The current char is: " << _char << std::endl;
	// std::cout << "The current int is: " << _int << std::endl;
	// std::cout << "The current float is: " << _float << std::endl;
	// std::cout << "The current double is: " << _double << std::endl;

	detectType(entry);
}

// Scalar::Scalar( const Scalar & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Scalar::~Scalar()
{
	std::cout << "[DESTRUCTOR] has been called!" << std::endl;
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

void	Scalar::detectType(std::string & entry){

	char *end;
	int len = entry.length();
	int nbrOfDots = findNbrOfDots(entry);
	
	if (nbrOfDots > 1)
		this->_type = isError;
	else if (len == 1 && !std::isdigit(entry[0]))
	{
		this->_type = isChar;
		this->_char = entry[0];
	}
	else if (nbrOfDots == 1 || isPseudoLiteralFloat(entry) || isPseudoLiteralDouble(entry))
	{
		if (isPseudoLiteralFloat(entry))
		{
			this->_type = isFloat;
			this->_float = std::strtof(entry.c_str(), &end);
		}
		else if(isPseudoLiteralDouble(entry))
		{
			this->_type = isDouble;
			this->_double = std::strtod(entry.c_str(), &end);
		}
		else if (entry[len - 1] == 'f')
		{
			this->_type = isFloat;
			this->_float = std::strtof(entry.c_str(), &end);
		}
		else
		{
			this->_type = isDouble;
			this->_double = std::strtod(entry.c_str(), &end);
		}
		if (*end != '\0')
			this->_type = isError;
	}
	else
	{
		this->_type = isInteger;
		this->_int = static_cast<int>(strtol(entry.c_str(), &end, 10));
		if (*end != '\0')
			this->_type = isError;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

bool isPseudoLiteralFloat(std::string & entry)
{
	if (entry == "inff" || entry == "+inff" || entry == "-inff" || entry == "nanf")
		return (true);
	return (false);
}

bool isPseudoLiteralDouble(std::string & entry)
{
	if(entry == "inf"|| entry == "+inf" || entry == "-inf" || entry == "nan")
		return (true);
	return (false);
}

int findNbrOfDots(std::string & entry)
{
	int count = 0;
	for (size_t i = 0; i < entry.length(); i++)
	{
		if(entry[i] == '.')
			count++;
	}
	return (count);
}