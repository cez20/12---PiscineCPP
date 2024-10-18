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
			_unsortedSequence.push_back(stringToDouble(arg));
		}
		i++;
	}
}

void PMergeMe::mergeInsertionSort() {

	if (_unsortedSequence.size() < 2)
		throw std::invalid_argument("ERROR! Arguments size less than 2");
	if (_unsortedSequence.size() % 2 == 1){
		_unpairedElement = _unsortedSequence.back();
		_unsortedSequence.pop_back();
	}

	// MERGE-INSERTION SORT FOR STD::VECTOR
	_startVector = std::clock();
	// createPairs(_myVectorPairs);
	// sortPairs(_myVectorPairs);
	// mergeSortRecursive(_myVectorPairs, 0, _myVectorPairs.size() - 1);
	// createMainChain();
	// createPend();
	// generateJacobsthalSequence();
	// insertionSort();
	_endVector = std::clock();

	// MERGE INSERTION SORT FOR STD::DEQUE

}

// template <typename T>
// void	PMergeMe::createPairs(T& container){

// 	std::list<double>::iterator it = _initialSequence.begin();

// 	while (it != _initialSequence.end()){
// 		int first = *it;
// 		++it;
// 		if (it != _initialSequence.end()){
// 			int second = *it;
// 			++it;
// 			container.push_back(std::make_pair(first, second));
// 		}
// 	}
// }

// void	PMergeMe::insertionSort(){

// 	// Put elements at _pendVector[jacobsthal_sequence_index] in main_chain
// 	for (size_t i = 0; i < _jacobsthalSequenceVector.size(); ++i){
// 		if(_jacobsthalSequenceVector[i] < _pendVector.size()){
// 			// std::cout << "The value of _pendVector[_jacobsthalSequenceVector[i]] is: " << _pendVector[_jacobsthalSequenceVector[i]] << std::endl;
// 			int index = binarySearch(_mainChainVector, _mainChainVector.size(), _pendVector[_jacobsthalSequenceVector[i]]);
// 			_mainChainVector.insert(_mainChainVector.begin() + index, _pendVector[_jacobsthalSequenceVector[i]]);
// 			_pendVector.erase(_pendVector.begin() + _jacobsthalSequenceVector[i]);
// 		}
// 	}
	
// 	//TODO: What should I do, insert all elements corresponding to jacobsthal sequence and then erase, or add elemen and erase immediately?
// 	//TODO: Also, notes seems to show that we start a jacobstal index 3, so we avoid the 0, 1, 1 sequence of the beginning.
// 	// TODO: Also, index[0] seems to be index 1 because it belongs to b1.
// 	// Insert remaining elements of _pendVector
// 	for (size_t i = 0; i < _pendVector.size(); ++i){
// 		int index = binarySearch(_mainChainVector, _mainChainVector.size(), _pendVector[i]);
// 		_mainChainVector.insert(_mainChainVector.begin() + index, _pendVector[i]);
// 	}

// 	// Inserting unpaired elements when initial array size is odd. This 
// 	//TODO: This _unpaired element is called a struggler
// 	if (_unpairedElement != -1){
// 		int index = binarySearch(_mainChainVector, _mainChainVector.size(), _unpairedElement);
// 		_mainChainVector.insert(_mainChainVector.begin() + index, _unpairedElement);
// 	}

// 	// Function to validate that content is struly sorted
// 	// if (std::is_sorted(_mainChainVector.begin(), _mainChainVector.end()))
// 	// 	std::cout << "Initial Sequence is now correctly sorted" << std::endl;
// 	// else
// 	// 	std::cout << "Initial Sequence is NOT sorted" << std::endl;
// }



// //TODO: Creer cette meme fonction pour storer un dequePair

// template<typename T>
// void	PMergeMe::sortPairs(T & container) {

// 	for (size_t i = 0; i < container.size(); ++i){
// 		if(container[i].first < container[i].second)
// 			std::swap(container[i].first, container[i].second);
// 	}
// }

// template <typename T>
// void	PMergeMe::mergeSortRecursive(T& container, size_t left, size_t right)
// {
// 	if (left >= right)
// 		return;
// 	const size_t middle = left + (right - left) / 2;
// 	mergeSortRecursive(container, left, middle);
// 	mergeSortRecursive(container, middle + 1, right);
// 	mergeSort(container, left, middle, right);
// }

// template <typename T>
// void 	PMergeMe::mergeSort(T& container, size_t left, size_t middle, size_t right)
// {
// 	std::vector<std::pair<int, int> >::iterator start = container.begin() + left;
// 	std::vector<std::pair<int, int> >::iterator mid = container.begin() + (middle + 1);
// 	std::vector<std::pair<int, int> >::iterator end = container.begin() + (right + 1);


// 	std::vector<std::pair<int, int> > leftSubPairs(start, mid);
// 	std::vector<std::pair<int, int> > rightSubPairs(mid, end);

// 	size_t i = 0;
// 	size_t j = 0;
// 	size_t k = left;

// 	while (i < leftSubPairs.size() && j < rightSubPairs.size())
// 	{
// 		if (leftSubPairs[i].first <= rightSubPairs[j].first)
// 			container[k++] = leftSubPairs[i++];
// 		else
// 			container[k++] = rightSubPairs[j++];
// 	}
// 	while (i < leftSubPairs.size())
// 		container[k++] = leftSubPairs[i++];
// 	while (j < rightSubPairs.size())
// 		container[k++] = rightSubPairs[j++];
// }

// void	PMergeMe::createMainChain(){

// 	for(size_t i = 0; i < _myVectorPairs.size(); ++i){
// 		_mainChainVector.push_back(_myVectorPairs[i].first);
// 	}

// 	// std::cout << "Printing main chain: ";
// 	// for (size_t i = 0; i < _mainChainVector.size(); ++i)
// 	// 	std::cout << _mainChainVector[i] << " ";
// 	// std::cout << std::endl;
// }

// void	PMergeMe::createPend(){
// 	for(size_t i = 0; i < _myVectorPairs.size(); ++i){
// 		_pendVector.push_back(_myVectorPairs[i].second);
// 	}

// 	// std::cout << "Printing pend: ";
// 	// for (size_t i = 0; i < _pendVector.size(); ++i)
// 	// 	std::cout << _pendVector[i] << " ";
// 	// std::cout << std::endl;
// }

// size_t PMergeMe::Jacobsthal(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;

//     int prev2 = 0; // Jacobsthal(0)
//     int prev1 = 1; // Jacobsthal(1)
//     int current = 0;

//     for (int i = 2; i <= n; ++i) {
//         current = prev1 + 2 * prev2;
//         prev2 = prev1;
//         prev1 = current;
//     }

//     return current;
// }


// void	PMergeMe::generateJacobsthalSequence(){

// 	// We put a condition to make sure that Jacobsthal index exists in _pendVector
// 	for(size_t i = 0; i < _pendVector.size(); ++i){
// 		if (Jacobsthal(i) < _pendVector.size())
// 			_jacobsthalSequenceVector.push_back(Jacobsthal(i));
// 	}

// 	// for(size_t i = 0; i < _jacobsthalSequenceVector.size(); ++i){
// 	// 	std::cout << "Jacobsthal sequence is: " << std::endl;
// 	// 	std::cout << _jacobsthalSequenceVector[i] << std::endl;
// 	// }
// }

// size_t	PMergeMe::binarySearch(std::vector<int> mainChain, size_t size, int number){

// 	size_t start = 0;
// 	size_t end = size - 1;

// 	while (start <= end){

// 		size_t middle = (start + end) / 2;
// 		if (mainChain[middle] == number) // Returns the indexes 
// 			return middle;
// 		else if (number < mainChain[middle]){
// 			if (middle == 0) 
// 				break;
// 			end = middle - 1;
// 		}
// 		else
// 			start = middle + 1;
// 	}
// 	return start;
// }


void 	PMergeMe::printUnsortedSequence(){

	std::list<double>::iterator it;

	std::cout << "Before Sorting: ";
	for(it = _unsortedSequence.begin(); it != _unsortedSequence.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// void	PMergeMe::printSortedSequence(){

// 	std::cout << "After Sorting: ";
// 	for(size_t i = 0; i < _mainChainVector.size(); ++i)
// 		std::cout << _mainChainVector[i] << " ";
// 	std::cout << std::endl;
// }

// void	PMergeMe::printClock(std::clock_t start, std::clock_t end){

// 	double elapsed_seconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
// 	double elapsed_microseconds = elapsed_seconds * 1000000;

//     // Output the time in microseconds
// 	std::cout << "Time to process a range of " << _mainChainVector.size() << " elements with std::vector: ";
//     std::cout << std::fixed << std::setprecision(7) << elapsed_microseconds << " us" << std::endl;
// }

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