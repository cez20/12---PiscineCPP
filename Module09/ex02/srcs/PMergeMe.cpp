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
		return;
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
	mergeSortRecursive(_myVector, 0, _myVector.size() / 2);

	// Merge-insertion sort for std::deque
	// sortPairs(_myDeque);

}

template <typename T>
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

template <typename T>
void	PMergeMe::mergeSort(T & container, const size_t left, const size_t middle, const size_t right){

	printContainer(container);
	std::cout << "The value of left is: " << left << std::endl;
	std::cout << "The value of middle is: " << middle << std::endl;
	std::cout << "The value of right is: " << right << std::endl;

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