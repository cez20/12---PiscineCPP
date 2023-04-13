/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:24:01 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/10 19:47:17 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

//Consequences des methodes PURES:
// - On ne peut pas "Argumenter" la methode(lui donner des arguments)
// - Cela veut dire qu'il n'y a pas de definition (pas d'implementation) de cette methode dans notre fichier .cpp
// - On ne pourra donc pas instancier notre classe, donc elle aura un comportement qui n'est pas la
// - Pour cette raison nous lui donnons le nom de classe ABSTRAITE



//Une convention nous dit qu'il faut mettre un "A" majuscule avant notre classe pour dire qu'elle est abstraite.
//Un character ne peut donc pas "attack" par lui meme, car il est une classe abstraite. 
//Par contre, les classe qui herite de Acharacter  auront une access a une fonciton attack meme si la classe Mere n'en a pas. 
// Il est aussi possible de declarer des attributs dans la classe Abstraite qui ne pourront ete utilise que par les classes derives 
class ACharacter{

public:
    virtual void   attack(std::string const & target) = 0; // Cela definit cette fonction comme une methode PURE 
    void           sayHello(std::string const & target); // Comportement CONCRET (a l'oppose d'un comportement abstrait)
};

// Class Warrior n'a pas le choix de definir une fonction attack, car sinon il ne pourra point utiliser celle de la classe
// mere, car elle est abstraite. 
class Warrior : public ACharacter{
public:
    virtual void attack(std::string const & target);
};

void ACharacter::sayHello(std::string const & target){

    std::cout << "Hello " << target << " !" << std::endl;
}

void Warrior::attack(std::string const & target){
    std::cout << "*attacks " << target << " with a sword" << std::endl;
}

// Lorsque je cree une classe qui n'a que des comportement abstraits, nous creeons une INTERFACE
// La convertion dit que nous devons mettre un "I" devant les classes de type Interface. 
// Il est impossible de declarer des attributs dans une INTERFACE
// C'est une forme de contrat que l'on declare.  
class ICoffeeMaker{
public:
    virtual void fillWaterTank(IWaterSource * src) = 0;  // ABSTRAIT 
    virtual ICoffee* makeCoffee(std::string const & type) = 0; // ABSTRAIT 
    
};

int main(){

    ACharacter* a = new Warrior();

    //This would NOT be ok because ACharacter is abstract
    //ACharacter* b - new ACharacter();

    a->sayHello("students");
    a->attack("Roger");
    
}