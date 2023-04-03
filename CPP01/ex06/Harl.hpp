/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:17:41 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/02 21:23:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl{

	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);

	public:
		Harl();
		void	complain(std::string level);
};
#endif