/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:01:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/23 16:29:21 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Printer{

private:
	std::string _name;
	int _availablePaper;

public:
	Printer(std::string name, int paper){
		_name = name;
		_availablePaper = paper;
	}
	void	Print(std::string txtDoc){
		
		int requiredPaper=txtDoc.length()/10;

		// If the paper needed is bigger than actual _available paper that we have. 
		if (requiredPaper > _availablePaper)
			throw "No paper"; // Putting a throw will break the execution of the function.  
		std::cout << "Printing ..." << txtDoc << std::endl;
		_availablePaper -= requiredPaper; 
	}
	
	
};

int main()
{
	Printer myPrinter("Hp Deskjet 1234", 10);
	try // Indicated what must be tried 
	{
		myPrinter.Print("Hello my name is Cesar. I am a software engineer.");
		myPrinter.Print("Hello my name is Cesar. I am a software engineer.");	
		myPrinter.Print("Hello my name is Cesar. I am a software engineer.");		
	}
	catch (const char * txtException) // If error was thrown above, catch it 
	{
		std::cout << "Exception: " << txtException << std::endl;
	}
	
	//system("pause>nul");
	return (0);
}