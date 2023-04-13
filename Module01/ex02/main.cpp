/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:11:36 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/27 15:22:22 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string sentence = "HI THIS IS BRAIN";
	std::string* stringPTR = &sentence;
	std::string& stringREF = sentence; 

	// Prints the addresses of each elements 
	std::cout << "This is the address of the string 'sentence: " << &sentence << std::endl;
	std::cout << "This is the address of the stringPTR: " << stringPTR << std::endl;
	std::cout << "This is the address of the stringREF: " << &stringREF << std::endl;

	// Prints the value of each string
	std::cout << "\nThe value of the string 'sentence: " << sentence << std::endl;
	std::cout << "The value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value of the stringREF: " << stringREF << std::endl;
	
	return (0);	
}