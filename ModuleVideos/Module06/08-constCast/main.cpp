/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:30:20 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/25 16:36:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	const cast est le type de cast qui permet de creer des cast avec des variables qui ont des 
	qualifiers comme "const"

	const cast, veut dire qu'on prendre une variable const pour la transformer en d'autres choses.

	Utiliser un const cast en C++, c'est mauvais signe. Design est mauvais et le code devrait etre
	refait.  
 */

int main(void)
{	
	int a = 42;									// Reference value
	
	int const *b = &a;							// Implicit promotion -> Ok
	int  	  *c = b;                           // Implicit demotion -> Hell no !
	int		  *d = const_cast<int *>(b);		// Explicit demotion -> Ok, I obey. 

	return (0);	
}