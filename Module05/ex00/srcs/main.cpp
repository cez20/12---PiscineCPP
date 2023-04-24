/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/23 19:59:25 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>


int main()
{
	/*
	** --------------------------TESTING INVALID GRADE AT INSTANCIATION --------------------------
	*/
	try
	{
		//Bureaucrat bureaucrat("Cesar", 151);
		Bureaucrat*	bureaucrat1 = new Bureaucrat("Robert", 0);
		
		delete bureaucrat1;
	}

	/*
	** --------------------------- TESTING INCREASE OF ALREADY EXISTING GRADE ----------------------------
	*/
	// try
	// {
	
	// 	Bureaucrat bureaucrat1("Robert", 1);
	// 	bureaucrat1.increaseGrade();
	// }
	
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
	catch (std::exception e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return (0);
}
