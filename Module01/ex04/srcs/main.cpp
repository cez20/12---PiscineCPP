/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:41:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/08 07:55:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceString(std::string line, size_t index, int start, std::string & str2)
{
	std::string new_string;
	
	new_string = line.substr(start, index - start);
	new_string += str2;
	return (new_string);
}

int main(int argc, char **argv)
{	
	std::string		file;
	std::string		str1;
	std::string		str2;
	std::string		str_tmp;
	std::ifstream	ifs;  
	std::ofstream   ofs;
	std::string 	output;
	std::string		line;
	size_t			index;
	size_t			start;

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
	
	ifs.open(file, std::ios_base::in);
	if (!ifs)
	{
		std::cerr << "There is an error with input file!" << std::endl;
		return (-1);
	}
	
	output = file + ".replace";
	ofs.open(output, std::ios::out);
	if (!ofs)
	{
		std::cerr << "There is an error with output file!" << std::endl;
		return (-1);
	}

	while (getline(ifs, line))
	{
		str_tmp.clear();
		start = 0;
		index = line.find(str1);
		while(index != std::string::npos)
		{
			str_tmp += replaceString(line, index, start, str2);
			start = index + (str1.length());
			index = line.find(str1, start);
		}
		str_tmp += line.substr(start, line.length() - start);
		ofs << str_tmp;
		if (!ifs.eof())
			ofs << "\n";
	}
	
	ifs.close();
	ofs.close();

	return (0);
}
