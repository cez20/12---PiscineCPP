#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class AMateria
{
	protected:
		std::string _type;
	
	public:

		AMateria();
		AMateria(std::string const & type);
		AMateria( AMateria const & src );
		virtual ~AMateria();

		AMateria &		operator=( AMateria const & rhs );

		std::string const & getType() const; //Returns the materia type
		void				setType(std::string const & type);

		virtual AMateria* clone() const = 0;  //Pure method that make the class abstract. Abtract behavior
		//virtual void use(ICharacter& target);
};

#endif /* ******************************************************** AMATERIA_H */