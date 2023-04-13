#ifndef HERITAGE1_HPP
#define HERITAGE1_HPP

#include <string>


/* On voit dans l'exemple ici que les classes Cat et Pony possedent des caracteristiques
similaires qui sont _nbrOfLegs et run. Nous pourrions donc creer une classe Parent
qui s'appelle Animal qui contient nbrOfLegs et run(). On pourrait donc dire qu'on 
des instances d'animaux et que dans cette classe on englobe des enfants qui sont
des Pony et de Cats. Avoir une classe parent evite d'avoir a reecrire les methodes run et
les attributs nbrOfLegs */



class Animal {

	private:
		int 	_nbrOfLegs;

	public;
		Cat();
		Cat(Cat const &);
		Cat& operator=(Cat const &);
		~Cat();

		void run(int distance);

		void scornSomeone(std::string const & target);

}


class Cat{

	private:
		int 	_nbrOfLegs;

	public;
		Cat();
		Cat(Cat const &);
		Cat& operator=(Cat const &);
		~Cat();

		void run(int distance);

		void scornSomeone(std::string const & target);

}

class Pony{

	private:
		int 	_nbrOfLegs;

	public;
		Pony();
		Pony(Pony const &);
		Pony& operator=(Pony const &);
		~Pony();

		void run(int distance);

		void doMagic(std::string const & target);

}














#endif
