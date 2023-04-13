/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:51:16 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 13:33:09 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{
	
public:

	Sample(void);
	~Sample(void);

	static int	getNbInst(void); // Fonction NON-MEMBRES qui permet de calculer le nombre d'instance a un moment X 

private:

	static int	_nbInst; // Attribut non-membre qui permet de storer le nombre d'instance a un moment X
};


#endif