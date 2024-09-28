## Loops
+ ``for(comando inicial; verificação pré execuções; comando repetido após cada execução){ ... }``
+ ``while(verificação pré execuções){ ... }``
+ ``do{ ... } while(verificação pós execuções);``

## Formatação de texto
Formato | Tipo
-- | --
%s | texto(string
%c | caractere
%d | inteiros
%lf | numeros reais
%p | endereços de memória(ponteiros)

## Comandos úteis:
+ ``malloc(int n * sizeof(tipo);``
	+ Aloca espaço na memória RAM, equivalente a *n* vezes o tamanho em bytes do tipo desejado
	+ Retorna o ponteiro (endereço na memória) do espaço alocado
+ ``free(ponteiro);``
	+ Libera o espaço ocupado pelo ponteiro
