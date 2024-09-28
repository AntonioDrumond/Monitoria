#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int main(){
	double a = 0.0,
		   b = 0.0;
	int n = 0;
	scanf(" %lf %lf", &a, &b);

	if( !(a < 0.0 || a > 1.0 || b < 0.0 || b > 1.0)){	
		printf("%s", "Insira n: ");
		scanf(" %d", &n); getchar();

		double buffer = 0;
		int contador = 0;
		for(int i=0; i<n; i++){
			scanf(" %lf", &buffer); getchar();
			double frac = buffer - (int)buffer;
			if( (frac>a) && (frac<b) ){
				//printf("valor certo: %lf \n", buffer);
				printf("%s%lf\n","valor certo:",  buffer);
				contador++;
			}
		}

		printf("%s%d%s", "Tinha ", contador, " valores validos");

	}
	else {
		printf("\n\n%s\n", "valores invalidos.");
	}

	getchar();
	return 0;
}
