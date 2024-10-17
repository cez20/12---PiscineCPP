#ifndef DEQUESORTER_HPP
# define DEQUESORTER_HPP

# include <iostream>
# include <string>
# include <deque>

class DequeSorter
{

	public:

		DequeSorter();
		DequeSorter( DequeSorter const & src );
		~DequeSorter();

		DequeSorter &		operator=( DequeSorter const & rhs );

	private:

		std::clock_t 						_start;
		std::clock_t 						_end;
		std::deque<std::pair<int,int> > 	_mydequePairs;
		std::deque<int>						_mainChain;
		std::deque<int>						_pend;
		std::deque<size_t>					_jacobsthalSequence;

};

std::ostream &			operator<<( std::ostream & o, DequeSorter const & i );

#endif /* ***************************************************** DEQUESORTER_H */