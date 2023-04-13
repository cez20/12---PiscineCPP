#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
#include <iostream>

class Cat : public Animal{

	public:
		Cat();
		Cat( Cat const & src );
		virtual ~Cat();

		Cat &		operator=( Cat const & rhs );

		virtual void	makeSound() const;
};

#endif /* ************************************************************* DOG_H */