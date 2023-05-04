/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:11:36 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/04 12:39:41 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\e[0m"
# define RED "\e[0;31m"

#include <iostream>
#include <string>

int main()
{
	std::string sentence = "HI THIS IS BRAIN";
	std::string* stringPTR = &sentence;
	std::string& stringREF = sentence; 

	std::cout << RED "Printing the addresses of std::string, pointer to string and reference to string" RESET << std::endl;
	std::cout << "This is the address of the string 'sentence' : " << &sentence << std::endl;
	std::cout << "This is the address of the stringPTR: " << stringPTR << std::endl;
	std::cout << "This is the address of the stringREF: " << &stringREF << std::endl;

	std::cout << RED "\nPrinting the value of each of these variables" RESET;
	std::cout << "\nThe value of the string 'sentence: " << sentence << std::endl;
	std::cout << "The value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value of the stringREF: " << stringREF << std::endl;
	
	return (0);	
}