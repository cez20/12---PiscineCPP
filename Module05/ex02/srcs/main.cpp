/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/07/07 07:10:20 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define YEL "\e[0;33m"
# define REDB "\e[41m"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdexcept>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                             TESTING BUREAUCRAT LEVELS                             *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	try{
		Bureaucrat bureaucrat1("Francis", 151);
	}catch(std::exception & e){
		std::cout << "Exception: " << e.what() << "\n\n";
	}
	
	try{
		Bureaucrat bureaucrat2("Robert", 0);
	}catch(std::exception & e){
		std::cout << "Exception: " << e.what() << "\n\n";
	}

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                             TESTING INSTANCIATION OF SHRUBBERY                    *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	/*
	   -------------------------- TRY AND CATCH ARE INSIDE CLASS INSTEAD OF MAIN -------------
	   Sign: 145
	   Execute: 137
	*/

	{
		Bureaucrat bureaucrat3("Cesar", 137);
		ShrubberyCreationForm shrubbery1("jardin");
		bureaucrat3.signAForm(shrubbery1); //Can be commented to see other error
		bureaucrat3.executeForm(shrubbery1);
		bureaucrat3.printData();
		shrubbery1.printData();
	
		Bureaucrat bureaucrat4("Cesar", 150);
		ShrubberyCreationForm shrubbery2("garden");
		bureaucrat4.signAForm(shrubbery2); //Can be commented to see other error
		bureaucrat4.executeForm(shrubbery2);
		bureaucrat4.printData();
		shrubbery2.printData();
	}

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                             TESTING INSTANCIATION OF ROBOTOMY                     *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	/*
	   Sign: 72
	   Execute: 45
	*/
	{
		Bureaucrat bureaucrat5("Steven", 45);
		RobotomyRequestForm robotomy1("Robot");
		bureaucrat5.signAForm(robotomy1); //Can be commented to see other error
		bureaucrat5.executeForm(robotomy1);
		bureaucrat5.printData();
		robotomy1.printData();
	}

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                    TESTING INSTANCIATION OF PRESIDENTIAL PARDON FORM              *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	/*
	   Sign: 25
	   Execute: 5
	*/

	Bureaucrat bureaucrat7("Maxime", 1);
	PresidentialPardonForm president1("Cesar");
	bureaucrat7.signAForm(president1); //Can be commented to see other error
	bureaucrat7.executeForm(president1);
	bureaucrat7.printData();
	president1.printData();	

	Bureaucrat bureaucrat8("Cesar", 26);
	PresidentialPardonForm president2("Albert");
	bureaucrat8.signAForm(president2); //Can be commented to see other error
	bureaucrat8.executeForm(president2);
	bureaucrat8.printData();
	president2.printData();	
	
	return (0);
}


