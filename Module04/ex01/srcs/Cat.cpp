#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): Animal()
{
	type = "Cat";
	this->_ptrBrain = new Brain();
	std::cout << "[DEFAULT CONSTRUCTOR] Cat default constructor has been called!" << std::endl;
}

Cat::Cat( const Cat & src ): Animal()
{
	this->_ptrBrain = new Brain();
	std::cout << "[COPY CONSTRUCTOR] Cat copy constructor has been called!" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete this->_ptrBrain;
	std::cout << "[DESTRUCTOR] Cat destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
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

void	Cat::makeSound() const
{
	std::cout << "[MAKE SOUND] The Cat says MEOW MEOW!" << std::endl;
}


/* ************************************************************************** */