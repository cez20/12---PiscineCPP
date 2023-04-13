/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 06:57:22 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/15 14:35:03 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Library to use cout and cint 
#include <cctype>  // Library to use "toupper" - Convert lowercase to uppercase 
#include <cstring> // library for strlen 
#include <cstdio> // library for putchar 

// (DONE)Function must take all command-line string and transform them from lowercase to uppercase
// (DONE)All command-line string must be displayed on the same line and then end with a newline 
// (DONE)If no-command-line string , display ("* LOUD AND UNBEARABLE FEEDBACK NOISE *")
// Exclamation mark (!) at the end of a string is perceive a a negation operator. If we want to use it
// use the escape character before (ex: ./megaphone "Hello Cesar\!")


int main(int argc, char **argv) {

	if (argc > 1)
	{
		for(int i = 1; i < argc; i++)
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