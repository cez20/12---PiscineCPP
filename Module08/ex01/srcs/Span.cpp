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
	// std::cout << "Vector capacity is: " << _listOfNumbers.capacity() << std::endl;
	// std::cout << "maxRangeofNumbers is :" << _maxRangeOfNumbers << std::endl;
}


Span::Span( const Span & src )
{
	std::cout << "[COPY CONSTRUCTOR] has been called" << std::endl;
	*this = src;
}


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

Span &				Span::operator=( Span const & rhs )
{
	std::cout << "[ASSIGNMENT OPERATOR OVERLOAD] has been called" << std::endl;
	if ( this != &rhs )
	{
		this->_maxRangeOfNumbers = rhs._maxRangeOfNumbers;
		this->_listOfNumbers = rhs._listOfNumbers;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void	Span::addNumber(int nbr){

	if (_listOfNumbers.size() >= _maxRangeOfNumbers){
		throw MaxCapacityReachedException();
	}
	
	_listOfNumbers.push_back(nbr);
}


void	Span::addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_listOfNumbers.size() + std::distance(begin, end) > _maxRangeOfNumbers) {
		throw MaxCapacityReachedException();
	}
	_listOfNumbers.insert(_listOfNumbers.end(), begin, end);
}

unsigned int Span::shortestSpan() const {

    if (_listOfNumbers.size() < 2){
        throw ShortestSpanException();
    }

    std::vector<int> sortedNumbers = _listOfNumbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();

    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
        minSpan = std::min(minSpan, span);
    }

    return minSpan;
}

long long Span::longestSpan() const {

    if (_listOfNumbers.size() < 2){
        throw LongestSpanException();
    }

    std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> minmax = 
        std::minmax_element(_listOfNumbers.begin(), _listOfNumbers.end());

    long long min = *minmax.first;
    long long max = *minmax.second;

    return max - min;
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