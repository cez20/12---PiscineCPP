#include "PMergeMe.hpp"
#define N_ELEM_IN_PAIR 2
#define MAX_ARRAY_SIZE 4096
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
		this->_myVector = rhs._myVector;
		this->_myDeque = rhs._myDeque;
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
	_myVector.assign(_initialSequence.begin(), _initialSequence.end());
	_myDeque.assign(_initialSequence.begin(), _initialSequence.end());
}


void PMergeMe::mergeInsertionSort() {

	// Merge-insertion sort for std::vector 
	sortPairs(_myVector);
	// Condition that avoids doing unnecessary calls to mergeSort to sort 2 numbers which are already sorted after sortPairs()
	if (_myVector.size() > 2){
		mergeSortRecursive(_myVector, 0, _myVector.size() / 2);
	}
	printContainer(_myVector);


	// Merge-insertion sort for std::deque
	// sortPairs(_myDeque);

}

template<typename T>
void	PMergeMe::sortPairs(T & container) {

	for (size_t i = 0; i < container.size(); i += 2){
		if(((i + 1) < container.size()) && container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
	}

	// Printing content of container
	// for (size_t i = 0; i < container.size(); ++i)
	// 	std::cout << container[i] << std::endl;
}

template <typename T>
void   PMergeMe::mergeSortRecursive(T & container, size_t left, size_t right) {

	if (left >= right)
		return;
	const size_t middle = left + (right - left) / 2;
	mergeSortRecursive(container, left, middle);
	mergeSortRecursive(container, middle + 1, right);
	mergeSort(container, left, middle, right);
}

// This function will put all the larger elements in order. Note that when a larger element is moved, its associated smallest element
// is also moved with it at the position before. 
template <typename T>
void	PMergeMe::mergeSort(T & container, const size_t left, const size_t middle, const size_t right){
	
	std::cout << "------------------  CALL ------------------" << std::endl;
	printContainer(container);
	std::cout << "\n";
	std::cout << "The value of left is: " << left << std::endl;
	std::cout << "The value of middle is: " << middle << std::endl;
	std::cout << "The value of right is: " << right << std::endl;
	std::cout << "\n";

	if (middle == 0){
		std::cout << "Middle value is 0, which means only one pair. SO no comparisons btw 2 pairs possible" << std::endl;
		return;
	}
		
	// Adjusting the indices because we are counting in pairs
	const size_t leftStart = left * N_ELEM_IN_PAIR;
	const size_t leftEnd = middle * N_ELEM_IN_PAIR;
	const size_t rightStart = middle * N_ELEM_IN_PAIR;
	const size_t rightEnd = right * N_ELEM_IN_PAIR;

	std::cout << "The value of leftStart is: " << leftStart << std::endl;
	std::cout << "The value of leftEnd is: "  << leftEnd << std::endl;
	std::cout << "The value of rightStart is: " << rightStart << std::endl;
	std::cout << "The value of rightEnd is: " << rightEnd << std::endl;
	std::cout << "\n";

	// Calculating length of left and rightSide
	const size_t leftLength = leftEnd - leftStart;
	// if (leftLength == 0)
	// 	leftLength += N_ELEM_IN_PAIR;
	const size_t rightLength = rightEnd - leftEnd;

	std::cout << "The value of leftLength is: " <<  leftLength << std::endl;
	std::cout << "The value of rightLength is: " << rightLength << std::endl;

	// Creating arrays that will contain the leftSubArray and rightSubArray
	//TODO: Verifier si au lieu de creer un array de 2000 elements, je ne peux pas creer le bon size a chaque fois.
	std::array<int, MAX_ARRAY_SIZE / 2> leftSubArray;
	std::array<int, MAX_ARRAY_SIZE / 2> rightSubArray;

	// Copying content of container inside newly created arrays
	std::copy(&container[leftStart], &container[leftStart + leftLength], leftSubArray.begin());
	std::copy(&container[rightStart], &container[rightStart + rightLength], rightSubArray.begin());

	// Comparing leftSubArray with rightSubArray and moving values accordingly
	// VERY IMPORTANT: if larger elements change place, its associated smallest element must move to.

	size_t i = 0;
	size_t j = 0;
	size_t k = leftStart;

	while (k < (rightEnd + 1)){

		if (i < leftLength && (j >= rightLength || leftSubArray[i + 1] < rightSubArray[j + 1])){
			container[k] = leftSubArray[i];
			container[k + 1] = leftSubArray[i + 1];
			i += N_ELEM_IN_PAIR;
			k += N_ELEM_IN_PAIR;
		} else {
			container[k] = rightSubArray[j];
			container[k + 1] = rightSubArray[j + 1];
			j += N_ELEM_IN_PAIR;
			k += N_ELEM_IN_PAIR;
		}
		std::cout << "I am in loop" << std::endl;
	}

	printContainer(container);
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

	std::cout << "Container content: ";
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}


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