/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:46:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/01 19:41:45 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
	
	while (!std::cin.eof())
	{	
		phonebook.display_options();
		if (phonebook.choice.compare("ADD") == 0)
			phonebook.add();
		else if (phonebook.choice == "SEARCH")
			phonebook.search();
		else if (phonebook.choice == "EXIT") 
		 	break;
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