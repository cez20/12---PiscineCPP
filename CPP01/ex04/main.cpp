/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:41:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/30 14:50:15 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char **argv)
{	
	std::ifstream	ifs;
	std::ofstream   ofs;
	std::string		line;
	std::size_t		index;
	
	if (argc == 4)
	{
		ifs.open(argv[1], std::ios_base::in);  // std::ios_base::in always set by default if no mode is mentioned 
		ofs.open("test1.replace"); // Mettre que le fichier doit se vider a chaque fois que le programme se relance 
		if (!ifs || !ofs) // On peut aussi utiliser le ifs.is_open()
			return (-1);
		while (ifs >> line)
		{
			if (line == argv[2])
				line = argv[3];
			line += "\n";
			ofs << line;
		}
		ifs.close(); // Close the input stream
		ofs.close(); // Close the output stream
	}
	else
		std::cout << "Error: your program should take 3 command line arguments";
	return (0);
}


// int main(int argc, char **argv)
// {	
// 	std::ifstream	ifs;
// 	std::ofstream   ofs;
// 	std::string		line;
// 	std::size_t		index;
	
// 	if (argc == 4)
// 	{
// 		ifs.open(argv[1], std::ios_base::in);  // std::ios_base::in always set by default if no mode is mentioned 
// 		if (!ifs) // On peut aussi utiliser le ifs.is_open()
// 			return (-1);
// 		while (std::getline(ifs, line))
// 		{
// 			index = line.find(argv[2], 0); // Looking for s1 inside line 
// 			while(index != std::string::npos)
// 			{
// 				std::cout << "I found a match" << std::endl;
// 				//I must find match and replace it. Manage if string is too long or not
// 				//Copy the line inside the ofstream called 
// 				index = line.find(argv[2], index + 1);
// 			}
// 		}
		
		



// 		ifs.close(); // Close the input stream 
// 	}
// 	else
// 		std::cout << "Error: your program should take 3 command line arguments";
// 	return (0);
// }