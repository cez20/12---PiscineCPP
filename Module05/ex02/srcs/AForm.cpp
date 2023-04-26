#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(): _name("Default AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	verifyGrade();
	std::cout << "[AForm DEFAULT CONSTRUCTOR] Default constructor is called" << std::endl;
}

AForm::AForm(std::string const name, unsigned int const sign, unsigned int const exec): _name(name), _gradeToSign(sign), _gradeToExecute(exec)
{
	verifyGrade();
	std::cout << "[AForm CONSTRUCTOR W ARGS] Constructor with argument is called" << std::endl;
}


AForm::AForm( const AForm & src ): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	verifyGrade();
	std::cout << "[AForm COPY CONSTRUCTOR] Copy constructor is called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
	std::cout << "[AForm DESTRUCTOR] Destructor is called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
		this->_isSigned = false;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & AForm)
{
	o << "AForm Name: " << AForm.getName() << std::endl;
	o << "AForm is signed: " << AForm.getSignStatus() << std::endl;
	o << "Minimum grade needed for AForm to be signed: " << AForm.getGradeToSign() << std::endl;
	o << "Minimum grade needed for AForm to be executed: " << AForm.getGradeToExecute() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	AForm::verifyGrade() const
{
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw AForm::GradeTooLowException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw AForm::GradeTooHighException();
}

void	AForm::beSigned(Bureaucrat & b)
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
		throw AForm::GradeTooLowException();
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSignStatus() const
{
	return (this->_isSigned);
}

unsigned int AForm::getGradeToSign() const 
{
	return (this->_gradeToSign);
}

unsigned int AForm::getGradeToExecute() const 
{
	return (this->_gradeToExecute);
}

/* ************************************************************************** */