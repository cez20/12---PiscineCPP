/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:18:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/13 15:19:03 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap 
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap( FragTrap const & src );
	~FragTrap();

	FragTrap &	operator=( FragTrap const & rhs );

	void highFiveGuys(void);
};

#endif /* ******************************************************** FRAGTRAP_H */