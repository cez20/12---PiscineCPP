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

		void			mergeInsertionSort();
		// void			createPairs(T& container);
		// void			sortPairs(T& container);
		// void			mergeSortRecursive(T& container, size_t left, size_t right);
		// void 		mergeSort(T& container, size_t left, size_t middle, size_t right);
		
		// void			createMainChain();
		// void			createPend();
		// size_t		Jacobsthal(int n);
		// void			generateJacobsthalSequence();
		// size_t		binarySearch(std::vector<int> mainChain, size_t size, int number);
		// void			insertionSort();

		void			printSortedSequence(T & container);
		void			printClock();

	private:

		int									_unpairedElement;
		std::clock_t 						_start;
		std::clock_t 						_end;
		std::deque<std::pair<int,int> > 	_myDequePairs;
		std::deque<int>						_mainChain;
		std::deque<int>						_pend;
		std::deque<size_t>					_jacobsthalSequence;

};

std::ostream &			operator<<( std::ostream & o, DequeSorter const & i );

#endif /* ***************************************************** DEQUESORTER_H */