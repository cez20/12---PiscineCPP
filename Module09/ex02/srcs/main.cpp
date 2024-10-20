/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/10/20 12:31:17 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <ctime>
#include "PMergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc >= 2) {
        PMergeMe    sortedList;
        
        //TODO: Do I need to put all function inside inside try/catch or only those that might have a mistake such as process Arguments!
        try {
            sortedList.processArguments(argc, argv);
            sortedList.printUnsortedSequence();
            
            sortedList.mergeInsertionSort();
            
            sortedList.printSortedSequence();
            sortedList.printSortingTimes();

            // sortedList.AreNumbersSorted();
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    } else {
        std::cout << "ERROR! Program should take 1 argument or more" << std::endl;
        return 1;
    }
    return 0;
}