/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:41:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/08 20:59:53 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceString(std::string line, int current_index, size_t str_position, std::string & str_replacement)
{
	std::string initial_content;
	std::string new_content;
	
	initial_content = line.substr(current_index, (str_position - current_index));
	new_content = (initial_content + str_replacement);
	return (new_content);
}

int main(int argc, char **argv)
{	
	std::string		file;
	std::string		str1;
	std::string		str2;
	std::ifstream	ifs;  
	std::ofstream   ofs;
	std::string 	output;
	std::string		line;
	std::string		new_line;
	size_t			current_index;
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
		new_line.clear();
		current_index = 0;
		str_position = line.find(str1);
		while(str_position != std::string::npos)
		{
			new_line += replaceString(line, current_index, str_position, str2);
			current_index = str_position + (str1.length());
			str_position = line.find(str1, current_index);
		}
		new_line += line.substr(current_index, line.length() - current_index);
		ofs << new_line;
		if (!ifs.eof())
			ofs << "\n";
	}
	
	ifs.close();
	ofs.close();

	return (0);
}
