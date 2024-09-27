#include "PMergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PMergeMe::PMergeMe()
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

PMergeMe &				PMergeMe::operator=( PMergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->_myVector = rhs._myVector;
		this->_myDeque = rhs._myDeque;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/


void PMergeMe::processArguments(int argCount, char **argList){
	
	int                 i = 1;

	while (i < argCount){
		std::string arg = argList[i];
		if(!isValidNumberFormat(arg) || !isBelowIntMax(arg))
			throw std::invalid_argument("Invalid argument. Either not a number or higher than INT_MAX");
		else{
			_start = std::clock(); // Starting the clock to calculate process runnning time. 
			_initialIntSequence.push_back(stringToDouble(arg));
		}
		i++;
	}
}

void	PMergeMe::initializeContainers() {

	_myVector.assign(_initialIntSequence.begin(), _initialIntSequence.end());
	_myDeque.assign(_initialIntSequence.begin(), _initialIntSequence.end());
}

void PMergeMe::sortPairs(){

	if (_myVector.size() < 2)
		return;
	for (size_t i = 0; i < _myVector.size(); i += 2){
		if(((i + 1) < _myVector.size()) && _myVector[i] > _myVector[i + 1])
			std::swap(_myVector[i], _myVector[i + 1]);
	}
	//printSequenceAfterSort(); // This is to test that the swap is done correctly. 
}

void PMergeMe::mergeSortPairsRecursive(size_t left, size_t right){

	if (left >= right)
		return;
	const size_t middle = left + (right - left) / 2;
	mergeSortPairsRecursive(left, middle);      // sort left part
	mergeSortPairsRecursive(middle + 1, right); // sort right part
	std::cout << "I am here" << std::endl;
}


// void
// merge_sort_pairs_recursion(std::vector<int>& array, const size_t left, const size_t right) {
//     if (left >= right) return; // recursion end condition

//     const size_t middle = left + (right - left) / 2;
//     merge_sort_pairs_recursion(array, left, middle);      // sort left part
//     merge_sort_pairs_recursion(array, middle + 1, right); // sort right part

//     merge_pair_arrays(array, left, middle, right); // merge two sorted parts
// }

void PMergeMe::mergeSortPairs(){
	
	size_t left = 0;
	size_t nbrElementsInPair = 2;
	size_t right = (_myVector.size() - 1) / nbrElementsInPair;

	if (isArraySizeOdd()){
		std::cout << _myVector.size() << std::endl;
		mergeSortPairsRecursive(left, right - 1);
	}
	else
		mergeSortPairsRecursive(left, right);

}

void PMergeMe::mergeInsertionSort() {

	if (_initialIntSequence.size() < 2)
		return;
	sortPairs();
	mergeSortPairs();
}

bool	PMergeMe::isArraySizeOdd(){

	if (_myVector.size() % 2 != 0)
		return true;
	return false;
}

void 	PMergeMe::printInitialIntSequence(){

	std::list<double>::iterator it;

	std::cout << "Before Sorting: ";
	for(it = _initialIntSequence.begin(); it != _initialIntSequence.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PMergeMe::printSequenceAfterSort(){

	std::vector<double>::iterator it;

	std::cout << "After Sorting: ";
	for(it = _myVector.begin(); it != _myVector.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
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


/*
** --------------------------------- ACCESSOR ---------------------------------
*/



// void	PMergeMe::initializeContainers() {

// 	_myVector.assign(_initialIntSequence.begin(), _initialIntSequence.end());
// 	_myDeque.assign(_initialIntSequence.begin(), _initialIntSequence.end());
// }

// void PMergeMe::recursiveSortPairs(int n){
// 	if (n < 1)
// 		return;
// 	if (_myVector[n] > _myVector[n - 1])
// 		std::swap(_myVector[n], _myVector[n - 1]);
// 	recursiveSortPairs(n - 2);
// }

// void PMergeMe::mergeInsertionSort() {

// 	int n = _myVector.size();
// 	if (n % 2 == 1)
// 		n -= 2;
// 	else
// 		n -= 1;
// 	recursiveSortPairs(n);
// }


/* ************************************************************************** */