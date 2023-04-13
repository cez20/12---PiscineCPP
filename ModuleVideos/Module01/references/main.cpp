/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:54:10 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/22 12:14:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Ce video traite des references
// Une reference est un pointeur qui est constant, toujours dereference, et jamais null
// une reference ne peut pas changer, ce sur quoi elle pointe. On dire qu'il s'agit d'un
// pointeur constant qui pointe toujours sur la meme chose.
// Pour une reference (lorsqu'on veut l'afficher), on a pas besoin de mettre une etoile, ou l'ecrit tel quel. 

#include <iostream>

int main()
{
	int	numberOfBalls = 42;  // Declare et definition d'une variable a 42 

	int*	ballsPtr = &numberOfBalls; // Pointeur sur int
	int&	ballsRef = numberOfBalls; // Reference au int numberofBalls (symbole &)
//	int&	ballsRef2;  //Impossible a faire, car cree une reference qui ne pointe sur rien.


	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21;
	std::cout  << numberOfBalls << std::endl;
	ballsRef = 84; // On peut changer la valeur de ce vers quoi il pointe.  
	std::cout << numberOfBalls << std::endl;

	return (0);
}