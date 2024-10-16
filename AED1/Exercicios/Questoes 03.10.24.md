## Instruções
+ Realizar as questões primeiro **no papel**. 
+ Antes de começar a escrever o código:
	+ Planejar e declarar variáveis necessárias
	+ Planejar a lógica do programa, o "passo a passo" a ser seguido.
## Questões:
###  1.) Método palavras:
- ler uma cadeia de caracteres do teclado;
- contar e mostrar todos símbolos que forem letras, ou maiúsculas ou minúsculas.
+ **Exemplo:** palavra = "P4LaVr@"
+ **Restrições:** Alocar espaço para receber a palavra com ``malloc()``
### 2.) Volume de esfera
+ Criar função que receba como parametro o número real do raio de uma esfera e retorne o seu volume.
+ Chamar essa função na main, com raio inserido pelo usuario.
+ **Restrições:** A função deve checar se o raio inserido é negativo, retornando *-1.0* para indicar erro.
### 3.) Função intervalos
+ Ler do teclado 3 valores inteiros
+ Retornar verdadeiro se o primeiro estiver dentro do intervalo dos outros dois, falso caso contrário.
+ Dentro da função, mostrar na tela todos os numeros inteiros dentro do intervalo.
+ **Restrições:** Retornar falso para indicar erro caso o limite inferior for maior que o superior, e printar "ERRO" na tela.
### 4.) Método do "quadrado"
+ Criar um método que receba o *endereço* de um double, e mude seu valor para o quadrado desse número, sem retornar nada.
+ **Restrições:** Deve ser um método de tipo void, sem retorno
### 5.) R + L = J
+ Criar uma função que receba, como string, uma equação do tipo "R+L=J", com uma variavel faltando, e retorne o valor dela.
+ **Exemplos:** Entrada "3+8=J" retorna 11 | Entrada "5+L=5" retorna 0 | Entrada "R+7=5" retorna -2
+ **Restrições:** Receber a string como um ponteiro de char