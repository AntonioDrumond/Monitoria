# Recursos úteis:
+ Bilbiotecas io.h e io.hpp do Theldo. Recomendo estudar inteiras
+ Bibliotecas LibAD.h e LibAD.hpp presentes nessa pasta. Contém funções, classes e definições úteis para a disciplina
+ Meu repositório de [AED1](https://github.com/antoniodrumond/AED1) **NAO COPIE, USE COMO REFERÊNCIA DE APRENDIZADO**

## Loops
+ ``for(comando inicial; verificação pré execuções; comando repetido após cada execução){ ... }``
+ ``while(verificação pré execuções){ ... }``
+ ``do{ ... } while(verificação pós execuções);``

## Formatação de texto
Formato | Tipo
-- | --
%s | texto (string)
%c | caracteres (char)
%d | inteiros (int)
%lf | numeros reais (double)
%f | numeros reais (float)
%p | endereços de memória (ponteiros)

## Comandos úteis:
+ ``malloc(int n * sizeof(tipo);``
	+ Aloca espaço na memória RAM, equivalente a *n* vezes o tamanho em bytes do tipo desejado
	+ Retorna o ponteiro (endereço na memória) do espaço alocado
+ ``free(ponteiro);``
	+ Libera o espaço ocupado pelo ponteiro
