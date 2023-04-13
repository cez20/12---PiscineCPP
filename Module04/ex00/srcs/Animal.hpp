#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	public:
		Animal();
		Animal( Animal const & src );
		virtual	~Animal();

		Animal &		operator=( Animal const & rhs );

		std::string			getType() const; // const must be after
		virtual	void		makeSound() const;

	protected:
		std::string type;

};

#endif /* ********************************************************** ANIMAL_H */