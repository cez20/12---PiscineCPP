#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>

class Span
{

	public:

		Span(unsigned int N);
		// Span( Span const & src );
		~Span();

		// Span &		operator=( Span const & rhs );
		void 			addNumber(unsigned int nbr);
		void			addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

	class MaxCapacityReachedException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class ShortestSpanException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class LongestSpanException: public std::exception {
		public:
			virtual const char* what() const throw();
	};

	private:
		Span(); // cannot be used
		unsigned int				_maxRangeOfNumbers;  // Designed maximum range of numbers that class can contain
		std::vector<unsigned int> 	_listOfNumbers;


};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */