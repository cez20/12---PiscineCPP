#ifndef PRESIDENTIALPARDONAForm_HPP
# define PRESIDENTIALPARDONAForm_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonAForm : public AForm
{
	private:
		// We will use the private attributes of AForm and access them through getters publicly inherited 

	public:

		PresidentialPardonAForm();
		PresidentialPardonAForm( PresidentialPardonAForm const & src );
		virtual ~PresidentialPardonAForm();

		PresidentialPardonAForm &		operator=( PresidentialPardonAForm const & rhs );



};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonAForm const & i );

#endif /* ****************************************** PRESIDENTIALPARDONAForm_H */