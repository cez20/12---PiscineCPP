/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/12/07 23:53:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <vector>  //A enlever 

int main()
{
    // MaxCapacityReached exception 
    
    Span test(3);

    test.addNumber(25);
    test.addNumber(100);
    test.addNumber(30);
    test.shortestSpan();
    test.longestSpan();

    try{
        test.addNumber(75);
    
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    // No range because all same values 

    Span test1(3);

    try{
        test1.addNumber(25);
        test1.addNumber(25);
        test1.addNumber(25);
        std::cout << "shortestSpan is: " << test1.shortestSpan() << std::endl;
        std::cout << "longest Span is: " << test1.longestSpan() << std::endl;
        
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    // Shortest and longest span exception 
    
    Span test2(3);
    
    test2.addNumber(3);
    
    try{
       test1.shortestSpan();
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    Span test3(3);
    
    test2.addNumber(3);
    try{
        test3.longestSpan();
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    // Testing shortest and longest range with 10000 numbers 

    srand(static_cast<unsigned int>(time(NULL)));

    std::vector<int> test4;
    for (std::size_t i = 0; i < 10000; ++i) {
        test4.push_back(rand());
        std::cout << test4[i] << std::endl;
    }

    Span test5(10000);
    test5.addManyNumbers(test4.begin(), test4.end());
    
    std::cout << "shortestSpan is: " << test5.shortestSpan() << std::endl;
    std::cout << "longest Span is: " << test5.longestSpan() << std::endl;
}