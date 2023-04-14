/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:27:14 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/14 12:07:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Dog : public AAnimal{

	public:
		Dog();
		Dog( Dog const & src );
		virtual ~Dog();

		Dog &		operator=( Dog const & rhs );

		virtual void	makeSound() const;
		Brain*			getBrain();

	private:
		Brain* _ptrBrain;
};

#endif /* ************************************************************* DOG_H */