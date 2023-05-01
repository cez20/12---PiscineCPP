/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:35:04 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/01 19:31:11 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>

int main(int argc, char **argv) {

	if (argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			for (size_t j = 0; j < strlen(argv[i]); j++)
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