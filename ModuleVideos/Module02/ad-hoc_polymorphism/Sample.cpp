/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:08:25 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/03 13:14:32 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"
#include <iostream>

Sample::Sample(){
	std::cout << "I am inside constructor" << std::endl;
}

Sample::~Sample(){

	std::cout << "I am inside destructor" << std::endl;
}

void Sample::bar(char c){
	
	std::cout << "I am printing character c: " << c << std::endl;
}

void Sample::bar(int c){
	std::cout << "I am printing int: " << c << std::endl;
}

void Sample::bar (std::string str)
{
	std::cout << "I am printing std::string str: " << str << std::endl;
}