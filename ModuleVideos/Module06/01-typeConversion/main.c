/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:11:44 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/03 21:07:20 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Il y existe en C, 2 types de cast:
	- Mettre en parentheses, le type de variable pour lequel on desire changer (int)4,25
	- Cast implicite: pas besoin de rien ecrire pour qu'il ait lieu. 
	  (Ex: On met la valeur d'un int dans un double)
	- Regarder des videos sur la representation des floats et des doubles en memoire. 
 */

// Conversion: Le fait de changer le codage d'un octet vers une autre forme de codage s;appelle une
// conversion. 

void dump_32bits_integer(int const n);
void dump_64bits_integer(double const z);

int main(){
	
	int a = 42;     					// Reference value

	double b = a;						// Implicit conversion cast
	double c = (double)a;				// Explicit conversion cast with parentheses and type
	
	double d = a;

	int e = d;
	int f = (int)d;
	
	dump_32bits_integer(a); // Fonction maison qui affiche la representation en bits d'une variable.
	
	dump_64bits_integer(b);
	dump_64bits_integer(c);
	
	dump_64bits_integer(d);
	dump_32bits_integer(e);
	dump_32bits_integer(f);

	return (0); 
}