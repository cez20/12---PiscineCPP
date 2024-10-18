#ifndef VECTORSORTER_HPP
# define VECTORSORTER_HPP

# include <iostream>
# include <string>
# include <vector>
# include "PMergeMe.hpp"

template <typename T>
class VectorSorter: public PMergeMe<std::vector<T> >
{
	public:

		VectorSorter();
		VectorSorter( VectorSorter const & src );
		~VectorSorter();

		VectorSorter &		operator=( VectorSorter const & rhs );

	private:

		int									_unpairedElement;
		std::clock_t 						_start;
		std::clock_t 						_end;
		std::vector<std::pair<int,int> > 	_myVectorPairs;
		std::vector<int>					_mainChain;
		std::vector<int>					_pend;
		std::vector<size_t>					_jacobsthalSequence;

};


#endif /* ************************************************* VECTORSORTER_H */