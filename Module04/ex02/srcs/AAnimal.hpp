/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:26:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/14 10:19:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal( AAnimal const & src );
		virtual	~AAnimal();

		AAnimal &		operator=( AAnimal const & rhs );

		std::string			getType() const; // const must be after
		virtual	void		makeSound() const = 0;

	protected:
		std::string type;

};

#endif /* ********************************************************** AAnimal_H */