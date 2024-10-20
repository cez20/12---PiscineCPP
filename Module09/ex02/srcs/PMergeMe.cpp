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
			throw std::invalid_argument("ERROR!Invalid argument. Either not a number, a negative number or higher than INT_MAX");
		else{
			_unsortedSequence.push_back(stringToDouble(arg));
		}
		i++;
	}
	if (_unsortedSequence.size() < 2)
		throw std::invalid_argument("ERROR!No sorting necessary! Only one number");
}

void PMergeMe::mergeInsertionSort() {

	if (_unsortedSequence.size() % 2 == 1){
		_unpairedElement = _unsortedSequence.back();
		_unsortedSequence.pop_back();
	}

	generateJacobsthalSequence(_unsortedSequence.size()/ 2);
\
	// MERGE-INSERTION SORT FOR STD::VECTOR
	_startVector = std::clock();
	createPairs(_myVectorPairs);
	sortPairs(_myVectorPairs);
	mergeSortRecursive(_myVectorPairs, 0, _myVectorPairs.size() - 1);
	createMainChain(_myVectorPairs, _mainChainVector);
	createPend(_myVectorPairs, _pendVector);
	insertionSort(_mainChainVector, _pendVector);
	_endVector = std::clock();

	// MERGE INSERTION SORT FOR STD::DEQUE
	_startDeque = std::clock();
	createPairs(_myDequePairs);
	sortPairs(_myDequePairs);
	mergeSortRecursive(_myDequePairs, 0, _myDequePairs.size() - 1);
	createMainChain(_myDequePairs, _mainChainDeque);
	createPend(_myDequePairs, _pendDeque);
	insertionSort(_mainChainDeque, _pendDeque);
	_endDeque = std::clock();
}

template <typename T>
void	PMergeMe::createPairs(T& container){

	std::list<double>::iterator it = _unsortedSequence.begin();

	while (it != _unsortedSequence.end()){
		int first = *it;
		++it;
		if (it != _unsortedSequence.end()){
			int second = *it;
			++it;
			container.push_back(std::make_pair(first, second));
		}
	}
}

template<typename T>
void	PMergeMe::sortPairs(T& container) {

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
	typename T::iterator	start = container.begin() + left;
	typename T::iterator 	mid = container.begin() + (middle + 1);
	typename T::iterator 	end = container.begin() + (right + 1);

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

template <typename T, typename U>
void	PMergeMe::createMainChain(T& container, U& mainChain){

	for(size_t i = 0; i < container.size(); ++i){
		mainChain.push_back(container[i].first);
	}
}

template <typename T, typename U>
void			PMergeMe::createPend(T& container, U& pend){
	for(size_t i = 0; i < container.size(); ++i){
		pend.push_back(container[i].second);
	}
}

size_t	 PMergeMe::Jacobsthal(int n) {
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

void	PMergeMe::generateJacobsthalSequence(size_t pendSize){

	for(size_t i = 0; i < pendSize ; ++i){
		if (Jacobsthal(i) < pendSize)
			_jacobsthalIndexes.push_back(Jacobsthal(i));
	}
}

template <typename U>
int	PMergeMe::binarySearch(U& mainChain, int number){

	size_t start = 0;
	size_t end = mainChain.size() - 1;

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

template <typename U>
void	PMergeMe::insertionSort(U& mainChain, U& pend){

	// Put elements in pend[jacobsthal index] inside mainChain
	for (size_t i = 0; i < _jacobsthalIndexes.size(); ++i){
		if(_jacobsthalIndexes[i] < pend.size()){
			int index = binarySearch(mainChain, pend[_jacobsthalIndexes[i]]);
			mainChain.insert(mainChain.begin() + index, pend[_jacobsthalIndexes[i]]);
			pend.erase(pend.begin() + _jacobsthalIndexes[i]);
		}
	}
	
	for (size_t i = 0; i < pend.size(); ++i){
		int index = binarySearch(mainChain, pend[i]);
		mainChain.insert(mainChain.begin() + index, pend[i]);
	}

	// // Inserting unpaired elements when initial array size is odd. This 
	// TODO: This _unpaired element is called a struggler
	if (_unpairedElement != -1){
		int index = binarySearch(mainChain, _unpairedElement);
		mainChain.insert(mainChain.begin() + index, _unpairedElement);
	}
}

void 	PMergeMe::printUnsortedSequence(){

	std::list<double>::iterator it;

	std::cout << "Before Sorting: ";
	for(it = _unsortedSequence.begin(); it != _unsortedSequence.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	PMergeMe::printPairs(T & container){

	std::cout << "Printing Pairs:" << std::endl;
	for (size_t i = 0; i < container.size(); ++i){
		std::cout << "Pair[" << i << "]: ";
		std::cout << container[i].first << " " << container[i].second << std::endl;
	}
}

void	PMergeMe::AreNumbersSorted(){

		//Function to validate that content is struly sorted
	if (std::is_sorted(_mainChainVector.begin(), _mainChainVector.end()))
		std::cout << "Initial Sequence is correctly sorted with std::vector" << std::endl;
	else
		std::cout << "Initial Sequence is NOT correctly sorted with std::vector" << std::endl;

	if (std::is_sorted(_mainChainDeque.begin(), _mainChainDeque.end()))
		std::cout << "Initial Sequence is correctly sorted with std::deque" << std::endl;
	else
		std::cout << "Initial Sequence is NOT correctly sorted with std::deque" << std::endl;
}


template <typename U>
void	PMergeMe::printMainChain(U& mainChain){

	std::cout << "Printing Main Chain: ";
	for(size_t i = 0; i < mainChain.size(); ++i)
		std::cout << mainChain[i] << " ";
	std::cout << std::endl;
}

template <typename U>
void	PMergeMe::printPend(U& pend){

	std::cout << "Printing Pend: ";
	for(size_t i = 0; i < pend.size(); ++i)
		std::cout << pend[i] << " ";
	std::cout << std::endl;
}

void			PMergeMe::printJacobsthalSequence(){

	std::cout << "Jacobsthal indexes for current number sequence: ";
	for(size_t i = 0; i < _jacobsthalIndexes.size(); ++i){
		std::cout << _jacobsthalIndexes[i] << " ";
	}
	std::cout << std::endl;
}

void	PMergeMe::printSortedSequence(){

	std::cout << "After Sorting: ";
	for(size_t i = 0; i < _mainChainVector.size(); ++i)
		std::cout << _mainChainVector[i] << " ";
	std::cout << std::endl;
}

void	PMergeMe::printSortingTimes(){

	double elapsed_seconds = static_cast<double>(_endVector - _startVector) / CLOCKS_PER_SEC;
	double elapsed_microseconds = elapsed_seconds * 1000000;

    // Output the time in microseconds
	std::cout << "Time to process a range of " << _mainChainVector.size() << " elements with std::vector: ";
    std::cout << std::fixed << std::setprecision(7) << elapsed_microseconds << " us" << std::endl;

	double elapsed_seconds1 = static_cast<double>(_endDeque - _startDeque) / CLOCKS_PER_SEC;
	double elapsed_microseconds1 = elapsed_seconds1 * 1000000;

    // Output the time in microseconds
	std::cout << "Time to process a range of " << _mainChainDeque.size() << " elements with std::deque: ";
    std::cout << std::fixed << std::setprecision(7) << elapsed_microseconds1 << " us" << std::endl;
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

// /* ************************************************************************** */