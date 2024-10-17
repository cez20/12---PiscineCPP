#ifndef VECTORSORTER_HPP
# define VECTORSORTER_HPP

# include <iostream>
# include <string>
# include <vector>

class VectorSorter
{

	public:

		VectorSorter();
		VectorSorter( VectorSorter const & src );
		~VectorSorter();

		VectorSorter &		operator=( VectorSorter const & rhs );

	private:

		std::clock_t 						_start;
		std::clock_t 						_end;
		std::vector<std::pair<int,int> > 	_myVectorPairs;
		std::vector<int>					_mainChain;
		std::vector<int>					_pend;
		std::vector<size_t>					_jacobsthalSequence;

};


#endif /* ************************************************* VECTORSORTER_H */