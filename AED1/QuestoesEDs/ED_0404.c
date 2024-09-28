#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char* menorM(char* input){
	int leng = strlen(input); // Tamanho do input
	char* result = malloc(leng * sizeof(char)); //Aloca espaco suficiente para todos os caracteres menores que "m"
	int i = 0, // Percorre o input
		j = 0; // Percorre o resultado
	while(i<leng){
		if(input[i]<'m' && input[i]>='a'){
			result[j] = input[i];
			j++;
		}
		i++;
	}
	return result;
}

int main(){
	printf("Insira o input: ");
	char* input = malloc(30 * sizeof(char)); // Aloca espaco para 30 * tamanho de 1 caractere, ou seja: espaco para 30 caracteres.
	scanf(" %s", input); getchar();
	
	char* result = menorM(input);
	printf("%s%s\n", "Caracteres menores que \"m\": ", result);

	getchar();
	free(result); // Libera o espaco alocado para as strings
	free(input);
	return 0;
}
