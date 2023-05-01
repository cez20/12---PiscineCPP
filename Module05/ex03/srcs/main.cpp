/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/01 17:04:28 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <stdexcept>
#include <cstdlib>
#include <ctime>


int main()
{
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


