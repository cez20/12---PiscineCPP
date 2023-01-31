/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:51:16 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 11:44:56 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{
	
public:

	Sample(int v);
	~Sample(void);

	int	getFoo(void) const;
	int	compare(Sample * other)	const; // Parametre prend un pointeur vers un instance de Sample(peu importe laquelle)

	//compare l'instance courante avec celle passe en parametre 

private:

	int	_foo;
};


#endif