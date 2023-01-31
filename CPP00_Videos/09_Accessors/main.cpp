/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 11:03:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_Class.hpp"

int main(){

	Sample	instance;

	instance.setFoo(42);
	std::cout << "instance.getFoo:" << instance.getFoo() << std::endl;
	
	instance.setFoo(-42);
	std::cout << "instance.getFoo:" << instance.getFoo() << std::endl;
	
	return 0;
}