/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:44:26 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/03 16:15:42 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Les 4 elements avec des commentaires font de cette classe, une class
// ayant la forme canonique de Coplien 

// **DORENAVANT toutes les classes doivent etre sous forme canonique. 
//		1- Constructeur par default
//		2- Constructor par copie
//		3- Destructor
//		4- Un operateur d'assignation 

class Sample{

private:
	int _foo;

public:
	Sample(void);					// Default constructor 
	Sample (int const n);
	Sample (Sample const & src);    // Constructor making a copy of instance (object) = appele Constructor par copie
	~Sample(void);					// Destructor 

	Sample & operator=(Sample const & rhs);  // Operateur d'assignation (=)

	int		getFoo(void) const;
};


// ne fait pas partie de la forme canonique mais tres repandu dans les classes 
std::ostream & operator<<(std::ostream & o, Sample const & i );

// Autre element frequent: 
//Fonction membre permettant  d'avoir une version sous forme de string, de la classe, afin de pouvoir l'afficher.
// Facilite le debug. 