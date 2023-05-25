/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:53:47 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/24 09:16:41 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Si on transfere un int vers un double, il y a un rearrangeement des bits
qui est fait pour representer un chiffre dans une autre type (ex: int vers double)

Il y existe un type de conversion qui s'appelle "conversion identitaire"
Il s'agit d'un conversion qui garde les memes bits dans le meme ordre
(En fait il n'y a pas eu de conversion pendant le cast).

Une conversion identitaire s'appelle une reinterpretation

demotion =   on prend un variable precise et on la met dans une variable generale
promotion =  on prend une variable generale et on la met dans une variable precise.


Hierarchie des types:
- void * plus generique que 
- int *
- char * 

Une conversion peut etre identitatire et lorsqu'elle l'est,  est appelle une reinterpretation et va permettre de jouer
sur des addresses plus generiques. 

Dans le cas d'une reinterpretation descendantes, toujours utiliser les marqueurs de 
cast epxlicite (type de variable entre parentheses)

Il est toujours possible d'aller d'une adresse plus precise vers une addresse plus generale. 
 */

#include <stdio.h>


int main()
{
    float a = 420.042f;                 // Reference value
    
    void    *b = &a;                    // Implicit reinterpretation cast
    void    *c = (void*) &a;            // Explicit reinterpretation cast

    void    *d = &a;                    // Implicit promotion -> ok. On prend variable generale pour mettre un cas precis. 
    int     *e = d;                     // Implicit demotion -> Hazardeous :  general (void) to more precise (int)
    int     *f = (int *)d;              // Explicit demotion -> ok , 1 obey

    printf("%p,  %f\n", &a, a);			// Prints address and value of float

    printf("%p\n", b);					// prints address of void pointer
    printf("%p\n", c);					// prints addresse of void pointer

    printf("%p\n", d);					// prints address of void pointer 
    printf("%p, %d\n", e, *e);			// printd address of int pointer and its value (initially float)
    printf("%p, %d\n", f, *f);			// prints address of int pointer and its value (initially float)
    
	//Essentially what happens in this case is that we do a reinterpretation,
	//Which means that we keeps the bits in the same order, so there is no converison or rearrangeement of bits
	// Binary representaiton of float is something like : 0 10000100010 10101100001100110011
	// If we take the bits as they are  and changed it into a int representaton  01000010 00101010 10000110 0110011

	//Conversion identitaire: Garde la meme identite binaire et cela donne lieu a une reinterpretation
	//0 10000100010 10101100001100110011 == 432.042f
	//01000010 00101010 10000110 0110011 = 1137837408

	// Bien qu'il s'agit de la meme representation binaire sur 32 bits, 

    return (0);    
}