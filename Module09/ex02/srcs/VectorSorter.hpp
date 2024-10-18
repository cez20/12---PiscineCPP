#ifndef VECTORSORTER_HPP
# define VECTORSORTER_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>

class VectorSorter
{
	public:

		VectorSorter();
		VectorSorter( VectorSorter const & src );
		~VectorSorter();

		VectorSorter &		operator=( VectorSorter const & rhs );

		void			mergeInsertionSort(std::list<double> unsortedSequence);
		void			createPairs(std::list<double> unsortedSequence);
		void			sortPairs();
		void			mergeSortRecursive(std::vector<std::pair<int,int> >& pairs, size_t left, size_t right);
		void 			mergeSort(std::vector<std::pair<int,int> >& container, size_t left, size_t middle, size_t right);
		
		void			createMainChain();
		void			createPend();
		size_t			Jacobsthal(int n);
		void			generateJacobsthalSequence();
		size_t			binarySearch(std::vector<int> mainChain, size_t size, int number);
		void			insertionSort();

		void			printSortedSequence();
		void			printClock();

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