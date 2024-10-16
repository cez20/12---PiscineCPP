#include "PMergeMe.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
//TODO: Je vais devoir initialiser mes variables initiales avec du contenu 
PMergeMe::PMergeMe(): _unpairedElement(-1)
{
}

PMergeMe::PMergeMe( const PMergeMe & src )
{
	*this = src; 
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PMergeMe::~PMergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

//TODO: We need to modify this according to variables created 
PMergeMe &				PMergeMe::operator=( PMergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->_myVectorPairs = rhs._myVectorPairs;
		this->_myDequePairs = rhs._myDequePairs;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


void PMergeMe::processArguments(int argCount, char **argList){
	
	int i = 1;

	while (i < argCount){
		std::string arg = argList[i];
		if(!isValidNumberFormat(arg) || !isBelowIntMax(arg))
			throw std::invalid_argument("Invalid argument. Either not a number, a negative number or higher than INT_MAX");
		else{
			_start = std::clock(); // TODO: Should I start clock here or just before starting the SortPairs which is first step in merge-insertion sort
			_initialSequence.push_back(stringToDouble(arg));
		}
		i++;
	}
}

void	PMergeMe::initializeContainers() {

	if (_initialSequence.size() < 2)
		throw std::invalid_argument("ERROR! Arguments size less than 2");
	if (_initialSequence.size() % 2 == 1){
		_unpairedElement = _initialSequence.back();
		_initialSequence.pop_back();
	}
	createPairs(_myVectorPairs);
	printContainer(_myVectorPairs);
	createPairs(_myDequePairs);
	printContainer(_myDequePairs);
}

template <typename T>
void	PMergeMe::createPairs(T & container){

	std::list<double>::iterator it = _initialSequence.begin();

	while (it != _initialSequence.end()){
		int first = *it;
		++it;
		if (it != _initialSequence.end()){
			int second = *it;
			++it;
			container.push_back(std::make_pair(first, second));
		}
	}
}

void PMergeMe::mergeInsertionSort() {

	// Merge-insertion sort for std::vector
	sortPairs(_myVectorPairs);
	std::cout << "After Pair Sorting: " << std::endl;
	printContainer(_myVectorPairs);
	if (_myVectorPairs.size() > 1) {
		mergeSortRecursive(_myVectorPairs, 0, _myVectorPairs.size() - 1);
		std::cout << "After MergeSorting: " << std::endl;
		printContainer(_myVectorPairs);
		createMainChain();
		createPend();
		generateJacobsthalSequence();
		insertionSort();
	}

	// MERGE INSERTION SORT FOR STD::DEQUE
	// sortPairs(_myDeque);
}

void	PMergeMe::insertionSort(){

	for (size_t i = 0; i < _pend.size(); ++i){
		int index = binarySearch(_mainChain, _mainChain.size(), _pend[i]);
		_mainChain.insert(_mainChain.begin() + index, _pend[i]);
		// for (size_t i = 0; i < _mainChain.size(); ++i)
		// 	std::cout << _mainChain[i] << " ";
		// std::cout << std::endl;
	}
	std::cout << "Printing final main chain: ";
	for (size_t i = 0; i < _mainChain.size(); ++i)
		std::cout << _mainChain[i] << " ";
	std::cout << std::endl;
}



//TODO: Creer cette meme fonction pour storer un dequePair

template<typename T>
void	PMergeMe::sortPairs(T & container) {

	for (size_t i = 0; i < container.size(); ++i){
		if(container[i].first < container[i].second)
			std::swap(container[i].first, container[i].second);
	}
}

template <typename T>
void	PMergeMe::mergeSortRecursive(T& container, size_t left, size_t right)
{
	if (left >= right)
		return;
	const size_t middle = left + (right - left) / 2;
	mergeSortRecursive(container, left, middle);
	mergeSortRecursive(container, middle + 1, right);
	mergeSort(container, left, middle, right);
}

template <typename T>
void 	PMergeMe::mergeSort(T& container, size_t left, size_t middle, size_t right)
{
	std::vector<std::pair<int, int> >::iterator start = container.begin() + left;
	std::vector<std::pair<int, int> >::iterator mid = container.begin() + (middle + 1);
	std::vector<std::pair<int, int> >::iterator end = container.begin() + (right + 1);


	std::vector<std::pair<int, int> > leftSubPairs(start, mid);
	std::vector<std::pair<int, int> > rightSubPairs(mid, end);

	size_t i = 0;
	size_t j = 0;
	size_t k = left;

	while (i < leftSubPairs.size() && j < rightSubPairs.size())
	{
		if (leftSubPairs[i].first <= rightSubPairs[j].first)
			container[k++] = leftSubPairs[i++];
		else
			container[k++] = rightSubPairs[j++];
	}
	while (i < leftSubPairs.size())
		container[k++] = leftSubPairs[i++];
	while (j < rightSubPairs.size())
		container[k++] = rightSubPairs[j++];
}

void	PMergeMe::createMainChain(){

	for(size_t i = 0; i < _myVectorPairs.size(); ++i){
		_mainChain.push_back(_myVectorPairs[i].first);
	}

	std::cout << "Printing main chain: ";
	for (size_t i = 0; i < _mainChain.size(); ++i)
		std::cout << _mainChain[i] << " ";
	std::cout << std::endl;
}

void	PMergeMe::createPend(){
	for(size_t i = 0; i < _myVectorPairs.size(); ++i){
		_pend.push_back(_myVectorPairs[i].second);
	}

	std::cout << "Printing pend: ";
	for (size_t i = 0; i < _pend.size(); ++i)
		std::cout << _pend[i] << " ";
	std::cout << std::endl;
}

// int		PMergeMe::Jacobsthal(int n){

// 	if (n == 0)
//         return 0;
//     // base case
//     if (n == 1)
//         return 1;
//     // recursive step.
//     return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
// }

int PMergeMe::Jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0; // Jacobsthal(0)
    int prev1 = 1; // Jacobsthal(1)
    int current = 0;

    for (int i = 2; i <= n; ++i) {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}


void	PMergeMe::generateJacobsthalSequence(){

	for(size_t i = 0; i < _pend.size(); ++i){
		_jacobsthalSequence.push_back(Jacobsthal(i));
	}

	// for(size_t i = 0; i < _jacobsthalSequence.size(); ++i){
	// 	std::cout << _jacobsthalSequence[i] << std::endl;
	// }
}

size_t	PMergeMe::binarySearch(std::vector<int> mainChain, size_t size, int number){

	size_t start = 0;
	size_t end = size - 1;

	while (start <= end){

		size_t middle = (start + end) / 2;
		if (mainChain[middle] == number) // Returns the indexes 
			return middle;
		else if (number < mainChain[middle]){
			if (middle == 0) 
				break;
			end = middle - 1;
		}
		else
			start = middle + 1;
	}
	return start;
}


void 	PMergeMe::printInitialIntSequence(){

	std::list<double>::iterator it;

	std::cout << "Before Sorting: ";
	for(it = _initialSequence.begin(); it != _initialSequence.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	PMergeMe::printContainer(T & container){

	for(size_t i = 0; i < container.size(); ++i){
		std::cout << "Pair[" << i << "] ";
		std::cout << container[i].first << " ";
		std::cout << container[i].second << std::endl;
	}
}

double  stringToDouble(const std::string& s){
    char *end;
    
    double num = std::strtod(s.c_str(), &end);
    if (*end != '\0')
        throw std::invalid_argument("Invalid number format");
    else
        return num; 
}

bool isValidNumberFormat (const std::string& arg){  
    if (arg.find_first_not_of("0123456789") != std::string::npos) {
        return false;
    }
    return true;;
}

bool isBelowIntMax(const std::string& arg){
    double num = stringToDouble(arg);
    if (num > INT_MAX)
        return false;
    return true;
}

/* ************************************************************************** */