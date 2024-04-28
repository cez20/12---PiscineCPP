/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/04/28 14:34:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <vector>  //A enlever 

int main()
{
    //Exemple inside module
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(1);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // MaxCapacityReached exception 
    
    Span test(3);

    test.addNumber(-2147483648);
    test.addNumber(0);
    test.addNumber(2147483647);

    std::cout << "shortestSpan is: " << test.shortestSpan() << std::endl;;
    std::cout << "longestSpan is: " << test.longestSpan() << std::endl;

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
    
    test2.addNumber(100);
    
    try{
       test2.shortestSpan();
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    Span test3(3);
    
    test3.addNumber(100);
    try{
        test3.longestSpan();
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    // Testing shortest and longest range with 10000 numbers 

    srand(static_cast<int>(time(NULL)));

    std::vector<int> test4;
    for (std::size_t i = 0; i < 10000; ++i) {
        test4.push_back(rand());
    }

    Span test5(10000);
    try{
        test5.addManyNumbers(test4.begin(), test4.end());
    }catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "shortestSpan is: " << test5.shortestSpan() << std::endl;
    std::cout << "longest Span is: " << test5.longestSpan() << std::endl;
    
   
}