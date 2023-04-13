/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample1_Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:30:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 10:34:56 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample1_Class.hpp"


Sample1::Sample1(void){

	std::cout << "Constructor" << std::endl;
	return;
}

Sample1::~Sample1(void){

	std::cout << "Destructor" << std::endl;
	return;
}