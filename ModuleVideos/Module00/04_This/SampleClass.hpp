/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SampleClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:26:28 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/25 18:47:57 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H // Malgre que le fichier finissent en .hpp, on dirait bien que l'on met le ifndef avec un H a la fin. 
# define SAMPLE_CLASS_H

class Sample{ // Nom de la class

public:
	
	int foo;
	
	Sample(void);   // Le nom  de la "class" est toujours utilise pour le CONSTRUCTOR  
	~Sample(void);  // nom de la "class" precede d'un tilder pour DESTRUCTOR

	void	bar(void);
};   // NE JAMAIS OUBLIER DE METTRE LE ';'


#endif 