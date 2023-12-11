/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/07/07 07:39:31 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define YEL "\e[0;33m"
# define REDB "\e[41m"

#include "Intern.hpp"
#include <stdexcept>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                             TESTING INTERN                                        *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* rrf1;
	rrf1 = someRandomIntern.makeForm("shrubbery creation", "Bender");
	AForm* rrf2;
	rrf2 = someRandomIntern.makeForm("presidential pardon", "Bender");
	AForm* rrf3;
	rrf3 = someRandomIntern.makeForm("wrong form", "Bender");

	delete rrf;
	delete rrf1;
	delete rrf2;

	return (0);
}


