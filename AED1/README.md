# Recursos úteis:
+ Bilbiotecas io.h e io.hpp do Theldo. Recomendo estudar inteiras
+ Bibliotecas LibAD.h e LibAD.hpp presentes nessa pasta. Contém funções, classes e definições úteis para a disciplina
+ Meu repositório de [AED1](https://github.com/antoniodrumond/AED1) **NAO COPIE, USE COMO REFERÊNCIA DE APRENDIZADO**
## Loops
+ ``for(comando inicial; verificação pré execuções; comando repetido após cada execução){ ... }``
+ ``while(verificação pré execuções){ ... }``
+ ``do{ ... } while(verificação pós execuções);``
## Variáveis
+ Variáveis são como caixinhas, que guardam valores e informações
+ Elas ocupam um espaço em *bytes* na memória do computador.
+ Para declarar variáveis, basta digitar o tipo, seguido pelo nome da variável, e se desejarmos, utilizar o sinal "=" para atribuir um valor inicial.
```c
int var = 0; // Variavel "var", do tipo int, com valor inicial 0
char s = 'a'; // Variavel "c", do tipo char, com valor inicial 'a'
```
## Ponteiros
+ Ponteiros são um tipo especial de variável int, que guarda, ao invés de um valor, o endereço na memória de outra variável ou função.
+ Esse endereço pode ser obtido com o operador `&`
+ Ponteiros são indicados pela presença de asteriscos \*
+ Tambem podemos criar ponteiros de ponteiros, com múltiplos asteriscos.
+ Exemplo:
```c
int var = 4; // Criamos a variavel "var"
int* ptr = &var; // Criamos o ponteiro de int "ptr", com o endereço de "var"
int** ptr2 = &ptr // Criamos o ponteiro de ponteiro de int "ptr2", com o endereco de "ptr"
```
+ Dessa maneira, dizemos que `ptr2` aponta para o endereco de um endereco de um número inteiro.
### Dereferenciação
+ Dereferenciar um ponteiro significa obter o **dado** guardado no endereço apontado por ele.
+ Isso pode ser feito com o operador \* **antes** do nome do ponteiro:
```c
int var = 4; // Criamos a variavel "var", com valor inicial de 4
int* ptr = &var; // Criamos o ponteiro "ptr", com o endereço de "var"
*ptr = 10; // Atribuimos 10 ao CONTEUDO de "ptr", ou seja: "var"
printf("%d - %d", *ptr, var); // printa "10 - 10"
```
+ Ou seja: Podemos usar o \* para obter o conteudo apontado por um ponteiro.
### Alocação manual de memória
+ Podemos alocar memória manualmente, "separando um espaço" em nossa memória RAM para ser utilizada pelo programa.
+ Caso aloquemos espaço manualmente dessa maneira, devemos liberar esse espaço também manualmente.
```c
// O comando malloc() aloca espaço na memória
int* ptr = malloc(1 * sizeof(int));
// O comando free() libera esse espaço que foi alocado
free(ptr); 

// O comando calloc() faz a mesma coisa, mas preenche o espaço alocado com 0s
int* ptr = calloc(1, sizeof(int));
free(ptr);
```
+ Esse espaço que alocamos pode também ser maior, para receber múltiplos elementos, como um **arranjo**.
```c
int* arr = malloc(10 * sizeof(int)); // Aloca o espaço para 10 ints
arr[0] = 15;
arr[1] = 20;
/* ... */
arr[9] = 98; // Esse espaço pode ser acessado como um arranjo normal.

// Ao usar o comando free(), TODO o espaço alocado será liberado
free(arr);
```

## Formatação de texto
| Formato | Tipo                             |
| ------- | -------------------------------- |
| %s      | texto (string)                   |
| %c      | caracteres (char)                |
| %d      | inteiros (int)                   |
| %lf     | numeros reais (double)           |
| %f      | numeros reais (float)            |
| %p      | endereços de memória (ponteiros) |

Caractere | Nome | Explicacao
-- | -- | --
\0 | Caractere nulo | Fim da cadeia de caracteres
\n | Nova linha | ...
\t | Tabulacao vertical | ...
\a | Beep | Emite um bipe
