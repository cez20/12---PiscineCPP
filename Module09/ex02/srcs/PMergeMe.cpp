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
	// printRecursiveSortedPairs();
}

void	PMergeMe::groupAndSortPairs() {

	for (size_t i = 0; i < _myVector.size(); i += 2){
		if(((i + 1) < _myVector.size()) && _myVector[i] > _myVector[i + 1])
			std::swap(_myVector[i], _myVector[i + 1]);
	}
	printSortedPairs();
}

void	PMergeMe::mergeSortPairs() {

	if (_myVector.size() % 2 == 1)
		mergeSortPairsRecursive(0, _myVector.size() / N_ELEM_IN_PAIR - 1);
	else
		mergeSortPairsRecursive(0, _myVector.size() / N_ELEM_IN_PAIR);
}

//Initial Array = 1 4 2 6

// 1ST ROUND: We split initial vector by 2 (_myVector / 2) for the first time
// MergeSortPairsRecursive(left, right);
// MergeSortPairs(0, 2): 
//	
//	[1 , 4]   vs [2, 6]
//	 ^	 ^        ^
//	 l            r          **** l, m, r always refers to indices and not the number itself 
//
//   Find the middle (to start middle of left pair):
//	
//   middle = left + (right - left) / 2
//		        ^       ^       ^
//		        0       2   -  0    / 2
//						   ^		^
//                         2      / 2  = 1
//   middle =   0  +  1

//   SECOND ROUND (left side)
//   mergeSortPairRecursive(left, right)
//   mergeSortPairRecursive(0, 1)    // We take middle as right value so that we divive and conquer on left side
//	
//	 [0] [1]        [2]	[3]
//	 [1 , 4]        [2 , 6 ]
//	  ^	  ^
//    l   r 

//   middle = left + (right - left) / 2
//		        ^       ^       ^
//		        0       1   -  0    / 2
//						   ^		^
//                         1      / 2  = 0.5 == 0 
//   middle =   0  +  0 = 0
//
//   THIRD ROUND(left side)

//	 mergeSortPairRecursive(left, right)
//	 mergeSortPairRecursive(0, 0)
//   
//   Stop condition because (left >= right)  0 >= 0, return;


//  FIRST ROUND (RIGHT SIDE OF LEFT SIDE)
//  Current values:
//  left = 0
//  right = 1
//  middle = 0

//  2ND ROUND (RIGHT SIDE)
//	mergeSortPairs(middle + 1, right)
//  mergeSortPairs(1, 1)
//
//  left >= right , stop condition
//
//
//
//  CALLING MERGE SORT (left, middle, right);
//  mergeSort(0, 1, 0);
//
//   

void   PMergeMe::mergeSortPairsRecursive(size_t left, size_t right) {

	if (left >= right)
		return;
	const size_t middle = left + (right - left) / 2;
	mergeSortPairsRecursive(left, middle);
	mergeSortPairsRecursive(middle + 1, right);
	mergeSort(left, middle, right);
}


// Left SubArrayIndex indicates the start of the LeftSubArray
// Middle Index indicates the middle between left and RightSubarray or in other words, the beginning of the rightSubArray
// RightSubArrayEndIndex : indicates the end index of the right subarray


void 	PMergeMe::mergeSort(size_t left, size_t middle, size_t right){

	const size_t leftSubArrayStartingIndex = left * N_ELEM_IN_PAIR;
	const size_t middleIndex = middle * N_ELEM_IN_PAIR;
	const size_t rightSubArrayEndIndex = right * N_ELEM_IN_PAIR;

	const size_t leftSubArrayLength = middleIndex - leftSubArrayStartingIndex + N_ELEM_IN_PAIR; // Clarify this part
	const size_t rightSubArrayLength = rightSubArrayEndIndex - middleIndex;

	std::array<int, MAX_ARRAY_SIZE / 2> leftSubArray;
	std::array<int, MAX_ARRAY_SIZE / 2> rightSubArray;

	std::copy(&_myVector[leftSubArrayStartingIndex], &_myVector[leftSubArrayStartingIndex + leftSubArrayLength], leftSubArray.begin());
    std::copy(&_myVector[middleIndex + N_ELEM_IN_PAIR], &_myVector[middleIndex + N_ELEM_IN_PAIR + rightSubArrayLength], rightSubArray.begin());

	size_t i = 0;
    size_t j = 0;
    for (size_t k = leftSubArrayStartingIndex; k < rightSubArrayEndIndex + 1; k += N_ELEM_IN_PAIR) {
        if (i < leftSubArrayLength && (j >= rightSubArrayLength || leftSubArray[i + 1] < rightSubArray[j + 1])) {
            // copy pair from left
			_myVector[k] = leftSubArray[i];
            _myVector[k + 1] = leftSubArray[i + 1];
            i += N_ELEM_IN_PAIR; // Goes to next pair. Jump 2 index further
        } else {
            // copy pair from right
            _myVector[k] = rightSubArray[j];
            _myVector[k + 1] = rightSubArray[j + 1];
            j += N_ELEM_IN_PAIR; // Goes to next pair. Jump 2 index further
        }
    }

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

void	PMergeMe::printRecursiveSortedPairs() {
	std::vector<double>::iterator it;

	std::cout << "After Recursive Pair Sorting: ";
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