#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>

class Span
{

	public:

		Span(unsigned int N);
		Span( Span const & src );
		~Span();

		Span &			operator=( Span const & rhs );
		void 			addNumber(int nbr);
		void			addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan() const;
		long long		longestSpan() const;

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
		Span();
		unsigned int				_maxRangeOfNumbers;
		std::vector<int> 			_listOfNumbers;


};

#endif /* ************************************************************ SPAN_H */