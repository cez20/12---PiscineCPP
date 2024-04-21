/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:54:36 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/02/27 20:46:16 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
// #include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{   
    if (argc != 2)
    {
        std::cerr << "Error: program has no arguments or too many arguments." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ifstream newfile;
    // newfile.open("../input.txt");
    newfile.open(argv[1]);
    if (newfile.fail())
    {
        std::cerr << "Error: could not open file" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::string x1, x2, x3;
    
    while (true)
    {
        newfile >> x1 >> x2 >> x3;
        if (newfile.eof())
            break;
        else
            std::cout << x1 << " " << x2 << " " << x3 << std::endl;
    }

    newfile.close();

    return 0;
}