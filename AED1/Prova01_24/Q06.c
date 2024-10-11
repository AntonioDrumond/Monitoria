#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool bissexto(int ano){ // Funcao que recebe o ano e retorna se ele e bissexto
	int ano1 = ano;
	while(ano1 >= 4){ // Loop para descobrir se o ano e multiplo de 4
		ano1 -= 4;
	}
	bool div4 = ano1==0 ? true : false; //div4 = true se ano1==0, e false caso contrario.
	
	if(!div4) return false; // Caso nao seja divisivel por 4, o ano NAO e bissexto
	else{
		ano1 = ano;
		while(ano1 >= 100){ // Checa se o ano e divisivel por 100
			ano1 -= 100;
		}
		bool div100 = ano1==0 ? true : false;

		if(!div100) return true; // Caso o ano seja divisivel por 4 e nao por 100, ele E bissexto
		else{
			ano1 = ano;
			while(ano1 >= 400){ // Checa se o ano e divisivel por 400
				ano1 -= 400;
			}
			bool div400 = ano1==0 ? true : false;

			if(div400) return true; // Se o ano for divisivel por 100 e 400, ele E bissexto
			else return false; // Se o ano for divisivel por 100 e nao 400, ele NAO E bissexto
		}
	}
}

int main(){
	int input = 0;
	do{
		printf("Insira um numero de um ano para checar se e bissexto, ou 0 para sair: ");
		scanf(" %d", &input); getchar();
		if(input != 0){
			if(bissexto(input)) printf("O ano inserido ERA bissexto\n\n");
			else printf("O ano inserido NAO ERA bissexto\n\n");
		}
	} while(input != 0);
	
	return 0;
}
