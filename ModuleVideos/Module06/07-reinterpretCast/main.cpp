/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:05:00 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/25 16:28:06 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Le reinterpret cast est le cast qui va permettre de upcast et des downcast.
// Il s'agit du cast le plus permissif parmi tous les cast. 
// Va permettre changer une addresse pour n'importe quel type d'addresse. 

int main()
{
	float a = 420.042f;                             // Reference value

	void	*b = &a;								// Implicit promotion -> Ok
	int		*c = reinterpret_cast<int *>(b); 		// Explicit demotion -> Ok, I obey
	int &	d = reinterpret_cast<int &>(b);			// Explicit demotion -> Ok, I obey

	return (0);
}

/* 
	Un exemple concret du reinterpret cast, serait le cas ou un serveur envoit des donnees, dont on ne connait
	pas le contenu. Ce contenu est store dans un void *. Qui est un espace memoire qui peut prendre n'importe quel
	type de donnees. 

	Apres analyse, on se rend compte que le contenu est des char store dans un char *. On va donc faire un reinterpret cast
	du void* vers un char* pour pouvoir lire les donnees.
 */