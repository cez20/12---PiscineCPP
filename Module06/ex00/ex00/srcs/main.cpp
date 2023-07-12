/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/07/11 22:28:49 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Scalar.hpp"
#include <cctype>


int main (int argc, char **argv)
{
	if (argc > 2) {
        std::cerr << "Too many arguments" << std::endl;
        return 1;
    }
    if (argc != 2) {
        std::cerr << "Tho launch this program: ./convert <arg> " << std::endl;
        return 1;
    }

    //Transforming the char* argv[1] into a std::string. 
	std::string input = argv[1];
    if (input.empty())
        std::cerr << "argv[1] is an empty string" << std::endl;

    Scalar  conversion(input);


	return (0);
}