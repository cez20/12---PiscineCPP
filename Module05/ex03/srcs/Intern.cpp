#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	formDetails[0]._name = "shrubbery creation";
	formDetails[0]._ptrToForm = &Intern::makeShrubberyForm;
	formDetails[1]._name = "robotomy request";
	formDetails[1]._ptrToForm = &Intern::makeRobotomyForm;
	formDetails[2]._name = "presidential pardon";
	formDetails[2]._ptrToForm = &Intern::makePresidentialForm;

	std::cout << "[INTERN DEFAULT CONSTRUCTOR] Default constructor has been called" << std::endl;
}

Intern::Intern( const Intern & src )
{
	std::cout << "[INTERN COPY CONSTRUCTOR] Copy constructor has been called" << std::endl;
	*this = src; 
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << "[INTERN DESTRUCTOR] Default constructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	this->formDetails[0]._name = rhs.formDetails[0]._name;
	this->formDetails[0]._ptrToForm = rhs.formDetails[0]._ptrToForm;
	this->formDetails[1]._name = rhs.formDetails[1]._name;
	this->formDetails[1]._ptrToForm = rhs.formDetails[1]._ptrToForm;
	this->formDetails[2]._name = rhs.formDetails[2]._name;
	this->formDetails[2]._ptrToForm = rhs.formDetails[2]._ptrToForm;

	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm*	Intern::makeForm(std::string const & name, std::string const & target) const
{
	for(int i = 0; i < 3; i++)
	{
		if (this->formDetails[i]._name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*formDetails[i]._ptrToForm)(target);
		}
	}

	std::cout << "Form requested to be created does NOT exist!" << std::endl; 
	return nullptr;
}

AForm*	Intern::makeShrubberyForm(std::string const & target) const
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeRobotomyForm(std::string const & target) const
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makePresidentialForm(std::string const & target) const
{
	return new PresidentialPardonForm(target);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

