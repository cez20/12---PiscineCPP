/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:19:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/25 13:41:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Il existe un type de reinterpretation (conserver le meme ordre des bits) qui
utilise un keyword qualifier "Const"


En ordre du plus general au plus precis:

void *
int const *  == Reference entier constant est plus general qu'une reference vers un entier constant (int *)
int * 		== Reference la plus basse, donc la plus precise.  


 */

#include <stdio.h>

int main(void)
{
	int a = 42;							// Reference value 
	
	int const *b = &a;					// Implicit type qualifier const 
	int const *c = (int const *) &a;	// Explicit type qualifier const

	/* 
	Le cas ici-bas creera une erreur lors de la compilation avec les flags -Wall -Wno-unused
	, car on assigne a int * e, une addresse de type const qui est une valuer qui n'est jamais amene a changer
	Si ce cas, etait autorise, cela voudrait dire que "e" pourrait changer la valeur, car il a perdu son qualifiant
	const. 

	Par contre, si je fais un cast explicite ou j'indique que je veux que le const soit change en int *, cela 
	va fonctionner.  
	*/
	
	int const	*d = &a;				// Implicit promotion ->Ok
	//int *		e  = d;					// Implicit demotion   -> Hell no!



	int *		f  = (int *)d;       	// Explicit demotion   -> Ok. 1 obey. 

	return (0);
}