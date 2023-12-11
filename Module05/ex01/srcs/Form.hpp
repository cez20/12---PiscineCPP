/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:08:46 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/07/05 08:20:14 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

		Form(std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExecute);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		void					verifyGrade() const;
		void					beSigned(Bureaucrat & b);

		std::string const &		getName() const;
		bool					getSignStatus() const;
		unsigned int const &	getGradeToSign() const;
		unsigned int const &	getGradeToExecute() const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()  //(voir Explication plus haut)
				{
					return ("Grade is too HIGH");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()  //(voir Explication plus haut)
				{
					return ("Grade is too LOW");
				}
		};

	private:

		Form();
		std::string const	_name;
		bool			  	_isSigned;
		unsigned int const	_gradeToSign;  // grade needed to be able to sign document
		unsigned int const	_gradeToExecute; // grade needed to be able to execute document 
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */