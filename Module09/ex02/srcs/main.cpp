/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/09/12 09:12:01 by cemenjiv         ###   ########.fr       */
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
            sortedList.printInitialIntSequence();
            sortedList.initializeContainers();
            sortedList.mergeInsertionSort();
            // sortedList.printSequenceAfterSort();
            // sortedList.printVectorSortingTime();
            // sortedList.printDequeSortingTime();
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
       
        // std::list<double>   argList;  
        // int                 i = 1;

        // while (i < argc){
        //     std::string arg = argv[i];
        //     if(!isValidNumberFormat(arg) || !isBelowIntMax(arg))
        //         std::cout << "There is an error!" << std::endl;
        //     else{
        //         std::clock_t start = std::clock();
        //         argList.push_back(stringToDouble(arg));
        //     }
        //     i++;
        // }
    } else {
        std::cout << "ERROR! Program should take 1 argument or more" << std::endl;
        return 1;
    }
    return 0;
}