/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   youtube.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:44:58 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/05 19:03:15 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class YoutubeChannel{

private:
	std::string Name;
	std::string OwnerName;
	
public:
	YoutubeChannel(std::string name, std::string ownerName): Name(name), OwnerName(ownerName){
	
	}
	void GetInfo(){
		std::cout << this->Name << std::endl;
		std::cout << this->OwnerName << std::endl;
	}

};

// When declaring Constructor of this class, I must give the necessary arguments of Base class constructor. 
class CookingYoutubeChannel : public YoutubeChannel{  // Public here means that this class will only have access to public elements of base class
	
	public:
	CookingYoutubeChannel(std::string name, std::string ownerName): YoutubeChannel(name, ownerName){
		
	}
};

int main()
{
	CookingYoutubeChannel ytChannel("Amys Kitchen", "Amy");
	ytChannel.GetInfo();
	
	return (0);
}