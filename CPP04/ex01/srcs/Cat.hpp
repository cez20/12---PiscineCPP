#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Cat : public Animal{

	public:
		Cat();
		Cat( Cat const & src );
		virtual ~Cat();

		Cat &		operator=( Cat const & rhs );

		virtual void	makeSound() const;

	private:
		Brain* _catPtrToBrain;
};

#endif /* ************************************************************* DOG_H */