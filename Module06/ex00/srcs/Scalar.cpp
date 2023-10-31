#include "Scalar.hpp"
#include <iomanip>
#include <sstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Scalar::Scalar()
{

}

Scalar::Scalar(std::string entry): _char(0), _int(0), _float(0.0f), _double(0.0), _type(isError) {
	std::cout << "[CONSTRUCTOR w args] has been called" << std::endl;

	detectType(entry);
	convertToAllTypes(entry);
	printChar();
	printInt();
	printFloat(entry);
	printDouble(entry);
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

	int len = entry.length();
	int nbrOfDots = findNbrOfDots(entry);
	
	if (nbrOfDots > 1)
		this->_type = isError;
	else if (len == 1 && !std::isdigit(entry[0]))
		this->_type = isChar;
	else if (nbrOfDots == 1 || isPseudoLiteralFloat(entry) || isPseudoLiteralDouble(entry))
	{
		if (isPseudoLiteralFloat(entry))
			this->_type = isFloat;
		else if(isPseudoLiteralDouble(entry))
			this->_type = isDouble;
		else if (entry[len - 1] == 'f')
			this->_type = isFloat;
		else
			this->_type = isDouble;
	}
	else
		this->_type = isInteger;
}

void Scalar::convertToAllTypes(std::string & entry)
{
	char *end = NULL;

	if (this->_type == isChar)
	{
		this->_char = entry[0];
		if (*end == '\0'){
			this->_int = static_cast<int>(this->_char);
			this->_float = static_cast<float>(this->_char);
			this->_double = static_cast<double>(this->_char);
		}
	}
	else if (this->_type == isInteger)
	{
		this->_int = static_cast<int>(strtol(entry.c_str(), &end, 10));
		if (*end == '\0'){
			this->_char = static_cast<char>(this->_int);
			this->_float = static_cast<float>(this->_int);
			this->_double = static_cast<double>(this->_int);
		}
	}
	else if (this->_type == isFloat)
	{
		this->_float = std::strtof(entry.c_str(), &end);
		if (*end == '\0' || *end == 'f'){
			this->_char = static_cast<char>(this->_float);
			this->_int = static_cast<int>(this->_float);
			this->_double = static_cast<double>(this->_float);
		}
	}

	else if (this->_type == isDouble)
	{
		this->_double = std::strtod(entry.c_str(), &end);
		if (*end == '\0'){
			this->_char = static_cast<char>(this->_double);
			this->_int = static_cast<int>(this->_double);
			this->_float = static_cast<float>(this->_double);
		}
	}

	std::cout << "Type: " << this->_type << std::endl;
	std::cout << "Char: " << this->_char << std::endl;
	std::cout << "Int: " << this->_int << std::endl;
	std::cout << "Float: " << this->_float << std::endl;
	std::cout << "Double: " << this->_double << std::endl;
}

void	Scalar::printChar()
{
	if (this->_type == isError)
		std::cout << "char: " << "impossible" << std::endl;

	else if (this->_int < 0 || this->_int > 127)
		std::cout << "char: " << "impossible" << std::endl;

	else if (this->_float != this->_float || this->_float == std::numeric_limits<double>::infinity() ||
		this->_float == -std::numeric_limits<double>::infinity())
		std::cout << "char: " << "impossible" << std::endl;

	else if (!std::isprint(static_cast<int>(this->_char)))
		std::cout << "char: " << "Non displayable" << std::endl;

	else{
		std::cout << "char: '" << this->_char << "'" << std::endl;
	}
}

void	Scalar::printInt()
{
	if (this->_type == isError)
		std::cout << "int: " << "impossible" << std::endl;

	else if (this->_float != this->_float || this->_float == std::numeric_limits<double>::infinity() ||
		this->_float == -std::numeric_limits<double>::infinity())
		std::cout << "int: " << "impossible" << std::endl;

	else{
		std::cout << "int: " << this->_int << std::endl;
	}
}

void	Scalar::printFloat(std::string & entry)
{
	if (this->_type == isError)
		std::cout << "float: " << "impossible" << std::endl;

	else if (entry == "+inff")
		std::cout << "float: +inff" << std::endl;
	
	else{
		std::stringstream ss;
		ss << "float: " << std::fixed << std::setprecision(1) << this->_float << "f";
		std::cout << ss.str() << std::endl;
	}
}

void	Scalar::printDouble(std::string & entry)
{
	if (this->_type == isError)
		std::cout << "double: impossible" << std::endl;

	else if (entry == "+inff")
		std::cout << "double: +inf" << std::endl;
	
	else {
		std::stringstream ss;
		ss << "double: " << std::fixed << std::setprecision(1) << this->_float;
		std::cout << ss.str() << std::endl;
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