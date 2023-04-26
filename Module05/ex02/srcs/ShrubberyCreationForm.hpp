#ifndef SHRUBBERYCREATIONAForm_HPP
# define SHRUBBERYCREATIONAForm_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationAForm: public AForm
{
	private:
		// We will use the private attributes of AForm and access them through getters publicly inherited 
	public:

		ShrubberyCreationAForm();
		ShrubberyCreationAForm( ShrubberyCreationAForm const & src );
		virtual ~ShrubberyCreationAForm();

		ShrubberyCreationAForm &		operator=( ShrubberyCreationAForm const & rhs );
};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationAForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONAForm_H */