/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:46:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/20 17:39:20 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phonebook.hpp"
#include "contact.hpp"

int main()
{
	PhoneBook	phonebook;
	
	while (!std::cin.eof())
	{	
		phonebook.menu_options();
		if (phonebook.choice.compare("ADD") == 0) // Maybe I can use a switch and the case 1, case 2 , etc)
			phonebook.ADD();
		else if (phonebook.choice == "SEARCH")
			phonebook.SEARCH();
		else if (phonebook.choice == "EXIT") // We can also use "relational operators" such as "=" and "!=", but this has to be used with std::string. 
		 	phonebook.EXIT();
		else if (std::cin.eof())
			break;
		else
		{
			std::cout << "\033[31mThis choice is invalid! Choice must be in UPPERCASE. Press ENTER to continue\033[0m" << std::endl;
			std::cin.get();
		}
	}		
	return 0;
}