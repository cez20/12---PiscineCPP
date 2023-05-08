/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:53:47 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/05 10:54:49 by cemenjiv         ###   ########.fr       */
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
 */

#include <stdio.h>


int main()
{
    float a = 420.042f;                 // Reference value
    
    void    *b = &a;                    // Implicit reinterpretation cast
    void    *c = (void*) &a;            // Explicit reinterpretation cast

    void    *d = &a;                    // Implicit promotion -> ok. On prend variable generale pour mettre un cas precis. 
    int     *e = d;                     // Implicit demotion -> Hazardeous
    int     *f = (int *)d;              // Explicit demotion -> ok , 1 obey

    printf("%p,  %f\n", &a, a);

    printf("%p\n", b);
    printf("%p\n", c);

    printf("%p\n", d);
    printf("%p, %d\n", e, *e);
    printf("%p, %d\n", f, *f);
    
    return (0);    
}