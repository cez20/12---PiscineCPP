/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/28 11:06:10 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <stdexcept>


int main()
{
	/*
	** --------------------------TESTING INSTANCIATION of NEW FORMS  --------------------------
	*/

	//**** SHRUBERRYCREATIONFORM ****
	Bureaucrat bureaucrat1("Cesar", 100);
	ShrubberyCreationForm shrubbery1("jardin");
	bureaucrat1.signAForm(shrubbery1);
	shrubbery1.execute(bureaucrat1);
	ShrubberyCreationForm shrubbery3 = shrubbery1;
	bureaucrat1.printData();
	shrubbery1.printData();

	
	Bureaucrat bureaucrat2("Robert", 150);
	ShrubberyCreationForm shrubbery2("champs");
	bureaucrat2.signAForm(shrubbery2);
	shrubbery2.execute(bureaucrat2);
	bureaucrat2.printData();
	shrubbery2.printData();

	//*** ROBOTOMYREQUESTFORM ****

	//Bureaucrat
	
	
	/*
	** --------------------------TESTING SIGNATURE AND EXECUTION OF FORM --------------------------
	*/
	// Bureaucrat	bureaucrat2("Robert", 150);
	// ShrubberyCreationForm Form1;
	// bureaucrat2.signAForm(Form1);
	// Form1.execute(bureaucrat2);

	// catch(AForm::GradeTooHighException &e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;	
	// }
	// catch(AForm::GradeTooLowException & e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	// catch(AForm::isNotSigned & e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	// catch(std::exception & e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }

	return (0);
}


