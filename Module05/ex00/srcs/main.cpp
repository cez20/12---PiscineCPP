/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/07/03 12:02:32 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define YEL "\e[0;33m"
# define REDB "\e[41m"

#include "Bureaucrat.hpp"

int main()
{
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                          GRADE TOO HIGH / GRADE TOO LOW                           *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	{
		try{
			Bureaucrat("Robert", 0);	
		} catch (Bureaucrat::GradeTooHighException &e){
			std::cout << "Exception: " << e.what() << std::endl;	
		}
		catch(Bureaucrat::GradeTooLowException & e){
			std::cout << "Exception: " << e.what() << std::endl;
		}
		catch (std::exception e){
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		try{
			Bureaucrat("Robert", 151);	
		} catch (Bureaucrat::GradeTooHighException &e){
			std::cout << "Exception: " << e.what() << std::endl;	
		}
		catch(Bureaucrat::GradeTooLowException & e){
			std::cout << "Exception: " << e.what() << std::endl;
		}
		catch (std::exception e){
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                          GRADE DECREASE/ GRADE INCREASE                           *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	{
		try{
			Bureaucrat bureaucrat1("Robert", 1);
			bureaucrat1.increaseGrade();
		} catch (Bureaucrat::GradeTooHighException &e){
			std::cout << "Exception: " << e.what() << std::endl;	
		}
		catch(Bureaucrat::GradeTooLowException & e){
			std::cout << "Exception: " << e.what() << std::endl;
		}
		catch (std::exception e){
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		try{
			Bureaucrat bureaucrat("Cesar", 150);
			bureaucrat.decreaseGrade();
		}catch (Bureaucrat::GradeTooHighException &e){
			std::cout << "Exception: " << e.what() << std::endl;	
		}
		catch(Bureaucrat::GradeTooLowException & e){
			std::cout << "Exception: " << e.what() << std::endl;
		}
		catch (std::exception e){
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
	std::cout << GRN"*                          TESTING INSERTION OPERATOR OVERLOAD                      *" RESET << std::endl;
	std::cout << GRN"*************************************************************************************" RESET << std::endl;

	Bureaucrat bureaucrat("Cesar", 100);
	std::cout << bureaucrat << std::endl;

	return (0);
}
