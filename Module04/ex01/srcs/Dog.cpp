#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): Animal()
{
	type = "Dog";
	this->_ptrBrain = new Brain();
	std::cout << "[DEFAULT CONSTRUCTOR] Dog default constructor has been called!" << std::endl;
}

Dog::Dog( const Dog & src ): Animal()
{
	this->_ptrBrain = new Brain();
	std::cout << "[COPY CONSTRUCTOR] Dog copy constructor has been called!" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->_ptrBrain;
	std::cout << "[DESTRUCTOR] Dog destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "[OPERATOR OVERLOAD] Cat Equal operator overload has been called!" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		for (size_t i = 0; i < 100; ++i) {
       	 _ptrBrain->setIdea(rhs._ptrBrain->getIdea(i), i);
    }
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound() const
{
	std::cout << "[MAKE SOUND] The Dog says WOOF WOOF!" << std::endl;
}


/* ************************************************************************** */