/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:44:52 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/23 16:46:41 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main()
{
	std::string food;
	std::ofstream outfile("test.txt");

	std::cout << "What did you eat?";
	std::cin >> food;
	outfile << food;
	//outfile.close();

}

// Structure interessant pour lire contenu d'un input


// while (file >> food)
// {
// 	food.push_back 
// }