#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): _name("Default form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	verifyGrade();
	std::cout << "[FORM DEFAULT CONSTRUCTOR] Default constructor is called" << std::endl;
}

Form::Form(std::string const name, unsigned int const sign, unsigned int const exec): _name(name), _gradeToSign(sign), _gradeToExecute(exec)
{
	verifyGrade();
	std::cout << "[FORM CONSTRUCTOR W ARGS] Constructor with argument is called" << std::endl;
}


Form::Form( const Form & src ): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	verifyGrade();
	std::cout << "[FORM COPY CONSTRUCTOR] Copy constructor is called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "[FORM DESTRUCTOR] Destructor is called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
		this->_isSigned = false;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & form)
{
	o << "Form Name: " << form.getName() << std::endl;
	o << "Form is signed: " << form.getSignStatus() << std::endl;
	o << "Minimum grade needed for Form to be signed: " << form.getGradeToSign() << std::endl;
	o << "Minimum grade needed for Form to be executed: " << form.getGradeToExecute() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::verifyGrade() const
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw Form::GradeTooLowException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw Form::GradeTooHighException();
}

void	Form::beSigned(Bureaucrat & b)
{
	if (b.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = true;
		std::cout << b.getName() << " signed " << this->_name << std::endl;
	}
	else
	{
		std::cout << b.getName() << " couldn't signed " << this->_name 
		<< " because its grade was too low!" << std::endl;
		throw Form::GradeTooLowException();
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const
{
	return (this->_name);
}

bool	Form::getSignStatus() const
{
	return (this->_isSigned);
}

unsigned int Form::getGradeToSign() const 
{
	return (this->_gradeToSign);
}

unsigned int Form::getGradeToExecute() const 
{
	return (this->_gradeToExecute);
}

/* ************************************************************************** */