/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/26 11:20:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <stdexcept>


int main()
{
	/*
	** --------------------------TESTING INSTANCIATION AND COPY CONSTRUCTOR  --------------------------
	*/
	try
	{
		Bureaucrat bureaucrat1;
		//AForm	AForm2("AG13", 140, 12);

	
	}


	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;	
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;	
	}
	catch(AForm::GradeTooLowException & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return (0);
}
