#include "SequenceProcessor.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

SequenceProcessor::SequenceProcessor()
{
}

SequenceProcessor::SequenceProcessor( const SequenceProcessor & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

SequenceProcessor::~SequenceProcessor()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

SequenceProcessor &				SequenceProcessor::operator=( SequenceProcessor const & rhs )
{
	if ( this != &rhs )
	{
		this->_unsortedSequence = rhs._unsortedSequence;
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/


void SequenceProcessor::processUnsortedSequence(int argCount, char **argList){
	
	int i = 1;

	while (i < argCount){
		std::string arg = argList[i];
		if(!isValidNumberFormat(arg) || !isBelowIntMax(arg))
			throw std::invalid_argument("Invalid argument. Either not a number, a negative number or higher than INT_MAX");
		else{
			_unsortedSequence.push_back(stringToDouble(arg));
		}
		i++;
	}
}

std::list<double>	SequenceProcessor::getUnsortedSequence() const {

	return _unsortedSequence;
}


void	SequenceProcessor::printUnsortedSequence(){

	std::list<double>::iterator it;

	std::cout << "Before Sorting: ";
	for(it = _unsortedSequence.begin(); it != _unsortedSequence.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

double  SequenceProcessor::stringToDouble(const std::string& s){
    char *end;
    
    double num = std::strtod(s.c_str(), &end);
    if (*end != '\0')
        throw std::invalid_argument("Invalid number format");
    else
        return num; 
}

bool SequenceProcessor::isValidNumberFormat (const std::string& arg){  
    if (arg.find_first_not_of("0123456789") != std::string::npos) {
        return false;
    }
    return true;;
}

bool SequenceProcessor::isBelowIntMax(const std::string& arg){
    double num = stringToDouble(arg);
    if (num > INT_MAX)
        return false;
    return true;
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */