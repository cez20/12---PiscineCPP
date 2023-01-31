/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:51:11 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/31 16:18:55 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"

int main(){

	char		choice[10];
	Contact		person;
	PhoneBook	iteration;
	
	std::cout << "Please enter one of the following options: ADD, SEARCH or EXIT : " << std::endl;
	std::cin >> choice;

	if (strcmp(choice, "EXIT") == 0)
	{
		std::cout << "Je suis dans la condition EXIT" << std::endl;
		iteration.EXIT();
	}
	else if (strcmp(choice, "ADD") == 0)
	{
		std::cout << "Please enter first name: ";
		std::cin >> person.first_name;
		std::cout << "Please enter last name: ";
		std::cin >> person.last_name;
		std::cout << "Please enter nickname: ";
		std::cin >> person.nickname;
		std::cout << "Please enter darkest secret : ";
		std::cin >> person.darkest_secret;
	}

	//std::cout << "Je n'ai pas exiter le programme " << std::endl;
	return 0;
}