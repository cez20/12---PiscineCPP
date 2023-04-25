#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool			  	_isSigned;
		unsigned int const	_gradeToSign;  // grade needed to be able to sign document
		unsigned int const	_gradeToExecute; // grade needed to be able to execute document 

	public:

		Form();
		Form(std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExecute);
		Form( Form const & src );
		virtual ~Form();

		Form &		operator=( Form const & rhs );

		void					verifyGrade() const;
		virtual	void			beSigned(Bureaucrat & b) = 0;

		std::string				getName() const;
		bool					getSignStatus() const;
		unsigned int			getGradeToSign() const;
		unsigned int			getGradeToExecute() const;

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
};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */