/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/11/11 15:10:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"

int main( void ) {
    
    int array[3] = {1, 2, 3};
    char array1[4] = {'a', 'b', 'c', 'd'};
    std::string array2[3] = {"Cesar", "Ana", "Morgan"};

    iter(array, 3, print_content);
    iter(array1, 4, print_content);
    iter(array2, 3, print_content);
    
    return 0;
}