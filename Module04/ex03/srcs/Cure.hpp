/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:32:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/21 13:24:57 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:
		Cure();
		Cure(std::string & type);
		Cure( Cure const & src );
		virtual ~Cure();

		Cure &		operator=( Cure const & rhs );

		virtual AMateria* clone() const;  // Dois-je mettre Cure* clone() ici ou Amateria est suffisant?
		virtual void use(ICharacter& target);

};

#endif /* ************************************************************ CURE_H */