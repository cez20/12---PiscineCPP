/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:31:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/18 22:54:35 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	
	public:

		AMateria();
		AMateria(std::string const & type);
		AMateria( AMateria const & src );
		virtual ~AMateria();

		AMateria &		operator=( AMateria const &);

		std::string const & getType() const; //Returns the materia type
		void				setType(std::string const & type);

		virtual AMateria* clone() const = 0;  //Pure method that make the class abstract. Abtract behavior
		virtual void use(ICharacter& target);
};

#endif /* ******************************************************** AMATERIA_H */