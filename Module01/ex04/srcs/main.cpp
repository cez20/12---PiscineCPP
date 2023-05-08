/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:41:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/07 20:56:57 by cemenjiv         ###   ########.fr       */
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
	std::ifstream	ifs;  
	std::ofstream   ofs;
	std::string 	output;
	std::string		line;
	std::size_t		index;
	std::size_t		start;

	if (argc != 4)
	{
		std::cout << "Error: your program should take 3 arguments";
		return (-1);
	}

	file = argv[1];
	str1 = argv[2];
	str2 = argv[3];

	if (str1.empty() && str2.empty())
	{
		std::cerr << "Error: The strings have no content";
		return (-1);
	}
	
	ifs.open(file, std::ios_base::in);  // std::ios_base::in always set by default if no mode is mentioned 
	if (!ifs)
	{
		std::cerr << "There is an error with input file!" << std::endl;
		return (-1);
	}
	
	output = file + ".replace";
	ofs.open(output);
	if (!ofs)
	{
		std::cerr << "There is an error with output file!" << std::endl;
		return (-1);
	}

	while (getline(ifs, line))
	{
		start = 0;
		index = line.find(str1); // Looking for str1 inside line.
		while(index != std::string::npos)
		{
			str += replace(line, index, start, str2);
			start = index + (str1.length());
			index = line.find(str1, start);
		}
		str += line.substr(start, line.length() - start);
		ofs << str;
		str.clear();
		ofs << "\n"; // Pas toujours le cas ou il y a un \n
	}
	
	ifs.close();
	ofs.close();

	return (0);
}
