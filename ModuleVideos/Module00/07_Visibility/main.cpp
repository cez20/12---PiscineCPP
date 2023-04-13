/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:55:06 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 10:07:12 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_Class.hpp"

int main () {

	Sample	instance;

	instance.publicFoo = 100;
	std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;
	
	instance._privateFoo = 200;
	std::cout << "instance._privateFoo: " << instance._privateFoo << std::endl;


	instance.publicBar();
	instance._privateBar();


	return 0;

}