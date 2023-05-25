/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:14:30 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/25 14:22:02 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// CEt exemple nous introduit a la syntax pour les cast en c++ 

int main(void)
{
	int a = 42;						// Reference value

	double b = a;					// Implicit promotion -> Ok
	int c = b;						// Implicit demotion -> Hell, no!
	int d = static_cast<int>(b);	// Explicit demotion -> Ok, I obey. 
	
	return (0);
}