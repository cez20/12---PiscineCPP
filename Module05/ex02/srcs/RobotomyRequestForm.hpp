#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class	Bureaucrat;

class RobotomyRequestForm: public AForm 
{
	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		virtual void			execute (Bureaucrat const & executor) const;
};

#endif /* ********************************************* RobotomyRequestForm_H */