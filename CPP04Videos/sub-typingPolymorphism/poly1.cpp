/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poly1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:02:33 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/10 19:22:53 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cette video discute du concept de polymorphisme de sous-typage (sub-typing polymorphism)
// Lorsqu'on met des fonctions commen etant virtual, cela veut dire que le linkage sera 
// dynamique et non pas statique. 

// Lorsqu'on compile le code sans virtual, nous avons un appel de resoluiton STATIQUE, qui veut
// dire que a la compilation, je sais DEJA, quelle sera la fonction que je vais appelle 
//(celle de Character au lieu de Warrior) car on utilise le type de la variable (Character *a vs new Warrrior)
// En d'autres mots, une compilation va toujours se fier sur le type de variable pour ses appels de fonctions

// Lorsqu'on met des fonctions en "virtual", la resolution des appels de fonction va devenir
// dynamique, ce qui veut dire qu'elle va etre fait a l'execution. Il va donc prenre en consideration
// l'information qu'on va lui fournir a l'execution.  En d'autres mots, lorsqu'il passe le code,
// etapes par etapes, et que le moment d'appeler la fonction sayHello devra se faire, il va regarder
// quel est le type reel , qui est dans ce cas-ci un Warrior, car on appelle le constructeur Warrior. 

// Une fonction membre qui est virtuelle est appelle un method(). Dans d'autres langage, les fonctions 
// membres sont appelle methods, mais en C++ , elle designe specifiquement les fonctions membres qui sont
//  virtuelles 


# include <iostream>
# include <string>

class Character
{	
public:
	virtual void sayHello(std::string const & target);
};

class Warrior : public Character{
public:
	virtual void sayHello(std::string const & target);
};

class Cat{
	//[...]
};

void	Character::sayHello(std::string const & target){
	std::cout << "Hello " << target << " !" << std::endl;
}

void	Warrior::sayHello(std::string const & target){
	std::cout << "F** off " << target << ", I don't like you !" << std::endl;
}

int main(){

	//This is OK, obviously , Warrior IS a Warrior
	Warrior* a = new Warrior();

	//This is also OK because Warrior IS a character
	Character* b = new Warrior();

	//This would NOT be ok because Character IS NOT a Warrior
	//(Although they ARE related, and Warrior is a character, the reverse is untrue (a character is not a Warrior))
	//Warrior* c = new Character();

	//This would NOT be ok either because Cat is NOT a Character
	//(They are not even related)
	//Character*	d = new Cat();

	a->sayHello("students");
	b->sayHello("students");
}
