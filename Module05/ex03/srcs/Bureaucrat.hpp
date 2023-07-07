#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string	const	_name;
		unsigned int		_grade;

	public:

		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string		getName() const;
		unsigned int	getGrade() const;
		void			increaseGrade();
		void			decreaseGrade();
		void			signAForm(AForm & f);
		void			executeForm(AForm const & form);
		void			printData() const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too HIGH");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too LOW");
				}
		};
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */