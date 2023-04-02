/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:20:09 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/02 18:29:26 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	std::cout << "Constructor has been called " << std::endl;
	funcPtr[0] = &Harl::debug;
	funcPtr[1] = &Harl::info;
	funcPtr[2] = &Harl::warning;
 	funcPtr[3] = &Harl::error;
}


void	Harl::complain(std::string level){

	std::string option[4] = {"debug", "info", "warning", "error"};
	
	for (int i = 0; i < 4; i++)
	{
		if (level == option[i])
		{
			(this->*funcPtr[i])();
			return;
		}
	}
	std::cout << "WRONG OPTION: " << std::endl
	          << "Level given is an invalid option!" << std::endl;
}

void	Harl::debug(void){

	std::cout << "DEBUG MESSAGE:" << std::endl;
	std::cout << "I love having extra bacon for my "
	          << "7XL-double-cheese-triple-pickle-special-ketchup-burger. "
			  << "I really do!" << std::endl;
}

void	Harl::info(){

	std::cout << "INFO MESSAGE:" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn't put enough bacon in my burger. If you did "
			  << "I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(){

	std::cout << "WARNING MESSAGE:" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I've been coming for years whereas you started "
			  << "working here since last month." << std::endl;
}

void	Harl::error(){

	std::cout << "ERROR MESSAGE:" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now!" << std::endl;
}