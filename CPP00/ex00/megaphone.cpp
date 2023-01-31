/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 06:57:22 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/31 08:03:05 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring> // library for strlen 
#include <cstdio> // library for putchar 

// int main(int argc, char **argv){

// 	int		i = 1;
// 	int		j = 0;
// 	//int		character; Only to be used to store content of to_upper if do not want to use typecast
	
// 	if (argc > 1)
// 	{
// 		while (i < argc)
// 		{
// 			j = 0;
// 			while (argv[i][j])
// 			{
// 				std::cout << (char)toupper(argv[i][j]);
// 				j++;
// 			}
// 			if (argv[i + 1])
//       			std::cout << ' ';
// 			i++;
// 		}
// 	}
// 	else
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
// 	std::cout << std::endl;
// 	return 0;
// }

int main(int argc, char **argv) {

	if (argc > 1)
	{
		for(int i=1; i < argc; i++)
		{
			for (int j=0; j < strlen(argv[i]); j++)
				putchar(toupper(argv[i][j]));
			if (argv[i + 1])
      			std::cout << ' ';
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}