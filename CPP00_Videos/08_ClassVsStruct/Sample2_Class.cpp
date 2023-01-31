/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample2_Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:31:08 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 10:36:32 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample2_Class.hpp"

Sample2::Sample2(void){

	std::cout << "Constructor" << std::endl;
	return;
}

Sample2::~Sample2(void){

	std::cout << "Destructor" << std::endl;
	return;
}