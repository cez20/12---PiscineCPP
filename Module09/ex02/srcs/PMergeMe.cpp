#include "PMergeMe.hpp"
#define N_ELEM_IN_PAIR 2
#define MAX_ARRAY_SIZE 4096
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


void PMergeMe::mergeInsertionSort() {

	// Gere size le size de l'array est 0 ou 1. 
	if (_initialIntSequence.size() < 2)
		return;
	groupAndSortPairs();
	
	mergeSortPairs();
}

void	PMergeMe::groupAndSortPairs() {

	for (size_t i = 0; i < _myVector.size(); i += 2){
		if(((i + 1) < _myVector.size()) && _myVector[i] > _myVector[i + 1])
			std::swap(_myVector[i], _myVector[i + 1]);
	}
	printSortedPairs();
}

void 	PMergeMe::mergeSort(size_t left, size_t middle, size_t right){

	const size_t l = left * N_ELEM_IN_PAIR;
    const size_t m = middle * N_ELEM_IN_PAIR;
    const size_t r = right * N_ELEM_IN_PAIR;

    const size_t left_length = m - l + N_ELEM_IN_PAIR;
    const size_t right_length = r - m;

	std::array<int, MAX_ARRAY_SIZE / 2> tmp_left;  // could do `new int[left_length]` instead; using stack for speed
    std::array<int, MAX_ARRAY_SIZE / 2> tmp_right; // same as above

	std::copy(&_myVector[l], &_myVector[l + left_length], tmp_left.begin());
    std::copy(&_myVector[m + N_ELEM_IN_PAIR], &_myVector[m + N_ELEM_IN_PAIR + right_length], tmp_right.begin());

	size_t i = 0;
    size_t j = 0;
    for (size_t k = l; k < r + 1; k += N_ELEM_IN_PAIR) {
        if (i < left_length && (j >= right_length || tmp_left[i + 1] < tmp_right[j + 1])) {
            // copy pair from left
			_myVector[k] = tmp_left[i];
            _myVector[k + 1] = tmp_left[i + 1];
            i += N_ELEM_IN_PAIR;
        } else {
            // copy pair from right
            _myVector[k] = tmp_right[j];
            _myVector[k + 1] = tmp_right[j + 1];
            j += N_ELEM_IN_PAIR;
        }
    }

}


// Merge sort is recursive
void	PMergeMe::mergeSortPairs() {

	if (_myVector.size() % 2 == 1)
		mergeSortPairsRecursive(0, _myVector.size() / N_ELEM_IN_PAIR - 1);
	else
		mergeSortPairsRecursive(0, _myVector.size() / N_ELEM_IN_PAIR);
}

void   PMergeMe::mergeSortPairsRecursive(size_t left, size_t right) {

	if (left >= right)
		return;
	const size_t middle = left + (right - left) / 2;
	mergeSortPairsRecursive(left, middle);
	mergeSortPairsRecursive(middle + 1, right);
	mergeSort(left, middle, right);
}


void 	PMergeMe::printInitialIntSequence(){

	std::list<double>::iterator it;

	std::cout << "Before Sorting: ";
	for(it = _initialIntSequence.begin(); it != _initialIntSequence.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PMergeMe::printSortedPairs() {

	std::vector<double>::iterator it;

	std::cout << "After Pair Sorting: ";
	for(it = _myVector.begin(); it != _myVector.end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


// void	PMergeMe::printSequenceAfterSort(){

// 	std::vector<double>::iterator it;

// 	std::cout << "After Sorting: ";
// 	for(it = _myVector.begin(); it != _myVector.end(); ++it){
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }

bool	PMergeMe::isArraySizeOdd(){

	if (_myVector.size() % 2 != 0)
		return true;
	return false;
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