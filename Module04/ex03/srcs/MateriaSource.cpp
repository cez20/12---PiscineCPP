#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = nullptr;
	std::cout << "[DEFAULT CONSTRUCTOR] MateriaSource default constructor has been called " << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	std::cout << "[COPY CONSTRUCTOR] MateriaSource default constructor has been called " << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = nullptr;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete _materias[i];
	std::cout << "[DESTRUCTOR] MateriaSource default constructor has been called " << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_materias[i];
		if (rhs._materias[i])
			this->_materias[i] = rhs._materias[i]->clone();
		else
			this->_materias[i] = nullptr;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	MateriaSource::learnMateria(AMateria * m)
{
	int index = 0;
	
	while (index < 4 && _materias[index] != nullptr)
		index++;
	if (index >= 4)
		delete m; // J'efface le AMateria passe en parametre, car
	else
		_materias[index] = m;

}

AMateria*  MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0;i < 4; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			return this->_materias[i]->clone();
		}
	}
	return (nullptr);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */