#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat
{
	public:

		Bureaucrat(std::string const name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string const &		getName() const;
		unsigned int const &	getGrade() const;
		void					increaseGrade();
		void					decreaseGrade();

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

		Bureaucrat();
		std::string	const	_name;
		unsigned int		_grade;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */