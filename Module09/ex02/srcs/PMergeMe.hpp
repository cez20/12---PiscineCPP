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


class PMergeMe
{
	public:
		PMergeMe();
		PMergeMe( PMergeMe const & src );
		~PMergeMe();

		PMergeMe &		operator=( PMergeMe const & rhs );

		void			processArguments(int argCount, char **argList);
		// void			initializeContainers();
		
		// void			mergeInsertionSort();
		// template<typename T>
		// void			createPairs(T& container);
		// template<typename T>
		// void			sortPairs(T& container);
		// template<typename T>
		// void			mergeSortRecursive(T& container, size_t left, size_t right);
		// template <typename T>
		// void 			mergeSort(T& container, size_t left, size_t middle, size_t right);
		
		// void			createMainChain();
		// void			createPend();
		// size_t			Jacobsthal(int n);
		// void			generateJacobsthalSequence();
		// size_t			binarySearch(std::vector<int> mainChain, size_t size, int number);
		// void			insertionSort();


		void			printInitialSequence();
		void			printSortedSequence();
		void			printClock();

	private:
		std::list<double>					_initialSequence;
		int									_unpairedElement;
		
		std::clock_t 						_clockStartVector;
		std::clock_t 						_clockEndVector;
		std::vector<std::pair<int,int> > 	_myVectorPairs;
		std::vector<int>					_mainChainVector;
		std::vector<int>					_pendVector;
		std::vector<size_t>					_jacobsthalSequenceVector;

		std::clock_t 						_clockStartDeque;
		std::clock_t						_clockEndDeque;
		std::deque<std::pair<int, int> >	_myDequePairs;
		
};

double  stringToDouble(const std::string& s);
bool 	isValidNumberFormat (const std::string& arg);
bool 	isBelowIntMax(const std::string& arg);



#endif /* ******************************************************** PMERGEME_H */