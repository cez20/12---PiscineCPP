#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <deque>
# include <algorithm>
# include <array>


class PMergeMe
{
	public:
		PMergeMe();
		PMergeMe( PMergeMe const & src );
		~PMergeMe();

		PMergeMe &		operator=( PMergeMe const & rhs );

		void			processArguments(int argCount, char **argList);
		void			initializeContainers();
		
		void			mergeInsertionSort();
		template<typename T>
		void			createPairs(T& container);
		template<typename T>
		void			sortPairs(T& container);
		template<typename T>
		void			mergeSortRecursive(T& container, size_t left, size_t right);
		template <typename T>
		void 			mergeSort(T& container, size_t left, size_t middle, size_t right);
		
		void			createMainChain();
		void			createPend();
		size_t			Jacobsthal(int n);
		void			generateJacobsthalSequence();
		size_t			binarySearch(std::vector<int> mainChain, size_t size, int number);
		void			insertionSort();


		void			printInitialSequence();
		void			printSortedSequence();
		template <typename T>
		void			printContainer(T & container);

		
	private:
		std::clock_t 						_start;
		std::vector<std::pair<int,int> > 	_myVectorPairs;
		std::vector<int>					_mainChain;
		std::vector<int>					_pend;
		std::vector<size_t>					_jacobsthalSequence;
		std::deque<std::pair<int, int> >	_myDequePairs;
		std::list<double>					_initialSequence;
		int									_unpairedElement;
		// size_t					_myVectorSortTime;
		// size_t					_myDequeSortTime;
};

double  stringToDouble(const std::string& s);
bool 	isValidNumberFormat (const std::string& arg);
bool 	isBelowIntMax(const std::string& arg);



#endif /* ******************************************************** PMERGEME_H */