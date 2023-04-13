/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:55:32 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/27 12:45:26 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_Class.hpp"

Sample::Sample(void): foo(0) {

	std::cout << "Constructor called " << std::endl;
	return;
}

Sample::~Sample(void){

	std::cout << "Destructor called " << std::endl;
	return;
}

void	Sample::bar(void)	const{

	std::cout << "Member function Bar called" << std::endl;
	return;
}