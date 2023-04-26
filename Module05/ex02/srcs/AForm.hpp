#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool			  	_isSigned;
		unsigned int const	_gradeToSign;  // grade needed to be able to sign document
		unsigned int const	_gradeToExecute; // grade needed to be able to execute document 

	public:

		AForm();
		AForm(std::string const name, unsigned int const gradeToSign, unsigned int const gradeToExecute);
		AForm( AForm const & src );
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		virtual void			execute (Bureaucrat const & executor) const = 0;
		void					verifyGrade() const;
		void					beSigned(Bureaucrat & b);

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

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AForm_H */