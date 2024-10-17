/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/10/17 18:14:05 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <ctime>
// #include "PMergeMe.hpp"
#include "SequenceProcessor.hpp"


int main(int argc, char **argv)
{
    if (argc < 2){
        std::cout << "ERROR! Program should take 1 argument or more" << std::endl;
        return 1;
    }
    
    SequenceProcessor sequence = SequenceProcessor();
    try {
        sequence.processArguments(argc, argv);
        sequence.printUnsortedSequence();
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }


}   
    

    // Then, this initialSequence will be sorted using Ford-Johnson algorithm and std::vector
    // Then, this initialSequence will be sorted using Ford-Johnson algorithm using std::deque
    // SortedSequence will be printed out. I think I can use either the std::vector sortedSequence or the std::deque SortedSequence
    // Then I have to printout the time it took the std::vector to do sorting.
    // Then I have to printout the time it took the std::deque to do sorting.
    

    // if (argc >= 2) {
    //     PMergeMe    sortedList;
        
    //     //TODO: Do I need to put all function inside inside try/catch or only those that might have a mistake such as process Arguments!
    //     try {
    //         sortedList.processArguments(argc, argv);
    //         sortedList.printInitialSequence();
    //         sortedList.initializeContainers();
    //         sortedList.mergeInsertionSort();
    //         sortedList.printSortedSequence();
    //         sortedList.printClock();
    //     } catch (std::exception & e) {
    //         std::cout << e.what() << std::endl;
    //     }
    // } else {
    //     std::cout << "ERROR! Program should take 1 argument or more" << std::endl;
    //     return 1;
    // }
    // return 0;