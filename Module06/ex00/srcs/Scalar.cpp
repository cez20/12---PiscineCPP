#include "Scalar.hpp"
#include <iomanip>
#include <sstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Scalar::Scalar()
{
	std::cout << "[DEFAULT CONSTRUCTOR] has been called." << std::endl;
}

Scalar::Scalar(std::string entry): _char(0), _int(0), _float(0.0f), _double(0.0), _type(IMPOSSIBLE) {

	if (entry.empty()){
		std::cout << "IMPOSSIBLE: Cannot convert because string is empty!" << std::endl;
		return;
	}
	
	detectType(entry);
	convertToAllTypes(entry);
	printChar();
	printInt();
	printFloat(entry);
	printDouble(entry);
}

Scalar::Scalar( const Scalar &src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Scalar::~Scalar()
{

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Scalar &				Scalar::operator=( Scalar const &rhs )
{
	if ( this != &rhs )
	{
		this->_char = rhs._char;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
		this->_type = rhs._type;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Scalar::detectType(std::string &entry){

	int len = entry.length();
	int nbrOfDots = findNbrOfDots(entry);
	
	if (nbrOfDots > 1)
		this->_type = IMPOSSIBLE;
	else if (len == 1 &&!std::isdigit(entry[0]))
		this->_type = CHAR;
	else if ((nbrOfDots == 1 && entry[len - 1] == 'f') || isPseudoLiteralFloat(entry))
	{
		this->_type = FLOAT;
		if (isPseudoLiteralFloat(entry))
			this->_type = PSEUDOFLOAT;
	}
	else if (nbrOfDots == 1 || isPseudoLiteralDouble(entry))
		this->_type = DOUBLE;
	else
		this->_type = INTEGER;
}

void Scalar::convertToAllTypes(std::string &entry)
{
	if (this->_type == CHAR)
		convertToChar(entry);
	else if (this->_type == INTEGER) 
		convertToInteger(entry);
	else if (this->_type == FLOAT || this->_type == PSEUDOFLOAT) 
		convertToFloat(entry);
	else if (this->_type == DOUBLE)
		convertToDouble(entry);
}

void Scalar::convertToChar(std::string &entry)
{
	this->_char = entry[0];
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
}

void Scalar::convertToInteger(std::string &entry)
{
	char *end = NULL;

	long long result = strtoll(entry.c_str(), &end, 10);
	if (result >= -2147483648 && result <= 2147483647)
	{
		this->_int = static_cast<int>(result);
		this->_char = static_cast<char>(this->_int);
		this->_float = static_cast<float>(this->_int);
		this->_double = static_cast<double>(this->_int);
	}
	else
		this->_type = IMPOSSIBLE;
}

void Scalar::convertToFloat(std::string &entry)
{
	char *end = NULL;
	
	entry.erase(entry.end() - 1);
	this->_float = std::strtof(entry.c_str(), &end);
	if (*end == '\0' || this->_type == PSEUDOFLOAT)
	{
		this->_char = static_cast<char>(this->_float);
		this->_int = static_cast<int>(this->_float);
		this->_double = static_cast<double>(this->_float);
	}
	else
		this->_type = IMPOSSIBLE;
}

void Scalar::convertToDouble(std::string &entry)
{
	char *end = NULL;

	this->_double = std::strtod(entry.c_str(), &end);
	if (*end == '\0')
	{
		this->_char = static_cast<char>(this->_double);
		this->_int = static_cast<int>(this->_double);
		this->_float = static_cast<float>(this->_double);
	}
	else
		this->_type = IMPOSSIBLE;
}

void	Scalar::printChar()
{
	if (this->_type == IMPOSSIBLE || isNan(this->_double) || isInfinite(this->_double)) 
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(this->_char)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << this->_char << "'" << std::endl;
}

void	Scalar::printInt()
{
	if (this->_type == IMPOSSIBLE || isNan(this->_double) || isInfinite(this->_double))
		std::cout << "int: impossible" << std::endl;
	else if (this->_float > std::numeric_limits<int>::max() || this->_float < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else if (this->_double > std::numeric_limits<int>::max() || this->_double < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->_int << std::endl;
}

void	Scalar::printFloat(std::string &entry)
{
	if (this->_type == IMPOSSIBLE)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << createString(entry, "float") << std::endl;
}

void	Scalar::printDouble(std::string &entry)
{
	if (this->_type == IMPOSSIBLE)
		std::cout << "double: impossible" << std::endl;
	else 
		std::cout << createString(entry, "double") << std::endl;
}


int Scalar::findNbrOfDots(std::string &entry)
{
	int count = 0;
	for (size_t i = 0; i < entry.length(); i++)
	{
		if(entry[i] == '.')
			count++;
	}
	return (count);
}

bool Scalar::isPseudoLiteralFloat(std::string &entry)
{
	if (entry == "inff" || entry == "+inff" || entry == "-inff" || entry == "nanf")
		return (true);
	return (false);
}

bool Scalar::isPseudoLiteralDouble(std::string &entry)
{
	if(entry == "inf"|| entry == "+inf" || entry == "-inf" || entry == "nan")
		return (true);
	return (false);
}

bool Scalar::isNan(double nbr)
{
	// NaN of "Not a number" never equals itself. 
	if (nbr != nbr)
		return (true);
	return (false);
}

bool Scalar::isInfinite(double nbr)
{
	double positiveInfinity = std::numeric_limits<double>::infinity();
	double negativeInfinity = -std::numeric_limits<double>::infinity();

	if (nbr == positiveInfinity || nbr == negativeInfinity)
		return (true);
	return (false);
}

std::string Scalar::createString(std::string & entry, std::string const &type)
{
	std::stringstream output_stream;

	if (entry == "+inf" && type == "float")
		output_stream << "float: +" << std::fixed << std::setprecision(1) << this->_float << "f";
	else if (type == "float")
		output_stream << "float: " << std::fixed << std::setprecision(1) << this->_float << "f";
	else if (entry == "+inf")
		output_stream << "double: +" << std::fixed << std::setprecision(1) << this->_double;
	else if (type == "double")
		output_stream << "double: " << std::fixed << std::setprecision(1) << this->_double;
	
	return output_stream.str();
}