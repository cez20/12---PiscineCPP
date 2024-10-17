#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <deque>
# include <algorithm>
# include <array>
# include <iomanip>


template <typename T>
class PMergeMe 
{
	public:
		PMergeMe();
		PMergeMe( PMergeMe const & src );
		~PMergeMe();

		PMergeMe &		operator=( PMergeMe const & rhs );

		// void			mergeInsertionSort();
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
		
};


#endif /* ******************************************************** PMERGEME_H */