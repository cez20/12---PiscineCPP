/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:20:09 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/31 12:28:19 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::complain(std::string level){

	if (level == "debug")
		debug();
	else if (level == "info")
		info();
	else if (level == "warning")
		warning();
	else if (level == "error")
		error();
}

void	Harl::debug(){

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup-burger! I really do." << std::endl;
}

void	Harl::info(){

	std::cout << "I think IK deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last mont" << std::endl;
}

void	Harl::warning(){

	std::cout << "I think I deserve some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(){

	std::cout << "This is unacceptable! I want to speak to the manager now.!" << std::endl;
}