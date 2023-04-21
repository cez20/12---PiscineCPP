/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:32:50 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/21 13:25:06 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		virtual ~Ice();

		Ice &		operator=( Ice const & rhs);

		virtual AMateria* clone() const;  // Dois-je mettre Ice* clone() ici ou Amateria est suffisant?
		virtual void use(ICharacter& target);
};

#endif /* ************************************************************* ICE_H */