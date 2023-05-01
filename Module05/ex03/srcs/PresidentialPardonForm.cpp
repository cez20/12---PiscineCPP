#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm(): AForm ("Presidential", "target", 25, 5)
{
	std::cout << "[PRESIDENTIAL DEFAULT CONSTRUCTOR] Constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential", target, 25, 5)
{
	std::cout << "[PRESIDENTIAL CONSTRUCTOR W/ ARG] Constructor has been called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
: AForm("Presidential", src.getTarget(), 25, 5)
{
	std::cout << "[PRESIDENTIAL COPY CONSTRUCTOR] Constructor has been called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PRESIDENTIAL DESTRUCTOR] Destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	isFormExecutable(executor);
    std::cout << getTarget() << " has been forgiven by Zaphod Beeblebrow" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */