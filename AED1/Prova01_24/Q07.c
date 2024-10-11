#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
@	Percebi que tinha interpretado a questao errado durante a aula.
@ 	Interpretei errado o conceito de numeros amigos. Segue o conceito correto:
@	"Dois números são colegas quadráticos se a soma dos algarismos do quadrado de um número
@	é igual à soma dos algarismos do quadrado do outro."
*/ 

int soma(int x){ //Essa funcao funciona apenas para numeros de 2 digitos
	int a = x/10;
	int b = x%10;
	return a+b;
}

int somaN(int x){// Funcao que calcula a soma dos digitos de um numero com qualquer numero de casas
	if(x<10) return x;
	else{
		int soma = 0;
		int init = x;
		do{ // Loop que "remove" a casa das unidades do numero, e soma ela ao total
			soma += init % 10;
			init /= 10;
		} while(init>0);
		return soma;
	}
}

bool amigos(int x, int y){ // Interpretacao errada.
	int somaX = soma(x);
	int somaY = soma(y);
	if((somaX*somaX)==y && (somaY*somaY)==x) return true;
	else return false;
}

bool amigosCerto(int x, int y){
	int somaX = somaN(x*x);
	int somaY = somaN(y*y);
	if(somaX==y && somaY==x) return true;
	else return false;
}

void questao(){
	for(int i=10; i<=99; i++){
		for(int j=i; j<=99; j++){
			bool friends = amigosCerto(i, j);
			if(friends) printf("Amigos: %d - %d\n", i, j);
		}
	}
}

int main(){
	questao();
	getchar();
	return 0;
}
