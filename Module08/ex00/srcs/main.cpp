/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/11/23 20:47:03 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <list>

int main()
{
    std::list<int> list1;

    list1.push_back(1);
    list1.push_back(17);
    list1.push_back(20);

    easyfind(list1, 17);
  
}