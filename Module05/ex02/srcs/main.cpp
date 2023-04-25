/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/24 22:19:31 by cemenjiv         ###   ########.fr       */
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
	try
	{
		Bureaucrat bureaucrat1;
		Form	form2("AG13", 140, 12);

	
	}


	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;	
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;	
	}
	catch(Form::GradeTooLowException & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return (0);
}
