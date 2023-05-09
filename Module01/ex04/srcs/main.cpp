/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:41:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/08 20:34:04 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceString(std::string line, size_t str_position, int index, std::string & str2)
{
	std::string new_string;
	
	new_string = line.substr(index, str_position - index);
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
	size_t			str_position;

	if (argc != 4)
	{
		std::cout << "Error: your program should take 3 arguments";
		return (-1);
	}

	file = argv[1];
	str1 = argv[2];
	str2 = argv[3];

	if (str1.empty() || str2.empty())
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
		index = 0;
		str_position = line.find(str1);
		while(str_position != std::string::npos)
		{
			str_tmp += replaceString(line, str_position, index, str2);
			index = str_position + (str1.length());
			str_position = line.find(str1, index);
		}
		str_tmp += line.substr(index, line.length() - index);
		ofs << str_tmp;
		if (!ifs.eof())
			ofs << "\n";
	}
	
	ifs.close();
	ofs.close();

	return (0);
}
