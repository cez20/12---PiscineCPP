#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{
	private:
	
	public:

		Ice();
		Ice(std::string &type);
		Ice( Ice const & src );
		~Ice();

		Ice &		operator=( Ice const & rhs );

		virtual AMateria* clone() const;  // Dois-je mettre Ice* clone() ici ou Amateria est suffisant?
		//virtual void use(ICharacter& target);

};

#endif /* ************************************************************* ICE_H */