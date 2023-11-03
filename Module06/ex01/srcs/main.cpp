/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:29:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/11/01 21:19:27 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serialize.hpp"


int main ()
{
    // Create one object of type Data 
    Data data1;
    data1.letter = 'c';
    data1.number = 42;
    data1.name = "Cesar";
    data1.isData = "true";

    std::cout << "Address of data pointer is: " << &data1 << std::endl;
    std::cout << data1.letter << std::endl;
    std::cout << data1.number << std::endl;
    std::cout << data1.name << std::endl;
    std::cout << data1.isData << std::endl;

    Serialize object1;
    uintptr_t test1 = object1.serialize(&data1);
    Data* test2 = object1.deserialize(test1);

    std::cout << "Address of data pointer is: " << test2 << std::endl;
    std::cout << test1 << std::endl;

    std::cout << "Address of data pointer is: " << test2 << std::endl;
    std::cout << test2->letter << std::endl;
    std::cout << test2->number << std::endl;
    std::cout << test2->name << std::endl;
    std::cout << test2->isData << std::endl;

    return (0);
}