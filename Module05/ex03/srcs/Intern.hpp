#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern
{
	private:
		struct	Forms
		{
			std::string 	_name;
			AForm* 			(Intern::*_ptrToForm)(std::string const &) const; 
		}  formDetails[3];
		
	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		AForm* 			makeForm(std::string const & name, std::string const & target) const;
		AForm*			makeShrubberyForm(std::string const & target) const;
		AForm*			makeRobotomyForm(std::string const & target) const;
		AForm*			makePresidentialForm(std::string const & target) const;
};

//std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */