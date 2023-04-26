#ifndef ROBOTOMYREQUESTAForm_HPP
# define ROBOTOMYREQUESTAForm_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class RobotomyRequestAForm: public AForm 
{
	private:
		// We will use the private attributes of AForm and access them through getters publicly inherited 
	public:

		RobotomyRequestAForm();
		RobotomyRequestAForm( RobotomyRequestAForm const & src );
		virtual ~RobotomyRequestAForm();

		RobotomyRequestAForm &		operator=( RobotomyRequestAForm const & rhs );

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestAForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTAForm_H */