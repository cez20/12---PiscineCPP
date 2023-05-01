/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/01 11:48:37 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <stdexcept>
#include <cstdlib>
#include <ctime>


int main()
{
	/*
	** --------------------------TESTING BUREAUCRAT LEVELS --------------------------
	*/

	// try{
	// 	Bureaucrat bureaucrat1("Francis", 151);
	// }catch(std::exception & e){
	// 	std::cout << "Exception: " << e.what() << "\n\n";
	// }
	
	// try{
	// 	Bureaucrat bureaucrat2("Robert", 0);
	// }catch(std::exception & e){
	// 	std::cout << "Exception: " << e.what() << "\n\n";
	// }

	// /*
	// ** --------------------------TESTING INSTANCIATION of NEW FORMS  --------------------------
	//    -------------------------- TRY AND CATCH ARE INSIDE CLASS INSTEAD OF MAIN -------------
	// */

	// //**** SHRUBERRYCREATIONFORM ****
	// Bureaucrat bureaucrat3("Cesar", 100);
	// ShrubberyCreationForm shrubbery1("jardin");
	// bureaucrat3.signAForm(shrubbery1); //Can be commented to see other error
	// bureaucrat3.executeForm(shrubbery1);
	// bureaucrat3.printData();
	// shrubbery1.printData();		

	// //**** ROBOTOMYREQUESTFORM ****
	// Bureaucrat bureaucrat4("Steven", 70);
	// RobotomyRequestForm robotomy1("robot");
	// bureaucrat4.signAForm(robotomy1); //Can be commented to see other error
	// bureaucrat4.executeForm(robotomy1);
	// bureaucrat4.printData();
	// robotomy1.printData();	

	// //**** PRESIDENTIAL PARDON FORM ****
	// Bureaucrat bureaucrat5("Maxime", 1);
	// PresidentialPardonForm president1("presidente");
	// bureaucrat5.signAForm(president1); //Can be commented to see other error
	// bureaucrat5.executeForm(president1);
	// bureaucrat5.printData();
	// president1.printData();	

	//**** INTERN PART  ****
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* rrf1;
	rrf1 = someRandomIntern.makeForm("shrubbery creation", "Bender");
	AForm* rrf2;
	rrf2 = someRandomIntern.makeForm("presidential pardon", "Bender");

	delete rrf;
	delete rrf1;
	delete rrf2;

	return (0);
}


