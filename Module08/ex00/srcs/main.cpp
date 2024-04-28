/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/04/28 17:38:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int main()
{
    //Container of type list
    std::list<int> list1;

    list1.push_back(1);
    list1.push_back(17);
    list1.push_back(20);

    easyfind(list1, 17);
    easyfind(list1, 0);

    //Container of type vector 
    std::vector<int> list2;

    list2.push_back(45);
    list2.push_back(1159);
    list2.push_back(200);

    easyfind(list2, 17);
    easyfind(list2, 200);

    //Container of type deque
    std::deque<int> list3;

    list3.push_back(1);
    list3.push_back(2);
    list3.push_back(3);
  
    easyfind(list3, 1);
    easyfind(list3, 48);

    //Container of type std::array
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    easyfind(arr, 3);
    easyfind(arr, 7);
}