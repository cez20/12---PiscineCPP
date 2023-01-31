/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 13:32:40 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_Class.hpp"

void f0(void){

	Sample	instance;
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	return;
}


void f1(void){
	
	Sample	instance;
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	f0();
	return;
}

int main(){

	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;
	f1();
	std::cout << "Number of instances: " << Sample::getNbInst() << std::endl;

	return 0;
}