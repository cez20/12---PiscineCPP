/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:41:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/30 22:41:41 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replace(std::string line, std::size_t index, int start, std::string& str2)
{
	std::string str;
	str = line.substr(start, index - start);
	str += str2;
	return (str);
}

int main(int argc, char **argv)
{	
	std::string		file;
	std::string		str;
	std::string		str1;
	std::string		str2;
	std::ifstream	ifs;  // Create the input stream 
	std::ofstream   ofs;  // Will contain the output stream
	std::string 	output;
	std::string		line;
	std::size_t		index;
	std::size_t		start;

	if (argc != 4)
	{
		std::cout << "Error: your program should take 3 command line arguments";
		return (-1);
	}

	file = argv[1];
	str1 = argv[2];
	str2 = argv[3];

	if (str1.empty() && str2.empty())
	{
		std::cout << "Error: The string have no content";
		return (-1);
	}
	
	output = file + ".replace";

	ifs.open(file, std::ios_base::in);  // std::ios_base::in always set by default if no mode is mentioned 
	ofs.open(output);
	if (!ifs)
	{
		std::cout << "Il y a une erreur avec ifs ou ofs" << std::endl;
		return (-1);
	}

	while (getline(ifs, line))
	{
		start = 0;
		index = line.find(str1); // Looking for str1 inside line.
		while(index != std::string::npos)
		{
			str = replace(line, index, start, str2);
			ofs << str;
			start = index + (str1.length());
			index = line.find(str1, start);
			if (index == std::string::npos)
			{
				str = line.substr(start, line.length() - start);
				ofs << str;
			}
		}
		std::cout << std::endl;
		ofs << "\n"; // Valider que 
	}
	ifs.close(); // Close the input stream 
	ofs.close();

	return (0);
}
