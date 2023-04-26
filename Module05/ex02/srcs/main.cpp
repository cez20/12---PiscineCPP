/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/26 16:08:02 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <stdexcept>


int main()
{
	/*
	** --------------------------TESTING INSTANCIATION AND COPY CONSTRUCTOR  --------------------------
	*/
	ShrubberyCreationForm shrubbery1("jardin");
	ShrubberyCreationForm shrubbery2 = shrubbery1;
	
	Bureaucrat bureaucrat1("Cesar", 1);
	
	shrubbery1.execute(bureaucrat1);
	

	// try
	// {
	// 	Bureaucrat bureaucrat1;		

	// }


	// catch (Bureaucrat::GradeTooHighException &e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;	
	// }
	// catch(Bureaucrat::GradeTooLowException & e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	// catch (AForm::GradeTooHighException &e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;	
	// }
	// catch(AForm::GradeTooLowException & e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	// catch (std::exception e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	
	return (0);
}
