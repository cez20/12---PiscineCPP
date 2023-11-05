/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:29:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/11/05 15:31:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serialize.hpp"


int main ()
{
    // Create one object based on the struct Data 
    Data data1;
    data1.letter = 'c';
    data1.number = 42;
    data1.name = "Cesar";
    data1.isData = "true";
    
    // Print content of struct Data 
    std::cout << "Address of Data object is: " << &data1 << std::endl;
    std::cout << "Letter: " <<  data1.letter << std::endl;
    std::cout << "Number is: " << data1.number << std::endl;
    std::cout << "Name is: " << data1.name << std::endl;
    std::cout << "Bool is: " << data1.isData << "\n" << std::endl;


    Serialize object1;
    uintptr_t test1 = object1.serialize(&data1);

    std::cout << "Address of Data object once serialize to uintptr_t:" << test1 << "\n" << std::endl;
    // std::cout << test1.letter << std::endl;
    // std::cout << test1.number << std::endl;

    Data* test2 = object1.deserialize(test1);
    std::cout << "Address of data object is: " << test2 << std::endl;
    std::cout << "Letter: " <<  test2->letter << std::endl;
    std::cout << "Number is: " << test2->number << std::endl;
    std::cout << "Name is: " << test2->name << std::endl;
    std::cout << "Bool is: " << test2->isData << "\n" << std::endl;
    
    return (0);
}