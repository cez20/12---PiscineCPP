/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions1.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:58:58 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/23 16:56:59 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

// throw std::exception va remontrer les blocks (blocks de la stack d'appel) jusqu'a
// atteindre le mot cle catch. 


// Lors de la declaration d'une fonction virtual, on peut mettre un "throw a la fin"
// const char* what() const throw() 
// Ceci veut dire que la fonction peut avoir un throw ou pas.  

// CATCH:
// Il y existe 2 types de catch soit les catch() specifique et les catch generiques:
// catch (PEBKACException& e) = Specifique, car on precise qu'il s'agit d'un exception de type PEBKACE
// catcg (std::exception& e) = GENERIQUE , pour tous les autres type de catch

// Dans les cas, on appele un programma va retourner une erreur 1 fois sur 2, il est important
// d'utiliser une valeur de retour representen par un INT, car le fait d'utiliser (ex: bool)
// catch() et tres couteux en terme de ressources. 

// Il y existe deja des messages d'exception avec des fonctions tel que new (bad alloc)
// ou avec open(), lorsqu'un fichier n'ouvre pas. A voir! 

void test1()
{
	try
	{
		//Do some stuff here
		if (/* there's an erreor */)
		{
			throw std::exception(); // Je vais lancer une exception 
		}
		else
		{
			// Do more stuff
		}
	}
	catch (std::exception e)
	{
		//Handle the error here
	}
}

void test2()
{
	//Do some stuff
	if (/* there's an erreor */)
	{
		throw std::exception();
	}
	else
	{
		//Do some more stuff
	}
}

void test3
{
	try
	{
		test2();
	}
	catch (std::exception& e) // On peut aussi prendre une reference vers une exception.  
	{
		//Handle error
	}
}


void test4()
{
	class PEBKACException: public std::exception  // Il s'agit d'une classe d'exception.  
	{
		public:
			virtual const char* what() const throw()  //(voir Explication plus haut)
			{
				return ("Problem exists between keyboard and chair");
			}
	};

	try
	{
		test3();
	}
	catch (PEBKACException& e)
	{
		//Handle the fact that the user is an idiot
	}
	catch (std::exception& e)
	{
		//Handle other exceptions that are like std::exception
	}

}