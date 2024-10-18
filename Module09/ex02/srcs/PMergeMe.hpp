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
		void			mergeInsertionSort();

		template<typename T>
		void			createPairs(T& container);

		template<typename T>
		void			sortPairs(T& container);

		template<typename T>
		void			mergeSortRecursive(T& container, size_t left, size_t right);

		template <typename T>
		void 			mergeSort(T& container, size_t left, size_t middle, size_t right);
		
		template <typename T, typename U>
		void			createMainChain(T& container, U& mainChain);
		template <typename T, typename U>
		void			createPend(T& container, U& pend);
		
		template<typename U>
		void			insertionSort(U& mainChain, U& pend);

		size_t			Jacobsthal(int n);
		void			generateJacobsthalSequence(size_t size);
		
		template <typename U>
		int				binarySearch(U& mainChain, int number);

		void			AreNumbersSorted();
		void			printUnsortedSequence();
		template <typename T>
		void			printPairs(T& container);
		template <typename U>
		void			printMainChain(U& mainChain);
		template <typename U>
		void			printPend(U& pend);
		void			printJacobsthalSequence();
		void			printSortedSequence();
		void			printSortingTimes();

	private:
		std::list<double>					_unsortedSequence;
		std::vector<size_t>					_jacobsthalIndexes;
		int									_unpairedElement;
		
		std::clock_t 						_startVector;
		std::clock_t 						_endVector;
		std::vector<std::pair<int,int> > 	_myVectorPairs;
		std::vector<int>					_mainChainVector;
		std::vector<int>					_pendVector;

		std::clock_t 						_startDeque;
		std::clock_t						_endDeque;
		std::deque<std::pair<int, int> >	_myDequePairs;
		std::deque<int>						_mainChainDeque;
		std::deque<int>						_pendDeque;
};

double  stringToDouble(const std::string& s);
bool 	isValidNumberFormat (const std::string& arg);
bool 	isBelowIntMax(const std::string& arg);



#endif /* ******************************************************** PMERGEME_H */