/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/11/11 18:12:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main( void ) {

    {
    Array<int> array1;
    Array<int> array2(5);

    Array<int> array3 = array2;

    array2.print_array();
    array3.print_array();

    array2.modify_array_value(2, -1);
    array2.print_array();
    array3.print_array();

    std::cout << "The number of elements inside the array is: " << array1.size() << std::endl;
    std::cout << "The number of elements inside the array is: " << array2.size() << std::endl;
    std::cout << "The number of elements inside the array is: " << array3.size() << std::endl;
    }

    {
        Array<double> array1;
        Array<double> array2(5);

        Array<double> array3 = array2;

        array2.print_array();
        array3.print_array();

        array2.modify_array_value(2, 42.0);
        array2.print_array();
        array3.print_array();

        std::cout << "The number of elements inside the array is: " << array1.size() << std::endl;
        std::cout << "The number of elements inside the array is: " << array2.size() << std::endl;
        std::cout << "The number of elements inside the array is: " << array3.size() << std::endl;  
    }

    return 0;
}