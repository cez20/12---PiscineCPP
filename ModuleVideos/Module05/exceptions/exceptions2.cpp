/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions2.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:16:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/27 14:27:19 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* IMPORTANT TO KNOW
   - You can throw any kind of variable or class in an exception AS LONG AS you have a corresponding catch
     with the right variable type
	- Ex: If I throw an int (throw 46), I must absolutely have a catch that received an int
 */

	// EXAMPLE OF EXCEPTION by throwing a number

	// int main()
	// {
	// 	int numerateur = 10;
	// 	int denominateur = 0;
	// 	int result;

	// 	try
	// 	{
	// 		if (denominateur == 0)
	// 			throw 0; // "throw denominateur" would have worked too.
	// 		else
	// 			result = numerateur / denominateur;
	// 	}
	// 	catch (int number)
	// 	{
	// 		std::cout << "Error was caused by denominateur that was at value: " << number << std::endl;
	// 	}
	// 	return (0);
	// }

	// EXAMPLE OF EXCEPTION by throwing a std::string 

	int main()
	{
		std::string Cesar = "Cesar";
		std::string empty = ""; // Creates an empty string

		std::string newstring = Cesar + empty;
		try
		{
			if (newstring.length() == Cesar.length())
				throw (std::string)"New constructed string same length as initial string";
			else
				std::cout << "Everything is perfect" << std::endl;
		}
		catch (std::string error)
		{
			std::cout << "Error: " << error << std::endl;
		}
		return (0);
	}
	
	// EXAMPLE BY THROWING A CLASS THAT IS DERIVED FROM STD::EXCEPTION CLASS
	// STD::EXCEPTION DEFAULT MESSAGE SET TO "std::exception" is override the message in class Cesar
	// Message is part of the what() function inside the std::exception class
	
	// int main()
	// {
	// 	class Cesar: public std::exception{

	// 		public:
	// 			virtual const char* what() const throw()
	// 			{
	// 				return ("I am tired");
	// 			}
	// 	};
		
	// 	int numerateur = 10;
	// 	int denominateur = 0;
	// 	int result;
	// 	Cesar 	cesar1;
	// 	std::exception 	ouf;



	// 	try {
	// 		if (denominateur == 0)
	// 			throw ouf; // il s'agit d'un objet de la classe std::exception cree plus haut! 
	// 			//throw std::exception();// En faisant ceci, j'appelle le constructeur de la classe exception qui cree un objec
	// 			//throw cesar1;
	// 		else
	// 			result = numerateur / denominateur;
				
	// 	}
	// 	catch (std::exception & d)
	// 	{
	// 		std::cout << "Problem with : " << d.what() << std::endl;
	// 	}
	
	// 	return 0;
	// } 