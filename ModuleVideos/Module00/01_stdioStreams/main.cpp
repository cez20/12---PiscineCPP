/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:07:46 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/25 17:17:34 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <thread> // For 2nd example 
#include <chrono> // For 2nd example 

int main(void)
{
	char buff[512];

	std::cout << "Hello World!" << std::endl;

	std::cout << "Input a word: ";
	std::cin >> buff;
	std::cout << "You entered: [" << buff << "]" << std::endl;

	return (0);
}


//****************************************************** 
//**SECOND SERIES OF EXAMPLES TO TEST \n vs std::endl***
//*******************************************************
 
//***  In this example, we display 1 number and then tell system NOT to flush (We do not force buffer to be written) ***
 
// using namespace std;
 
// int main()
// {
//   for (int i = 1; i <= 5; ++i)
//   {
//       cout << i << " ";
//       this_thread::sleep_for(chrono::seconds(1));
//   }
//   cout << endl;
//   return 0;
// }


//***  In this example, we display 1 number and then tell system to flush (force the buffer to be written) ***

// using namespace std;

// int main()
// {
//    for (int i = 1; i <= 5; ++i)
//    {
//       cout << i << " " << flush;
//       this_thread::sleep_for(chrono::seconds(1));
//    }
//    return 0;
// }
