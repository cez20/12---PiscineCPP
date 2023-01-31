/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:33:35 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 08:59:01 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_Class.hpp"

Sample::Sample(float const f): pi (f), qd(42){

	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void){

	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::bar(void) const{

	std::cout << "this->pi: " << this->pi << std::endl;
	std::cout << "this->qd:  " << this->qd << std::endl;
	
}