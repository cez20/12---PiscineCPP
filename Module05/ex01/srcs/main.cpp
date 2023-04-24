/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/24 18:52:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>


int main()
{
	/*
	** --------------------------TESTING INSTANCIATION AND COPY CONSTRUCTOR  --------------------------
	*/
	// try
	// {
	// 	Form	form2("AG13", 140, 12);
	// 	Form	form3 = form2;

	// 	std::cout << form3;
	// }

	/*
	** --------------------------- TESTING beSigned() and signForm FUNCTION ----------------------------
	*/
	try
	{
		Bureaucrat	bureaucrat1("Roger", 100);
		Form		form4("BP13", 99, 99);
		Form		form5("BP14", 99, 99);

		//form4.beSigned(bureaucrat1);
		//std::cout << form4;
		//bureaucrat1.signForm(form4);
		bureaucrat1.signForm(form5);
	}
	
	/*
	** --------------------------- TESTING DECREASE OF ALREADY EXISTING GRADE  ----------------------------
	*/

	// try
	// {
	// 	Bureaucrat bureaucrat("Cesar", 150);
	// 	bureaucrat.decreaseGrade();
	// }

	/*
	** --------------------------- TESTING INSERTION OPERATOR OVERLOAD  ----------------------------
	*/

	// try
	// {
	// 	Bureaucrat bureaucrat("Cesar", 100);
	// 	bureaucrat.decreaseGrade();
	// 	std::cout << bureaucrat << std::endl;
	// }


	/*
	** --------------------------- CATCHING EXCEPTION BASED ON RIGHT EXCEPTION TYPE  ----------------------------
	*/

	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;	
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	// catch (Form::GradeTooHighException &e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;	
	// }
	// catch(Form::GradeTooLowException & e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	catch (std::exception e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return (0);
}
