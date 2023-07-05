/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/07/05 09:13:47 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define YEL "\e[0;33m"
# define REDB "\e[41m"

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>

int main()
{
	{
		std::cout << GRN"*************************************************************************************" RESET << std::endl;
		std::cout << GRN"*                    TESTING INSTANCIATION AND COPY CONSTRUCTOR                     *" RESET << std::endl;
		std::cout << GRN"*************************************************************************************" RESET << std::endl;

		Form	form1("AG13", 140, 12);
		Form	form2 = form1;
		std::cout << form2;

		try {
			Form form3 ("AG14", 151, 45);
		}

		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Form Exception: " << e.what() << std::endl;	
		}
		catch(Bureaucrat::GradeTooLowException & e)
		{
			std::cout << "Form Exception: " << e.what() << std::endl;
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Form Exception: " << e.what() << std::endl;	
		}
		catch(Form::GradeTooLowException & e)
		{
			std::cout << "Form Exception: " << e.what() << std::endl;
		}
		catch (std::exception e)
		{
			std::cout << "Form Exception: " << e.what() << std::endl;
		}
	}

	{
		std::cout << GRN"*************************************************************************************" RESET << std::endl;
		std::cout << GRN"*                    TESTING BeSigned() and signForm() functions                    *" RESET << std::endl;
		std::cout << GRN"*************************************************************************************" RESET << std::endl;

		try
		{
			Bureaucrat	bureaucrat1("Roger", 100);
			Form		form4("BP13", 99, 99);
			Form		form5("BP14", 100, 130);

			form5.beSigned(bureaucrat1);
			//bureaucrat1.signForm(form4);
		}
	
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Form Exception: " << e.what() << std::endl;	
		}
		catch(Bureaucrat::GradeTooLowException & e)
		{
			std::cout << "Form Exception: " << e.what() << std::endl;
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Form Exception: " << e.what() << std::endl;	
		}
		catch(Form::GradeTooLowException & e)
		{
			std::cout << "Form Exception: " << e.what() << std::endl;
		}
		catch (std::exception e)
		{
			std::cout << "Form Exception: " << e.what() << std::endl;
		}
	}
	return (0);
}
