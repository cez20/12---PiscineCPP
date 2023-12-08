#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
	std::cout << "[DEFAULT CONSTRUCTOR] has been called";
}

Span::Span(unsigned int N): _maxRangeOfNumbers(N)
{
	std::cout << "[CONSTRUCTOR W PARAMETERS] has been called" << std::endl;

	_listOfNumbers.reserve(N);
	std::cout << "Vector capacity is: " << _listOfNumbers.capacity() << std::endl;
	std::cout << "maxRangeofNumbers is :" << _maxRangeOfNumbers << std::endl;
}


// Span::Span( const Span & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
	std::cout << "[DESTRUCTOR] has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Span &				Span::operator=( Span const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/


void	Span::addNumber(unsigned int nbr){

	if (_listOfNumbers.size() >= _maxRangeOfNumbers){
		throw MaxCapacityReachedException();
	}
	
	_listOfNumbers.push_back(nbr);
}


void	Span::addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end; ++it) {
        addNumber(*it);
		std::cout << "Value of it is:" << *it << std::endl;
    }
}

unsigned int Span::shortestSpan() const {

	if (_listOfNumbers.size() < 2){
		throw ShortestSpanException();
	}
	
	std::vector <unsigned int>::const_iterator it;
	std::vector <unsigned int>::const_iterator ite = _listOfNumbers.end();
	unsigned int minSpan = std::numeric_limits<unsigned int>::max();

	for (it = _listOfNumbers.begin(); it != ite; ++it) {
		if (std::next(it) != ite)
		{
			int span = *(std::next(it)) - *it;
			minSpan = std::min(minSpan, static_cast<unsigned int>(std::abs(span)));
		}
    }
	return (minSpan);
}

unsigned int Span::longestSpan() const {

	if (_listOfNumbers.size() < 2){
		throw LongestSpanException();
	}

	std::vector <unsigned int>::const_iterator it;
	std::vector <unsigned int>::const_iterator ite = _listOfNumbers.end();
	unsigned int maxSpan = std::numeric_limits<unsigned int>::min();

	  for (it = _listOfNumbers.begin(); it != ite; ++it) {
        if (std::next(it) != ite)
		{
			int span = *(std::next(it)) - *it;
			maxSpan = std::max(maxSpan, static_cast<unsigned int>(std::abs(span)));
		}
    }

	return (maxSpan);
}

const char * Span::MaxCapacityReachedException:: what() const throw() {
	return "EXCEPTION: Maximum capacity of vector is reached";
}

const char * Span::ShortestSpanException:: what() const throw() {
	return "EXCEPTION: Shortest Span impossible because less than 2 numbers";
}

const char * Span::LongestSpanException:: what() const throw() {
	return "EXCEPTION: Longest Span impossible because less than 2 numbers";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */