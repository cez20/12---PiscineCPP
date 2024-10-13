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
	printRecursiveSortedPairs();
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

void   PMergeMe::mergeSortPairsRecursive(size_t left, size_t right) {

	if (left >= right)
		return;
	const size_t middle = left + (right - left) / 2;
	mergeSortPairsRecursive(left, middle);
	mergeSortPairsRecursive(middle + 1, right);
	mergeSort(left, middle, right);
}

void 	PMergeMe::mergeSort(size_t left, size_t middle, size_t right){

	std::cout << "---------------- CALL -----------------" << std::endl;
	printVector();
	std::cout << "\n";
	std::cout << "Initial left value (index) is: " << left << std::endl;
	std::cout << "Initial Middle value (index) is: " << middle << std::endl;
	std::cout << "Initial Right value (index) is: " << right << std::endl;

	// If middle et left are equal, it means there are only 2 elements in array, therefore 
	// 2 elements are already in order because of SortPairs?()
	if (middle == left)
		return;

	// Now I must compare 2 pairs absolutely. On first round, if I keep left = 0 and right = 1, it will compare the same pairs which was already done
	// in sortedPairs. Therefore, I must adjust so that left , must point to the first index of left side, and right must point to the index of following pair

	//1 - Ajuster les index pour qu'il represente ce qu'il doive representer
	const size_t leftSubArrayStartingIndex = left * N_ELEM_IN_PAIR;
	const size_t middleIndex = middle * N_ELEM_IN_PAIR;
	const size_t rightSubArrayEndIndex = right * N_ELEM_IN_PAIR;  // Is it EndIndex or Beginnning Index. Not sure yet
 
	std::cout << "\n";
	std::cout << "LeftSubArrayStartingIndex is: " << leftSubArrayStartingIndex << std::endl; // TO BE REMOVED
	std::cout << "MiddleIndex is: " << middleIndex << std::endl; // TO BE REMOVED
	std::cout << "RightSubArrayEndIndex is: " << rightSubArrayEndIndex << std::endl; // TO BE REMOVED

	//2 - Longueur de l'array de gauche
	size_t leftSubArrayLength = middleIndex - leftSubArrayStartingIndex; // TODO: The + N_ELEM_IN PAIR causes value to not be good
	if (leftSubArrayLength == 0) // TODO: P-e que je peux l'enlever en raison de ma condition if left == middle return; 
		leftSubArrayLength += N_ELEM_IN_PAIR;
	
	std::cout << "\n";
	std::cout << "leftSubArrayLength is: " << leftSubArrayLength << std::endl; // TO BE REMOVED

	//3 - Longueur de l'array de droite
	const size_t rightSubArrayLength = rightSubArrayEndIndex - middleIndex;
	std::cout << "rightSubArrayLength is: " << rightSubArrayLength << std::endl; // TO BE REMOVED

	//4 - Creer des array temporaire de facon a pouvoir contenir les regroupements que l'on va comparer
	std::array<int, MAX_ARRAY_SIZE / 2> leftSubArray;
	std::array<int, MAX_ARRAY_SIZE / 2> rightSubArray;

	std::cout << "\n";
	std::cout << "Create a leftSubArray of 2043 elements" << std::endl; // TO BE REMOVED
	std::cout << "Created a rightSubArray of 2043 elements" << std::endl; // TO BE REMOVED
	std::cout << "\n";

	//5 - Copier le regroupement de paires de la moitie gauche dans leftSubArray
	for (size_t i = 0; i < leftSubArrayLength; ++i) {
        leftSubArray[i] = _myVector[leftSubArrayStartingIndex + i];
		std::cout << "Inserted " << _myVector[leftSubArrayStartingIndex + i] << " in leftSubArray[" << i << "]" << std::endl; // TO BE REMOVED
    }

	//6 - Copier le regroupement de paires de la moitie droite dans righSubArray
	std::cout << "\n";
	for (size_t i = 0; i < rightSubArrayLength; ++i) {
		if (middleIndex == 0){
			rightSubArray[i] = _myVector[middleIndex + N_ELEM_IN_PAIR + i]; // TODO: This part causes problem too
			std::cout << "Inserted " << _myVector[middleIndex + N_ELEM_IN_PAIR + i] << " in rightSubArray[" << i << "]" << std::endl; // TO BE REMOVED
		} else {
			rightSubArray[i] = _myVector[middleIndex + i]; // TODO: This part causes problem too
			std::cout << "Inserted " << _myVector[middleIndex + i] << " in rightSubArray[" << i << "]" << std::endl; // TO BE REMOVED
		}
    }

	//7 - Do mergeSort when comparing elements of both halves
	size_t i = 0;
    size_t j = 0;
    for (size_t k = leftSubArrayStartingIndex; k < (leftSubArrayLength + rightSubArrayLength); k += N_ELEM_IN_PAIR) {
        if (i < leftSubArrayLength && (j >= rightSubArrayLength || leftSubArray[i + 1] < rightSubArray[j + 1])) {
            // copy pair from left
			_myVector[k] = leftSubArray[i];
            _myVector[k + 1] = leftSubArray[i + 1];
			std::cout << "\nInserted " << leftSubArray[i] << " at _myVector position [" << k << "]" << std::endl;
			std::cout << "Inserted " << leftSubArray[i + 1] << " at _myVector position [" << k + 1 << "]" << std::endl;
            i += N_ELEM_IN_PAIR; // Goes to next pair. Jump 2 index further
        } else {
            // copy pair from right
            _myVector[k] = rightSubArray[j];
            _myVector[k + 1] = rightSubArray[j + 1];
			std::cout << "\nInserted " << rightSubArray[j] << " at _myVector position [" << k << "]" << std::endl;
			std::cout << "Inserted " << rightSubArray[j + 1] << " at _myVector position [" << k + 1 << "]" << std::endl;
            j += N_ELEM_IN_PAIR; // Goes to next pair. Jump 2 index further
        }
    }

	printVector();
	std::cout << "--------------- END OF CALL ------------------" << std::endl;
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

void	PMergeMe::printVector() {
	std::vector<double>::iterator it;

	std::cout << "Vector content: ";
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