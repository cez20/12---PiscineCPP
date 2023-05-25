/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:11:44 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/24 07:37:51 by cemenjiv         ###   ########.fr       */
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

// Hierarchie dans les types de variable
// On peut caster d'un int vers un double, mais l'inverse est hasardeux. (int = 4 bytes, double = 8 bytes)
// Flag -Wconversion to avoid implicit conversion from double to int
//	(from precise to less precise). Therefore, explicit conversion is needed.

#include <stdio.h>
#include <stdint.h>

void print_binary1(uint32_t value, int num_bits) {
    for (int i = num_bits - 1; i >= 0; i--) {
        putchar((value & (1U << i)) ? '1' : '0');
    }
}

void dump_32bits_integer(int32_t num) {
    union {
        int32_t i;
        uint32_t u;
    } converter;
    converter.i = num;

    uint32_t byte1 = (converter.u >> 24) & 0xFF;
    uint32_t byte2 = (converter.u >> 16) & 0xFF;
    uint32_t byte3 = (converter.u >> 8) & 0xFF;
    uint32_t byte4 = converter.u & 0xFF;

    print_binary1(byte1, 8);    // First byte
    putchar(' ');
    print_binary1(byte2, 8);    // Second byte
    putchar(' ');
    print_binary1(byte3, 8);    // Third byte
    putchar(' ');
    print_binary1(byte4, 8);    // Fourth byte
}

void print_binary(uint64_t value, int num_bits) {
    for (int i = num_bits - 1; i >= 0; i--) {
        putchar((value & (1ULL << i)) ? '1' : '0');
    }
}


void dump_64bits_integer(double num) 
{
	union {
			double d;
			uint64_t u;
		} converter;
		converter.d = num;
		
		uint64_t sign = (converter.u >> 63) & 1;
		uint64_t exponent = (converter.u >> 52) & 0x7FF;
		uint64_t mantissa = converter.u & 0xFFFFFFFFFFFFF;

		print_binary(sign, 1);    // Sign bit
		putchar(' ');
		print_binary(exponent, 11);    // Exponent bits
		putchar(' ');
		print_binary(mantissa, 52);    // Manti
}

int main(){
	
	int a = 42;     					// Reference value

	double b = a;						// Implicit conversion cast
	double c = (double)a;				// Explicit conversion cast with parentheses and type
	
	double d = a;	

	int e = d;				// On peut considerer ceci comme hasardeux, car qu'est-ce qui me prouve que
							// ce que veux vraiment changer un type moins precis ver precis, donc une perte de precision
	int f = (int)d;
	
	dump_32bits_integer(a); // Fonction maison qui affiche la representation en bits d'une variable.
	printf("\n");
	dump_64bits_integer(b);
	printf("\n");
	dump_64bits_integer(c);
	printf("\n");
	dump_64bits_integer(d);
	printf("\n");
	dump_32bits_integer(e);
	printf("\n");
	dump_32bits_integer(f);

	return (0); 
}