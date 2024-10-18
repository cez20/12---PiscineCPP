#include "DequeSorter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DequeSorter::DequeSorter(): _unpairedElement(-1)
{
}

DequeSorter::DequeSorter( const DequeSorter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DequeSorter::~DequeSorter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DequeSorter &				DequeSorter::operator=( DequeSorter const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void DequeSorter::mergeInsertionSort(std::list<double> unsortedSequence) {

	if (unsortedSequence.size() < 2)
		throw std::invalid_argument("ERROR! Arguments size less than 2");
	if (unsortedSequence.size() % 2 == 1){
		_unpairedElement = unsortedSequence.back();
		unsortedSequence.pop_back();
	}

	_start = std::clock();
	createPairs(unsortedSequence);
	sortPairs();
	mergeSortRecursive(_myDequePairs, 0, _myDequePairs.size() - 1);
	// std::cout << "After mergeSorting" << std::endl;
	// for (size_t i = 0; i < _myDequePairs.size(); ++i){
	// 	std::cout << "Pair[" << i << "]: ";
	// 	std::cout << _myDequePairs[i].first << " " << _myDequePairs[i].second << std::endl;
	// }
	createMainChain();
	createPend();
	generateJacobsthalSequence();
	insertionSort();
	_end = std::clock();

}

void	DequeSorter::createPairs(std::list<double> unsortedSequence){

	std::list<double>::iterator it = unsortedSequence.begin();

	while (it != unsortedSequence.end()){
		int first = *it;
		++it;
		if (it != unsortedSequence.end()){
			int second = *it;
			++it;
			_myDequePairs.push_back(std::make_pair(first, second));
		}
	}

	// for (size_t i = 0; i < _myDequePairs.size(); ++i){
	// 	std::cout << "Pair[" << i << "]: ";
	// 	std::cout << _myDequePairs[i].first << " " << _myDequePairs[i].second << std::endl;
	// }

}

// //TODO: Creer cette meme fonction pour storer un dequePair

void	DequeSorter::sortPairs() {

	for (size_t i = 0; i < _myDequePairs.size(); ++i){
		if(_myDequePairs[i].first < _myDequePairs[i].second)
			std::swap(_myDequePairs[i].first, _myDequePairs[i].second);
	}

	// std::cout << "After sortPairs: " << std::endl;
	// for (size_t i = 0; i < _myDequePairs.size(); ++i){
	// 	std::cout << "Pair[" << i << "]: ";
	// 	std::cout << _myDequePairs[i].first << " " << _myDequePairs[i].second << std::endl;
	// }
}

// Important to put a reference here
void	DequeSorter::mergeSortRecursive(std::deque<std::pair<int,int> >& container, size_t left, size_t right)
{
	if (left >= right)
		return;
	const size_t middle = left + (right - left) / 2;
	mergeSortRecursive(container, left, middle);
	mergeSortRecursive(container, middle + 1, right);
	mergeSort(container, left, middle, right);
}

// Important to put a reference here --> std::vector<std::pair<int, int> >&
void 	DequeSorter::mergeSort(std::deque<std::pair<int,int> >& container, size_t left, size_t middle, size_t right)
{
	std::deque<std::pair<int, int> >::iterator start = container.begin() + left;
	std::deque<std::pair<int, int> >::iterator mid = container.begin() + (middle + 1);
	std::deque<std::pair<int, int> >::iterator end = container.begin() + (right + 1);


	std::deque<std::pair<int, int> > leftSubPairs(start, mid);
	std::deque<std::pair<int, int> > rightSubPairs(mid, end);

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

void	DequeSorter::createMainChain(){

	for(size_t i = 0; i < _myDequePairs.size(); ++i){
		_mainChain.push_back(_myDequePairs[i].first);
	}

	// std::cout << "Printing main chain: ";
	// for (size_t i = 0; i < _mainChainVector.size(); ++i)
	// 	std::cout << _mainChainVector[i] << " ";
	// std::cout << std::endl;
}

void	DequeSorter::createPend(){
	for(size_t i = 0; i < _myDequePairs.size(); ++i){
		_pend.push_back(_myDequePairs[i].second);
	}

	// std::cout << "Printing pend: ";
	// for (size_t i = 0; i < _pendDeque.size(); ++i)
	// 	std::cout << _pendDeque[i] << " ";
	// std::cout << std::endl;
}

size_t DequeSorter::Jacobsthal(int n) {
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


void	DequeSorter::generateJacobsthalSequence(){

	// We put a condition to make sure that Jacobsthal index exists in _pendVector
	for(size_t i = 0; i < _pend.size(); ++i){
		if (Jacobsthal(i) < _pend.size())
			_jacobsthalSequence.push_back(Jacobsthal(i));
	}

	// for(size_t i = 0; i < _jacobsthalSequenceVector.size(); ++i){
	// 	std::cout << "Jacobsthal sequence is: " << std::endl;
	// 	std::cout << _jacobsthalSequenceVector[i] << std::endl;
	// }
}

size_t	DequeSorter::binarySearch(std::deque<int> mainChain, size_t size, int number){

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

void	DequeSorter::insertionSort(){

	// Put elements at deque[jacobsthal_sequence_index] in main_chain
	for (size_t i = 0; i < _jacobsthalSequence.size(); ++i){
		if(_jacobsthalSequence[i] < _pend.size()){
			// std::cout << "The value of _pendVector[_jacobsthalSequenceVector[i]] is: " << _pendVector[_jacobsthalSequenceVector[i]] << std::endl;
			int index = binarySearch(_mainChain, _mainChain.size(), _pend[_jacobsthalSequence[i]]);
			_mainChain.insert(_mainChain.begin() + index, _pend[_jacobsthalSequence[i]]);
			_pend.erase(_pend.begin() + _jacobsthalSequence[i]);
		}
	}
	
	//TODO: What should I do, insert all elements corresponding to jacobsthal sequence and then erase, or add elemen and erase immediately?
	//TODO: Also, notes seems to show that we start a jacobstal index 3, so we avoid the 0, 1, 1 sequence of the beginning.
	// TODO: Also, index[0] seems to be index 1 because it belongs to b1.
	// Insert remaining elements of _pendVector
	for (size_t i = 0; i < _pend.size(); ++i){
		int index = binarySearch(_mainChain, _mainChain.size(), _pend[i]);
		_mainChain.insert(_mainChain.begin() + index, _pend[i]);
	}

	// Inserting unpaired elements when initial array size is odd. This 
	//TODO: This _unpaired element is called a struggler
	if (_unpairedElement != -1){
		int index = binarySearch(_mainChain, _mainChain.size(), _unpairedElement);
		_mainChain.insert(_mainChain.begin() + index, _unpairedElement);
	}

	// Function to validate that content is struly sorted
	// if (std::is_sorted(_mainChain.begin(), _mainChain.end()))
	// 	std::cout << "Initial Sequence is now correctly sorted" << std::endl;
	// else
	// 	std::cout << "Initial Sequence is NOT sorted" << std::endl;
}

void	DequeSorter::printSortedSequence(){

	std::cout << "After Sorting: ";
	for(size_t i = 0; i < _mainChain.size(); ++i)
		std::cout << _mainChain[i] << " ";
	std::cout << std::endl;
}

void	DequeSorter::printClock(){

	double elapsed_seconds = static_cast<double>(_end - _start) / CLOCKS_PER_SEC;
	double elapsed_microseconds = elapsed_seconds * 1000000;

    // Output the time in microseconds
	std::cout << "Time to process a range of " << _mainChain.size() << " elements with std::deque: ";
    std::cout << std::fixed << std::setprecision(7) << elapsed_microseconds << " us" << std::endl;
}


/* ************************************************************************** */

/* ************************************************************************** */

/* ************************************************************************** */