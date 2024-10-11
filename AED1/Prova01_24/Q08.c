#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isDescendente(char c){ // Funcao que verifica se um caractere e descendente
	if(c=='g' || c=='j' || c=='p' || c=='q' || c=='y') return true;
	else return false;
}

int testar(const char* str){ // Funcao que recebe uma string e retorna o seu numero de descendentes
	int n = strlen(str);
	int count = 0;
	for(int i=0; i<n; i++){
		if(isDescendente(str[i])) count++;
	}
	return count;
}

int main(){
	printf("Teste_1: \"bagagem\" -> %d descendentes\n", testar("bagagem"));
	printf("Teste_2: \"papagaio\" -> %d descendentes\n", testar("papagaio"));
	getchar();
	return 0;
}
