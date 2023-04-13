/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filestream.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:58:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/23 15:41:42 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> // fstream means filestream

//ifs means input file stream; 
//ofs means output file stream 
//Je peux creer un stream en utilisant std::ifstream et je peux lire du contenu
// a partir de ce stream comme je le ferais avec std::cin << 

// We can also read from file by doing: 
	//getline (file from which I read, file in which I put content)
	//line = file.get() will also allows you to put content inside line.  
	//file.is_open() // condition to see if input stream open correctly. 


int main()
{
	std::ifstream	ifs("numbers"); //numbers represents the file to open. 
	unsigned int	dst;
	unsigned int	dst2;
	ifs >> dst >> dst2; // I put content I read inside these variables. First number in dst, second number in dst 

	std::cout << dst << " " << dst2 << std::endl;
	ifs.close();

	
	//----------------------

	std::ofstream	ofs("test.out"); // Create an output stream named test.out in which I put content

	ofs << "i like ponies a whole damn lot" << std::endl; // Inset string inside output stream
	ofs.close();
}